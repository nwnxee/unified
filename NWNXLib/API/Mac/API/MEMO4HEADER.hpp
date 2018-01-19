#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct MEMO4HEADER
{
    uint32_t nextBlock;
    char usused[2];
    int16_t blockSize;
};

}

}
