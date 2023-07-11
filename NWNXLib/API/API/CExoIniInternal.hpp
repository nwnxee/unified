#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoIniInternal)
#endif



typedef int BOOL;


class CExoIniInternal
{
    CExoString * m_pFileNames;

    CExoIniInternal(CExoString sUserDirectory);
    ~CExoIniInternal();
    BOOL ReadIniEntry(CExoString & sValue, const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry);
    BOOL WriteIniEntry(const CExoString & sValue, const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry, BOOL stripIfEmpty);


#ifdef NWN_CLASS_EXTENSION_CExoIniInternal
    NWN_CLASS_EXTENSION_CExoIniInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoIniInternal)
#endif

