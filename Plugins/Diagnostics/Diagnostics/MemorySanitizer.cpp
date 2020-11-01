#include "Diagnostics/MemorySanitizer.hpp"

#include "Platform/Debug.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "API/Functions.hpp"
#include <dlfcn.h>
#include <execinfo.h>


namespace Diagnostics {

using namespace NWNXLib;
using namespace NWNXLib::API;

static thread_local bool meta = false;
struct MetaFunction
{
    bool oldmeta;
    MetaFunction() { oldmeta = meta; meta = true; }
    ~MetaFunction() { meta = oldmeta; }
};


MemorySanitizer::MemorySanitizer(Services::HooksProxy*, Services::TasksProxy* tasker)
{
    enabled = true;
    tasker = tasker;
}
MemorySanitizer::~MemorySanitizer()
{
    enabled = false;
}

void MemorySanitizer::ReportError(void *ptr)
{
    try
    {
        void **bt = active_allocations.at(ptr);
        char buffer[16*1024];
        char** resolvedFrames = backtrace_symbols(bt, 8);
        std::strncat(buffer, "\n  Allocation backtrace:\n", sizeof(buffer)-1);
        for (int i = 0; i < 8; ++i)
        {
            uintptr_t addr, addr2;
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            if (std::sscanf(backtraceBuffer, "    ./nwserver-linux(+%lx) [%lx]", &addr, &addr2) == 2)
            {
                std::snprintf(backtraceBuffer, sizeof(backtraceBuffer),
                    "    ./nwserver-linux(%s) [0x%lx]\n", Platform::Debug::ResolveAddress(addr).c_str(), addr2);
            }
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
        LOG_NOTICE("%s", buffer);
    } catch (std::out_of_range& e)
    {
        LOG_NOTICE("Pointer %p not found in active allocations list.", ptr);
    }
}

#define MSAN_ASSERT(cond, ptr, fmt, ...)      \
  do { if (!(cond)) {                         \
        ASSERT_MSG(cond, fmt, ##__VA_ARGS__); \
        MemorySanitizer::ReportError(ptr);    \
  } } while(0)

constexpr uint8_t  UNINIT = 0x55;
constexpr uint32_t MAGIC1 = 0x76aade08;
constexpr uint64_t MAGIC2 = 0x8d0308b6e7dce543ull;
constexpr uint64_t MAGIC3 = 0xe561f9248d7563d1ull;
constexpr uint64_t MAGIC4 = 0x5dd93457b02ebbb6ull;
struct MemoryFenceHead
{
    uint32_t magic1;
    uint32_t size;
    uint64_t magic2;
};
struct MemoryFenceTail
{
    uint64_t magic3;
    uint64_t magic4;
};
constexpr size_t FenceSize = sizeof(MemoryFenceHead) + sizeof(MemoryFenceTail);

static inline void* InitFence(void *ptr, size_t size)
{
    MemoryFenceHead *head = (MemoryFenceHead*)ptr;
    head->magic1 = MAGIC1;
    head->magic2 = MAGIC2;
    head->size = size;

    ptr = (uint8_t*)ptr + sizeof(MemoryFenceHead);
    MemoryFenceTail *tail = (MemoryFenceTail*)((uint8_t*)ptr + size);
    tail->magic3 = MAGIC3;
    tail->magic4 = MAGIC4;

    memset(ptr, UNINIT, size);
    return ptr;
}
static inline size_t CheckFence(void *ptr)
{
    MemoryFenceHead *head = (MemoryFenceHead*)((uint8_t*)ptr - sizeof(MemoryFenceHead));
    MSAN_ASSERT(head->magic1 == MAGIC1, ptr, "Buffer overrun detected.");
    MSAN_ASSERT(head->magic2 == MAGIC2, ptr, "Buffer overrun detected.");

    MemoryFenceTail *tail = (MemoryFenceTail*)((uint8_t*)ptr + head->size);
    MSAN_ASSERT(tail->magic3 == MAGIC3, ptr, "Buffer overrun detected.");
    MSAN_ASSERT(tail->magic4 == MAGIC4, ptr, "Buffer overrun detected.");
    return head->size;
}



void *MemorySanitizer::malloc(size_t size)
{
    ResolveSymbols();
    if (!enabled || meta) return real_malloc(size);
    MetaFunction mf;

    void *ptr = malloc(size + FenceSize);
    ptr = InitFence(ptr, size);

    void *bt[8];
    backtrace(bt, 8);

    LOG_NOTICE("allocated %p", ptr);
    std::lock_guard<std::mutex> guard(lock);
    active_allocations[ptr] = bt;

    return ptr;
}
void MemorySanitizer::free(void *ptr)
{
    ResolveSymbols();
    if (!enabled || meta) return real_free(ptr);
    MetaFunction mf;

    size_t size = CheckFence(ptr);
    memset(ptr, UNINIT, size);

    std::lock_guard<std::mutex> guard(lock);
    MSAN_ASSERT(active_allocations.count(ptr) == 1, ptr, "Freeing non-allocated pointer.");
    MSAN_ASSERT(pending_free.count(ptr) == 0, ptr, "Double free detected.");
    pending_free.insert(ptr);
}

void *MemorySanitizer::calloc(size_t num, size_t size)
{
    ResolveSymbols();
    if (!enabled || meta) return real_calloc(num, size);

    size_t fullsize = num * size;
    void *ptr = malloc(fullsize);
    memset(ptr, 0, fullsize);
    return ptr;
}
void *MemorySanitizer::realloc(void *ptr, size_t size)
{
    ResolveSymbols();
    if (!enabled || meta) return real_realloc(ptr, size);

    if (ptr == nullptr) return malloc(size);

    size_t oldsize = CheckFence(ptr);
    void *newptr = malloc(size);
    memcpy(newptr, ptr, std::min(oldsize, size));
    return newptr;
}

void MemorySanitizer::FreePending()
{
    MetaFunction mf;
    std::lock_guard<std::mutex> guard(lock);
    
    for (auto* ptr : pending_free)
    {
        size_t size = CheckFence(ptr);
        for (size_t i = 0; i < size; i++)
        {
            if (((char*)ptr)[i] != UNINIT)
            {
                MSAN_ASSERT(0, ptr, "Use after free detected. ptr[%d] = %02x", i, ((char*)ptr)[i]);
                break;
            }
        }
        active_allocations.erase(ptr);
        real_free((char*)ptr - sizeof(MemoryFenceHead));
    }
}

void MemorySanitizer::ResolveSymbols()
{
    if (real_malloc) return;

    real_malloc  = (void*(*)(size_t))        dlsym(RTLD_NEXT, "malloc");
    real_free    = (void(*)(void*))          dlsym(RTLD_NEXT, "free");
    real_calloc  = (void*(*)(size_t,size_t)) dlsym(RTLD_NEXT, "calloc");
    real_realloc = (void*(*)(void*,size_t))  dlsym(RTLD_NEXT, "realloc");
}

}


extern "C" void *malloc(size_t size)             { return Diagnostics::MemorySanitizer::malloc(size); }
extern "C" void *calloc(size_t num, size_t size) { return Diagnostics::MemorySanitizer::calloc(num, size); }
extern "C" void *realloc(void *ptr, size_t size) { return Diagnostics::MemorySanitizer::realloc(ptr, size);}
extern "C" void free(void *ptr)                  { return Diagnostics::MemorySanitizer::free(ptr);}
