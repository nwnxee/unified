#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct LobbyEnter_t
{
    uint64_t m_ulSteamIDLobby;
    uint32_t m_rgfChatPermissions;
    int32_t m_bLocked;
    uint32_t m_EChatRoomEnterResponse;
};

}

}
