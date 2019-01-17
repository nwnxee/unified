#pragma once

#include <cstdint>

#include "ssl_primary_config.hpp"

namespace NWNXLib {

namespace API {

struct curl_ssl_session
{
    char* name;
    char* conn_to_host;
    const char* scheme;
    void* sessionid;
    uint32_t idsize;
    int32_t age;
    int32_t remote_port;
    int32_t conn_to_port;
    ssl_primary_config ssl_config;
};

}

}
