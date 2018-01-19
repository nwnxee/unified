#pragma once

#include <cstdint>

#include "STRUCT_B4NODE.hpp"

namespace NWNXLib {

namespace API {

struct T4HEADER
{
    STRUCT_B4NODE root;
    STRUCT_B4NODE freeList;
    uint32_t version;
    int16_t keyLen;
    uint8_t typeCode;
    uint8_t signature;
    uint32_t codeBaseNote;
    uint32_t blockSize;
    uint32_t multiplier;
    char sortSeq[8];
    char dummy3[4];
    int16_t descending;
    int16_t filterPos;
    int16_t filterLen;
    int16_t exprPos;
    int16_t exprLen;
};

}

}
