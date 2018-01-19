#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CNetLayerSessionInfo.hpp"

namespace NWNXLib {

namespace API {

struct CExtendedServerInfo
{
    int32_t m_bPasswordRequired;
    uint8_t m_nMinLevel;
    uint8_t m_nMaxLevel;
    uint8_t m_nPlayerCount;
    uint8_t m_nMaxPlayers;
    CExoString m_sModuleName;
    int32_t m_bAllowLocalVaultChars;
    int32_t m_bPauseAndPlay;
    int32_t m_bMultiplayerEnabled;
    uint8_t m_nPVPSetting;
    uint8_t m_nExpansionPacksRequired;
    CExoString m_sModuleDescription;
    CExoString m_sGameDetails;
    CExoString m_sBuild;
    int16_t m_nGameType;
    int32_t m_bOnePartyOnly;
    int32_t m_bLegalChars;
    int32_t m_bItemRestrict;

    CExtendedServerInfo* operator=(CNetLayerSessionInfo&);
};

CExtendedServerInfo* CExtendedServerInfo__OperatorAssignment(CExtendedServerInfo* thisPtr, CNetLayerSessionInfo&);

}

}
