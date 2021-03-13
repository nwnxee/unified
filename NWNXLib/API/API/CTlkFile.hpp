#pragma once
#include "nwn_api.hpp"

#include "CExoFile.hpp"
#include "CExoString.hpp"
#include "STR_RES.hpp"
#include "TLK_FILE_HEADER.hpp"
#include <unordered_map>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkFile)
#endif



typedef int BOOL;


struct CTlkFile : CExoFile
{
    TLK_FILE_HEADER m_header;
    std::unordered_map<STRREF, STR_RES> m_cache;

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

