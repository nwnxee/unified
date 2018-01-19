#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FIELD4IMAGE
{
    char name[11];
    char type;
    int32_t offset;
    uint8_t len;
    uint8_t dec;
    char nullBinary;
    char filler2[12];
    char hasTag;
};

}

}
