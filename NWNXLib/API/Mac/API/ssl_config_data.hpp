#pragma once

#include <cstdint>

#include "ssl_primary_config.hpp"
#include "unknown_curl_ssl_ctx_callback.hpp"

namespace NWNXLib {

namespace API {

struct ssl_config_data
{
    ssl_primary_config primary;
    bool enable_beast;
    bool no_revoke;
    int32_t certverifyresult;
    char* CRLfile;
    char* issuercert;
    curl_ssl_ctx_callback fsslctx;
    void* fsslctxp;
    bool certinfo;
    bool falsestart;
    char* cert;
    char* cert_type;
    char* key;
    char* key_type;
    char* key_passwd;
};

}

}
