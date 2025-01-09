#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSEffectListHandler.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWAmbientSound.hpp"
#include "API/CNWSAmbientSound.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_StartCombatRoundHook;
static Hooks::Hook s_ApplyDisarmHook;
static Hooks::Hook s_SendServerToPlayerAmbientBattleMusicPlayHook;
static Hooks::Hook s_SendFeedbackMessageHook;
static Hooks::Hook s_SetCombatModeHook;
static Hooks::Hook s_BroadcastAttackOfOpportunityHook;
static Hooks::Hook s_BroadcastAttackOfOpportunityCombatEventHook;
static Hooks::Hook s_AddAttackActionsHook;
static Hooks::Hook s_AddAttackOfOpportunityHook;
static Hooks::Hook s_SetBroadcastedAOOToHook;
static Hooks::Hook s_PlayBattleMusicHook;
static Hooks::Hook s_AddActionHook;
static Hooks::Hook s_ChangeAttackTargetHook;

static void StartCombatRoundHook(CNWSCombatRound*, ObjectID);
static int32_t ApplyDisarmHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
static int32_t SendServerToPlayerAmbientBattleMusicPlayHook(CNWSMessage*, PlayerID, BOOL);
static void SendFeedbackMessageHook(CNWSCreature*, uint16_t, CNWCCMessageData*, CNWSPlayer*);
static void SetCombatModeHook(CNWSCreature*, uint8_t, int32_t);
static void BroadcastAttackOfOpportunityHook(CNWSCreature*, ObjectID, BOOL);
static void BroadcastAttackOfOpportunityCombatEventHook(CNWSCreature*, ObjectID, BOOL);
static BOOL AddAttackActionsHook(CNWSCreature*, ObjectID, BOOL, BOOL, BOOL);
static void AddAttackOfOpportunityHook(CNWSCombatRound*, ObjectID);
static void SetBroadcastedAOOToHook(CNWSCreature*, BOOL);
static void PlayBattleMusicHook(CNWSAmbientSound*, BOOL);
static void AddActionHook(CNWSObject*, uint32_t, uint16_t,
    uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*,
    uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*,
    uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);
static void ChangeAttackTargetHook(CNWSCreature*, CNWSObjectActionNode*, const OBJECT_ID);

static bool s_InBroadcastAttackOfOpportunity;
static bool s_SkipPushAndSignalCombatAttackOfOpportunityBefore;
static bool s_OnCombatAttackOfOpportunityResult;

