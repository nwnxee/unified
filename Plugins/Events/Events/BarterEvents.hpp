#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class BarterEvents
{
public:
    BarterEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePlayerToServerBarter_StartBarterHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
    static void EndedBarter(
            NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSBarter*,
            int32_t);
    static void SetListAcceptedHook(
            NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSBarter*,
            int32_t);
    static void SendServerToPlayerBarterCloseBarterHook(
            NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSMessage*,
            NWNXLib::API::Types::ObjectID,
            NWNXLib::API::Types::ObjectID,
            int32_t);
};

}
