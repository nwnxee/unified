#pragma once

#include <cstdint>

#include "S4SCAN.hpp"
#include "S4STACK.hpp"
#include "e4exprSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;

struct E4PARSE
{
    e4exprSt expr;
    S4STACK constants;
    S4SCAN scan;
    S4STACK op;
    CODE4St* codeBase;
};

}

}
