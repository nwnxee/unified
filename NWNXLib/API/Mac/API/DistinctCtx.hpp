#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct DistinctCtx
{
    uint8_t isTnct;
    uint8_t eTnctType;
    int32_t tabTnct;
    int32_t addrTnct;
};

}

}
