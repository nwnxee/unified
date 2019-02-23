#include "Events/SpellEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* m_SpellCastAndImpactHook = nullptr;

SpellEvents::SpellEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_CAST_SPELL_.*", [hooker]() {
        hooker->RequestExclusiveHook<NWNXLib::API::Functions::CNWSObject__SpellCastAndImpact>(&CastSpellHook);
        m_SpellCastAndImpactHook = hooker->FindHookByAddress(NWNXLib::API::Functions::CNWSObject__SpellCastAndImpact);
    });
}

void SpellEvents::CastSpellHook
(
    NWNXLib::API::CNWSObject* thisPtr,
    uint32_t spellID,
    NWNXLib::API::Vector targetPosition,
    NWNXLib::API::Types::ObjectID oidTarget,
    int8_t multiClass,
    NWNXLib::API::Types::ObjectID oidItem,
    bool spellCountered,
    bool counteringSpell,
    int8_t projectilePathType,
    bool isInstantSpell
)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
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
        m_SpellCastAndImpactHook->CallOriginal<void>(thisPtr, spellID, targetPosition, oidTarget, multiClass, oidItem,
                spellCountered, counteringSpell, projectilePathType, isInstantSpell);
    }
    else
    {
        thisPtr->m_bLastSpellCast = true;
    }

    PushAndSignal("NWNX_ON_CAST_SPELL_AFTER");
}

}
