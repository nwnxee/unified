#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerInfoParams
{
    RoomType roomType;
    char* nick;
    uint32_t IP;
    int32_t profileID;
};

}

}
