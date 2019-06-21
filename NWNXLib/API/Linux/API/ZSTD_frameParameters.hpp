#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_frameParameters
{
    uint32_t contentSizeFlag;
    uint32_t checksumFlag;
    uint32_t noDictIDFlag;
};

}

}
