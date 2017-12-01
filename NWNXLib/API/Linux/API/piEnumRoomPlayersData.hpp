#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"
#include "unknown_piEnumRoomPlayersCallback.hpp"

namespace NWNXLib {

namespace API {

struct piEnumRoomPlayersData
{
    void* peer;
    RoomType roomType;
    int32_t count;
    piEnumRoomPlayersCallback callback;
    void* param;
};

}

}
