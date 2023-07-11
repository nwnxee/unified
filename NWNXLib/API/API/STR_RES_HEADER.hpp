#pragma once
#include "nwn_api.hpp"

#include "STR_RES_HEADER_OLD.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(STR_RES_HEADER)
#endif





class STR_RES_HEADER : STR_RES_HEADER_OLD
{
    float fSoundLength;



#ifdef NWN_CLASS_EXTENSION_STR_RES_HEADER
    NWN_CLASS_EXTENSION_STR_RES_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(STR_RES_HEADER)
#endif

