#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FSE_DState_t
{
    uint32_t state;
    const void* table;
};

}

}
