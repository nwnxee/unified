#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct FormInfo
{
    char* name;
    bool name_alloc;
    uint32_t namelength;
    char* value;
    bool value_alloc;
    int64_t contentslength;
    char* contenttype;
    bool contenttype_alloc;
    int32_t flags;
    char* buffer;
    uint32_t bufferlength;
    char* showfilename;
    bool showfilename_alloc;
    char* userp;
    curl_slist* contentheader;
    FormInfo* more;
};

}

}
