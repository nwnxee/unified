#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct piPlayer;

struct piPickXpingPlayerData
{
    void* peer;
    piPlayer* player;
};

}

}
