#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackKickedParams
{
    char* channel;
    char* user;
    char* reason;
};

}

}
