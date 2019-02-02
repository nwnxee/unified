#include "Events/PolymorphEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* m_PolymorphHook = nullptr;
static Hooking::FunctionHook* m_UnPolymorphHook = nullptr;

PolymorphEvents::PolymorphEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__Polymorph,
        int32_t, CNWSCreature*, int32_t, CGameEffect*, int32_t>(PolymorphEvents::PolymorphHook);
    hooker->RequestExclusiveHook<Functions::CNWSCreature__UnPolymorph,
        int32_t, CNWSCreature*, CGameEffect*>(PolymorphEvents::UnPolymorphHook);

    m_PolymorphHook = hooker->FindHookByAddress(Functions::CNWSCreature__Polymorph);
    m_UnPolymorphHook = hooker->FindHookByAddress(Functions::CNWSCreature__UnPolymorph);
}

int32_t PolymorphEvents::PolymorphHook
(
    CNWSCreature* pThis,
    int32_t nPolymorphType,
    CGameEffect* pParentEffect,
    int32_t bLoadingGame
)
{
    int32_t retVal;

    Events::PushEventData("POLYMORPH_TYPE", std::to_string(nPolymorphType));
    if (Events::SignalEvent("NWNX_ON_POLYMORPH_BEFORE", pThis->m_idSelf))
    {
        retVal = m_PolymorphHook->CallOriginal<int32_t>(pThis, nPolymorphType, pParentEffect, bLoadingGame);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("POLYMORPH_TYPE", std::to_string(nPolymorphType));
    Events::SignalEvent("NWNX_ON_POLYMORPH_BEFORE", pThis->m_idSelf);
    return retVal;
}

int32_t PolymorphEvents::UnPolymorphHook
(
    CNWSCreature* pThis,
    CGameEffect* pParentEffect
)
{
    int32_t retVal;

    if (Events::SignalEvent("NWNX_ON_UNPOLYMORPH_BEFORE", pThis->m_idSelf))
    {
        retVal = m_UnPolymorphHook->CallOriginal<int32_t>(pThis, pParentEffect);
    }
    else
    {
        retVal = false;
    }

    Events::SignalEvent("NWNX_ON_POLYMORPH_BEFORE", pThis->m_idSelf);
    return retVal;
}

}
