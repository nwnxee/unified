#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ObjectEvents
{
public:
    ObjectEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t AddLockObjectActionHook(CNWSObject*, ObjectID);
    static int32_t AddUnlockObjectActionHook(CNWSObject*, ObjectID, ObjectID, int32_t);
};

}
