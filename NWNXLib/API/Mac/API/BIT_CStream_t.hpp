#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct BIT_CStream_t
{
    uint32_t bitContainer;
    uint32_t bitPos;
    char* startPtr;
    char* ptr;
    char* endPtr;
};

}

}
