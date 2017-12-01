#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piCleanseRoomCacheMapData
{
    void* peer;
    RoomType roomType;
};

}

}
