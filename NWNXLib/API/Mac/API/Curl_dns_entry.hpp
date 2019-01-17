#pragma once

#include <cstdint>

#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_addrinfo;

struct Curl_dns_entry
{
    Curl_addrinfo* addr;
    __time_t timestamp;
    int32_t inuse;
};

}

}
