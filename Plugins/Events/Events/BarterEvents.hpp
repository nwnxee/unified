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
    static int32_t HandlePlayerToServerBarter_StartBarterHook(CNWSMessage*, CNWSPlayer*);
    static void EndedBarter(bool, CNWSBarter*, int32_t);
    static void SetListAcceptedHook(bool, CNWSBarter*, int32_t);
    static void SendServerToPlayerBarterCloseBarterHook(bool, CNWSMessage*, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t);
};

}
