#include "Events/ItemEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/CNWSItem.hpp"
#include "API/CItemRepository.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooking::FunctionHook* m_UseItemHook = nullptr;
static Hooking::FunctionHook* m_OpenInventoryHook = nullptr;
static Hooking::FunctionHook* m_CloseInventoryHook = nullptr;
static Hooking::FunctionHook* m_AddItemHook = nullptr;
static Hooking::FunctionHook* m_FindItemWithBaseItemIdHook = nullptr;
static Hooking::FunctionHook* m_LearnScrollHook = nullptr;
static Hooking::FunctionHook* m_RunEquipHook = nullptr;
static Hooking::FunctionHook* m_RunUnequipHook = nullptr;
static Hooking::FunctionHook* m_ItemEventHandlerHook = nullptr;

ItemEvents::ItemEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_USE_ITEM_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__UseItem>(&UseItemHook);
        m_UseItemHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__UseItem);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_OPEN_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSItem__OpenInventory>(&OpenInventoryHook);
        m_OpenInventoryHook = hooker->FindHookByAddress(API::Functions::CNWSItem__OpenInventory);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_CLOSE_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSItem__CloseInventory>(&CloseInventoryHook);
        m_CloseInventoryHook = hooker->FindHookByAddress(API::Functions::CNWSItem__CloseInventory);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_ADD_ITEM_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CItemRepository__AddItem>(&AddItemHook);
        m_AddItemHook = hooker->FindHookByAddress(API::Functions::CItemRepository__AddItem);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CItemRepository__RemoveItem, int32_t>(&RemoveItemHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_AMMO_RELOAD_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CItemRepository__FindItemWithBaseItemId>(&FindItemWithBaseItemIdHook);
        m_FindItemWithBaseItemIdHook = hooker->FindHookByAddress(API::Functions::CItemRepository__FindItemWithBaseItemId);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_SCROLL_LEARN_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__LearnScroll>(&LearnScrollHook);
        m_LearnScrollHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__LearnScroll);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_EQUIP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__RunEquip>(&RunEquipHook);
        m_RunEquipHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__RunEquip);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_UNEQUIP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__RunUnequip>(&RunUnequipHook);
        m_RunUnequipHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__RunUnequip);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_(DESTROY_OBJECT|DECREMENT_STACKSIZE)_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSItem__EventHandler>(&ItemEventHandlerHook);
        m_ItemEventHandlerHook = hooker->FindHookByAddress(API::Functions::CNWSItem__EventHandler);
    });
}

int32_t ItemEvents::UseItemHook(
    API::CNWSCreature* thisPtr,
    API::Types::ObjectID item,
    uint8_t propIndex,
    uint8_t subPropIndex,
    API::Types::ObjectID target,
    API::Vector targetPosition,
    API::Types::ObjectID area)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(item));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
        Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(propIndex));
        Events::PushEventData("ITEM_SUB_PROPERTY_INDEX", std::to_string(subPropIndex));
        Events::PushEventData("TARGET_POSITION_X", std::to_string(targetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(targetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(targetPosition.z));
    return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_USE_ITEM_BEFORE"))
    {
        retVal = m_UseItemHook->CallOriginal<int32_t>(thisPtr, item, propIndex, subPropIndex, target, targetPosition, area);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_USE_ITEM_AFTER");

    return retVal;
}

void ItemEvents::OpenInventoryHook(CNWSItem* thisPtr, Types::ObjectID oidOpener)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("OWNER", Utils::ObjectIDToString(oidOpener));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE"))
    {
        m_OpenInventoryHook->CallOriginal<void>(thisPtr, oidOpener);
    }

    PushAndSignal("NWNX_ON_ITEM_INVENTORY_OPEN_AFTER");
}

void ItemEvents::CloseInventoryHook(CNWSItem* thisPtr, Types::ObjectID oidCloser, int32_t bUpdatePlayer)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("OWNER", Utils::ObjectIDToString(oidCloser));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE"))
    {
        m_CloseInventoryHook->CallOriginal<void>(thisPtr, oidCloser, bUpdatePlayer);
    }

    PushAndSignal("NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER");
}

