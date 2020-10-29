#include "Events/SpellEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* s_SpellCastAndImpactHook;
static Hooking::FunctionHook* s_SetMemorizedSpellSlotHook;
static Hooking::FunctionHook* s_ClearMemorizedSpellSlotHook;
static Hooking::FunctionHook* s_BroadcastSpellCastHook;

SpellEvents::SpellEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_CAST_SPELL_.*", [hooker]() {
        s_SpellCastAndImpactHook = hooker->RequestExclusiveHook
             <NWNXLib::API::Functions::_ZN10CNWSObject18SpellCastAndImpactEj6Vectorjhjiihi>
             (&CastSpellHook);
    });

    Events::InitOnFirstSubscribe("NWNX_SET_MEMORIZED_SPELL_SLOT_.*", [hooker]() {
        s_SetMemorizedSpellSlotHook = hooker->RequestExclusiveHook
             <NWNXLib::API::Functions::_ZN17CNWSCreatureStats21SetMemorizedSpellSlotEhhjhhi>
             (&SetMemorizedSpellSlotHook);
    });

    Events::InitOnFirstSubscribe("NWNX_CLEAR_MEMORIZED_SPELL_.*", [hooker]() {
        s_ClearMemorizedSpellSlotHook = hooker->RequestExclusiveHook
             <NWNXLib::API::Functions::_ZN17CNWSCreatureStats23ClearMemorizedSpellSlotEhhh>
             (&ClearMemorizedSpellSlotHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_BROADCAST_CAST_SPELL_.*", [hooker]() {
        s_BroadcastSpellCastHook = hooker->RequestExclusiveHook
             <NWNXLib::API::Functions::_ZN12CNWSCreature18BroadcastSpellCastEjht>
             (&BroadcastSpellCastHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_SPELL_INTERRUPTED_.*", [hooker]() {
        hooker->RequestSharedHook<
                NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti, int32_t>
                (&EffectAppliedHook);
    });
}

void SpellEvents::CastSpellHook
(
    CNWSObject* thisPtr,
    uint32_t spellID,
    Vector targetPosition,
    ObjectID oidTarget,
    int8_t multiClass,
    ObjectID oidItem,
    bool spellCountered,
    bool counteringSpell,
    int8_t projectilePathType,
    bool isInstantSpell
)
{
    if (!Events::IsIDInWhitelist("NWNX_ON_CAST_SPELL", spellID))
    {
        s_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, spellID, targetPosition, oidTarget, multiClass, oidItem,
                                                     spellCountered, counteringSpell, projectilePathType, isInstantSpell);
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_ID", std::to_string(spellID));

        Events::PushEventData("TARGET_POSITION_X", std::to_string(targetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(targetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(targetPosition.z));

        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("MULTI_CLASS", std::to_string(multiClass));
        Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(oidItem));
        Events::PushEventData("SPELL_COUNTERED", std::to_string(spellCountered));
        Events::PushEventData("COUNTERING_SPELL", std::to_string(counteringSpell));
        Events::PushEventData("PROJECTILE_PATH_TYPE", std::to_string(projectilePathType));
        Events::PushEventData("IS_INSTANT_SPELL", std::to_string(isInstantSpell));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_CAST_SPELL_BEFORE"))
    {
        s_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, spellID, targetPosition, oidTarget, multiClass, oidItem,
                spellCountered, counteringSpell, projectilePathType, isInstantSpell);
    }
    else
    {
        thisPtr->m_bLastSpellCast = true;
    }

    PushAndSignal("NWNX_ON_CAST_SPELL_AFTER");
}

int32_t SpellEvents::SetMemorizedSpellSlotHook
(
    CNWSCreatureStats* thisPtr,
    uint8_t multiClass,
    uint8_t slot,
    uint32_t spellID,
    uint8_t domain,
    uint8_t meta,
    int32_t fromClient
)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    Events::PushEventData("SPELL_CLASS", std::to_string(multiClass));
    Events::PushEventData("SPELL_SLOT", std::to_string(slot));
    Events::PushEventData("SPELL_ID", std::to_string(spellID));
    Events::PushEventData("SPELL_DOMAIN", std::to_string(domain));
    Events::PushEventData("SPELL_METAMAGIC", std::to_string(meta));
    Events::PushEventData("SPELL_FROMCLIENT", std::to_string(fromClient));

    retVal = Events::SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_BEFORE", thisPtr->m_pBaseCreature->m_idSelf, &sBeforeEventResult)
             ? s_SetMemorizedSpellSlotHook->CallOriginal<int32_t>(thisPtr, multiClass, slot, spellID, domain, meta, fromClient) :
             sBeforeEventResult == "1";

    Events::PushEventData("SPELL_CLASS", std::to_string(multiClass));
    Events::PushEventData("SPELL_SLOT", std::to_string(slot));
    Events::PushEventData("SPELL_ID", std::to_string(spellID));
    Events::PushEventData("SPELL_DOMAIN", std::to_string(domain));
    Events::PushEventData("SPELL_METAMAGIC", std::to_string(meta));
    Events::PushEventData("SPELL_FROMCLIENT", std::to_string(fromClient));
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));

    Events::SignalEvent("NWNX_SET_MEMORIZED_SPELL_SLOT_AFTER", thisPtr->m_pBaseCreature->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

void SpellEvents::ClearMemorizedSpellSlotHook
(
    CNWSCreatureStats* thisPtr,
    uint8_t multiClass,
    uint8_t level,
    uint8_t slot
)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SPELL_CLASS", std::to_string(multiClass));
        Events::PushEventData("SPELL_LEVEL", std::to_string(level));
        Events::PushEventData("SPELL_SLOT", std::to_string(slot));
        return Events::SignalEvent(ev, thisPtr->m_pBaseCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_BEFORE"))
    {
        s_ClearMemorizedSpellSlotHook->CallOriginal<void>(thisPtr, multiClass, level, slot);
    }

    PushAndSignal("NWNX_CLEAR_MEMORIZED_SPELL_SLOT_AFTER");
}

void SpellEvents::BroadcastSpellCastHook(CNWSCreature* thisPtr, uint32_t nSpellID, uint8_t nMultiClass, uint16_t nFeat)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
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

void SpellEvents::EffectAppliedHook(bool before, CNWSEffectListHandler*, CNWSObject *pObject, CGameEffect *pGameEffect, int32_t)
{
    // An easy way to capture a spell interrupting is when the visual effect is applied
    // Visual Effect 292 and 293 are for a spell interruption failure (head and hand)
    if (pGameEffect->m_nType != Constants::EffectTrueType::VisualEffect || !pGameEffect->m_nNumIntegers ||
        (pGameEffect->m_nParamInteger[0] != 292 && pGameEffect->m_nParamInteger[0] != 293))
        return;

    Events::PushEventData("SPELL_ID", std::to_string(pObject->m_nLastSpellId));
    Events::PushEventData("SPELL_CLASS", std::to_string(pObject->m_nLastSpellCastMulticlass));
    Events::PushEventData("SPELL_FEAT", std::to_string(pObject->m_nLastSpellCastFeat));
    Events::PushEventData("SPELL_DOMAIN", std::to_string(pObject->m_nLastDomainLevel));
    Events::PushEventData("SPELL_SPONTANEOUS", std::to_string(pObject->m_bLastSpellCastSpontaneous));
    Events::PushEventData("SPELL_METAMAGIC", std::to_string(pObject->m_nLastSpellCastMetaType));
    Events::SignalEvent(before ? "NWNX_ON_SPELL_INTERRUPTED_BEFORE" : "NWNX_ON_SPELL_INTERRUPTED_AFTER" , pObject->m_idSelf);
}
}
