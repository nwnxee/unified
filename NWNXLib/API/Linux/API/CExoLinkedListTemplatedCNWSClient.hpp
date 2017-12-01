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
    CExoLinkedListTemplatedCNWSClient();
    CExoLinkedListTemplatedCNWSClient(const CExoLinkedListTemplatedCNWSClient&);
    CExoLinkedListTemplatedCNWSClient& operator=(const CExoLinkedListTemplatedCNWSClient&);

    ~CExoLinkedListTemplatedCNWSClient();
};

void CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientDtor(CExoLinkedListTemplatedCNWSClient* thisPtr);

}

}
