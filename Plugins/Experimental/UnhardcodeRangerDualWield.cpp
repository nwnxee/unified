#include "nwnx.hpp"
#include "API/CFactionManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSModule.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_HasFeatHook;

void UnhardcodeRangerDualWield() __attribute__((constructor));
void UnhardcodeRangerDualWield()
{
    if (!Config::Get<bool>("UNHARDCODE_RANGER_DUALWIELD", false))
        return;

    LOG_INFO("EXPERIMENTAL: Unhardcoding Ranger DualWield Feat.");

    s_HasFeatHook = Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats7HasFeatEt,
        (void*)+[](CNWSCreatureStats* pCreatureStats, uint16_t nFeat) -> int32_t
        {
            return pCreatureStats->m_lstFeats.Contains(nFeat) || pCreatureStats->m_lstBonusFeats.Contains(nFeat);
        }, Hooks::Order::Final);
}

}

