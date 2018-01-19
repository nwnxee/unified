#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct EncapsulatedResListEntry_st
{
    uint32_t nOffsetToResource;
    uint32_t nResourceSize;
};

}

}
