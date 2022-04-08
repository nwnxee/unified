#include "nwnx.hpp"

#include "API/CNWSCreatureStats.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void DisplayNumAttacksOverrideInCharacterSheet() __attribute__((constructor));
void DisplayNumAttacksOverrideInCharacterSheet()
{
    if (!Config::Get<bool>("DISPLAY_NUM_ATTACKS_OVERRIDE_IN_CHARACTER_SHEET", false))
        return;

    LOG_INFO("Number of attacks per round overridden by SetBaseAttackBonus() will show on the character sheet.");

    static Hooks::Hook s_GetAttacksPerRoundHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats18GetAttacksPerRoundEv,
    (void*)+[](CNWSCreatureStats *pCreatureStats) -> uint8_t
    {
        if (pCreatureStats->m_nOverrideBaseAttackBonus)
            return pCreatureStats->m_nOverrideBaseAttackBonus;
        else
            return s_GetAttacksPerRoundHook->CallOriginal<uint8_t>(pCreatureStats);
    }, Hooks::Order::Late);
}

}
