#include "Events/ClientEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Events.hpp"
#include "Services/Patching/Patching.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

ClientEvents::ClientEvents(ViewPtr<HooksProxy> hooker)
{
    hooker->RequestSharedHook<API::Functions::CServerExoAppInternal__RemovePCFromWorld, void,
        CServerExoAppInternal*, CNWSPlayer*>(&RemovePCFromWorldHook);
}

void ClientEvents::RemovePCFromWorldHook(Hooks::CallType type, CServerExoAppInternal*, CNWSPlayer* player)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    if (before)
    {
        Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_BEFORE" , player->m_oidNWSObject);
        // NOTE: Events won't be processed for disconnecting characters, e.g. RemoveEffect events.
        // If we wanted that to happen, we'd need to process the event like CServerAIMaster__GetPendingEvent.
    }
    else
    {
        Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_AFTER", player->m_oidNWSObject);
    }

}

}
