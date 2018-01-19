#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCExoString
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCExoString() = default;
    CExoLinkedListTemplatedCExoString(const CExoLinkedListTemplatedCExoString&) = default;
    CExoLinkedListTemplatedCExoString& operator=(const CExoLinkedListTemplatedCExoString&) = default;

    ~CExoLinkedListTemplatedCExoString();
};

void CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringDtor(CExoLinkedListTemplatedCExoString* thisPtr);

}

}
