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

    static int32_t ExamineTrapHook(CNWSMessage*, CNWSPlayer*, ObjectID, CNWSCreature*, int32_t);
};

}
