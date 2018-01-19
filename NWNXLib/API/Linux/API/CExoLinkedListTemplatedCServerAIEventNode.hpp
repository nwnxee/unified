#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCServerAIEventNode
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCServerAIEventNode() = default;
    CExoLinkedListTemplatedCServerAIEventNode(const CExoLinkedListTemplatedCServerAIEventNode&) = default;
    CExoLinkedListTemplatedCServerAIEventNode& operator=(const CExoLinkedListTemplatedCServerAIEventNode&) = default;

    ~CExoLinkedListTemplatedCServerAIEventNode();
};

void CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeDtor(CExoLinkedListTemplatedCServerAIEventNode* thisPtr);

}

}
