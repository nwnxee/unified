#pragma once

#include <cstdint>

#include "unknown_curl_sslbackend.hpp"

namespace NWNXLib {

namespace API {

struct curl_tlssessioninfo
{
    curl_sslbackend backend;
    void* internals;
};

}

}
