#pragma once
#include "nwn_api.hpp"

#include <string>


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
    CExoString(const std::string & other);
    CExoString & operator=(const std::string & other);
    void string() const;
    ~CExoString();
    CExoString & operator=(const CExoString & string);
    CExoString & operator=(const char * string);
    BOOL operator==(const CExoString & string) const;
    BOOL operator==(const char * string) const;
    BOOL operator!=(const CExoString & string) const;
    BOOL operator!=(const char * string) const;
    BOOL operator<(const CExoString & string) const;
    BOOL operator<(const char * string) const;
    BOOL operator>(const CExoString & string) const;
    BOOL operator>(const char * string) const;
    BOOL operator<=(const CExoString & string) const;
    BOOL operator<=(const char * string) const;
    BOOL operator>=(const CExoString & string) const;
    BOOL operator>=(const char * string) const;
    char operator[](int32_t position) const;
    CExoString operator+(const CExoString & string) const;
    int32_t AsINT() const;
    float AsFLOAT() const;
    char * CStr() const;
    int32_t Find(const CExoString & string, int32_t position = 0) const;
    int32_t Find(char ch, int32_t position = 0) const;
    int32_t FindNot(char ch, int32_t position = 0) const;
    void Format(const char * format);
    int32_t GetLength() const;
    void Insert(const CExoString & string, int32_t position);
    BOOL IsEmpty() const;
    CExoString Left(int32_t count) const;
    CExoString LowerCase() const;
    CExoString Right(int32_t count) const;
    CExoString SubString(int32_t start, int32_t count = - 1) const;
    CExoString UpperCase() const;
    BOOL CompareNoCase(const CExoString & sString) const;
    BOOL ComparePrefixNoCase(const CExoString & sString, int32_t nSize) const;
    BOOL StripNonAlphaNumeric(BOOL bFileName = true, BOOL bEmail = false, BOOL bMasterServer = false);
    CExoString Strip(bool leading = true, bool trailing = true, const char * set = " \t\v\r\n\f") const;
    CExoString AsTAG() const;


#ifdef NWN_CLASS_EXTENSION_CExoString
    NWN_CLASS_EXTENSION_CExoString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoString)
#endif

