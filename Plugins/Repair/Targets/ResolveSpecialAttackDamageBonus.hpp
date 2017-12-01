#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

#include <sys/socket.h>

namespace Repair {

class ResolveSpecialAttackDamageBonus
{
public:
    ResolveSpecialAttackDamageBonus(
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher,
        NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log);

private:
    static int32_t ResolveSpecialAttackDamageBonusInlineHook(NWNXLib::API::CNWSCreatureStats* thisPtr);
};

}
