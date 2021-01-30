#include "Tweaks/ClearSpellEffectsOnTURDs.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSObject.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"



namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook *s_ClearSpellEffectsOnOthersHook;

ClearSpellEffectsOnTURDs::ClearSpellEffectsOnTURDs(Services::HooksProxy* hooker)
{
    s_ClearSpellEffectsOnOthersHook = hooker->Hook(Functions::_ZN10CNWSObject25ClearSpellEffectsOnOthersEv, (void*)&CNWSObject__ClearSpellEffectsOnOthers_hook, Hooking::Order::Early);
}


void ClearSpellEffectsOnTURDs::CNWSObject__ClearSpellEffectsOnOthers_hook(CNWSObject *pObject)
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
}


}
