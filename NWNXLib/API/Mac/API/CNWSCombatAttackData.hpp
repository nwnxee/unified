#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCGameEffectPtr.hpp"
#include "CExoArrayListTemplatedCNWCCMessageDataPtr.hpp"
#include "CExoArrayListTemplatedCNWSSpellScriptDataPtr.hpp"
#include "CExoString.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CNWSCombatAttackData
{
    uint8_t m_nAttackGroup;
    uint16_t m_nAnimationLength;
    uint32_t m_oidReactObject;
    uint16_t m_nReactionDelay;
    uint16_t m_nReactionAnimation;
    uint16_t m_nReactionAnimationLength;
    uint8_t m_nToHitRoll;
    uint8_t m_nThreatRoll;
    int32_t m_nToHitMod;
    char m_nMissedBy;
    int16_t m_nDamage[13];
    uint8_t m_nWeaponAttackType;
    uint8_t m_nAttackMode;
    uint8_t m_nConcealment;
    int32_t m_bRangedAttack;
    int32_t m_bSneakAttack;
    int32_t m_bDeathAttack;
    int32_t m_bKillingBlow;
    int32_t m_bCoupDeGrace;
    int32_t m_bCriticalThreat;
    int32_t m_bAttackDeflected;
    uint8_t m_nAttackResult;
    uint16_t m_nAttackType;
    uint16_t m_nSpecialAttackID;
    Vector m_vRangedTarget;
    uint32_t m_oidAmmunition;
    CExoString m_sAttackDebugText;
    CExoString m_sDamageDebugText;
    CExoArrayListTemplatedCGameEffectPtr m_alstOnHitGameEffects;
    CExoArrayListTemplatedCNWSSpellScriptDataPtr m_alstOnHitSpellScripts;
    CExoArrayListTemplatedCNWSSpellScriptDataPtr m_alstOnHitEnemySpellScripts;
    CExoArrayListTemplatedCNWCCMessageDataPtr m_alstPendingFeedback;

    // The below are auto generated stubs.
    CNWSCombatAttackData(const CNWSCombatAttackData&) = default;
    CNWSCombatAttackData& operator=(const CNWSCombatAttackData&) = default;

    CNWSCombatAttackData();
    ~CNWSCombatAttackData();
    void AddDamage(uint16_t, int32_t);
    void ClearAttackData();
    void Copy(CNWSCombatAttackData*, int32_t);
    int32_t GetDamage(uint16_t);
    int32_t GetTotalDamage(int32_t);
    int32_t LoadData(CResGFF*, CResStruct*);
    int32_t SaveData(CResGFF*, CResStruct*);
    void SetBaseDamage(int32_t);
    void SetDamage(uint16_t, int32_t);
};

void CNWSCombatAttackData__CNWSCombatAttackDataCtor__0(CNWSCombatAttackData* thisPtr);
void CNWSCombatAttackData__CNWSCombatAttackDataDtor__0(CNWSCombatAttackData* thisPtr);
void CNWSCombatAttackData__AddDamage(CNWSCombatAttackData* thisPtr, uint16_t, int32_t);
void CNWSCombatAttackData__ClearAttackData(CNWSCombatAttackData* thisPtr);
void CNWSCombatAttackData__Copy(CNWSCombatAttackData* thisPtr, CNWSCombatAttackData*, int32_t);
int32_t CNWSCombatAttackData__GetDamage(CNWSCombatAttackData* thisPtr, uint16_t);
int32_t CNWSCombatAttackData__GetTotalDamage(CNWSCombatAttackData* thisPtr, int32_t);
int32_t CNWSCombatAttackData__LoadData(CNWSCombatAttackData* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSCombatAttackData__SaveData(CNWSCombatAttackData* thisPtr, CResGFF*, CResStruct*);
void CNWSCombatAttackData__SetBaseDamage(CNWSCombatAttackData* thisPtr, int32_t);
void CNWSCombatAttackData__SetDamage(CNWSCombatAttackData* thisPtr, uint16_t, int32_t);

}

}
