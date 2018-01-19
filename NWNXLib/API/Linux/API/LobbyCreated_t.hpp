#pragma once

#include <cstdint>

#include "unknown_EResult.hpp"

namespace NWNXLib {

namespace API {

struct LobbyCreated_t
{
    EResult m_eResult;
    uint64_t m_ulSteamIDLobby;
};

}

}
