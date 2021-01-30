#include "Tweaks/DisplayNumAttacksOverrideInCharacterSheet.hpp"
#include "API/CNWSCreatureStats.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooks::Hook s_GetAttacksPerRoundHook;

DisplayNumAttacksOverrideInCharacterSheet::DisplayNumAttacksOverrideInCharacterSheet()
{
    s_GetAttacksPerRoundHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats18GetAttacksPerRoundEv,
                                            (void*)&GetAttacksPerRoundHook, Hooks::Order::Late);
}

uint8_t DisplayNumAttacksOverrideInCharacterSheet::GetAttacksPerRoundHook(CNWSCreatureStats *pCreatureStats)
{
    if (pCreatureStats->m_nOverrideBaseAttackBonus)
        return pCreatureStats->m_nOverrideBaseAttackBonus;
    else
        return s_GetAttacksPerRoundHook->CallOriginal<uint8_t>(pCreatureStats);
}

}
