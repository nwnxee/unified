#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CERFString)
#endif

struct CExoFile;


typedef int BOOL;


struct CERFString
{
    uint32_t m_nLanguageID;
    uint32_t m_nSize;
    const char * m_pText;

    CExoString GetText();
    void SetText(const CExoString & sString);
    CERFString();
    ~CERFString();
    BOOL Read();
    BOOL Reset();
    BOOL Write(CExoFile & cOutFile);


#ifdef NWN_CLASS_EXTENSION_CERFString
    NWN_CLASS_EXTENSION_CERFString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CERFString)
#endif

