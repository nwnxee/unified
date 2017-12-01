#pragma once

#include <cstdint>

#include "CHATChannelMode.hpp"
#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piRoomModeChangedParams
{
    RoomType roomType;
    CHATChannelMode mode;
};

}

}
