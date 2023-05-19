#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSEffectListHandler.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWCCMessageData.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

struct SpellCastAction
{
    uint32_t nSpellId;
    uint8_t nMultiClass;
    uint32_t nDomainLevel;
    uint32_t nMetaMagic;
    BOOL bSpontaneous;
    BOOL bDefensiveCast;
    OBJECT_ID oidTarget;
    float fTargetX;
    float fTargetY;
    float fTargetZ;
    BOOL bInstant;
    uint32_t nProjectilePathType;
    uint32_t nFeat;
    uint8_t nCasterLevel;
    BOOL bFake;
};

static SpellCastAction s_LastSpellAction;

static Hooks::Hook s_SpellCastAndImpactHook;
static Hooks::Hook s_SetMemorizedSpellSlotHook;
static Hooks::Hook s_ClearMemorizedSpellSlotHook;
static Hooks::Hook s_BroadcastSpellCastHook;
static Hooks::Hook s_OnEffectAppliedHook;
static Hooks::Hook s_DecrementSpellReadyCountHook;
static Hooks::Hook s_ClearActionHook;
static Hooks::Hook s_AIActionCastSpellHook;
static Hooks::Hook s_SendFeedbackMessageHook;
static Hooks::Hook s_BroadcastCounterSpellDataHook;

static void SpellCastAndImpactHook(CNWSObject*, uint32_t, Vector, ObjectID, uint8_t, ObjectID, int32_t, int32_t, uint8_t, int32_t);
static int32_t SetMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t, int32_t);
static void ClearMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint8_t);
static void BroadcastSpellCastHook(CNWSCreature*, uint32_t, uint8_t, uint16_t);
static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
static int32_t DecrementSpellReadyCountHook(CNWSCreature*, uint32_t, uint8_t, uint8_t, uint8_t, uint8_t);
static BOOL ClearActionHook(CNWSCreature*, CNWSObjectActionNode*, BOOL);
static uint32_t AIActionCastSpellHook(CNWSCreature*, CNWSObjectActionNode*);
static void SendFeedbackMessageHook(CNWSCreature*, uint16_t, CNWCCMessageData*, CNWSPlayer*);
static void BroadcastCounterSpellDataHook(CNWSObject*, CNWSpell*, CNWCCMessageData*);

void SpellEvents() __attribute__((constructor));
void SpellEvents()
{
    InitOnFirstSubscribe("NWNX_ON_CAST_SPELL_.*", []() {
        s_SpellCastAndImpactHook = Hooks::HookFunction(&CNWSObject::SpellCastAndImpact,
                                                &SpellCastAndImpactHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_SET_MEMORIZED_SPELL_SLOT_.*", []() {
        s_SetMemorizedSpellSlotHook = Hooks::HookFunction(&CNWSCreatureStats::SetMemorizedSpellSlot,
                                                   &SetMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_CLEAR_MEMORIZED_SPELL_.*", []() {
        s_ClearMemorizedSpellSlotHook = Hooks::HookFunction(&CNWSCreatureStats::ClearMemorizedSpellSlot,
                                                     &ClearMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_BROADCAST_CAST_SPELL_.*", []() {
        s_BroadcastSpellCastHook = Hooks::HookFunction(&CNWSCreature::BroadcastSpellCast,
                                                &BroadcastSpellCastHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_SPELL_INTERRUPTED_.*", []() {
        s_OnEffectAppliedHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti,
                                             &OnEffectAppliedHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_DECREMENT_SPELL_COUNT_.*", []() {
        s_DecrementSpellReadyCountHook = Hooks::HookFunction(&CNWSCreature::DecrementSpellReadyCount,
                                             &DecrementSpellReadyCountHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_SPELL_FAILED_.*", []() {
        s_AIActionCastSpellHook = Hooks::HookFunction(&CNWSCreature::AIActionCastSpell, &AIActionCastSpellHook, Hooks::Order::Earliest);
        s_ClearActionHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature11ClearActionEP20CNWSObjectActionNodei, &ClearActionHook, Hooks::Order::Early);
        s_SendFeedbackMessageHook = Hooks::HookFunction(&CNWSCreature::SendFeedbackMessage, &SendFeedbackMessageHook, Hooks::Order::Early);
        s_BroadcastCounterSpellDataHook = Hooks::HookFunction(&CNWSObject::BroadcastCounterSpellData, &BroadcastCounterSpellDataHook, Hooks::Order::Early);
    });
}

void SpellCastAndImpactHook(CNWSObject* thisPtr, uint32_t nSpellID, Vector vTargetPosition, ObjectID oidTarget,
                                         uint8_t nMultiClass, ObjectID oidItem, int32_t bSpellCountered, int32_t bCounteringSpell,
                                         uint8_t nProjectilePathType, int32_t bInstantSpell)
{
    if (!IsIDInWhitelist("NWNX_ON_CAST_SPELL", nSpellID))
    {
        s_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, nSpellID, vTargetPosition, oidTarget, nMultiClass, oidItem,
                                                     bSpellCountered, bCounteringSpell, nProjectilePathType, bInstantSpell);
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(nSpellID));

        PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));

        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        PushEventData("MULTI_CLASS", std::to_string(nMultiClass));
        PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(oidItem));
        PushEventData("SPELL_COUNTERED", std::to_string(bSpellCountered));
        PushEventData("COUNTERING_SPELL", std::to_string(bCounteringSpell));
        PushEventData("PROJECTILE_PATH_TYPE", std::to_string(nProjectilePathType));
        PushEventData("IS_INSTANT_SPELL", std::to_string(bInstantSpell));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_CAST_SPELL_BEFORE"))
    {
        s_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, nSpellID, vTargetPosition, oidTarget, nMultiClass, oidItem,
                                                     bSpellCountered, bCounteringSpell, nProjectilePathType, bInstantSpell);
    }
    else
    {
        thisPtr->m_bLastSpellCast = true;
    }

    PushAndSignal("NWNX_ON_CAST_SPELL_AFTER");
}

