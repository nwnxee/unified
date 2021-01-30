#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class BlockDMSpawnItem
{
public:
    BlockDMSpawnItem(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerGameObjectUpdateHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
