#include "Events/SkillEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* m_UseSkillHook = nullptr;

SkillEvents::SkillEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_SKILL_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__UseSkill, int32_t, API::CNWSCreature*, uint8_t, uint8_t, NWNXLib::API::Types::ObjectID,
            NWNXLib::API::Vector, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t>(&UseSkillHook);

        m_UseSkillHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__UseSkill);
    });
}

int32_t SkillEvents::UseSkillHook(
    API::CNWSCreature* thisPtr,
    uint8_t skill,
    uint8_t subSkill,
    API::Types::ObjectID target,
    NWNXLib::API::Vector targetPosition,
    API::Types::ObjectID area,
    API::Types::ObjectID usedItem,
    int32_t activePropertyIndex)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("SKILL_ID", std::to_string(skill));
        Events::PushEventData("SUB_SKILL_ID", std::to_string(subSkill));
        Events::PushEventData("USED_ITEM_OBJECT_ID", Utils::ObjectIDToString(usedItem));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
        Events::PushEventData("TARGET_POSITION_X", std::to_string(targetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(targetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(targetPosition.z));
    return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_SKILL_BEFORE"))
    {
        retVal = m_UseSkillHook->CallOriginal<int32_t>(thisPtr, skill, subSkill, target, targetPosition, area, usedItem, activePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_USE_SKILL_AFTER");

    return retVal;
}

}
