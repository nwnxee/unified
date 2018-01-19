#pragma once

#include <cstdint>

#include "STRUCT_B4NODE.hpp"

namespace NWNXLib {

namespace API {

struct B4STD_HEADER
{
    int16_t nodeAttribute;
    int16_t nKeys;
    STRUCT_B4NODE leftNode;
    STRUCT_B4NODE rightNode;
};

}

}
