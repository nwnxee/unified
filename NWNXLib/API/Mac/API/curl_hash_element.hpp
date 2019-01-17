#pragma once

#include <cstdint>

#include "curl_llist_element.hpp"

namespace NWNXLib {

namespace API {

struct curl_hash_element
{
    curl_llist_element list;
    void* ptr;
    uint32_t key_len;
    char key[1];
};

}

}
