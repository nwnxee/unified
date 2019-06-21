#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BtCursor;
struct Table;
struct sqlite3;
struct sqlite3_stmt;

struct Incrblob
{
    int32_t nByte;
    int32_t iOffset;
    uint16_t iCol;
    BtCursor* pCsr;
    sqlite3_stmt* pStmt;
    sqlite3* db;
    char* zDb;
    Table* pTab;
};

}

}
