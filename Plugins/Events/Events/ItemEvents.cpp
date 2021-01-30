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
#include <cmath>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_UseItemHook;
static Hooks::Hook s_OpenInventoryHook;
static Hooks::Hook s_CloseInventoryHook;
static Hooks::Hook s_FindItemWithBaseItemIdHook;
static Hooks::Hook s_LearnScrollHook;
static Hooks::Hook s_CanEquipItemHook;
static Hooks::Hook s_RunEquipHook;
static Hooks::Hook s_RunUnequipHook;
static Hooks::Hook s_ItemEventHandlerHook;
static Hooks::Hook s_UseLoreOnItemHook;
static Hooks::Hook s_PayToIdenfifyItemHook;
static Hooks::Hook s_SplitItemHook;
static Hooks::Hook s_CanUseItemHook;
static Hooks::Hook s_AcquireItemHook;

ItemEvents::ItemEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_VALIDATE_USE_ITEM_.*", []() {
        s_CanUseItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature10CanUseItemEP8CNWSItemi,
                                        (void*)&CanUseItemHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_USE_ITEM_.*", []() {
        s_UseItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature7UseItemEjhhj6Vectorji,
                                     (void*)&UseItemHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_OPEN_.*", []() {
        s_OpenInventoryHook = Hooks::HookFunction(API::Functions::_ZN8CNWSItem13OpenInventoryEj,
                                           (void*)&OpenInventoryHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_INVENTORY_CLOSE_.*", []() {
        s_CloseInventoryHook = Hooks::HookFunction(API::Functions::_ZN8CNWSItem14CloseInventoryEji,
                                            (void*)&CloseInventoryHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_AMMO_RELOAD_.*", []() {
        s_FindItemWithBaseItemIdHook = Hooks::HookFunction(API::Functions::_ZN15CItemRepository22FindItemWithBaseItemIdEji,
                                                    (void*)&FindItemWithBaseItemIdHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_SCROLL_LEARN_.*", []() {
        s_LearnScrollHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature11LearnScrollEj,
                                         (void*)&LearnScrollHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_VALIDATE_ITEM_EQUIP_.*", []() {
        s_CanEquipItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature12CanEquipItemEP8CNWSItemPjiiiP10CNWSPlayer,
                                          (void*)&CanEquipItemHook, Hooks::Order::Early);
        });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_EQUIP_.*", []() {
        s_RunEquipHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature8RunEquipEjjj,
                                      (void*)&RunEquipHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_UNEQUIP_.*", []() {
        s_RunUnequipHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature10RunUnequipEjjhhij,
                                        (void*)&RunUnequipHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_(DESTROY_OBJECT|DECREMENT_STACKSIZE)_.*", []() {
        s_ItemEventHandlerHook = Hooks::HookFunction(API::Functions::_ZN8CNWSItem12EventHandlerEjjPvjj,
                                              (void*)&ItemEventHandlerHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_USE_LORE_.*", []() {
        s_UseLoreOnItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature13UseLoreOnItemEj,
                                           (void*)&UseLoreOnItemHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_PAY_TO_IDENTIFY_.*", []() {
        s_PayToIdenfifyItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature17PayToIdentifyItemEjj,
                                               (void*)&PayToIdentifyItemHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_SPLIT_.*", []() {
        s_SplitItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature9SplitItemEP8CNWSItemi,
                                       (void*)&SplitItemHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_ITEM_ACQUIRE_.*", []() {
        s_AcquireItemHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature11AcquireItemEPP8CNWSItemjjhhii,
                                         (void*)&AcquireItemHook, Hooks::Order::Early);
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
        ? s_CanUseItemHook->CallOriginal<int32_t>(thisPtr, pItem, bIgnoreIdentifiedFlag) : sBeforeEventResult == "1";

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("BEFORE_RESULT", std::to_string(retVal));
    Events::SignalEvent("NWNX_ON_VALIDATE_USE_ITEM_AFTER", thisPtr->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : sAfterEventResult == "1";

    return retVal;
}

