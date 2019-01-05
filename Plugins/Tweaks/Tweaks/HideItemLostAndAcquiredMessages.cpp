#include "Tweaks/HideItemLostAndAcquiredMessages.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CNWSMessage.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* m_SendFeedbackMessageHook = nullptr;

HideItemLostAndAcquiredMessages::HideItemLostAndAcquiredMessages(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__SendFeedbackMessage>(&HideItemLostAndAcquiredMessages::SendFeedbackMessageHook);

    m_SendFeedbackMessageHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__SendFeedbackMessage);
}

void HideItemLostAndAcquiredMessages::SendFeedbackMessageHook(
    CNWSCreature* thisPtr, 
    uint16_t nFeedbackID, 
    CNWCCMessageData* pData, 
    CNWSPlayer* pPlayer)
{
    bool bSuppressMessage = false;

    switch(nFeedbackID)
    {
        case 50: // Acquired Item
        case 51: // Lost Item 
            bSuppressMessage = true;
            break;

        default:
            break;
    }

    if (!bSuppressMessage)
    {
        m_SendFeedbackMessageHook->CallOriginal<void>(thisPtr, nFeedbackID, pData, pPlayer);
    }
}

}
