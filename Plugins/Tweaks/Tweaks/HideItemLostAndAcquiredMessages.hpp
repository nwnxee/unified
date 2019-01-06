#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class HideItemLostAndAcquiredMessages
{
public:
    HideItemLostAndAcquiredMessages(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void SendFeedbackMessageHook(
        NWNXLib::API::CNWSCreature* thisPtr, 
        uint16_t nFeedbackID, 
        NWNXLib::API::CNWCCMessageData* pData, 
        NWNXLib::API::CNWSPlayer* pPlayer);
};

}
