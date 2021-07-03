#include "nwnx.hpp"

#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSArea.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixAoEObjectPositionBug() __attribute__((constructor));
void FixAoEObjectPositionBug()
{
    if (!Config::Get<bool>("FIX_AOE_OBJECT_POSITION_BUG", false))
        return;

    LOG_INFO("AoE Objects no longer break GetNearestXXX() functions.");

    static Hooks::Hook s_JumpToPointHook = Hooks::HookFunction(Functions::_ZN22CNWSAreaOfEffectObject11JumpToPointEP8CNWSAreaRK6Vector,
        (void*)+[](CNWSAreaOfEffectObject *pThis, CNWSArea *pNewArea, const Vector &vNewPos) -> void
        {
            if (auto *pLinkedTo = Utils::AsNWSCreature(Utils::GetGameObject(pThis->m_oidLinkedToObj)))
            {
                if (pThis->GetArea() == pNewArea)
                {
                    if (pLinkedTo->m_aInSubAreas.Contains(pThis->m_idSelf))
                    {
                        pLinkedTo->m_aInSubAreas.Remove(pThis->m_idSelf);
                    }

                    pThis->RemoveFromSubAreas();
                    pThis->SetPosition(vNewPos);
                    pLinkedTo->m_aInSubAreas.AddUnique(pThis->m_idSelf);
                    pThis->UpdateSubAreas();
                }
            }
        }, Hooks::Order::Final);

    static Hooks::Hook s_MoveToPointHook = Hooks::HookFunction(Functions::_ZN22CNWSAreaOfEffectObject11MoveToPointERK6Vector,
        (void*)+[](CNWSAreaOfEffectObject *pThis, const Vector &vNewPos) -> void
        {
           if (auto *pLinkedTo = Utils::AsNWSCreature(Utils::GetGameObject(pThis->m_oidLinkedToObj)))
           {
               pThis->SetPosition(vNewPos);
               pLinkedTo->m_aInSubAreas.AddUnique(pThis->m_idSelf);
               pThis->UpdateSubAreas();
           }
        }, Hooks::Order::Final);
}

}
