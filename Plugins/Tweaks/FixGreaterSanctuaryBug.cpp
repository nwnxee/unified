#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixGreaterSanctuaryBug() __attribute__((constructor));
void FixGreaterSanctuaryBug()
{
    if (!Config::Get<bool>("FIX_GREATER_SANCTUARY_BUG", false))
        return;

    LOG_INFO("Greater sanctuary bug fixed.");

    static Hooks::Hook s_RemoveCombatInvisibilityEffectsHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature31RemoveCombatInvisibilityEffectsEv,
                (void*)+[](CNWSCreature *pThis) -> void
                {
                    int sanctPtr = pThis->m_pStats->m_nSanctuaryPtr;
                    int invPtr = pThis->m_pStats->m_nInvisibilityPtr;
                    int startPtr = invPtr > sanctPtr ? sanctPtr : invPtr;

                    std::vector<uint64_t> remove(128);
                    for (int k = startPtr; k < pThis->m_appliedEffects.num; k++)
                    {
                        auto *pEffect = pThis->m_appliedEffects.element[k];
                        if (pEffect->m_nType == 63 || (pEffect->m_nType == 47 && pEffect->GetInteger(0) == 1))
                        {
                            remove.push_back(pEffect->m_nID);
                        }
                    }

                    for (auto id: remove)
                        pThis->RemoveEffectById(id);
                }, Hooks::Order::Final);
}

}
