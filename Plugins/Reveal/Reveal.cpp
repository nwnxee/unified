#include "Reveal.hpp"
#include <string>
#include "API/CNWSCreature.hpp"
#include "API/CNWSFaction.hpp"
#include "API/Functions.hpp"



using namespace NWNXLib;
using namespace NWNXLib::API;

static Reveal::Reveal* g_plugin;

//key names for Per Object Storage
const std::string revealKey = "REVEAL";
const std::string detectionKey = "DETECTION VECTOR";

//constants for detection method

const int NWNX_REVEAL_SEEN = 1;
const int NWNX_REVEAL_HEARD = 0;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Reveal::Reveal(services);
    return g_plugin;
}

namespace Reveal {

Reveal::Reveal(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func)              \
    ScriptAPI::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(RevealTo);
    REGISTER(SetRevealToParty);

#undef REGISTER

    m_DoStealthDetection = Hooks::HookFunction(&CNWSCreature::DoStealthDetection, (void*)&HookStealthDetection, Hooks::Order::Late);
}

Reveal::~Reveal()
{
}
BOOL Reveal::HookStealthDetection(CNWSCreature* pObserverCreature, CNWSCreature* pHidingCreature, BOOL bClearLOS, BOOL* bSeen, BOOL* bHeard, BOOL bTargetHiding)
{
    if (pObserverCreature->m_bPlayerCharacter && pHidingCreature->m_bPlayerCharacter && pHidingCreature->m_nStealthMode)
    {
        if (pObserverCreature->GetArea() == pHidingCreature->GetArea())
        {
            auto partyReveal = pHidingCreature->nwnxGet<int>(revealKey + "PARTY");
            if (partyReveal && *partyReveal)
            {
                if (pObserverCreature->GetFaction()->GetLeader() == pHidingCreature->GetFaction()->GetLeader())
                {
                    auto detectionVector = pHidingCreature->nwnxGet<int>(detectionKey + "PARTY");
                    if (detectionVector && *detectionVector)
                        *bSeen = *detectionVector;
                    else
                        *bSeen = false;

                    *bHeard = true;
                    return true;
                }
            }

            auto reveal = pHidingCreature->nwnxGet<int>(revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf));
            if (reveal && *reveal)
            {
                pHidingCreature->nwnxRemove(revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf)); //remove mapping after first check
                
                auto detectionVector = pHidingCreature->nwnxGet<int>(detectionKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf));
                if (detectionVector && *detectionVector)
                    *bSeen = *detectionVector;
                else
                    *bSeen = false;

                *bHeard = true;
                return true;
            }
        }
    }
    return g_plugin->m_DoStealthDetection->CallOriginal<BOOL>(pObserverCreature, pHidingCreature, bClearLOS, bSeen, bHeard, bTargetHiding);
}


ArgumentStack Reveal::RevealTo(ArgumentStack&& args)
{
    auto stealtherID = ScriptAPI::ExtractArgument<ObjectID>(args);
    auto observerID = ScriptAPI::ExtractArgument<ObjectID>(args);
    auto detectionVector = ScriptAPI::ExtractArgument<int>(args);

    auto stealther = Utils::GetGameObject(stealtherID);
    stealther->nwnxSet(revealKey + Utils::ObjectIDToString(observerID), true); //store stealth to observer reveal map
    stealther->nwnxSet(detectionKey + Utils::ObjectIDToString(observerID), detectionVector); //store the means through which detection happens
    return ScriptAPI::Arguments();
}

ArgumentStack Reveal::SetRevealToParty(ArgumentStack&& args)
{
    auto stealtherID = ScriptAPI::ExtractArgument<ObjectID>(args);
    auto revealToPartyState = ScriptAPI::ExtractArgument<int>(args);
    auto detectionVector = ScriptAPI::ExtractArgument<int>(args);

    auto stealther = Utils::GetGameObject(stealtherID);
    stealther->nwnxSet(revealKey + "PARTY", revealToPartyState, true); //store party reveal state
    stealther->nwnxSet(detectionKey + "PARTY", detectionVector, true); //store the means through which detection happens
    return ScriptAPI::Arguments();
}

}
