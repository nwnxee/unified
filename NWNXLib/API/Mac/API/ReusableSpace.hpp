#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ReusableSpace
{
    uint8_t* pSpace;
    int32_t nFree;
    int32_t nNeeded;
};

}

}
