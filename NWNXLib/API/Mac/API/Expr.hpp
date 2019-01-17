#pragma once

#include <cstdint>

#include "unknown_TLS_A25F04F3BC9ED4A88235AE0C89B9FE4A.hpp"
#include "unknown_TLS_CFE8F5777337CCE173A2EAA33C040F90.hpp"
#include "unknown_i16.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct AggInfo;
struct Table;
struct Window_0;

struct Expr
{
    uint8_t op;
    char affinity;
    uint32_t flags;
    TLS_CFE8F5777337CCE173A2EAA33C040F90 u;
    Expr* pLeft;
    Expr* pRight;
    TLS_A25F04F3BC9ED4A88235AE0C89B9FE4A x;
    int32_t nHeight;
    int32_t iTable;
    i16 iColumn;
    int16_t iAgg;
    int16_t iRightJoinTable;
    uint8_t op2;
    AggInfo* pAggInfo;
    Table* pTab;
    Window_0* pWin;
};

}

}
