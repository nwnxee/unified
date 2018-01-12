#include "CExoLocStringInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoLocStringInternal::CExoLocStringInternal()
{
    CExoLocStringInternal__CExoLocStringInternalCtor__0(this);
}

CExoLocStringInternal::~CExoLocStringInternal()
{
    CExoLocStringInternal__CExoLocStringInternalDtor__0(this);
}

int32_t CExoLocStringInternal::AddString(int32_t a0, CExoString a1)
{
    return CExoLocStringInternal__AddString(this, a0, a1);
}

int32_t CExoLocStringInternal::Assign(CExoLocStringInternal* a0)
{
    return CExoLocStringInternal__Assign(this, a0);
}

void CExoLocStringInternal::ClearLocString()
{
    return CExoLocStringInternal__ClearLocString(this);
}

int32_t CExoLocStringInternal::Compare(CExoLocString& a0)
{
    return CExoLocStringInternal__Compare(this, a0);
}

int32_t CExoLocStringInternal::GetString(int32_t a0, CExoString* a1)
{
    return CExoLocStringInternal__GetString__0(this, a0, a1);
}

int32_t CExoLocStringInternal::GetString(uint32_t a0, int32_t* a1, CExoString* a2)
{
    return CExoLocStringInternal__GetString__1(this, a0, a1, a2);
}

uint32_t CExoLocStringInternal::GetStringCount()
{
    return CExoLocStringInternal__GetStringCount(this);
}

int32_t CExoLocStringInternal::GetStringLength(uint32_t a0)
{
    return CExoLocStringInternal__GetStringLength(this, a0);
}

void CExoLocStringInternal::RemoveString(int32_t a0)
{
    return CExoLocStringInternal__RemoveString(this, a0);
}

void CExoLocStringInternal__CExoLocStringInternalCtor__0(CExoLocStringInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocStringInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__CExoLocStringInternalCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoLocStringInternal__CExoLocStringInternalDtor__0(CExoLocStringInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocStringInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__CExoLocStringInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoLocStringInternal__AddString(CExoLocStringInternal* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__AddString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoLocStringInternal__Assign(CExoLocStringInternal* thisPtr, CExoLocStringInternal* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, CExoLocStringInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__Assign);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoLocStringInternal__ClearLocString(CExoLocStringInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocStringInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__ClearLocString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoLocStringInternal__Compare(CExoLocStringInternal* thisPtr, CExoLocString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__Compare);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoLocStringInternal__GetString__0(CExoLocStringInternal* thisPtr, int32_t a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, int32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__GetString__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoLocStringInternal__GetString__1(CExoLocStringInternal* thisPtr, uint32_t a0, int32_t* a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, uint32_t, int32_t*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__GetString__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CExoLocStringInternal__GetStringCount(CExoLocStringInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__GetStringCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoLocStringInternal__GetStringLength(CExoLocStringInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocStringInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__GetStringLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoLocStringInternal__RemoveString(CExoLocStringInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocStringInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocStringInternal__RemoveString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
