#pragma once

#include <cstdint>

#include "CSteamID.hpp"

namespace NWNXLib {

namespace API {

struct GameLobbyJoinRequested_t
{
    CSteamID m_steamIDLobby;
    CSteamID m_steamIDFriend;
};

}

}
