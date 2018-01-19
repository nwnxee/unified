#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListNode;

struct CExoLinkedListInternal
{
    CExoLinkedListNode* pHead;
    CExoLinkedListNode* pTail;
    uint32_t m_nCount;

    // The below are auto generated stubs.
    CExoLinkedListInternal() = default;
    CExoLinkedListInternal(const CExoLinkedListInternal&) = default;
    CExoLinkedListInternal& operator=(const CExoLinkedListInternal&) = default;

    ~CExoLinkedListInternal();
    CExoLinkedListNode* AddAfter(void*, CExoLinkedListNode*);
    CExoLinkedListNode* AddBefore(void*, CExoLinkedListNode*);
    CExoLinkedListNode* AddHead(void*);
    CExoLinkedListNode* AddTail(void*);
    void* GetAtPos(CExoLinkedListNode*);
    void* GetNext(CExoLinkedListNode*);
    void* GetPrev(CExoLinkedListNode*);
    void* Remove(CExoLinkedListNode*);
    void* RemoveHead();
    void* RemoveTail();
};

void CExoLinkedListInternal__CExoLinkedListInternalDtor(CExoLinkedListInternal* thisPtr);
CExoLinkedListNode* CExoLinkedListInternal__AddAfter(CExoLinkedListInternal* thisPtr, void*, CExoLinkedListNode*);
CExoLinkedListNode* CExoLinkedListInternal__AddBefore(CExoLinkedListInternal* thisPtr, void*, CExoLinkedListNode*);
CExoLinkedListNode* CExoLinkedListInternal__AddHead(CExoLinkedListInternal* thisPtr, void*);
CExoLinkedListNode* CExoLinkedListInternal__AddTail(CExoLinkedListInternal* thisPtr, void*);
void* CExoLinkedListInternal__GetAtPos(CExoLinkedListInternal* thisPtr, CExoLinkedListNode*);
void* CExoLinkedListInternal__GetNext(CExoLinkedListInternal* thisPtr, CExoLinkedListNode*);
void* CExoLinkedListInternal__GetPrev(CExoLinkedListInternal* thisPtr, CExoLinkedListNode*);
void* CExoLinkedListInternal__Remove(CExoLinkedListInternal* thisPtr, CExoLinkedListNode*);
void* CExoLinkedListInternal__RemoveHead(CExoLinkedListInternal* thisPtr);
void* CExoLinkedListInternal__RemoveTail(CExoLinkedListInternal* thisPtr);

}

}
