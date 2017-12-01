#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct piUDPPing
{
    uint8_t magic;
    uint8_t version;
    uint16_t trip;
    uint16_t ID_A;
    uint16_t ID_B;
};

}

}
