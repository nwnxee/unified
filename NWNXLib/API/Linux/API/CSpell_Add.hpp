#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CSpell_Add
{
    uint32_t m_nSpellID;
    int32_t m_bReadied;
    int32_t m_bDomainSpell;
    uint8_t m_nMetaType;
    uint8_t m_nSpellSlot;
    uint8_t m_nSpellLevel;
};

}

}
