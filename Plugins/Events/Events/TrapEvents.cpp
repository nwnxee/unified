#include "Events/TrapEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "Plugin.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* m_AIActionDisarmTrapHook=nullptr;
static NWNXLib::Hooking::FunctionHook* m_AIActionExamineTrapHook=nullptr;
static NWNXLib::Hooking::FunctionHook* m_AIActionFlagTrapHook=nullptr;
static NWNXLib::Hooking::FunctionHook* m_AIActionRecoverTrapHook=nullptr;
static NWNXLib::Hooking::FunctionHook* m_AIActionSetTrapHook=nullptr;

TrapEvents::TrapEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_TRAP_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionDisarmTrap, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionDisarmTrapHook);
        m_AIActionDisarmTrapHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionDisarmTrap);
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionExamineTrap, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionExamineTrapHook);
        m_AIActionExamineTrapHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionExamineTrap);
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionFlagTrap, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionFlagTrapHook);
        m_AIActionFlagTrapHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionFlagTrap);
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionRecoverTrap, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionRecoverTrapHook);
        m_AIActionRecoverTrapHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionRecoverTrap);
        hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AIActionSetTrap, uint32_t, API::CNWSCreature*, API::CNWSObjectActionNode*>(&AIActionSetTrapHook);
        m_AIActionSetTrapHook =  hooker->FindHookByAddress(API::Functions::CNWSCreature__AIActionSetTrap);
    });
}

uint32_t TrapEvents::HandleTrapHook(
        const std::string& event,
        NWNXLib::Hooking::FunctionHook* originalTrapHook,
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{

    uint32_t retVal;
    std::string sAux;

    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[0])));

    if (Events::SignalEvent("NWNX_ON_TRAP_" + event + "_BEFORE", pCreature->m_idSelf, &sAux))
    {
        retVal = originalTrapHook->CallOriginal<uint32_t>(pCreature, pNode);
    }
    else
    {
        retVal = std::stoul(sAux);
        if(retVal == 0)
            retVal = 3; //CNWSObject::ACTION_FAILED;
    }

    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uint32_t)(pNode->m_pParameter[0])));
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));

    Events::SignalEvent("NWNX_ON_TRAP_" + event + "_AFTER", pCreature->m_idSelf);
    return retVal;
}

uint32_t TrapEvents::AIActionDisarmTrapHook(
    CNWSCreature *pCreature,
    CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("DISARM", m_AIActionDisarmTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionExamineTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("EXAMINE", m_AIActionExamineTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionFlagTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("FLAG", m_AIActionFlagTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionRecoverTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("RECOVER", m_AIActionRecoverTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionSetTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("SET", m_AIActionSetTrapHook, pCreature, pNode);
}

}
