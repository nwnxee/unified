#include "Events/InventoryEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CItemRepository.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerGuiInventoryMessageHook;
static NWNXLib::Hooking::FunctionHook* s_AddItemHook;
static NWNXLib::Hooking::FunctionHook* s_AddGoldHook;
static NWNXLib::Hooking::FunctionHook* s_RemoveGoldHook;

InventoryEvents::InventoryEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_(SELECT|OPEN)_.*", [hooker]()
    {
        s_HandlePlayerToServerGuiInventoryMessageHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN11CNWSMessage39HandlePlayerToServerGuiInventoryMessageEP10CNWSPlayerh>
            (&HandlePlayerToServerGuiInventoryMessageHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_ADD_ITEM_.*", [hooker]() {
        s_AddItemHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN15CItemRepository7AddItemEPP8CNWSItemhhii>
            (&AddItemHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_REMOVE_ITEM_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN15CItemRepository10RemoveItemEP8CNWSItem, int32_t>(&RemoveItemHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_ADD_GOLD_.*", [hooker]() {
        s_AddGoldHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature7AddGoldEii>
            (&AddGoldHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INVENTORY_REMOVE_GOLD_.*", [hooker]() {
        s_RemoveGoldHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature10RemoveGoldEii>
            (&RemoveGoldHook);
    });
}

int32_t InventoryEvents::HandlePlayerToServerGuiInventoryMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;

    if (!pPlayer)
        return s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);

    switch (nMinor)
    {
        case MessageGuiInventoryMinor::Status:
        {
            auto target = Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF;
            auto open = (bool)(Utils::PeekMessage<uint8_t>(thisPtr, 4) & 0x10);

            if (open)
            {
                auto PushAndSignal = [&](const std::string& ev) -> bool
                {
                    Events::PushEventData("TARGET_INVENTORY", Utils::ObjectIDToString(target));
                    return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
                };

                if (PushAndSignal("NWNX_ON_INVENTORY_OPEN_BEFORE"))
                {
                    retVal = s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
                }
                else
                {
                    CNWSPlayerInventoryGUI *pInventory = pPlayer->m_oidNWSObject == target ? pPlayer->m_pInventoryGUI :
                                                         pPlayer->m_pOtherInventoryGUI;

                    auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
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
                retVal = s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
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

                auto PushAndSignal = [&](const std::string& ev) -> bool
                {
                    Events::PushEventData("CURRENT_PANEL", std::to_string(currentPanel));
                    Events::PushEventData("SELECTED_PANEL", std::to_string(selectedPanel));

                    return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
                };

                if (PushAndSignal("NWNX_ON_INVENTORY_SELECT_PANEL_BEFORE"))
                {
                    retVal = s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer,
                                                                                                  nMinor);
                }
                else
                {
                    auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
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
                retVal = s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            }
            break;
        }

        default:
            retVal = s_HandlePlayerToServerGuiInventoryMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            break;
    }

    return retVal;
}

int32_t InventoryEvents::AddItemHook(CItemRepository* thisPtr, CNWSItem** ppItem, uint8_t x, uint8_t y,
                                int32_t bAllowEncumbrance, int32_t bMergeItem)
{
    int32_t retVal;

    auto *pContainer = Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent);

    // Early out if parent isn't an item or placeable or Bad Things(tm) happen
    if(!Utils::AsNWSItem(pContainer) && !Utils::AsNWSPlaceable(pContainer))
    {
        return s_AddItemHook->CallOriginal<int32_t>(thisPtr, ppItem, x, y, bAllowEncumbrance, bMergeItem);
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(ppItem && *ppItem ? (**ppItem).m_idSelf : OBJECT_INVALID));
        return Events::SignalEvent(ev, thisPtr->m_oidParent);
    };

    if (PushAndSignal("NWNX_ON_INVENTORY_ADD_ITEM_BEFORE"))
    {
        retVal = s_AddItemHook->CallOriginal<int32_t>(thisPtr, ppItem, x, y, bAllowEncumbrance, bMergeItem);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_INVENTORY_ADD_ITEM_AFTER");

    return retVal;
}

void InventoryEvents::RemoveItemHook(bool before, CItemRepository* thisPtr, CNWSItem* pItem)
{

    auto *pContainer = Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent);

    // Early out if parent isn't an item or placeable or Bad Things(tm) happen
    if(!Utils::AsNWSItem(pContainer) && !Utils::AsNWSPlaceable(pContainer))
    {
        return;
    }

    // Only a shared hook for RemoveItem because skipping it also makes Bad Things(tm) happen
    Events::PushEventData("ITEM", Utils::ObjectIDToString(pItem ? pItem->m_idSelf : OBJECT_INVALID));
    Events::SignalEvent(before ? "NWNX_ON_INVENTORY_REMOVE_ITEM_BEFORE" : "NWNX_ON_INVENTORY_REMOVE_ITEM_AFTER", thisPtr->m_oidParent);
}

void InventoryEvents::AddGoldHook(CNWSCreature *pCreature, int32_t nGold, int32_t bDisplayFeedBack)
{
    auto PushAndSignal = [&](const std::string &ev) -> bool {
        Events::PushEventData("GOLD", std::to_string(nGold));
        return Events::SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_INVENTORY_ADD_GOLD_BEFORE"))
    {
        s_AddGoldHook->CallOriginal<void>(pCreature, nGold, bDisplayFeedBack);
    }

    PushAndSignal("NWNX_ON_INVENTORY_ADD_GOLD_AFTER");
}

void InventoryEvents::RemoveGoldHook(CNWSCreature *pCreature, int32_t nGold, int32_t bDisplayFeedBack)
{
    auto PushAndSignal = [&](const std::string &ev) -> bool {
        Events::PushEventData("GOLD", std::to_string(nGold));
        return Events::SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_INVENTORY_REMOVE_GOLD_BEFORE"))
    {
        s_RemoveGoldHook->CallOriginal<void>(pCreature, nGold, bDisplayFeedBack);
    }

    PushAndSignal("NWNX_ON_INVENTORY_REMOVE_GOLD_AFTER");
}

}
