#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCExoKeyTable
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCExoKeyTable() = default;
    CExoLinkedListTemplatedCExoKeyTable(const CExoLinkedListTemplatedCExoKeyTable&) = default;
    CExoLinkedListTemplatedCExoKeyTable& operator=(const CExoLinkedListTemplatedCExoKeyTable&) = default;

    ~CExoLinkedListTemplatedCExoKeyTable();
};

void CExoLinkedListTemplatedCExoKeyTable__CExoLinkedListTemplatedCExoKeyTableDtor(CExoLinkedListTemplatedCExoKeyTable* thisPtr);

}

}