int32_t ItemEvents::UseItemHook(CNWSCreature* thisPtr, ObjectID oidItem, uint8_t nActivePropertyIndex, uint8_t nSubPropertyIndex,
                                ObjectID oidTarget, Vector vTargetPosition, ObjectID oidArea, int32_t bUseCharges)
{
    int32_t retVal;
    std::string result;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(oidItem));
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(nActivePropertyIndex));
        Events::PushEventData("ITEM_SUB_PROPERTY_INDEX", std::to_string(nSubPropertyIndex));
        Events::PushEventData("TARGET_POSITION_X", std::to_string(vTargetPosition.x));
        Events::PushEventData("TARGET_POSITION_Y", std::to_string(vTargetPosition.y));
        Events::PushEventData("TARGET_POSITION_Z", std::to_string(vTargetPosition.z));
        Events::PushEventData("USE_CHARGES",       std::to_string(bUseCharges));
        return Events::SignalEvent(ev, thisPtr->m_idSelf, &result);
    };

    if (PushAndSignal("NWNX_ON_USE_ITEM_BEFORE"))
    {
        retVal = s_UseItemHook->CallOriginal<int32_t>(thisPtr, oidItem, nActivePropertyIndex, nSubPropertyIndex, oidTarget, vTargetPosition, oidArea, bUseCharges);
    }
    else
    {
        retVal = atoi(result.c_str()) == 1;
    }

    PushAndSignal("NWNX_ON_USE_ITEM_AFTER");

    return retVal;
}

void ItemEvents::OpenInventoryHook(CNWSItem* thisPtr, ObjectID oidOpener)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("OWNER", Utils::ObjectIDToString(oidOpener));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_INVENTORY_OPEN_BEFORE"))
    {
        s_OpenInventoryHook->CallOriginal<void>(thisPtr, oidOpener);
    }

    PushAndSignal("NWNX_ON_ITEM_INVENTORY_OPEN_AFTER");
}

void ItemEvents::CloseInventoryHook(CNWSItem* thisPtr, ObjectID oidCloser, int32_t bUpdatePlayer)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("OWNER", Utils::ObjectIDToString(oidCloser));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_INVENTORY_CLOSE_BEFORE"))
    {
        s_CloseInventoryHook->CallOriginal<void>(thisPtr, oidCloser, bUpdatePlayer);
    }

    PushAndSignal("NWNX_ON_ITEM_INVENTORY_CLOSE_AFTER");
}

