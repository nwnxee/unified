#pragma once

#include <cstdint>

#include "unknown_RoomType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerChangedNickParams
{
    RoomType roomType;
    char* oldNick;
    char* newNick;
};

}

}
