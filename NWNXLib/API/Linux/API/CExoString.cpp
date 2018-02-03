#include "CExoString.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CExoString::CExoString()
{
    CExoString__CExoStringCtor__0(this);
}

CExoString::CExoString(int32_t a0)
{
    CExoString__CExoStringCtor__1(this, a0);
}

CExoString::CExoString(const CExoString& a0)
{
    CExoString__CExoStringCtor__2(this, a0);
}

CExoString::CExoString(const char* a0)
{
    CExoString__CExoStringCtor__3(this, a0);
}

CExoString::CExoString(const CResRef& a0)
{
    CExoString__CExoStringCtor__4(this, a0);
}

CExoString::CExoString(const char* a0, int32_t a1)
{
    CExoString__CExoStringCtor__5(this, a0, a1);
}

CExoString::~CExoString()
{
    CExoString__CExoStringDtor(this);
}

float CExoString::AsFLOAT()
{
    return CExoString__AsFLOAT(this);
}

int32_t CExoString::AsINT()
{
    return CExoString__AsINT(this);
}

CExoString CExoString::AsTAG()
{
    return CExoString__AsTAG(this);
}

int32_t CExoString::CompareNoCase(const CExoString& a0)
{
    return CExoString__CompareNoCase(this, a0);
}

int32_t CExoString::ComparePrefixNoCase(const CExoString& a0, int32_t a1)
{
    return CExoString__ComparePrefixNoCase(this, a0, a1);
}

char* CExoString::CStr()
{
    return CExoString__CStr(this);
}

int32_t CExoString::Find(const CExoString& a0, int32_t a1)
{
    return CExoString__Find__0(this, a0, a1);
}

int32_t CExoString::Find(char a0, int32_t a1)
{
    return CExoString__Find__1(this, a0, a1);
}

int32_t CExoString::FindNot(char a0, int32_t a1)
{
    return CExoString__FindNot(this, a0, a1);
}

int32_t CExoString::GetLength()
{
    return CExoString__GetLength(this);
}

void CExoString::Insert(const CExoString& a0, int32_t a1)
{
    return CExoString__Insert(this, a0, a1);
}

int32_t CExoString::IsEmpty()
{
    return CExoString__IsEmpty(this);
}

CExoString CExoString::Left(int32_t a0)
{
    return CExoString__Left(this, a0);
}

CExoString CExoString::LowerCase()
{
    return CExoString__LowerCase(this);
}

int32_t CExoString::operator!=(const CExoString& a0)
{
    return CExoString__OperatorNotEqualTo__0(this, a0);
}

int32_t CExoString::operator!=(const char* a0)
{
    return CExoString__OperatorNotEqualTo__1(this, a0);
}

char CExoString::operator*(int32_t a0)
{
    return CExoString__OperatorMultiplication(this, a0);
}

CExoString CExoString::operator+(const CExoString& a0)
{
    return CExoString__OperatorAddition(this, a0);
}

int32_t CExoString::operator<(const CExoString& a0)
{
    return CExoString__OperatorLesserThan__0(this, a0);
}

int32_t CExoString::operator<(const char* a0)
{
    return CExoString__OperatorLesserThan__1(this, a0);
}

int32_t CExoString::operator<=(const CExoString& a0)
{
    return CExoString__OperatorLesserThanOrEqualTo__0(this, a0);
}

int32_t CExoString::operator<=(const char* a0)
{
    return CExoString__OperatorLesserThanOrEqualTo__1(this, a0);
}

CExoString& CExoString::operator=(const CExoString& a0)
{
    return CExoString__OperatorAssignment__0(this, a0);
}

CExoString& CExoString::operator=(const char* a0)
{
    return CExoString__OperatorAssignment__1(this, a0);
}

int32_t CExoString::operator==(const CExoString& a0)
{
    return CExoString__OperatorEqualTo__0(this, a0);
}

int32_t CExoString::operator==(const char* a0)
{
    return CExoString__OperatorEqualTo__1(this, a0);
}

int32_t CExoString::operator>(const CExoString& a0)
{
    return CExoString__OperatorGreaterThan__0(this, a0);
}

int32_t CExoString::operator>(const char* a0)
{
    return CExoString__OperatorGreaterThan__1(this, a0);
}

int32_t CExoString::operator>=(const CExoString& a0)
{
    return CExoString__OperatorGreaterThanOrEqualTo__0(this, a0);
}

int32_t CExoString::operator>=(const char* a0)
{
    return CExoString__OperatorGreaterThanOrEqualTo__1(this, a0);
}

CExoString CExoString::Right(int32_t a0)
{
    return CExoString__Right(this, a0);
}

int32_t CExoString::StripNonAlphaNumeric(int32_t a0, int32_t a1, int32_t a2)
{
    return CExoString__StripNonAlphaNumeric(this, a0, a1, a2);
}

CExoString CExoString::SubString(int32_t a0, int32_t a1)
{
    return CExoString__SubString(this, a0, a1);
}

CExoString CExoString::UpperCase()
{
    return CExoString__UpperCase(this);
}

void CExoString__CExoStringCtor__0(CExoString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoString__CExoStringCtor__1(CExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoString__CExoStringCtor__2(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoString__CExoStringCtor__3(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoString__CExoStringCtor__4(CExoString* thisPtr, const CResRef& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__4);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoString__CExoStringCtor__5(CExoString* thisPtr, const char* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, const char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringCtor__5);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CExoString__CExoStringDtor(CExoString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CExoStringDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

float CExoString__AsFLOAT(CExoString* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__AsFLOAT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoString__AsINT(CExoString* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__AsINT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CExoString__AsTAG(CExoString* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__AsTAG);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoString__CompareNoCase(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CompareNoCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__ComparePrefixNoCase(CExoString* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__ComparePrefixNoCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

char* CExoString__CStr(CExoString* thisPtr)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__CStr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoString__Find__0(CExoString* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__Find__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoString__Find__1(CExoString* thisPtr, char a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__Find__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoString__FindNot(CExoString* thisPtr, char a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__FindNot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoString__GetLength(CExoString* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__GetLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoString__Insert(CExoString* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoString*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__Insert);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoString__IsEmpty(CExoString* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__IsEmpty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CExoString__Left(CExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__Left);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CExoString__LowerCase(CExoString* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__LowerCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoString__OperatorNotEqualTo__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorNotEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorNotEqualTo__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorNotEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CExoString__OperatorMultiplication(CExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorMultiplication);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CExoString__OperatorAddition(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorAddition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorLesserThan__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorLesserThan__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorLesserThan__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorLesserThan__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorLesserThanOrEqualTo__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorLesserThanOrEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorLesserThanOrEqualTo__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorLesserThanOrEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString& CExoString__OperatorAssignment__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CExoString&(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorAssignment__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString& CExoString__OperatorAssignment__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = CExoString&(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorAssignment__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorEqualTo__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorEqualTo__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorGreaterThan__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorGreaterThan__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorGreaterThan__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorGreaterThan__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorGreaterThanOrEqualTo__0(CExoString* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorGreaterThanOrEqualTo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__OperatorGreaterThanOrEqualTo__1(CExoString* thisPtr, const char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__OperatorGreaterThanOrEqualTo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CExoString__Right(CExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__Right);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoString__StripNonAlphaNumeric(CExoString* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoString*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__StripNonAlphaNumeric);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CExoString__SubString(CExoString* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__SubString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CExoString__UpperCase(CExoString* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoString__UpperCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
