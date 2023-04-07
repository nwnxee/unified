#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoPackedFile)
#endif

struct CExoFile;


typedef int BOOL;


struct CExoPackedFile
{
    CExoString m_sFileName;
    uint16_t m_wDrives;
    uint32_t m_nFileSize;
    CExoFile * m_pExoFile;
    int32_t m_nRefCount;
    BOOL m_bLoaded;
    BOOL m_bHeaderLoaded;

    CExoPackedFile();
    virtual ~CExoPackedFile();
    virtual void AddRefCount();
    virtual BOOL CloseFile();
    virtual void DeleteRefCount();
    virtual void DeleteAsyncRefCount();
    virtual CExoFile * GetFile();
    virtual uint32_t GetResourceSize(RESID nID);
    virtual BOOL Initialize();
    virtual BOOL OpenFile();
    virtual BOOL OpenFile(uint8_t * pCipher);
    virtual uint32_t ReadResource(RESID nID, void * pData, uint32_t nSize, uint32_t nDataOffset);
    virtual void ReadResourceAsync(RESID nID, void * pData, uint32_t nSize, uint32_t nDataOffset);
    virtual BOOL LoadHeader(const char * expectOid, uint8_t nType = 0);
    virtual BOOL UnloadHeader();
    uint32_t ReadNWCompressedBuffer(void * outBuffer, uint32_t outBufSize, uint32_t readLength);


#ifdef NWN_CLASS_EXTENSION_CExoPackedFile
    NWN_CLASS_EXTENSION_CExoPackedFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoPackedFile)
#endif

