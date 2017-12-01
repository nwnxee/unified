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
    CExoLinkedListTemplatedCERFKey();
    CExoLinkedListTemplatedCERFKey(const CExoLinkedListTemplatedCERFKey&);
    CExoLinkedListTemplatedCERFKey& operator=(const CExoLinkedListTemplatedCERFKey&);

    ~CExoLinkedListTemplatedCERFKey();
};

void CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyDtor(CExoLinkedListTemplatedCERFKey* thisPtr);

}

}
