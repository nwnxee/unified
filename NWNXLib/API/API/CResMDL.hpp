#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResMDL)
#endif



typedef int BOOL;


struct CResMDL : CRes
{
    BOOL m_bLoaded;
    uint32_t m_nMDLNormalSize;
    uint8_t * m_pMDLData;

    CResMDL();
    ~CResMDL();
    uint8_t * GetMDLDataPtr();
    uint32_t GetMDLSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResMDL
    NWN_CLASS_EXTENSION_CResMDL
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResMDL)
#endif

