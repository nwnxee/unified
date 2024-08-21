#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CItemRepository.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSBarter.hpp"
#include "API/CNWSItem.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_HandlePlayerToServerBarter_StartBarterHook;
static Hooks::Hook s_SetListAcceptedHook;
static Hooks::Hook s_SendServerToPlayerBarterCloseBarterHook;
static Hooks::Hook s_AddItemHook;
static ObjectID s_initiatorOid;
static ObjectID s_targetOid;

static int32_t HandlePlayerToServerBarter_StartBarterHook(CNWSMessage*, CNWSPlayer*);
static void EndedBarter(bool, CNWSBarter*, int32_t);
static int32_t SetListAcceptedHook(CNWSBarter*, int32_t);
static int32_t SendServerToPlayerBarterCloseBarterHook(CNWSMessage*, ObjectID, ObjectID, int32_t);
static int32_t AddItemHook(CNWSBarter*, OBJECT_ID, uint8_t&, uint8_t&);

void BarterEvents() __attribute__((constructor));
void BarterEvents()
{
    InitOnFirstSubscribe("NWNX_ON_BARTER_START_.*", []() {
        s_HandlePlayerToServerBarter_StartBarterHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerBarter_StartBarter,
                &HandlePlayerToServerBarter_StartBarterHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_BARTER_END_.*", []() {
        s_SetListAcceptedHook = Hooks::HookFunction(&CNWSBarter::SetListAccepted,
            &SetListAcceptedHook, Hooks::Order::Earliest);
        s_SendServerToPlayerBarterCloseBarterHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerBarterCloseBarter,
                &SendServerToPlayerBarterCloseBarterHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_BARTER_ADD_ITEM_.*", []() {
        s_AddItemHook = Hooks::HookFunction(
                &CNWSBarter::AddItem,
                &AddItemHook, Hooks::Order::Early);
    });
}

