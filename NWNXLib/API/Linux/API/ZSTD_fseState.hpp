#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTD_seqSymbol;

struct ZSTD_fseState
{
    uint32_t state;
    const ZSTD_seqSymbol* table;
};

}

}
