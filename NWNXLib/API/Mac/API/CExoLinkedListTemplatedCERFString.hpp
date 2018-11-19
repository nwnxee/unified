#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCERFString
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCERFString() = default;
    CExoLinkedListTemplatedCERFString(const CExoLinkedListTemplatedCERFString&) = default;
    CExoLinkedListTemplatedCERFString& operator=(const CExoLinkedListTemplatedCERFString&) = default;

    ~CExoLinkedListTemplatedCERFString();
};

void CExoLinkedListTemplatedCERFString__CExoLinkedListTemplatedCERFStringDtor(CExoLinkedListTemplatedCERFString* thisPtr);

}

}
