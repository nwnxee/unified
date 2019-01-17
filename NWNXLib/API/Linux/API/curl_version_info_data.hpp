#pragma once

#include <cstdint>

#include "unknown_CURLversion.hpp"

namespace NWNXLib {

namespace API {

struct curl_version_info_data
{
    CURLversion age;
    const char* version;
    uint32_t version_num;
    const char* host;
    int32_t features;
    const char* ssl_version;
    int32_t ssl_version_num;
    const char* libz_version;
    const char** const protocols;
    const char* ares;
    int32_t ares_num;
    const char* libidn;
    int32_t iconv_ver_num;
    const char* libssh_version;
    uint32_t brotli_ver_num;
    const char* brotli_version;
};

}

}
