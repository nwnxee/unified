#include "nwnx.hpp"

#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixAutoMapCrash() __attribute__((constructor));
void FixAutoMapCrash()
{
    if (!Config::Get<bool>("FIX_AUTOMAP_CRASH", false))
        return;

    LOG_INFO("Fixing a server crash that happens when automap data is outdated for a player.");

    static Hooks::Hook s_SetAutoMapDataHook = Hooks::HookFunction(&CNWSCreature::SetAutoMapData,
    +[](CNWSCreature *pThis, int32_t nNumAreas, OBJECT_ID *pAreaList, uint8_t **pMapTileData) -> void
    {
        s_SetAutoMapDataHook->CallOriginal<void>(pThis, nNumAreas, pAreaList, pMapTileData);
        pThis->ReconcileAutoMapData();
    }, Hooks::Order::Early);
}

}
