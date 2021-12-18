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
    RESREF m_resRefLowerCase;
    RESREF m_resRef;

    CResRef();
    CResRef(const RESREF resRef);
    CResRef(const CExoString & sName);
    CResRef(const char * pName);
    CResRef(const uint8_t * pName, uint8_t nLength);
    void CopyToString(CExoString & str) const;
    void CopyToString(char * pStr) const;
    int32_t operator!=(const CResRef & cResRef) const;
    int32_t operator!=(const CExoString & sName) const;
    int32_t operator!=(const char * pName) const;
    int32_t operator==(const CResRef & cResRef) const;
    int32_t operator==(const CExoString & sName) const;
    int32_t operator==(const char * name) const;
    int operator!();
    CResRef operator=(const CResRef & cResRef);
    CResRef operator=(const RESREF resRef);
    CResRef operator=(const CExoString & sName);
    CResRef operator=(const char * pName);
    CResRef operator+=(const CExoString & sName);
    void GetResRef(RESREF resRef) const;
    char * GetResRef() const;
    char * GetResRefStr() const;
    BOOL IsValid() const;
    uint8_t GetLength() const;

    // Custom utility impl, missing from the API
    CResRef(const CResRef& other) = default;

#ifdef NWN_CLASS_EXTENSION_CResRef
    NWN_CLASS_EXTENSION_CResRef
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResRef)
#endif

