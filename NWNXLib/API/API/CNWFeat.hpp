#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWFeat)
#endif



typedef int BOOL;


struct CNWFeat
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    CResRef m_cIcon;
    BOOL m_bGainMultiple;
    BOOL m_bAllClassesCanUse;
    BOOL m_bTargetSelf;
    BOOL m_bHostileFeat;
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
    uint32_t m_nSpellId;
    uint8_t m_nUsesPerDay;
    BOOL m_bValidFeat;
    BOOL m_bRequiresEpic;
    BOOL m_bRequiresAction;

    CNWFeat();
    ~CNWFeat();
    CExoString GetNameText();
    CExoString GetDescriptionText();


#ifdef NWN_CLASS_EXTENSION_CNWFeat
    NWN_CLASS_EXTENSION_CNWFeat
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWFeat)
#endif

