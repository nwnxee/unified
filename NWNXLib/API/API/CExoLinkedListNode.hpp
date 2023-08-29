#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLinkedListNode)
#endif



typedef CExoLinkedListNode * CExoLinkedListPosition;


class CExoLinkedListNode
{
public:
    CExoLinkedListPosition pPrev;
    CExoLinkedListPosition pNext;
    void * pObject;



#ifdef NWN_CLASS_EXTENSION_CExoLinkedListNode
    NWN_CLASS_EXTENSION_CExoLinkedListNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLinkedListNode)
#endif

