#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_hash;
struct curl_llist_element;

struct curl_hash_iterator
{
    curl_hash* hash;
    int32_t slot_index;
    curl_llist_element* current_element;
};

}

}
