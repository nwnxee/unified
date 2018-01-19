#include "ICrashReporter.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void ICrashReporter::ExposeFile(__sFILE* a0, const char* a1)
{
    return ICrashReporter__ExposeFile(a0, a1);
}

int32_t ICrashReporter::WriteMinidump(__sFILE* a0, int32_t a1)
{
    return ICrashReporter__WriteMinidump(this, a0, a1);
}

void ICrashReporter__ExposeFile(__sFILE* a0, const char* a1)
{
    using FuncPtrType = void(*)(__sFILE*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__ExposeFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1);
}

int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, __sFILE* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, __sFILE*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteMinidump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
