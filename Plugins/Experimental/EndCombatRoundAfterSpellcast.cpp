#include "nwnx.hpp"

#include "API/CNWSCombatRound.hpp"

namespace Experimental {

    using namespace NWNXLib;
    using namespace NWNXLib::API;

    void EndCombatRoundAfterSpellcast() __attribute__((constructor));
    void EndCombatRoundAfterSpellcast()
    {
        if (!Config::Get<bool>("END_COMBATROUND_AFTER_SPELLCAST", false))
            return;

        LOG_INFO("EXPERIMENTAL: Ending combat rounds after casting a spell.");

        static Hooks::Hook s_RemoveSpellAction_hook = Hooks::HookFunction(&CNWSCombatRound::RemoveSpellAction,
            +[](CNWSCombatRound* pThis) -> void
            {
                s_RemoveSpellAction_hook->CallOriginal<void>(pThis);
                if (pThis->m_bSpellCastRound)
                    pThis->EndCombatRound();
            }, Hooks::Order::Early);
    }
}
