#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XColor
{
    uint32_t pixel;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    char flags;
    char pad;
};

}

}
