#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerLeftParams
{
    RoomType roomType;
    char* nick;
    char* reason;
};

}

}
