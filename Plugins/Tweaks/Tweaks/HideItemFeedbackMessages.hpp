#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class HideItemFeedbackMessages
{
public:
    HideItemFeedbackMessages(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker, int32_t feedbackMode, bool onlyHideLostAcquired);

private:
    static void SendFeedbackMessageHook(
        NWNXLib::API::CNWSCreature* pCreature, 
        uint16_t nFeedbackID, 
        NWNXLib::API::CNWCCMessageData* pData, 
        NWNXLib::API::CNWSPlayer* pPlayer);   
    
    static int32_t m_feedbackMode;
    static bool m_onlyHideLostAcquired;
};

}
