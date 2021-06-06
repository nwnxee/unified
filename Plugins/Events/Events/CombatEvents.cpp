#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSClient.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWCCMessageData.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_StartCombatRoundHook;
static Hooks::Hook s_ApplyDisarmHook;
static Hooks::Hook s_SendServerToPlayerAmbientBattleMusicPlayHook;
static Hooks::Hook s_SendFeedbackMessageHook;

static void StartCombatRoundHook(CNWSCombatRound*, ObjectID);
static int32_t ApplyDisarmHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
static int32_t SendServerToPlayerAmbientBattleMusicPlayHook(CNWSMessage*, PlayerID, BOOL);
static void SendFeedbackMessageHook(CNWSCreature*, uint16_t, CNWCCMessageData*, CNWSPlayer*);

void CombatEvents() __attribute__((constructor));
void CombatEvents()
{
    InitOnFirstSubscribe("NWNX_ON_START_COMBAT_ROUND_.*", []() {
        s_StartCombatRoundHook = Hooks::HookFunction(API::Functions::_ZN15CNWSCombatRound16StartCombatRoundEj,
                                                     (void*)&StartCombatRoundHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_DISARM_*", []() {
        s_ApplyDisarmHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler13OnApplyDisarmEP10CNWSObjectP11CGameEffecti,
                                                (void*)&ApplyDisarmHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_ENTER.*", []() {
        s_SendServerToPlayerAmbientBattleMusicPlayHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage40SendServerToPlayerAmbientBattleMusicPlayEji,
                (void*)&SendServerToPlayerAmbientBattleMusicPlayHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_DR_BROKEN.*", []() {
        s_SendFeedbackMessageHook = Hooks::HookFunction(
                API::Functions::_ZN12CNWSCreature19SendFeedbackMessageEtP16CNWCCMessageDataP10CNWSPlayer,
                (void*)&SendFeedbackMessageHook, Hooks::Order::Earliest);
    });
}

void StartCombatRoundHook(CNWSCombatRound* thisPtr, ObjectID oidTarget)
{
    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    SignalEvent("NWNX_ON_START_COMBAT_ROUND_BEFORE" , thisPtr->m_pBaseCreature->m_idSelf);
    s_StartCombatRoundHook->CallOriginal<void>(thisPtr, oidTarget);
    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    SignalEvent("NWNX_ON_START_COMBAT_ROUND_AFTER" , thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t ApplyDisarmHook(CNWSEffectListHandler* pEffectHandler, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("DISARMER_OBJECT_ID", Utils::ObjectIDToString(pEffect->m_oidCreator));
        auto nFeatId = pEffect->GetInteger(0) == 1 ? Constants::Feat::ImprovedDisarm : Constants::Feat::Disarm;
        PushEventData("FEAT_ID", std::to_string(nFeatId));
        return SignalEvent(ev, pObject->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_DISARM_BEFORE"))
    {
        retVal = s_ApplyDisarmHook->CallOriginal<int32_t>(pEffectHandler, pObject, pEffect, bLoadingGame);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_DISARM_AFTER");

    return retVal;
}

int32_t SendServerToPlayerAmbientBattleMusicPlayHook(CNWSMessage *pMessage, PlayerID nPlayer, BOOL bPlay)
{
    if (auto *pPlayer = static_cast<CNWSPlayer *>(Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayer)))
    {
        if (bPlay)
        {
            SignalEvent("NWNX_ON_COMBAT_ENTER_BEFORE", pPlayer->m_oidNWSObject);
            auto retVal = s_SendServerToPlayerAmbientBattleMusicPlayHook->CallOriginal<int32_t>(pMessage, nPlayer, bPlay);
            SignalEvent("NWNX_ON_COMBAT_ENTER_AFTER", pPlayer->m_oidNWSObject);
            return retVal;
        }
        else
        {
            SignalEvent("NWNX_ON_COMBAT_EXIT_BEFORE", pPlayer->m_oidNWSObject);
            auto retVal = s_SendServerToPlayerAmbientBattleMusicPlayHook->CallOriginal<int32_t>(pMessage, nPlayer, bPlay);
            SignalEvent("NWNX_ON_COMBAT_EXIT_AFTER", pPlayer->m_oidNWSObject);
            return retVal;
        }
    }

    return s_SendServerToPlayerAmbientBattleMusicPlayHook->CallOriginal<int32_t>(pMessage, nPlayer, bPlay);
}

void SendFeedbackMessageHook(CNWSCreature *pCreature, uint16_t nFeedbackID, CNWCCMessageData *pMessageData , CNWSPlayer *pFeedbackPlayer)
{
    if (!pMessageData ||
        (nFeedbackID != 66 /*DAMAGE_RESISTANCE_REMAINING*/ && nFeedbackID != 67 /*DAMAGE_REDUCTION_REMAINING*/) ||
        pCreature->m_idSelf != pMessageData->GetObjectID(0) ||
        pMessageData->GetInteger(2)/*Remaining DR*/ != 0)
    {
        s_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pMessageData, pFeedbackPlayer);
        return;
    }

    PushEventData("TYPE", std::to_string(nFeedbackID == 66 ? 1 : 0));
    SignalEvent("NWNX_ON_COMBAT_DR_BROKEN_BEFORE", pCreature->m_idSelf);
    s_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pMessageData, pFeedbackPlayer);
    PushEventData("TYPE", std::to_string(nFeedbackID == 66 ? 1 : 0));
    SignalEvent("NWNX_ON_COMBAT_DR_BROKEN_AFTER", pCreature->m_idSelf);
}

}
