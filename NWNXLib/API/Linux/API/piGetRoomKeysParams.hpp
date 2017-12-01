#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piGetRoomKeysParams
{
    RoomType roomType;
    char* nick;
    int32_t num;
    char** keys;
    char** values;
};

}

}
