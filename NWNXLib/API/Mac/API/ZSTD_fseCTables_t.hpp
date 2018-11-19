#pragma once

#include <cstdint>

#include "unknown_FSE_repeat.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_fseCTables_t
{
    uint32_t offcodeCTable[193];
    uint32_t matchlengthCTable[363];
    uint32_t litlengthCTable[329];
    FSE_repeat offcode_repeatMode;
    FSE_repeat matchlength_repeatMode;
    FSE_repeat litlength_repeatMode;
};

}

}
