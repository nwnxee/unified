#pragma once

#include <cstdint>

#include "unknown__ht.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct HashElem;

struct Hash
{
    uint32_t htsize;
    uint32_t count;
    HashElem* first;
    _ht* ht;
};

}

}
