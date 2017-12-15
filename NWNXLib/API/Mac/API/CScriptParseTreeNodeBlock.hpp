#pragma once

#include <cstdint>

#include "CScriptParseTreeNode.hpp"

namespace NWNXLib {

namespace API {

struct CScriptParseTreeNodeBlock
{
    CScriptParseTreeNode m_pNodes[4096];
    CScriptParseTreeNodeBlock* m_pNextBlock;

    // The below are auto generated stubs.
    CScriptParseTreeNodeBlock(const CScriptParseTreeNodeBlock&);
    CScriptParseTreeNodeBlock& operator=(const CScriptParseTreeNodeBlock&);

    CScriptParseTreeNodeBlock();
};

void CScriptParseTreeNodeBlock__CScriptParseTreeNodeBlockCtor(CScriptParseTreeNodeBlock* thisPtr);

}

}
