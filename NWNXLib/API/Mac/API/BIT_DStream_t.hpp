#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct BIT_DStream_t
{
    uint32_t bitContainer;
    uint32_t bitsConsumed;
    const char* ptr;
    const char* start;
    const char* limitPtr;
};

}

}
