#pragma once

#include <cstdint>

#include "unknown_ZSTD_frameType_e.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_frameHeader
{
    uint64_t frameContentSize;
    uint64_t windowSize;
    uint32_t blockSizeMax;
    ZSTD_frameType_e frameType;
    uint32_t headerSize;
    uint32_t dictID;
    uint32_t checksumFlag;
};

}

}
