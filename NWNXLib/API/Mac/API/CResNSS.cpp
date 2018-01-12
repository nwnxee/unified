#include "CResNSS.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResNSS::CResNSS()
{
    CResNSS__CResNSSCtor__0(this);
}

CResNSS::~CResNSS()
{
    CResNSS__CResNSSDtor__0(this);
}

unsigned char* CResNSS::GetNSSDataPtr()
{
    return CResNSS__GetNSSDataPtr(this);
}

uint32_t CResNSS::GetNSSSize()
{
    return CResNSS__GetNSSSize(this);
}

int32_t CResNSS::IsLoaded()
{
    return CResNSS__IsLoaded(this);
}

int32_t CResNSS::OnResourceFreed()
{
    return CResNSS__OnResourceFreed(this);
}

int32_t CResNSS::OnResourceServiced()
{
    return CResNSS__OnResourceServiced(this);
}

void CResNSS__CResNSSCtor__0(CResNSS* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__CResNSSCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResNSS__CResNSSDtor__0(CResNSS* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResNSS*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__CResNSSDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char* CResNSS__GetNSSDataPtr(CResNSS* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__GetNSSDataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CResNSS__GetNSSSize(CResNSS* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__GetNSSSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNSS__IsLoaded(CResNSS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNSS__OnResourceFreed(CResNSS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNSS__OnResourceServiced(CResNSS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNSS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNSS__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
