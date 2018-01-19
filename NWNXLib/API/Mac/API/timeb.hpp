#pragma once

#include <cstdint>

#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct timeb
{
    __time_t time;
    uint16_t millitm;
    int16_t timezone;
    int16_t dstflag;
};

}

}
