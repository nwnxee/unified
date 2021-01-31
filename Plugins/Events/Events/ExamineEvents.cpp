#include "Events/ExamineEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

static Hooks::Hook s_SendServerToPlayerExamineGui_TrapDataHook;

ExamineEvents::ExamineEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_EXAMINE_OBJECT_.*", []() {

        #define HOOK_EXAMINE(_address) \
            static Hooks::Hook CAT(pExamineHook, __LINE__) = Hooks::HookFunction(_address, \
            (void*)+[](CNWSMessage *pMessage, CNWSPlayer* pPlayer, ObjectID oidObject) -> int32_t \
            { \
                HandleExamine(true, pPlayer->m_oidNWSObject, oidObject); \
                auto retVal = CAT(pExamineHook, __LINE__)->CallOriginal<int32_t>(pMessage, pPlayer, oidObject); \
                HandleExamine(false, pPlayer->m_oidNWSObject, oidObject);  \
                return retVal; \
            }, Hooks::Order::Earliest)

                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage41SendServerToPlayerExamineGui_CreatureDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_DoorDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_ItemDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage42SendServerToPlayerExamineGui_PlaceableDataEP10CNWSPlayerj);

        #undef HOOK_EXAMINE

        s_SendServerToPlayerExamineGui_TrapDataHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_TrapDataEP10CNWSPlayerjP12CNWSCreaturei,
                (void*)&ExamineTrapHook, Hooks::Order::Earliest);
    });
}

void ExamineEvents::HandleExamine(bool before, ObjectID examiner, ObjectID examinee)
{
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    Events::SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner);
}

int32_t ExamineEvents::ExamineTrapHook(CNWSMessage *pMessage, CNWSPlayer* pPlayer, ObjectID oidTrapID, CNWSCreature *pCreature, int32_t bSuccess)
{
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(oidTrapID));
    Events::PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(bSuccess));
    Events::SignalEvent("NWNX_ON_EXAMINE_OBJECT_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_SendServerToPlayerExamineGui_TrapDataHook->CallOriginal<int32_t>(pMessage, pPlayer, oidTrapID, pCreature, bSuccess);
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(oidTrapID));
    Events::PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(bSuccess));
    Events::SignalEvent("NWNX_ON_EXAMINE_OBJECT_AFTER", pPlayer->m_oidNWSObject);
    return retVal;
}

}
