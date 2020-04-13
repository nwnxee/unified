#include "Events/SkillEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* s_UseSkillHook;

SkillEvents::SkillEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_SKILL_.*", [hooker]() {
        s_UseSkillHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature8UseSkillEhhj6Vectorjji, int32_t, CNWSCreature*, uint8_t, uint8_t,
            ObjectID, Vector, ObjectID, ObjectID, int32_t>
            (&UseSkillHook);
    });
}

int32_t SkillEvents::UseSkillHook(
    CNWSCreature* thisPtr,
    uint8_t skill,
    uint8_t subSkill,
    ObjectID target,
    Vector targetPosition,
    ObjectID area,
    ObjectID usedItem,
    int32_t activePropertyIndex)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
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
        retVal = s_UseSkillHook->CallOriginal<int32_t>(thisPtr, skill, subSkill, target, targetPosition, area, usedItem, activePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_USE_SKILL_AFTER");

    return retVal;
}

}
