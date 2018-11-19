#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct IdList_item;

struct IdList
{
    IdList_item* a;
    int32_t nId;
};

}

}
