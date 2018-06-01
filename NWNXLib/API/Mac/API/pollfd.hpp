#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct pollfd
{
    int32_t fd;
    int16_t events;
    int16_t revents;
};

}

}
