#pragma once

#include <cstdint>

#include "z_stream_s.hpp"
#include "unknown_zlibInitState.hpp"

namespace NWNXLib {

namespace API {

struct zlib_params
{
    zlibInitState zlib_init;
    uint32_t trailerlen;
    z_stream_s z;
};

}

}
