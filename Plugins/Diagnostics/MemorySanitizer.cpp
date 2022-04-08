#include "nwnx.hpp"

#include "API/Functions.hpp"
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <dlfcn.h>
#include <execinfo.h>


namespace Diagnostics::MemorySanitizer {

using namespace NWNXLib;
using namespace NWNXLib::API;

struct Backtrace { void *bt[8]; };

static std::unordered_map<void*, Backtrace> active_allocations;
static std::unordered_set<void*> pending_free;

static std::recursive_mutex lock;
static bool enabled = false;

static void *(*real_calloc)(size_t, size_t);
static void *(*real_realloc)(void *, size_t);
static void  (*real_free)(void *);
static void *(*real_malloc)(size_t);


static thread_local bool meta = false;
struct MetaFunction
{
    bool oldmeta;
    MetaFunction() { oldmeta = meta; meta = true; }
    ~MetaFunction() { meta = oldmeta; }
};

void MemorySanitizer() __attribute__((constructor));
void MemorySanitizerDestructor() __attribute__((destructor));
static void ResolveSymbols();
static void FreePending();

void MemorySanitizer()
{
    if (!Config::Get<bool>("MEMORY_SANITIZER", false))
        return;

    LOG_INFO("Memory sanitizer enabled");
    if (real_malloc == nullptr)
    {
        LOG_WARNING("NWNX_Diagnostics.so is not preloaded, memory sanitizer will not work.");
        LOG_WARNING("Please see Diagnostics/README.md for instructions");
        return;
    }
    static Hooks::Hook pMainLoopHook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal8MainLoopEv,
            (void*)+[](CServerExoAppInternal *pServerExoAppInternal) -> int32_t
            {
                auto retVal = pMainLoopHook->CallOriginal<int32_t>(pServerExoAppInternal);
                FreePending();
                return retVal;
            }, Hooks::Order::Earliest);
    enabled = true;
}
void MemorySanitizerDestructor()
{
    if (enabled)
    {
        LOG_WARNING("Shutting down MSAN, a crash is imminent. This is not a bug.");
    }
}

static void ReportError(void *ptr)
{
    try
    {
        Backtrace bt;
        {
            std::lock_guard<std::recursive_mutex> guard(lock);
            bt = active_allocations.at(ptr);
        }
        char buffer[16*1024] = "";
        char** resolvedFrames = backtrace_symbols(bt.bt, 8);
        std::strncat(buffer, "\n  Allocation backtrace:\n", sizeof(buffer)-1);
        for (int i = 0; i < 8; ++i)
        {
            uintptr_t addr, addr2;
            char backtraceBuffer[2048] = "";
            char path[64];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            if (std::sscanf(backtraceBuffer, "    %63[^(](+%lx) [%lx]", path, &addr, &addr2) == 3)
            {
                std::snprintf(backtraceBuffer, sizeof(backtraceBuffer),
                    "    %s(%s) [0x%lx]\n", path, Platform::ResolveAddress(addr).c_str(), addr2);
            }
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
        std::puts(buffer);
        real_free(resolvedFrames);
    } catch (std::out_of_range& e)
    {
        LOG_NOTICE("Pointer %p not found in active allocations list.", ptr);
    }
}

#define MSAN_ASSERT(cond, ptr, fmt, ...)      \
  do { if (!(cond)) {                         \
        ASSERT_MSG(cond, fmt, ##__VA_ARGS__); \
        ReportError(ptr);    \
  } } while(0)

constexpr uint8_t  UNINIT = 0x69;
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



void *malloc(size_t size)
{
    ResolveSymbols();
    if (!enabled || meta) return real_malloc(size);
    MetaFunction mf;

    void *ptr = malloc(size + FenceSize);
    ptr = InitFence(ptr, size);

    Backtrace bt;
    backtrace(bt.bt, 8);

    std::lock_guard<std::recursive_mutex> guard(lock);
    active_allocations[ptr] = bt;

    return ptr;
}
void free(void *ptr)
{
    ResolveSymbols();
    if (!enabled || meta) return real_free(ptr);
    MetaFunction mf;

    {
        std::lock_guard<std::recursive_mutex> guard(lock);
        if (active_allocations.count(ptr) == 0)
        {
            // Logging infra is not reentrant.
            //LOG_WARNING("Freeing non-allocated pointer %p.", ptr);
            return real_free(ptr);
        }
    }

    size_t size = CheckFence(ptr);
    memset(ptr, UNINIT, size);

    std::lock_guard<std::recursive_mutex> guard(lock);
    MSAN_ASSERT(pending_free.count(ptr) == 0, ptr, "Double free detected.");
    pending_free.insert(ptr);
}

void *calloc(size_t num, size_t size)
{
    // dlsym calls calloc(), so just return null to avoid infinite recursion
    //ResolveSymbols();
    if (real_calloc == nullptr) return nullptr;
    if (!enabled || meta) return real_calloc(num, size);

    size_t fullsize = num * size;
    void *ptr = malloc(fullsize);
    memset(ptr, 0, fullsize);
    return ptr;
}
void *realloc(void *ptr, size_t size)
{
    ResolveSymbols();
    if (!enabled || meta) return real_realloc(ptr, size);

    if (ptr == nullptr) return malloc(size);

    size_t oldsize = CheckFence(ptr);
    void *newptr = malloc(size);
    memcpy(newptr, ptr, std::min(oldsize, size));
    return newptr;
}

static void FreePending()
{
    MetaFunction mf;
    std::lock_guard<std::recursive_mutex> guard(lock);
    
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
    pending_free.clear();
}

static void ResolveSymbols()
{
    if (real_calloc) return;
    MetaFunction mf;

    real_calloc  = (void*(*)(size_t,size_t)) dlsym(RTLD_NEXT, "calloc");
    real_malloc  = (void*(*)(size_t))        dlsym(RTLD_NEXT, "malloc");
    real_free    = (void(*)(void*))          dlsym(RTLD_NEXT, "free");
    real_realloc = (void*(*)(void*,size_t))  dlsym(RTLD_NEXT, "realloc");
}

}


extern "C" void *malloc(size_t size)             { return Diagnostics::MemorySanitizer::malloc(size); }
extern "C" void *calloc(size_t num, size_t size) { return Diagnostics::MemorySanitizer::calloc(num, size); }
extern "C" void *realloc(void *ptr, size_t size) { return Diagnostics::MemorySanitizer::realloc(ptr, size);}
extern "C" void free(void *ptr)                  { return Diagnostics::MemorySanitizer::free(ptr);}
