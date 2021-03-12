#include "Events/ObjectEvents.hpp"
#include "API/CNWSObject.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_AddLockObjectActionHook;
static NWNXLib::Hooks::Hook s_AddUnlockObjectActionHook;

ObjectEvents::ObjectEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_OBJECT_LOCK_.*", []() {
        s_AddLockObjectActionHook = Hooks::HookFunction(API::Functions::_ZN10CNWSObject19AddLockObjectActionEj,
                                                 (void*)&AddLockObjectActionHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_OBJECT_UNLOCK_.*", []() {
        s_AddUnlockObjectActionHook = Hooks::HookFunction(API::Functions::_ZN10CNWSObject21AddUnlockObjectActionEjji,
                                                   (void*)&AddUnlockObjectActionHook, Hooks::Order::Early);
    });
}

int32_t ObjectEvents::AddLockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));

        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_LOCK_BEFORE"))
    {
        retVal = s_AddLockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_LOCK_AFTER");

    return retVal;
}

int32_t ObjectEvents::AddUnlockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor, ObjectID oidThievesTool, int32_t nActivePropertyIndex)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));
        Events::PushEventData("THIEVES_TOOL", Utils::ObjectIDToString(oidThievesTool));
        Events::PushEventData("ACTIVE_PROPERTY_INDEX", std::to_string(nActivePropertyIndex));

        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_UNLOCK_BEFORE"))
    {
        retVal = s_AddUnlockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor, oidThievesTool, nActivePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_UNLOCK_AFTER");

    return retVal;
}

}
