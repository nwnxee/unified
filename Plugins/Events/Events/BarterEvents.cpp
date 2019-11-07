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
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerBarter_StartBarterHook;

static Types::ObjectID m_initiatorOid;
static Types::ObjectID m_targetOid;

BarterEvents::BarterEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_BARTER_START_.*", [hooker]() {
        hooker->RequestExclusiveHook<Functions::_ZN11CNWSMessage38HandlePlayerToServerBarter_StartBarterEP10CNWSPlayer, int32_t,
                CNWSMessage*, CNWSPlayer*>(&HandlePlayerToServerBarter_StartBarterHook);
        m_HandlePlayerToServerBarter_StartBarterHook = hooker->FindHookByAddress(API::Functions::_ZN11CNWSMessage38HandlePlayerToServerBarter_StartBarterEP10CNWSPlayer);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_BARTER_END_.*", [hooker]() {
        hooker->RequestSharedHook<Functions::_ZN10CNWSBarter15SetListAcceptedEi, int32_t,
                CNWSBarter*, int32_t>(&SetListAcceptedHook);
        hooker->RequestSharedHook<Functions::_ZN11CNWSMessage35SendServerToPlayerBarterCloseBarterEjji, int32_t,
                CNWSMessage*, uint32_t, uint32_t, int32_t>(&SendServerToPlayerBarterCloseBarterHook);
    });
}

int32_t BarterEvents::HandlePlayerToServerBarter_StartBarterHook(
        CNWSMessage* pMessage,
        CNWSPlayer* pPlayer)
{
    int32_t retVal;

    Types::ObjectID oidPlayer = pPlayer->m_oidNWSObject;
    Types::ObjectID targetId = Utils::PeekMessage<Types::ObjectID>(pMessage, 0) & 0x7FFFFFFF;

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetId));
        return Events::SignalEvent(ev, oidPlayer);
    };

    if (PushAndSignal("NWNX_ON_BARTER_START_BEFORE"))
    {
        retVal = m_HandlePlayerToServerBarter_StartBarterHook->CallOriginal<int32_t>(pMessage, pPlayer);
    }
    else
        retVal = false;

    PushAndSignal("NWNX_ON_BARTER_START_AFTER");

    return retVal;
}

void BarterEvents::SetListAcceptedHook(
        NWNXLib::Services::Hooks::CallType type,
        CNWSBarter *pBarter,
        int32_t bAccepted)
{
    if (pBarter && bAccepted)
        EndedBarter(type, pBarter, bAccepted);
}

void BarterEvents::SendServerToPlayerBarterCloseBarterHook(
        Services::Hooks::CallType type,
        CNWSMessage*,
        Types::ObjectID nInitiatorId,
        Types::ObjectID,
        int32_t bAccepted)
{
    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    uint32_t oidPlayer = static_cast<CNWSPlayer*>(exoApp->GetClientObjectByPlayerId(nInitiatorId, 0))->m_oidPCObject;
    CNWSCreature* pCreature = exoApp->GetCreatureByGameObjectID(oidPlayer);
    auto *pBarter = pCreature->GetBarterInfo(0);

    // We only need to run the END on a CANCEL BARTER for the initiator
    if (pBarter->m_bInitiator && !bAccepted)
        EndedBarter(type, pBarter, bAccepted);
}

void BarterEvents::EndedBarter(
        NWNXLib::Services::Hooks::CallType type,
        CNWSBarter *pBarter,
        int32_t bAccepted)
{
    CNWSBarter* otherBarter;
    CNWSBarter* initiatorBarter;
    CNWSBarter* targetBarter;

    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    if (bAccepted && before)
    {
        otherBarter = Utils::GetGameObject(pBarter->m_oidBarrator)->AsNWSCreature()->GetBarterInfo(0);

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
                auto item = *(static_cast<Types::ObjectID *>(node->pObject));
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
                auto item = *(static_cast<Types::ObjectID *>(node->pObject));
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
        otherBarter = Utils::GetGameObject(pBarter->m_oidBarrator)->AsNWSCreature()->GetBarterInfo(0);

        initiatorBarter = pBarter->m_bInitiator ? pBarter : otherBarter;
        targetBarter = pBarter->m_bInitiator ? otherBarter : pBarter;

        Events::PushEventData("BARTER_COMPLETE", "0");
        Events::PushEventData("BARTER_TARGET", Utils::ObjectIDToString(targetBarter->m_pOwner->m_idSelf));
        Events::SignalEvent(before ? "NWNX_ON_BARTER_END_BEFORE" : "NWNX_ON_BARTER_END_AFTER", initiatorBarter->m_pOwner->m_idSelf);
    }
}

}
