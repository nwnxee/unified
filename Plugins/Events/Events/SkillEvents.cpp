#include "Events/SkillEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

static Hooks::Hook s_UseSkillHook;

SkillEvents::SkillEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_SKILL_.*", []() {
        s_UseSkillHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature8UseSkillEhhj6Vectorjji,
                                      (void*)&UseSkillHook, Hooks::Order::Early);
    });
}

int32_t SkillEvents::UseSkillHook(CNWSCreature* thisPtr, uint8_t nSkill, uint8_t nSubSkill, ObjectID oidTarget, Vector vTargetPosition,
                                  ObjectID oidArea, ObjectID oidUsedItem, int32_t nActivePropertyIndex )
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("SKILL_ID", std::to_string(nSkill));
        Events::PushEventData("SUB_SKILL_ID", std::to_string(nSubSkill));
        Events::PushEventData("USED_ITEM_OBJECT_ID", Utils::ObjectIDToString(oidUsedItem ));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));
    return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_SKILL_BEFORE"))
    {
        retVal = s_UseSkillHook->CallOriginal<int32_t>(thisPtr, nSkill, nSubSkill, oidTarget, vTargetPosition, oidArea, oidUsedItem, nActivePropertyIndex );
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_USE_SKILL_AFTER");

    return retVal;
}

}
