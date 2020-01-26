#include "Reveal.hpp"
#include <string>
#include "API/CNWSCreature.hpp"
#include "API/CNWSFaction.hpp"
#include "API/Functions.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"



using namespace NWNXLib;
using namespace NWNXLib::API;

static Reveal::Reveal* g_plugin;

//key names for Per Object Storage
const std::string revealKey = "REVEAL";
const std::string detectionKey = "DETECTION VECTOR";

//constants for detection method

const int NWNX_REVEAL_SEEN = 1;
const int NWNX_REVEAL_HEARD = 0;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Reveal",
        "Functions to allow the selective revealing of a stealthed character to another character or their party.",
        "Silvard",
        "jusenkyo at gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Reveal::Reveal(params);
    return g_plugin;
}

namespace Reveal {

Reveal::Reveal(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(RevealTo);
    REGISTER(SetRevealToParty);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature18DoStealthDetectionEPS_iPiS1_i, int32_t,CNWSCreature*,CNWSCreature*, int32_t, int32_t*, int32_t*, int32_t>(&HookStealthDetection);
    m_DoStealthDetection = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature18DoStealthDetectionEPS_iPiS1_i);
}

Reveal::~Reveal()
{
}
int32_t Reveal::HookStealthDetection(CNWSCreature* pObserverCreature, CNWSCreature* pHidingCreature, int32_t bClearLOS, int32_t* bSeen, int32_t* bHeard, int32_t bTargetInvisible)
{
    Services::PerObjectStorageProxy* pPOS = g_plugin->GetServices()->m_perObjectStorage.get();

    if (pObserverCreature->m_bPlayerCharacter && pHidingCreature->m_bPlayerCharacter && pHidingCreature->m_nStealthMode)
    {
        if (pObserverCreature->GetArea() == pHidingCreature->GetArea())
        {
            if (*pPOS->Get<int>(pHidingCreature->m_idSelf, revealKey + "PARTY"))
            {
                if (pObserverCreature->GetFaction()->GetLeader() == pHidingCreature->GetFaction()->GetLeader())
                {
                    if(*pPOS->Get<int>(pHidingCreature->m_idSelf, detectionKey + "PARTY"))
                    {
                        *bSeen = true;
                    }
                    *bHeard = true;
                    return true;
                }
            }
            if (*pPOS->Get<int>(pHidingCreature->m_idSelf, revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf)))
            {
                pPOS->Remove(pHidingCreature->m_idSelf, revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf)); //remove mapping after first check
                if (*pPOS->Get<int>(pHidingCreature->m_idSelf, detectionKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf)))
                {
                    *bSeen = true;
                }
                *bHeard = true;
                return true;
            }
        }
    }
    return g_plugin->m_DoStealthDetection->CallOriginal<int32_t>(pObserverCreature, pHidingCreature, bClearLOS, bSeen, bHeard, bTargetInvisible);
}


ArgumentStack Reveal::RevealTo(ArgumentStack&& args)
{
    auto stealtherID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto observerID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto detectionVector = Services::Events::ExtractArgument<int>(args);

    Services::PerObjectStorageProxy* pPOS = g_plugin->GetServices()->m_perObjectStorage.get();

    pPOS->Set(stealtherID, revealKey + Utils::ObjectIDToString(observerID), true); //store stealth to observer reveal map
    pPOS->Set(stealtherID, detectionKey + Utils::ObjectIDToString(observerID), detectionVector); //store the means through which detection happens
    return Services::Events::Arguments();
}

ArgumentStack Reveal::SetRevealToParty(ArgumentStack&& args)
{
    auto stealtherID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto revealToPartyState = Services::Events::ExtractArgument<int>(args);
    auto detectionVector = Services::Events::ExtractArgument<int>(args);

    Services::PerObjectStorageProxy* pPOS = g_plugin->GetServices()->m_perObjectStorage.get();

    pPOS->Set(stealtherID, revealKey + "PARTY", revealToPartyState, true); //store party reveal state
    pPOS->Set(stealtherID, detectionKey + "PARTY", detectionVector, true); //store the means through which detection happens
    return Services::Events::Arguments();
}

}
