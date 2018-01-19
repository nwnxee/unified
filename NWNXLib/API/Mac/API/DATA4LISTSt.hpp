#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct RELATE4St;

struct DATA4LISTSt
{
    RELATE4St** pointers;
    uint32_t memAllocated;
    int32_t pointersTot;
    int32_t pointersUsed;
};

}

}
