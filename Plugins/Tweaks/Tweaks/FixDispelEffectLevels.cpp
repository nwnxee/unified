#include "Tweaks/FixDispelEffectLevels.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSRules.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

FixDispelEffectLevels::FixDispelEffectLevels(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN21CNWSEffectListHandler21OnApplyDispelAllMagicEP10CNWSObjectP11CGameEffecti>
        (&CNWSEffectListHandler__OnApplyDispelAllMagic);
    hooker->RequestExclusiveHook<Functions::_ZN21CNWSEffectListHandler22OnApplyDispelBestMagicEP10CNWSObjectP11CGameEffecti>
        (&CNWSEffectListHandler__OnApplyDispelBestMagic);
}

int32_t FixDispelEffectLevels::CNWSEffectListHandler__OnApplyDispelAllMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame)
{
    (void)thisPtr;
    (void)bLoadingGame;
    auto nDispelLevel = pEffect->GetInteger(0);
    int nDispelledEffects = 0;
    auto* pCreatorObject = Utils::GetGameObject(pEffect->m_oidCreator);
    if (nDispelLevel < 1)
    {
        if (auto* pCreature = Utils::AsNWSCreature(pCreatorObject))
            nDispelLevel = pCreature->m_pStats->GetLevel(0);
        else
            return 1;
    }

    std::vector<uint64_t> nIgnoreEffectIDs;
    CNWCCMessageData messageData;
    messageData.SetObjectID(0, pObject->m_idSelf);

    for (auto* effect : pObject->m_appliedEffects)
    {
        if (((effect->m_nSubType & (Constants::EffectSubType::Magical | Constants::EffectSubType::Supernatural)) != Constants::EffectSubType::Magical)
            || ((effect->m_nSubType & 7) != Constants::EffectDurationType::Temporary && (effect->m_nSubType & 7) != Constants::EffectDurationType::Permanent))
            continue;

        if (std::find(nIgnoreEffectIDs.begin(), nIgnoreEffectIDs.end(), effect->m_nID) != nIgnoreEffectIDs.end())
            continue;

        auto nEffectLevel = effect->m_nCasterLevel;
        if (auto* pCreator = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(effect->m_oidCreator))
        {
            if (nEffectLevel == -1)
                nEffectLevel = pCreator->m_pStats->GetLevel(0);
        }
        else
        {
            if (nEffectLevel == -1) //FIX: Added check to use saved caster level when objects are removed (dead NPCs / disconnected PCs)
                nEffectLevel = 0;
        }

        auto nRoll = Globals::Rules()->RollDice(1, 20);
        if (nRoll + nDispelLevel > 10 + nEffectLevel)
        {
            auto* pAIMaster = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
            pAIMaster->AddEventDeltaTime(0, 0, pEffect->m_oidCreator, pObject->m_idSelf, Constants::Event::RemoveEffect, effect);
            if (effect->m_nSpellId != ~0u)
                messageData.SetInteger(++nDispelledEffects, effect->m_nSpellId);
        }

        nIgnoreEffectIDs.push_back(effect->m_nID);
    }

    messageData.SetInteger(0, nDispelledEffects);
    if (nDispelledEffects > 0)
    {
        if (auto* pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pObject->m_idSelf))
            if (auto* pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
                pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID, Constants::MessageClientSideMsgMinor::DispelMagic, &messageData, nullptr);

        if (pCreatorObject && pCreatorObject->m_idSelf != pObject->m_idSelf)
            if (auto* pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreatorObject->m_idSelf))
                if (auto* pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
                    pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID, Constants::MessageClientSideMsgMinor::DispelMagic, &messageData, nullptr);
    }

    return 1;
}

int32_t FixDispelEffectLevels::CNWSEffectListHandler__OnApplyDispelBestMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame)
{
    (void)thisPtr;
    (void)bLoadingGame;
    auto nDispelLevel = pEffect->GetInteger(0);
    if (nDispelLevel < 0)
    {
        if (auto* pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pEffect->m_oidCreator)))
            nDispelLevel = pCreature->m_pStats->GetLevel(0);
        else
            return 1;
    }

    std::vector<uint64_t> nFailedDispelIds;

    for (auto* effect : pObject->m_appliedEffects)
    {
        if (((effect->m_nSubType & (Constants::EffectSubType::Magical | Constants::EffectSubType::Supernatural)) != Constants::EffectSubType::Magical)
            || ((effect->m_nSubType & 7) != Constants::EffectDurationType::Temporary && (effect->m_nSubType & 7) != Constants::EffectDurationType::Permanent))
            continue;

        if (std::find(nFailedDispelIds.begin(), nFailedDispelIds.end(), effect->m_nID) != nFailedDispelIds.end())
            continue;

        auto nEffectLevel = effect->m_nCasterLevel;
        if (auto* pCreator = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(effect->m_oidCreator))
        {
            if (nEffectLevel == -1)
                nEffectLevel = pCreator->m_pStats->GetLevel(0);

            if (nEffectLevel < 1)
                continue;
        }
        else
        {
            if (nEffectLevel == -1) //FIX: Added check to use saved caster level when objects are removed (dead NPCs / disconnected PCs)
                nEffectLevel = 0;
        }

        auto nRoll = Globals::Rules()->RollDice(1, 20);
        if (nRoll + nDispelLevel > 10 + nEffectLevel)
        {
            if (effect->m_nSpellId != ~0u)
            {
                CNWCCMessageData messageData;
                messageData.SetObjectID(0, pObject->m_idSelf);
                messageData.SetInteger(0, 1);
                messageData.SetInteger(1, effect->m_nSpellId);
                if (auto* pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pObject->m_idSelf))
                    if (auto* pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
                        pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID, Constants::MessageClientSideMsgMinor::DispelMagic, &messageData, nullptr);
            }

            auto* pAIMaster = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
            pAIMaster->AddEventDeltaTime(0, 0, pEffect->m_oidCreator, pObject->m_idSelf, Constants::Event::RemoveEffect, effect);
            return 1;
        }
        nFailedDispelIds.push_back(effect->m_nID);
    }

    return 1;
}

}