#pragma once

#include <cstdint>

#include "ZSTD_window_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ldmEntry_t;

struct ldmState_t
{
    ZSTD_window_t window;
    ldmEntry_t* hashTable;
    uint8_t* bucketOffsets;
    uint64_t hashPower;
};

}

}
