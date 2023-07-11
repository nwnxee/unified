#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(TLK_FILE_HEADER)
#endif





class TLK_FILE_HEADER
{
    uint32_t fileType;
    uint32_t versionNum;
    uint32_t LanguageType;
    uint32_t nStrEntries;
    uint32_t strEntriesOffset;



#ifdef NWN_CLASS_EXTENSION_TLK_FILE_HEADER
    NWN_CLASS_EXTENSION_TLK_FILE_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(TLK_FILE_HEADER)
#endif

