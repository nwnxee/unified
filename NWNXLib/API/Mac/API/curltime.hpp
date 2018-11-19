#pragma once

#include <cstdint>

#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct curltime
{
    __time_t tv_sec;
    int32_t tv_usec;
};

}

}
