#pragma once

#include <cstdint>

#include "unknown_Collate4type.hpp"

namespace NWNXLib {

namespace API {

struct COLLATE4
{
    Collate4type collateType;
    void* charToKeyTranslationArray;
    void* unicodeToKeyTranslationArray;
    void* charToKeyCompressionArray;
    void* unicodeToKeyCompressionArray;
    uint16_t keySizeCharPerCharAdd;
    uint16_t expandOrCompressChar;
    uint16_t noTailChar;
    uint8_t didAllocChar;
    uint8_t didAllocUnicode;
    uint16_t expandOrCompressUnicode;
    uint16_t noTailUnicode;
};

}

}