int32_t SetMemorizedSpellSlotHook(CNWSCreatureStats *thisPtr, uint8_t nMultiClass, uint8_t nSpellSlot,
                                               uint32_t nSpellID, uint8_t nDomainLevel, uint8_t nMetaType, BOOL bFromClient)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
    PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
    PushEventData("SPELL_ID", std::to_string(nSpellID));
    PushEventData("SPELL_DOMAIN", std::to_string(nDomainLevel));
    PushEventData("SPELL_METAMAGIC", std::to_string(nMetaType));
    PushEventData("SPELL_FROMCLIENT", std::to_string(bFromClient));

    retVal = SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE", thisPtr->m_pBaseCreature->m_idSelf, &sBeforeEventResult)
             ? s_SetMemorizedSpellSlotHook->CallOriginal<int32_t>(thisPtr, nMultiClass, nSpellSlot, nSpellID, nDomainLevel, nMetaType, bFromClient) :
             sBeforeEventResult == "1";

    PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
    PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
    PushEventData("SPELL_ID", std::to_string(nSpellID));
    PushEventData("SPELL_DOMAIN", std::to_string(nDomainLevel));
    PushEventData("SPELL_METAMAGIC", std::to_string(nMetaType));
    PushEventData("SPELL_FROMCLIENT", std::to_string(bFromClient));
    PushEventData("ACTION_RESULT", std::to_string(retVal));

    SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER", thisPtr->m_pBaseCreature->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

