#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CCombatInformation)
#endif

struct CCombatInformationNode;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


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
    BOOL m_bOffHandWeaponEquipped;
    uint8_t m_nOffHandCriticalHitRange;
    uint8_t m_nOffHandCriticalHitMultiplier;
    CExoArrayList<CCombatInformationNode *> m_pAttackList;
    CExoArrayList<CCombatInformationNode *> m_pDamageList;
    OBJECT_ID m_oidRightEquipped;
    OBJECT_ID m_oidLeftEquipped;
    CExoString m_sRightEquipped;
    CExoString m_sLeftEquipped;
    uint8_t m_nDamageDice;
    uint8_t m_nDamageDie;

    CCombatInformation();
    CCombatInformation(CCombatInformation * m_ExistingCombatDataToCopy);
    ~CCombatInformation();
    BOOL SaveData(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadData(CResGFF * pRes, CResStruct * pStruct);
    BOOL operator==(CCombatInformation & pData);
    BOOL operator!=(CCombatInformation & pData);
    CCombatInformation & operator=(CCombatInformation & pData);


#ifdef NWN_CLASS_EXTENSION_CCombatInformation
    NWN_CLASS_EXTENSION_CCombatInformation
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CCombatInformation)
#endif

