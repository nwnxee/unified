#include "Events/TrapEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "nwnx.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_AIActionDisarmTrapHook;
static NWNXLib::Hooks::Hook s_AIActionExamineTrapHook;
static NWNXLib::Hooks::Hook s_AIActionFlagTrapHook;
static NWNXLib::Hooks::Hook s_AIActionRecoverTrapHook;
static NWNXLib::Hooks::Hook s_AIActionSetTrapHook;
static NWNXLib::Hooks::Hook s_OnEnterTrapHook;

TrapEvents::TrapEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_TRAP_.*", []() {
        s_AIActionDisarmTrapHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature18AIActionDisarmTrapEP20CNWSObjectActionNode,
                                                (void*)&AIActionDisarmTrapHook, Hooks::Order::Early);
        s_AIActionExamineTrapHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature19AIActionExamineTrapEP20CNWSObjectActionNode,
                                                 (void*)&AIActionExamineTrapHook, Hooks::Order::Early);
        s_AIActionFlagTrapHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature16AIActionFlagTrapEP20CNWSObjectActionNode,
                                              (void*)&AIActionFlagTrapHook, Hooks::Order::Early);
        s_AIActionRecoverTrapHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature19AIActionRecoverTrapEP20CNWSObjectActionNode,
                                                 (void*)&AIActionRecoverTrapHook, Hooks::Order::Early);
        s_AIActionSetTrapHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature15AIActionSetTrapEP20CNWSObjectActionNode,
                                             (void*)&AIActionSetTrapHook, Hooks::Order::Early);
        s_OnEnterTrapHook = Hooks::HookFunction(API::Functions::_ZN11CNWSTrigger11OnEnterTrapEi,
                                         (void*)&OnEnterTrapHook, Hooks::Order::Early);
    });
}

uint32_t TrapEvents::HandleTrapHook(const std::string& event, Hooks::FunctionHook* originalTrapHook, CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
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

uint32_t TrapEvents::AIActionDisarmTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("DISARM", s_AIActionDisarmTrapHook.get(), pCreature, pNode);
}

uint32_t TrapEvents::AIActionExamineTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("EXAMINE", s_AIActionExamineTrapHook.get(), pCreature, pNode);
}

uint32_t TrapEvents::AIActionFlagTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("FLAG", s_AIActionFlagTrapHook.get(), pCreature, pNode);
}

uint32_t TrapEvents::AIActionRecoverTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("RECOVER", s_AIActionRecoverTrapHook.get(), pCreature, pNode);
}

uint32_t TrapEvents::AIActionSetTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("SET", s_AIActionSetTrapHook.get(), pCreature, pNode);
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
