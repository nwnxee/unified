#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedNWAreaExpansion_st
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedNWAreaExpansion_st() = default;
    CExoLinkedListTemplatedNWAreaExpansion_st(const CExoLinkedListTemplatedNWAreaExpansion_st&) = default;
    CExoLinkedListTemplatedNWAreaExpansion_st& operator=(const CExoLinkedListTemplatedNWAreaExpansion_st&) = default;

    ~CExoLinkedListTemplatedNWAreaExpansion_st();
};

void CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stDtor(CExoLinkedListTemplatedNWAreaExpansion_st* thisPtr);

}

}
