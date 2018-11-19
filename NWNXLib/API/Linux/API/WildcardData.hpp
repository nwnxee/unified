#pragma once

#include <cstdint>

#include "curl_llist.hpp"
#include "unknown_curl_wildcard_dtor.hpp"
#include "unknown_curl_wildcard_states.hpp"

namespace NWNXLib {

namespace API {

struct WildcardData
{
    curl_wildcard_states state;
    char* path;
    char* pattern;
    curl_llist filelist;
    void* protdata;
    curl_wildcard_dtor dtor;
    void* customptr;
};

}

}
