#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct InLoop
{
    int32_t iCur;
    int32_t addrInTop;
    int32_t iBase;
    int32_t nPrefix;
    uint8_t eEndLoopOp;
};

}

}
