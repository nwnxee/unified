#pragma once

#include <cstdint>

#include "hashtable_list.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct json_t;

struct hashtable_pair
{
    hashtable_list list;
    hashtable_list ordered_list;
    uint32_t hash;
    json_t* value;
    char key[1];
};

}

}
