#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CExoFile.hpp"
#include "TLK_FILE_HEADER.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkFile)
#endif



typedef int BOOL;


struct CTlkFile : CExoFile
{
    TLK_FILE_HEADER m_header;

    CTlkFile(CExoString sFileName);
    CTlkFile(const void * pMemoryBuffer, int32_t nSize);
    virtual ~CTlkFile();
    BOOL ReadHeader();


#ifdef NWN_CLASS_EXTENSION_CTlkFile
    NWN_CLASS_EXTENSION_CTlkFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTlkFile)
#endif

