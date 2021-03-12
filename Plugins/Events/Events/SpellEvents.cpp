#include "Events/SpellEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SpellCastAndImpactHook;
static Hooks::Hook s_SetMemorizedSpellSlotHook;
static Hooks::Hook s_ClearMemorizedSpellSlotHook;
static Hooks::Hook s_BroadcastSpellCastHook;
static Hooks::Hook s_OnEffectAppliedHook;

SpellEvents::SpellEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_CAST_SPELL_.*", []() {
        s_SpellCastAndImpactHook = Hooks::HookFunction(Functions::_ZN10CNWSObject18SpellCastAndImpactEj6Vectorjhjiihi,
                                                (void*)&SpellCastAndImpactHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_SET_MEMORIZED_SPELL_SLOT_.*", []() {
        s_SetMemorizedSpellSlotHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats21SetMemorizedSpellSlotEhhjhhi,
                                                   (void*)&SetMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_CLEAR_MEMORIZED_SPELL_.*", []() {
        s_ClearMemorizedSpellSlotHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats23ClearMemorizedSpellSlotEhhh,
                                                     (void*)&ClearMemorizedSpellSlotHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_BROADCAST_CAST_SPELL_.*", []() {
        s_BroadcastSpellCastHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature18BroadcastSpellCastEjht,
                                                (void*)&BroadcastSpellCastHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_SPELL_INTERRUPTED_.*", []() {
        s_OnEffectAppliedHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti,
                                             (void*)&OnEffectAppliedHook, Hooks::Order::Earliest);
    });
}

void SpellEvents::SpellCastAndImpactHook(CNWSObject* thisPtr, uint32_t nSpellID, Vector vTargetPosition, ObjectID oidTarget,
                                         uint8_t nMultiClass, ObjectID oidItem, int32_t bSpellCountered, int32_t bCounteringSpell,
                                         uint8_t nProjectilePathType, int32_t bInstantSpell)
{
    if (!Events::IsIDInWhitelist("NWNX_ON_CAST_SPELL", nSpellID))
    {
        s_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, nSpellID, vTargetPosition, oidTarget, nMultiClass, oidItem,
                                                     bSpellCountered, bCounteringSpell, nProjectilePathType, bInstantSpell);
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_ID", std::to_string(nSpellID));

        Events::PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));

        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("MULTI_CLASS", std::to_string(nMultiClass));
        Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(oidItem));
        Events::PushEventData("SPELL_COUNTERED", std::to_string(bSpellCountered));
        Events::PushEventData("COUNTERING_SPELL", std::to_string(bCounteringSpell));
        Events::PushEventData("PROJECTILE_PATH_TYPE", std::to_string(nProjectilePathType));
        Events::PushEventData("IS_INSTANT_SPELL", std::to_string(bInstantSpell));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
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

int32_t SpellEvents::SetMemorizedSpellSlotHook(CNWSCreatureStats *thisPtr, uint8_t nMultiClass, uint8_t nSpellSlot,
                                               uint32_t nSpellID, uint8_t nDomainLevel, uint8_t nMetaType, BOOL bFromClient)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    Events::PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
    Events::PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
    Events::PushEventData("SPELL_ID", std::to_string(nSpellID));
    Events::PushEventData("SPELL_DOMAIN", std::to_string(nDomainLevel));
    Events::PushEventData("SPELL_METAMAGIC", std::to_string(nMetaType));
    Events::PushEventData("SPELL_FROMCLIENT", std::to_string(bFromClient));

    retVal = Events::SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE", thisPtr->m_pBaseCreature->m_idSelf, &sBeforeEventResult)
             ? s_SetMemorizedSpellSlotHook->CallOriginal<int32_t>(thisPtr, nMultiClass, nSpellSlot, nSpellID, nDomainLevel, nMetaType, bFromClient) :
             sBeforeEventResult == "1";

    Events::PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
    Events::PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
    Events::PushEventData("SPELL_ID", std::to_string(nSpellID));
    Events::PushEventData("SPELL_DOMAIN", std::to_string(nDomainLevel));
    Events::PushEventData("SPELL_METAMAGIC", std::to_string(nMetaType));
    Events::PushEventData("SPELL_FROMCLIENT", std::to_string(bFromClient));
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));

    Events::SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER", thisPtr->m_pBaseCreature->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

void SpellEvents::ClearMemorizedSpellSlotHook(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_CLASS", std::to_string(nMultiClass));
        Events::PushEventData("SPELL_LEVEL", std::to_string(nSpellLevel));
        Events::PushEventData("SPELL_SLOT", std::to_string(nSpellSlot));
        return Events::SignalEvent(ev, thisPtr->m_pBaseCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE"))
    {
        s_ClearMemorizedSpellSlotHook->CallOriginal<void>(thisPtr, nMultiClass, nSpellLevel, nSpellSlot);
    }

    PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER");
}

void SpellEvents::BroadcastSpellCastHook(CNWSCreature *thisPtr, uint32_t nSpellID, uint8_t nMultiClass, uint16_t nFeat)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_ID", std::to_string(nSpellID));
        Events::PushEventData("MULTI_CLASS", std::to_string(nMultiClass));
        Events::PushEventData("FEAT", std::to_string(nFeat));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_BROADCAST_CAST_SPELL_BEFORE"))
    {
        s_BroadcastSpellCastHook->CallOriginal<void>(thisPtr, nSpellID, nMultiClass, nFeat);
    }

    PushAndSignal("NWNX_ON_BROADCAST_CAST_SPELL_AFTER");
}

int32_t SpellEvents::OnEffectAppliedHook(CNWSEffectListHandler *pEffectListHandler, CNWSObject *pObject, CGameEffect *pEffect, int32_t bLoadingGame)
{
    // An easy way to capture a spell interrupting is when the visual effect is applied
    // Visual Effect 292 and 293 are for a spell interruption failure (head and hand)
    if (!pEffect || pEffect->m_nType != Constants::EffectTrueType::VisualEffect || !pEffect->m_nNumIntegers ||
        (pEffect->m_nParamInteger[0] != 292 && pEffect->m_nParamInteger[0] != 293))
        return s_OnEffectAppliedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect, bLoadingGame);

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_ID", std::to_string(pObject->m_nLastSpellId));
        Events::PushEventData("SPELL_CLASS", std::to_string(pObject->m_nLastSpellCastMulticlass));
        Events::PushEventData("SPELL_FEAT", std::to_string(pObject->m_nLastSpellCastFeat));
        Events::PushEventData("SPELL_DOMAIN", std::to_string(pObject->m_nLastDomainLevel));
        Events::PushEventData("SPELL_SPONTANEOUS", std::to_string(pObject->m_bLastSpellCastSpontaneous));
        Events::PushEventData("SPELL_METAMAGIC", std::to_string(pObject->m_nLastSpellCastMetaType));
        return Events::SignalEvent(ev, pObject->m_idSelf);
    };

    PushAndSignal("NWNX_ON_SPELL_INTERRUPTED_BEFORE");
    auto retVal = s_OnEffectAppliedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect, bLoadingGame);
    PushAndSignal("NWNX_ON_SPELL_INTERRUPTED_AFTER");

    return retVal;
}

}
