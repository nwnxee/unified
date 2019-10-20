#include "Events/FeatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include "ViewPtr.hpp"
#include "API/Vector.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooking::FunctionHook* m_UseFeatHook = nullptr;

FeatEvents::FeatEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_FEAT_.*", [hooker]() {
        hooker->RequestExclusiveHook<
            NWNXLib::API::Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector,
            int32_t,
            NWNXLib::API::CNWSCreature*,
            uint16_t,
            uint16_t,
            NWNXLib::API::Types::ObjectID,
            NWNXLib::API::Types::ObjectID,
            NWNXLib::API::Vector*>(FeatEvents::UseFeatHook);

        m_UseFeatHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector);
    });
}

int32_t FeatEvents::UseFeatHook(
    NWNXLib::API::CNWSCreature* thisPtr,
    uint16_t featID,
    uint16_t subFeatID,
    NWNXLib::API::Types::ObjectID oidTarget,
    NWNXLib::API::Types::ObjectID oidArea,
    NWNXLib::API::Vector* pvTarget)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("FEAT_ID", std::to_string(featID));
        Events::PushEventData("SUBFEAT_ID", std::to_string(subFeatID));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("AREA_OBJECT_ID", Utils::ObjectIDToString(oidArea));
        Events::PushEventData("TARGET_POSITION_X", pvTarget ? std::to_string(pvTarget->x) : "0.0");
        Events::PushEventData("TARGET_POSITION_Y", pvTarget ? std::to_string(pvTarget->y) : "0.0");
        Events::PushEventData("TARGET_POSITION_Z", pvTarget ? std::to_string(pvTarget->z) : "0.0");
    return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_FEAT_BEFORE"))
    {
        retVal = m_UseFeatHook->CallOriginal<int32_t>(thisPtr, featID, subFeatID, oidTarget, oidArea, pvTarget);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_USE_FEAT_AFTER");

    return retVal;
}

}
