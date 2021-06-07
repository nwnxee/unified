#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CFactionManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CNWSModule.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

void DisableLevelUpValidation() __attribute__((constructor));
void DisableLevelUpValidation()
{
    if (!Config::Get<bool>("DISABLE_LEVELUP_VALIDATION", false))
        return;

    LOG_INFO("EXPERIMENTAL: Disabling LevelUp Validation.");

    static Hooks::Hook s_ValidateLevelUpHook = Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh,
        (void*)+[](CNWSCreatureStats* pCreatureStats, CNWLevelStats* pLevelUpStats, uint8_t nDomain1, uint8_t nDomain2, uint8_t nSchool) -> uint32_t
        {
            bool bValidated = pCreatureStats->CanLevelUp() && pCreatureStats->GetIsClassAvailable(pLevelUpStats->m_nClass);

            if (!bValidated)
                return 57924;

            if (pCreatureStats->m_bIsPC)
            {
                // Validation goes here, but we're skipping it aaaaaall.

                if (auto *pModule = Utils::GetModule())
                {
                    auto* pScriptEvent = new CScriptEvent;
                    pScriptEvent->m_nType = ScriptEvent::OnPlayerLevelUp;
                    Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerAIMaster->AddEventAbsoluteTime(
                            0, 0, pCreatureStats->m_pBaseCreature->m_idSelf, pModule->m_idSelf, Event::SignalEvent, pScriptEvent);

                }
            }

            pCreatureStats->LevelUp(pLevelUpStats, nDomain1, nDomain2, nSchool, true);
            pCreatureStats->UpdateCombatInformation();

            return 0;
        }, Hooks::Order::Final);
}

}
