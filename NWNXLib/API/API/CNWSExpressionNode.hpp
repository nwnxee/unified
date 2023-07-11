#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSExpressionNode)
#endif





class CNWSExpressionNode
{
    int32_t nTimesVisited;
    int32_t m_nType;
    int32_t m_nPosition;
    CNWSExpressionNode * m_pNext;
    CExoString m_sMatch;
    CNWSExpressionNode * m_pAlternate;

    CNWSExpressionNode();
    ~CNWSExpressionNode();


#ifdef NWN_CLASS_EXTENSION_CNWSExpressionNode
    NWN_CLASS_EXTENSION_CNWSExpressionNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSExpressionNode)
#endif

