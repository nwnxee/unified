#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCKeyTableInfo
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCKeyTableInfo() = default;
    CExoLinkedListTemplatedCKeyTableInfo(const CExoLinkedListTemplatedCKeyTableInfo&) = default;
    CExoLinkedListTemplatedCKeyTableInfo& operator=(const CExoLinkedListTemplatedCKeyTableInfo&) = default;

    ~CExoLinkedListTemplatedCKeyTableInfo();
};

void CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoDtor(CExoLinkedListTemplatedCKeyTableInfo* thisPtr);

}

}
