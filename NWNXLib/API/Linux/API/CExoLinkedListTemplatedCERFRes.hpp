#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCERFRes
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCERFRes();
    CExoLinkedListTemplatedCERFRes(const CExoLinkedListTemplatedCERFRes&);
    CExoLinkedListTemplatedCERFRes& operator=(const CExoLinkedListTemplatedCERFRes&);

    ~CExoLinkedListTemplatedCERFRes();
};

void CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResDtor(CExoLinkedListTemplatedCERFRes* thisPtr);

}

}
