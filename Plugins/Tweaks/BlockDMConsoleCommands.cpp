#include "nwnx.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void BlockDMSpawnItem() __attribute__((constructor));
void BlockDMSpawnItem()
{
    static const auto SPAWN_CREATURE_DISABLED = Config::Get<bool>("BLOCK_DM_SPAWNCREATURE", false);
    static const auto SPAWN_ITEM_DISABLED = Config::Get<bool>("BLOCK_DM_SPAWNITEM", false);


    if (!SPAWN_CREATURE_DISABLED || !SPAWN_ITEM_DISABLED) 
        return;

    if (SPAWN_ITEM_DISABLED)
    	LOG_INFO("Blocking the 'dm_spawnitem' console command.");
    if (SPAWN_CREATURE_DISABLED)
    	LOG_INFO("Blocking the 'dm_spawncreature' console command.");

    static Hooks::Hook s_HandlePlayerToServerGameObjectUpdateHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage36HandlePlayerToServerGameObjectUpdateEP10CNWSPlayerh,
            (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor) -> int32_t
            {
                // The message types defining the dm command type
                const auto MSGTYPE_SPAWN_CREATURE = 67;
                const auto MSGTYPE_SPAWN_ITEM = 65;
                auto nMsgType = Utils::PeekMessage<uint8_t>(pMessage, 0);

                LOG_DEBUG("BlockDMConsoleCommands: nMinor: %i, nMsgType: %i", nMinor, nMsgType);

                if ((nMinor == 1 && nMsgType == MSGTYPE_SPAWN_CREATURE && SPAWN_CREATURE_DISABLED) || // dm_spawnitem
                   (nMinor == 1 && nMsgType == MSGTYPE_SPAWN_ITEM && SPAWN_ITEM_DISABLED)) // dm_spawncreature
                    return false;
                else
                    return s_HandlePlayerToServerGameObjectUpdateHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }, Hooks::Order::Late);
    }

}
