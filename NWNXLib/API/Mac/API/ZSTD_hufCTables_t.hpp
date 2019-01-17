#pragma once

#include <cstdint>

#include "unknown_HUF_repeat.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_hufCTables_t
{
    uint32_t CTable[256];
    HUF_repeat repeatMode;
};

}

}
