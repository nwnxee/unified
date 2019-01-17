#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct curl_slist
{
    char* data;
    curl_slist* next;
};

}

}
