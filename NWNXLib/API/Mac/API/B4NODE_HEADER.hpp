#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct B4NODE_HEADER
{
    int16_t freeSpace;
    uint8_t recNumMask[4];
    uint8_t dupByteCnt;
    uint8_t trailByteCnt;
    uint8_t recNumLen;
    uint8_t dupCntLen;
    uint8_t trailCntLen;
    uint8_t infoLen;
};

}

}
