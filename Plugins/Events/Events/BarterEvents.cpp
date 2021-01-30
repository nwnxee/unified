#include "Events/BarterEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CItemRepository.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSBarter.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_HandlePlayerToServerBarter_StartBarterHook;
static Hooks::Hook s_SetListAcceptedHook;
static Hooks::Hook s_SendServerToPlayerBarterCloseBarterHook;

static ObjectID m_initiatorOid;
static ObjectID m_targetOid;

BarterEvents::BarterEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_BARTER_START_.*", []() {
        s_HandlePlayerToServerBarter_StartBarterHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage38HandlePlayerToServerBarter_StartBarterEP10CNWSPlayer,
                (void*)&HandlePlayerToServerBarter_StartBarterHook, Hooks::Order::Early);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_BARTER_END_.*", []() {
        s_SetListAcceptedHook = Hooks::HookFunction(Functions::_ZN10CNWSBarter15SetListAcceptedEi,
                                             (void*)&SetListAcceptedHook, Hooks::Order::Earliest);
        s_SendServerToPlayerBarterCloseBarterHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage35SendServerToPlayerBarterCloseBarterEjji,
                (void*)&SendServerToPlayerBarterCloseBarterHook, Hooks::Order::Earliest);
    });
}

int32_t BarterEvents::HandlePlayerToServerBarter_StartBarterHook(CNWSMessage* pMessage, CNWSPlayer* pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer->m_oidNWSObject;
    ObjectID targetId = Utils::PeekMessage<ObjectID>(pMessage, 0) & 0x7FFFFFFF;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetId));
        return Events::SignalEvent(ev, oidPlayer);
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

int32_t BarterEvents::SetListAcceptedHook(CNWSBarter *pBarter, int32_t bAccepted)
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

int32_t BarterEvents::SendServerToPlayerBarterCloseBarterHook(CNWSMessage *pMessage, ObjectID nInitiatorId,
                                                              ObjectID nRecipientId, int32_t bAccepted)
{
    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    uint32_t oidPlayer = static_cast<CNWSPlayer*>(exoApp->GetClientObjectByPlayerId(nInitiatorId))->m_oidNWSObject;
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

void BarterEvents::EndedBarter(bool before, CNWSBarter *pBarter, int32_t bAccepted)
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
        m_initiatorOid = initiatorBarter->m_pOwner->m_idSelf;
        m_targetOid = targetBarter->m_pOwner->m_idSelf;
        if (initiatorBarter->m_pBarterList)
        {
            auto *itemList = initiatorBarter->m_pBarterList->m_oidItems.m_pcExoLinkedListInternal;
            Events::PushEventData("BARTER_INITIATOR_ITEM_COUNT", std::to_string(itemList->m_nCount));
            int i = 0;
            for (auto *node = itemList->pHead; node; node = node->pNext)
            {
                auto item = *(static_cast<ObjectID *>(node->pObject));
                Events::PushEventData("BARTER_INITIATOR_ITEM_" + std::to_string(i), Utils::ObjectIDToString(item));
                i++;
            }
        }
        else
        {
            Events::PushEventData("BARTER_INITIATOR_ITEM_COUNT", "0");
        }

        if (targetBarter->m_pBarterList)
        {
            auto *itemList = targetBarter->m_pBarterList->m_oidItems.m_pcExoLinkedListInternal;
            Events::PushEventData("BARTER_TARGET_ITEM_COUNT", std::to_string(itemList->m_nCount));
            int i = 0;
            for (auto *node = itemList->pHead; node; node = node->pNext)
            {
                auto item = *(static_cast<ObjectID *>(node->pObject));
                Events::PushEventData("BARTER_TARGET_ITEM_" + std::to_string(i), Utils::ObjectIDToString(item));
                i++;
            }
        }
        else
        {
            Events::PushEventData("BARTER_TARGET_ITEM_COUNT", "0");
        }
        Events::PushEventData("BARTER_COMPLETE", "1");
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(m_targetOid));
        Events::SignalEvent("NWNX_ON_BARTER_END_BEFORE", m_initiatorOid);
    }
    else if (bAccepted)
    {
        // When the AcceptTrade has been selected by both players and ran both in the BEFORE and AFTER
        // the oidBarrator becomes invalid.
        if (pBarter->m_oidBarrator != Constants::OBJECT_INVALID)
            return;

        Events::PushEventData("BARTER_COMPLETE", "1");
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(m_targetOid));
        Events::SignalEvent("NWNX_ON_BARTER_END_AFTER", m_initiatorOid);
    }
    else // Cancelled Barter
    {
        auto* other = Utils::AsNWSCreature(exoApp->GetGameObject(pBarter->m_oidBarrator));
        if (other == nullptr)
            return;

        otherBarter = other->GetBarterInfo(0);

        initiatorBarter = pBarter->m_bInitiator ? pBarter : otherBarter;
        targetBarter = pBarter->m_bInitiator ? otherBarter : pBarter;

        Events::PushEventData("BARTER_COMPLETE", "0");
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetBarter->m_pOwner->m_idSelf));
        Events::SignalEvent(before ? "NWNX_ON_BARTER_END_BEFORE" : "NWNX_ON_BARTER_END_AFTER", initiatorBarter->m_pOwner->m_idSelf);
    }
}

}