void ClearMemorizedSpellSlotHook(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
        PushEventData("SPELL_LEVEL", std::to_string(nSpellLevel));
        PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
        return SignalEvent(ev, thisPtr->m_pBaseCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE"))
    {
        s_ClearMemorizedSpellSlotHook->CallOriginal<void>(thisPtr, nMultiClass, nSpellLevel, nSpellSlot);
    }

    PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER");
}

void BroadcastSpellCastHook(CNWSCreature *thisPtr, uint32_t nSpellID, uint8_t nMultiClass, uint16_t nFeat)
{
    uint8_t nMetaType = Constants::MetaMagicType::Any;
    uint8_t nProjectilePathType;
    bool bSpontaneous;
    auto oidTarget = Constants::OBJECT_INVALID;
    uint32_t nDomainLevel;
    Vector vTargetPosition;
    
    if (auto *pActionNode = thisPtr->m_pExecutingAIAction)
    {
        if ((uint32_t)pActionNode->m_nActionId == 15 /*ACTION_ID_CAST_SPELL*/)
        {
            nDomainLevel = (uint32_t)pActionNode->m_pParameter[2];
            nMetaType = (uint8_t)(uint32_t)pActionNode->m_pParameter[3];
            bSpontaneous = (int32_t)pActionNode->m_pParameter[4];
            oidTarget = (uint32_t)pActionNode->m_pParameter[5];
            auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(oidTarget));
            vTargetPosition = pTarget ? pTarget->m_vPosition : Vector((*(float*)&pActionNode->m_pParameter[6]), (*(float*)&pActionNode->m_pParameter[7]), (*(float*)&pActionNode->m_pParameter[8]));
            nProjectilePathType = (uint8_t)((uint32_t)pActionNode->m_pParameter[9] & 0xFFu);
        }
    }

    if (oidTarget == Constants::OBJECT_INVALID)
        oidTarget = thisPtr->m_oidArea;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(nSpellID));
        PushEventData("MULTI_CLASS", std::to_string(nMultiClass));
        PushEventData("FEAT", std::to_string(nFeat));
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));
        PushEventData("SPELL_DOMAIN", std::to_string(nDomainLevel));
        PushEventData("SPELL_SPONTANEOUS", std::to_string(bSpontaneous));
        PushEventData("SPELL_METAMAGIC", std::to_string(nMetaType));
        PushEventData("PROJECTILE_PATH_TYPE", std::to_string(nProjectilePathType));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_BROADCAST_CAST_SPELL_BEFORE"))
    {
        s_BroadcastSpellCastHook->CallOriginal<void>(thisPtr, nSpellID, nMultiClass, nFeat);
    }

    PushAndSignal("NWNX_ON_BROADCAST_CAST_SPELL_AFTER");
}

int32_t OnEffectAppliedHook(CNWSEffectListHandler *pEffectListHandler, CNWSObject *pObject, CGameEffect *pEffect, int32_t bLoadingGame)
{
    // An easy way to capture a spell interrupting is when the visual effect is applied
    // Visual Effect 292 and 293 are for a spell interruption failure (head and hand)
    if (!pEffect || pEffect->m_nType != Constants::EffectTrueType::VisualEffect || !pEffect->m_nNumIntegers ||
        (pEffect->m_nParamInteger[0] != 292 && pEffect->m_nParamInteger[0] != 293))
        return s_OnEffectAppliedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect, bLoadingGame);

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(pObject->m_nLastSpellId));
        PushEventData("SPELL_CLASS", std::to_string(pObject->m_nLastSpellCastMulticlass));
        PushEventData("SPELL_FEAT", std::to_string(pObject->m_nLastSpellCastFeat));
        PushEventData("SPELL_DOMAIN", std::to_string(pObject->m_nLastDomainLevel));
        PushEventData("SPELL_SPONTANEOUS", std::to_string(pObject->m_bLastSpellCastSpontaneous));
        PushEventData("SPELL_METAMAGIC", std::to_string(pObject->m_nLastSpellCastMetaType));
        return SignalEvent(ev, pObject->m_idSelf);
    };

    PushAndSignal("NWNX_ON_SPELL_INTERRUPTED_BEFORE");
    auto retVal = s_OnEffectAppliedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect, bLoadingGame);
    PushAndSignal("NWNX_ON_SPELL_INTERRUPTED_AFTER");

    return retVal;
}

int32_t DecrementSpellReadyCountHook(CNWSCreature *thisPtr, uint32_t nSpellID, uint8_t nMultiClass, uint8_t nDomainLevel, uint8_t nMetaType, uint8_t nCasterLevel)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(nSpellID));
        PushEventData("CLASS", std::to_string(nMultiClass));
        PushEventData("DOMAIN", std::to_string(nDomainLevel));
        PushEventData("METAMAGIC", std::to_string(nMetaType));
        PushEventData("CASTERLEVEL", std::to_string(nCasterLevel));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    int32_t retVal;
    if (PushAndSignal("NWNX_ON_DECREMENT_SPELL_COUNT_BEFORE"))
    {
        retVal = s_DecrementSpellReadyCountHook->CallOriginal<int32_t>(thisPtr, nSpellID, nMultiClass, nDomainLevel, nMetaType, nCasterLevel);
    }
    else
    {
        retVal = true;
    }

    PushAndSignal("NWNX_ON_DECREMENT_SPELL_COUNT_AFTER");

    return retVal;
}

