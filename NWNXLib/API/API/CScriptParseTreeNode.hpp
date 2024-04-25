#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptParseTreeNode)
#endif

struct CExoString;




struct CScriptParseTreeNode
{
    int32_t nOperation;
    CExoString * m_psStringData;
    int32_t nIntegerData;
    int32_t nIntegerData2;
    int32_t nIntegerData3;
    int32_t nIntegerData4;
    float fFloatData;
    float fVectorData[3];
    int32_t m_nFileReference;
    int32_t nLine;
    int32_t nChar;
    CScriptParseTreeNode * pLeft;
    CScriptParseTreeNode * pRight;
    int32_t nType;
    CExoString * m_psTypeName;
    int32_t m_nStackPointer;
    bool m_bAllowAsDefaultValueInFunctionDecl;


#ifdef NWN_CLASS_EXTENSION_CScriptParseTreeNode
    NWN_CLASS_EXTENSION_CScriptParseTreeNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptParseTreeNode)
#endif

