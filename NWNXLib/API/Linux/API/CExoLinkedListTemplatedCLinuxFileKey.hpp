#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCLinuxFileKey
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCLinuxFileKey() = default;
    CExoLinkedListTemplatedCLinuxFileKey(const CExoLinkedListTemplatedCLinuxFileKey&) = default;
    CExoLinkedListTemplatedCLinuxFileKey& operator=(const CExoLinkedListTemplatedCLinuxFileKey&) = default;

    ~CExoLinkedListTemplatedCLinuxFileKey();
};

void CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyDtor(CExoLinkedListTemplatedCLinuxFileKey* thisPtr);

}

}
