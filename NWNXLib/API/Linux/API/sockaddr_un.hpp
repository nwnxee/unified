#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sockaddr_un
{
    uint16_t sun_family;
    char sun_path[108];
};

}

}
