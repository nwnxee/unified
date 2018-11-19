#pragma once

#include <cstdint>

#include "curl_certinfo.hpp"
#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct PureInfo
{
    int32_t httpcode;
    int32_t httpproxycode;
    int32_t httpversion;
    __time_t filetime;
    bool timecond;
    int32_t header_size;
    int32_t request_size;
    uint32_t proxyauthavail;
    uint32_t httpauthavail;
    int32_t numconnects;
    char* contenttype;
    char* wouldredirect;
    char conn_primary_ip[46];
    int32_t conn_primary_port;
    char conn_local_ip[46];
    int32_t conn_local_port;
    const char* conn_scheme;
    uint32_t conn_protocol;
    curl_certinfo certs;
};

}

}
