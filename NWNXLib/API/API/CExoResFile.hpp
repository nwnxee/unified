#pragma once
#include "nwn_api.hpp"

#include "CExoPackedFile.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoResFile)
#endif

class BIFFFILE_HEADER;
class BIFFFILE_VARRESENTRY_E1;


typedef int BOOL;


enum BIFFFILE_Version
{
    BIFFFILE_V1,
    BIFFFILE_E1
};
class CExoResFile : public CExoPackedFile
{
public:
    BIFFFILE_Version m_nVersion;
    BIFFFILE_HEADER * m_pBiffHeader;
    BIFFFILE_VARRESENTRY_E1 * m_pBiffVarResEntry;

    CExoResFile();
    ~CExoResFile();
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


#ifdef NWN_CLASS_EXTENSION_CExoResFile
    NWN_CLASS_EXTENSION_CExoResFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoResFile)
#endif

