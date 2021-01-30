#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class BlockDMSpawnItem
{
public:
    BlockDMSpawnItem();

private:
    static int32_t HandlePlayerToServerGameObjectUpdateHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
