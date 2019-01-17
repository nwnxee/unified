#pragma once

#include <cstdint>

#include "Hash.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Table;

struct Schema
{
    int32_t schema_cookie;
    int32_t iGeneration;
    Hash tblHash;
    Hash idxHash;
    Hash trigHash;
    Hash fkeyHash;
    Table* pSeqTab;
    uint8_t file_format;
    uint8_t enc;
    uint16_t schemaFlags;
    int32_t cache_size;
};

}

}
