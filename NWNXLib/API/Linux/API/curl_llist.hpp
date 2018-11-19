#pragma once

#include <cstdint>

#include "unknown_curl_llist_dtor.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_llist_element;

struct curl_llist
{
    curl_llist_element* head;
    curl_llist_element* tail;
    curl_llist_dtor dtor;
    uint32_t size;
};

}

}
