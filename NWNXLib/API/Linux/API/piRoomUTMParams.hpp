#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"
#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piRoomUTMParams
{
    RoomType roomType;
    char* nick;
    char* command;
    char* parameters;
    PEERBool authenticated;
};

}

}
