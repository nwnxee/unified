#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CHATChannelMode;

struct ciCallbackGetChannelModeParams
{
    CHATBool success;
    char* channel;
    CHATChannelMode* mode;
};

}

}
