#pragma once

#include <cstdint>

#include "in_addr.hpp"

namespace NWNXLib {

namespace API {

struct sockaddr_in
{
    uint16_t sin_family;
    uint16_t sin_port;
    in_addr sin_addr;
    uint8_t sin_zero[8];
};

}

}
