#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ObjectEvents
{
public:
    ObjectEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t AddLockObjectActionHook(CNWSObject*, NWNXLib::API::Types::ObjectID);
    static int32_t AddUnlockObjectActionHook(CNWSObject*, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t);
};

}
