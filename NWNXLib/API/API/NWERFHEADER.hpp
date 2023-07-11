#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWERFHEADER)
#endif





class NWERFHEADER
{
    char sVersion[8];
    uint32_t nStringCount;
    uint32_t nTotalStringSize;
    uint32_t nEntryCount;
    uint32_t nOffsetToStringList;
    uint32_t nOffsetToKeyList;
    uint32_t nOffsetToResourceList;
    uint32_t nBuildYear;
    uint32_t nBuildDay;
    uint32_t nDescriptionStrRef;
    uint8_t nUnused[116];



#ifdef NWN_CLASS_EXTENSION_NWERFHEADER
    NWN_CLASS_EXTENSION_NWERFHEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWERFHEADER)
#endif

