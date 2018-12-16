#include "Events/ItemEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* m_UseItemHook = nullptr;

ItemEvents::ItemEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<API::Functions::CNWSCreature__UseItem, int32_t, API::CNWSCreature*, API::Types::ObjectID, uint8_t,
        uint8_t, API::Types::ObjectID, API::Vector, API::Types::ObjectID>(&UseItemHook);

    m_UseItemHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__UseItem);
}

void ItemEvents::UseItemHook(
    Services::Hooks::CallType type, 
    API::CNWSCreature* thisPtr, 
    API::Types::ObjectID item, 
    uint8_t propIndex,
    uint8_t unusedInt,
    API::Types::ObjectID target, 
    API::Vector unusedVector, 
    API::Types::ObjectID unusedObjectId)
{
    //const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(item));
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(propIndex));
    
    if (Events::SignalEvent("NWNX_ON_USE_ITEM_BEFORE", thisPtr->m_idSelf))
    {
        LOG_ERROR("Calling Original");
        m_UseItemHook->CallOriginal<void>(thisPtr, item, propIndex, unusedInt, target, unusedVector, unusedObjectId);
    }

    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(item));
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(target));
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(propIndex));

    Events::SignalEvent("NWNX_ON_USE_ITEM_AFTER", thisPtr->m_idSelf);

    //Events::SignalEvent(before ? "NWNX_ON_USE_ITEM_BEFORE" : "NWNX_ON_USE_ITEM_AFTER", thisPtr->m_idSelf);
}

}
