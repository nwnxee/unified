#pragma once

#include <cstdint>

#include "unknown_comp_function.hpp"
#include "unknown_curl_hash_dtor.hpp"
#include "unknown_hash_function.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_llist;

struct curl_hash
{
    curl_llist* table;
    hash_function hash_func;
    comp_function comp_func;
    curl_hash_dtor dtor;
    int32_t slots;
    uint32_t size;
};

}

}
