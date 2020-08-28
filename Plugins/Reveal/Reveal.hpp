#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "Common.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Reveal {

class Reveal : public NWNXLib::Plugin
{
public:
    Reveal(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Reveal();

private:
    NWNXLib::Hooking::FunctionHook* m_DoStealthDetection;

    static int32_t HookStealthDetection(CNWSCreature* thisCreature, CNWSCreature* pHidingCreature, int32_t bClearLOS, int32_t* bSeen, int32_t* bHeard, int32_t bTargetInvisible);

    ArgumentStack RevealTo(ArgumentStack&& args);
    ArgumentStack SetRevealToParty(ArgumentStack&& args);
};

}
