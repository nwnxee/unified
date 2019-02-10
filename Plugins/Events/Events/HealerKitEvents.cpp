#include "Events/HealerKitEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/CNWSObject.hpp"
#include "Plugin.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

static NWNXLib::Hooking::FunctionHook* m_AIActionHealHook=nullptr;

HealerKitEvents::HealerKitEvents(ViewPtr<Services::HooksProxy> hooker)
{

    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionHeal, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionHealHook);
    m_AIActionHealHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionHeal);
}

uint32_t HealerKitEvents::AIActionHealHook(
    NWNXLib::API::CNWSCreature *pCreature,
    NWNXLib::API::CNWSObjectActionNode *pNode)
{
    uint32_t retVal;
    std::string sAux;

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[0]))); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[1]))); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uint32_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string((uint32_t)(pNode->m_pParameter[3]))); //nMoveToTarget

    if (Events::SignalEvent("NWNX_ON_HEALER_KIT_BEFORE", pCreature->m_idSelf, &sAux))
    {

        retVal = m_AIActionHealHook->CallOriginal<uint32_t>(pCreature, pNode);
    }
    else
    {
        retVal = atoi(sAux.c_str());
        if(retVal==0)
        {
            retVal = 3; //CNWSObject::ACTION_FAILED;
        }
    }

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[0]))); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[1]))); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uint32_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string((uint32_t)(pNode->m_pParameter[3]))); //nMoveToTarget
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal)); //nMoveToTarget

    Events::SignalEvent("NWNX_ON_HEALER_KIT_AFTER", pCreature->m_idSelf);
    return retVal;
}

}
