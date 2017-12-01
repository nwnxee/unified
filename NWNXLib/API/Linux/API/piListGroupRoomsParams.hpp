#pragma once

#include <cstdint>

#include "unknown__SBServer.hpp"

namespace NWNXLib {

namespace API {

struct piListGroupRoomsParams
{
    int32_t groupID;
    _SBServer* server;
    char* name;
    int32_t numWaiting;
    int32_t maxWaiting;
    int32_t numGames;
    int32_t numPlaying;
};

}

}
