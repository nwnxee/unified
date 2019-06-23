#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLinkedList)
#endif

struct CExoLinkedListInternal;


typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;


template<class T> struct CExoLinkedList
{
    CExoLinkedListInternal * m_pcExoLinkedListInternal;

    CExoLinkedList();
    ~CExoLinkedList();
    CExoLinkedListPosition AddHead(T * Object);
    CExoLinkedListPosition AddTail(T * Object);
    CExoLinkedListPosition AddAfter(T * Object, CExoLinkedListPosition Position);
    CExoLinkedListPosition AddBefore(T * Object, CExoLinkedListPosition Position);
    uint32_t Count();
    T * GetAtPos(CExoLinkedListPosition Position);
    T * GetHead();
    CExoLinkedListPosition GetHeadPos();
    T * GetNext(CExoLinkedListPosition & Position);
    T * GetPrev(CExoLinkedListPosition & Position);
    T * GetTail();
    CExoLinkedListPosition GetTailPos();
    BOOL IsEmpty();
    T * RemoveHead();
    T * RemoveTail();
    T * Remove(CExoLinkedListPosition Position);


#ifdef NWN_CLASS_EXTENSION_CExoLinkedList
    NWN_CLASS_EXTENSION_CExoLinkedList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLinkedList)
#endif

