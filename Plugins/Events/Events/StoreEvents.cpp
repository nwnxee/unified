#include "Events/StoreEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSStore.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* s_RequestBuyHook;
static NWNXLib::Hooking::FunctionHook* s_RequestSellHook;

StoreEvents::StoreEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_STORE_REQUEST_BUY_.*", [hooker]() {
        s_RequestBuyHook = hooker->Hook(API::Functions::_ZN12CNWSCreature10RequestBuyEjjj, (void*)&RequestBuyHook, Hooking::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_STORE_REQUEST_SELL_.*", [hooker]() {
        s_RequestSellHook = hooker->Hook(API::Functions::_ZN12CNWSCreature11RequestSellEjj, (void*)&RequestSellHook, Hooking::Order::Early);
    });
}

int32_t StoreEvents::RequestBuyHook(CNWSCreature *pCreature, ObjectID oidItemToBuy, ObjectID oidStore, ObjectID oidDesiredRepository)
{
    int32_t retVal;
    int32_t price = 0;

    auto *pStore = Utils::AsNWSStore(Utils::GetGameObject(oidStore));
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItemToBuy));

    if (pStore && pItem)
        price = pStore->CalculateItemSellPrice(pItem, pCreature->m_idSelf);

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItemToBuy));
        Events::PushEventData("STORE", Utils::ObjectIDToString(oidStore));
        Events::PushEventData("PRICE", std::to_string(price));
        return Events::SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_STORE_REQUEST_BUY_BEFORE"))
        retVal = s_RequestBuyHook->CallOriginal<int32_t>(pCreature, oidItemToBuy, oidStore, oidDesiredRepository);
    else
        retVal = false;

    Events::PushEventData("RESULT", std::to_string(retVal));
    PushAndSignalEvent("NWNX_ON_STORE_REQUEST_BUY_AFTER");

    return retVal;
}

int32_t StoreEvents::RequestSellHook(CNWSCreature *pCreature, ObjectID oidItemToSell, ObjectID oidStore)
{
    int32_t retVal;
    int32_t price = 0;

    auto *pStore = Utils::AsNWSStore(Utils::GetGameObject(oidStore));
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItemToSell));

    if (pStore && pItem)
        price = pStore->CalculateItemBuyPrice(pItem, pCreature->m_idSelf);

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        Events::PushEventData("ITEM", Utils::ObjectIDToString(oidItemToSell));
        Events::PushEventData("STORE", Utils::ObjectIDToString(oidStore));
        Events::PushEventData("PRICE", std::to_string(price));
        return Events::SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_STORE_REQUEST_SELL_BEFORE"))
        retVal = s_RequestSellHook->CallOriginal<int32_t>(pCreature, oidItemToSell, oidStore);
    else
        retVal = false;

    Events::PushEventData("RESULT", std::to_string(retVal));
    PushAndSignalEvent("NWNX_ON_STORE_REQUEST_SELL_AFTER");

    return retVal;
}

}
