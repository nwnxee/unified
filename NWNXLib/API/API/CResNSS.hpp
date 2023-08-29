#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResNSS)
#endif



typedef int BOOL;


class CResNSS : public CRes
{
public:
    BOOL m_bLoaded;
    uint32_t m_nNSSNormalSize;
    uint8_t * m_pNSSData;

    CResNSS();
    ~CResNSS();
    uint8_t * GetNSSDataPtr();
    uint32_t GetNSSSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResNSS
    NWN_CLASS_EXTENSION_CResNSS
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResNSS)
#endif

