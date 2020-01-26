#include "Tweaks/FixScrollLearningBug.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CItemRepository.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

FixScrollLearningBug::FixScrollLearningBug(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN12CNWSCreature11LearnScrollEj>
                                    (&CNWSCreature__LearnScroll_hook);
}

BOOL FixScrollLearningBug::CNWSCreature__LearnScroll_hook(CNWSCreature *pThis, OBJECT_ID oidScrollToLearn)
{

    auto pServerExoApp = Globals::AppManager()->m_pServerExoApp;

    auto pItem = pServerExoApp->GetItemByGameObjectID(oidScrollToLearn);
    if (!pItem || pItem->m_nBaseItem != Constants::BaseItem::SpellScroll) {
        pThis->SendFeedbackMessage(0x4e, nullptr, nullptr);
        return false;
    }

    auto pActiveProperty = pItem->GetActiveProperty(0);
    if (!pActiveProperty)
        return false;

    int nSpellIndex;
    Globals::Rules()->m_p2DArrays->m_pIPRPSpells->GetINTEntry(pActiveProperty->m_nSubType, CExoString("SpellIndex"), &nSpellIndex);
    
    auto pSpell = Globals::Rules()->m_pSpellArray->GetSpell(nSpellIndex);
    if (!pSpell)
        return false;

    CItemRepository* pItemRepository = nullptr;
    auto pPossessor = pServerExoApp->GetGameObject(pItem->m_oidPossessor);
    if (pPossessor) {
        if (auto pCreature = Utils::AsNWSCreature(pPossessor)) {
            pItemRepository = pCreature->m_pcItemRepository;
        } else if (auto pItem = Utils::AsNWSItem(pPossessor)) {
            pItemRepository = pItem->m_pItemRepository;
            if (pItem->m_oidPossessor != pThis->m_idSelf)
                return false;
        }
    }

    if (!pItemRepository) //Not present in decompiled code
        return 0;
    
    if (!pItemRepository->GetItemInRepository(pItem, 0)) {
        pThis->SendFeedbackMessage(0xdc, nullptr, nullptr);
        return 0;
    }

    int nFeedback = 0;
    bool bLearned = false;
    for (int nMultiClass = 0; nMultiClass < pThis->m_pStats->m_nNumMultiClasses; nMultiClass++) {
        auto nClass = pThis->m_pStats->GetClass(nMultiClass);
        if (nClass >= Globals::Rules()->m_nNumClasses)
            continue;
        if (Globals::Rules()->m_lstClasses[nClass].m_bCanLearnFromScrolls) {
            auto nSpellLevel = pSpell->GetSpellLevel(nClass);
            if (nSpellLevel == (uint8_t) -1) {
                nFeedback = 0xe0;
                continue;
            }
            auto nSpellGain = pThis->m_pStats->GetSpellGainWithBonus(nMultiClass, nSpellLevel);
            if (nSpellGain == 0) {
                nFeedback = 0x50;
                continue;
            }
            if (!pThis->m_pStats->GetSpellMinAbilityMet(nMultiClass, nSpellLevel)) {
                nFeedback = 0x51;
                continue;
            }
            auto nSchool = pThis->m_pStats->GetSchool(nMultiClass);
            if (nSchool) {
                int nOppositeSchool = 0;
                auto pSchoolTable = Globals::Rules()->m_p2DArrays->m_pSpellSchoolTable;
                auto bFound = pSchoolTable->GetINTEntry(nSchool, "Opposition", &nOppositeSchool);
                if (bFound && pSpell->m_nSchool == nOppositeSchool) {
                    nFeedback = 0xdb;
                    continue;
                }
            }

            auto nKnownSpells = pThis->m_pStats->GetNumberKnownSpells(nMultiClass, nSpellLevel);
            bool bKnownSpell = false;
            for (int i = 0; i < nKnownSpells; i++) {
                if (pThis->m_pStats->GetKnownSpell(nMultiClass, nSpellLevel, i) == nSpellIndex) {
                    nFeedback = 0xdd;
                    bKnownSpell = true;
                    break;
                }
            }

            if (bKnownSpell)
                continue;

            pThis->m_pStats->AddKnownSpell(nMultiClass, nSpellIndex);
            bLearned = true;
        }
    }

    if (!bLearned) {
        pThis->SendFeedbackMessage(nFeedback ? nFeedback : 0x4f, nullptr, nullptr);
        return false;
    }

    if (pItem->m_nStackSize < 2)
        pThis->RemoveItem(pItem, 1, 1, 0, 1);
    else
        pItem->m_nStackSize -= 1;

    CNWCCMessageData* pMessageData = new CNWCCMessageData();
    pMessageData->SetInteger(0, nSpellIndex);
    pThis->SendFeedbackMessage(0xde, pMessageData, nullptr);
    return true;
}

}
