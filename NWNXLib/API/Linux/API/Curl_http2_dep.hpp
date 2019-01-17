#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;

struct Curl_http2_dep
{
    Curl_http2_dep* next;
    Curl_easy* data;
};

}

}
