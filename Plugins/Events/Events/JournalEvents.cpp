#include "Events/JournalEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "Events.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_HandlePlayerToServerJournalMessageHook;

JournalEvents::JournalEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_JOURNAL_(OPEN|CLOSE)_.*", []() {
        s_HandlePlayerToServerJournalMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage34HandlePlayerToServerJournalMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerJournalMessageHook, Hooks::Order::Earliest);
    });
}

int32_t JournalEvents::HandlePlayerToServerJournalMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    switch (nMinor)
    {
        case MessageJournalMinor::QuestScreenOpen:
        {
            Events::SignalEvent("NWNX_ON_JOURNAL_OPEN_BEFORE", pPlayer->m_oidNWSObject);
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            Events::SignalEvent("NWNX_ON_JOURNAL_OPEN_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        case MessageJournalMinor::QuestScreenClosed:
        {
            Events::SignalEvent("NWNX_ON_JOURNAL_CLOSE_BEFORE", pPlayer->m_oidNWSObject);
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            Events::SignalEvent("NWNX_ON_JOURNAL_CLOSE_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        default:
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            break;
    }

    return retVal;
}

}
