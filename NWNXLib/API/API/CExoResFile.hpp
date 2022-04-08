#pragma once
#include "nwn_api.hpp"

#include "CExoPackedFile.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoResFile)
#endif

struct BIFFFILE_HEADER;
struct BIFFFILE_VARRESENTRY_E1;


typedef int BOOL;


enum BIFFFILE_Version
{
    BIFFFILE_V1,
    BIFFFILE_E1
};
struct CExoResFile : CExoPackedFile
{
    BIFFFILE_Version m_nVersion;
    BIFFFILE_HEADER * m_pBiffHeader;
    BIFFFILE_VARRESENTRY_E1 * m_pBiffVarResEntry;

    CExoResFile();
    ~CExoResFile();
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


#ifdef NWN_CLASS_EXTENSION_CExoResFile
    NWN_CLASS_EXTENSION_CExoResFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoResFile)
#endif

