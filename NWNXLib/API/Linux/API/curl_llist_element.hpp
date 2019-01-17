#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct curl_llist_element
{
    void* ptr;
    curl_llist_element* prev;
    curl_llist_element* next;
};

}

}
