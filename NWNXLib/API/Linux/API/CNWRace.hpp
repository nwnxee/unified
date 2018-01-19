#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

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
    int32_t m_bIsPlayerRace;
    uint16_t m_nNumFeats;
    uint16_t* m_lstFeatTable;
    int32_t m_nAge;
    uint16_t m_nDefaultAppearance;

    // The below are auto generated stubs.
    CNWRace(const CNWRace&) = default;
    CNWRace& operator=(const CNWRace&) = default;

    CNWRace();
    ~CNWRace();
    CExoString GetConverNameLowerText();
    CExoString GetConverNameText();
    CExoString GetDefaultBiographyText();
    CExoString GetDescriptionText();
    CExoString GetNamePluralText();
    CExoString GetNameText();
    int32_t IsFirstLevelGrantedFeat(uint16_t);
    void LoadFeatsTable(CExoString);
};

void CNWRace__CNWRaceCtor(CNWRace* thisPtr);
void CNWRace__CNWRaceDtor(CNWRace* thisPtr);
CExoString CNWRace__GetConverNameLowerText(CNWRace* thisPtr);
CExoString CNWRace__GetConverNameText(CNWRace* thisPtr);
CExoString CNWRace__GetDefaultBiographyText(CNWRace* thisPtr);
CExoString CNWRace__GetDescriptionText(CNWRace* thisPtr);
CExoString CNWRace__GetNamePluralText(CNWRace* thisPtr);
CExoString CNWRace__GetNameText(CNWRace* thisPtr);
int32_t CNWRace__IsFirstLevelGrantedFeat(CNWRace* thisPtr, uint16_t);
void CNWRace__LoadFeatsTable(CNWRace* thisPtr, CExoString);

}

}
