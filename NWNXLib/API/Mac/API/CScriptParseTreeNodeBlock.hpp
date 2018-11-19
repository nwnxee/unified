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
    CScriptParseTreeNodeBlock(const CScriptParseTreeNodeBlock&) = default;
    CScriptParseTreeNodeBlock& operator=(const CScriptParseTreeNodeBlock&) = default;

    CScriptParseTreeNodeBlock();
    void CleanBlockEntries();
};

void CScriptParseTreeNodeBlock__CScriptParseTreeNodeBlockCtor(CScriptParseTreeNodeBlock* thisPtr);
void CScriptParseTreeNodeBlock__CleanBlockEntries(CScriptParseTreeNodeBlock* thisPtr);

}

}
