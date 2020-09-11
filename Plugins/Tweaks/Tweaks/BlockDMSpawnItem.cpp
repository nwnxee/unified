#include "Tweaks/BlockDMSpawnItem.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerGameObjectUpdateHook;

BlockDMSpawnItem::BlockDMSpawnItem(Services::HooksProxy* hooker)
{
    s_HandlePlayerToServerGameObjectUpdateHook =
            hooker->RequestExclusiveHook<Functions::_ZN11CNWSMessage36HandlePlayerToServerGameObjectUpdateEP10CNWSPlayerh>
                    (&HandlePlayerToServerGameObjectUpdateHook);
}

int32_t BlockDMSpawnItem::HandlePlayerToServerGameObjectUpdateHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    auto nMsgType = Utils::PeekMessage<uint8_t>(pMessage, 0);

    LOG_DEBUG("BlockDMSpawnItem: nMinor: %i, nMsgType: %i", nMinor, nMsgType);

    // TODO: add these as constants sometime
    if (nMinor == 1 && nMsgType == 65) // dm_spawnitem
        return false;
    else
        return s_HandlePlayerToServerGameObjectUpdateHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
}

}
