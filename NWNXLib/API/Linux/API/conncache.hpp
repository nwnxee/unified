#pragma once

#include <cstdint>

#include "curl_hash.hpp"
#include "curltime.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;

struct conncache
{
    curl_hash hash;
    uint32_t num_conn;
    int32_t next_connection_id;
    curltime last_cleanup;
    Curl_easy* closure_handle;
};

}

}
