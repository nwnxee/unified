#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoPackedFile.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoEncapsulatedFile)
#endif

struct ENCAPSULATED_HEADER;
struct ENCAPSULATED_RESLISTENTRY_E1;


typedef int BOOL;


struct CExoEncapsulatedFile : CExoPackedFile
{
    CExoLocString m_lsDescription;
    ENCAPSULATED_HEADER * m_pEncapsulatedHeader;
    ENCAPSULATED_RESLISTENTRY_E1 * m_pResListEntry;
    uint8_t m_nFileType;

    CExoEncapsulatedFile();
    ~CExoEncapsulatedFile();
    virtual void AddRefCount();
    virtual BOOL CloseFile();
    virtual void DeleteRefCount();
    virtual uint32_t GetResourceSize(RESID nID);
    virtual BOOL Initialize();
    virtual BOOL OpenFile();
    virtual BOOL OpenFile(uint8_t * pCipher);
    virtual uint32_t ReadResource(RESID nID, void * pData, uint32_t nSize, uint32_t nDataOffset);
    virtual BOOL LoadHeader(const char * expectOid, uint8_t nType = 0);
    virtual BOOL UnloadHeader();


#ifdef NWN_CLASS_EXTENSION_CExoEncapsulatedFile
    NWN_CLASS_EXTENSION_CExoEncapsulatedFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoEncapsulatedFile)
#endif

