#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XCharStruct
{
    int16_t lbearing;
    int16_t rbearing;
    int16_t width;
    int16_t ascent;
    int16_t descent;
    uint16_t attributes;
};

}

}
