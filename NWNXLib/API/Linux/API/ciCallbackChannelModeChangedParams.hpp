#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CHATChannelMode;

struct ciCallbackChannelModeChangedParams
{
    char* channel;
    CHATChannelMode* mode;
};

}

}
