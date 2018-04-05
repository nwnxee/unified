#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class PlayerDyingHitPointLimit
{
public:
    PlayerDyingHitPointLimit(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker, int16_t hplimit);

    
private:
    static int32_t CNWSObject__GetIsPCDying_Hook(NWNXLib::API::CNWSObject*);
    static int16_t m_hplimit;
};

}
