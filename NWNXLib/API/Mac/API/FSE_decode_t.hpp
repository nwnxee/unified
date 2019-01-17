#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FSE_decode_t
{
    uint16_t newState;
    uint8_t symbol;
    uint8_t nbBits;
};

}

}
