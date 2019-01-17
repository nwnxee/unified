#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct curl_certinfo
{
    int32_t num_of_certs;
    curl_slist** certinfo;
};

}

}
