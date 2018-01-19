#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPlayerJournalQuestUpdates;

struct CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates
{
    CNWSPlayerJournalQuestUpdates* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates* thisPtr, int32_t);

}

}
