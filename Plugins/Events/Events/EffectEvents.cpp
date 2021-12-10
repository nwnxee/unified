#include "Events.hpp"
#include "API/CNWSObject.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_OnEffectAppliedHook;
static Hooks::Hook s_OnEffectRemovedHook;

static void HandleEffectHook(const std::string&, bool, CNWSObject*, CGameEffect*);
static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
static int32_t OnEffectRemovedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);

void EffectEvents() __attribute__((constructor));
void EffectEvents()
{
    InitOnFirstSubscribe("NWNX_ON_EFFECT_APPLIED_.*", []() {
        s_OnEffectAppliedHook = Hooks::HookFunction(
                NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti,
                (void*)&OnEffectAppliedHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_EFFECT_REMOVED_.*", []() {
        s_OnEffectRemovedHook = Hooks::HookFunction(
                NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
                (void*)&OnEffectRemovedHook, Hooks::Order::Earliest);
    });
}

void HandleEffectHook(const std::string& event, bool before, CNWSObject* pObject, CGameEffect* pEffect)
{
    if (!pObject || !pEffect)
        return;

    int32_t effectDurationType = pEffect->GetDurationType();

    if (effectDurationType != EffectDurationType::Temporary && effectDurationType != EffectDurationType::Permanent)
        return;

    switch (pEffect->m_nType)
    {
        case EffectTrueType::Icon:
        case EffectTrueType::VisualEffect:
        case EffectTrueType::Link:
        case EffectTrueType::ItemProperty:
        case EffectTrueType::Beam:
            return;

        default:
            break;
    }

    PushEventData("UNIQUE_ID", std::to_string(pEffect->m_nID));
    PushEventData("CREATOR", Utils::ObjectIDToString(pEffect->m_oidCreator));
    PushEventData("TYPE", std::to_string(pEffect->m_nType));
    PushEventData("SUB_TYPE", std::to_string(pEffect->GetSubType()));
    PushEventData("DURATION_TYPE", std::to_string(effectDurationType));
    PushEventData("DURATION", std::to_string(pEffect->m_fDuration));
    PushEventData("SPELL_ID", std::to_string(pEffect->m_nSpellId));
    PushEventData("CASTER_LEVEL", std::to_string(pEffect->m_nCasterLevel));
    PushEventData("CUSTOM_TAG", pEffect->m_sCustomTag.CStr());

    for (int i = 0; i < pEffect->m_nNumIntegers; i++)
    {// Int Params
        PushEventData("INT_PARAM_" + std::to_string(i + 1), std::to_string(pEffect->m_nParamInteger[i]));
    }

    for(int i = 0; i < 4; i++)
    {// Float Params
        PushEventData("FLOAT_PARAM_" + std::to_string(i + 1), std::to_string(pEffect->m_nParamFloat[i]));
    }

    for(int i = 0; i < 6; i++)
    {// String Params
        PushEventData("STRING_PARAM_" + std::to_string(i + 1), pEffect->m_sParamString[i].CStr());
    }

    for(int i = 0; i < 4; i++)
    {// Object Params
        PushEventData("OBJECT_PARAM_" + std::to_string(i + 1), Utils::ObjectIDToString(pEffect->m_oidParamObjectID[i]));
    }

    SignalEvent(before ? "NWNX_ON_EFFECT_" + event + "_BEFORE" : "NWNX_ON_EFFECT_" + event + "_AFTER" , pObject->m_idSelf);
}

int32_t OnEffectAppliedHook(CNWSEffectListHandler *thisPtr, CNWSObject* pObject, CGameEffect* pEffect, int32_t bLoadingGame)
{
    HandleEffectHook("APPLIED", true, pObject, pEffect);
    auto retVal = s_OnEffectAppliedHook->CallOriginal<int32_t>(thisPtr, pObject, pEffect, bLoadingGame);
    HandleEffectHook("APPLIED", false, pObject, pEffect);
    return retVal;
}

int32_t OnEffectRemovedHook(CNWSEffectListHandler *thisPtr, CNWSObject* pObject, CGameEffect* pEffect)
{
    HandleEffectHook("REMOVED", true, pObject, pEffect);
    auto retVal = s_OnEffectRemovedHook->CallOriginal<int32_t>(thisPtr, pObject, pEffect);
    HandleEffectHook("REMOVED", false, pObject, pEffect);
    return retVal;
}

}
