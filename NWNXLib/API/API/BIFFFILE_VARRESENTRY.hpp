#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(BIFFFILE_VARRESENTRY)
#endif





struct BIFFFILE_VARRESENTRY
{
    uint32_t nID;
    uint32_t nOffset;
    uint32_t nSize;
    uint32_t nType;



#ifdef NWN_CLASS_EXTENSION_BIFFFILE_VARRESENTRY
    NWN_CLASS_EXTENSION_BIFFFILE_VARRESENTRY
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(BIFFFILE_VARRESENTRY)
#endif

