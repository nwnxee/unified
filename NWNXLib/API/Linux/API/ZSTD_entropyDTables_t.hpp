#pragma once

#include <cstdint>

#include "ZSTD_seqSymbol.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_entropyDTables_t
{
    ZSTD_seqSymbol LLTable[513];
    ZSTD_seqSymbol OFTable[257];
    ZSTD_seqSymbol MLTable[513];
    uint32_t hufTable[4097];
    uint32_t workspace[512];
    uint32_t rep[3];
};

}

}
