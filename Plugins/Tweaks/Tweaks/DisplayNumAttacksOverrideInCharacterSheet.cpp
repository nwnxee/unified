#include "Tweaks/DisplayNumAttacksOverrideInCharacterSheet.hpp"
#include "API/CNWSCreatureStats.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* s_GetAttacksPerRoundHook;

DisplayNumAttacksOverrideInCharacterSheet::DisplayNumAttacksOverrideInCharacterSheet(Services::HooksProxy* hooker)
{
    s_GetAttacksPerRoundHook = hooker->Hook(Functions::_ZN17CNWSCreatureStats18GetAttacksPerRoundEv,
                                            (void*)&GetAttacksPerRoundHook, Hooking::Order::Late);
}

uint8_t DisplayNumAttacksOverrideInCharacterSheet::GetAttacksPerRoundHook(CNWSCreatureStats *pCreatureStats)
{
    if (pCreatureStats->m_nOverrideBaseAttackBonus)
        return pCreatureStats->m_nOverrideBaseAttackBonus;
    else
        return s_GetAttacksPerRoundHook->CallOriginal<uint8_t>(pCreatureStats);
}

}
