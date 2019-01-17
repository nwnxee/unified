#pragma once

#include <cstdint>

#include "hostname.hpp"
#include "unknown_curl_proxytype.hpp"

namespace NWNXLib {

namespace API {

struct proxy_info
{
    hostname host;
    int32_t port;
    curl_proxytype proxytype;
    char* user;
    char* passwd;
};

}

}
