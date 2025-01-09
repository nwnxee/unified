#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExtendedServerInfo)
#endif



typedef int BOOL;


struct CExtendedServerInfo
{
    BOOL m_bPasswordRequired;
    uint8_t m_nMinLevel;
    uint8_t m_nMaxLevel;
    uint8_t m_nPlayerCount;
    uint8_t m_nMaxPlayers;
    CExoString m_sModuleName;
    BOOL m_bAllowLocalVaultChars;
    BOOL m_bPauseAndPlay;
    BOOL m_bMultiplayerEnabled;
    uint8_t m_nPVPSetting;
    CExoString m_sServerName;
    CExoString m_sModuleDescription;
    CExoString m_sGameDetails;
    CExoString m_sBuild;
    int16_t m_nGameType;
    BOOL m_bOnePartyOnly;
    BOOL m_bLegalChars;
    BOOL m_bItemRestrict;

    CExtendedServerInfo * operator=(class CNetLayerSessionInfo & pIn);


#ifdef NWN_CLASS_EXTENSION_CExtendedServerInfo
    NWN_CLASS_EXTENSION_CExtendedServerInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExtendedServerInfo)
#endif

