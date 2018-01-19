#pragma once

#include <cstdint>

#include "unknown_CARD8.hpp"

namespace NWNXLib {

namespace API {

struct xGenericReply
{
    CARD8 type;
    CARD8 data1;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t data00;
    uint32_t data01;
    uint32_t data02;
    uint32_t data03;
    uint32_t data04;
    uint32_t data05;
};

}

}
