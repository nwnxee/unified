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

static NWNXLib::Hooking::FunctionHook* s_AIActionHealHook;

HealerKitEvents::HealerKitEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_HEALER_KIT_.*", [hooker]() {
        s_AIActionHealHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature12AIActionHealEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionHealHook);
    });
}

uint32_t HealerKitEvents::AIActionHealHook(
    CNWSCreature *pCreature,
    CNWSObjectActionNode *pNode)
{
    uint32_t retVal;
    std::string sAux;

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0]))); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1]))); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uintptr_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string((uintptr_t)(pNode->m_pParameter[3]))); //nMoveToTarget

    if (Events::SignalEvent("NWNX_ON_HEALER_KIT_BEFORE", pCreature->m_idSelf, &sAux))
    {

        retVal = s_AIActionHealHook->CallOriginal<uint32_t>(pCreature, pNode);
    }
    else
    {
        retVal = atoi(sAux.c_str());
        if(retVal==0)
        {
            retVal = 3; //CNWSObject::ACTION_FAILED;
        }
    }

    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0]))); //oidTarget
    Events::PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1]))); //oidItemUsed
    Events::PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uintptr_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    Events::PushEventData("MOVE_TO_TARGET", std::to_string((uintptr_t)(pNode->m_pParameter[3]))); //nMoveToTarget
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal)); //nMoveToTarget

    Events::SignalEvent("NWNX_ON_HEALER_KIT_AFTER", pCreature->m_idSelf);
    return retVal;
}

}
