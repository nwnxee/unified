#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Module;
struct sqlite3;
struct sqlite3_vtab;

struct VTable
{
    sqlite3* db;
    Module* pMod;
    sqlite3_vtab* pVtab;
    int32_t nRef;
    uint8_t bConstraint;
    int32_t iSavepoint;
    VTable* pNext;
};

}

}
