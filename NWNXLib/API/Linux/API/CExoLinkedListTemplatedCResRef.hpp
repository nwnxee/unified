#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCResRef
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCResRef() = default;
    CExoLinkedListTemplatedCResRef(const CExoLinkedListTemplatedCResRef&) = default;
    CExoLinkedListTemplatedCResRef& operator=(const CExoLinkedListTemplatedCResRef&) = default;

    ~CExoLinkedListTemplatedCResRef();
};

void CExoLinkedListTemplatedCResRef__CExoLinkedListTemplatedCResRefDtor(CExoLinkedListTemplatedCResRef* thisPtr);

}

}
