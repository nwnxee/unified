#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerStackEntry)
#endif

class CScriptParseTreeNode;




class CScriptCompilerStackEntry
{
    int32_t nState;
    int32_t nRule;
    int32_t nTerm;
    CScriptParseTreeNode * pCurrentTree;
    CScriptParseTreeNode * pReturnTree;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerStackEntry
    NWN_CLASS_EXTENSION_CScriptCompilerStackEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerStackEntry)
#endif

