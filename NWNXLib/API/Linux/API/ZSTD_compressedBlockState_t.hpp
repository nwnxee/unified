#pragma once

#include <cstdint>

#include "ZSTD_entropyCTables_t.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_compressedBlockState_t
{
    ZSTD_entropyCTables_t entropy;
    uint32_t rep[3];
};

}

}
