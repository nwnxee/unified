#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackUserChangedNickParams
{
    char* channel;
    char* oldNick;
    char* newNick;
};

}

}
