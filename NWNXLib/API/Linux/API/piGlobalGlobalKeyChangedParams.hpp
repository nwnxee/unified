#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piGlobalGlobalKeyChangedParams
{
    RoomType roomType;
    char* nick;
    char* key;
    char* value;
};

}

}
