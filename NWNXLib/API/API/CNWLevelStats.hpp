#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWLevelStats)
#endif



typedef int BOOL;


class CNWLevelStats
{
public:
    CExoArrayList<uint32_t> m_pAddedKnownSpellList[10];
    CExoArrayList<uint32_t> m_pRemovedKnownSpellList[10];
    CExoArrayList<uint16_t> m_lstFeats;
    char * m_lstSkillRanks;
    uint16_t m_nSkillPointsRemaining;
    uint8_t m_nAbilityGain;
    uint8_t m_nHitDie;
    uint8_t m_nClass;
    BOOL m_bEpic;

    CNWLevelStats();
    ~CNWLevelStats();
    void ClearFeats();
    void AddFeat(uint16_t nFeat);
    char GetSkillRankChange(uint16_t nSkill);
    void SetSkillRankChange(uint16_t nSkill, char nRank);


#ifdef NWN_CLASS_EXTENSION_CNWLevelStats
    NWN_CLASS_EXTENSION_CNWLevelStats
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWLevelStats)
#endif

