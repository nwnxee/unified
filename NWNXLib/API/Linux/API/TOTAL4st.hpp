#pragma once

#include <cstdint>

#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct EXPR4CALCSt;
struct e4exprSt;

struct TOTAL4st
{
    l4linkSt link;
    EXPR4CALCSt* calcPtr;
    e4exprSt* resetExpression;
    char* lastResetValue;
    e4exprSt* addCondition;
    char* lastAddValue;
    int16_t logcon;
    int16_t donce;
    int16_t totalType;
    int16_t lookahead;
    double total;
    double low;
    double high;
    int32_t count;
};

}

}
