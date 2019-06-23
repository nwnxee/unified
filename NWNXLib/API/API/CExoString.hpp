#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoString)
#endif

struct CResRef;


typedef int BOOL;


struct CExoString
{
    char * m_sString;
    uint32_t m_nBufferLength;

    CExoString();
    CExoString(const CResRef & source);
    CExoString(const char * source);
    CExoString(const CExoString & source);
    CExoString(const char * source, int32_t length);
    CExoString(int32_t value);
    ~CExoString();
    CExoString & operator=(const CExoString & string);
    CExoString & operator=(const char * string);
    BOOL operator==(const CExoString & string);
    BOOL operator==(const char * string);
    BOOL operator!=(const CExoString & string);
    BOOL operator!=(const char * string);
    BOOL operator<(const CExoString & string);
    BOOL operator<(const char * string);
    BOOL operator>(const CExoString & string);
    BOOL operator>(const char * string);
    BOOL operator<=(const CExoString & string);
    BOOL operator<=(const char * string);
    BOOL operator>=(const CExoString & string);
    BOOL operator>=(const char * string);
    char operator[](int32_t position);
    CExoString operator+(const CExoString & string);
    int32_t AsINT();
    float AsFLOAT();
    char * CStr();
    int32_t Find(const CExoString & string, int32_t position = 0);
    int32_t Find(char ch, int32_t position = 0);
    int32_t FindNot(char ch, int32_t position = 0);
    void Format(const char * format);
    int32_t GetLength();
    void Insert(const CExoString & string, int32_t position);
    BOOL IsEmpty();
    CExoString Left(int32_t count);
    CExoString LowerCase();
    CExoString Right(int32_t count);
    CExoString SubString(int32_t start, int32_t count = - 1);
    CExoString UpperCase();
    BOOL CompareNoCase(const CExoString & sString);
    BOOL ComparePrefixNoCase(const CExoString & sString, int32_t nSize);
    BOOL StripNonAlphaNumeric(BOOL bFileName = true, BOOL bEmail = false, BOOL bMasterServer = false);
    CExoString Strip(bool leading = true, bool trailing = true, const char * set = " \t\v\r\n\f");
    CExoString AsTAG();


#ifdef NWN_CLASS_EXTENSION_CExoString
    NWN_CLASS_EXTENSION_CExoString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoString)
#endif

