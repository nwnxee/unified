#include "Reveal.hpp"
#include <string>
#include "API/CNWSCreature.hpp"
#include "API/CNWSFaction.hpp"
#include "API/Functions.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "ViewPtr.hpp"



using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Reveal::Reveal> g_plugin;

//key names for Per Object Storage
const std::string revealKey = "REVEAL";

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
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Reveal::func, this, std::placeholders::_1))

    REGISTER(RevealTo);
    REGISTER(SetRevealToParty);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__DoStealthDetection, int32_t,CNWSCreature*,CNWSCreature*, int32_t, int32_t*, int32_t*, int32_t>(&HookStealthDetection);
    m_DoStealthDetection = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__DoStealthDetection);
}   

Reveal::~Reveal()
{
}
int32_t Reveal::HookStealthDetection(NWNXLib::API::CNWSCreature* pObserverCreature, NWNXLib::API::CNWSCreature* pHidingCreature, int32_t bClearLOS, int32_t* bSeen, int32_t* bHeard, int32_t bTargetInvisible)
{
    if (pObserverCreature->m_bPlayerCharacter && pHidingCreature->m_bPlayerCharacter && pHidingCreature->m_nStealthMode)
    {
        if (pObserverCreature->GetArea() == pHidingCreature->GetArea())
        {
            if (static_cast<bool>(*g_plugin->GetServices()->m_perObjectStorage->Get<int>(pHidingCreature->m_idSelf, revealKey + "PARTY")))
            {
                if (pObserverCreature->GetFaction()->GetLeader() == pHidingCreature->GetFaction()->GetLeader())
                {
                    *bHeard = true;
                    return true;
                }
            }
            if (static_cast<bool>(*g_plugin->GetServices()->m_perObjectStorage->Get<int>(pHidingCreature->m_idSelf, revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf))))
            {
                g_plugin->GetServices()->m_perObjectStorage->Remove(pHidingCreature->m_idSelf, revealKey + Utils::ObjectIDToString(pObserverCreature->m_idSelf)); //remove mapping after first check
                *bHeard = true;
                return true;
            }
        }
    }
    return g_plugin->m_DoStealthDetection->CallOriginal<int32_t>(pObserverCreature, pHidingCreature, bClearLOS, bSeen, bHeard, bTargetInvisible);
}


ArgumentStack Reveal::RevealTo(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto stealtherID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto observerID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    
    Services::PerObjectStorageProxy* pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
    
    pPOS->Set(stealtherID, revealKey + Utils::ObjectIDToString(observerID), true); //store stealth to observer reveal map
    return stack;
}

ArgumentStack Reveal::SetRevealToParty(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto stealtherID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto revealToPartyState = Services::Events::ExtractArgument<int>(args);
    Services::PerObjectStorageProxy* pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
    
    pPOS->Set(stealtherID, revealKey + "PARTY", revealToPartyState); //store party reveal state
    return stack;
}

}
