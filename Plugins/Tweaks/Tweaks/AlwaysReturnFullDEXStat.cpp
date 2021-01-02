#include "Tweaks/AlwaysReturnFullDEXStat.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWRace.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

AlwaysReturnFullDEXStat::AlwaysReturnFullDEXStat(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats10GetDEXStatEv>(&GetDEXStatHook);
}

uint8_t AlwaysReturnFullDEXStat::GetDEXStatHook(CNWSCreatureStats *pCreatureStats)
{
    return std::max(pCreatureStats->m_nDexterityBase +
                    pCreatureStats->GetTotalDEXBonus() +
                    Globals::Rules()->m_lstRaces[pCreatureStats->m_nRace].m_nDEXAdjust +
                    pCreatureStats->GetClassesAbilityAdjust(Constants::Ability::Dexterity), 3);
}

}
