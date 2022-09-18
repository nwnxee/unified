#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSkill)
#endif



typedef int BOOL;


struct CNWSkill
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    CExoString m_sIconName;
    int32_t m_nKeyAbility;
    BOOL m_bHostileSkill;
    BOOL m_bUntrained;
    BOOL m_bArmorCheckPenalty;
    BOOL m_bAllClassesCanUse;
    BOOL m_bHideFromLevelUp;

    CNWSkill();
    ~CNWSkill();
    CExoString GetNameText();
    CExoString GetDescriptionText();


#ifdef NWN_CLASS_EXTENSION_CNWSkill
    NWN_CLASS_EXTENSION_CNWSkill
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSkill)
#endif

