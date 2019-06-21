#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct KeyInfo;
struct sqlite3_value;

struct UnpackedRecord
{
    KeyInfo* pKeyInfo;
    sqlite3_value* aMem;
    uint16_t nField;
    char default_rc;
    uint8_t errCode;
    char r1;
    char r2;
    uint8_t eqSeen;
};

}

}
