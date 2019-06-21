#pragma once

#include <cstdint>

#include "CSteamID.hpp"
#include "unknown_EResult.hpp"

namespace NWNXLib {

namespace API {

struct UserStatsReceived_t
{
    uint64_t m_nGameID;
    EResult m_eResult;
    CSteamID m_steamIDUser;
};

}

}