uint32_t AIActionCastSpellHook(CNWSCreature* thisPtr, CNWSObjectActionNode* pNode)
{
    s_LastSpellAction.nSpellId = pNode->m_pParameter[0];
    s_LastSpellAction.nMultiClass = pNode->m_pParameter[1] & 0xFF;
    s_LastSpellAction.nDomainLevel = pNode->m_pParameter[2];
    s_LastSpellAction.nMetaMagic = pNode->m_pParameter[3];
    s_LastSpellAction.bSpontaneous = pNode->m_pParameter[4] != 0;
    s_LastSpellAction.bDefensiveCast = (pNode->m_pParameter[1] & 0x0000FF00) >> 8;
    s_LastSpellAction.oidTarget = pNode->m_pParameter[5];
    s_LastSpellAction.fTargetX = *((float*)&pNode->m_pParameter[6]);
    s_LastSpellAction.fTargetY = *((float*)&pNode->m_pParameter[7]);
    s_LastSpellAction.fTargetZ = *((float*)&pNode->m_pParameter[8]);
    s_LastSpellAction.bInstant = (pNode->m_pParameter[9] & 0x40000000) != 0;
    s_LastSpellAction.nProjectilePathType = pNode->m_pParameter[9] & 0x3FFFFFFF;
    s_LastSpellAction.nFeat = pNode->m_pParameter[10];
    s_LastSpellAction.nCasterLevel = pNode->m_pParameter[11] & 0x000000FF;
    s_LastSpellAction.bFake = (pNode->m_pParameter[9] & 0x80000000) != 0;

    return s_AIActionCastSpellHook->CallOriginal<uint32_t>(thisPtr, pNode);
}

BOOL ClearActionHook(CNWSCreature* thisPtr, CNWSObjectActionNode* pNode, BOOL bIsTopmostAction)
{
    if ((IsIDInWhitelist("NWNX_ON_SPELL_FAILED", pNode->m_pParameter[0])) && 
        (bIsTopmostAction) && (pNode->m_nActionId == 15) && (pNode->m_nParameters == 12) && (pNode->m_bInterruptable))
    {
        auto PushAndSignal = [&](const std::string& ev) -> bool {
            PushEventData("SPELL_ID", std::to_string(pNode->m_pParameter[0]));
            PushEventData("MULTI_CLASS", std::to_string(pNode->m_pParameter[1] & 0xFF));
            PushEventData("DOMAIN", std::to_string(pNode->m_pParameter[2]));
            PushEventData("METAMAGIC", std::to_string(pNode->m_pParameter[3]));
            PushEventData("SPELL_SPONTANEOUS", std::to_string(pNode->m_pParameter[4]));
            PushEventData("DEFENSIVELY_CAST", std::to_string((pNode->m_pParameter[1] & 0x0000FF00) >> 8));
            PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(pNode->m_pParameter[5]));
            PushEventData("TARGET_POSITION_X", std::to_string(*((float*)&pNode->m_pParameter[6])));
            PushEventData("TARGET_POSITION_Y", std::to_string(*((float*)&pNode->m_pParameter[7])));
            PushEventData("TARGET_POSITION_Z", std::to_string(*((float*)&pNode->m_pParameter[8])));
            PushEventData("IS_INSTANT_SPELL", std::to_string((uint32_t)((pNode->m_pParameter[9] & 0x40000000) != 0)));
            PushEventData("PROJECTILE_PATH_TYPE", std::to_string(pNode->m_pParameter[9] & 0x3FFFFFFF));
            PushEventData("FEAT", std::to_string(pNode->m_pParameter[10]));
            PushEventData("CASTERLEVEL", std::to_string(pNode->m_pParameter[11] & 0x000000FF));
            PushEventData("IS_FAKE", std::to_string((uint32_t)((pNode->m_pParameter[9] & 0x80000000) != 0)));
            PushEventData("REASON", "0" /* NWNX_EVENTS_SPELLFAIL_REASON_CANCELED */);
            return SignalEvent(ev, thisPtr->m_idSelf);
        };

        PushAndSignal("NWNX_ON_SPELL_FAILED_BEFORE");

        auto retVal = s_ClearActionHook->CallOriginal<BOOL>(thisPtr, pNode, bIsTopmostAction);

        PushAndSignal("NWNX_ON_SPELL_FAILED_AFTER");

        return retVal;
    }
    
    return s_ClearActionHook->CallOriginal<BOOL>(thisPtr, pNode, bIsTopmostAction);
}

