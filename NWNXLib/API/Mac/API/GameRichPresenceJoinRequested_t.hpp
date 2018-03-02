#pragma once

#include <cstdint>

#include "CSteamID.hpp"

namespace NWNXLib {

namespace API {

struct GameRichPresenceJoinRequested_t
{
    CSteamID m_steamIDFriend;
    char m_rgchConnect[256];
};

}

}
