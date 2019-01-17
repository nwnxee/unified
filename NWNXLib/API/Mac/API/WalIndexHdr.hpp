#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WalIndexHdr
{
    uint32_t iVersion;
    uint32_t unused;
    uint32_t iChange;
    uint8_t isInit;
    uint8_t bigEndCksum;
    uint16_t szPage;
    uint32_t mxFrame;
    uint32_t nPage;
    uint32_t aFrameCksum[2];
    uint32_t aSalt[2];
    uint32_t aCksum[2];
};

}

}
