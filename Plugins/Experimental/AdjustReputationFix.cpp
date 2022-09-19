#include "nwnx.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CFactionManager.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

void AdjustReputationFix() __attribute__((constructor));
void AdjustReputationFix()
{
    if (!Config::Get<bool>("ADJUST_REPUTATION_FIX", false))
        return;

    LOG_INFO("EXPERIMENTAL: Attempting to resolve faction/reputation crash.");

    static Hooks::Hook s_AdjustReputationHook = Hooks::HookFunction(&CNWSCreature::AdjustReputation,
        +[](CNWSCreature *pThis, int32_t nFactionId, int32_t nAdjustment) -> void
        {
            auto *pFactionManager = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager;

            if (!pFactionManager->GetIsNPCFaction(nFactionId))
                return;

            if (pThis->m_bPlayerCharacter || pThis->GetIsPossessedFamiliar())
            {
                if (pThis->m_pReputation)
                {
                    int32_t index = nFactionId - 1;
                    if (index >= 0 && index < pThis->m_pReputation->num)
                    {
                        pThis->m_pReputation->element[index] += nAdjustment;
                        pThis->m_pReputation->element[index] = std::clamp(pThis->m_pReputation->element[index], 0, 100);
                    }
                }
            }
            else
            {
                if (pThis->m_pStats->m_nFactionId != nFactionId)
                {
                    int32_t rep = pFactionManager->GetNPCFactionReputation(pThis->m_pStats->m_nFactionId, nFactionId);
                    pFactionManager->SetNPCFactionReputation(pThis->m_pStats->m_nFactionId, nFactionId, (rep + nAdjustment));
                }
            }
        }, Hooks::Order::Final);
}

}
