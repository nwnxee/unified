#pragma once

#include <cstdint>

#include "curltime.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct connectdata;

struct pingpong
{
    char* cache;
    uint32_t cache_size;
    uint32_t nread_resp;
    char* linestart_resp;
    bool pending_resp;
    char* sendthis;
    uint32_t sendleft;
    uint32_t sendsize;
    curltime response;
    int32_t response_time;
    connectdata* conn;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
};

}

}
