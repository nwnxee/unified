#pragma once

#include <cstdint>

#include "unknown_volatileht_slot.hpp"
#include "unknown_volatileu32.hpp"

namespace NWNXLib {

namespace API {

struct WalHashLoc
{
    volatileht_slot* aHash;
    volatileu32* aPgno;
    uint32_t iZero;
};

}

}
