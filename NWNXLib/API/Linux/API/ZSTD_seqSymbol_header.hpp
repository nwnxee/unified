#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_seqSymbol_header
{
    uint32_t fastMode;
    uint32_t tableLog;
};

}

}
