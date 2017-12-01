#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWSExpressionNode
{
    int32_t nTimesVisited;
    int32_t m_nType;
    int32_t m_nPosition;
    CNWSExpressionNode* m_pNext;
    CExoString m_sMatch;
    CNWSExpressionNode* m_pAlternate;

    // The below are auto generated stubs.
    CNWSExpressionNode(const CNWSExpressionNode&);
    CNWSExpressionNode& operator=(const CNWSExpressionNode&);

    CNWSExpressionNode();
    ~CNWSExpressionNode();
};

void CNWSExpressionNode__CNWSExpressionNodeCtor(CNWSExpressionNode* thisPtr);
void CNWSExpressionNode__CNWSExpressionNodeDtor(CNWSExpressionNode* thisPtr);

}

}
