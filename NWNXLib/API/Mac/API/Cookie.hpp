#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Cookie
{
    Cookie* next;
    char* name;
    char* value;
    char* path;
    char* spath;
    char* domain;
    int64_t expires;
    char* expirestr;
    bool tailmatch;
    char* version;
    char* maxage;
    bool secure;
    bool livecookie;
    bool httponly;
};

}

}
