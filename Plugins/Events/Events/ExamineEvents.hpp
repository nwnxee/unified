#pragma once

#include "nwnx.hpp"

namespace Events {

class ExamineEvents
{
public:
    ExamineEvents();

private:
    static void HandleExamine(bool, ObjectID, ObjectID);

    static int32_t ExamineTrapHook(CNWSMessage*, CNWSPlayer*, ObjectID, CNWSCreature*, int32_t);
};

}
