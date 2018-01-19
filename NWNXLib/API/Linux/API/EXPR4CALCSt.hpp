#pragma once

#include <cstdint>

#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct TOTAL4st;
struct e4exprSt;

struct EXPR4CALCSt
{
    l4linkSt link;
    e4exprSt* expr;
    TOTAL4st* total;
    char name[20];
    int32_t curResultPos;
};

}

}
