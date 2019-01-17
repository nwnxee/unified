#pragma once

#include <cstdint>

#include "unknown_ZSTD_OptPrice_e.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ZSTD_entropyCTables_t;
struct ZSTD_match_t;
struct ZSTD_optimal_t;

struct optState_t
{
    uint32_t* litFreq;
    uint32_t* litLengthFreq;
    uint32_t* matchLengthFreq;
    uint32_t* offCodeFreq;
    ZSTD_match_t* matchTable;
    ZSTD_optimal_t* priceTable;
    uint32_t litSum;
    uint32_t litLengthSum;
    uint32_t matchLengthSum;
    uint32_t offCodeSum;
    uint32_t litSumBasePrice;
    uint32_t litLengthSumBasePrice;
    uint32_t matchLengthSumBasePrice;
    uint32_t offCodeSumBasePrice;
    ZSTD_OptPrice_e priceType;
    const ZSTD_entropyCTables_t* symbolCosts;
};

}

}
