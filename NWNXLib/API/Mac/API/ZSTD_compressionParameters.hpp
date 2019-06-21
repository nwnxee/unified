#pragma once

#include <cstdint>

#include "unknown_ZSTD_strategy.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_compressionParameters
{
    uint32_t windowLog;
    uint32_t chainLog;
    uint32_t hashLog;
    uint32_t searchLog;
    uint32_t searchLength;
    uint32_t targetLength;
    ZSTD_strategy strategy;
};

}

}
