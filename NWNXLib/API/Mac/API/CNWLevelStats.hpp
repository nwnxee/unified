#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoArrayListTemplatedshortunsignedint.hpp"

namespace NWNXLib {

namespace API {

struct CNWLevelStats
{
    CExoArrayListTemplatedlongunsignedint m_pAddedKnownSpellList[10];
    CExoArrayListTemplatedlongunsignedint m_pRemovedKnownSpellList[10];
    CExoArrayListTemplatedshortunsignedint m_lstFeats;
    char* m_lstSkillRanks;
    uint16_t m_nSkillPointsRemaining;
    uint8_t m_nAbilityGain;
    uint8_t m_nHitDie;
    uint8_t m_nClass;
    int32_t m_bEpic;

    // The below are auto generated stubs.
    CNWLevelStats(const CNWLevelStats&) = default;
    CNWLevelStats& operator=(const CNWLevelStats&) = default;

    CNWLevelStats();
    ~CNWLevelStats();
    void AddFeat(uint16_t);
    void ClearFeats();
    char GetSkillRankChange(uint16_t);
    void SetSkillRankChange(uint16_t, char);
};

void CNWLevelStats__CNWLevelStatsCtor__0(CNWLevelStats* thisPtr);
void CNWLevelStats__CNWLevelStatsDtor__0(CNWLevelStats* thisPtr);
void CNWLevelStats__AddFeat(CNWLevelStats* thisPtr, uint16_t);
void CNWLevelStats__ClearFeats(CNWLevelStats* thisPtr);
char CNWLevelStats__GetSkillRankChange(CNWLevelStats* thisPtr, uint16_t);
void CNWLevelStats__SetSkillRankChange(CNWLevelStats* thisPtr, uint16_t, char);

}

}
