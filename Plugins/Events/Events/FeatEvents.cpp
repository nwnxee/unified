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
    hooker->RequestExclusiveHook<
        NWNXLib::API::Functions::CNWSCreature__UseFeat,
        int32_t,
        NWNXLib::API::CNWSCreature*,
        uint16_t,
        uint16_t,
        NWNXLib::API::Types::ObjectID,
        NWNXLib::API::Types::ObjectID,
        NWNXLib::API::Vector*>(FeatEvents::UseFeatHook);

    m_UseFeatHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__UseFeat);
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

    Events::PushEventData("FEAT_ID", std::to_string(featID));
    Events::PushEventData("SUBFEAT_ID", std::to_string(subFeatID));

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::PushEventData("AREA_OBJECT_ID", Utils::ObjectIDToString(oidArea));

    Events::PushEventData("TARGET_POSITION_X", pvTarget ? std::to_string(pvTarget->x) : "0.0");
    Events::PushEventData("TARGET_POSITION_Y", pvTarget ? std::to_string(pvTarget->y) : "0.0");
    Events::PushEventData("TARGET_POSITION_Z", pvTarget ? std::to_string(pvTarget->z) : "0.0");

    if (Events::SignalEvent("NWNX_ON_USE_FEAT_BEFORE", thisPtr->m_idSelf))
    {
        retVal = m_UseFeatHook->CallOriginal<int32_t>(thisPtr, featID, subFeatID, oidTarget, oidArea, pvTarget);
    }
    else
    {
        retVal = false;    
    }

    Events::PushEventData("FEAT_ID", std::to_string(featID));
    Events::PushEventData("SUBFEAT_ID", std::to_string(subFeatID));

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::PushEventData("AREA_OBJECT_ID", Utils::ObjectIDToString(oidArea));

    Events::PushEventData("TARGET_POSITION_X", pvTarget ? std::to_string(pvTarget->x) : "0.0");
    Events::PushEventData("TARGET_POSITION_Y", pvTarget ? std::to_string(pvTarget->y) : "0.0");
    Events::PushEventData("TARGET_POSITION_Z", pvTarget ? std::to_string(pvTarget->z) : "0.0");

    Events::SignalEvent("NWNX_ON_USE_FEAT_AFTER", thisPtr->m_idSelf);   

    return retVal;
}

}
