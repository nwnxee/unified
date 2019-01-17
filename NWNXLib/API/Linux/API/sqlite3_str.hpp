#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct sqlite3;

struct sqlite3_str
{
    sqlite3* db;
    char* zText;
    uint32_t nAlloc;
    uint32_t mxAlloc;
    uint32_t nChar;
    uint8_t accError;
    uint8_t printfFlags;
};

}

}
