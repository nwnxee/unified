#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ExamineEvents
{
public:
    ExamineEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandleExamine(bool, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID);

    static void ExamineCreatureHook(bool, CNWSMessage*, CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExamineDoorHook(bool, CNWSMessage*, CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExamineItemHook(bool, CNWSMessage*, CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExaminePlaceableHook(bool, CNWSMessage*, CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExamineTrapHook(bool, CNWSMessage*,CNWSPlayer*, NWNXLib::API::Types::ObjectID, CNWSCreature*, int32_t);
};

}
