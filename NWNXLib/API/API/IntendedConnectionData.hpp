#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(IntendedConnectionData)
#endif





struct IntendedConnectionData
{
    uint8_t m_nConnectionType;
    int32_t m_nPlayerLanguage;
    CExoString m_sPlayerName;
    CExoString m_sCDKey;
    CExoString m_sLegacyCDKey;



#ifdef NWN_CLASS_EXTENSION_IntendedConnectionData
    NWN_CLASS_EXTENSION_IntendedConnectionData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(IntendedConnectionData)
#endif

