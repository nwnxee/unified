#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct DATA4HEADER_FULL
{
    char version;
    char yy;
    char mm;
    char dd;
    int32_t numRecs;
    uint16_t headerLen;
    uint16_t recordLen;
    char zero[16];
    char hasMdxMemo;
    char codePage;
    char zero2[2];
};

}

}
