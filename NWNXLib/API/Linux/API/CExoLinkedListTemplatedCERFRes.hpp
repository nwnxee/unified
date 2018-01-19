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
    CExoLinkedListTemplatedCERFRes() = default;
    CExoLinkedListTemplatedCERFRes(const CExoLinkedListTemplatedCERFRes&) = default;
    CExoLinkedListTemplatedCERFRes& operator=(const CExoLinkedListTemplatedCERFRes&) = default;

    ~CExoLinkedListTemplatedCERFRes();
};

void CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResDtor(CExoLinkedListTemplatedCERFRes* thisPtr);

}

}
