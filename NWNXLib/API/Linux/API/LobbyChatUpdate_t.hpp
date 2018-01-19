#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct LobbyChatUpdate_t
{
    uint64_t m_ulSteamIDLobby;
    uint64_t m_ulSteamIDUserChanged;
    uint64_t m_ulSteamIDMakingChange;
    uint32_t m_rgfChatMemberStateChange;
};

}

}
