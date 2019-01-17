#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCERFKey
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCERFKey() = default;
    CExoLinkedListTemplatedCERFKey(const CExoLinkedListTemplatedCERFKey&) = default;
    CExoLinkedListTemplatedCERFKey& operator=(const CExoLinkedListTemplatedCERFKey&) = default;

    ~CExoLinkedListTemplatedCERFKey();
};

void CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyDtor(CExoLinkedListTemplatedCERFKey* thisPtr);

}

}
