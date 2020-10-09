#pragma once

#include "Common.hpp"

namespace Tweaks {

class PlayerDyingHitPointLimit
{
public:
    PlayerDyingHitPointLimit(NWNXLib::Services::HooksProxy* hooker, int16_t hplimit);


private:
    static int32_t CNWSObject__GetIsPCDying_Hook(CNWSObject*);
    static int32_t CNWSObject__GetDead_Hook(CNWSObject*);
    static int16_t m_hplimit;
};

}
