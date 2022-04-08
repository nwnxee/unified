#include "nwnx.hpp"

#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWRace.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void AlwaysReturnFullDEXStat() __attribute__((constructor));
void AlwaysReturnFullDEXStat()
{
    if (!Config::Get<bool>("ALWAYS_RETURN_FULL_DEX_STAT", false))
        return;

    LOG_INFO("GetDEXStat() is always returning a creature's full Dexterity Stat.");

    static Hooks::Hook s_GetDEXStatHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats10GetDEXStatEv,
        (void*)+[](CNWSCreatureStats *pCreatureStats) -> uint8_t
        {
            return std::max(pCreatureStats->m_nDexterityBase +
                            pCreatureStats->GetTotalDEXBonus() +
                            Globals::Rules()->m_lstRaces[pCreatureStats->m_nRace].m_nDEXAdjust +
                            pCreatureStats->GetClassesAbilityAdjust(Constants::Ability::Dexterity), 3);
        }, Hooks::Order::Final);
}

}
