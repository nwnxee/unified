#pragma once

#include "nwnx.hpp"

namespace Events {

class BarterEvents
{
public:
    BarterEvents();

private:
    static int32_t HandlePlayerToServerBarter_StartBarterHook(CNWSMessage*, CNWSPlayer*);
    static void EndedBarter(bool, CNWSBarter*, int32_t);
    static int32_t SetListAcceptedHook(CNWSBarter*, int32_t);
    static int32_t SendServerToPlayerBarterCloseBarterHook(CNWSMessage*, ObjectID, ObjectID, int32_t);
};

}
