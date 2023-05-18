#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CGameEffect.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNWSFaction.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixTURDEffectUnlinking() __attribute__((constructor));
void FixTURDEffectUnlinking()
{
    if (!Config::Get<bool>("FIX_TURD_EFFECT_UNLINKING", false))
        return;

    LOG_INFO("Fixing effects unlinking when restored from a TURD.");

    static Hooks::Hook s_EatTURDHook = Hooks::HookFunction(&CNWSPlayer::EatTURD,
    +[](CNWSPlayer *pThis, CNWSPlayerTURD *pTURD) -> void
    {
        auto *pCreature = Utils::AsNWSCreature(pThis->GetGameObject());

        ObjectID oidOld = pThis->GetGameObject()->m_idSelf;
        int32_t nAILevel = 0;

        if (pCreature)
        {
            nAILevel = pCreature->m_nAILevel;
            Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->RemoveObject(pCreature);
        }

        CGameObject *pObject;
        Globals::AppManager()->m_pServerExoApp->GetObjectArray()->Delete(pThis->GetGameObject()->m_idSelf, &pObject);
        pObject->SetId(pTURD->m_oidPlayer);
        Globals::AppManager()->m_pServerExoApp->GetObjectArray()->AddObjectAtPos(pObject->m_idSelf, pObject);

        if (pCreature)
            Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->AddObject(pCreature, nAILevel);

        pThis->SetGameObject(Utils::AsNWSObject(pObject));
        pThis->m_oidPCObject = pObject->m_idSelf;

        pCreature->GetFaction()->ChangeMemberId(oidOld, pObject->m_idSelf);
        pCreature->ResetItemPossessor();

        delete pCreature->m_pReputation;
        pCreature->m_pReputation = pTURD->m_pReputation;
        pTURD->m_pReputation = nullptr;

        delete pCreature->m_pPersonalReputationList;
        pCreature->m_pPersonalReputationList = pTURD->m_pPersonalReputationList;
        pTURD->m_pPersonalReputationList = nullptr;

        pCreature->m_oidDesiredArea = pTURD->m_oidArea;
        pCreature->m_vDesiredAreaLocation = pTURD->m_vPosition;
        pCreature->m_bDesiredAreaUpdateComplete = false;
        pCreature->SetOrientation(pTURD->m_vOrientation);

        pCreature->CopyScriptVars(&pTURD->m_ScriptVars);
        pCreature->ReloadJournalEntries();
        pCreature->SetAutoMapData(pTURD->m_nNumAutomapAreas, pTURD->m_poidAutomapAreasList, pTURD->m_pAutoMapTileData);

        for (int i = 0; i < pTURD->m_appliedEffects.num; i++)
        {
            auto *pEffect = pTURD->m_appliedEffects.element[i];
            if (!pEffect->m_bSkipOnLoad && pEffect->GetDurationType() != Constants::EffectDurationType::Equipped)
            {
                auto *pNewEffect = new CGameEffect(false);
                pNewEffect->CopyEffect(pEffect);
                pCreature->ApplyEffect(pNewEffect, true);
            }
        }

        while (!pCreature->m_lQueuedActions.IsEmpty())
        {
            auto *pNode = pCreature->m_lQueuedActions.RemoveHead();
            delete pNode;
        }

        pThis->m_bFromTURD = true;

        pTURD->RemoveFromArea();
        Utils::GetModule()->RemoveFromTURDList(pThis);
    }, Hooks::Order::Final);

    static Hooks::Hook s_CopyEffectListHook = Hooks::HookFunction(&CNWSPlayerTURD::CopyEffectList,
    +[](CNWSPlayerTURD *pThis, CExoArrayList<CGameEffect*> *pEffectList) -> void
    {
        for (int i = 0; i < pEffectList->num; i++)
        {
            auto *pEffect = new CGameEffect(false);
            pEffect->CopyEffect(pEffectList->element[i]);
            pThis->m_appliedEffects.Add(pEffect);
        }
    }, Hooks::Order::Final);
}

}
