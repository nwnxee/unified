#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(BIFFFILE_HEADER)
#endif





struct BIFFFILE_HEADER
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nNumVariableResources;
    uint32_t nNumFixedResources;
    uint32_t nTableOffset;
    char cOid[24];
    uint8_t pReserved[8];



#ifdef NWN_CLASS_EXTENSION_BIFFFILE_HEADER
    NWN_CLASS_EXTENSION_BIFFFILE_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(BIFFFILE_HEADER)
#endif

