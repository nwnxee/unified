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
    CExoLinkedListTemplatedCExoKeyTable();
    CExoLinkedListTemplatedCExoKeyTable(const CExoLinkedListTemplatedCExoKeyTable&);
    CExoLinkedListTemplatedCExoKeyTable& operator=(const CExoLinkedListTemplatedCExoKeyTable&);

    ~CExoLinkedListTemplatedCExoKeyTable();
};

void CExoLinkedListTemplatedCExoKeyTable__CExoLinkedListTemplatedCExoKeyTableDtor(CExoLinkedListTemplatedCExoKeyTable* thisPtr);

}

}
