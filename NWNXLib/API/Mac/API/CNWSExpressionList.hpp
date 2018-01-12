#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSExpressionNode;

struct CNWSExpressionList
{
    CNWSExpressionNode* m_pHead;
    CNWSExpressionNode* m_pAfter;
    CNWSExpressionNode* m_pTail;

    // The below are auto generated stubs.
    CNWSExpressionList(const CNWSExpressionList&) = default;
    CNWSExpressionList& operator=(const CNWSExpressionList&) = default;

    CNWSExpressionList();
    ~CNWSExpressionList();
    void AddNode(CNWSExpressionNode*);
    void AddNodeToHead(CNWSExpressionNode*);
    void DeleteAlternate(CNWSExpressionNode*);
    void DeleteList();
};

void CNWSExpressionList__CNWSExpressionListCtor__0(CNWSExpressionList* thisPtr);
void CNWSExpressionList__CNWSExpressionListDtor__0(CNWSExpressionList* thisPtr);
void CNWSExpressionList__AddNode(CNWSExpressionList* thisPtr, CNWSExpressionNode*);
void CNWSExpressionList__AddNodeToHead(CNWSExpressionList* thisPtr, CNWSExpressionNode*);
void CNWSExpressionList__DeleteAlternate(CNWSExpressionList* thisPtr, CNWSExpressionNode*);
void CNWSExpressionList__DeleteList(CNWSExpressionList* thisPtr);

}

}
