#include "Events/PolymorphEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;


static Hooking::FunctionHook* s_OnApplyPolymorphHook;
static Hooking::FunctionHook* s_OnRemovePolymorphHook;

PolymorphEvents::PolymorphEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_POLYMORPH_.*", [hooker]() {
        s_OnApplyPolymorphHook = hooker->RequestExclusiveHook
            <Functions::_ZN21CNWSEffectListHandler16OnApplyPolymorphEP10CNWSObjectP11CGameEffecti, int32_t, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t>
            (PolymorphEvents::OnApplyPolymorphHook);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_UNPOLYMORPH_.*", [hooker]() {
        s_OnRemovePolymorphHook = hooker->RequestExclusiveHook
            <Functions::_ZN21CNWSEffectListHandler17OnRemovePolymorphEP10CNWSObjectP11CGameEffect, int32_t, CNWSEffectListHandler*, CNWSObject*, CGameEffect*>
            (PolymorphEvents::OnRemovePolymorphHook);
    });

}

int32_t PolymorphEvents::OnApplyPolymorphHook
(
    CNWSEffectListHandler* pThis,
    CNWSObject* pObject,
    CGameEffect* pEffect,
    int32_t bLoadingGame
)
{
    int32_t retVal;

    if (!Utils::AsNWSCreature(pObject))
        return 1; // delete

    int32_t type = pEffect->GetInteger(0);
    Events::PushEventData("POLYMORPH_TYPE", std::to_string(type));
    if (Events::SignalEvent("NWNX_ON_POLYMORPH_BEFORE", pObject->m_idSelf))
    {
        retVal = s_OnApplyPolymorphHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
    }
    else
    {
        retVal = 1; // Delete effect
    }

    Events::PushEventData("POLYMORPH_TYPE", std::to_string(type));
    Events::SignalEvent("NWNX_ON_POLYMORPH_AFTER", pObject->m_idSelf);
    return retVal;
}

int32_t PolymorphEvents::OnRemovePolymorphHook
(
    CNWSEffectListHandler* pThis,
    CNWSObject* pObject,
    CGameEffect* pEffect
)
{
    int32_t retVal;

    if (!Utils::AsNWSCreature(pObject))
        return 1; // delete

    if (Events::SignalEvent("NWNX_ON_UNPOLYMORPH_BEFORE", pObject->m_idSelf))
    {
        retVal = s_OnRemovePolymorphHook->CallOriginal<int32_t>(pThis, pObject, pEffect);
    }
    else
    {
        retVal = 0; // keep effect
    }

    Events::SignalEvent("NWNX_ON_UNPOLYMORPH_AFTER", pObject->m_idSelf);
    return retVal;
}

}
