#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedNWModuleExpansion_st
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedNWModuleExpansion_st() = default;
    CExoLinkedListTemplatedNWModuleExpansion_st(const CExoLinkedListTemplatedNWModuleExpansion_st&) = default;
    CExoLinkedListTemplatedNWModuleExpansion_st& operator=(const CExoLinkedListTemplatedNWModuleExpansion_st&) = default;

    ~CExoLinkedListTemplatedNWModuleExpansion_st();
};

void CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stDtor(CExoLinkedListTemplatedNWModuleExpansion_st* thisPtr);

}

}
