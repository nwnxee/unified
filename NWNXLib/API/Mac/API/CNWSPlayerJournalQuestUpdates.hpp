#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWSPlayerJournalQuestUpdates
{
    uint16_t flags;
    CExoString szPlot_Id;
};

}

}
