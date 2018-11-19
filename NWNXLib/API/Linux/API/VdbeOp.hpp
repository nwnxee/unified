#pragma once

#include <cstdint>

#include "unknown_p4union.hpp"

namespace NWNXLib {

namespace API {

struct VdbeOp
{
    uint8_t opcode;
    char p4type;
    uint16_t p5;
    int32_t p1;
    int32_t p2;
    int32_t p3;
    p4union p4;
};

}

}
