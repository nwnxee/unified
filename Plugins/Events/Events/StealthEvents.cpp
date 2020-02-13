#include "Events/StealthEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Utils.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* m_SetStealthModeHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_DoSpotDetectionHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_DoListenDetectionHook = nullptr;

StealthEvents::StealthEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_E.*_STEALTH_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature14SetStealthModeEh>(&SetStealthModeHook);
        m_SetStealthModeHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature14SetStealthModeEh);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_DO_LISTEN_DETECTION_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature17DoListenDetectionEPS_i, int32_t>(&DoListenDetectionHook);
        m_DoListenDetectionHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature17DoListenDetectionEPS_i);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_DO_SPOT_DETECTION.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature15DoSpotDetectionEPS_i, int32_t>(&DoSpotDetectionHook);
        m_DoSpotDetectionHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature15DoSpotDetectionEPS_i);
    });
}

void StealthEvents::SetStealthModeHook(CNWSCreature* thisPtr, uint8_t nStealthMode)
{
    const bool willBeStealthed = nStealthMode != 0;
    const bool currentlyStealthed = thisPtr->m_nStealthMode != 0;

    if (!currentlyStealthed && willBeStealthed)
    {
        if (Events::SignalEvent("NWNX_ON_ENTER_STEALTH_BEFORE", thisPtr->m_idSelf))
        {
            m_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
        }
        else
        {
            thisPtr->ClearActivities(1);
        }

        Events::SignalEvent("NWNX_ON_ENTER_STEALTH_AFTER", thisPtr->m_idSelf);
    }
    else if(currentlyStealthed && !willBeStealthed)
    {
        if (Events::SignalEvent("NWNX_ON_EXIT_STEALTH_BEFORE", thisPtr->m_idSelf))
        {
            m_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
        }
        else
        {
            thisPtr->SetActivity(1, true);
        }

        Events::SignalEvent("NWNX_ON_EXIT_STEALTH_AFTER", thisPtr->m_idSelf);
    }
}

int32_t StealthEvents::HandleDetectionHook(
        const std::string& type,
        NWNXLib::Hooking::FunctionHook* pHook,
        CNWSCreature* pThis,
        CNWSCreature* pTarget,
        int32_t bTargetInvisible)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    Events::PushEventData("TARGET", Utils::ObjectIDToString(pTarget->m_idSelf));
    Events::PushEventData("TARGET_INVISIBLE", std::to_string(bTargetInvisible));

    retVal = Events::SignalEvent("NWNX_ON_DO_" + type + "_DETECTION_BEFORE", pThis->m_idSelf, &sBeforeEventResult)
             ? pHook->CallOriginal<int32_t>(pThis, pTarget, bTargetInvisible) : sBeforeEventResult == "1";

    Events::PushEventData("TARGET", Utils::ObjectIDToString(pTarget->m_idSelf));
    Events::PushEventData("TARGET_INVISIBLE", std::to_string(bTargetInvisible));
    Events::PushEventData("BEFORE_RESULT", std::to_string(retVal));

    Events::SignalEvent("NWNX_ON_DO_" + type + "_DETECTION_AFTER", pThis->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

int32_t StealthEvents::DoListenDetectionHook(
        CNWSCreature* pThis,
        CNWSCreature* pTarget,
        int32_t bTargetInvisible)
{
    if (!pTarget->m_nStealthMode && !bTargetInvisible)
        return true;

    return HandleDetectionHook("LISTEN", m_DoListenDetectionHook, pThis, pTarget, bTargetInvisible);
}

int32_t StealthEvents::DoSpotDetectionHook(
        CNWSCreature* pThis,
        CNWSCreature* pTarget,
        int32_t bTargetInvisible)
{
    if (bTargetInvisible || pThis->GetBlind())
        return false;

    if (!pTarget->m_nStealthMode)
        return true;

    return HandleDetectionHook("SPOT", m_DoSpotDetectionHook, pThis, pTarget, bTargetInvisible);
}

}
