#pragma once

#include <cstdint>

#include "sockaddr.hpp"

namespace NWNXLib {

namespace API {

struct curl_sockaddr
{
    int32_t family;
    int32_t socktype;
    int32_t protocol;
    uint32_t addrlen;
    sockaddr addr;
};

}

}
