#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ExoTGAHeader_st
{
    uint8_t nIDFieldSize;
    uint8_t nColorMapType;
    uint8_t nImageTypeCode;
    uint8_t nColorMapOrigin[2];
    uint8_t nColorMapLength[2];
    uint8_t nColorMapEntrySize;
    uint16_t nXLowerLeft;
    uint16_t nYLowerLeft;
    uint16_t nWidth;
    uint16_t nHeight;
    uint8_t nImagePixelSize;
    uint8_t nImageDescriptor;
};

}

}
