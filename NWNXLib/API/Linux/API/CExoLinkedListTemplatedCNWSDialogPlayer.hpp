#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListInternal;

struct CExoLinkedListTemplatedCNWSDialogPlayer
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;

    // The below are auto generated stubs.
    CExoLinkedListTemplatedCNWSDialogPlayer() = default;
    CExoLinkedListTemplatedCNWSDialogPlayer(const CExoLinkedListTemplatedCNWSDialogPlayer&) = default;
    CExoLinkedListTemplatedCNWSDialogPlayer& operator=(const CExoLinkedListTemplatedCNWSDialogPlayer&) = default;

    ~CExoLinkedListTemplatedCNWSDialogPlayer();
};

void CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerDtor(CExoLinkedListTemplatedCNWSDialogPlayer* thisPtr);

}

}
