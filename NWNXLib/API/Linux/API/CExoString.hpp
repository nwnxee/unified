#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoString
{
    char* m_sString;
    uint32_t m_nBufferLength;

    CExoString();
    CExoString(int32_t);
    CExoString(const CExoString&);
    CExoString(const char*);
    CExoString(const char*, int32_t);
    ~CExoString();
    float AsFLOAT();
    int32_t AsINT();
    CExoString AsTAG();
    int32_t CompareNoCase(const CExoString&);
    int32_t ComparePrefixNoCase(const CExoString&, int32_t);
    char* CStr();
    int32_t Find(const CExoString&, int32_t);
    int32_t Find(char, int32_t);
    int32_t FindNot(char, int32_t);
    int32_t GetLength();
    void Insert(const CExoString&, int32_t);
    int32_t IsEmpty();
    CExoString Left(int32_t);
    CExoString LowerCase();
    int32_t operator!=(const CExoString&);
    int32_t operator!=(const char*);
    char operator*(int32_t);
    CExoString operator+(const CExoString&);
    int32_t operator<(const CExoString&);
    int32_t operator<(const char*);
    int32_t operator<=(const CExoString&);
    int32_t operator<=(const char*);
    CExoString& operator=(const CExoString&);
    CExoString& operator=(const char*);
    int32_t operator==(const CExoString&);
    int32_t operator==(const char*);
    int32_t operator>(const CExoString&);
    int32_t operator>(const char*);
    int32_t operator>=(const CExoString&);
    int32_t operator>=(const char*);
    CExoString Right(int32_t);
    int32_t StripNonAlphaNumeric(int32_t, int32_t, int32_t);
    CExoString SubString(int32_t, int32_t);
    CExoString UpperCase();
};

void CExoString__CExoStringCtor__0(CExoString* thisPtr);
void CExoString__CExoStringCtor__1(CExoString* thisPtr, int32_t);
void CExoString__CExoStringCtor__2(CExoString* thisPtr, const CExoString&);
void CExoString__CExoStringCtor__3(CExoString* thisPtr, const char*);
void CExoString__CExoStringCtor__4(CExoString* thisPtr, const char*, int32_t);
void CExoString__CExoStringDtor(CExoString* thisPtr);
float CExoString__AsFLOAT(CExoString* thisPtr);
int32_t CExoString__AsINT(CExoString* thisPtr);
CExoString CExoString__AsTAG(CExoString* thisPtr);
int32_t CExoString__CompareNoCase(CExoString* thisPtr, const CExoString&);
int32_t CExoString__ComparePrefixNoCase(CExoString* thisPtr, const CExoString&, int32_t);
char* CExoString__CStr(CExoString* thisPtr);
int32_t CExoString__Find__0(CExoString* thisPtr, const CExoString&, int32_t);
int32_t CExoString__Find__1(CExoString* thisPtr, char, int32_t);
int32_t CExoString__FindNot(CExoString* thisPtr, char, int32_t);
int32_t CExoString__GetLength(CExoString* thisPtr);
void CExoString__Insert(CExoString* thisPtr, const CExoString&, int32_t);
int32_t CExoString__IsEmpty(CExoString* thisPtr);
CExoString CExoString__Left(CExoString* thisPtr, int32_t);
CExoString CExoString__LowerCase(CExoString* thisPtr);
int32_t CExoString__OperatorNotEqualTo__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorNotEqualTo__1(CExoString* thisPtr, const char*);
char CExoString__OperatorMultiplication(CExoString* thisPtr, int32_t);
CExoString CExoString__OperatorAddition(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorLesserThan__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorLesserThan__1(CExoString* thisPtr, const char*);
int32_t CExoString__OperatorLesserThanOrEqualTo__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorLesserThanOrEqualTo__1(CExoString* thisPtr, const char*);
CExoString& CExoString__OperatorAssignment__0(CExoString* thisPtr, const CExoString&);
CExoString& CExoString__OperatorAssignment__1(CExoString* thisPtr, const char*);
int32_t CExoString__OperatorEqualTo__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorEqualTo__1(CExoString* thisPtr, const char*);
int32_t CExoString__OperatorGreaterThan__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorGreaterThan__1(CExoString* thisPtr, const char*);
int32_t CExoString__OperatorGreaterThanOrEqualTo__0(CExoString* thisPtr, const CExoString&);
int32_t CExoString__OperatorGreaterThanOrEqualTo__1(CExoString* thisPtr, const char*);
CExoString CExoString__Right(CExoString* thisPtr, int32_t);
int32_t CExoString__StripNonAlphaNumeric(CExoString* thisPtr, int32_t, int32_t, int32_t);
CExoString CExoString__SubString(CExoString* thisPtr, int32_t, int32_t);
CExoString CExoString__UpperCase(CExoString* thisPtr);

}

}
