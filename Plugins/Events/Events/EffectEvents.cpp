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


EffectEvents::EffectEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<NWNXLib::API::Functions::CNWSEffectListHandler__OnEffectApplied, int32_t>(&OnEffectAppliedHook);
    hooker->RequestSharedHook<NWNXLib::API::Functions::CNWSEffectListHandler__OnEffectRemoved, int32_t>(&OnEffectRemovedHook);
}

void EffectEvents::HandleEffectHook(const std::string& event, Services::Hooks::CallType type, CNWSObject* pObject, CGameEffect* pEffect)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    switch (pEffect->m_nType)
    {
        case EffectTrueType::Invalid:
        case EffectTrueType::Icon:
        case EffectTrueType::RacialType:
        case EffectTrueType::VisualEffect:
        case EffectTrueType::Link:
        case EffectTrueType::ItemProperty:
        case EffectTrueType::HasteInternal:
        case EffectTrueType::SlowInternal:
        case EffectTrueType::SetStateInternal:
            return;

        default:
            break;
    }

    Events::PushEventData("ID", std::to_string(pEffect->m_nID));
    Events::PushEventData("CREATOR", Utils::ObjectIDToString(pEffect->m_oidCreator));
    Events::PushEventData("TYPE", std::to_string(pEffect->m_nType));
    Events::PushEventData("SUB_TYPE", std::to_string(pEffect->m_nSubType));
    Events::PushEventData("SPELL_ID", std::to_string(pEffect->m_nSpellId));
    Events::PushEventData("CASTER_LEVEL", std::to_string(pEffect->m_nCasterLevel));
    Events::PushEventData("CUSTOM_TAG", pEffect->m_sCustomTag.CStr());
    Events::PushEventData("DURATION", std::to_string(pEffect->m_fDuration));

    int32_t numIntegerParams = pEffect->m_nNumIntegers;
    if (numIntegerParams)
    {
        for (int i = 0; i < numIntegerParams; i++)
        {
            Events::PushEventData("INT_PARAM_" + std::to_string(i + 1), std::to_string(pEffect->m_nParamInteger[i]));
        }
    }

    Events::SignalEvent(before ? "NWNX_ON_EFFECT_" + event + "_BEFORE" : "NWNX_ON_EFFECT_" + event + "_AFTER" , pObject->m_idSelf);
}

void EffectEvents::OnEffectAppliedHook(Services::Hooks::CallType type, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect, int32_t bLoadingGame)
{
    (void)bLoadingGame;
    HandleEffectHook("APPLIED", type, pObject, pEffect);
}

void EffectEvents::OnEffectRemovedHook(Services::Hooks::CallType type, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect)
{
    HandleEffectHook("REMOVED", type, pObject, pEffect);
}

}
