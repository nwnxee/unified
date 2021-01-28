#include "Events/FeatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include "API/Vector.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooking::FunctionHook* s_UseFeatHook;
static Hooking::FunctionHook* s_HasFeatHook;

FeatEvents::FeatEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_FEAT_.*", [hooker]() {
        s_UseFeatHook = hooker->Hook(Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector, (void*)&UseFeatHook, Hooking::Order::Early);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_HAS_FEAT_.*", [hooker]() {
        s_HasFeatHook = hooker->Hook(Functions::_ZN17CNWSCreatureStats7HasFeatEt, (void*)&HasFeatHook, Hooking::Order::Early);
    });
    Events::ForceEnableWhitelist("NWNX_ON_HAS_FEAT");
}

int32_t FeatEvents::UseFeatHook(CNWSCreature* thisPtr, uint16_t nFeat, uint16_t nSubFeat, ObjectID oidTarget, ObjectID oidArea, Vector* pvTarget)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("FEAT_ID", std::to_string(nFeat));
        Events::PushEventData("SUBFEAT_ID", std::to_string(nSubFeat));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("AREA_OBJECT_ID", Utils::ObjectIDToString(oidArea));
        Events::PushEventData("TARGET_POSITION_X", pvTarget ? std::to_string(pvTarget->x) : "0.0");
        Events::PushEventData("TARGET_POSITION_Y", pvTarget ? std::to_string(pvTarget->y) : "0.0");
        Events::PushEventData("TARGET_POSITION_Z", pvTarget ? std::to_string(pvTarget->z) : "0.0");
    return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_FEAT_BEFORE"))
    {
        retVal = s_UseFeatHook->CallOriginal<int32_t>(thisPtr, nFeat, nSubFeat, oidTarget, oidArea, pvTarget);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_USE_FEAT_AFTER");

    return retVal;
}

int32_t FeatEvents::HasFeatHook(CNWSCreatureStats* thisPtr, uint16_t nFeat)
{
    int32_t retVal;
    std::string hasFeat;

    if (!Events::IsIDInWhitelist("NWNX_ON_HAS_FEAT", nFeat))
    {
        return s_HasFeatHook->CallOriginal<int32_t>(thisPtr, nFeat);
    }

    auto bHasFeat = s_HasFeatHook->CallOriginal<int32_t>(thisPtr, nFeat);
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("FEAT_ID", std::to_string(nFeat));
        Events::PushEventData("HAS_FEAT", std::to_string(bHasFeat));
        return Events::SignalEvent(ev, thisPtr->m_pBaseCreature->m_idSelf, &hasFeat);
    };

    if (PushAndSignal("NWNX_ON_HAS_FEAT_BEFORE"))
    {
        retVal = bHasFeat;
    }
    else
    {
        retVal = hasFeat == "1";
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_HAS_FEAT_AFTER");

    return retVal;
}

}
