#include "Events.hpp"
#include "API/CNWSObject.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_AddLockObjectActionHook;
static NWNXLib::Hooks::Hook s_AddUnlockObjectActionHook;
static NWNXLib::Hooks::Hook s_AddUseObjectActionHook;

static int32_t AddLockObjectActionHook(CNWSObject*, ObjectID);
static int32_t AddUnlockObjectActionHook(CNWSObject*, ObjectID, ObjectID, int32_t);
static int32_t AddUseObjectActionHook(CNWSObject*, ObjectID);

void ObjectEvents() __attribute__((constructor));
void ObjectEvents()
{
    InitOnFirstSubscribe("NWNX_ON_OBJECT_LOCK_.*", []() {
        s_AddLockObjectActionHook = Hooks::HookFunction(&CNWSObject::AddLockObjectAction,
                                                 &AddLockObjectActionHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_OBJECT_UNLOCK_.*", []() {
        s_AddUnlockObjectActionHook = Hooks::HookFunction(&CNWSObject::AddUnlockObjectAction,
                                                   &AddUnlockObjectActionHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_OBJECT_USE_.*", []() {
        s_AddUseObjectActionHook = Hooks::HookFunction(&CNWSObject::AddUseObjectAction,
                                                   (void*)&AddUseObjectActionHook, Hooks::Order::Early);
    });
}

int32_t AddLockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));

        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_LOCK_BEFORE"))
    {
        retVal = s_AddLockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_LOCK_AFTER");

    return retVal;
}

int32_t AddUnlockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor, ObjectID oidThievesTool, int32_t nActivePropertyIndex)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));
        PushEventData("THIEVES_TOOL", Utils::ObjectIDToString(oidThievesTool));
        PushEventData("ACTIVE_PROPERTY_INDEX", std::to_string(nActivePropertyIndex));

        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_UNLOCK_BEFORE"))
    {
        retVal = s_AddUnlockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor, oidThievesTool, nActivePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_UNLOCK_AFTER");

    return retVal;
}

int32_t AddUseObjectActionHook(CNWSObject *thisPtr, ObjectID oidObjectToUse)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("OBJECT", Utils::ObjectIDToString(oidObjectToUse));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_USE_BEFORE"))
    {
        retVal = s_AddUseObjectActionHook->CallOriginal<int32_t>(thisPtr, oidObjectToUse);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_USE_AFTER");

    return retVal;
}

}
