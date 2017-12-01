#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piRoomKeyChangedParams
{
    RoomType roomType;
    char* nick;
    char* key;
    char* value;
};

}

}
