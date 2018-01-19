#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct KeyFileResFileName_st
{
    uint32_t nFileSize;
    uint32_t nFileNameOffset;
    uint16_t nFileNameSize;
    uint16_t bDrives;
};

}

}
