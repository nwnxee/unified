#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xQueryTextExtentsReply
{
    CARD8 type;
    uint8_t drawDirection;
    uint16_t sequenceNumber;
    uint32_t length;
    int16_t fontAscent;
    int16_t fontDescent;
    int16_t overallAscent;
    int16_t overallDescent;
    int32_t overallWidth;
    int32_t overallLeft;
    int32_t overallRight;
    uint32_t pad;
};

}

}
