#pragma once

#include <cstdint>

#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct hostcache_prune_data
{
    int32_t cache_timeout;
    __time_t now;
};

}

}
