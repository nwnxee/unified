#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCLinuxFileSection
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCLinuxFileSection() = default;
    CExoLinkedListTemplatedCLinuxFileSection(const CExoLinkedListTemplatedCLinuxFileSection&) = default;
    CExoLinkedListTemplatedCLinuxFileSection& operator=(const CExoLinkedListTemplatedCLinuxFileSection&) = default;

    ~CExoLinkedListTemplatedCLinuxFileSection();
};

void CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionDtor(CExoLinkedListTemplatedCLinuxFileSection* thisPtr);

}

}
