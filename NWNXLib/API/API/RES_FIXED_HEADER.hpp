#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(RES_FIXED_HEADER)
#endif





class RES_FIXED_HEADER
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nNumber;
    uint32_t nSize;
    uint32_t nTableOffset;



#ifdef NWN_CLASS_EXTENSION_RES_FIXED_HEADER
    NWN_CLASS_EXTENSION_RES_FIXED_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(RES_FIXED_HEADER)
#endif

