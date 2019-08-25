#include "Tweaks/MaxLevel.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"
#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWRules.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

uint8_t MaxLevel::m_maxLevel;
uint32_t MaxLevel::m_nExperienceTableAdded[20];
MaxLevel::MaxLevel(ViewPtr<Services::HooksProxy> hooker, uint8_t maxLevel)
{
    m_maxLevel = maxLevel;

    hooker->RequestExclusiveHook<Functions::CNWSCreatureStats__CanLevelUp>
                                    (&CNWSCreatureStats__CanLevelUp_hook);
    hooker->RequestSharedHook<Functions::CNWRules__ReloadAll, void, CNWRules*>(&ReloadAllHook);
}

void MaxLevel::ReloadAllHook(Services::Hooks::CallType type, CNWRules* pRules)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    if (before || !pRules)
        return;

    uint8_t moreLevels = m_maxLevel - 40;
    int32_t xpLevel = 0;
    for (int i = 0; i < moreLevels; i++)
    {
        auto *twoda = new C2DA(CResRef("EXPTABLE"), 1);
        twoda->Load2DArray();
        twoda->GetINTEntry(40 + i, 1, &xpLevel);
        m_nExperienceTableAdded[i] = xpLevel;
    }
}

int32_t MaxLevel::CNWSCreatureStats__CanLevelUp_hook(CNWSCreatureStats* pStats)
{
    auto pCreature = pStats->m_pBaseCreature;
    if ((pCreature->m_nAssociateType >= 5 && pCreature->m_nAssociateType <= 8) || pCreature->m_nAssociateType == 2)
    {
        return false;
    }
    int32_t totalLevels = 0;
    for (int i = 0; i < pStats->m_nNumMultiClasses; i++)
    {
        totalLevels += pStats->m_ClassInfo[i].m_nLevel;
    }
    if (totalLevels >= m_maxLevel)
        return 0;
    auto xp = pStats->m_nExperience;
    uint32_t xp_threshold = 0;
    if (totalLevels <= 40)
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels-1];
    else
        xp_threshold = m_nExperienceTableAdded[totalLevels-40];

    if (!pStats->m_bIsPC)
        return 1;
    if (xp < xp_threshold)
        return 0;
    return 1;
}

}
