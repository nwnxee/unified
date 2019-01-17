#pragma once

#include <cstdint>

#include "unknown_ZSTD_dictContentType_e.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_prefixDict_s
{
    const void* dict;
    uint32_t dictSize;
    ZSTD_dictContentType_e dictContentType;
};

}

}
