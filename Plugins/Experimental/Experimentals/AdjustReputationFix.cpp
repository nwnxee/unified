#include "Experimentals/AdjustReputationFix.hpp"


#include "API/CAppManager.hpp"
#include "API/CFactionManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

AdjustReputationFix::AdjustReputationFix()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature16AdjustReputationEii, (void*)&CNWSCreature__AdjustReputation_Hook, Hooks::Order::Final);
}

void AdjustReputationFix::CNWSCreature__AdjustReputation_Hook(CNWSCreature *pThis, int32_t nFactionId, int32_t nAdjustment)
{
    auto* pFactionManager = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager;

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
}
}
