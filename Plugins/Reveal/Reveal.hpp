#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::ArgumentStack;

namespace Reveal {

class Reveal : public NWNXLib::Plugin
{
public:
    Reveal(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Reveal();

private:
    NWNXLib::Hooks::Hook m_DoStealthDetection;

    static BOOL HookStealthDetection(CNWSCreature* thisCreature, CNWSCreature* pHidingCreature, BOOL bClearLOS, BOOL* bSeen, BOOL* bHeard, BOOL bTargetHiding);

    ArgumentStack RevealTo(ArgumentStack&& args);
    ArgumentStack SetRevealToParty(ArgumentStack&& args);
};

}
