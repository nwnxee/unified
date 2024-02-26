#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayerPlayerCDKeyInfo)
#endif



typedef int BOOL;


struct CNetLayerPlayerCDKeyInfo
{
    CExoString sPublic;
    CExoString sResponse;
    BOOL bValidated;



#ifdef NWN_CLASS_EXTENSION_CNetLayerPlayerCDKeyInfo
    NWN_CLASS_EXTENSION_CNetLayerPlayerCDKeyInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayerPlayerCDKeyInfo)
#endif

