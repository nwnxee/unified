#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResRef)
#endif

struct CExoString;


typedef uint8_t RESREF[16];
typedef int BOOL;


struct CResRef
{
    RESREF m_resRefLowerCase;
    RESREF m_resRef;

    CResRef();
    CResRef(const RESREF resRef);
    CResRef(const CExoString & sName);
    CResRef(const char * pName);
    CResRef(const uint8_t * pName, uint8_t nLength);
    void CopyToString(CExoString & str);
    void CopyToString(char * pStr);
    int32_t operator!=(const CResRef & cResRef);
    int32_t operator!=(const CExoString & sName);
    int32_t operator!=(const char * pName);
    int32_t operator==(const CResRef & cResRef);
    int32_t operator==(const CExoString & sName);
    int32_t operator==(const char * name);
    int operator!();
    CResRef operator=(const CResRef & cResRef);
    CResRef operator=(const RESREF resRef);
    CResRef operator=(const CExoString & sName);
    CResRef operator=(const char * pName);
    CResRef operator+=(const CExoString & sName);
    void GetResRef(RESREF resRef);
    char * GetResRef();
    char * GetResRefStr();
    BOOL IsValid();
    uint8_t GetLength();


#ifdef NWN_CLASS_EXTENSION_CResRef
    NWN_CLASS_EXTENSION_CResRef
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResRef)
#endif

