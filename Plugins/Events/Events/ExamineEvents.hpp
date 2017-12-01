#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class ExamineEvents
{
public:
    ExamineEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void HandleExamine(NWNXLib::Services::Hooks::CallType, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID);

    static void ExamineCreatureHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*,
        NWNXLib::API::CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExamineDoorHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*,
        NWNXLib::API::CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExamineItemHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*,
        NWNXLib::API::CNWSPlayer*, NWNXLib::API::Types::ObjectID);
    static void ExaminePlaceableHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*,
        NWNXLib::API::CNWSPlayer*, NWNXLib::API::Types::ObjectID);
};

}
