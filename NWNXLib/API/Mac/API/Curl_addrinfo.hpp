#pragma once

#include <cstdint>

#include "unknown_socklen_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sockaddr;

struct Curl_addrinfo
{
    int32_t ai_flags;
    int32_t ai_family;
    int32_t ai_socktype;
    int32_t ai_protocol;
    socklen_t ai_addrlen;
    char* ai_canonname;
    sockaddr* ai_addr;
    Curl_addrinfo* ai_next;
};

}

}
