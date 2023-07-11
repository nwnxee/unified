#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedListInternal.hpp"
#include "CExoLinkedListNode.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLinkedList)
#endif

typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;


// NOTE: Manually implemented for now..
template<class T> class CExoLinkedList
{
public:
    CExoLinkedListInternal * m_pcExoLinkedListInternal;

    CExoLinkedList()
    {
        m_pcExoLinkedListInternal = new CExoLinkedListInternal();
    }
    ~CExoLinkedList()
    {
        delete m_pcExoLinkedListInternal;
    }
    CExoLinkedListPosition AddHead(T * Object)
    {
        return m_pcExoLinkedListInternal->AddHead(Object);
    }
    CExoLinkedListPosition AddTail(T * Object)
    {
        return m_pcExoLinkedListInternal->AddTail(Object);
    }
    CExoLinkedListPosition AddAfter(T * Object, CExoLinkedListPosition Position)
    {
        return m_pcExoLinkedListInternal->AddAfter(Object, Position);
    }
    CExoLinkedListPosition AddBefore(T * Object, CExoLinkedListPosition Position)
    {
        return m_pcExoLinkedListInternal->AddBefore(Object, Position);
    }
    uint32_t Count()
    {
        return m_pcExoLinkedListInternal->m_nCount;
    }
    T * GetAtPos(CExoLinkedListPosition Position)
    {
        return (T*)m_pcExoLinkedListInternal->GetAtPos(Position);
    }
    T * GetHead()
    {
        return (T*)(m_pcExoLinkedListInternal->pHead ? m_pcExoLinkedListInternal->pHead->pObject : nullptr);
    }
    CExoLinkedListPosition GetHeadPos()
    {
        return m_pcExoLinkedListInternal->pHead;
    }
    T * GetNext(CExoLinkedListPosition & Position)
    {
        return (T*)m_pcExoLinkedListInternal->GetNext(Position);
    }
    T * GetPrev(CExoLinkedListPosition & Position)
    {
        return (T*)m_pcExoLinkedListInternal->GetPrev(Position);
    }
    T * GetTail()
    {
        return (T*)(m_pcExoLinkedListInternal->pTail ? m_pcExoLinkedListInternal->pTail->pObject : nullptr);
    }
    CExoLinkedListPosition GetTailPos()
    {
        return m_pcExoLinkedListInternal->pTail;
    }
    BOOL IsEmpty()
    {
        return m_pcExoLinkedListInternal->pHead == nullptr;
    }
    T * RemoveHead()
    {
        return (T*)m_pcExoLinkedListInternal->RemoveHead();
    }
    T * RemoveTail()
    {
        return (T*)m_pcExoLinkedListInternal->RemoveTail();
    }
    T * Remove(CExoLinkedListPosition Position)
    {
        return (T*)m_pcExoLinkedListInternal->Remove(Position);
    }


#ifdef NWN_CLASS_EXTENSION_CExoLinkedList
    NWN_CLASS_EXTENSION_CExoLinkedList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLinkedList)
#endif