ObjectID ItemEvents::FindItemWithBaseItemIdHook(CItemRepository* thisPtr, uint32_t nBaseItemId, int32_t nTh)
{
    // This event hook is currently only used for Ammunition Reloading but could in the future be used for more
    if ((nBaseItemId != Constants::BaseItem::Arrow &&
         nBaseItemId != Constants::BaseItem::Bolt &&
         nBaseItemId != Constants::BaseItem::Bullet))
    {
        return s_FindItemWithBaseItemIdHook->CallOriginal<int32_t>(thisPtr, nBaseItemId, nTh);
    }

    auto *pItemHolder = Utils::AsNWSCreature(Globals::AppManager()->m_pServerExoApp->GetGameObject(thisPtr->m_oidParent));

    if(!pItemHolder)
    {
        // For our purposes we only want this to be used on creature ItemRepositories
        return s_FindItemWithBaseItemIdHook->CallOriginal<int32_t>(thisPtr, nBaseItemId, nTh);
    }

    // We're most assuredly in an infinite loop here caused by the scripting end
    // unless the player has > 255 stacks of ammo they can't equip
    // Suppose I could set this to a higher value but I think this is safe
    if(nTh > 255)
        return OBJECT_INVALID;

    auto ItemSanityCheck = [&](uint32_t objectId) -> bool {
        if (static_cast<ObjectID>(objectId) == Constants::OBJECT_INVALID)
            return true;

        auto *pItem = Utils::AsNWSItem(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId));
        if (!pItem)
        {
            LOG_WARNING("Item does not exist, falling back to original call.");
            return false;
        }
        else if (pItem->m_nBaseItem != nBaseItemId)
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

    Events::PushEventData("BASE_ITEM_ID", std::to_string(nBaseItemId));
    Events::PushEventData("BASE_ITEM_NTH", std::to_string(nTh));

    if (Events::SignalEvent("NWNX_ON_ITEM_AMMO_RELOAD_BEFORE", thisPtr->m_oidParent, &sBeforeEventResult))
    {
        retVal = s_FindItemWithBaseItemIdHook->CallOriginal<uint32_t>(thisPtr, nBaseItemId, nTh);
    }
    else
    {
        if (!sBeforeEventResult.empty())
        {
            retVal = stoul(sBeforeEventResult, nullptr, 16);
            if (ItemSanityCheck(retVal))
                return retVal;
        }
        retVal = s_FindItemWithBaseItemIdHook->CallOriginal<uint32_t>(thisPtr, nBaseItemId, nTh);
    }

    Events::PushEventData("BASE_ITEM_ID", std::to_string(nBaseItemId));
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

int32_t ItemEvents::LearnScrollHook(CNWSCreature *thisPtr, ObjectID oidScrollToLearn)
{
    int32_t retVal = false;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("RESULT", std::to_string(retVal));
        Events::PushEventData("SCROLL", Utils::ObjectIDToString(oidScrollToLearn));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_SCROLL_LEARN_BEFORE"))
    {
        retVal = s_LearnScrollHook->CallOriginal<int32_t>(thisPtr, oidScrollToLearn);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_ITEM_SCROLL_LEARN_AFTER");

    return retVal;
}

int32_t ItemEvents::CanEquipItemHook(CNWSCreature *thisPtr, CNWSItem *pItem, uint32_t *pEquipToSlot, int32_t bEquipping,
                                     int32_t bLoading, int32_t bDisplayFeedback, CNWSPlayer* pFeedbackPlayer)
{
    int32_t retVal;
    std::string sBeforeEventResult;
    std::string sAfterEventResult;

    std::string itemId = Utils::ObjectIDToString(pItem->m_idSelf);
    std::string invSlot = std::to_string((uint32_t) std::round(log2(*pEquipToSlot)));

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("SLOT", invSlot);

    retVal = Events::SignalEvent("NWNX_ON_VALIDATE_ITEM_EQUIP_BEFORE", thisPtr->m_idSelf, &sBeforeEventResult)
        ? s_CanEquipItemHook->CallOriginal<int32_t>(thisPtr, pItem, pEquipToSlot, bEquipping, bLoading, bDisplayFeedback, pFeedbackPlayer) : sBeforeEventResult == "1";

    Events::PushEventData("ITEM_OBJECT_ID", itemId);
    Events::PushEventData("SLOT", invSlot);
    Events::PushEventData("BEFORE_RESULT", std::to_string(retVal));
    Events::SignalEvent("NWNX_ON_VALIDATE_ITEM_EQUIP_AFTER", thisPtr->m_idSelf, &sAfterEventResult);

    retVal = sAfterEventResult.empty() ? retVal : std::stoi(sAfterEventResult);

    return retVal;
}

int32_t ItemEvents::RunEquipHook(CNWSCreature* thisPtr, ObjectID oidItemToEquip, uint32_t nInventorySlot, ObjectID oidFeedbackPlayer)
{
    int32_t retVal;
    uint8_t slotId = 0;
    uint32_t slot = nInventorySlot;
    while (slot >>= 1) { slotId++; }
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItemToEquip));
        Events::PushEventData("SLOT", std::to_string(slotId));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_EQUIP_BEFORE"))
    {
        retVal = s_RunEquipHook->CallOriginal<int32_t>(thisPtr, oidItemToEquip, nInventorySlot, oidFeedbackPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_EQUIP_AFTER");

    return retVal;
}

int32_t ItemEvents::RunUnequipHook(CNWSCreature* thisPtr, ObjectID oidItemToUnequip, ObjectID oidTargetRepository, uint8_t x,
                                   uint8_t y, int32_t bMergeIntoRepository, ObjectID oidFeedbackPlayer )
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItemToUnequip));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_UNEQUIP_BEFORE"))
    {
        retVal = s_RunUnequipHook->CallOriginal<int32_t>(thisPtr, oidItemToUnequip, oidTargetRepository, x, y, bMergeIntoRepository , oidFeedbackPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_UNEQUIP_AFTER");

    return retVal;
}

// hooks into CNWSItem::EventHandler
void ItemEvents::ItemEventHandlerHook(CNWSItem* thisPtr, uint32_t nEventId, ObjectID nCallerObjectId, void *pScript,
                                      uint32_t nCalendarDay, uint32_t nTimeOfDay)
{
    auto CallOriginal = [&]() -> void {
        s_ItemEventHandlerHook->CallOriginal<void>(thisPtr, nEventId, nCallerObjectId, pScript, nCalendarDay, nTimeOfDay);
    };

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        //Events::PushEventData("EVENT_ID", std::to_string(nEventId));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    auto HandleHookableEvent = [&](const std::string& eventName) -> void {
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

int32_t ItemEvents::UseLoreOnItemHook(CNWSCreature *thisPtr, ObjectID oidItem)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItem));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_USE_LORE_BEFORE"))
    {
        retVal = s_UseLoreOnItemHook->CallOriginal<int32_t>(thisPtr, oidItem);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_ITEM_USE_LORE_AFTER");

    return retVal;
}

