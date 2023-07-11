#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SSubNetProfile)
#endif





class SSubNetProfile
{
    uint32_t nPlayerID;
    CExoString sPlayerName;
    CExoString sCDPublicKey;
    uint64_t nStartTime;
    uint64_t nTotalBytesSent;
    uint64_t nTotalBytesReceived;



#ifdef NWN_CLASS_EXTENSION_SSubNetProfile
    NWN_CLASS_EXTENSION_SSubNetProfile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SSubNetProfile)
#endif

