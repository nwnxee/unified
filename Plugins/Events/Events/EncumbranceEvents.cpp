#include "Events.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_UpdateEncumbranceStateHook;

static void UpdateEncumbranceStateHook(CNWSCreature*, BOOL);

void EncumbranceEvents() __attribute__((constructor));
void EncumbranceEvents()
{
    InitOnFirstSubscribe("NWNX_ON_ENCUMBRANCE_CHANGE_.*", []() {
        s_UpdateEncumbranceStateHook = Hooks::HookFunction(&CNWSCreature::UpdateEncumbranceState,
                                                           &UpdateEncumbranceStateHook, Hooks::Order::Earliest);
    });
}

void UpdateEncumbranceStateHook(CNWSCreature *thisPtr, BOOL bDisplayFeedback)
{
    // The engine works out the new state inside this function and applies the movement speed
    // penalty there too, so the event can only be signalled after it has run.
    const int32_t oldState = thisPtr->m_nEncumbranceState;
    s_UpdateEncumbranceStateHook->CallOriginal<void>(thisPtr, bDisplayFeedback);
    const int32_t newState = thisPtr->m_nEncumbranceState;

    if (oldState != newState)
    {
        PushEventData("OLD_STATE", std::to_string(oldState));
        PushEventData("NEW_STATE", std::to_string(newState));
        PushEventData("TOTAL_WEIGHT", std::to_string(thisPtr->m_nTotalWeightCarried));
        SignalEvent("NWNX_ON_ENCUMBRANCE_CHANGE_AFTER", thisPtr->m_idSelf);
    }
}

}
