#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedSJournalEntry.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSCreature;

struct CNWSJournal
{
    CExoArrayListTemplatedSJournalEntry m_lstEntries;
    CNWSCreature* m_pCreature;

    // The below are auto generated stubs.
    CNWSJournal(const CNWSJournal&) = default;
    CNWSJournal& operator=(const CNWSJournal&) = default;

    CNWSJournal();
    ~CNWSJournal();
    void Destroy(CExoString);
    void SetDate(CExoString, uint32_t, int32_t);
    void SetPicture(CExoString, int32_t, int32_t);
    void SetState(CExoString, uint32_t, int32_t);
    void SetTime(CExoString, uint32_t, int32_t);
};

void CNWSJournal__CNWSJournalCtor(CNWSJournal* thisPtr);
void CNWSJournal__CNWSJournalDtor(CNWSJournal* thisPtr);
void CNWSJournal__Destroy(CNWSJournal* thisPtr, CExoString);
void CNWSJournal__SetDate(CNWSJournal* thisPtr, CExoString, uint32_t, int32_t);
void CNWSJournal__SetPicture(CNWSJournal* thisPtr, CExoString, int32_t, int32_t);
void CNWSJournal__SetState(CNWSJournal* thisPtr, CExoString, uint32_t, int32_t);
void CNWSJournal__SetTime(CNWSJournal* thisPtr, CExoString, uint32_t, int32_t);

}

}
