#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_dns_entry;

struct Curl_async
{
    char* hostname;
    int32_t port;
    Curl_dns_entry* dns;
    bool done;
    int32_t status;
    void* os_specific;
};

}

}
