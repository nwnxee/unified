#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piKickedParams
{
    RoomType roomType;
    char* nick;
    char* reason;
};

}

}
