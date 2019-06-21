#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct nodeElt_s
{
    uint32_t count;
    uint16_t parent;
    uint8_t byte;
    uint8_t nbBits;
};

}

}
