#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct curl_httppost
{
    curl_httppost* next;
    char* name;
    int32_t namelength;
    char* contents;
    int32_t contentslength;
    char* buffer;
    int32_t bufferlength;
    char* contenttype;
    curl_slist* contentheader;
    curl_httppost* more;
    int32_t flags;
    char* showfilename;
    void* userp;
    int64_t contentlen;
};

}

}
