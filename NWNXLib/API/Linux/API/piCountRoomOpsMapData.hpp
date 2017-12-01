#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piCountRoomOpsMapData
{
    int32_t count;
    RoomType roomType;
    const char* exclude;
};

}

}
