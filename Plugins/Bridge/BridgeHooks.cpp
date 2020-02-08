#include "BridgeHooks.hpp"
#include "Bridge.hpp"
#include "BridgeMessage.hpp"
#include "API/Functions.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Bridge
{
Bridge* Hooks::s_bridge = nullptr;

void Hooks::InitHooks(Bridge* bridge, NWNXLib::Services::HooksProxy* hooker)
{
    s_bridge = bridge;

    hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN13CServerExoApp8MainLoopEv, void>(
        &CServerExoApp__MainLoop);
}
}

void Bridge::Hooks::CServerExoApp__MainLoop(bool before, CServerExoApp*)
{
    if (before || !s_bridge || !s_bridge->GetInstance())
        return;
    static int ticks = 0;
    if (ticks < 50)
    {
        ticks++;
    }
    else
    {
        ticks = 0;
        if (auto event = s_bridge->GetInstance()->GetIncomingEvent())
        {
            s_bridge->GetInstance()->HandleIncomingEvent(std::move(event));
        }
    }
}
