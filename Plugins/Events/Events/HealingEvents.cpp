#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSObjectActionNode.hpp"

namespace Events {

using namespace NWNXLib;

static NWNXLib::Hooks::Hook s_AIActionHealHook;
static NWNXLib::Hooks::Hook s_OnApplyHealHook;

static uint32_t AIActionHealHook(CNWSCreature*, CNWSObjectActionNode*);
static int32_t OnApplyHealHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);

void HealingEvents() __attribute__((constructor));
void HealingEvents()
{
    InitOnFirstSubscribe("NWNX_ON_HEALER_KIT_.*", []() {
        s_AIActionHealHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature12AIActionHealEP20CNWSObjectActionNode,
                                          (void*)&AIActionHealHook, Hooks::Order::Early);
    });
    InitOnFirstSubscribe("NWNX_ON_HEAL_.*", []() {
        s_OnApplyHealHook = Hooks::HookFunction(API::Functions::_ZN21CNWSEffectListHandler11OnApplyHealEP10CNWSObjectP11CGameEffecti,
                                         (void*)&OnApplyHealHook, Hooks::Order::Early);
    });
}

uint32_t AIActionHealHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode)
{
    uint32_t retVal;
    std::string sAux;

    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0]))); //oidTarget
    PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1]))); //oidItemUsed
    PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uintptr_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    PushEventData("MOVE_TO_TARGET", std::to_string((uintptr_t)(pNode->m_pParameter[3]))); //nMoveToTarget

    if (SignalEvent("NWNX_ON_HEALER_KIT_BEFORE", pCreature->m_idSelf, &sAux))
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

    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[0]))); //oidTarget
    PushEventData("ITEM_OBJECT_ID", Utils::ObjectIDToString((uintptr_t)(pNode->m_pParameter[1]))); //oidItemUsed
    PushEventData("ITEM_PROPERTY_INDEX", std::to_string((uintptr_t)(pNode->m_pParameter[2]))); //nActiveItemPropertyIndex
    PushEventData("MOVE_TO_TARGET", std::to_string((uintptr_t)(pNode->m_pParameter[3]))); //nMoveToTarget
    PushEventData("ACTION_RESULT", std::to_string(retVal));

    SignalEvent("NWNX_ON_HEALER_KIT_AFTER", pCreature->m_idSelf);
    return retVal;
}

int32_t OnApplyHealHook(CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pGameEffect, int32_t bLoadingGame)
{
    int32_t retVal;
    std::string sAux;
    int32_t nHealAmount = pGameEffect->GetInteger(0);
    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(pObject->m_idSelf));
    PushEventData("HEAL_AMOUNT", std::to_string(nHealAmount));

    if (SignalEvent("NWNX_ON_HEAL_BEFORE", pGameEffect->m_oidCreator, &sAux))
    {
        retVal = s_OnApplyHealHook->CallOriginal<int32_t>(pThis, pObject, pGameEffect, bLoadingGame);
    }
    else
    {
        nHealAmount = atoi(sAux.c_str());
        pGameEffect->SetInteger(0, nHealAmount);
        retVal = s_OnApplyHealHook->CallOriginal<int32_t>(pThis, pObject, pGameEffect, bLoadingGame);
    }

    PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(pObject->m_idSelf));
    PushEventData("HEAL_AMOUNT", std::to_string(nHealAmount));
    PushEventData("ACTION_RESULT", std::to_string(retVal));

    SignalEvent("NWNX_ON_HEAL_AFTER", pGameEffect->m_oidCreator);
    return retVal;
}

}
