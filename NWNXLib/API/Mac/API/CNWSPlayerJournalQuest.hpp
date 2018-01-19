#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates.hpp"

namespace NWNXLib {

namespace API {

struct CNWSPlayerJournalQuest
{
    int32_t m_bOpen;
    CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates m_lstModifications;
    int32_t m_bFullUpdateNeeded;
};

}

}
