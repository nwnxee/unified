#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct seqDef_s
{
    uint32_t offset;
    uint16_t litLength;
    uint16_t matchLength;
};

}

}
