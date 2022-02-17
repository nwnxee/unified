#include "nwnx.hpp"

#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWClass.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixMulticlassXPPenaltyBug() __attribute__((constructor));
void FixMulticlassXPPenaltyBug()
{
    if (!Config::Get<bool>("FIX_MULTICLASS_XP_PENALTY_BUG", false))
        return;

    LOG_INFO("Fixing a multiclass xp penalty bug.");

    static Hooks::Hook s_AddExperienceHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13AddExperienceEj,
        (void*)+[](CNWSCreatureStats *pThis, uint32_t nValue) -> void
        {
            if (pThis->m_pBaseCreature->m_nAssociateType != Constants::AssociateType::None)
                return;

            if (pThis->m_nNumMultiClasses > 1)
            {
                auto GetCNWClass = [](uint8_t nClass) -> CNWClass*
                {
                    if (nClass < Globals::Rules()->m_nNumClasses)
                        return &Globals::Rules()->m_lstClasses[nClass];
                    else
                        return nullptr;
                };

                uint8_t nFavoredClass = Globals::Rules()->m_lstRaces[pThis->m_nRace].m_nFavoredClass;
                if (nFavoredClass == Constants::ClassType::Invalid)
                {
                    uint8_t nMaxLevelMultiClass = 0;

                    if (auto *pClass = GetCNWClass(pThis->GetClass(1)))
                    {
                        if (pClass->m_sPreReqTable == "" && pThis->GetClassLevel(0) < pThis->GetClassLevel(1))
                            nMaxLevelMultiClass = 1;
                    }

                    if (auto *pClass = GetCNWClass(pThis->GetClass(2)))
                    {
                        if (pClass->m_sPreReqTable == "" && pThis->GetClassLevel(nMaxLevelMultiClass) < pThis->GetClassLevel(2))
                            nMaxLevelMultiClass = 2;
                    }

                    nFavoredClass = pThis->GetClass(nMaxLevelMultiClass);
                }

                uint8_t nMaxLevel = 0;
                for (uint8_t nMultiClass = 0; nMultiClass < pThis->m_nNumMultiClasses; nMultiClass++)
                {
                    uint8_t nClass = pThis->GetClass(nMultiClass);
                    if (auto *pClass = GetCNWClass(nClass))
                    {
                        if (nFavoredClass != nClass && pClass->m_bXPPenalty)
                            nMaxLevel = std::max(nMaxLevel, pThis->GetClassLevel(nMultiClass));
                    }
                }

                double dXPPenalties = 0.0;
                for (uint8_t nMultiClass = 0; nMultiClass < pThis->m_nNumMultiClasses; nMultiClass++)
                {
                    uint8_t nClass = pThis->GetClass(nMultiClass);
                    if (auto *pClass = GetCNWClass(nClass))
                    {
                        if (nFavoredClass != nClass && pClass->m_bXPPenalty)
                        {
                            if ((nMaxLevel - pThis->GetClassLevel(nMultiClass)) >= 2)
                                dXPPenalties += 1.0;
                        }
                    }
                }

                nValue = (uint32_t)(((double)nValue) * (1.0l - 0.2l * dXPPenalties));
            }

            pThis->SetExperience(pThis->m_nExperience + nValue);
        }, Hooks::Order::Final);
}

}
