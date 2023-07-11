#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResDWK)
#endif



typedef int BOOL;


class CResDWK : CRes
{
    BOOL m_bLoaded;
    uint32_t m_nDWKNormalSize;
    uint8_t * m_pDWKData;

    CResDWK();
    ~CResDWK();
    uint8_t * GetDWKDataPtr();
    uint32_t GetDWKSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResDWK
    NWN_CLASS_EXTENSION_CResDWK
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResDWK)
#endif

