#include "Events/SpellEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

SpellEvents::SpellEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<
        NWNXLib::API::Functions::CNWSObject__SpellCastAndImpact, 
        int32_t, 
        NWNXLib::API::CNWSObject*, 
        uint32_t,
        NWNXLib::API::Vector,
        uint32_t,
        int8_t,
        uint32_t,
        bool,
        bool,
        int8_t,
        bool>(SpellEvents::CastSpellHook);
}

void SpellEvents::CastSpellHook
(
    Services::Hooks::CallType type, 
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
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
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

    Events::SignalEvent(before ? "NWNX_ON_CAST_SPELL_BEFORE" : "NWNX_ON_CAST_SPELL_AFTER", thisPtr->m_idSelf);
}

}
