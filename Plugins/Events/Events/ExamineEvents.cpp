#include "Events/ExamineEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

ExamineEvents::ExamineEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_EXAMINE_OBJECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage41SendServerToPlayerExamineGui_CreatureDataEP10CNWSPlayerj, int32_t,
            CNWSMessage*, CNWSPlayer*, ObjectID>(&ExamineCreatureHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_DoorDataEP10CNWSPlayerj, int32_t,
            CNWSMessage*, CNWSPlayer*, ObjectID>(&ExamineDoorHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_ItemDataEP10CNWSPlayerj, int32_t,
            CNWSMessage*, CNWSPlayer*, ObjectID>(&ExamineItemHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage42SendServerToPlayerExamineGui_PlaceableDataEP10CNWSPlayerj, int32_t,
            CNWSMessage*, CNWSPlayer*, ObjectID>(&ExaminePlaceableHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_TrapDataEP10CNWSPlayerjP12CNWSCreaturei, int32_t,
            CNWSMessage*, CNWSPlayer*, ObjectID, CNWSCreature*, int32_t>(&ExamineTrapHook);
    });
}

void ExamineEvents::HandleExamine(bool before, ObjectID examiner,
    ObjectID examinee)
{
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    Events::SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner);
}

void ExamineEvents::ExamineCreatureHook(bool before, CNWSMessage*,
    CNWSPlayer* examiner, ObjectID examinee)
{
    HandleExamine(before, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineDoorHook(bool before, CNWSMessage*,
    CNWSPlayer* examiner, ObjectID examinee)
{
    HandleExamine(before, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineItemHook(bool before, CNWSMessage*,
    CNWSPlayer* examiner, ObjectID examinee)
{
    HandleExamine(before, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExaminePlaceableHook(bool before, CNWSMessage*,
    CNWSPlayer* examiner, ObjectID examinee)
{
    HandleExamine(before, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineTrapHook(bool before, CNWSMessage*,
                                         CNWSPlayer* examiner, ObjectID examinee,
                                         CNWSCreature*, int32_t success)
{
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    Events::PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(success));
    Events::SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner->m_oidNWSObject);
}

}
