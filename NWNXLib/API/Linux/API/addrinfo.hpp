#pragma once

#include <cstdint>

#include "unknown___socklen_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sockaddr;

struct addrinfo
{
    int32_t ai_flags;
    int32_t ai_family;
    int32_t ai_socktype;
    int32_t ai_protocol;
    __socklen_t ai_addrlen;
    sockaddr* ai_addr;
    char* ai_canonname;
    addrinfo* ai_next;
};

}

}
