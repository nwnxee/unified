#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Btree;
struct Schema;

struct Db
{
    char* zDbSName;
    Btree* pBt;
    uint8_t safety_level;
    uint8_t bSyncSet;
    Schema* pSchema;
};

}

}
