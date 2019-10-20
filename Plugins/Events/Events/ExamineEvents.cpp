#include "Events/ExamineEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

ExamineEvents::ExamineEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_EXAMINE_OBJECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage41SendServerToPlayerExamineGui_CreatureDataEP10CNWSPlayerj, int32_t,
            API::CNWSMessage*, API::CNWSPlayer*, API::Types::ObjectID>(&ExamineCreatureHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_DoorDataEP10CNWSPlayerj, int32_t,
            API::CNWSMessage*, API::CNWSPlayer*, API::Types::ObjectID>(&ExamineDoorHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_ItemDataEP10CNWSPlayerj, int32_t,
            API::CNWSMessage*, API::CNWSPlayer*, API::Types::ObjectID>(&ExamineItemHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage42SendServerToPlayerExamineGui_PlaceableDataEP10CNWSPlayerj, int32_t,
            API::CNWSMessage*, API::CNWSPlayer*, API::Types::ObjectID>(&ExaminePlaceableHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_TrapDataEP10CNWSPlayerjP12CNWSCreaturei, int32_t,
            API::CNWSMessage*, API::CNWSPlayer*, API::Types::ObjectID, API::CNWSCreature*, int32_t>(&ExamineTrapHook);
    });
}

void ExamineEvents::HandleExamine(Services::Hooks::CallType type, API::Types::ObjectID examiner,
    API::Types::ObjectID examinee)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    Events::SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner);
}

void ExamineEvents::ExamineCreatureHook(Services::Hooks::CallType type, API::CNWSMessage*,
    API::CNWSPlayer* examiner, API::Types::ObjectID examinee)
{
    HandleExamine(type, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineDoorHook(Services::Hooks::CallType type, API::CNWSMessage*,
    API::CNWSPlayer* examiner, API::Types::ObjectID examinee)
{
    HandleExamine(type, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineItemHook(Services::Hooks::CallType type, API::CNWSMessage*,
    API::CNWSPlayer* examiner, API::Types::ObjectID examinee)
{
    HandleExamine(type, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExaminePlaceableHook(Services::Hooks::CallType type, API::CNWSMessage*,
    API::CNWSPlayer* examiner, API::Types::ObjectID examinee)
{
    HandleExamine(type, examiner->m_oidNWSObject, examinee);
}

void ExamineEvents::ExamineTrapHook(Services::Hooks::CallType type, API::CNWSMessage*,
                                         API::CNWSPlayer* examiner, API::Types::ObjectID examinee,
                                         API::CNWSCreature*, int32_t success)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    Events::PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    Events::PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(success));
    Events::SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner->m_oidNWSObject);
}

}
