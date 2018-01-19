#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CEncounterListEntry
{
    CResRef m_cCreatureResRef;
    float m_fCR;
    float m_fCreaturePoints;
    int32_t m_bAlreadyUsed;
    int32_t m_bAlreadyChecked;
    int32_t m_bUnique;
};

}

}
