#pragma once

#include <cstdint>

#include "LIST4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

struct MEM4st
{
    l4linkSt link;
    LIST4 chunks;
    LIST4 pieces;
    int32_t unitStart;
    uint32_t unitSize;
    int32_t unitExpand;
    int32_t nRepeat;
    int32_t nUsed;
};

}

}
