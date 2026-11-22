#include "nwnx.hpp"

#include "API/CNWSAreaOfEffectObject.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixAoEJumpWithoutAreaCrash() __attribute__((constructor));
void FixAoEJumpWithoutAreaCrash()
{
    if (!Config::Get<bool>("FIX_AOE_JUMP_WITHOUT_AREA_CRASH", false))
        return;

    LOG_INFO("An area of effect that is in no area will not be moved when its creature jumps to another area.");

    static Hooks::Hook s_JumpToPointHook = Hooks::HookFunction(&CNWSAreaOfEffectObject::JumpToPoint,
        +[](CNWSAreaOfEffectObject *pAoE, CNWSArea *pNewArea, const Vector &vNewPos) -> void
        {
            if (!pNewArea && pAoE && !pAoE->GetArea())
            {
                LOG_WARNING("Skipped moving area of effect 0x%08x, which is in no area.", pAoE->m_idSelf);
                return;
            }
            s_JumpToPointHook->CallOriginal<void>(pAoE, pNewArea, vNewPos);
        }, Hooks::Order::Earliest);
}

}
