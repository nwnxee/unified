#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piFindPlayerByIndexData
{
    int32_t index;
    int32_t count;
    RoomType roomType;
};

}

}
