#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCNWSClient
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCNWSClient() = default;
    CExoLinkedListTemplatedCNWSClient(const CExoLinkedListTemplatedCNWSClient&) = default;
    CExoLinkedListTemplatedCNWSClient& operator=(const CExoLinkedListTemplatedCNWSClient&) = default;

    ~CExoLinkedListTemplatedCNWSClient();
};

void CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientDtor(CExoLinkedListTemplatedCNWSClient* thisPtr);

}

}
