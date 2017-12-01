#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"

namespace NWNXLib {

namespace API {

struct piReadyChangedParams
{
    char* nick;
    PEERBool ready;
};

}

}
