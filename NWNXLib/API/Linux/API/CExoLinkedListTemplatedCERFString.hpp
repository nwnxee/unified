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
    CExoLinkedListTemplatedCERFString();
    CExoLinkedListTemplatedCERFString(const CExoLinkedListTemplatedCERFString&);
    CExoLinkedListTemplatedCERFString& operator=(const CExoLinkedListTemplatedCERFString&);

    ~CExoLinkedListTemplatedCERFString();
};

void CExoLinkedListTemplatedCERFString__CExoLinkedListTemplatedCERFStringDtor(CExoLinkedListTemplatedCERFString* thisPtr);

}

}
