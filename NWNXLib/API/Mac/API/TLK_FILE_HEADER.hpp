#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct TLK_FILE_HEADER
{
    uint32_t fileType;
    uint32_t versionNum;
    uint32_t LanguageType;
    uint32_t nStrEntries;
    uint32_t strEntriesOffset;
};

}

}
