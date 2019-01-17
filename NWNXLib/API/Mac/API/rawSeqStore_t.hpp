#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct rawSeq;

struct rawSeqStore_t
{
    rawSeq* seq;
    uint32_t pos;
    uint32_t size;
    uint32_t capacity;
};

}

}
