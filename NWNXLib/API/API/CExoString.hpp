#pragma once
#include "nwn_api.hpp"

#include <string>
#include <vector>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoString)
#endif

struct CResRef;


typedef int BOOL;


struct CExoString
{
    char * m_sString;
    uint32_t m_nStringLength;
    uint32_t m_nBufferLength;

    CExoString() : m_sString(nullptr) { InitFromCharArray(nullptr); }
    CExoString(CExoString&& other) : m_sString(nullptr)
    {
        Clear(false);
        Steal(&other);
    }
    CExoString& operator=(CExoString&& other)
    {
        if (this == &other) return *this;
        Steal(&other);
        return *this;
    }
    explicit CExoString(const CResRef & source);
    CExoString(const char * source) : m_sString(nullptr) { InitFromCharArray(source); }
    CExoString(const CExoString & source) : m_sString(nullptr) { InitFromCharArray(source.CStr(), source.GetLength()); }
    CExoString(const char * source, int32_t length) : m_sString(nullptr) { InitFromCharArray(source, length); }
    static CExoString ToString(int32_t value);
    CExoString(const std::string & other) : m_sString(nullptr) { InitFromCharArray(other.c_str(), other.size()); }
    CExoString& operator = (const std::string& other) { return InitFromCharArray(other.c_str(), other.size()); }
    operator std::string() const { return std::string(CStr()); }
    size_t size() const { return GetLength(); }
    const char * c_str() const { return CStr(); }
    ~CExoString() { Clear(); }
    CExoString& operator=(const CExoString & string) { return InitFromCharArray(string.CStr(), string.GetLength()); }
    CExoString& operator=(const char * string) { return InitFromCharArray(string); }
    BOOL operator==(const CExoString & string) const
    {
        if (GetLength() != string.GetLength())
            return false;
        if (m_sString == nullptr)
            return true;
        return strcmp(CStr(), string.CStr()) == 0;
    }
    BOOL operator==(const char * string) const
    {
        if (string == nullptr || string[0] == '\0')
            return GetLength() == 0;
        return strcmp(CStr(), string) == 0;
    }
    BOOL operator!=(const CExoString & string) const { return ! operator==(string); }
    BOOL operator!=(const char * string) const { return ! operator==(string); }
    BOOL operator<(const CExoString & string) const { return strcmp(CStr(), string.CStr()) < 0; }
    BOOL operator<(const char * string) const { return strcmp(CStr(), (string != nullptr) ? string : "") < 0; }
    BOOL operator>(const CExoString & string) const { return strcmp(CStr(), string.CStr()) > 0; }
    BOOL operator>(const char * string) const { return strcmp(CStr(), (string != nullptr) ? string : "") > 0; }
    BOOL operator<=(const CExoString & string) const { return strcmp(CStr(), string.CStr()) <= 0; }
    BOOL operator<=(const char * string) const { return strcmp(CStr(), (string != nullptr) ? string : "") <= 0; }
    BOOL operator>=(const CExoString & string) const { return strcmp(CStr(), string.CStr()) >= 0; }
    BOOL operator>=(const char * string) const { return strcmp(CStr(), (string != nullptr) ? string : "") >= 0; }
    char operator [] (uint32_t position) const { return (position > GetLength()) ? '\0' : CStr()[position]; }
    CExoString operator + (const CExoString &string) const;
    int32_t AsINT() const { return atoi(CStr()); }
    float AsFLOAT() const { return (float)atof(CStr()); }
    const char* CStr() const { return m_sString ? m_sString : ""; }
    int32_t Find(const CExoString & string, int32_t position = 0) const;
    int32_t Find(char ch, int32_t position = 0) const;
    int32_t FindNot(char ch, int32_t position = 0) const;
    CExoString RemoveAll(const char * c) const;
    CExoString RemoveAllExcept(const char * c) const;
    void Format(const char * format, ...);

    template<typename ... T>
    static CExoString F(const char* fmt, T&& ... args)
    {
        CExoString f;
        f.Format(fmt, args...);
        return f;
    }
    inline uint32_t GetLength() const
    {
        return m_nStringLength;
    }
    void Insert(const CExoString & string, uint32_t position);
    BOOL IsEmpty() const { return GetLength() == 0; }
    CExoString Left(uint32_t count) const;
    CExoString LowerCase() const;
    CExoString Right(uint32_t count) const;
    CExoString SubString(uint32_t start, uint32_t count=~0) const;
    CExoString UpperCase() const;
    BOOL CompareNoCase(const CExoString & sString) const;
    BOOL ComparePrefixNoCase(const CExoString & sString, int32_t nSize) const;
    BOOL StripNonAlphaNumeric(BOOL bFileName = true, BOOL bEmail = false, BOOL bMasterServer = false);
    CExoString Strip(bool leading = true, bool trailing = true, const char * set = " \t\v\r\n\f") const;
    CExoString AsTAG() const;
    int32_t GetHash() const;
    std::vector<CExoString> Split(const CExoString & delimiter) const;
    static CExoString FormatBytes(uint64_t bytes);
    static CExoString FormatDuration(uint64_t span, int compact_levels = 4, int min_level = 1, bool label_fields = true, const char* separator = " ");

    void Clear(BOOL bDelete = true)
    {
        if (bDelete)
            delete[] m_sString;
        m_sString = 0;
        m_nStringLength = 0;
        m_nBufferLength = 0;
    }
    void Steal(CExoString *other)
    {
        Clear();
        m_sString = other->m_sString;
        m_nStringLength = other->m_nStringLength;
        m_nBufferLength = other->m_nBufferLength;
        other->Clear(false);
    }
    char *Relinquish()
    {
        char *buf = m_sString;
        Clear(false);
        return buf;
    }
    void Allocate(uint32_t size)
    {
        Clear();
        if (size > 0)
        {
            m_nBufferLength = size;
            m_sString = new char[m_nBufferLength];
            SetLength(size-1);
        }
    }
    void SetLength(uint32_t len)
    {
        m_sString[len] = '\0';
        m_nStringLength = len;
    }
    CExoString &InitFromCharArray(const char *str, uint32_t len = ~0)
    {
        if (len != 0 && str != nullptr && str[0] != '\0')
        {
            len = (len == 0xFFFFFFFF) ? strlen(str) : len;
            if (str != m_sString)
            {
                Allocate(len+1);
                memcpy(m_sString, str, len);
            }
            else
            {
                SetLength(len);
            }
        }
        else
        {
            Clear();
        }
        return *this;
    }

#ifdef NWN_CLASS_EXTENSION_CExoString
    NWN_CLASS_EXTENSION_CExoString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoString)
#endif

namespace std {
template <>
struct hash<CExoString>
{
    std::size_t operator()(const CExoString& k) const
    {
        return (size_t)k.GetHash();
    }
};
}
