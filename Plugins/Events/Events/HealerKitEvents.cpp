#include "Events/HealerKitEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

HealerKitEvents::HealerKitEvents(ViewPtr<Services::HooksProxy> hooker)
{
    
    m_services->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__AIActionHeal>(&Creature::AIActionHeal);
    m_AIActionHealHook = m_services->m_hooks->FindHookByAddress(Functions::CNWSCreature__AIActionHeal);
}

int32_t HealerKitEvents::AIActionHealHook(
    NWNXLib::API::CNWSCreature *pCreature, 
    NWNXLib::API::CNWSObjectActionNode *pNode)
{

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(pNode->m_pParameter[0])); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(pNode->m_pParameter[1])); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(pNode->m_pParameter[2])); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string(pNode->m_pParameter[3])); //nMoveToTarget

    if (Events::SignalEvent("NWNX_ON_HEALER_KIT_BEFORE", thisPtr->m_idSelf))
    {
        m_AIActionHealHook->CallOriginal<void>(thisPtr, assocId, unused);
    }
    
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(pNode->m_pParameter[0])); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString(pNode->m_pParameter[1])); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string(pNode->m_pParameter[2])); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string(pNode->m_pParameter[3])); //nMoveToTarget
    Events::SignalEvent("NWNX_ON_HEALER_KIT_AFTER", thisPtr->m_idSelf);
}

}
