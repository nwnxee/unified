#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResNDB)
#endif



typedef int BOOL;


class CResNDB : public CRes
{
public:
    BOOL m_bLoaded;
    uint32_t m_nNDBNormalSize;
    uint8_t * m_pNDBData;

    CResNDB();
    ~CResNDB();
    uint8_t * GetNDBDataPtr();
    uint32_t GetNDBSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResNDB
    NWN_CLASS_EXTENSION_CResNDB
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResNDB)
#endif

