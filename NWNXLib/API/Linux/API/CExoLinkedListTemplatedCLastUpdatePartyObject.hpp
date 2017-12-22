#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCLastUpdatePartyObject
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCLastUpdatePartyObject() = default;
    CExoLinkedListTemplatedCLastUpdatePartyObject(const CExoLinkedListTemplatedCLastUpdatePartyObject&) = default;
    CExoLinkedListTemplatedCLastUpdatePartyObject& operator=(const CExoLinkedListTemplatedCLastUpdatePartyObject&) = default;

    ~CExoLinkedListTemplatedCLastUpdatePartyObject();
};

void CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectDtor(CExoLinkedListTemplatedCLastUpdatePartyObject* thisPtr);

}

}
