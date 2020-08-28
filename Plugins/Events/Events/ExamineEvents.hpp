#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ExamineEvents
{
public:
    ExamineEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandleExamine(bool, ObjectID, ObjectID);

    static void ExamineCreatureHook(bool, CNWSMessage*, CNWSPlayer*, ObjectID);
    static void ExamineDoorHook(bool, CNWSMessage*, CNWSPlayer*, ObjectID);
    static void ExamineItemHook(bool, CNWSMessage*, CNWSPlayer*, ObjectID);
    static void ExaminePlaceableHook(bool, CNWSMessage*, CNWSPlayer*, ObjectID);
    static void ExamineTrapHook(bool, CNWSMessage*,CNWSPlayer*, ObjectID, CNWSCreature*, int32_t);
};

}
