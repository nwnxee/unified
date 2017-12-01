#pragma once

#include <cstdint>

#include "unknown_MessageType.hpp"
#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piRoomMessageParams
{
    RoomType roomType;
    char* nick;
    char* message;
    MessageType messageType;
};

}

}
