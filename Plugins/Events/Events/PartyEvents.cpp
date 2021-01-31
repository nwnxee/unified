#include "Events/PartyEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include <cstring>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

static Hooks::Hook s_HandlePlayerToServerPartyHook;

PartyEvents::PartyEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_PARTY_.*", []() {
        s_HandlePlayerToServerPartyHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage25HandlePlayerToServerPartyEP10CNWSPlayerh,
                (void*)&HandlePartyMessageHook, Hooks::Order::Early);
    });
}

int32_t PartyEvents::HandlePartyMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;

    std::string event = "NWNX_ON_PARTY_";
    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;
    std::string sOidOther = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF);

    std::string argname;
    switch (nMinor)
    {
        case Constants::MessagePartyMinor::Leave:
            event += "LEAVE";
            argname = "LEAVING";
            break;
        case Constants::MessagePartyMinor::Kick:
            event += "KICK";
            argname = "KICKED";
            break;
        case Constants::MessagePartyMinor::TransferLeadership:
            event += "TRANSFER_LEADERSHIP";
            argname = "NEW_LEADER";
            break;
        case Constants::MessagePartyMinor::Invite:
            event += "INVITE";
            argname = "INVITED";
            break;
        case Constants::MessagePartyMinor::IgnoreInvitation:
            event += "IGNORE_INVITATION";
            argname = "INVITED_BY";
            break;
        case Constants::MessagePartyMinor::AcceptInvitation:
            event += "ACCEPT_INVITATION";
            argname = "INVITED_BY";
            break;
        case Constants::MessagePartyMinor::RejectInvitation:
            event += "REJECT_INVITATION";
            argname = "INVITED_BY";
            break;
        case Constants::MessagePartyMinor::KickHenchman:
            event += "KICK_HENCHMAN";
            argname = "KICKED";
            break;

        default:
            break;
    }

    Events::PushEventData(argname, sOidOther);

    if (Events::SignalEvent(event + "_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerPartyHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData(argname, sOidOther);
    Events::SignalEvent(event + "_AFTER", oidPlayer);

    return retVal;
}

}
