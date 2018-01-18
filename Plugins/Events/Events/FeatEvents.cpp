#include "Events/FeatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Helpers.hpp"
#include "Services/Log/Log.hpp"
#include "ViewPtr.hpp"
#include "API/Vector.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;


FeatEvents::FeatEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<
        NWNXLib::API::Functions::CNWSCreature__UseFeat, 
        int32_t, 
        NWNXLib::API::CNWSCreature*, 
        uint16_t, 
        uint16_t, 
        NWNXLib::API::Types::ObjectID, 
        NWNXLib::API::Types::ObjectID, 
        NWNXLib::API::Vector*>(FeatEvents::UseFeatHook);
}

void FeatEvents::UseFeatHook
(
    Services::Hooks::CallType type, 
    NWNXLib::API::CNWSCreature* thisPtr, 
    uint16_t featID, 
    uint16_t subFeatID, 
    NWNXLib::API::Types::ObjectID oidTarget, 
    NWNXLib::API::Types::ObjectID oidArea, 
    NWNXLib::API::Vector* pvTarget
)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    Events::PushEventData("FEAT_ID", std::to_string(featID));
    Events::PushEventData("SUBFEAT_ID", std::to_string(subFeatID));
    
    Events::PushEventData("TARGET_OBJECT_ID", Helpers::ObjectIDToString(oidTarget));
    Events::PushEventData("AREA_OBJECT_ID", Helpers::ObjectIDToString(oidArea));

    Events::PushEventData("TARGET_POSITION_X", std::to_string(pvTarget->x));
    Events::PushEventData("TARGET_POSITION_Y", std::to_string(pvTarget->y));
    Events::PushEventData("TARGET_POSITION_Z", std::to_string(pvTarget->z));

    Events::SignalEvent(before ? "NWNX_ON_USE_FEAT_BEFORE" : "NWNX_ON_USE_FEAT_AFTER", thisPtr->m_idSelf);
}

}
