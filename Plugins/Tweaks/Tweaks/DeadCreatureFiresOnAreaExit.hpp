#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DeadCreatureFiresOnAreaExit
{
public:
    DeadCreatureFiresOnAreaExit();

private:
    static int32_t CNWSArea__RemoveObjectFromArea_hook(CNWSArea*, ObjectID);
};

}
