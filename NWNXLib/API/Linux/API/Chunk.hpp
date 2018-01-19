#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Chunk
{
    uint32_t magic;
    uint32_t length;
    uint8_t* data;
};

}

}
