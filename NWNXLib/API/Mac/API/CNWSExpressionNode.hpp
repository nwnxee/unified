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
    CNWSExpressionNode(const CNWSExpressionNode&) = default;
    CNWSExpressionNode& operator=(const CNWSExpressionNode&) = default;

    CNWSExpressionNode();
    ~CNWSExpressionNode();
};

void CNWSExpressionNode__CNWSExpressionNodeCtor__0(CNWSExpressionNode* thisPtr);
void CNWSExpressionNode__CNWSExpressionNodeDtor__0(CNWSExpressionNode* thisPtr);

}

}
