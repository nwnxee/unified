#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct VdbeOpList
{
    uint8_t opcode;
    char p1;
    char p2;
    char p3;
};

}

}
