#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CScriptParseTreeNode;

struct CScriptCompilerStackEntry
{
    int32_t nState;
    int32_t nRule;
    int32_t nTerm;
    CScriptParseTreeNode* pCurrentTree;
    CScriptParseTreeNode* pReturnTree;
};

}

}
