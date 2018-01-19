#include "CResPWK.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResPWK::CResPWK()
{
    CResPWK__CResPWKCtor(this);
}

CResPWK::~CResPWK()
{
    CResPWK__CResPWKDtor__0(this);
}

unsigned char* CResPWK::GetPWKDataPtr()
{
    return CResPWK__GetPWKDataPtr(this);
}

uint32_t CResPWK::GetPWKSize()
{
    return CResPWK__GetPWKSize(this);
}

int32_t CResPWK::IsLoaded()
{
    return CResPWK__IsLoaded(this);
}

int32_t CResPWK::OnResourceFreed()
{
    return CResPWK__OnResourceFreed(this);
}

int32_t CResPWK::OnResourceServiced()
{
    return CResPWK__OnResourceServiced(this);
}

void CResPWK__CResPWKCtor(CResPWK* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__CResPWKCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResPWK__CResPWKDtor__0(CResPWK* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResPWK*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__CResPWKDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char* CResPWK__GetPWKDataPtr(CResPWK* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__GetPWKDataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CResPWK__GetPWKSize(CResPWK* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__GetPWKSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResPWK__IsLoaded(CResPWK* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResPWK__OnResourceFreed(CResPWK* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResPWK__OnResourceServiced(CResPWK* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResPWK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResPWK__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
