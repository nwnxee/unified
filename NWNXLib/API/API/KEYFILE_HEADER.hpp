#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(KEYFILE_HEADER)
#endif





struct KEYFILE_HEADER
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nResFiles;
    uint32_t nKeys;
    uint32_t nOffsetToFileTable;
    uint32_t nOffsetToKeyTable;



#ifdef NWN_CLASS_EXTENSION_KEYFILE_HEADER
    NWN_CLASS_EXTENSION_KEYFILE_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(KEYFILE_HEADER)
#endif

