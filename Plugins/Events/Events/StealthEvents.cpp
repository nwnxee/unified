#include "Events/StealthEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_SetStealthModeHook;
static NWNXLib::Hooks::Hook s_SetDetectModeHook;
static NWNXLib::Hooks::Hook s_DoSpotDetectionHook;
static NWNXLib::Hooks::Hook s_DoListenDetectionHook;

StealthEvents::StealthEvents()
{
    // TODO: Deprecate ON_E*_STEALTH in favor of ON_STEALTH_E*
    Events::InitOnFirstSubscribe("NWNX_ON_(E.*_STEALTH_.*|STEALTH_E.*)", []() {
        s_SetStealthModeHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature14SetStealthModeEh,
                                            (void*)&SetStealthModeHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_DETECT_E.*", []() {
        s_SetDetectModeHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature13SetDetectModeEh,
                                           (void*)&SetDetectModeHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_DO_LISTEN_DETECTION_.*", []() {
        s_DoListenDetectionHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature17DoListenDetectionEPS_i,
                                               (void*)&DoListenDetectionHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_DO_SPOT_DETECTION.*", []() {
        s_DoSpotDetectionHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature15DoSpotDetectionEPS_i,
                                             (void*)&DoSpotDetectionHook, Hooks::Order::Early);
    });
}

void StealthEvents::SetStealthModeHook(CNWSCreature* thisPtr, uint8_t nStealthMode)
{
    const bool willBeStealthed = nStealthMode != 0;
    const bool currentlyStealthed = thisPtr->m_nStealthMode != 0;
    std::string sResult;

    if (!currentlyStealthed && willBeStealthed)
    {
        // TODO: Deprecate ON_E*_STEALTH in favor of ON_STEALTH_E*
        if (Events::SignalEvent("NWNX_ON_ENTER_STEALTH_BEFORE", thisPtr->m_idSelf) &&
            Events::SignalEvent("NWNX_ON_STEALTH_ENTER_BEFORE", thisPtr->m_idSelf, &sResult))
        {
            s_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
        }
        else
        {
            if (sResult == "0")
            {
                bool bHadHIPS = false;
                if (thisPtr->m_pStats->HasFeat(Constants::Feat::HideInPlainSight))
                {
                    thisPtr->m_pStats->RemoveFeat(Constants::Feat::HideInPlainSight);
                    bHadHIPS = true;
                }
                s_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
                if (bHadHIPS)
                    thisPtr->m_pStats->AddFeat(Constants::Feat::HideInPlainSight);
            }
            else if (sResult == "1")
            {
                bool bNoHIPS = false;
                if (!thisPtr->m_pStats->HasFeat(Constants::Feat::HideInPlainSight))
                {
                    thisPtr->m_pStats->AddFeat(Constants::Feat::HideInPlainSight);
                    bNoHIPS = true;
                }
                s_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
                if (bNoHIPS)
                    thisPtr->m_pStats->RemoveFeat(Constants::Feat::HideInPlainSight);
            }
            else
                thisPtr->ClearActivities(1);
        }

        // TODO: Deprecate ON_E*_STEALTH in favor of ON_STEALTH_E*
        Events::SignalEvent("NWNX_ON_ENTER_STEALTH_AFTER", thisPtr->m_idSelf);
        Events::SignalEvent("NWNX_ON_STEALTH_ENTER_AFTER", thisPtr->m_idSelf);
    }
    else if (currentlyStealthed && !willBeStealthed)
    {
        // TODO: Deprecate ON_E*_STEALTH in favor of ON_STEALTH_E*
        if (Events::SignalEvent("NWNX_ON_EXIT_STEALTH_BEFORE", thisPtr->m_idSelf) &&
            Events::SignalEvent("NWNX_ON_STEALTH_EXIT_BEFORE", thisPtr->m_idSelf))
        {
            s_SetStealthModeHook->CallOriginal<void>(thisPtr, nStealthMode);
        }
        else
        {
            thisPtr->SetActivity(1, true);
        }

        // TODO: Deprecate ON_E*_STEALTH in favor of ON_STEALTH_E*
        Events::SignalEvent("NWNX_ON_EXIT_STEALTH_AFTER", thisPtr->m_idSelf);
        Events::SignalEvent("NWNX_ON_STEALTH_EXIT_AFTER", thisPtr->m_idSelf);
    }
}

void StealthEvents::SetDetectModeHook(CNWSCreature* thisPtr, uint8_t nDetectMode)
{
    const bool willBeDetecting = nDetectMode != 0;
    const bool currentlyDetecting = thisPtr->m_nDetectMode != 0;

    if (!currentlyDetecting && willBeDetecting)
    {
        if (Events::SignalEvent("NWNX_ON_DETECT_ENTER_BEFORE", thisPtr->m_idSelf))
        {
            s_SetDetectModeHook->CallOriginal<void>(thisPtr, nDetectMode);
        }
        else
        {
            thisPtr->ClearActivities(0);
        }

        Events::SignalEvent("NWNX_ON_DETECT_ENTER_AFTER", thisPtr->m_idSelf);
    }
    else if(currentlyDetecting && !willBeDetecting)
    {
        if (Events::SignalEvent("NWNX_ON_DETECT_ENTER_BEFORE", thisPtr->m_idSelf))
        {
            s_SetDetectModeHook->CallOriginal<void>(thisPtr, nDetectMode);
        }
        else
        {
            thisPtr->SetActivity(0, true);
        }

        Events::SignalEvent("NWNX_ON_DETECT_ENTER_AFTER", thisPtr->m_idSelf);
    }
}

int32_t StealthEvents::HandleDetectionHook(const std::string& type, Hooks::FunctionHook* pHook, CNWSCreature* pThis,
                                           CNWSCreature* pTarget, int32_t bTargetInvisible)
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

int32_t StealthEvents::DoListenDetectionHook(CNWSCreature* pThis, CNWSCreature* pTarget, int32_t bTargetInvisible)
{
    if (!pTarget->m_nStealthMode && !bTargetInvisible)
        return true;

    return HandleDetectionHook("LISTEN", s_DoListenDetectionHook.get(), pThis, pTarget, bTargetInvisible);
}

int32_t StealthEvents::DoSpotDetectionHook(CNWSCreature* pThis, CNWSCreature* pTarget, int32_t bTargetInvisible)
{
    if (bTargetInvisible || pThis->GetBlind())
        return false;

    if (!pTarget->m_nStealthMode)
        return true;

    return HandleDetectionHook("SPOT", s_DoSpotDetectionHook.get(), pThis, pTarget, bTargetInvisible);
}

}
