#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSExpression)
#endif

class CExoString;
class CNWSExpressionList;
class CNWSExpressionNode;


typedef int BOOL;


class CNWSExpression
{
    int32_t m_nExpressionId;
    CExoArrayList<CExoString *> m_aStored;
    BOOL m_bCaseSensitive;
    CNWSExpressionList * m_pGraph;
    CExoString m_sParsedString;

    CNWSExpression();
    ~CNWSExpression();
    int32_t ParseString(CExoString sStringToParse);
    BOOL TestString(const CExoString & sStringToTest, BOOL bFindStrings = true);
    void ClearGraph();
    void ClearAlternate(CNWSExpressionNode * pNode);
    CNWSExpressionNode * NewNode(int32_t nType);


#ifdef NWN_CLASS_EXTENSION_CNWSExpression
    NWN_CLASS_EXTENSION_CNWSExpression
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSExpression)
#endif

