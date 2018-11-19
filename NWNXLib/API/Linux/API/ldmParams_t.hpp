#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ldmParams_t
{
    uint32_t enableLdm;
    uint32_t hashLog;
    uint32_t bucketSizeLog;
    uint32_t minMatchLength;
    uint32_t hashEveryLog;
    uint32_t windowLog;
};

}

}
