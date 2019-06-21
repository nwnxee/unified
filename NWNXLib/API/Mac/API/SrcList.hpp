#pragma once

#include <cstdint>

#include "SrcList_item.hpp"

namespace NWNXLib {

namespace API {

struct SrcList
{
    int32_t nSrc;
    uint32_t nAlloc;
    SrcList_item a[1];
};

}

}
