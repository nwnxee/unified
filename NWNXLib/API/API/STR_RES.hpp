#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(STR_RES)
#endif





class STR_RES
{
    CExoString szText;
    CResRef cSoundResRef;
    float fSoundLength;



#ifdef NWN_CLASS_EXTENSION_STR_RES
    NWN_CLASS_EXTENSION_STR_RES
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(STR_RES)
#endif

