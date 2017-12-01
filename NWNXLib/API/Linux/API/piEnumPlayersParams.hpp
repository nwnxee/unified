#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piEnumPlayersParams
{
    RoomType roomType;
    int32_t index;
    char* nick;
    int32_t flags;
};

}

}
