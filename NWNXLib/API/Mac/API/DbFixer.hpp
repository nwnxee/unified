#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Parse;
struct Schema;
struct Token;

struct DbFixer
{
    Parse* pParse;
    Schema* pSchema;
    int32_t bVarOnly;
    const char* zDb;
    const char* zType;
    const Token* pName;
};

}

}
