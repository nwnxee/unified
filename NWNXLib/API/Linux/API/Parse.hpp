#pragma once

#include <cstdint>

#include "Token.hpp"
#include "unknown_i16.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct AutoincInfo;
struct ExprList;
struct Index;
struct RenameToken;
struct Table;
struct TableLock;
struct Trigger;
struct TriggerPrg;
struct Vdbe;
struct With;
struct sqlite3;

struct Parse
{
    sqlite3* db;
    char* zErrMsg;
    Vdbe* pVdbe;
    int32_t rc;
    uint8_t colNamesSet;
    uint8_t checkSchema;
    uint8_t nested;
    uint8_t nTempReg;
    uint8_t isMultiWrite;
    uint8_t mayAbort;
    uint8_t hasCompound;
    uint8_t okConstFactor;
    uint8_t disableLookaside;
    int32_t nRangeReg;
    int32_t iRangeReg;
    int32_t nErr;
    int32_t nTab;
    int32_t nMem;
    int32_t nOpAlloc;
    int32_t szOpAlloc;
    int32_t iSelfTab;
    int32_t nLabel;
    int32_t* aLabel;
    ExprList* pConstExpr;
    Token constraintName;
    uint32_t writeMask;
    uint32_t cookieMask;
    int32_t regRowid;
    int32_t regRoot;
    int32_t nMaxArg;
    int32_t nSelect;
    int32_t nTableLock;
    TableLock* aTableLock;
    AutoincInfo* pAinc;
    Parse* pToplevel;
    Table* pTriggerTab;
    int32_t addrCrTab;
    uint32_t nQueryLoop;
    uint32_t oldmask;
    uint32_t newmask;
    uint8_t eTriggerOp;
    uint8_t eOrconf;
    uint8_t disableTriggers;
    int32_t aTempReg[8];
    Token sNameToken;
    Token sLastToken;
    i16 nVar;
    uint8_t iPkSortOrder;
    uint8_t explain;
    uint8_t eParseMode;
    int32_t nVtabLock;
    int32_t nHeight;
    int32_t addrExplain;
    int32_t* pVList;
    Vdbe* pReprepare;
    const char* zTail;
    Table* pNewTable;
    Index* pNewIndex;
    Trigger* pNewTrigger;
    const char* zAuthContext;
    Token sArg;
    Table** apVtabLock;
    Table* pZombieTab;
    TriggerPrg* pTriggerPrg;
    With* pWith;
    With* pWithToFree;
    RenameToken* pRename;
};

}

}
