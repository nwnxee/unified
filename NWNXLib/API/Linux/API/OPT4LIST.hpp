#pragma once

#include <cstdint>

#include "LIST4.hpp"

namespace NWNXLib {

namespace API {

struct OPT4LIST
{
    LIST4 list;
    uint16_t minLink;
    uint32_t maxTime;
    uint32_t minTime;
    char currentPrioCount;
};

}

}
