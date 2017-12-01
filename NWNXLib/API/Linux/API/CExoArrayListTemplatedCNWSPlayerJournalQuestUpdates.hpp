#pragma once

#include <cstdint>

#include "CNWSPlayerJournalQuestUpdates.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates
{
    CNWSPlayerJournalQuestUpdates* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates();
    CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates(const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates&);
    CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates& operator=(const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates&);

    ~CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates();
    void Add(CNWSPlayerJournalQuestUpdates);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__CExoArrayListTemplatedCNWSPlayerJournalQuestUpdatesDtor(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates* thisPtr);
void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Add(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates* thisPtr, CNWSPlayerJournalQuestUpdates);
void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates* thisPtr, int32_t);

}

}