void ItemEvents::PayToIdentifyItemHook(CNWSCreature *thisPtr, ObjectID oidItem, ObjectID oidStore )
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItem));
        Events::PushEventData("STORE", Utils::ObjectIDToString(oidStore ));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_PAY_TO_IDENTIFY_BEFORE"))
    {
        s_PayToIdenfifyItemHook->CallOriginal<int32_t>(thisPtr, oidItem, oidStore );
    }

    PushAndSignal("NWNX_ON_ITEM_PAY_TO_IDENTIFY_AFTER");
}

void ItemEvents::SplitItemHook(CNWSCreature *thisPtr, CNWSItem *pItemToSplit, int32_t nNumberToSplitOff)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(pItemToSplit->m_idSelf));
        Events::PushEventData("NUMBER_SPLIT_OFF", std::to_string(nNumberToSplitOff));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_SPLIT_BEFORE"))
    {
        s_SplitItemHook->CallOriginal<void>(thisPtr, pItemToSplit, nNumberToSplitOff);
    }

    PushAndSignal("NWNX_ON_ITEM_SPLIT_AFTER");
}

int32_t ItemEvents::AcquireItemHook(CNWSCreature* thisPtr, CNWSItem **ppItem, ObjectID oidPossessor,
                                    ObjectID oidTargetRepository, uint8_t x, uint8_t y, int32_t bOriginatingFromScript, int32_t bDisplayFeedback)
{
    int32_t retVal = false;

    if (!ppItem || !(*ppItem))
        return s_AcquireItemHook->CallOriginal<int32_t>(thisPtr, ppItem, oidPossessor, oidTargetRepository, x, y, bOriginatingFromScript, bDisplayFeedback);

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        ObjectID oidItem = (*ppItem) != nullptr ? (*ppItem)->m_idSelf : Constants::OBJECT_INVALID;

        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItem));
        Events::PushEventData("GIVER", Utils::ObjectIDToString(oidPossessor));
        Events::PushEventData("RESULT", std::to_string(retVal));
        return Events::SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ITEM_ACQUIRE_BEFORE"))
    {
        retVal = s_AcquireItemHook->CallOriginal<int32_t>(thisPtr, ppItem, oidPossessor, oidTargetRepository, x, y, bOriginatingFromScript, bDisplayFeedback);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_ITEM_ACQUIRE_AFTER");

    return retVal;
}

}
