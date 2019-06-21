#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CollSeq;
struct sqlite3;

struct KeyInfo
{
    uint32_t nRef;
    uint8_t enc;
    uint16_t nKeyField;
    uint16_t nAllField;
    sqlite3* db;
    uint8_t* aSortOrder;
    CollSeq* aColl[1];
};

}

}
