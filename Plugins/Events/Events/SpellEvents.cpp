#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SpellCastAndImpactHook;
static Hooks::Hook s_SetMemorizedSpellSlotHook;
static Hooks::Hook s_ClearMemorizedSpellSlotHook;
static Hooks::Hook s_BroadcastSpellCastHook;
static Hooks::Hook s_OnEffectAppliedHook;

static void SpellCastAndImpactHook(CNWSObject*, uint32_t, Vector, ObjectID, uint8_t, ObjectID, int32_t, int32_t, uint8_t, int32_t);
static int32_t SetMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t, int32_t);
static void ClearMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint8_t);
static void BroadcastSpellCastHook(CNWSCreature*, uint32_t, uint8_t, uint16_t);
static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);

void SpellEvents() __attribute__((constructor));
void SpellEvents()
{
    InitOnFirstSubscribe("NWNX_ON_CAST_SPELL_.*", []() {
        s_SpellCastAndImpactHook = Hooks::HookFunction(Functions::_ZN10CNWSObject18SpellCastAndImpactEj6Vectorjhjiihi,
                                                (void*)&SpellCastAndImpactHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_SET_MEMORIZED_SPELL_SLOT_.*", []() {
        s_SetMemorizedSpellSlotHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats21SetMemorizedSpellSlotEhhjhhi,
                                                   (void*)&SetMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_CLEAR_MEMORIZED_SPELL_.*", []() {
        s_ClearMemorizedSpellSlotHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats23ClearMemorizedSpellSlotEhhh,
                                                     (void*)&ClearMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_BROADCAST_CAST_SPELL_.*", []() {
        s_BroadcastSpellCastHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature18BroadcastSpellCastEjht,
                                                (void*)&BroadcastSpellCastHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_SPELL_INTERRUPTED_.*", []() {
        s_OnEffectAppliedHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti,
                                             (void*)&OnEffectAppliedHook, Hooks::Order::Earliest);
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
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SPELL_ID", std::to_string(nSpellID));
        PushEventData("MULTI_CLASS", std::to_string(nMultiClass));
        PushEventData("FEAT", std::to_string(nFeat));
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

}
