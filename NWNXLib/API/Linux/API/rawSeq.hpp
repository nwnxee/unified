#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct rawSeq
{
    uint32_t offset;
    uint32_t litLength;
    uint32_t matchLength;
};

}

}
