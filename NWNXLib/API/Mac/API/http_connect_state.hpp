#pragma once

#include <cstdint>

#include "unknown_TLS_39BB10A5031A9859147330F63E646D71.hpp"

namespace NWNXLib {

namespace API {

struct http_connect_state
{
    char connect_buffer[16384];
    int32_t perline;
    int32_t keepon;
    char* line_start;
    char* ptr;
    int64_t cl;
    bool chunked_encoding;
    TLS_39BB10A5031A9859147330F63E646D71 tunnel_state;
    bool close_connection;
};

}

}
