#pragma once

#include <cstdint>

#include "CGameID.hpp"
#include "CSteamID.hpp"

namespace NWNXLib {

namespace API {

struct FriendGameInfo_t
{
    CGameID m_gameID;
    uint32_t m_unGameIP;
    uint16_t m_usGamePort;
    uint16_t m_usQueryPort;
    CSteamID m_steamIDLobby;
};

}

}
