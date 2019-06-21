#pragma once

#include <cstdint>

#include "unknown_i16.hpp"
#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct AuxData;
struct Parse;
struct SubProgram;
struct VdbeCursor;
struct VdbeFrame;
struct VdbeOp;
struct sqlite3;
struct sqlite3_value;

struct Vdbe
{
    sqlite3* db;
    Vdbe* pPrev;
    Vdbe* pNext;
    Parse* pParse;
    i16 nVar;
    uint32_t magic;
    int32_t nMem;
    int32_t nCursor;
    uint32_t cacheCtr;
    int32_t pc;
    int32_t rc;
    int32_t nChange;
    int32_t iStatement;
    sqlite_int64 iCurrentTime;
    sqlite_int64 nFkConstraint;
    sqlite_int64 nStmtDefCons;
    sqlite_int64 nStmtDefImmCons;
    VdbeOp* aOp;
    sqlite3_value* aMem;
    sqlite3_value** apArg;
    sqlite3_value* aColName;
    sqlite3_value* pResultSet;
    char* zErrMsg;
    VdbeCursor** apCsr;
    sqlite3_value* aVar;
    int32_t* pVList;
    sqlite_int64 startTime;
    int32_t nOp;
    uint16_t nResColumn;
    uint8_t errorAction;
    uint8_t minWriteFileFormat;
    uint8_t prepFlags;
    uint32_t expired : 2;
    uint32_t explain : 2;
    uint32_t doingRerun : 1;
    uint32_t changeCntOn : 1;
    uint32_t runOnlyOnce : 1;
    uint32_t usesStmtJournal : 1;
    uint32_t readOnly : 1;
    uint32_t bIsReader : 1;
    uint32_t btreeMask;
    uint32_t lockMask;
    uint32_t aCounter[7];
    char* zSql;
    void* pFree;
    VdbeFrame* pFrame;
    VdbeFrame* pDelFrame;
    int32_t nFrame;
    uint32_t expmask;
    SubProgram* pProgram;
    AuxData* pAuxData;
};

}

}
