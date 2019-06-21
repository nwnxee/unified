#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct seq_t
{
    uint32_t litLength;
    uint32_t matchLength;
    uint32_t offset;
    const uint8_t* match;
};

}

}
