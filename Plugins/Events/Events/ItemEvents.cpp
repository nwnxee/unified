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
#include <cmath>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooking::FunctionHook* m_UseItemHook = nullptr;
static Hooking::FunctionHook* m_OpenInventoryHook = nullptr;
static Hooking::FunctionHook* m_CloseInventoryHook = nullptr;
static Hooking::FunctionHook* m_FindItemWithBaseItemIdHook = nullptr;
static Hooking::FunctionHook* m_LearnScrollHook = nullptr;
static Hooking::FunctionHook* m_CanEquipItemHook = nullptr;
static Hooking::FunctionHook* m_RunEquipHook = nullptr;
static Hooking::FunctionHook* m_RunUnequipHook = nullptr;
static Hooking::FunctionHook* m_ItemEventHandlerHook = nullptr;
static Hooking::FunctionHook* m_UseLoreOnItemHook = nullptr;
static Hooking::FunctionHook* m_PayToIdenfifyItemHook = nullptr;
static Hooking::FunctionHook* m_SplitItemHook = nullptr;
static Hooking::FunctionHook* m_CanUseItemHook = nullptr;

ItemEvents::ItemEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_VALIDATE_USE_ITEM_.*", [hooker]() {
            hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature10CanUseItemEP8CNWSItemi>(&CanUseItemHook);
        m_CanUseItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature10CanUseItemEP8CNWSItemi);
        });

    Events::InitOnFirstSubscribe("NWNX_ON_USE_ITEM_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature7UseItemEjhhj6Vectorj>(&UseItemHook);
        m_UseItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature7UseItemEjhhj6Vectorj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_OPEN_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN8CNWSItem13OpenInventoryEj>(&OpenInventoryHook);
        m_OpenInventoryHook = hooker->FindHookByAddress(API::Functions::_ZN8CNWSItem13OpenInventoryEj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_CLOSE_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN8CNWSItem14CloseInventoryEji>(&CloseInventoryHook);
        m_CloseInventoryHook = hooker->FindHookByAddress(API::Functions::_ZN8CNWSItem14CloseInventoryEji);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_AMMO_RELOAD_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN15CItemRepository22FindItemWithBaseItemIdEji>(&FindItemWithBaseItemIdHook);
        m_FindItemWithBaseItemIdHook = hooker->FindHookByAddress(API::Functions::_ZN15CItemRepository22FindItemWithBaseItemIdEji);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_SCROLL_LEARN_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature11LearnScrollEj>(&LearnScrollHook);
        m_LearnScrollHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature11LearnScrollEj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_VALIDATE_ITEM_EQUIP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature12CanEquipItemEP8CNWSItemPjiiiP10CNWSPlayer>(&CanEquipItemHook);
        m_CanEquipItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature12CanEquipItemEP8CNWSItemPjiiiP10CNWSPlayer);
        });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_EQUIP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature8RunEquipEjjj>(&RunEquipHook);
        m_RunEquipHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature8RunEquipEjjj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_UNEQUIP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature10RunUnequipEjjhhij>(&RunUnequipHook);
        m_RunUnequipHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature10RunUnequipEjjhhij);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_(DESTROY_OBJECT|DECREMENT_STACKSIZE)_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN8CNWSItem12EventHandlerEjjPvjj>(&ItemEventHandlerHook);
        m_ItemEventHandlerHook = hooker->FindHookByAddress(API::Functions::_ZN8CNWSItem12EventHandlerEjjPvjj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_USE_LORE_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature13UseLoreOnItemEj>(&UseLoreOnItemHook);
        m_UseLoreOnItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature13UseLoreOnItemEj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_PAY_TO_IDENTIFY_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature17PayToIdentifyItemEjj>(&PayToIdentifyItemHook);
        m_PayToIdenfifyItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature17PayToIdentifyItemEjj);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_SPLIT_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature9SplitItemEP8CNWSItemi>(&SplitItemHook);
        m_SplitItemHook = hooker->FindHookByAddress(API::Functions::_ZN12CNWSCreature9SplitItemEP8CNWSItemi);
    });
}

