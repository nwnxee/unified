#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedC2DA
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedC2DA() = default;
    CExoLinkedListTemplatedC2DA(const CExoLinkedListTemplatedC2DA&) = default;
    CExoLinkedListTemplatedC2DA& operator=(const CExoLinkedListTemplatedC2DA&) = default;

    ~CExoLinkedListTemplatedC2DA();
};

void CExoLinkedListTemplatedC2DA__CExoLinkedListTemplatedC2DADtor(CExoLinkedListTemplatedC2DA* thisPtr);

}

}
