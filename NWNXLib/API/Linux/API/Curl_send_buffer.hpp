#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Curl_send_buffer
{
    char* buffer;
    uint32_t size_max;
    uint32_t size_used;
};

}

}
