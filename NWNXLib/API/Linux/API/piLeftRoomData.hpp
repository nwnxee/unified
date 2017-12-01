#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piLeftRoomData
{
    void* peer;
    RoomType roomType;
};

}

}
