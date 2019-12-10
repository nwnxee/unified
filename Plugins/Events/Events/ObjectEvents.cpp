#include "Events/ObjectEvents.hpp"
#include "API/CNWSObject.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* m_AddLockObjectActionHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_AddUnlockObjectActionHook = nullptr;

ObjectEvents::ObjectEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_OBJECT_LOCK_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSObject19AddLockObjectActionEj>(&AddLockObjectActionHook);
        m_AddLockObjectActionHook = hooker->FindHookByAddress(API::Functions::_ZN10CNWSObject19AddLockObjectActionEj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_OBJECT_UNLOCK_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSObject21AddUnlockObjectActionEjji>(&AddUnlockObjectActionHook);
        m_AddUnlockObjectActionHook = hooker->FindHookByAddress(API::Functions::_ZN10CNWSObject21AddUnlockObjectActionEjji);
    });

}

int32_t ObjectEvents::AddLockObjectActionHook(CNWSObject *thisPtr, Types::ObjectID oidDoor)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));

        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_LOCK_BEFORE"))
    {
        retVal = m_AddLockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_OBJECT_LOCK_AFTER");

    return retVal;
}

int32_t ObjectEvents::AddUnlockObjectActionHook(CNWSObject *thisPtr, Types::ObjectID oidDoor, Types::ObjectID oidThievesTool, int32_t nActivePropertyIndex)
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
        retVal = m_AddUnlockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor, oidThievesTool, nActivePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_OBJECT_UNLOCK_AFTER");

    return retVal;
}

}
