#include "CExoLocString.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLocStringInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLocString::CExoLocString()
{
    CExoLocString__CExoLocStringCtor__0(this);
}

CExoLocString::CExoLocString(const CExoLocString& a0)
{
    CExoLocString__CExoLocStringCtor__2(this, a0);
}

CExoLocString::~CExoLocString()
{
    CExoLocString__CExoLocStringDtor__0(this);
}

int32_t CExoLocString::AddString(int32_t a0, CExoString a1, unsigned char a2)
{
    return CExoLocString__AddString(this, a0, a1, a2);
}

void CExoLocString::ClearLocString()
{
    return CExoLocString__ClearLocString(this);
}

int32_t CExoLocString::GetString(uint32_t a0, int32_t* a1, CExoString* a2, unsigned char* a3)
{
    return CExoLocString__GetString__0(this, a0, a1, a2, a3);
}

int32_t CExoLocString::GetString(int32_t a0, CExoString* a1, unsigned char a2, int32_t a3)
{
    return CExoLocString__GetString__1(this, a0, a1, a2, a3);
}

uint32_t CExoLocString::GetStringCount()
{
    return CExoLocString__GetStringCount(this);
}

int32_t CExoLocString::GetStringInternal(int32_t a0, CExoString* a1)
{
    return CExoLocString__GetStringInternal(this, a0, a1);
}

int32_t CExoLocString::GetStringLength(uint32_t a0)
{
    return CExoLocString__GetStringLength(this, a0);
}

int32_t CExoLocString::GetStringLoc(int32_t a0, CExoString* a1, unsigned char a2)
{
    return CExoLocString__GetStringLoc(this, a0, a1, a2);
}

int32_t CExoLocString::operator!=(CExoLocString& a0)
{
    return CExoLocString__OperatorNotEqualTo(this, a0);
}

CExoLocString& CExoLocString::operator=(const CExoLocString& a0)
{
    return CExoLocString__OperatorAssignment(this, a0);
}

int32_t CExoLocString::operator==(CExoLocString& a0)
{
    return CExoLocString__OperatorEqualTo(this, a0);
}

void CExoLocString::RemoveString(int32_t a0)
{
    return CExoLocString__RemoveString__0(this, a0);
}

void CExoLocString::RemoveString(int32_t a0, unsigned char a1)
{
    return CExoLocString__RemoveString__1(this, a0, a1);
}

void CExoLocString__CExoLocStringCtor__0(CExoLocString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__CExoLocStringCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoLocString__CExoLocStringCtor__2(CExoLocString* thisPtr, const CExoLocString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*, const CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__CExoLocStringCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoLocString__CExoLocStringDtor__0(CExoLocString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__CExoLocStringDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoLocString__AddString(CExoLocString* thisPtr, int32_t a0, CExoString a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, int32_t, CExoString, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__AddString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CExoLocString__ClearLocString(CExoLocString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__ClearLocString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoLocString__GetString__0(CExoLocString* thisPtr, uint32_t a0, int32_t* a1, CExoString* a2, unsigned char* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, uint32_t, int32_t*, CExoString*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetString__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoLocString__GetString__1(CExoLocString* thisPtr, int32_t a0, CExoString* a1, unsigned char a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, int32_t, CExoString*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetString__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CExoLocString__GetStringCount(CExoLocString* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoLocString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetStringCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoLocString__GetStringInternal(CExoLocString* thisPtr, int32_t a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, int32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetStringInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoLocString__GetStringLength(CExoLocString* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetStringLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoLocString__GetStringLoc(CExoLocString* thisPtr, int32_t a0, CExoString* a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, int32_t, CExoString*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__GetStringLoc);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoLocString__OperatorNotEqualTo(CExoLocString* thisPtr, CExoLocString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__OperatorNotEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLocString& CExoLocString__OperatorAssignment(CExoLocString* thisPtr, const CExoLocString& a0)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CExoLocString*, const CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoLocString__OperatorEqualTo(CExoLocString* thisPtr, CExoLocString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoLocString*, CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__OperatorEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoLocString__RemoveString__0(CExoLocString* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__RemoveString__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoLocString__RemoveString__1(CExoLocString* thisPtr, int32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLocString*, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLocString__RemoveString__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
