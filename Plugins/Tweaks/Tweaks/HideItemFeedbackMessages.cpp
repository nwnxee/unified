#include "Tweaks/HideItemFeedbackMessages.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/Functions.hpp"
#include "ViewPtr.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* m_SendFeedbackMessageHook = nullptr;
int32_t HideItemFeedbackMessages::m_feedbackMode;
bool HideItemFeedbackMessages::m_onlyHideLostAcquired;

HideItemFeedbackMessages::HideItemFeedbackMessages(ViewPtr<Services::HooksProxy> hooker, int32_t feedbackMode, bool onlyHideLostAcquired)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__SendFeedbackMessage>(&HideItemFeedbackMessages::SendFeedbackMessageHook);
    m_SendFeedbackMessageHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__SendFeedbackMessage);

    m_feedbackMode = feedbackMode;
    m_onlyHideLostAcquired = onlyHideLostAcquired;
}

void HideItemFeedbackMessages::SendFeedbackMessageHook(
    CNWSCreature* pCreature, 
    uint16_t nFeedbackID, 
    CNWCCMessageData* pData, 
    CNWSPlayer* pPlayer)
{
    bool bSuppressMessage = false;

    LOG_DEBUG("nFeedbackID = %u", nFeedbackID);

    auto GetShouldSuppressItemFeedbackMessage = [&pCreature]() -> bool 
    {
        CNWSScriptVarTable *pScriptVarTable = &pCreature->m_ScriptVars;
        bool retVal = 0;
        if (pScriptVarTable)
        {
            CExoString varName = "NWNX_HIDE_ITEM_MESSAGES";

            retVal = !!pScriptVarTable->GetInt(varName);

            LOG_DEBUG("NWNX_HIDE_ITEM_MESSAGES = %i", retVal);
        }        

        return retVal;   
    };

    switch(nFeedbackID)
    {
        case 50: // Acquired Item
        case 51: // Lost Item
            if (m_feedbackMode == 2)
            {// Only suppress feedback messages when player has a local var
                bSuppressMessage = GetShouldSuppressItemFeedbackMessage();
            }
            else
            {// Always suppress
                bSuppressMessage = true;
            }
            break;
        
        case 71:    // Armor/Shield Penalty
        case 121:   // Weapon equipped as one handed weapon
        case 122:   // Weapon equipped as two handed weapon
        case 123:   // Equipped item swapped out
            if (!m_onlyHideLostAcquired)
            {
                if (m_feedbackMode == 2)
                {// Only suppress feedback messages when player has a local var
                    bSuppressMessage = GetShouldSuppressItemFeedbackMessage();
                }
                else
                {// Always suppress
                    bSuppressMessage = true;
                }  
            }          
            break;
        

        default:
            break;
    }

    if (!bSuppressMessage)
    {
        m_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pData, pPlayer);
    }
}

}
