#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResPWK)
#endif



typedef int BOOL;


class CResPWK : CRes
{
    BOOL m_bLoaded;
    uint32_t m_nPWKNormalSize;
    uint8_t * m_pPWKData;

    CResPWK();
    ~CResPWK();
    uint8_t * GetPWKDataPtr();
    uint32_t GetPWKSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResPWK
    NWN_CLASS_EXTENSION_CResPWK
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResPWK)
#endif

