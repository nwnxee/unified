#pragma once
#include "nwn_api.hpp"

#include "CExtendedServerInfo.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CFriendPresenceInfo)
#endif





struct CFriendPresenceInfo : CExtendedServerInfo
{
    CExoString m_sFriendName;
    CExoString m_sServerName;
    CExoString m_sServerAddress;

    void Decode(CExoString json);


#ifdef NWN_CLASS_EXTENSION_CFriendPresenceInfo
    NWN_CLASS_EXTENSION_CFriendPresenceInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CFriendPresenceInfo)
#endif

