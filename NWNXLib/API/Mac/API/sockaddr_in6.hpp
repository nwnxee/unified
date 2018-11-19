#pragma once

#include <cstdint>

#include "in6_addr.hpp"

namespace NWNXLib {

namespace API {

struct sockaddr_in6
{
    uint16_t sin6_family;
    uint16_t sin6_port;
    uint32_t sin6_flowinfo;
    in6_addr sin6_addr;
    uint32_t sin6_scope_id;
};

}

}
