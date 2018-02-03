#include "CResRef.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CResRef::CResRef()
{
    CResRef__CResRefCtor__0(this);
}

CResRef::CResRef(const CExoString& a0)
{
    CResRef__CResRefCtor__1(this, a0);
}

CResRef::CResRef(const char* a0)
{
    CResRef__CResRefCtor__2(this, a0);
}

CResRef::CResRef(const unsigned char* a0)
{
    CResRef__CResRefCtor__3(this, a0);
}

CResRef::CResRef(const unsigned char* a0, unsigned char a1)
{
    CResRef__CResRefCtor__4(this, a0, a1);
}

void CResRef::CopyToString(CExoString& a0)
{
    return CResRef__CopyToString__0(this, a0);
}

void CResRef::CopyToString(char* a0)
{
    return CResRef__CopyToString__1(this, a0);
}

unsigned char CResRef::GetLength()
{
    return CResRef__GetLength(this);
}

char* CResRef::GetResRef()
{
    return CResRef__GetResRef__0(this);
}

void CResRef::GetResRef(unsigned char* a0)
{
    return CResRef__GetResRef__1(this, a0);
}

char* CResRef::GetResRefStr()
{
    return CResRef__GetResRefStr(this);
}

int32_t CResRef::IsValid()
{
    return CResRef__IsValid(this);
}

int32_t CResRef::operator!()
{
    return CResRef__OperatorUndefined(this);
}

int32_t CResRef::operator!=(const CExoString& a0)
{
    return CResRef__OperatorNotEqualTo__0(this, a0);
}

int32_t CResRef::operator!=(const char* a0)
{
    return CResRef__OperatorNotEqualTo__1(this, a0);
}

int32_t CResRef::operator!=(const CResRef& a0)
{
    return CResRef__OperatorNotEqualTo__2(this, a0);
}

CResRef CResRef::operator+=(const CExoString& a0)
{
    return CResRef__OperatorAdditionAssignment(this, a0);
}

CResRef CResRef::operator=(const CExoString& a0)
{
    return CResRef__OperatorAssignment__0(this, a0);
}

CResRef CResRef::operator=(const char* a0)
{
    return CResRef__OperatorAssignment__1(this, a0);
}

CResRef CResRef::operator=(const unsigned char* a0)
{
    return CResRef__OperatorAssignment__2(this, a0);
}

CResRef CResRef::operator=(const CResRef& a0)
{
    return CResRef__OperatorAssignment__3(this, a0);
}

int32_t CResRef::operator==(const CExoString& a0)
{
    return CResRef__OperatorEqualTo__0(this, a0);
}

int32_t CResRef::operator==(const char* a0)
{
    return CResRef__OperatorEqualTo__1(this, a0);
}

int32_t CResRef::operator==(const CResRef& a0)
{
    return CResRef__OperatorEqualTo__2(this, a0);
}

void CResRef__CResRefCtor__0(CResRef* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CResRefCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResRef__CResRefCtor__1(CResRef* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CResRefCtor__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CResRef__CResRefCtor__2(CResRef* thisPtr, const char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CResRefCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CResRef__CResRefCtor__3(CResRef* thisPtr, const unsigned char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, const unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CResRefCtor__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CResRef__CResRefCtor__4(CResRef* thisPtr, const unsigned char* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, const unsigned char*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CResRefCtor__4);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CResRef__CopyToString__0(CResRef* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CopyToString__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CResRef__CopyToString__1(CResRef* thisPtr, char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__CopyToString__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CResRef__GetLength(CResRef* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__GetLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char* CResRef__GetResRef__0(CResRef* thisPtr)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__GetResRef__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CResRef__GetResRef__1(CResRef* thisPtr, unsigned char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResRef*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__GetResRef__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char* CResRef__GetResRefStr(CResRef* thisPtr)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__GetResRefStr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResRef__IsValid(CResRef* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__IsValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResRef__OperatorUndefined(CResRef* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorUndefined);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResRef__OperatorNotEqualTo__0(CResRef* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorNotEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResRef__OperatorNotEqualTo__1(CResRef* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorNotEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResRef__OperatorNotEqualTo__2(CResRef* thisPtr, const CResRef& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorNotEqualTo__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CResRef__OperatorAdditionAssignment(CResRef* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResRef*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorAdditionAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CResRef__OperatorAssignment__0(CResRef* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResRef*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorAssignment__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CResRef__OperatorAssignment__1(CResRef* thisPtr, const char* a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResRef*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorAssignment__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CResRef__OperatorAssignment__2(CResRef* thisPtr, const unsigned char* a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResRef*, const unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorAssignment__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CResRef__OperatorAssignment__3(CResRef* thisPtr, const CResRef& a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResRef*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorAssignment__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResRef__OperatorEqualTo__0(CResRef* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResRef__OperatorEqualTo__1(CResRef* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResRef__OperatorEqualTo__2(CResRef* thisPtr, const CResRef& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResRef*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResRef__OperatorEqualTo__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
