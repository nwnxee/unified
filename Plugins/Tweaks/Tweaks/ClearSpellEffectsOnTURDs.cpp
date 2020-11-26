#include "Tweaks/ClearSpellEffectsOnTURDs.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSObject.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

#include "Services/Hooks/Hooks.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

ClearSpellEffectsOnTURDs::ClearSpellEffectsOnTURDs(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<Functions::_ZN10CNWSObject25ClearSpellEffectsOnOthersEv, uint32_t>(&CNWSObject__ClearSpellEffectsOnOthers_hook);
}


void ClearSpellEffectsOnTURDs::CNWSObject__ClearSpellEffectsOnOthers_hook(bool before, CNWSObject *pObject)
{
    if (before)
    {
        auto *pTURDList = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal;
        if (!pTURDList)
            return;

        for (auto *pNode = pTURDList->pHead; pNode; pNode = pNode->pNext)
        {
            auto *pTURD = static_cast<CNWSPlayerTURD*>(pNode->pObject);

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
}


}
