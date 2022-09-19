#include "Events.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

using namespace NWNXLib;

static Hooks::Hook s_UseSkillHook;

static int32_t UseSkillHook(CNWSCreature*, uint8_t, uint8_t, ObjectID, Vector, ObjectID, ObjectID, int32_t);

void SkillEvents() __attribute__((constructor));
void SkillEvents()
{
    InitOnFirstSubscribe("NWNX_ON_USE_SKILL_.*", []() {
        s_UseSkillHook = Hooks::HookFunction(&CNWSCreature::UseSkill,
                                      &UseSkillHook, Hooks::Order::Early);
    });
}

int32_t UseSkillHook(CNWSCreature* thisPtr, uint8_t nSkill, uint8_t nSubSkill, ObjectID oidTarget, Vector vTargetPosition,
                                  ObjectID oidArea, ObjectID oidUsedItem, int32_t nActivePropertyIndex )
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("SKILL_ID", std::to_string(nSkill));
        PushEventData("SUB_SKILL_ID", std::to_string(nSubSkill));
        PushEventData("USED_ITEM_OBJECT_ID", Utils::ObjectIDToString(oidUsedItem ));
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));
    return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_SKILL_BEFORE"))
    {
        retVal = s_UseSkillHook->CallOriginal<int32_t>(thisPtr, nSkill, nSubSkill, oidTarget, vTargetPosition, oidArea, oidUsedItem, nActivePropertyIndex );
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_USE_SKILL_AFTER");

    return retVal;
}

}
