#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Column;
struct ExprList;
struct FKey;
struct Index;
struct Schema;
struct Select;
struct Trigger;
struct VTable;

struct Table
{
    char* zName;
    Column* aCol;
    Index* pIndex;
    Select* pSelect;
    FKey* pFKey;
    char* zColAff;
    ExprList* pCheck;
    int32_t tnum;
    uint32_t nTabRef;
    uint32_t tabFlags;
    int16_t iPKey;
    int16_t nCol;
    int16_t nRowLogEst;
    int16_t szTabRow;
    uint8_t keyConf;
    int32_t addColOffset;
    int32_t nModuleArg;
    char** azModuleArg;
    VTable* pVTable;
    Trigger* pTrigger;
    Schema* pSchema;
    Table* pNextZombie;
};

}

}