int32_t ItemEvents::AddItemHook(CItemRepository* thisPtr, CNWSItem** ppItem, uint8_t x, uint8_t y,
                                int32_t bAllowEncumbrance, int32_t bMergeItem)
{
    int32_t retVal;
    auto *pItemContainer = Utils::AsNWSItem(Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent));

    if(!pItemContainer)
    {// Early out if parent isn't an item or Bad Things(tm) happen
        return m_AddItemHook->CallOriginal<int32_t>(thisPtr, ppItem, x, y, bAllowEncumbrance, bMergeItem);
    }

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(ppItem && *ppItem ? (**ppItem).m_idSelf : OBJECT_INVALID));
        return Events::SignalEvent(ev, thisPtr->m_oidParent);
    };

    if (PushAndSignal("NWNX_ON_ITEM_INVENTORY_ADD_ITEM_BEFORE"))
    {
        retVal = m_AddItemHook->CallOriginal<int32_t>(thisPtr, ppItem, x, y, bAllowEncumbrance, bMergeItem);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_ITEM_INVENTORY_ADD_ITEM_AFTER");

    return retVal;
}

void ItemEvents::RemoveItemHook(Services::Hooks::CallType type, CItemRepository* thisPtr, CNWSItem* pItem)
{
    auto *pItemContainer = Utils::AsNWSItem(Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent));

    if(!pItemContainer)
    {// Early out if parent isn't an item or Bad Things(tm) happen
        return;
    }

    // Only a shared hook for RemoveItem because skipping it also makes Bad Things(tm) happen
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    Events::PushEventData("ITEM", Utils::ObjectIDToString(pItem ? pItem->m_idSelf : OBJECT_INVALID));
    Events::SignalEvent(before ? "NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_BEFORE" : "NWNX_ON_ITEM_INVENTORY_REMOVE_ITEM_AFTER", thisPtr->m_oidParent);
}

uint32_t ItemEvents::FindItemWithBaseItemIdHook(CItemRepository* thisPtr, uint32_t baseItem, int32_t nTh)
{

    // This event hook is currently only used for Ammunition Reloading but could in the future be used for more
    if ((baseItem != Constants::BaseItem::Arrow &&
         baseItem != Constants::BaseItem::Bolt &&
         baseItem != Constants::BaseItem::Bullet))
    {
        return m_FindItemWithBaseItemIdHook->CallOriginal<int32_t>(thisPtr, baseItem, nTh);
    }

    auto *pItemHolder = Utils::AsNWSCreature(Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent));

    if(!pItemHolder)
    {
        // For our purposes we only want this to be used on creature ItemRepositories
        return m_FindItemWithBaseItemIdHook->CallOriginal<int32_t>(thisPtr, baseItem, nTh);
    }

    // We're most assuredly in an infinite loop here caused by the scripting end
    // unless the player has > 255 stacks of ammo they can't equip
    // Suppose I could set this to a higher value but I think this is safe
    if(nTh > 255)
        return OBJECT_INVALID;

    auto ItemSanityCheck = [&](uint32_t objectId) -> bool {
        if (static_cast<Types::ObjectID>(objectId) == Constants::OBJECT_INVALID)
            return true;

        auto *pItem = Utils::AsNWSItem(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId));
        if (!pItem)
        {
            LOG_WARNING("Item does not exist, falling back to original call.");
            return false;
        }
        else if (pItem->m_nBaseItem != baseItem)
        {
            LOG_WARNING("Base Item ID of returned item does not match, falling back to original call.");
            return false;
        }
        else if (pItem->m_oidPossessor != thisPtr->m_oidParent)
        {
            LOG_WARNING("Item does not belong to that creature, falling back to original call.");
            return false;
        }
        return true;
    };

    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    uint32_t retVal;

    Events::PushEventData("BASE_ITEM_ID", std::to_string(baseItem));
    Events::PushEventData("BASE_ITEM_NTH", std::to_string(nTh));

    if (Events::SignalEvent("NWNX_ON_ITEM_AMMO_RELOAD_BEFORE", thisPtr->m_oidParent, &sBeforeEventResult))
    {
        retVal = m_FindItemWithBaseItemIdHook->CallOriginal<uint32_t>(thisPtr, baseItem, nTh);
    }
    else
    {
        if (!sBeforeEventResult.empty())
        {
            retVal = stoul(sBeforeEventResult, nullptr, 16);
            if (ItemSanityCheck(retVal))
                return retVal;
        }
        retVal = m_FindItemWithBaseItemIdHook->CallOriginal<uint32_t>(thisPtr, baseItem, nTh);
    }

    Events::PushEventData("BASE_ITEM_ID", std::to_string(baseItem));
    Events::PushEventData("BASE_ITEM_NTH", std::to_string(nTh));
    Events::PushEventData("ACTION_RESULT", Utils::ObjectIDToString(retVal));

    if (Events::SignalEvent("NWNX_ON_ITEM_AMMO_RELOAD_AFTER", thisPtr->m_oidParent, &sAfterEventResult))
    {
        if (!sAfterEventResult.empty())
        {
            uint32_t result = stoul(sAfterEventResult, nullptr, 16);
            if (ItemSanityCheck(result))
                return result;
        }
    }

    return retVal;
}

