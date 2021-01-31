#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class PlayerDyingHitPointLimit
{
public:
    PlayerDyingHitPointLimit(int16_t hplimit);


private:
    static int32_t CNWSObject__GetIsPCDying_Hook(CNWSObject*);
    static int32_t CNWSObject__GetDead_Hook(CNWSObject*);
    static int16_t m_hplimit;
};

}
