#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedNWPlayerListItem_st
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedNWPlayerListItem_st() = default;
    CExoLinkedListTemplatedNWPlayerListItem_st(const CExoLinkedListTemplatedNWPlayerListItem_st&) = default;
    CExoLinkedListTemplatedNWPlayerListItem_st& operator=(const CExoLinkedListTemplatedNWPlayerListItem_st&) = default;

    ~CExoLinkedListTemplatedNWPlayerListItem_st();
};

void CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stDtor(CExoLinkedListTemplatedNWPlayerListItem_st* thisPtr);

}

}
