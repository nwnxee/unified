#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSStats_Spell
{
    uint32_t m_nSpellId;
    int32_t m_bReadied;
    uint8_t m_nMetaType;
    int32_t m_bDomainSpell;

    // The below are auto generated stubs.
    CNWSStats_Spell(const CNWSStats_Spell&) = default;
    CNWSStats_Spell& operator=(const CNWSStats_Spell&) = default;

    CNWSStats_Spell();
};

void CNWSStats_Spell__CNWSStats_SpellCtor__0(CNWSStats_Spell* thisPtr);

}

}
