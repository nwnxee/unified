#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct KeyFileHeader_st
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nResFiles;
    uint32_t nKeys;
    uint32_t nOffsetToFileTable;
    uint32_t nOffsetToKeyTable;
};

}

}
