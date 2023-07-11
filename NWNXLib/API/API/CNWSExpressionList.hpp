#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSExpressionList)
#endif

class CNWSExpressionNode;




class CNWSExpressionList
{
public:
    CNWSExpressionNode *m_pHead, *m_pAfter, *m_pTail;

    CNWSExpressionList();
    ~CNWSExpressionList();
    void DeleteList();
    void AddNode(CNWSExpressionNode * pNode);
    void AddNodeToHead(CNWSExpressionNode * pNode);
    void DeleteAlternate(CNWSExpressionNode * pNode);


#ifdef NWN_CLASS_EXTENSION_CNWSExpressionList
    NWN_CLASS_EXTENSION_CNWSExpressionList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSExpressionList)
#endif

