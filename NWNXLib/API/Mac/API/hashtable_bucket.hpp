#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct hashtable_list;

struct hashtable_bucket
{
    hashtable_list* first;
    hashtable_list* last;
};

}

}
