#pragma once

#include <cstdint>

#include "unknown_peerEnumPlayersCallback.hpp"

namespace NWNXLib {

namespace API {

struct piEnumPlayersData
{
    peerEnumPlayersCallback callback;
    void* param;
};

}

}
