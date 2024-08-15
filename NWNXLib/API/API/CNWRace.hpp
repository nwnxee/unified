#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWRace)
#endif



typedef int BOOL;


struct CNWRace
{
    int32_t m_nNameStrref;
    int32_t m_nConverNameStrref;
    int32_t m_nConverNameLowerStrref;
    int32_t m_nNamePluralStrref;
    int32_t m_nDescriptionStrref;
    int32_t m_nDefaultBiographyStrref;
    char m_nSTRAdjust;
    char m_nDEXAdjust;
    char m_nINTAdjust;
    char m_nCHAAdjust;
    char m_nWISAdjust;
    char m_nCONAdjust;
    uint8_t m_nEndurance;
    uint8_t m_nFavoredClass;
    BOOL m_bIsPlayerRace;
    uint16_t m_nNumFeats;
    uint16_t * m_lstFeatTable;
    int32_t m_nAge;
    uint16_t m_nDefaultAppearance;
    CExoString m_sIcon;
    int32_t m_nExtraFeatsAtFirstLevel;
    int32_t m_nExtraSkillPointsPerLevel;
    int32_t m_nFirstLevelSkillPointsMultiplier;
    int32_t m_nAbilitiesPointBuyNumber;
    int32_t m_nNormalFeatEveryNthLevel;
    int32_t m_nNumberNormalFeatsEveryNthLevel;
    int32_t m_nSkillPointModifierAbility;
    uint16_t m_nFavoredEnemyFeat;

    CNWRace();
    ~CNWRace();
    CExoString GetNameText();
    CExoString GetConverNameText();
    CExoString GetConverNameLowerText();
    CExoString GetNamePluralText();
    CExoString GetDescriptionText();
    CExoString GetDefaultBiographyText();
    char GetAbilityAdjust(uint8_t nAbilityId);
    BOOL IsFirstLevelGrantedFeat(uint16_t nFeat);
    void LoadFeatsTable(CExoString sTable);


#ifdef NWN_CLASS_EXTENSION_CNWRace
    NWN_CLASS_EXTENSION_CNWRace
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWRace)
#endif

