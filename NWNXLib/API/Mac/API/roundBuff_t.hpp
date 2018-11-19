#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct roundBuff_t
{
    uint8_t* buffer;
    uint32_t capacity;
    uint32_t pos;
};

}

}
