#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSStore.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_RequestBuyHook;
static NWNXLib::Hooks::Hook s_RequestSellHook;

static int32_t RequestBuyHook(CNWSCreature*, ObjectID, ObjectID, ObjectID);
static int32_t RequestSellHook(CNWSCreature*, ObjectID, ObjectID);

void StoreEvents() __attribute__((constructor));
void StoreEvents()
{
    InitOnFirstSubscribe("NWNX_ON_STORE_REQUEST_BUY_.*", []() {
        s_RequestBuyHook = Hooks::HookFunction(&CNWSCreature::RequestBuy, &RequestBuyHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_STORE_REQUEST_SELL_.*", []() {
        s_RequestSellHook = Hooks::HookFunction(&CNWSCreature::RequestSell, &RequestSellHook, Hooks::Order::Early);
    });
}

int32_t RequestBuyHook(CNWSCreature *pCreature, ObjectID oidItemToBuy, ObjectID oidStore, ObjectID oidDesiredRepository)
{
    int32_t retVal;
    int32_t price = 0;

    auto *pStore = Utils::AsNWSStore(Utils::GetGameObject(oidStore));
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItemToBuy));

    if (pStore && pItem)
        price = pStore->CalculateItemSellPrice(pItem, pCreature->m_idSelf);

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        PushEventData("ITEM", Utils::ObjectIDToString(oidItemToBuy));
        PushEventData("STORE", Utils::ObjectIDToString(oidStore));
        PushEventData("PRICE", std::to_string(price));
        return SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_STORE_REQUEST_BUY_BEFORE"))
        retVal = s_RequestBuyHook->CallOriginal<int32_t>(pCreature, oidItemToBuy, oidStore, oidDesiredRepository);
    else
        retVal = false;

    PushEventData("RESULT", std::to_string(retVal));
    PushAndSignalEvent("NWNX_ON_STORE_REQUEST_BUY_AFTER");

    return retVal;
}

int32_t RequestSellHook(CNWSCreature *pCreature, ObjectID oidItemToSell, ObjectID oidStore)
{
    int32_t retVal;
    int32_t price = 0;

    auto *pStore = Utils::AsNWSStore(Utils::GetGameObject(oidStore));
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItemToSell));

    if (pStore && pItem)
        price = pStore->CalculateItemBuyPrice(pItem, pCreature->m_idSelf);

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        PushEventData("ITEM", Utils::ObjectIDToString(oidItemToSell));
        PushEventData("STORE", Utils::ObjectIDToString(oidStore));
        PushEventData("PRICE", std::to_string(price));
        return SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_STORE_REQUEST_SELL_BEFORE"))
        retVal = s_RequestSellHook->CallOriginal<int32_t>(pCreature, oidItemToSell, oidStore);
    else
        retVal = false;

    PushEventData("RESULT", std::to_string(retVal));
    PushAndSignalEvent("NWNX_ON_STORE_REQUEST_SELL_AFTER");

    return retVal;
}

}
