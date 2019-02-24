#include "Events/InventoryEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerGuiInventoryMessageHook = nullptr;

InventoryEvents::InventoryEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_.*", [hooker]()
    {
        hooker->RequestExclusiveHook<API::Functions::CNWSMessage__HandlePlayerToServerGuiInventoryMessage>(
                &HandlePlayerToServerGuiInventoryMessageHook);
        m_HandlePlayerToServerGuiInventoryMessageHook = hooker->FindHookByAddress(
                API::Functions::CNWSMessage__HandlePlayerToServerGuiInventoryMessage);
    });
}

int32_t InventoryEvents::HandlePlayerToServerGuiInventoryMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    Types::ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;

    switch (nMinor)
    {
        case MessageGuiInventoryMinor::Status:
        {
            std::string open = std::to_string(Utils::PeekMessage<int32_t>(thisPtr, 0));

            auto PushAndSignal = [&](std::string ev) -> bool
            {
                Events::PushEventData("OPEN", open);

                return Events::SignalEvent(ev, oidPlayer);
            };

            if (PushAndSignal("NWNX_ON_INVENTORY_OPEN_BEFORE"))
            {
                retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal("NWNX_ON_INVENTORY_OPEN_AFTER");
            break;
        }

        case MessageGuiInventoryMinor::SelectPanel:
        {
            std::string panel = std::to_string(Utils::PeekMessage<uint8_t>(thisPtr, 0));

            auto PushAndSignal = [&](std::string ev) -> bool
            {
                Events::PushEventData("PAGE", panel);

                return Events::SignalEvent(ev, oidPlayer);
            };

            if (PushAndSignal("NWNX_ON_INVENTORY_SELECT_PAGE_BEFORE"))
            {
                retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal("NWNX_ON_INVENTORY_SELECT_PAGE_AFTER");
            break;
        }

        default:
            retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            break;
    }

    return retVal;
}

}
