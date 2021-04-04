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
    static int32_t PermittedToDisplayCharacterSheetHook(CNWSPlayer*, ObjectID);
    static int32_t HandlePlayerToServerCharacterSheetMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