void BroadcastCounterSpellDataHook(CNWSObject* thisPtr, CNWSpell* pSpell, CNWCCMessageData* pMessageData)
{
    if (!IsIDInWhitelist("NWNX_ON_SPELL_FAILED", s_LastSpellAction.nSpellId))
    {
        s_BroadcastCounterSpellDataHook->CallOriginal<void>(thisPtr, pSpell, pMessageData);
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(s_LastSpellAction.nSpellId));
        PushEventData("MULTI_CLASS", std::to_string(s_LastSpellAction.nMultiClass));
        PushEventData("DOMAIN", std::to_string(s_LastSpellAction.nDomainLevel));
        PushEventData("METAMAGIC", std::to_string(s_LastSpellAction.nMetaMagic));
        PushEventData("SPELL_SPONTANEOUS", std::to_string((uint32_t)s_LastSpellAction.bSpontaneous));
        PushEventData("DEFENSIVELY_CAST", std::to_string((uint32_t)s_LastSpellAction.bDefensiveCast));
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(s_LastSpellAction.oidTarget));
        PushEventData("TARGET_POSITION_X", std::to_string(s_LastSpellAction.fTargetX));
        PushEventData("TARGET_POSITION_Y", std::to_string(s_LastSpellAction.fTargetY));
        PushEventData("TARGET_POSITION_Z", std::to_string(s_LastSpellAction.fTargetZ));
        PushEventData("IS_INSTANT_SPELL", std::to_string((uint32_t)s_LastSpellAction.bInstant));
        PushEventData("PROJECTILE_PATH_TYPE", std::to_string(s_LastSpellAction.nProjectilePathType));
        PushEventData("FEAT", std::to_string(s_LastSpellAction.nFeat));
        PushEventData("CASTERLEVEL", std::to_string(s_LastSpellAction.nCasterLevel));
        PushEventData("IS_FAKE", std::to_string((uint32_t)s_LastSpellAction.bFake));
        PushEventData("REASON", "1" /* NWNX_EVENTS_SPELLFAIL_REASON_COUNTERSPELL */);
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    PushAndSignal("NWNX_ON_SPELL_FAILED_BEFORE");

    s_BroadcastCounterSpellDataHook->CallOriginal<void>(thisPtr, pSpell, pMessageData);

    PushAndSignal("NWNX_ON_SPELL_FAILED_AFTER");  
}

