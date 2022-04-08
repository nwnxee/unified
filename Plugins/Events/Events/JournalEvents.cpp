#include "Events.hpp"
#include "API/CNWSPlayer.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_HandlePlayerToServerJournalMessageHook;

static int32_t HandlePlayerToServerJournalMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void JournalEvents() __attribute__((constructor));
void JournalEvents()
{
    InitOnFirstSubscribe("NWNX_ON_JOURNAL_(OPEN|CLOSE)_.*", []() {
        s_HandlePlayerToServerJournalMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage34HandlePlayerToServerJournalMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerJournalMessageHook, Hooks::Order::Earliest);
    });
}

int32_t HandlePlayerToServerJournalMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    switch (nMinor)
    {
        case MessageJournalMinor::QuestScreenOpen:
        {
            SignalEvent("NWNX_ON_JOURNAL_OPEN_BEFORE", pPlayer->m_oidNWSObject);
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            SignalEvent("NWNX_ON_JOURNAL_OPEN_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        case MessageJournalMinor::QuestScreenClosed:
        {
            SignalEvent("NWNX_ON_JOURNAL_CLOSE_BEFORE", pPlayer->m_oidNWSObject);
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            SignalEvent("NWNX_ON_JOURNAL_CLOSE_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        default:
            retVal = s_HandlePlayerToServerJournalMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            break;
    }

    return retVal;
}

}
