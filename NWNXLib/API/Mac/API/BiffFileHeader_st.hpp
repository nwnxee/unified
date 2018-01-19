#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct BiffFileHeader_st
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nNumVariableResources;
    uint32_t nNumFixedResources;
    uint32_t nTableOffset;
};

}

}