void SendFeedbackMessageHook(CNWSCreature* thisPtr, uint16_t nFeedbackID, CNWCCMessageData* pMessageData, CNWSPlayer* pFeedbackPlayer)
{
    if ((IsIDInWhitelist("NWNX_ON_SPELL_FAILED", s_LastSpellAction.nSpellId)) &&
        (
            (nFeedbackID == 61 /* NWNX_FEEDBACK_CAST_ARCANE_SPELL_FAILURE */) || 
            (nFeedbackID == 236 /* NWNX_FEEDBACK_CAST_EFFECT_SPELL_FAILURE */) || 
            (nFeedbackID == 21 /* NWNX_FEEDBACK_CAST_LOST_TARGET */) || 
            (nFeedbackID == 211 /* NWNX_FEEDBACK_CAST_USE_MOUTH */) || 
            (nFeedbackID == 233 /* NWNX_FEEDBACK_CAST_DEFCAST_CONCENTRATION_FAILURE */) ||
            (nFeedbackID == 65 /* NWNX_FEEDBACK_CAST_ENTANGLE_CONCENTRATION_FAILURE */) ||
            // Untested:
            (nFeedbackID == 107 /* NWNX_FEEDBACK_CAST_CANT_CAST_WHILE_POLYMORPHED */) ||
            (nFeedbackID == 22 /* NWNX_FEEDBACK_CAST_CANT_CAST */) || 
            (nFeedbackID == 210 /* NWNX_FEEDBACK_CAST_USE_HANDS */)
        ))
    {
        int32_t nFailReason = -1;
        switch (nFeedbackID)
        {
            case 61 /* NWNX_FEEDBACK_CAST_ARCANE_SPELL_FAILURE */:           nFailReason = 2; break; /* NWNX_EVENTS_SPELLFAIL_REASON_ASF */
            case 236 /* NWNX_FEEDBACK_CAST_ARCANE_SPELL_FAILURE */:          nFailReason = 3; break; /* NWNX_EVENTS_SPELLFAIL_REASON_SPELLFAILURE */
            case 21 /* NWNX_FEEDBACK_CAST_LOST_TARGET */:                    nFailReason = 4; break; /* NWNX_EVENTS_SPELLFAIL_REASON_LOST_TARGET */
            case 211 /* NWNX_FEEDBACK_CAST_USE_MOUTH */:                     nFailReason = 5; break; /* NWNX_EVENTS_SPELLFAIL_REASON_SILENCED */
            case 233 /* NWNX_FEEDBACK_CAST_DEFCAST_CONCENTRATION_FAILURE */: nFailReason = 6; break; /* NWNX_EVENTS_SPELLFAIL_REASON_DEFCAST_CONCENTRATION */
            case 65 /* NWNX_FEEDBACK_CAST_ENTANGLE_CONCENTRATION_FAILURE */: nFailReason = 7; break; /* NWNX_EVENTS_SPELLFAIL_REASON_ENTANGLE_CONCENTRATION */
            case 107 /* NWNX_FEEDBACK_CAST_CANT_CAST_WHILE_POLYMORPHED */:   nFailReason = 8; break; /* NWNX_EVENTS_SPELLFAIL_REASON_POLYMORPHED */
            case 22 /* NWNX_FEEDBACK_CAST_CANT_CAST */:                      nFailReason = 9; break; /* NWNX_EVENTS_SPELLFAIL_REASON_CANT_CAST */
            case 210 /* NWNX_FEEDBACK_CAST_USE_HANDS */:                     nFailReason = 10; break; /* NWNX_EVENTS_SPELLFAIL_REASON_CANT_USE_HANDS */
        }

        auto PushAndSignal = [&](const std::string& ev) -> bool {
            PushEventData("SPELL_ID", std::to_string(s_LastSpellAction.nSpellId));
            PushEventData("MULTI_CLASS", std::to_string(s_LastSpellAction.nMultiClass));
            PushEventData("DOMAIN", std::to_string(s_LastSpellAction.nDomainLevel));
            PushEventData("METAMAGIC", std::to_string(s_LastSpellAction.nMetaMagic));
            PushEventData("SPELL_SPONTANEOUS", std::to_string((uint32_t)s_LastSpellAction.bSpontaneous));
            PushEventData("DEFENSIVELY_CAST", std::to_string((uint32_t)s_LastSpellAction.bDefensiveCast));
            PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(s_LastSpellAction.oidTarget));
            PushEventData("TARGET_POSITION_X", std::to_string(s_LastSpellAction.fTargetX));
            PushEventData("TARGET_POSITION_Y", std::to_string(s_LastSpellAction.fTargetY));
            PushEventData("TARGET_POSITION_Z", std::to_string(s_LastSpellAction.fTargetZ));
            PushEventData("IS_INSTANT_SPELL", std::to_string((uint32_t)s_LastSpellAction.bInstant));
            PushEventData("PROJECTILE_PATH_TYPE", std::to_string(s_LastSpellAction.nProjectilePathType));
            PushEventData("FEAT", std::to_string(s_LastSpellAction.nFeat));
            PushEventData("CASTERLEVEL", std::to_string(s_LastSpellAction.nCasterLevel));
            PushEventData("IS_FAKE", std::to_string((uint32_t)s_LastSpellAction.bFake));
            PushEventData("REASON", std::to_string(nFailReason));
            return SignalEvent(ev, thisPtr->m_idSelf);
        };

        PushAndSignal("NWNX_ON_SPELL_FAILED_BEFORE");

        s_SendFeedbackMessageHook->CallOriginal<void>(thisPtr, nFeedbackID, pMessageData, pFeedbackPlayer);

        PushAndSignal("NWNX_ON_SPELL_FAILED_AFTER");
    }
    else
        s_SendFeedbackMessageHook->CallOriginal<void>(thisPtr, nFeedbackID, pMessageData, pFeedbackPlayer);
}

}
