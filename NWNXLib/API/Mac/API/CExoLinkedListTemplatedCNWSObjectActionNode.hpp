#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCNWSObjectActionNode
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCNWSObjectActionNode() = default;
    CExoLinkedListTemplatedCNWSObjectActionNode(const CExoLinkedListTemplatedCNWSObjectActionNode&) = default;
    CExoLinkedListTemplatedCNWSObjectActionNode& operator=(const CExoLinkedListTemplatedCNWSObjectActionNode&) = default;

    ~CExoLinkedListTemplatedCNWSObjectActionNode();
};

void CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeDtor(CExoLinkedListTemplatedCNWSObjectActionNode* thisPtr);

}

}
