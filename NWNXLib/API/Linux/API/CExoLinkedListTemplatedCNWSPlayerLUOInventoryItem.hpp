#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem() = default;
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem(const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem&) = default;
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem& operator=(const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem&) = default;

    ~CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem();
};

void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemDtor(CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem* thisPtr);

}

}
