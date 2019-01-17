#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Cookie;

struct CookieInfo
{
    Cookie* cookies[256];
    char* filename;
    bool running;
    int32_t numcookies;
    bool newsession;
};

}

}
