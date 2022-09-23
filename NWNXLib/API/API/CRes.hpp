#pragma once
#include "nwn_api.hpp"

#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CRes)
#endif

struct CKeyTableEntry;


typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;


struct CRes
{
    uint16_t m_nDemands;
    RESID m_nID;
    uint32_t m_status;
    void * m_pResource;
    CKeyTableEntry * m_pKeyEntry;
    uint32_t m_nSize;
    uint32_t m_nRefs;
    BOOL m_bAllocHeaderData;
    BOOL m_bAllocTrailingData;
    CExoLinkedListPosition m_pos;
    BOOL m_bAllowCaching;

    CRes();
    CRes(RESID nNewID);
    virtual ~CRes();
    void * Demand();
    BOOL ReadRaw(int32_t nSize, char * pBuffer);
    void Dump(BOOL bRemove = false);
    void * GetData();
    int32_t GetDemands();
    virtual int32_t GetFixedResourceSize();
    virtual int32_t GetFixedResourceDataOffset();
    RESID GetID();
    int32_t GetSize();
    virtual BOOL OnResourceFreed();
    virtual BOOL OnResourceServiced();
    int32_t Release();
    int32_t Request();
    void SetID(RESID nNewID);


#ifdef NWN_CLASS_EXTENSION_CRes
    NWN_CLASS_EXTENSION_CRes
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CRes)
#endif