int32_t ItemEvents::LearnScrollHook(CNWSCreature *thisPtr, Types::ObjectID oidScrollToLearn)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("SCROLL", Utils::ObjectIDToString(oidScrollToLearn));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_SCROLL_LEARN_BEFORE"))
    {
        retVal = m_LearnScrollHook->CallOriginal<int32_t>(thisPtr, oidScrollToLearn);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_ITEM_SCROLL_LEARN_AFTER");

    return retVal;
}

int32_t ItemEvents::RunEquipHook(
        API::CNWSCreature* thisPtr,
        API::Types::ObjectID item,
        uint32_t nInventorySlot,
        uint32_t oidFeedbackPlayer)
{
    int32_t retVal;
    uint8_t slotId = 0;
    uint32_t slot = nInventorySlot;
    while (slot >>= 1) { slotId++; }
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(item));
        Events::PushEventData("SLOT", std::to_string(slotId));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_EQUIP_BEFORE"))
    {
        retVal = m_RunEquipHook->CallOriginal<int32_t>(thisPtr, item, nInventorySlot, oidFeedbackPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_EQUIP_AFTER");
    return retVal;
}

int32_t ItemEvents::RunUnequipHook(
        API::CNWSCreature* thisPtr,
        API::Types::ObjectID item,
        API::Types::ObjectID itemRepo,
        uint8_t x,
        uint8_t y,
        int32_t mergeIntoRepo,
        uint32_t oidFeedbackPlayer)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(item));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_UNEQUIP_BEFORE"))
    {
        retVal = m_RunUnequipHook->CallOriginal<int32_t>(thisPtr, item, itemRepo, x, y, mergeIntoRepo, oidFeedbackPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_UNEQUIP_AFTER");

    return retVal;
}

// hooks into CNWSItem::EventHandler
void ItemEvents::ItemEventHandlerHook(
        API::CNWSItem* thisPtr,
        uint32_t nEventId,
        NWNXLib::API::Types::ObjectID nCallerObjectId,
        void *pScript,
        uint32_t nCalendarDay,
        uint32_t nTimeOfDay)
{
    auto CallOriginal = [&]() -> void {
        m_ItemEventHandlerHook->CallOriginal<int32_t>(thisPtr, nEventId, nCallerObjectId, pScript, nCalendarDay, nTimeOfDay);
    };
    auto PushAndSignal = [&](std::string ev) -> bool {
        //Events::PushEventData("EVENT_ID", std::to_string(nEventId));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };
    auto HandleHookableEvent = [&](std::string eventName) -> void {
        if (PushAndSignal("NWNX_ON_ITEM_" + eventName + "_BEFORE"))
            CallOriginal();
        PushAndSignal("NWNX_ON_ITEM_" + eventName + "_AFTER");
    };
    switch(nEventId)
    {
        case 11:
            HandleHookableEvent("DESTROY_OBJECT");
            break;
        case 16:
            HandleHookableEvent("DECREMENT_STACKSIZE");
            break;
        default:
            CallOriginal();
    }
}

}
