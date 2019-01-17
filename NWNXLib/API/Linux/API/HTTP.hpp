#pragma once

#include <cstdint>

#include "back.hpp"
#include "curl_mimepart_s.hpp"
#include "unknown_TLS_3CA125CC99F88F1CC1A30B7B256021F0.hpp"

namespace NWNXLib {

namespace API {

struct HTTP
{
    curl_mimepart_s* sendit;
    int64_t postsize;
    const char* postdata;
    const char* p_pragma;
    const char* p_accept;
    int64_t readbytecount;
    int64_t writebytecount;
    curl_mimepart_s form;
    back backup;
    TLS_3CA125CC99F88F1CC1A30B7B256021F0 sending;
    void* send_buffer;
};

}

}
