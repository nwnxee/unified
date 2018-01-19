#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XTextProperty
{
    uint8_t* value;
    uint32_t encoding;
    int32_t format;
    uint32_t nitems;
};

}

}
