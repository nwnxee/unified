#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoLinkedListNode
{
    CExoLinkedListNode* pPrev;
    CExoLinkedListNode* pNext;
    void* pObject;
};

}

}
