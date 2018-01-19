#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCCombatInformationNodePtr.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CCombatInformation
{
    uint8_t m_nNumAttacks;
    char m_nOnHandAttackModifier;
    char m_nOnHandDamageModifier;
    char m_nOffHandAttackModifier;
    char m_nOffHandDamageModifier;
    uint8_t m_nSpellResistance;
    uint8_t m_nArcaneSpellFailure;
    uint8_t m_nArmorCheckPenalty;
    uint8_t m_nUnarmedDamageDice;
    uint8_t m_nUnarmedDamageDie;
    uint8_t m_nCreatureDamageDice[3];
    uint8_t m_nCreatureDamageDie[3];
    char m_nCreatureDamageModifier[3];
    uint8_t m_nOnHandCriticalHitRange;
    uint8_t m_nOnHandCriticalHitMultiplier;
    int32_t m_bOffHandWeaponEquipped;
    uint8_t m_nOffHandCriticalHitRange;
    uint8_t m_nOffHandCriticalHitMultiplier;
    CExoArrayListTemplatedCCombatInformationNodePtr m_pAttackList;
    CExoArrayListTemplatedCCombatInformationNodePtr m_pDamageList;
    uint32_t m_oidRightEquipped;
    uint32_t m_oidLeftEquipped;
    CExoString m_sRightEquipped;
    CExoString m_sLeftEquipped;
    uint8_t m_nDamageDice;
    uint8_t m_nDamageDie;

    // The below are auto generated stubs.
    CCombatInformation(const CCombatInformation&) = default;

    CCombatInformation();
    ~CCombatInformation();
    int32_t LoadData(CResGFF*, CResStruct*);
    int32_t operator!=(CCombatInformation&);
    CCombatInformation& operator=(CCombatInformation&);
    int32_t operator==(CCombatInformation&);
    int32_t SaveData(CResGFF*, CResStruct*);
};

void CCombatInformation__CCombatInformationCtor(CCombatInformation* thisPtr);
void CCombatInformation__CCombatInformationDtor(CCombatInformation* thisPtr);
int32_t CCombatInformation__LoadData(CCombatInformation* thisPtr, CResGFF*, CResStruct*);
int32_t CCombatInformation__OperatorNotEqualTo(CCombatInformation* thisPtr, CCombatInformation&);
CCombatInformation& CCombatInformation__OperatorAssignment(CCombatInformation* thisPtr, CCombatInformation&);
int32_t CCombatInformation__OperatorEqualTo(CCombatInformation* thisPtr, CCombatInformation&);
int32_t CCombatInformation__SaveData(CCombatInformation* thisPtr, CResGFF*, CResStruct*);

}

}
