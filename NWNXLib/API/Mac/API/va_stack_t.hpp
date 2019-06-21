#pragma once

#include <cstdint>

#include "unknown_FormatType.hpp"
#include "unknown_TLS_45744FE314B1BCEBBF557915BBDC1D4D.hpp"

namespace NWNXLib {

namespace API {

struct va_stack_t
{
    FormatType type;
    int32_t flags;
    int32_t width;
    int32_t precision;
    TLS_45744FE314B1BCEBBF557915BBDC1D4D data;
};

}

}
