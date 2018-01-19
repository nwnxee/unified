#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCExoStringPtr.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSExpressionList;
struct CNWSExpressionNode;

struct CNWSExpression
{
    int32_t m_nExpressionId;
    CExoArrayListTemplatedCExoStringPtr m_aStored;
    int32_t m_bCaseSensitive;
    CNWSExpressionList* m_pGraph;
    CExoString m_sParsedString;

    // The below are auto generated stubs.
    CNWSExpression(const CNWSExpression&) = default;
    CNWSExpression& operator=(const CNWSExpression&) = default;

    CNWSExpression();
    ~CNWSExpression();
    void ClearAlternate(CNWSExpressionNode*);
    void ClearGraph();
    CNWSExpressionNode* NewNode(int32_t);
    int32_t ParseString(CExoString);
    int32_t TestString(const CExoString&, int32_t);
};

void CNWSExpression__CNWSExpressionCtor(CNWSExpression* thisPtr);
void CNWSExpression__CNWSExpressionDtor(CNWSExpression* thisPtr);
void CNWSExpression__ClearAlternate(CNWSExpression* thisPtr, CNWSExpressionNode*);
void CNWSExpression__ClearGraph(CNWSExpression* thisPtr);
CNWSExpressionNode* CNWSExpression__NewNode(CNWSExpression* thisPtr, int32_t);
int32_t CNWSExpression__ParseString(CNWSExpression* thisPtr, CExoString);
int32_t CNWSExpression__TestString(CNWSExpression* thisPtr, const CExoString&, int32_t);

}

}
