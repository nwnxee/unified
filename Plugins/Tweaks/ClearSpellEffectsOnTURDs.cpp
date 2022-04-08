#include "nwnx.hpp"

#include "API/CNWSModule.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void ClearSpellEffectsOnTURDs() __attribute__((constructor));
void ClearSpellEffectsOnTURDs()
{
    if (!Config::Get<bool>("CLEAR_SPELL_EFFECTS_ON_TURDS", false))
        return;

    LOG_INFO("Effects on logged out users will be removed when a caster rests.");

    static Hooks::Hook s_ClearSpellEffectsOnOthersHook =
            Hooks::HookFunction(Functions::_ZN10CNWSObject25ClearSpellEffectsOnOthersEv,
            (void*)+[](CNWSObject *pObject) -> void
            {
                if (auto *pTURDList = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal)
                {
                    for (auto *pNode = pTURDList->pHead; pNode; pNode = pNode->pNext)
                    {
                        auto *pTURD = static_cast<CNWSPlayerTURD *>(pNode->pObject);

                        if (pTURD)
                        {
                            std::vector<uint64_t> remove(128);
                            for (int i = 0; i < pTURD->m_appliedEffects.num; i++)
                            {
                                auto *pEffect = pTURD->m_appliedEffects.element[i];

                                if (pEffect->m_oidCreator == pObject->m_idSelf)
                                    remove.push_back(pEffect->m_nID);
                            }
                            for (auto id: remove)
                                pTURD->RemoveEffectById(id);
                        }
                    }
                }
                s_ClearSpellEffectsOnOthersHook->CallOriginal<void>(pObject);
            }, Hooks::Order::Early);
}

}
