#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWCCMessageData.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void SummonAssociateUseComputeSafeLocation() __attribute__((constructor));
void SummonAssociateUseComputeSafeLocation()
{
    if (!Config::Get<bool>("SUMMON_ASSOCIATE_USE_COMPUTE_SAFE_LOCATION", false))
        return;

    LOG_INFO("SummonAssociate() will use ComputeSafeLocation() instead of ComputeNonVisibleLocation().");

    static Hooks::Hook s_GetDEXStatHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature15SummonAssociateE7CResRef10CExoStringt,
        (void*)+[](CNWSCreature *pThis, CResRef cResRef, CExoString sAssociateName, uint16_t nAssociateType) -> void
        {
            CNWSCreature *pCreature = new CNWSCreature;
            if (!pCreature->LoadFromTemplate(cResRef))
            {
                LOG_WARNING("Failed to summon associate, invalid creature file: %s", cResRef);
                delete pCreature;
                return;
            }

            CExoLocString sName;
            sName.AddString(0, sAssociateName);
            pCreature->m_pStats->m_lsFirstName = sName;
            pCreature->SetAssociateType(nAssociateType);

            if (auto *pArea = pThis->GetArea())
            {
                Vector vSpawnPosition{};
                if (!pArea->ComputeSafeLocation(pThis->m_vPosition, 20.0f, pCreature->m_pcPathfindInformation, false, &vSpawnPosition))
                {
                    LOG_WARNING("Failed to compute safe location, using master's position.");
                    vSpawnPosition = pThis->m_vPosition;
                }

                pThis->AddAssociate(pCreature->m_idSelf, nAssociateType);

                auto *pEffect = new CGameEffect;
                pEffect->m_nType = Constants::EffectTrueType::VisualEffect;
                pEffect->SetInteger(0, 36);
                pArea->ApplyEffect(pEffect, vSpawnPosition, pThis->m_vOrientation);

                pCreature->SetPosition(vSpawnPosition);
                pCreature->AddToArea(pArea, vSpawnPosition.x, vSpawnPosition.y, pArea->ComputeHeight(vSpawnPosition));

                auto *pMessageData = new CNWCCMessageData;
                pMessageData->SetObjectID(0, pCreature->m_idSelf);
                pThis->SendFeedbackMessage(154, pMessageData);
            }
            else
            {
                LOG_WARNING("Associate's master is in an invalid area somehow? How did this happen.");
            }
        }, Hooks::Order::Final);
}

}
