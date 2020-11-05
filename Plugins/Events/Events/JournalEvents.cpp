#include "Events/JournalEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

JournalEvents::JournalEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_JOURNAL_(OPEN|CLOSE)_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage34HandlePlayerToServerJournalMessageEP10CNWSPlayerh, int32_t>(&HandlePlayerToServerJournalMessageHook);
    });
}

void JournalEvents::HandlePlayerToServerJournalMessageHook(bool before, CNWSMessage*, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    switch (nMinor)
    {
        case MessageJournalMinor::QuestScreenOpen:
        {
            Events::SignalEvent(before ? "NWNX_ON_JOURNAL_OPEN_BEFORE" : "NWNX_ON_JOURNAL_OPEN_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        case MessageJournalMinor::QuestScreenClosed:
        {
            Events::SignalEvent(before ? "NWNX_ON_JOURNAL_CLOSE_BEFORE" : "NWNX_ON_JOURNAL_CLOSE_AFTER", pPlayer->m_oidNWSObject);
            break;
        }

        default:
            break;
    }
}

}
