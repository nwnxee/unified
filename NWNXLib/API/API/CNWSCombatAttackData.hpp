#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCombatAttackData)
#endif

struct CGameEffect;
struct CNWCCMessageData;
struct CNWSSpellScriptData;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSCombatAttackData
{
    uint8_t m_nAttackGroup;
    uint16_t m_nAnimationLength;
    OBJECT_ID m_oidReactObject;
    uint16_t m_nReactionDelay;
    uint16_t m_nReactionAnimation;
    uint16_t m_nReactionAnimationLength;
    uint8_t m_nToHitRoll;
    uint8_t m_nThreatRoll;
    int32_t m_nToHitMod;
    char m_nMissedBy;
    int16_t m_nDamage[32];
    uint8_t m_nWeaponAttackType;
    uint8_t m_nAttackMode;
    uint8_t m_nConcealment;
    BOOL m_bRangedAttack;
    BOOL m_bSneakAttack;
    BOOL m_bDeathAttack;
    BOOL m_bKillingBlow;
    BOOL m_bCoupDeGrace;
    BOOL m_bCriticalThreat;
    BOOL m_bAttackDeflected;
    uint8_t m_nAttackResult;
    uint16_t m_nAttackType;
    uint16_t m_nSpecialAttackID;
    Vector m_vRangedTarget;
    OBJECT_ID m_oidAmmunition;
    CExoString m_sAttackDebugText;
    CExoString m_sDamageDebugText;
    CExoArrayList<CGameEffect *> m_alstOnHitGameEffects;
    CExoArrayList<CNWSSpellScriptData *> m_alstOnHitSpellScripts;
    CExoArrayList<CNWSSpellScriptData *> m_alstOnHitEnemySpellScripts;
    CExoArrayList<CNWCCMessageData *> m_alstPendingFeedback;

    CNWSCombatAttackData();
    ~CNWSCombatAttackData();
    void ClearAttackData();
    void Copy(CNWSCombatAttackData * pData, BOOL bCopyDebugInfo = false);
    void SetBaseDamage(int32_t nDamage);
    void SetDamage(uint32_t damageFlags, int32_t nDamage);
    void AddDamage(uint32_t damageFlags, int32_t nDamage);
    int32_t GetDamage(uint32_t damageFlags);
    int32_t GetTotalDamage(BOOL bBaseDamage = false);
    BOOL SaveData(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadData(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSCombatAttackData
    NWN_CLASS_EXTENSION_CNWSCombatAttackData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCombatAttackData)
#endif

