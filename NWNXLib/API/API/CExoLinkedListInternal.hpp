#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLinkedListInternal)
#endif



typedef CExoLinkedListNode * CExoLinkedListPosition;


class CExoLinkedListInternal
{
    CExoLinkedListPosition pHead;
    CExoLinkedListPosition pTail;
    uint32_t m_nCount;

    ~CExoLinkedListInternal();
    CExoLinkedListPosition AddHead(void * Object);
    CExoLinkedListPosition AddTail(void * Object);
    CExoLinkedListPosition AddAfter(void * Object, CExoLinkedListPosition Position);
    CExoLinkedListPosition AddBefore(void * Object, CExoLinkedListPosition Position);
    void * GetAtPos(CExoLinkedListPosition Position);
    void * GetNext(CExoLinkedListPosition & Position);
    void * GetPrev(CExoLinkedListPosition & Position);
    void * RemoveHead();
    void * RemoveTail();
    void * Remove(CExoLinkedListPosition Position);


#ifdef NWN_CLASS_EXTENSION_CExoLinkedListInternal
    NWN_CLASS_EXTENSION_CExoLinkedListInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLinkedListInternal)
#endif

