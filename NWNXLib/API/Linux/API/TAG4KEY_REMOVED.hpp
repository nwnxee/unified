#pragma once

#include <cstdint>

#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

struct TAG4KEY_REMOVED
{
    l4linkSt link;
    uint32_t recno;
    uint8_t key[1];
};

}

}
