#pragma once

#include <cstdint>

#include "unknown_curl_khtype.hpp"

namespace NWNXLib {

namespace API {

struct curl_khkey
{
    const char* key;
    uint32_t len;
    curl_khtype keytype;
};

}

}
