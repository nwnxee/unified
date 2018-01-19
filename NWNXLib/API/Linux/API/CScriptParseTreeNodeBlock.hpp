#pragma once

#include <cstdint>

#include "CScriptParseTreeNode.hpp"

namespace NWNXLib {

namespace API {

struct CScriptParseTreeNodeBlock
{
    CScriptParseTreeNode m_pNodes[4096];
    CScriptParseTreeNodeBlock* m_pNextBlock;
};

}

}
