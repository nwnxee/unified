#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWFeat
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    CResRef m_cIcon;
    int32_t m_bGainMultiple;
    int32_t m_bAllClassesCanUse;
    int32_t m_bTargetSelf;
    int32_t m_bHostileFeat;
    uint8_t m_nMinAttackBonus;
    uint8_t m_nMinSTR;
    uint8_t m_nMinDEX;
    uint8_t m_nMinINT;
    uint8_t m_nMinWIS;
    uint8_t m_nMinCON;
    uint8_t m_nMinCHA;
    uint8_t m_nMinSpellLevel;
    uint16_t m_lstPrereqFeats[2];
    uint16_t m_lstOrPrereqFeats[5];
    uint16_t m_nRequiredSkill;
    uint16_t m_nMinRequiredSkillRank;
    uint16_t m_nRequiredSkill2;
    uint16_t m_nMinRequiredSkillRank2;
    int32_t m_nSuccessor;
    char m_nMasterFeat;
    uint8_t m_nMinLevel;
    uint8_t m_nMaxLevel;
    uint8_t m_nMinLevelClass;
    uint8_t m_nMinFortSave;
    int32_t m_nSpellId;
    uint8_t m_nUsesPerDay;
    int32_t m_bValidFeat;
    int32_t m_bRequiresEpic;
    int32_t m_bRequiresAction;

    // The below are auto generated stubs.
    CNWFeat(const CNWFeat&) = default;
    CNWFeat& operator=(const CNWFeat&) = default;

    CNWFeat();
    ~CNWFeat();
    CExoString GetDescriptionText();
    CExoString GetNameText();
};

void CNWFeat__CNWFeatCtor(CNWFeat* thisPtr);
void CNWFeat__CNWFeatDtor(CNWFeat* thisPtr);
CExoString CNWFeat__GetDescriptionText(CNWFeat* thisPtr);
CExoString CNWFeat__GetNameText(CNWFeat* thisPtr);

}

}
