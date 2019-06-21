#include "ICrashReporter.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

ICrashReporter::~ICrashReporter()
{
    ICrashReporter__ICrashReporterDtor__0(this);
}

CExoString ICrashReporter::ChecksumFile(const CExoString& a0)
{
    return ICrashReporter__ChecksumFile(a0);
}

void ICrashReporter::ExposeFile(__sFILE* a0, const char* a1)
{
    return ICrashReporter__ExposeFile(a0, a1);
}

int32_t ICrashReporter::WriteCallstack(__sFILE* a0)
{
    return ICrashReporter__WriteCallstack(this, a0);
}

int32_t ICrashReporter::WriteMinidump(__sFILE* a0, int32_t a1)
{
    return ICrashReporter__WriteMinidump(this, a0, a1);
}

int32_t ICrashReporter::WriteSystemFiles(__sFILE* a0)
{
    return ICrashReporter__WriteSystemFiles(this, a0);
}

void ICrashReporter__ICrashReporterDtor__0(ICrashReporter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(ICrashReporter*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__ICrashReporterDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString ICrashReporter__ChecksumFile(const CExoString& a0)
{
    using FuncPtrType = CExoString(*)(const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__ChecksumFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0);
}

void ICrashReporter__ExposeFile(__sFILE* a0, const char* a1)
{
    using FuncPtrType = void(*)(__sFILE*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__ExposeFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1);
}

int32_t ICrashReporter__WriteCallstack(ICrashReporter* thisPtr, __sFILE* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, __sFILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteCallstack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, __sFILE* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, __sFILE*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteMinidump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t ICrashReporter__WriteSystemFiles(ICrashReporter* thisPtr, __sFILE* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(ICrashReporter*, __sFILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ICrashReporter__WriteSystemFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
