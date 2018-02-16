#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct hashtable_list
{
    hashtable_list* prev;
    hashtable_list* next;
};

}

}
