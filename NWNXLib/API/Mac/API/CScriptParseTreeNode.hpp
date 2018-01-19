#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CScriptParseTreeNode
{
    int32_t nOperation;
    CExoString* m_psStringData;
    int32_t nIntegerData;
    int32_t nIntegerData2;
    int32_t nIntegerData3;
    int32_t nIntegerData4;
    float fFloatData;
    float fVectorData[3];
    int32_t m_nFileReference;
    int32_t nLine;
    int32_t nChar;
    CScriptParseTreeNode* pLeft;
    CScriptParseTreeNode* pRight;
    int32_t nType;
    CExoString* m_psTypeName;
    int32_t m_nStackPointer;

    // The below are auto generated stubs.
    CScriptParseTreeNode() = default;
    CScriptParseTreeNode(const CScriptParseTreeNode&) = default;
    CScriptParseTreeNode& operator=(const CScriptParseTreeNode&) = default;

    ~CScriptParseTreeNode();
    void Clean();
};

void CScriptParseTreeNode__CScriptParseTreeNodeDtor(CScriptParseTreeNode* thisPtr);
void CScriptParseTreeNode__Clean(CScriptParseTreeNode* thisPtr);

}

}
