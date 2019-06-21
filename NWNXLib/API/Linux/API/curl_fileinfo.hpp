#pragma once

#include <cstdint>

#include "unknown_TLS_76CA767D8485B09FD3AE2D60CB7F3C5B.hpp"
#include "unknown___time_t.hpp"
#include "unknown_curlfiletype.hpp"

namespace NWNXLib {

namespace API {

struct curl_fileinfo
{
    char* filename;
    curlfiletype filetype;
    __time_t time;
    uint32_t perm;
    int32_t uid;
    int32_t gid;
    int64_t size;
    int32_t hardlinks;
    TLS_76CA767D8485B09FD3AE2D60CB7F3C5B strings;
    uint32_t flags;
    char* b_data;
    uint32_t b_size;
    uint32_t b_used;
};

}

}
