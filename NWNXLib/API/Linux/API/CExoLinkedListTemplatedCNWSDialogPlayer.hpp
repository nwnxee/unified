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
    CExoLinkedListTemplatedCNWSDialogPlayer();
    CExoLinkedListTemplatedCNWSDialogPlayer(const CExoLinkedListTemplatedCNWSDialogPlayer&);
    CExoLinkedListTemplatedCNWSDialogPlayer& operator=(const CExoLinkedListTemplatedCNWSDialogPlayer&);

    ~CExoLinkedListTemplatedCNWSDialogPlayer();
};

void CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerDtor(CExoLinkedListTemplatedCNWSDialogPlayer* thisPtr);

}

}
