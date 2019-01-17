#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;

struct Curl_sh_entry
{
    Curl_easy* easy;
    int32_t action;
    int32_t socket;
    void* socketp;
};

}

}
