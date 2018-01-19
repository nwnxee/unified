#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct LobbyDataUpdate_t
{
    uint64_t m_ulSteamIDLobby;
    uint64_t m_ulSteamIDMember;
    uint8_t m_bSuccess;
};

}

}
