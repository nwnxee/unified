#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FileChunk
{
    FileChunk* pNext;
    uint8_t zChunk[8];
};

}

}