int32_t HandlePlayerToServerBarter_StartBarterHook(CNWSMessage* pMessage, CNWSPlayer* pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer->m_oidNWSObject;
    ObjectID targetId = Utils::PeekMessage<ObjectID>(pMessage, 0) & 0x7FFFFFFF;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetId));
        return SignalEvent(ev, oidPlayer);
    };

    if (PushAndSignal("NWNX_ON_BARTER_START_BEFORE"))
    {
        retVal = s_HandlePlayerToServerBarter_StartBarterHook->CallOriginal<int32_t>(pMessage, pPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_BARTER_START_AFTER");

    return retVal;
}

int32_t SetListAcceptedHook(CNWSBarter *pBarter, int32_t bAccepted)
{
    if (pBarter && bAccepted)
    {
        EndedBarter(true, pBarter, bAccepted);
        auto retVal = s_SetListAcceptedHook->CallOriginal<int32_t>(pBarter, bAccepted);
        EndedBarter(false, pBarter, bAccepted);
        return retVal;
    }

    return s_SetListAcceptedHook->CallOriginal<int32_t>(pBarter, bAccepted);
}

int32_t SendServerToPlayerBarterCloseBarterHook(CNWSMessage *pMessage, ObjectID nInitiatorId,
                                                              ObjectID nRecipientId, int32_t bAccepted)
{
    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    uint32_t oidPlayer = exoApp->GetClientObjectByPlayerId(nInitiatorId)->m_oidNWSObject;
    CNWSCreature* pCreature = exoApp->GetCreatureByGameObjectID(oidPlayer);
    auto *pBarter = pCreature->GetBarterInfo(0);

    // We only need to run the END on a CANCEL BARTER for the initiator
    if (pBarter && pBarter->m_bInitiator && !bAccepted)
    {
        EndedBarter(true, pBarter, bAccepted);
        auto retVal = s_SendServerToPlayerBarterCloseBarterHook->CallOriginal<int32_t>(pMessage, nInitiatorId, nRecipientId, bAccepted);
        EndedBarter(false, pBarter, bAccepted);
        return retVal;
    }

    return s_SendServerToPlayerBarterCloseBarterHook->CallOriginal<int32_t>(pMessage, nInitiatorId, nRecipientId, bAccepted);
}

void EndedBarter(bool before, CNWSBarter *pBarter, int32_t bAccepted)
{
    CNWSBarter* otherBarter;
    CNWSBarter* initiatorBarter;
    CNWSBarter* targetBarter;
    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;

    if (bAccepted && before)
    {
        auto* other = Utils::AsNWSCreature(exoApp->GetGameObject(pBarter->m_oidBarrator));
        if (other == nullptr)
            return;

        otherBarter = other->GetBarterInfo(0);

        // We only handle a completed barter when the other player has already accepted
        if (!otherBarter->m_bListAccepted)
            return;

        initiatorBarter = pBarter->m_bInitiator ? pBarter : otherBarter;
        targetBarter = pBarter->m_bInitiator ? otherBarter : pBarter;

        // We need to use these in the AFTER where they're no longer available
        s_initiatorOid = initiatorBarter->m_pOwner->m_idSelf;
        s_targetOid = targetBarter->m_pOwner->m_idSelf;
        if (initiatorBarter->m_pBarterList)
        {
            auto *itemList = initiatorBarter->m_pBarterList->m_oidItems.m_pcExoLinkedListInternal;
            PushEventData("BARTER_INITIATOR_ITEM_COUNT", std::to_string(itemList->m_nCount));
            int i = 0;
            for (auto *node = itemList->pHead; node; node = node->pNext)
            {
                auto item = *(static_cast<ObjectID *>(node->pObject));
                PushEventData("BARTER_INITIATOR_ITEM_" + std::to_string(i), Utils::ObjectIDToString(item));
                i++;
            }
        }
        else
        {
            PushEventData("BARTER_INITIATOR_ITEM_COUNT", "0");
        }

        if (targetBarter->m_pBarterList)
        {
            auto *itemList = targetBarter->m_pBarterList->m_oidItems.m_pcExoLinkedListInternal;
            PushEventData("BARTER_TARGET_ITEM_COUNT", std::to_string(itemList->m_nCount));
            int i = 0;
            for (auto *node = itemList->pHead; node; node = node->pNext)
            {
                auto item = *(static_cast<ObjectID *>(node->pObject));
                PushEventData("BARTER_TARGET_ITEM_" + std::to_string(i), Utils::ObjectIDToString(item));
                i++;
            }
        }
        else
        {
            PushEventData("BARTER_TARGET_ITEM_COUNT", "0");
        }
        PushEventData("BARTER_COMPLETE", "1");
        PushEventData("BARTER_TARGET", Utils::ObjectIDToString(s_targetOid));
        SignalEvent("NWNX_ON_BARTER_END_BEFORE", s_initiatorOid);
    }
    else if (bAccepted)
    {
        // When the AcceptTrade has been selected by both players and ran both in the BEFORE and AFTER
        // the oidBarrator becomes invalid.
        if (pBarter->m_oidBarrator != Constants::OBJECT_INVALID)
            return;

        PushEventData("BARTER_COMPLETE", "1");
        PushEventData("BARTER_TARGET", Utils::ObjectIDToString(s_targetOid));
        SignalEvent("NWNX_ON_BARTER_END_AFTER", s_initiatorOid);
    }
    else // Cancelled Barter
    {
        auto* other = Utils::AsNWSCreature(exoApp->GetGameObject(pBarter->m_oidBarrator));
        if (other == nullptr)
            return;

        otherBarter = other->GetBarterInfo(0);

        initiatorBarter = pBarter->m_bInitiator ? pBarter : otherBarter;
        targetBarter = pBarter->m_bInitiator ? otherBarter : pBarter;

        PushEventData("BARTER_COMPLETE", "0");
        PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetBarter->m_pOwner->m_idSelf));
        SignalEvent(before ? "NWNX_ON_BARTER_END_BEFORE" : "NWNX_ON_BARTER_END_AFTER", initiatorBarter->m_pOwner->m_idSelf);
    }
}

static int32_t AddItemHook(CNWSBarter *pThis, OBJECT_ID oidItem, uint8_t & xPos, uint8_t & yPos)
{
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItem));
    if (!pThis || !pThis->m_pOwner || !pItem)
        return s_AddItemHook->CallOriginal<int32_t>(pThis, oidItem, &xPos, &yPos);

    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("ITEM", Utils::ObjectIDToString(oidItem));
        PushEventData("BARTER_TARGET", Utils::ObjectIDToString(pThis->m_oidBarrator));
        return SignalEvent(ev, pThis->m_pOwner->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_BARTER_ADD_ITEM_BEFORE"))
    {
        retVal = s_AddItemHook->CallOriginal<int32_t>(pThis, oidItem, &xPos, &yPos);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_BARTER_ADD_ITEM_AFTER");

    return retVal;
}

}
