#pragma once

#include <cstdint>

#include "unknown_YYMINORTYPE.hpp"

namespace NWNXLib {

namespace API {

struct yyStackEntry
{
    uint16_t stateno;
    uint16_t major;
    YYMINORTYPE minor;
};

}

}
