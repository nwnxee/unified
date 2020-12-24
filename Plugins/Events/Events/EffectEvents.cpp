#include "Events/EffectEvents.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;


EffectEvents::EffectEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_EFFECT_APPLIED_.*", [hooker]() {
       hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectAppliedEP10CNWSObjectP11CGameEffecti, int32_t>(&OnEffectAppliedHook);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_EFFECT_REMOVED_.*", [hooker]() {
        hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect, int32_t>(&OnEffectRemovedHook);
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

void EffectEvents::OnEffectAppliedHook(bool before, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect, int32_t)
{
    HandleEffectHook("APPLIED", before, pObject, pEffect);
}

void EffectEvents::OnEffectRemovedHook(bool before, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect)
{
    HandleEffectHook("REMOVED", before, pObject, pEffect);
}

}
