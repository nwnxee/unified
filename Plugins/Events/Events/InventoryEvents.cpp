#include "Events/InventoryEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
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

    if (!pPlayer)
        return m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);

    switch (nMinor)
    {
        case MessageGuiInventoryMinor::Status:
        {
            auto target = Utils::PeekMessage<Types::ObjectID>(thisPtr, 0) & 0x7FFFFFFF;
            auto open = (bool)(Utils::PeekMessage<uint8_t>(thisPtr, 4) & 0x10);

            if (open)
            {
                auto PushAndSignal = [&](std::string ev) -> bool
                {
                    Events::PushEventData("TARGET_INVENTORY", Utils::ObjectIDToString(target));
                    return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
                };

                if (PushAndSignal("NWNX_ON_INVENTORY_OPEN_BEFORE"))
                {
                    retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
                }
                else
                {
                    CNWSPlayerInventoryGUI *pInventory = pPlayer->m_oidNWSObject == target ? pPlayer->m_pInventoryGUI :
                                                         pPlayer->m_pOtherInventoryGUI;

                    auto *pMessage = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
                    if (pMessage)
                    {
                        pMessage->SendPlayerToServerGuiInventory_Status(pPlayer, false, target);
                        pInventory->SetOpen(false, false/*bClientDirected*/);
                    }

                    retVal = false;
                }

                PushAndSignal("NWNX_ON_INVENTORY_OPEN_AFTER");
            }
            else
            {
                retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            }
            break;
        }

        case MessageGuiInventoryMinor::SelectPanel:
        {
            auto selectedPanel = Utils::PeekMessage<uint8_t>(thisPtr, 0);
            auto ownInventory = (bool)(Utils::PeekMessage<uint8_t>(thisPtr, 1) & 0x10);

            if (ownInventory)
            {
                uint8_t currentPanel = pPlayer->m_pInventoryGUI->m_nSelectedInventoryPanel;

                auto PushAndSignal = [&](std::string ev) -> bool
                {
                    Events::PushEventData("CURRENT_PANEL", std::to_string(currentPanel));
                    Events::PushEventData("SELECTED_PANEL", std::to_string(selectedPanel));

                    return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
                };

                if (PushAndSignal("NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE"))
                {
                    retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer,
                                                                                                  nMinor);
                }
                else
                {
                    auto *pMessage = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
                    if (pMessage)
                    {
                        pMessage->SendServerToPlayerInventory_SelectPanel(pPlayer->m_nPlayerID, currentPanel);
                    }

                    retVal = false;
                }

                PushAndSignal("NWNX_ON_INVENTORY_SELECT_PANEL_AFTER");
            }
            else
            {
                retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            }
            break;
        }

        default:
            retVal = m_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            break;
    }

    return retVal;
}

}
