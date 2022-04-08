#include "Events.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerPVPListOperationsHook;

static int32_t HandlePlayerToServerPVPListOperationsHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void PVPEvents() __attribute__((constructor));
void PVPEvents()
{
    InitOnFirstSubscribe("NWNX_ON_PVP_ATTITUDE_CHANGE_.*", []() {
        s_HandlePlayerToServerPVPListOperationsHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage37HandlePlayerToServerPVPListOperationsEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerPVPListOperationsHook, Hooks::Order::Early);
    });
}

int32_t HandlePlayerToServerPVPListOperationsHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
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
            PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
            PushEventData("ATTITUDE", std::to_string(attitude));

            return SignalEvent(ev, pPlayer->m_oidNWSObject);
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
