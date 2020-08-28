#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class BarterEvents
{
public:
    BarterEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerBarter_StartBarterHook(CNWSMessage*, CNWSPlayer*);
    static void EndedBarter(bool, CNWSBarter*, int32_t);
    static void SetListAcceptedHook(bool, CNWSBarter*, int32_t);
    static void SendServerToPlayerBarterCloseBarterHook(bool, CNWSMessage*, ObjectID, ObjectID, int32_t);
};

}
