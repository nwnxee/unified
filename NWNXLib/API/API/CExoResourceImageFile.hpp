#pragma once
#include "nwn_api.hpp"

#include "CExoPackedFile.hpp"
#include "ENCAPSULATED_KEYLISTENTRY.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoResourceImageFile)
#endif

struct ENCAPSULATED_HEADER;
struct ENCAPSULATED_RESLISTENTRY;


typedef int BOOL;


struct CExoResourceImageFile : CExoPackedFile
{
    uint8_t * m_pResourceImage;

    CExoResourceImageFile();
    ~CExoResourceImageFile();
    virtual void AddRefCount();
    virtual void AddAsyncRefCount();
    virtual BOOL CloseFile();
    virtual BOOL CloseAsyncFile();
    virtual void DeleteRefCount();
    virtual void DeleteAsyncRefCount();
    virtual uint32_t GetResourceSize(RESID nID);
    virtual BOOL Initialize();
    virtual BOOL OpenFile();
    virtual BOOL OpenFile(uint8_t * pCipher);
    virtual BOOL OpenAsyncFile();
    virtual uint32_t ReadResource(RESID nID, void * pData, uint32_t nSize, uint32_t nDataOffset);
    virtual void ReadResourceAsync(RESID nID, void * pData, uint32_t nSize, uint32_t nDataOffset);
    virtual BOOL LoadHeader(const char * expectOid, uint8_t nType = 0);
    virtual BOOL UnloadHeader();
    virtual void * GetResource(RESID nID);
    ENCAPSULATED_KEYLISTENTRY * * GetKeyList();
    ENCAPSULATED_KEYLISTENTRY GetKeyListEntry(uint32_t nIndex);
    ENCAPSULATED_RESLISTENTRY * GetResourceListEntry(RESID nID);
    ENCAPSULATED_HEADER * GetHeader();


#ifdef NWN_CLASS_EXTENSION_CExoResourceImageFile
    NWN_CLASS_EXTENSION_CExoResourceImageFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoResourceImageFile)
#endif

