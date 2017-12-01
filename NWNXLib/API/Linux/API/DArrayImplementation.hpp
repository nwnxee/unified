#pragma once

#include <cstdint>

#include "unknown_ArrayElementFreeFn.hpp"

namespace NWNXLib {

namespace API {

struct DArrayImplementation
{
    int32_t count;
    int32_t capacity;
    int32_t elemsize;
    int32_t growby;
    ArrayElementFreeFn elemfreefn;
    void* list;
};

}

}
