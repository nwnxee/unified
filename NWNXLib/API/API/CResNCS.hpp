#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResNCS)
#endif



typedef int BOOL;


class CResNCS : public CRes
{
public:
    BOOL m_bLoaded;
    uint32_t m_nNCSNormalSize;
    uint8_t * m_pNCSData;

    CResNCS();
    ~CResNCS();
    uint8_t * GetNCSDataPtr();
    uint32_t GetNCSSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResNCS
    NWN_CLASS_EXTENSION_CResNCS
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResNCS)
#endif

