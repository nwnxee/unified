#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerFlagsChangedParams
{
    RoomType roomType;
    char* nick;
    int32_t oldFlags;
    int32_t newFlags;
};

}

}
