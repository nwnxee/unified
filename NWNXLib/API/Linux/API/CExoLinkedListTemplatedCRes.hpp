#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCRes
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCRes();
    CExoLinkedListTemplatedCRes(const CExoLinkedListTemplatedCRes&);
    CExoLinkedListTemplatedCRes& operator=(const CExoLinkedListTemplatedCRes&);

    ~CExoLinkedListTemplatedCRes();
};

void CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResDtor(CExoLinkedListTemplatedCRes* thisPtr);

}

}
