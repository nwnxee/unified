#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSStats_SpellLikeAbility
{
    uint32_t m_nSpellId;
    int32_t m_bReadied;
    uint8_t m_nCasterLevel;

    // The below are auto generated stubs.
    CNWSStats_SpellLikeAbility(const CNWSStats_SpellLikeAbility&) = default;
    CNWSStats_SpellLikeAbility& operator=(const CNWSStats_SpellLikeAbility&) = default;

    CNWSStats_SpellLikeAbility();
};

void CNWSStats_SpellLikeAbility__CNWSStats_SpellLikeAbilityCtor__0(CNWSStats_SpellLikeAbility* thisPtr);

}

}
