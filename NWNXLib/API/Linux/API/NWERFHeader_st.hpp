#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct NWERFHeader_st
{
    char sVersion[8];
    uint32_t nStringCount;
    uint32_t nTotalStringSize;
    uint32_t nEntryCount;
    uint32_t nOffsetToStringList;
    uint32_t nOffsetToKeyList;
    uint32_t nOffsetToResourceList;
    uint32_t nBuildYear;
    uint32_t nBuildDay;
    uint32_t nDescriptionStrRef;
    uint8_t nUnused[116];
};

}

}
