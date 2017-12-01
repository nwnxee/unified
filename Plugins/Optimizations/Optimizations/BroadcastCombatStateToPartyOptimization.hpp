#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

#include <cstdint>

namespace Optimizations {

class BroadcastCombatStateToPartyOptimization
{
public:
    BroadcastCombatStateToPartyOptimization(NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher);

private:
    static NWNXLib::API::CNWSPlayer* GetClientObjectByObjectIdPatch(NWNXLib::API::CServerExoApp*, NWNXLib::API::Types::ObjectID);
};

}
