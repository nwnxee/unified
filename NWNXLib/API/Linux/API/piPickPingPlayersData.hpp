#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct piPlayer;

struct piPickPingPlayersData
{
    void* peer;
    piPlayer** players;
    int32_t max;
    int32_t num;
};

}

}
