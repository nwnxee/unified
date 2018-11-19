#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct DynamicStatic
{
    char* url;
    bool url_alloc;
    char* referer;
    bool referer_alloc;
    curl_slist* cookielist;
    curl_slist* resolve;
};

}

}
