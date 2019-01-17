#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_frameProgression
{
    uint64_t ingested;
    uint64_t consumed;
    uint64_t produced;
};

}

}
