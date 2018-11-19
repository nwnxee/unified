#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WalCkptInfo
{
    uint32_t nBackfill;
    uint32_t aReadMark[5];
    uint8_t aLock[8];
    uint32_t nBackfillAttempted;
    uint32_t notUsed0;
};

}

}
