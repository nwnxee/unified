#pragma once

#include <cstdint>

#include "unknown_curl_read_callback.hpp"

namespace NWNXLib {

namespace API {

struct back
{
    curl_read_callback fread_func;
    void* fread_in;
    const char* postdata;
    int64_t postsize;
};

}

}
