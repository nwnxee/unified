#pragma once

#include <cstdint>

#include "hashtable_list.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct hashtable_bucket;

struct hashtable
{
    uint32_t size;
    hashtable_bucket* buckets;
    uint32_t order;
    hashtable_list list;
    hashtable_list ordered_list;
};

}

}
