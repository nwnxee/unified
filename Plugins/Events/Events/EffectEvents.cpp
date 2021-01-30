#include "Events/EffectEvents.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_OnEffectAppliedHook;
static Hooks::Hook s_OnEffectRemovedHook;

EffectEvents::EffectEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_EFFECT_APPLIED_.*", []() {
        s_OnEffectAppliedHook = Hooks::HookFunction(
                NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti,
                (void*)&OnEffectAppliedHook, Hooks::Order::Earliest);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_EFFECT_REMOVED_.*", []() {
        s_OnEffectRemovedHook = Hooks::HookFunction(
                NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
                (void*)&OnEffectRemovedHook, Hooks::Order::Earliest);
    });
}

void EffectEvents::HandleEffectHook(const std::string& event, bool before, CNWSObject* pObject, CGameEffect* pEffect)
{
    if (!pObject || !pEffect)
        return;

    int32_t effectDurationType = pEffect->m_nSubType & EffectDurationType::MASK;

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

    Events::PushEventData("UNIQUE_ID", std::to_string(pEffect->m_nID));
    Events::PushEventData("CREATOR", Utils::ObjectIDToString(pEffect->m_oidCreator));
    Events::PushEventData("TYPE", std::to_string(pEffect->m_nType));
    Events::PushEventData("SUB_TYPE", std::to_string(pEffect->m_nSubType & EffectSubType::MASK));
    Events::PushEventData("DURATION_TYPE", std::to_string(effectDurationType));
    Events::PushEventData("DURATION", std::to_string(pEffect->m_fDuration));
    Events::PushEventData("SPELL_ID", std::to_string(pEffect->m_nSpellId));
    Events::PushEventData("CASTER_LEVEL", std::to_string(pEffect->m_nCasterLevel));
    Events::PushEventData("CUSTOM_TAG", pEffect->m_sCustomTag.CStr());

    for (int i = 0; i < pEffect->m_nNumIntegers; i++)
    {// Int Params
        Events::PushEventData("INT_PARAM_" + std::to_string(i + 1), std::to_string(pEffect->m_nParamInteger[i]));
    }

    for(int i = 0; i < 4; i++)
    {// Float Params
        Events::PushEventData("FLOAT_PARAM_" + std::to_string(i + 1), std::to_string(pEffect->m_nParamFloat[i]));
    }

    for(int i = 0; i < 6; i++)
    {// String Params
        Events::PushEventData("STRING_PARAM_" + std::to_string(i + 1), pEffect->m_sParamString[i].CStr());
    }

    for(int i = 0; i < 4; i++)
    {// Object Params
        Events::PushEventData("OBJECT_PARAM_" + std::to_string(i + 1), Utils::ObjectIDToString(pEffect->m_oidParamObjectID[i]));
    }

    Events::SignalEvent(before ? "NWNX_ON_EFFECT_" + event + "_BEFORE" : "NWNX_ON_EFFECT_" + event + "_AFTER" , pObject->m_idSelf);
}

int32_t EffectEvents::OnEffectAppliedHook(CNWSEffectListHandler *thisPtr, CNWSObject* pObject, CGameEffect* pEffect, int32_t bLoadingGame)
{
    HandleEffectHook("APPLIED", true, pObject, pEffect);
    auto retVal = s_OnEffectAppliedHook->CallOriginal<int32_t>(thisPtr, pObject, pEffect, bLoadingGame);
    HandleEffectHook("APPLIED", false, pObject, pEffect);
    return retVal;
}

int32_t EffectEvents::OnEffectRemovedHook(CNWSEffectListHandler *thisPtr, CNWSObject* pObject, CGameEffect* pEffect)
{
    HandleEffectHook("REMOVED", true, pObject, pEffect);
    auto retVal = s_OnEffectRemovedHook->CallOriginal<int32_t>(thisPtr, pObject, pEffect);
    HandleEffectHook("REMOVED", false, pObject, pEffect);
    return retVal;
}

}
