#include "Optimizations/BroadcastCombatStateToPartyOptimization.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Version.hpp"
#include "Services/Patching/Patching.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

BroadcastCombatStateToPartyOptimization::BroadcastCombatStateToPartyOptimization(ViewPtr<Services::PatchingProxy> patcher)
{
    patcher->PatchWithCall(0x08128DB1, 0x08128DB6 - 0x08128DB1, &GetClientObjectByObjectIdPatch); NWNX_EXPECT_VERSION(8109);
}

CNWSPlayer* BroadcastCombatStateToPartyOptimization::GetClientObjectByObjectIdPatch(CServerExoApp* thisPtr, Types::ObjectID objId)
{
    if (objId <= Constants::OBJECT_INVALID)
    {
        // This object ID isn't a player object as all players object start at OBJECT_INVALID upwards.
        // This optimization is *technically* incorrect because the active game object might be a possessed creature.
        // However, all the branch does is set the excited flag, which really isn't a big deal.
        // So we trade incorrect behaviour for a big leap in speed here.
        return nullptr;
    }

    return thisPtr->GetClientObjectByObjectId(objId);
}

}
