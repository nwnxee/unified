#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct AuxData;
struct Vdbe;
struct VdbeCursor;
struct VdbeOp;
struct sqlite3_value;

struct VdbeFrame
{
    Vdbe* v;
    VdbeFrame* pParent;
    VdbeOp* aOp;
    sqlite_int64* anExec;
    sqlite3_value* aMem;
    VdbeCursor** apCsr;
    uint8_t* aOnce;
    void* token;
    sqlite_int64 lastRowid;
    AuxData* pAuxData;
    int32_t nCursor;
    int32_t pc;
    int32_t nOp;
    int32_t nMem;
    int32_t nChildMem;
    int32_t nChildCsr;
    int32_t nChange;
    int32_t nDbChange;
};

}

}
