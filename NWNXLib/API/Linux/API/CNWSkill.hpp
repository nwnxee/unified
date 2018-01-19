#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWSkill
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    CExoString m_sIconName;
    int32_t m_nKeyAbility;
    int32_t m_bHostileSkill;
    int32_t m_bUntrained;
    int32_t m_bArmorCheckPenalty;
    int32_t m_bAllClassesCanUse;

    // The below are auto generated stubs.
    CNWSkill(const CNWSkill&) = default;
    CNWSkill& operator=(const CNWSkill&) = default;

    CNWSkill();
    ~CNWSkill();
    CExoString GetDescriptionText();
    CExoString GetNameText();
};

void CNWSkill__CNWSkillCtor(CNWSkill* thisPtr);
void CNWSkill__CNWSkillDtor(CNWSkill* thisPtr);
CExoString CNWSkill__GetDescriptionText(CNWSkill* thisPtr);
CExoString CNWSkill__GetNameText(CNWSkill* thisPtr);

}

}
