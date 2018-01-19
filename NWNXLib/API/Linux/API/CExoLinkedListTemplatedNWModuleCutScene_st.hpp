#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedNWModuleCutScene_st
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedNWModuleCutScene_st() = default;
    CExoLinkedListTemplatedNWModuleCutScene_st(const CExoLinkedListTemplatedNWModuleCutScene_st&) = default;
    CExoLinkedListTemplatedNWModuleCutScene_st& operator=(const CExoLinkedListTemplatedNWModuleCutScene_st&) = default;

    ~CExoLinkedListTemplatedNWModuleCutScene_st();
};

void CExoLinkedListTemplatedNWModuleCutScene_st__CExoLinkedListTemplatedNWModuleCutScene_stDtor(CExoLinkedListTemplatedNWModuleCutScene_st* thisPtr);

}

}
