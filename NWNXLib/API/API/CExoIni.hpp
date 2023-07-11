#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoIni)
#endif

class CExoIniInternal;


typedef int BOOL;


class CExoIni
{
    CExoIniInternal * m_pcExoIniInternal;

    CExoIni(CExoString sUserDirectory);
    ~CExoIni();
    BOOL ReadIniEntry(CExoString & sValue, const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry);
    BOOL WriteIniEntry(const CExoString & sValue, const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry, BOOL stripIfEmpty = false);
    int32_t GetIntOr(const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry, int32_t nOtherwise);
    float GetFloatOr(const int32_t & idxIniFile, const CExoString & sSection, const CExoString & sEntry, float nOtherwise);


#ifdef NWN_CLASS_EXTENSION_CExoIni
    NWN_CLASS_EXTENSION_CExoIni
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoIni)
#endif

