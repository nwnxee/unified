#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZSTD_window_t
{
    const uint8_t* nextSrc;
    const uint8_t* base;
    const uint8_t* dictBase;
    uint32_t dictLimit;
    uint32_t lowLimit;
};

}

}