int32_t ItemEvents::CanUseItemHook(CNWSCreature* thisPtr, CNWSItem* pItem, int32_t bIgnoreIdentifiedFlag)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    std::string itemId = Utils::ObjectIDToString(pItem->m_idSelf);

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    retVal = Events::SignalEvent("NWNX_ON_VALIDATE_USE_ITEM_BEFORE", thisPtr->m_idSelf, &sBeforeEventResult)
        ? m_CanUseItemHook->CallOriginal<int32_t>(thisPtr, pItem, bIgnoreIdentifiedFlag) : sBeforeEventResult == "1";

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("BEFORE_RESULT", std::to_string(retVal));
    Events::SignalEvent("NWNX_ON_VALIDATE_USE_ITEM_AFTER", thisPtr->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

int32_t ItemEvents::UseItemHook(
    CNWSCreature* thisPtr,
    API::Types::ObjectID item,
    uint8_t propIndex,
    uint8_t subPropIndex,
    API::Types::ObjectID target,
    Vector targetPosition,
    API::Types::ObjectID area)
{
    int32_t retVal;
    std::string result;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(item));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
        Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(propIndex));
        Events::PushEventData("ITEM_SUB_PROPERTY_INDEX", std::to_string(subPropIndex));
        Events::PushEventData("TARGET_POSITION_X", std::to_string(targetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(targetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(targetPosition.z));
    return Events::SignalEvent(ev, thisPtr->m_idSelf, &result);
    };

    if (PushAndSignal("NWNX_ON_USE_ITEM_BEFORE"))
    {
        retVal = m_UseItemHook->CallOriginal<int32_t>(thisPtr, item, propIndex, subPropIndex, target, targetPosition, area);
    }
    else
    {
        retVal = atoi(result.c_str()) == 1;
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

int32_t ItemEvents::CanEquipItemHook(CNWSCreature* thisPtr, CNWSItem* pItem, uint32_t* pEquipToSlot, int32_t bEquipping, int32_t bLoading, int32_t bDisplayFeedback, CNWSPlayer* pFeedbackPlayer)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    std::string itemId = Utils::ObjectIDToString(pItem->m_idSelf);
    std::string invSlot = std::to_string((uint32_t) std::round(log2(*pEquipToSlot)));

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("SLOT", invSlot);

    retVal = Events::SignalEvent("NWNX_ON_VALIDATE_ITEM_EQUIP_BEFORE", thisPtr->m_idSelf, &sBeforeEventResult)
        ? m_CanEquipItemHook->CallOriginal<int32_t>(thisPtr, pItem, pEquipToSlot, bEquipping, bLoading, bDisplayFeedback, pFeedbackPlayer) : sBeforeEventResult == "1";

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("SLOT", invSlot);
    Events::PushEventData("BEFORE_RESULT", std::to_string(retVal));
    Events::SignalEvent("NWNX_ON_VALIDATE_ITEM_EQUIP_AFTER", thisPtr->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

int32_t ItemEvents::RunEquipHook(
        CNWSCreature* thisPtr,
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
        CNWSCreature* thisPtr,
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
        CNWSItem* thisPtr,
        uint32_t nEventId,
        NWNXLib::API::Types::ObjectID nCallerObjectId,
        void *pScript,
        uint32_t nCalendarDay,
        uint32_t nTimeOfDay)
{
    auto CallOriginal = [&]() -> void {
        m_ItemEventHandlerHook->CallOriginal<void>(thisPtr, nEventId, nCallerObjectId, pScript, nCalendarDay, nTimeOfDay);
    };

    auto PushAndSignal = [&](std::string ev) -> bool {
        //Events::PushEventData("EVENT_ID", std::to_string(nEventId));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    auto HandleHookableEvent = [&](std::string eventName) -> void {
        if (PushAndSignal("NWNX_ON_ITEM_" + eventName + "_BEFORE"))
        {
            CallOriginal();
        }
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
            break;
    }
}

int32_t ItemEvents::UseLoreOnItemHook(CNWSCreature *thisPtr, Types::ObjectID item)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(item));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_USE_LORE_BEFORE"))
    {
        retVal = m_UseLoreOnItemHook->CallOriginal<int32_t>(thisPtr, item);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_USE_LORE_AFTER");

    return retVal;
}

void ItemEvents::PayToIdentifyItemHook(CNWSCreature *thisPtr, Types::ObjectID item, Types::ObjectID store)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(item));
        Events::PushEventData("STORE", Utils::ObjectIDToString(store));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE"))
    {
        m_PayToIdenfifyItemHook->CallOriginal<int32_t>(thisPtr, item, store);
    }

    PushAndSignal("NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER");
}

void ItemEvents::SplitItemHook(CNWSCreature *thisPtr, CNWSItem *pItem, int32_t nNumberToSplitOff)
{
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(pItem->m_idSelf));
        Events::PushEventData("NUMBER_SPLIT_OFF", std::to_string(nNumberToSplitOff));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_SPLIT_BEFORE"))
    {
        m_SplitItemHook->CallOriginal<void>(thisPtr, pItem, nNumberToSplitOff);
    }

    PushAndSignal("NWNX_ON_ITEM_SPLIT_AFTER");
}

}
