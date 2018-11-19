#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3PrngType
{
    uint8_t isInit;
    uint8_t i;
    uint8_t j;
    uint8_t s[256];
};

}

}
