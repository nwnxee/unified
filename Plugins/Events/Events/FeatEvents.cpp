#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_UseFeatHook;
static Hooks::Hook s_HasFeatHook;

static int32_t UseFeatHook(CNWSCreature*, uint16_t, uint16_t, ObjectID, ObjectID, Vector*);
static int32_t HasFeatHook(CNWSCreatureStats*, uint16_t);

void FeatEvents() __attribute__((constructor));
void FeatEvents()
{
    InitOnFirstSubscribe("NWNX_ON_USE_FEAT_.*", []() {
        s_UseFeatHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector, (void*)&UseFeatHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_HAS_FEAT_.*", []() {
        ForceEnableWhitelist("NWNX_ON_HAS_FEAT");
        s_HasFeatHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats7HasFeatEt, (void*)&HasFeatHook, Hooks::Order::Early);
    });
}

int32_t UseFeatHook(CNWSCreature* thisPtr, uint16_t nFeat, uint16_t nSubFeat, ObjectID oidTarget, ObjectID oidArea, Vector* pvTarget)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("FEAT_ID", std::to_string(nFeat));
        PushEventData("SUBFEAT_ID", std::to_string(nSubFeat));
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        PushEventData("AREA_OBJECT_ID", Utils::ObjectIDToString(oidArea));
        PushEventData("TARGET_POSITION_X", pvTarget ? std::to_string(pvTarget->x) : "0.0");
        PushEventData("TARGET_POSITION_Y", pvTarget ? std::to_string(pvTarget->y) : "0.0");
        PushEventData("TARGET_POSITION_Z", pvTarget ? std::to_string(pvTarget->z) : "0.0");
    return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_FEAT_BEFORE"))
    {
        retVal = s_UseFeatHook->CallOriginal<int32_t>(thisPtr, nFeat, nSubFeat, oidTarget, oidArea, pvTarget);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_USE_FEAT_AFTER");

    return retVal;
}

int32_t HasFeatHook(CNWSCreatureStats* thisPtr, uint16_t nFeat)
{
    int32_t retVal;
    std::string hasFeat;

    if (!IsIDInWhitelist("NWNX_ON_HAS_FEAT", nFeat))
    {
        return s_HasFeatHook->CallOriginal<int32_t>(thisPtr, nFeat);
    }

    auto bHasFeat = s_HasFeatHook->CallOriginal<int32_t>(thisPtr, nFeat);
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("FEAT_ID", std::to_string(nFeat));
        PushEventData("HAS_FEAT", std::to_string(bHasFeat));
        return SignalEvent(ev, thisPtr->m_pBaseCreature->m_idSelf, &hasFeat);
    };

    if (PushAndSignal("NWNX_ON_HAS_FEAT_BEFORE"))
    {
        retVal = bHasFeat;
    }
    else
    {
        retVal = hasFeat == "1";
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_HAS_FEAT_AFTER");

    return retVal;
}

}
