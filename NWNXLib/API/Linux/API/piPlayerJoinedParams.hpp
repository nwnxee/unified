#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerJoinedParams
{
    RoomType roomType;
    char* nick;
};

}

}
