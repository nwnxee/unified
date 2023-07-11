#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResWOK)
#endif



typedef int BOOL;


class CResWOK : CRes
{
    BOOL m_bLoaded;
    uint32_t m_nWOKNormalSize;
    uint8_t * m_pWOKData;

    CResWOK();
    ~CResWOK();
    uint8_t * GetWOKDataPtr();
    uint32_t GetWOKSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResWOK
    NWN_CLASS_EXTENSION_CResWOK
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResWOK)
#endif

