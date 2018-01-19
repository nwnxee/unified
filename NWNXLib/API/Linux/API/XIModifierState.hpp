#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XIModifierState
{
    int32_t base;
    int32_t latched;
    int32_t locked;
    int32_t effective;
};

}

}
