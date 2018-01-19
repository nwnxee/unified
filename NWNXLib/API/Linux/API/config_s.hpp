#pragma once

#include <cstdint>

#include "unknown_compress_func.hpp"

namespace NWNXLib {

namespace API {

struct config_s
{
    uint16_t good_length;
    uint16_t max_lazy;
    uint16_t nice_length;
    uint16_t max_chain;
    compress_func func;
};

}

}
