#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedExoLocString_st
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedExoLocString_st() = default;
    CExoLinkedListTemplatedExoLocString_st(const CExoLinkedListTemplatedExoLocString_st&) = default;
    CExoLinkedListTemplatedExoLocString_st& operator=(const CExoLinkedListTemplatedExoLocString_st&) = default;

    ~CExoLinkedListTemplatedExoLocString_st();
};

void CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stDtor(CExoLinkedListTemplatedExoLocString_st* thisPtr);

}

}
