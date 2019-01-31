#include "Events/StealthEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Utils.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* m_DoSpotDetectionHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_DoListenDetectionHook = nullptr;

StealthEvents::StealthEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<API::Functions::CNWSCreature__SetStealthMode, void, API::CNWSCreature*, uint8_t>(&SetStealthModeHook);

    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__DoListenDetection, int32_t>(&DoListenDetectionHook);
    m_DoListenDetectionHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__DoListenDetection);

    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__DoSpotDetection, int32_t>(&DoSpotDetectionHook);
    m_DoSpotDetectionHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__DoSpotDetection);
}

void StealthEvents::SetStealthModeHook(Services::Hooks::CallType type, API::CNWSCreature* thisPtr, uint8_t mode)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    const bool willBeStealthed = mode != 0;

    static bool currentlyStealthed;
    currentlyStealthed = before ? thisPtr->m_nStealthMode != 0 : currentlyStealthed;

    if (!currentlyStealthed && willBeStealthed)
    {
        Events::SignalEvent(before ? "NWNX_ON_ENTER_STEALTH_BEFORE" : "NWNX_ON_ENTER_STEALTH_AFTER", thisPtr->m_idSelf);
    }
    else
    {
        Events::SignalEvent(before ? "NWNX_ON_EXIT_STEALTH_BEFORE" : "NWNX_ON_EXIT_STEALTH_AFTER", thisPtr->m_idSelf);
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

    Events::PushEventData("TARGET", Utils::ObjectIDToString(pTarget->m_idSelf));
    Events::PushEventData("TARGET_INVISIBLE", std::to_string(bTargetInvisible));

    retVal = Events::SignalEvent("NWNX_ON_DO_" + type + "_DETECTION_BEFORE", pThis->m_idSelf)
             ? pHook->CallOriginal<int32_t>(pThis, pTarget, bTargetInvisible) : false;

    Events::PushEventData("TARGET", Utils::ObjectIDToString(pTarget->m_idSelf));
    Events::PushEventData("TARGET_INVISIBLE", std::to_string(bTargetInvisible));

    Events::SignalEvent("NWNX_ON_DO_" + type + "_DETECTION_AFTER", pThis->m_idSelf);

    return retVal;
}

int32_t StealthEvents::DoListenDetectionHook(
        CNWSCreature* pThis,
        CNWSCreature* pTarget,
        int32_t bTargetInvisible)
{
    return HandleDetectionHook("LISTEN", m_DoListenDetectionHook, pThis, pTarget, bTargetInvisible);
}

int32_t StealthEvents::DoSpotDetectionHook(
        CNWSCreature* pThis,
        CNWSCreature* pTarget,
        int32_t bTargetInvisible)
{
    return HandleDetectionHook("SPOT", m_DoSpotDetectionHook, pThis, pTarget, bTargetInvisible);
}

}
