#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerNetOptions)
#endif



typedef int BOOL;


class CServerNetOptions
{
public:
    int32_t m_nGameRegion;
    CExoString m_szGameDetails;
    int16_t m_GameType;
    BOOL m_bNetworkRelaysEnabled;



#ifdef NWN_CLASS_EXTENSION_CServerNetOptions
    NWN_CLASS_EXTENSION_CServerNetOptions
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerNetOptions)
#endif

