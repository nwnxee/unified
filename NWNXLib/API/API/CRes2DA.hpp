#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CRes2DA)
#endif

class EXO2DAHEADER;


typedef int BOOL;


class CRes2DA : public CRes
{
public:
    BOOL m_bLoaded;
    uint32_t m_n2DANormalSize;
    uint8_t * m_p2DAData;
    EXO2DAHEADER * m_p2DAHeader;

    CRes2DA();
    ~CRes2DA();
    uint8_t * Get2DADataPtr();
    EXO2DAHEADER * Get2DAHeaderPtr();
    uint32_t Get2DASize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CRes2DA
    NWN_CLASS_EXTENSION_CRes2DA
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CRes2DA)
#endif

