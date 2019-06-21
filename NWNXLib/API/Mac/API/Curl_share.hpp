#pragma once

#include <cstdint>

#include "conncache.hpp"
#include "curl_hash.hpp"
#include "unknown_curl_lock_function.hpp"
#include "unknown_curl_unlock_function.hpp"
#include "unknown_volatileunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CookieInfo;
struct curl_ssl_session;

struct Curl_share
{
    uint32_t specifier;
    volatileunsignedint dirty;
    curl_lock_function lockfunc;
    curl_unlock_function unlockfunc;
    void* clientdata;
    conncache conn_cache;
    curl_hash hostcache;
    CookieInfo* cookies;
    curl_ssl_session* sslsession;
    uint32_t max_ssl_sessions;
    int32_t sessionage;
};

}

}
