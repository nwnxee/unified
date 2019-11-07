#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CExoLocString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWPLAYERLISTITEM)
#endif



typedef int BOOL;


struct NWPLAYERLISTITEM
{
    CExoString sCommunityName;
    CExoLocString sLocFirstName;
    CExoLocString sLocLastName;
    BOOL bIsPrimaryPlayer;



#ifdef NWN_CLASS_EXTENSION_NWPLAYERLISTITEM
    NWN_CLASS_EXTENSION_NWPLAYERLISTITEM
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWPLAYERLISTITEM)
#endif

