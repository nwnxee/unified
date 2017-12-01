#pragma once

#include <cstdint>

#include "unknown_PEERJoinResult.hpp"
#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piJoinRoomParams
{
    PEERJoinResult result;
    RoomType roomType;
};

}

}