void CombatEvents() __attribute__((constructor));
void CombatEvents()
{
    InitOnFirstSubscribe("NWNX_ON_START_COMBAT_ROUND_.*", []() {
        s_StartCombatRoundHook = Hooks::HookFunction(&CNWSCombatRound::StartCombatRound,
                                                     &StartCombatRoundHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_DISARM_*", []() {
        s_ApplyDisarmHook = Hooks::HookFunction(&CNWSEffectListHandler::OnApplyDisarm,
                                                &ApplyDisarmHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_(ENTER|EXIT)_.*", []() {
        s_SendServerToPlayerAmbientBattleMusicPlayHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerAmbientBattleMusicPlay,
                &SendServerToPlayerAmbientBattleMusicPlayHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_DR_BROKEN.*", []() {
        s_SendFeedbackMessageHook = Hooks::HookFunction(
                &CNWSCreature::SendFeedbackMessage,
                &SendFeedbackMessageHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_MODE_.*", []() {
        s_SetCombatModeHook = Hooks::HookFunction(
                &CNWSCreature::SetCombatMode,
                &SetCombatModeHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_.*", []() {
        s_BroadcastAttackOfOpportunityHook = Hooks::HookFunction(
                &CNWSCreature::BroadcastAttackOfOpportunity,
                (void*)&BroadcastAttackOfOpportunityHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_.*", []() {
        s_BroadcastAttackOfOpportunityCombatEventHook = Hooks::HookFunction(
                &CNWSCreature::BroadcastAttackOfOpportunity,
                (void*)&BroadcastAttackOfOpportunityCombatEventHook, Hooks::Order::Earliest);
        s_AddAttackActionsHook = Hooks::HookFunction(
                &CNWSCreature::AddAttackActions,
                (void*)&AddAttackActionsHook, Hooks::Order::Early);
        s_AddAttackOfOpportunityHook = Hooks::HookFunction(
                &CNWSCombatRound::AddAttackOfOpportunity,
                (void*)AddAttackOfOpportunityHook, Hooks::Order::Early);
        s_SetBroadcastedAOOToHook = Hooks::HookFunction(
                &CNWSCreature::SetBroadcastedAOOTo,
                (void*)&SetBroadcastedAOOToHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_AREA_PLAY_BATTLE_MUSIC_.*", []() {
        s_PlayBattleMusicHook = Hooks::HookFunction(
                API::Functions::_ZN16CNWSAmbientSound15PlayBattleMusicEi,
                (void*)PlayBattleMusicHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_ATTACK_TARGET_CHANGE_.*", []() {
        s_AddActionHook = Hooks::HookFunction(&CNWSObject::AddAction, &AddActionHook, Hooks::Order::Early);
        s_ChangeAttackTargetHook = Hooks::HookFunction(&CNWSCreature::ChangeAttackTarget, &ChangeAttackTargetHook, Hooks::Order::Early);
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
    if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayer))
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

void SetCombatModeHook(CNWSCreature* thisPtr, uint8_t nMode, int32_t bForceMode)
{
    if (!thisPtr->m_bPlayerCharacter)
    {
        s_SetCombatModeHook->CallOriginal<void>(thisPtr, nMode, bForceMode);
        return;
    }

    const uint8_t nCurrentMode = thisPtr->m_nCombatMode;

    if (nCurrentMode != nMode)
    {
        if (nCurrentMode != CombatMode::None)
        {
            PushEventData("COMBAT_MODE_ID", std::to_string(nCurrentMode));
            if (SignalEvent("NWNX_ON_COMBAT_MODE_OFF", thisPtr->m_idSelf))
            {
                s_SetCombatModeHook->CallOriginal<void>(thisPtr, nMode, bForceMode);
            }
            return;
        }

        if (nMode != CombatMode::None)
        {
            PushEventData("COMBAT_MODE_ID", std::to_string(nMode));
            if (SignalEvent("NWNX_ON_COMBAT_MODE_ON", thisPtr->m_idSelf))
            {
                s_SetCombatModeHook->CallOriginal<void>(thisPtr, nMode, bForceMode);
            }
            return;
        }
    }

    s_SetCombatModeHook->CallOriginal<void>(thisPtr, nMode, bForceMode);
}

void BroadcastAttackOfOpportunityHook(CNWSCreature *thisPtr, ObjectID oidSingleTarget, BOOL bMovement)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidSingleTarget));
        PushEventData("MOVEMENT", std::to_string(bMovement));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_BEFORE"))
    {
        s_BroadcastAttackOfOpportunityHook->CallOriginal<void>(thisPtr, oidSingleTarget, bMovement);
    }

    PushAndSignal("NWNX_ON_BROADCAST_ATTACK_OF_OPPORTUNITY_AFTER");
}

void BroadcastAttackOfOpportunityCombatEventHook(CNWSCreature *thisPtr, ObjectID oidSingleTarget, BOOL bMovement)
{
    s_InBroadcastAttackOfOpportunity = true;
    s_BroadcastAttackOfOpportunityCombatEventHook->CallOriginal<void>(thisPtr, oidSingleTarget, bMovement);
    s_InBroadcastAttackOfOpportunity = false;
}

BOOL PushAndSignalCombatAttackOfOpportunityBefore(ObjectID oidSelf, ObjectID oidTarget)
{
    // We are possibly called by AddAttackActions before AddAttackOfOpportunity, so only PushAndSignal once
    if (s_SkipPushAndSignalCombatAttackOfOpportunityBefore)
    {
        return s_OnCombatAttackOfOpportunityResult;
    }
    s_SkipPushAndSignalCombatAttackOfOpportunityBefore = true;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        return SignalEvent(ev, oidSelf);
    };

    s_OnCombatAttackOfOpportunityResult = PushAndSignal("NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_BEFORE");
    return s_OnCombatAttackOfOpportunityResult;
}

BOOL AddAttackActionsHook(CNWSCreature *thisPtr, ObjectID oidTarget, BOOL bPassive, BOOL bClearAllActions, BOOL bAddToFront)
{
    if (s_InBroadcastAttackOfOpportunity)
    {
        if (!PushAndSignalCombatAttackOfOpportunityBefore(thisPtr->m_idSelf, oidTarget))
        {
            return false;
        }
    }

    return s_AddAttackActionsHook->CallOriginal<BOOL>(thisPtr, oidTarget, bPassive, bClearAllActions, bAddToFront);
}

void AddAttackOfOpportunityHook(CNWSCombatRound *thisPtr, ObjectID oidTarget)
{
    if (PushAndSignalCombatAttackOfOpportunityBefore(thisPtr->m_pBaseCreature->m_idSelf, oidTarget))
    {
        s_AddAttackOfOpportunityHook->CallOriginal<void>(thisPtr, oidTarget);
    }

    PushEventData("TARGET_OBJECT_ID",  Utils::ObjectIDToString(oidTarget));
    SignalEvent("NWNX_ON_COMBAT_ATTACK_OF_OPPORTUNITY_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
}

void SetBroadcastedAOOToHook(CNWSCreature *thisPtr, BOOL bValue)
{
    if (s_InBroadcastAttackOfOpportunity)
    {
        s_SkipPushAndSignalCombatAttackOfOpportunityBefore = false;
        if (!s_OnCombatAttackOfOpportunityResult)
        {
            return;
        }
    }

    s_SetBroadcastedAOOToHook->CallOriginal<void>(thisPtr, bValue);
}

void PlayBattleMusicHook(CNWSAmbientSound *pThis, BOOL bPlay)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("PLAY", std::to_string(bPlay));
        return SignalEvent(ev, pThis->m_nArea);
    };

    if ((pThis->m_bBattlePlaying && !bPlay) || (!pThis->m_bBattlePlaying && bPlay))
    {
        if (PushAndSignal("NWNX_ON_AREA_PLAY_BATTLE_MUSIC_BEFORE"))
        {
            s_PlayBattleMusicHook->CallOriginal<void>(pThis, bPlay);
        }

        PushAndSignal("NWNX_ON_AREA_PLAY_BATTLE_MUSIC_AFTER");
    }
    else
    {
        s_PlayBattleMusicHook->CallOriginal<void>(pThis, bPlay);
    }
}

static void AddActionHook(CNWSObject* pObject, uint32_t nActionId, uint16_t nGroupId, uint32_t nParamType1, void* pParameter1,
    uint32_t nParamType2, void* pParameter2, uint32_t nParamType3, void* pParameter3, uint32_t nParamType4, void* pParameter4,
    uint32_t nParamType5, void* pParameter5, uint32_t nParamType6, void* pParameter6, uint32_t nParamType7, void* pParameter7,
    uint32_t nParamType8, void* pParameter8, uint32_t nParamType9, void* pParameter9, uint32_t nParamType10, void* pParameter10,
    uint32_t nParamType11, void* pParameter11, uint32_t nParamType12, void* pParameter12)
{
    bool bOriginalCalled = false;
    if ((pObject->m_nObjectType == Constants::ObjectType::Creature) &&
        ((nActionId == 12 /* Attack */) || (nActionId == 1 /* MoveToPoint */) || (nActionId == 51 /* Drivemode */)))
    {
        auto* pCreature = Utils::AsNWSCreature(pObject);

        OBJECT_ID oidLastAttackTarget = Constants::OBJECT_INVALID;
        if (auto oidLastAttackTargetOpt = pCreature->nwnxGet<int32_t>("LAST_ATTACK_TARGET"))
            oidLastAttackTarget = oidLastAttackTargetOpt.value();

        OBJECT_ID oidNewTarget = (nActionId == 12) ? *(OBJECT_ID*)pParameter1 : Constants::OBJECT_INVALID;
        if (oidNewTarget != oidLastAttackTarget)
        {
            std::string sResult = "";
            auto PushAndSignal = [&](const std::string& event, OBJECT_ID oidNewTargetParam, bool retargetable, std::string* result = nullptr) -> void {
                PushEventData("OLD_TARGET_OBJECT_ID", Utils::ObjectIDToString(oidLastAttackTarget));
                PushEventData("NEW_TARGET_OBJECT_ID", Utils::ObjectIDToString(oidNewTargetParam));
                PushEventData("AUTOMATIC_CHANGE", std::to_string(false));
                PushEventData("RETARGETABLE", std::to_string(retargetable));
                SignalEvent(event, pCreature->m_idSelf, result);
            };

            PushAndSignal("NWNX_ON_ATTACK_TARGET_CHANGE_BEFORE", oidNewTarget, nActionId == 12, &sResult);
            if ((nActionId == 12) && (sResult != ""))
            {
                oidNewTarget = Utils::StringToObjectID(sResult);
                *(OBJECT_ID*)pParameter1 = oidNewTarget;
            }

            s_AddActionHook->CallOriginal<void>(pObject, nActionId, nGroupId, nParamType1, pParameter1,
                nParamType2, pParameter2, nParamType3, pParameter3, nParamType4, pParameter4,
                nParamType5, pParameter5, nParamType6, pParameter6, nParamType7, pParameter7,
                nParamType8, pParameter8, nParamType9, pParameter9, nParamType10, pParameter10,
                nParamType11, pParameter11, nParamType12, pParameter12);
            bOriginalCalled = true;

            PushAndSignal("NWNX_ON_ATTACK_TARGET_CHANGE_AFTER", oidNewTarget, false);

            pCreature->nwnxSet("LAST_ATTACK_TARGET", (int32_t)oidNewTarget);
        }
    }

    if (!bOriginalCalled)
    {
        s_AddActionHook->CallOriginal<void>(pObject, nActionId, nGroupId, nParamType1, pParameter1,
            nParamType2, pParameter2, nParamType3, pParameter3, nParamType4, pParameter4,
            nParamType5, pParameter5, nParamType6, pParameter6, nParamType7, pParameter7,
            nParamType8, pParameter8, nParamType9, pParameter9, nParamType10, pParameter10,
            nParamType11, pParameter11, nParamType12, pParameter12);
    }
}

static void ChangeAttackTargetHook(CNWSCreature* pCreature, CNWSObjectActionNode* pNode, const OBJECT_ID oidAttackTarget)
{
    OBJECT_ID oidLastAttackTarget = Constants::OBJECT_INVALID;
    if (auto oidLastAttackTargetOpt = pCreature->nwnxGet<int32_t>("LAST_ATTACK_TARGET"))
        oidLastAttackTarget = oidLastAttackTargetOpt.value();

    OBJECT_ID oidNewAttackTarget = oidAttackTarget;
    if (oidNewAttackTarget != oidLastAttackTarget)
    {
        std::string sResult = "";
        auto PushAndSignal = [&](const std::string& event, OBJECT_ID oidNewTargetParam, bool retargetable, std::string* result = nullptr) -> void {
            PushEventData("OLD_TARGET_OBJECT_ID", Utils::ObjectIDToString(oidLastAttackTarget));
            PushEventData("NEW_TARGET_OBJECT_ID", Utils::ObjectIDToString(oidNewTargetParam));
            PushEventData("AUTOMATIC_CHANGE", std::to_string(true));
            PushEventData("RETARGETABLE", std::to_string(retargetable));
            SignalEvent(event, pCreature->m_idSelf, result);
        };

        PushAndSignal("NWNX_ON_ATTACK_TARGET_CHANGE_BEFORE", oidNewAttackTarget, true, &sResult);
        if (sResult != "")
            oidNewAttackTarget = Utils::StringToObjectID(sResult);

        s_ChangeAttackTargetHook->CallOriginal<void>(pCreature, pNode, oidNewAttackTarget);

        PushAndSignal("NWNX_ON_ATTACK_TARGET_CHANGE_AFTER", oidNewAttackTarget, false);

        pCreature->nwnxSet("LAST_ATTACK_TARGET", (int32_t)oidNewAttackTarget);
    }
    else
    {
        s_ChangeAttackTargetHook->CallOriginal<void>(pCreature, pNode, oidNewAttackTarget);
    }
}

}
