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

    static Hooks::Hook s_EatTURDHook = Hooks::HookFunction(&CNWSPlayer::EatTURD,
    +[](CNWSPlayer *pThis, CNWSPlayerTURD *pTURD) -> void
    {
        s_EatTURDHook->CallOriginal<void>(pThis, pTURD);
        if (auto *pCreature = Utils::AsNWSCreature(pThis->GetGameObject()))
            pCreature->ReconcileAutoMapData();
    }, Hooks::Order::Early);
}

}
