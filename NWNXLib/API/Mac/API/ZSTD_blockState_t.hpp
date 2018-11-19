#pragma once

#include <cstdint>

#include "ZSTD_matchState_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTD_compressedBlockState_t;

struct ZSTD_blockState_t
{
    ZSTD_compressedBlockState_t* prevCBlock;
    ZSTD_compressedBlockState_t* nextCBlock;
    ZSTD_matchState_t matchState;
};

}

}
