#include "ICrashReporter.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void ICrashReporter::ExposeFile(_IO_FILE* a0, const char* a1)
{
    return ICrashReporter__ExposeFile(a0, a1);
}

int32_t ICrashReporter::WriteCallstack(_IO_FILE* a0)
{
    return ICrashReporter__WriteCallstack(this, a0);
}

int32_t ICrashReporter::WriteMinidump(_IO_FILE* a0, int32_t a1)
{
    return ICrashReporter__WriteMinidump(this, a0, a1);
}

int32_t ICrashReporter::WriteSystemFiles(_IO_FILE* a0)
{
    return ICrashReporter__WriteSystemFiles(this, a0);
}

void ICrashReporter__ExposeFile(_IO_FILE* a0, const char* a1)
{
    using FuncPtrType = void(*)(_IO_FILE*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__ExposeFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1);
}

int32_t ICrashReporter__WriteCallstack(ICrashReporter* thisPtr, _IO_FILE* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, _IO_FILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteCallstack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, _IO_FILE* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, _IO_FILE*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteMinidump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t ICrashReporter__WriteSystemFiles(ICrashReporter* thisPtr, _IO_FILE* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, _IO_FILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteSystemFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
