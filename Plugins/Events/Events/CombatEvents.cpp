
#include "Events/CombatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooking::FunctionHook* s_ApplyDisarmHook;

CombatEvents::CombatEvents(HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_START_COMBAT_ROUND_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN15CNWSCombatRound16StartCombatRoundEj, int32_t>(&StartCombatRoundHook);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_DISARM_*", [hooker]() {
        s_ApplyDisarmHook = hooker->RequestExclusiveHook
                <API::Functions::_ZN21CNWSEffectListHandler13OnApplyDisarmEP10CNWSObjectP11CGameEffecti>(&ApplyDisarmHook);
    });
}

void CombatEvents::StartCombatRoundHook(bool before, CNWSCombatRound* thisPtr, uint32_t oidTarget)
{
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::SignalEvent(before ? "NWNX_ON_START_COMBAT_ROUND_BEFORE" : "NWNX_ON_START_COMBAT_ROUND_AFTER" , thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t CombatEvents::ApplyDisarmHook(CNWSEffectListHandler* pEffectHandler, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame)
{

    int32_t retVal = false;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("DISARMER_OBJECT_ID", Utils::ObjectIDToString(pEffect->m_oidCreator));
        auto nFeatId = pEffect->GetInteger(0) == 1 ? Constants::Feat::ImprovedDisarm : Constants::Feat::Disarm;
        Events::PushEventData("FEAT_ID", std::to_string(nFeatId));
        return Events::SignalEvent(ev, pObject->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_DISARM_BEFORE"))
    {
        retVal = s_ApplyDisarmHook->CallOriginal<int32_t>(pEffectHandler, pObject, pEffect, bLoadingGame);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_DISARM_AFTER");

    return retVal;
}

}
