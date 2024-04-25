#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResRef)
#endif

struct CExoString;


typedef int BOOL;
typedef uint8_t RESREF[16];


struct CResRef
{
    char m_resRef[16 + 1];

    CResRef() { memset(m_resRef, 0, sizeof(m_resRef)); }
    CResRef(const RESREF resRef) { *this = resRef; }
    CResRef(const CExoString &sName) { *this = sName; }
    CResRef(const char *pName) { *this = pName; }
    CResRef(const char *pName, uint8_t nLength) { InitFromCharArray(pName, nLength); }
    void CopyToString(CExoString &str) const { str = GetResRefStr(); }
    void CopyToString(char *pStr) const { strcpy(pStr, GetResRefStr()); }
    int32_t operator!=(const CResRef & cResRef) const { return !operator==(cResRef); }
    int32_t operator!=(const CExoString &sName) const { return !operator==(sName); }
    int32_t operator!=(const char *pName) const { return !operator==(pName); }
    int32_t operator==(const CResRef & cResRef) const;
    int32_t operator==(const CExoString & sName) const;
    int32_t operator==(const char * name) const;
    CResRef& operator=(const CResRef & cResRef);
    CResRef& operator=(const RESREF resRef);
    CResRef& operator=(const CExoString &sName);
    CResRef& operator=(const char *pName);
    CResRef& operator+=(const CExoString &sName);
    char* GetResRef() { return (char *)m_resRef; }
    const char* GetResRefStr() const { return (const char *)m_resRef; }
    BOOL IsValid() const { return GetResRefStr()[0] != '\0'; }
    uint8_t GetLength() const { return strlen(GetResRefStr()); }
    void InitFromCharArray(const char *str, int32_t size = -1);

    // Custom utility impl, missing from the API
    CResRef(const CResRef& other) = default;

#ifdef NWN_CLASS_EXTENSION_CResRef
    NWN_CLASS_EXTENSION_CResRef
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResRef)
#endif

