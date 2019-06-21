#pragma once

#include <cstdint>

#include "WalSegment.hpp"

namespace NWNXLib {

namespace API {

struct WalIterator
{
    int32_t iPrior;
    int32_t nSegment;
    WalSegment aSegment[1];
};

}

}
