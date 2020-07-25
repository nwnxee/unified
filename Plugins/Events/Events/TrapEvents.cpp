#include "Events/TrapEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "Plugin.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* s_AIActionDisarmTrapHook;
static NWNXLib::Hooking::FunctionHook* s_AIActionExamineTrapHook;
static NWNXLib::Hooking::FunctionHook* s_AIActionFlagTrapHook;
static NWNXLib::Hooking::FunctionHook* s_AIActionRecoverTrapHook;
static NWNXLib::Hooking::FunctionHook* s_AIActionSetTrapHook;
static NWNXLib::Hooking::FunctionHook* s_OnEnterTrapHook;

TrapEvents::TrapEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_TRAP_.*", [hooker]() {
        s_AIActionDisarmTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature18AIActionDisarmTrapEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionDisarmTrapHook);
        s_AIActionExamineTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature19AIActionExamineTrapEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionExamineTrapHook);
        s_AIActionFlagTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature16AIActionFlagTrapEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionFlagTrapHook);
        s_AIActionRecoverTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature19AIActionRecoverTrapEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionRecoverTrapHook);
        s_AIActionSetTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature15AIActionSetTrapEP20CNWSObjectActionNode, uint32_t, CNWSCreature*, CNWSObjectActionNode*>
            (&AIActionSetTrapHook);
        s_OnEnterTrapHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN11CNWSTrigger11OnEnterTrapEi, void, CNWSTrigger*, int32_t>
            (&OnEnterTrapHook);
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

    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0])));

    if (Events::SignalEvent("NWNX_ON_TRAP_" + event + "_BEFORE", pCreature->m_idSelf, &sAux))
    {
        retVal = originalTrapHook->CallOriginal<uint32_t>(pCreature, pNode);
    }
    else
    {
        retVal = atoi(sAux.c_str());
        if(retVal == 0)
            retVal = 3; //CNWSObject::ACTION_FAILED;
    }

    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0])));
    Events::PushEventData("ACTION_RESULT", std::to_string(retVal));

    Events::SignalEvent("NWNX_ON_TRAP_" + event + "_AFTER", pCreature->m_idSelf);
    return retVal;
}

uint32_t TrapEvents::AIActionDisarmTrapHook(
    CNWSCreature *pCreature,
    CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("DISARM", s_AIActionDisarmTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionExamineTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("EXAMINE", s_AIActionExamineTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionFlagTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("FLAG", s_AIActionFlagTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionRecoverTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("RECOVER", s_AIActionRecoverTrapHook, pCreature, pNode);
}

uint32_t TrapEvents::AIActionSetTrapHook(
        CNWSCreature *pCreature,
        CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("SET", s_AIActionSetTrapHook, pCreature, pNode);
}

void TrapEvents::OnEnterTrapHook(CNWSTrigger *pTrigger, int32_t bForceSet)
{
    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString(pTrigger->m_idSelf));
    Events::PushEventData("TRAP_FORCE_SET", std::to_string(bForceSet));

    std::string forceSet;
    if (Events::SignalEvent("NWNX_ON_TRAP_ENTER_BEFORE", pTrigger->m_oidLastEntered, &forceSet))
    {
        s_OnEnterTrapHook->CallOriginal<void>(pTrigger, bForceSet);
    }
    else if (!forceSet.empty())
    {
        s_OnEnterTrapHook->CallOriginal<void>(pTrigger, forceSet == "1");
    }

    Events::PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString(pTrigger->m_idSelf));
    Events::SignalEvent("NWNX_ON_TRAP_ENTER_AFTER", pTrigger->m_oidLastEntered);
}

}
