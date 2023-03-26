#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSObjectActionNode.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_AIActionDisarmTrapHook;
static NWNXLib::Hooks::Hook s_AIActionExamineTrapHook;
static NWNXLib::Hooks::Hook s_AIActionFlagTrapHook;
static NWNXLib::Hooks::Hook s_AIActionRecoverTrapHook;
static NWNXLib::Hooks::Hook s_AIActionSetTrapHook;
static NWNXLib::Hooks::Hook s_OnEnterTrapHook;

static uint32_t HandleTrapHook(const std::string&, NWNXLib::Hooks::FunctionHook*, CNWSCreature*, CNWSObjectActionNode*);
static uint32_t AIActionDisarmTrapHook(CNWSCreature*, CNWSObjectActionNode*);
static uint32_t AIActionExamineTrapHook(CNWSCreature*, CNWSObjectActionNode*);
static uint32_t AIActionFlagTrapHook(CNWSCreature*, CNWSObjectActionNode*);
static uint32_t AIActionRecoverTrapHook(CNWSCreature*, CNWSObjectActionNode*);
static uint32_t AIActionSetTrapHook(CNWSCreature*, CNWSObjectActionNode*);
static void OnEnterTrapHook(CNWSTrigger*, int32_t);

void TrapEvents() __attribute__((constructor));
void TrapEvents()
{
    InitOnFirstSubscribe("NWNX_ON_TRAP_.*", []() {
        s_AIActionDisarmTrapHook = Hooks::HookFunction(&CNWSCreature::AIActionDisarmTrap,
                                                &AIActionDisarmTrapHook, Hooks::Order::Early);
        s_AIActionExamineTrapHook = Hooks::HookFunction(&CNWSCreature::AIActionExamineTrap,
                                                 &AIActionExamineTrapHook, Hooks::Order::Early);
        s_AIActionFlagTrapHook = Hooks::HookFunction(&CNWSCreature::AIActionFlagTrap,
                                              &AIActionFlagTrapHook, Hooks::Order::Early);
        s_AIActionRecoverTrapHook = Hooks::HookFunction(&CNWSCreature::AIActionRecoverTrap,
                                                 &AIActionRecoverTrapHook, Hooks::Order::Early);
        s_AIActionSetTrapHook = Hooks::HookFunction(&CNWSCreature::AIActionSetTrap,
                                             &AIActionSetTrapHook, Hooks::Order::Early);
        s_OnEnterTrapHook = Hooks::HookFunction(&CNWSTrigger::OnEnterTrap,
                                         &OnEnterTrapHook, Hooks::Order::Early);
    });
}

uint32_t HandleTrapHook(const std::string& event, Hooks::FunctionHook* originalTrapHook, CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    uint32_t retVal;
    std::string sAux;

    BOOL bInRange;
    if (event != "SET")
        bInRange = pCreature->GetIsInUseRange((ObjectID)pNode->m_pParameter[0]);
    else
    {
        if (auto *pGO = Utils::GetGameObject((uintptr_t)(pNode->m_pParameter[1])))
            bInRange = pCreature->GetIsInUseRange(pGO->m_idSelf, 0.5f, false);
        else
        {
            Vector vTarget = Vector(*(float*)&pNode->m_pParameter[2], *(float*)&pNode->m_pParameter[3], *(float*)&pNode->m_pParameter[4]);
            vTarget = VectorMath::Subtract(vTarget, VectorMath::Normalize(VectorMath::Subtract(pCreature->m_vPosition, vTarget)));
            bInRange = (VectorMath::MagnitudeSquared(VectorMath::Subtract(pCreature->m_vPosition, vTarget)) < 2.25f);
        }
    }

    if (!bInRange || !pCreature->m_bTrapAnimationPlayed) // BEFORE
    {
        PushEventData("NEEDS_TO_MOVE", std::to_string((uint32_t)!bInRange));
        PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0])));
        if (event == "SET")
        {
            PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1])));
            PushEventData("TARGET_POSITION_X", std::to_string(*(float*)&pNode->m_pParameter[2]));
            PushEventData("TARGET_POSITION_Y", std::to_string(*(float*)&pNode->m_pParameter[3]));
            PushEventData("TARGET_POSITION_Z", std::to_string(*(float*)&pNode->m_pParameter[4]));
        }

        if (SignalEvent("NWNX_ON_TRAP_" + event + "_BEFORE", pCreature->m_idSelf, &sAux))
        {
            retVal = originalTrapHook->CallOriginal<uint32_t>(pCreature, pNode);
        }
        else
        {
            retVal = atoi(sAux.c_str());
            if(retVal == 0)
                retVal = 3; //CNWSObject::ACTION_FAILED;

            PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0])));
            if (event == "SET")
            {
                PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1])));
                PushEventData("TARGET_POSITION_X", std::to_string(*(float*)&pNode->m_pParameter[2]));
                PushEventData("TARGET_POSITION_Y", std::to_string(*(float*)&pNode->m_pParameter[3]));
                PushEventData("TARGET_POSITION_Z", std::to_string(*(float*)&pNode->m_pParameter[4]));
            }
            PushEventData("ACTION_RESULT", std::to_string(retVal != 3));

            SignalEvent("NWNX_ON_TRAP_" + event + "_AFTER", pCreature->m_idSelf);
        }
    }
    else // AFTER
    {
        retVal = originalTrapHook->CallOriginal<uint32_t>(pCreature, pNode);

        PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0])));
        if (event == "SET")
        {
            PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1])));
            PushEventData("TARGET_POSITION_X", std::to_string(*(float*)&pNode->m_pParameter[2]));
            PushEventData("TARGET_POSITION_Y", std::to_string(*(float*)&pNode->m_pParameter[3]));
            PushEventData("TARGET_POSITION_Z", std::to_string(*(float*)&pNode->m_pParameter[4]));
        }
        PushEventData("ACTION_RESULT", std::to_string(retVal != 3));

        SignalEvent("NWNX_ON_TRAP_" + event + "_AFTER", pCreature->m_idSelf);
    }

    return retVal;
}

uint32_t AIActionDisarmTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("DISARM", s_AIActionDisarmTrapHook.get(), pCreature, pNode);
}

uint32_t AIActionExamineTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("EXAMINE", s_AIActionExamineTrapHook.get(), pCreature, pNode);
}

uint32_t AIActionFlagTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("FLAG", s_AIActionFlagTrapHook.get(), pCreature, pNode);
}

uint32_t AIActionRecoverTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("RECOVER", s_AIActionRecoverTrapHook.get(), pCreature, pNode);
}

uint32_t AIActionSetTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    return HandleTrapHook("SET", s_AIActionSetTrapHook.get(), pCreature, pNode);
}

void OnEnterTrapHook(CNWSTrigger *pTrigger, int32_t bForceSet)
{
    PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString(pTrigger->m_idSelf));
    PushEventData("TRAP_FORCE_SET", std::to_string(bForceSet));

    std::string forceSet;
    if (SignalEvent("NWNX_ON_TRAP_ENTER_BEFORE", pTrigger->m_oidLastEntered, &forceSet))
    {
        s_OnEnterTrapHook->CallOriginal<void>(pTrigger, bForceSet);
    }
    else if (!forceSet.empty())
    {
        s_OnEnterTrapHook->CallOriginal<void>(pTrigger, forceSet == "1");
    }

    PushEventData("TRAP_OBJECT_ID", Utils::ObjectIDToString(pTrigger->m_idSelf));
    SignalEvent("NWNX_ON_TRAP_ENTER_AFTER", pTrigger->m_oidLastEntered);
}

}
