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
    CExoLinkedListTemplatedCExoString();
    CExoLinkedListTemplatedCExoString(const CExoLinkedListTemplatedCExoString&);
    CExoLinkedListTemplatedCExoString& operator=(const CExoLinkedListTemplatedCExoString&);

    ~CExoLinkedListTemplatedCExoString();
};

void CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringDtor(CExoLinkedListTemplatedCExoString* thisPtr);

}

}
