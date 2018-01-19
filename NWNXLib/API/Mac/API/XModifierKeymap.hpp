#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XModifierKeymap
{
    int32_t max_keypermod;
    uint8_t* modifiermap;
};

}

}
