#include "Events/PVPEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerPVPListOperationsHook;

PVPEvents::PVPEvents(HooksProxy* hooker)
{    Events::InitOnFirstSubscribe("NWNX_ON_PVP_ATTITUDE_CHANGE_.*", [hooker]() {
        s_HandlePlayerToServerPVPListOperationsHook = hooker->RequestExclusiveHook
            <Functions::_ZN11CNWSMessage37HandlePlayerToServerPVPListOperationsEP10CNWSPlayerh>
            (&HandlePlayerToServerPVPListOperationsHook);
    });
}

int32_t PVPEvents::HandlePlayerToServerPVPListOperationsHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    if (nMinor != Constants::MessagePVPMinor::AttitudeChange)
    {
        retVal = s_HandlePlayerToServerPVPListOperationsHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }
    else
    {
        auto target = Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF;
        auto attitude = (bool)(Utils::PeekMessage<uint8_t>(thisPtr, 4) & 0x10);

        auto PushAndSignal = [&](const std::string& ev) -> bool {
            Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
            Events::PushEventData("ATTITUDE", std::to_string(attitude));

            return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
        };

        if (PushAndSignal("NWNX_ON_PVP_ATTITUDE_CHANGE_BEFORE"))
        {
            retVal = s_HandlePlayerToServerPVPListOperationsHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
        }
        else
        {
            // Need to reflip the Attitude switch back on the client that initiated the change when we skip the event
            auto targetPlayerId = Globals::AppManager()->m_pServerExoApp->GetPlayerIDByGameObjectID(target);
            thisPtr->SendServerToPlayerPVP_Attitude_Change(targetPlayerId, pPlayer->m_nPlayerID, attitude == 0);
            retVal = false;
        }

        PushAndSignal("NWNX_ON_PVP_ATTITUDE_CHANGE_AFTER");
    }

    return retVal;
}

}
