#include "Events.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_OnApplyPolymorphHook;
static Hooks::Hook s_OnRemovePolymorphHook;

static int32_t OnApplyPolymorphHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
static int32_t OnRemovePolymorphHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);

void PolymorphEvents() __attribute__((constructor));
void PolymorphEvents()
{
    InitOnFirstSubscribe("NWNX_ON_POLYMORPH_.*", []() {
        s_OnApplyPolymorphHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler16OnApplyPolymorphEP10CNWSObjectP11CGameEffecti,
                                              (void*)&OnApplyPolymorphHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_UNPOLYMORPH_.*", []() {
        s_OnRemovePolymorphHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler17OnRemovePolymorphEP10CNWSObjectP11CGameEffect,
                                               (void*)&OnRemovePolymorphHook, Hooks::Order::Early);
    });
}

int32_t OnApplyPolymorphHook(CNWSEffectListHandler* pThis, CNWSObject* pObject, CGameEffect* pEffect, int32_t bLoadingGame)
{
    int32_t retVal;

    if (!Utils::AsNWSCreature(pObject))
        return 1; // delete

    int32_t type = pEffect->GetInteger(0);
    PushEventData("POLYMORPH_TYPE", std::to_string(type));
    if (SignalEvent("NWNX_ON_POLYMORPH_BEFORE", pObject->m_idSelf))
    {
        retVal = s_OnApplyPolymorphHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
    }
    else
    {
        retVal = 1; // Delete effect
    }

    PushEventData("POLYMORPH_TYPE", std::to_string(type));
    SignalEvent("NWNX_ON_POLYMORPH_AFTER", pObject->m_idSelf);

    return retVal;
}

int32_t OnRemovePolymorphHook(CNWSEffectListHandler* pThis, CNWSObject* pObject, CGameEffect* pEffect)
{
    int32_t retVal;

    if (!Utils::AsNWSCreature(pObject))
        return 1; // delete

    if (SignalEvent("NWNX_ON_UNPOLYMORPH_BEFORE", pObject->m_idSelf))
    {
        retVal = s_OnRemovePolymorphHook->CallOriginal<int32_t>(pThis, pObject, pEffect);
    }
    else
    {
        retVal = 0; // keep effect
    }

    SignalEvent("NWNX_ON_UNPOLYMORPH_AFTER", pObject->m_idSelf);

    return retVal;
}

}
