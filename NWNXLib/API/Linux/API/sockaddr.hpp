#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sockaddr
{
    uint16_t sa_family;
    char sa_data[14];
};

}

}
