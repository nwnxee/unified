#pragma once
#include "nwn_api.hpp"

#include "CScriptParseTreeNode.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptParseTreeNodeBlock)
#endif





class CScriptParseTreeNodeBlock
{
    CScriptParseTreeNode m_pNodes[4096];
    CScriptParseTreeNodeBlock * m_pNextBlock;



#ifdef NWN_CLASS_EXTENSION_CScriptParseTreeNodeBlock
    NWN_CLASS_EXTENSION_CScriptParseTreeNodeBlock
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptParseTreeNodeBlock)
#endif

