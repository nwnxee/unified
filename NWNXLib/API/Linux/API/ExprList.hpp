#pragma once

#include <cstdint>

#include "ExprList_item.hpp"

namespace NWNXLib {

namespace API {

struct ExprList
{
    int32_t nExpr;
    ExprList_item a[1];
};

}

}
