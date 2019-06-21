#pragma once

#include <cstdint>

#include "unknown_curl_sslbackend.hpp"

namespace NWNXLib {

namespace API {

struct curl_ssl_backend
{
    curl_sslbackend id;
    const char* name;
};

}

}
