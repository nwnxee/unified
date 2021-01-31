#include "Tweaks/FixGreaterSanctuaryBug.hpp"


#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

FixGreaterSanctuaryBug::FixGreaterSanctuaryBug()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN12CNWSCreature31RemoveCombatInvisibilityEffectsEv,
                 (void*)&CNWSCreature__RemoveCombatInvisibilityEffects_hook, Hooks::Order::Final);
}

void FixGreaterSanctuaryBug::CNWSCreature__RemoveCombatInvisibilityEffects_hook(CNWSCreature *pThis)
{
    int sanctPtr = pThis->m_pStats->m_nSanctuaryPtr;
    int invPtr = pThis->m_pStats->m_nInvisibilityPtr;
    int startPtr = invPtr>sanctPtr ? sanctPtr : invPtr;

    std::vector<uint64_t> remove(128);
    for (int k = startPtr; k < pThis->m_appliedEffects.num; k++)
    {
        auto eff = pThis->m_appliedEffects.element[k];
        if( eff->m_nType == 63 ||
            (eff->m_nType == 47 && eff->GetInteger(0)==1))
        {
            remove.push_back(eff->m_nID);
        }
    }

    for (auto id: remove)
        pThis->RemoveEffectById(id);
}

}
