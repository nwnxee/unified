#include "Experimentals/UnhardcodeRangerDualWield.hpp"

#include "API/CFactionManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSModule.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

UnhardcodeRangerDualWield::UnhardcodeRangerDualWield()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats7HasFeatEt, (void*)&HasFeatHook, Hooks::Order::Final);
}

int32_t UnhardcodeRangerDualWield::HasFeatHook(CNWSCreatureStats* pCreatureStats, uint16_t nFeat)
{
    return pCreatureStats->m_lstFeats.Contains(nFeat) || pCreatureStats->m_lstBonusFeats.Contains(nFeat);
}

}
