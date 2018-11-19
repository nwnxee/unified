#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CFeatUseListEntry;

struct CExoArrayListTemplatedCFeatUseListEntryPtr
{
    CFeatUseListEntry** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCFeatUseListEntryPtr() = default;
    CExoArrayListTemplatedCFeatUseListEntryPtr(const CExoArrayListTemplatedCFeatUseListEntryPtr&) = default;
    CExoArrayListTemplatedCFeatUseListEntryPtr& operator=(const CExoArrayListTemplatedCFeatUseListEntryPtr&) = default;

    ~CExoArrayListTemplatedCFeatUseListEntryPtr();
};

void CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrDtor(CExoArrayListTemplatedCFeatUseListEntryPtr* thisPtr);

}

}
