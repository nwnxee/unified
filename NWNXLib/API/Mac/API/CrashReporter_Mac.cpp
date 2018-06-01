#include "CrashReporter_Mac.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CrashReporter_Mac::CrashReporter_Mac(void* a0)
{
    CrashReporter_Mac__CrashReporter_MacCtor__0(this, a0);
}

CrashReporter_Mac::~CrashReporter_Mac()
{
    CrashReporter_Mac__CrashReporter_MacDtor__0(this);
}

void CrashReporter_Mac::CanWriteCallstack()
{
    return CrashReporter_Mac__CanWriteCallstack(this);
}

void CrashReporter_Mac::CanWriteMinidump()
{
    return CrashReporter_Mac__CanWriteMinidump(this);
}

void CrashReporter_Mac::CanWriteSystemFiles()
{
    return CrashReporter_Mac__CanWriteSystemFiles(this);
}

void CrashReporter_Mac::InternalCrashHandler(int32_t a0)
{
    return CrashReporter_Mac__InternalCrashHandler(this, a0);
}

void CrashReporter_Mac::ReportCrashToUser(const char* a0, const char* a1)
{
    return CrashReporter_Mac__ReportCrashToUser(this, a0, a1);
}

void CrashReporter_Mac::WriteCallstack(__sFILE* a0)
{
    return CrashReporter_Mac__WriteCallstack(this, a0);
}

void CrashReporter_Mac::WriteSystemFiles(__sFILE* a0)
{
    return CrashReporter_Mac__WriteSystemFiles(this, a0);
}

void CrashReporter_Mac__CrashReporter_MacCtor__0(CrashReporter_Mac* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__CrashReporter_MacCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CrashReporter_Mac__CrashReporter_MacDtor__0(CrashReporter_Mac* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__CrashReporter_MacDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CrashReporter_Mac__CanWriteCallstack(CrashReporter_Mac* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__CanWriteCallstack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CrashReporter_Mac__CanWriteMinidump(CrashReporter_Mac* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__CanWriteMinidump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CrashReporter_Mac__CanWriteSystemFiles(CrashReporter_Mac* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__CanWriteSystemFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CrashReporter_Mac__InternalCrashHandler(CrashReporter_Mac* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__InternalCrashHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CrashReporter_Mac__ReportCrashToUser(CrashReporter_Mac* thisPtr, const char* a0, const char* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, const char*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__ReportCrashToUser);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CrashReporter_Mac__WriteCallstack(CrashReporter_Mac* thisPtr, __sFILE* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, __sFILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__WriteCallstack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CrashReporter_Mac__WriteSystemFiles(CrashReporter_Mac* thisPtr, __sFILE* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CrashReporter_Mac*, __sFILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CrashReporter_Mac__WriteSystemFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

}

}
