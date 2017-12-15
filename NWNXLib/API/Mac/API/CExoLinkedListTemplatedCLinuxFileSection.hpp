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
    CExoLinkedListTemplatedCLinuxFileSection();
    CExoLinkedListTemplatedCLinuxFileSection(const CExoLinkedListTemplatedCLinuxFileSection&);
    CExoLinkedListTemplatedCLinuxFileSection& operator=(const CExoLinkedListTemplatedCLinuxFileSection&);

    ~CExoLinkedListTemplatedCLinuxFileSection();
};

void CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionDtor(CExoLinkedListTemplatedCLinuxFileSection* thisPtr);

}

}
