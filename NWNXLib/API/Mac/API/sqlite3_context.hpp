#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FuncDef;
struct Vdbe;
struct sqlite3_value;

struct sqlite3_context
{
    sqlite3_value* pOut;
    FuncDef* pFunc;
    sqlite3_value* pMem;
    Vdbe* pVdbe;
    int32_t iOp;
    int32_t isError;
    uint8_t skipFlag;
    uint8_t argc;
    sqlite3_value* argv[1];
};

}

}
