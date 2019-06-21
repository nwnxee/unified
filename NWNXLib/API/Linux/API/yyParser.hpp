#pragma once

#include <cstdint>

#include "yyStackEntry.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Parse;

struct yyParser
{
    yyStackEntry* yytos;
    Parse* pParse;
    yyStackEntry yystack[100];
    yyStackEntry* yystackEnd;
};

}

}
