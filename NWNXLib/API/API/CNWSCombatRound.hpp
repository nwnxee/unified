#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CNWSCombatAttackData.hpp"
#include "CNWSCombatRoundAction.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCombatRound)
#endif

class CNWSCreature;
class CNWSItem;
class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSCombatRound
{
public:
    CNWSCombatAttackData m_pcLastAttack[50];
    CExoArrayList<uint16_t> m_nSpecialAttacks;
    CExoArrayList<uint16_t> m_nSpecialAttackIDs;
    uint16_t m_nAttackID;
    BOOL m_bRoundStarted;
    BOOL m_bSpellCastRound;
    int32_t m_nTimer;
    int32_t m_nRoundLength;
    int32_t m_nOverlapAmount;
    int32_t m_nBleedAmount;
    BOOL m_bRoundPaused;
    OBJECT_ID m_oidRoundPausedBy;
    int32_t m_nPauseTimer;
    BOOL m_bInfinitePause;
    uint8_t m_nCurrentAttack;
    uint8_t m_nAttackGroup;
    BOOL m_bDeflectArrow;
    BOOL m_bWeaponSucks;
    BOOL m_bEpicDodgeUsed;
    int32_t m_nParryIndex;
    int32_t m_nAttacksOfOpportunity;
    int32_t m_nCleaveAttacks;
    int32_t m_nCircleKickAttacks;
    OBJECT_ID m_oidNewAttackTarget;
    int32_t m_nOnHandAttacks;
    int32_t m_nOffHandAttacks;
    int32_t m_nOffHandAttacksTaken;
    int32_t m_nExtraAttacksTaken;
    int32_t m_nAdditionalAttacks;
    int32_t m_nBonusEffectAttacks;
    uint8_t m_nParryActions;
    OBJECT_ID m_oidDodgeTarget;
    CExoLinkedList<CNWSCombatRoundAction> * m_pScheduledActions;
    CNWSCreature * m_pBaseCreature;

    CNWSCombatRound(CNWSCreature * pCreature);
    ~CNWSCombatRound();
    void StartCombatRound(OBJECT_ID oidTarget);
    void StartCombatRoundCast(uint32_t nRoundLength = 6000);
    void EndCombatRound();
    void RecomputeRound();
    void IncrementTimer(int32_t nTimeDelta);
    void DecrementPauseTimer(int32_t nTimeDelta);
    void SetRoundPaused(BOOL bValue, OBJECT_ID oidPausedBy = 0x7f000000);
    void SetPauseTimer(int32_t nValue, BOOL bInfinite = false);
    void DecrementRoundLength(int32_t nValue, BOOL bBleed = false);
    CNWSCombatAttackData * GetAttack(int32_t nAttack);
    void ClearAllAttacks();
    void SignalCombatRoundStarted();
    BOOL CheckActionLength(OBJECT_ID oidPauser, int32_t nActionLength);
    BOOL CheckActionLengthAtTime(OBJECT_ID oidPauser, int32_t nActionLength, int32_t nTimeIndex);
    BOOL GetActionPending();
    BOOL GetAttackActionPending();
    BOOL GetSpellActionPending();
    CNWSCombatRoundAction * GetAction();
    void AddAction(CNWSCombatRoundAction * pAction);
    void RemoveAllActions();
    void AddReaction(int32_t nTimeIndex, int32_t nTimeAnimation);
    void AddSpellAction();
    void RemoveSpellAction();
    void AddParryAttack(OBJECT_ID oidTarget);
    void AddParryIndex();
    void AddCleaveAttack(OBJECT_ID oidTarget, BOOL bGreatCleave = false);
    void AddCircleKickAttack(OBJECT_ID oidTarget);
    void AddAttackOfOpportunity(OBJECT_ID oidTarget);
    void AddWhirlwindAttack(OBJECT_ID oidTarget, BOOL bImproved);
    void AddEquipAction(OBJECT_ID oidItem, uint32_t nInventorySlot);
    void AddUnequipAction(OBJECT_ID oidItem, OBJECT_ID oidTargetRepository, uint8_t x, uint8_t y);
    void AddCombatStepAction(uint32_t nTimeIndex, OBJECT_ID oidTarget);
    void InitializeAttackActions(OBJECT_ID oidTarget);
    void InitializeNumberOfAttacks();
    void InitializeCombatModes();
    int32_t CalculateOffHandAttacks();
    BOOL GetCombatStepRequired(OBJECT_ID oidTarget);
    uint8_t GetTotalAttacks();
    void SetDeflectArrow(BOOL bValue);
    void SetCurrentAttack(uint8_t nCurrentAttack);
    BOOL GetOffHandAttack();
    BOOL GetExtraAttack();
    BOOL HasCreatureWeapons();
    int32_t GetWeaponAttackType();
    CNWSItem * GetCurrentAttackWeapon(int32_t nWeaponAttackType = 0);
    void UpdateAttackTargetForAllActions(OBJECT_ID oidNewTarget);
    void InsertSpecialAttack(uint16_t nSpecialAttack, int32_t nIndex);
    void AddSpecialAttack(uint16_t nSpecialAttack);
    void RemoveSpecialAttack(int32_t nIndex);
    int32_t GetNumSpecialAttacks();
    uint16_t GetSpecialAttack(int32_t nIndex);
    uint16_t GetSpecialAttackID(int32_t nIndex);
    uint16_t GetNewAttackID();
    void ClearAllSpecialAttacks();
    BOOL SaveCombatRound(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadCombatRound(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSCombatRound
    NWN_CLASS_EXTENSION_CNWSCombatRound
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCombatRound)
#endif

