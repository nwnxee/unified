#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedshortunsignedint.hpp"
#include "CNWSCombatAttackData.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListTemplatedCNWSCombatRoundAction;
struct CNWSCombatRoundAction;
struct CNWSCreature;
struct CNWSItem;
struct CResGFF;
struct CResStruct;

struct CNWSCombatRound
{
    CNWSCombatAttackData m_pcLastAttack[50];
    CExoArrayListTemplatedshortunsignedint m_nSpecialAttacks;
    CExoArrayListTemplatedshortunsignedint m_nSpecialAttackIDs;
    uint16_t m_nAttackID;
    int32_t m_bRoundStarted;
    int32_t m_bSpellCastRound;
    int32_t m_nTimer;
    int32_t m_nRoundLength;
    int32_t m_nOverlapAmount;
    int32_t m_nBleedAmount;
    int32_t m_bRoundPaused;
    uint32_t m_oidRoundPausedBy;
    int32_t m_nPauseTimer;
    int32_t m_bInfinitePause;
    uint8_t m_nCurrentAttack;
    uint8_t m_nAttackGroup;
    int32_t m_bDeflectArrow;
    int32_t m_bWeaponSucks;
    int32_t m_bEpicDodgeUsed;
    int32_t m_nParryIndex;
    int32_t m_nAttacksOfOpportunity;
    int32_t m_nCleaveAttacks;
    int32_t m_nCircleKickAttacks;
    uint32_t m_oidNewAttackTarget;
    int32_t m_nOnHandAttacks;
    int32_t m_nOffHandAttacks;
    int32_t m_nOffHandAttacksTaken;
    int32_t m_nExtraAttacksTaken;
    int32_t m_nAdditionalAttacks;
    int32_t m_nBonusEffectAttacks;
    uint8_t m_nParryActions;
    uint32_t m_oidDodgeTarget;
    CExoLinkedListTemplatedCNWSCombatRoundAction* m_pScheduledActions;
    CNWSCreature* m_pBaseCreature;

    // The below are auto generated stubs.
    CNWSCombatRound() = default;
    CNWSCombatRound(const CNWSCombatRound&) = default;
    CNWSCombatRound& operator=(const CNWSCombatRound&) = default;

    CNWSCombatRound(CNWSCreature*);
    ~CNWSCombatRound();
    void AddAction(CNWSCombatRoundAction*);
    void AddAttackOfOpportunity(uint32_t);
    void AddCircleKickAttack(uint32_t);
    void AddCleaveAttack(uint32_t, int32_t);
    void AddCombatStepAction(uint32_t, uint32_t);
    void AddEquipAction(uint32_t, uint32_t);
    void AddParryAttack(uint32_t);
    void AddParryIndex();
    void AddReaction(int32_t, int32_t);
    void AddSpecialAttack(uint16_t);
    void AddSpellAction();
    void AddUnequipAction(uint32_t, uint32_t, unsigned char, unsigned char);
    void AddWhirlwindAttack(uint32_t, int32_t);
    int32_t CalculateOffHandAttacks();
    int32_t CheckActionLength(uint32_t, int32_t);
    int32_t CheckActionLengthAtTime(uint32_t, int32_t, int32_t);
    void ClearAllAttacks();
    void ClearAllSpecialAttacks();
    void DecrementPauseTimer(int32_t);
    void DecrementRoundLength(int32_t, int32_t);
    void EndCombatRound();
    CNWSCombatRoundAction* GetAction();
    int32_t GetActionPending();
    CNWSCombatAttackData* GetAttack(int32_t);
    int32_t GetAttackActionPending();
    int32_t GetCombatStepRequired(uint32_t);
    CNWSItem* GetCurrentAttackWeapon(int32_t);
    int32_t GetExtraAttack();
    uint16_t GetNewAttackID();
    int32_t GetNumSpecialAttacks();
    int32_t GetOffHandAttack();
    uint16_t GetSpecialAttack(int32_t);
    uint16_t GetSpecialAttackID(int32_t);
    int32_t GetSpellActionPending();
    unsigned char GetTotalAttacks();
    int32_t GetWeaponAttackType();
    int32_t HasCreatureWeapons();
    void IncrementTimer(int32_t);
    void InitializeAttackActions(uint32_t);
    void InitializeCombatModes();
    void InitializeNumberOfAttacks();
    void InsertSpecialAttack(uint16_t, int32_t);
    int32_t LoadCombatRound(CResGFF*, CResStruct*);
    void RecomputeRound();
    void RemoveAllActions();
    void RemoveSpecialAttack(int32_t);
    void RemoveSpellAction();
    int32_t SaveCombatRound(CResGFF*, CResStruct*);
    void SetCurrentAttack(unsigned char);
    void SetDeflectArrow(int32_t);
    void SetPauseTimer(int32_t, int32_t);
    void SetRoundPaused(int32_t, uint32_t);
    void SignalCombatRoundStarted();
    void StartCombatRound(uint32_t);
    void StartCombatRoundCast(uint32_t);
    void UpdateAttackTargetForAllActions(uint32_t);
};

void CNWSCombatRound__CNWSCombatRoundCtor__0(CNWSCombatRound* thisPtr, CNWSCreature*);
void CNWSCombatRound__CNWSCombatRoundDtor__0(CNWSCombatRound* thisPtr);
void CNWSCombatRound__AddAction(CNWSCombatRound* thisPtr, CNWSCombatRoundAction*);
void CNWSCombatRound__AddAttackOfOpportunity(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__AddCircleKickAttack(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__AddCleaveAttack(CNWSCombatRound* thisPtr, uint32_t, int32_t);
void CNWSCombatRound__AddCombatStepAction(CNWSCombatRound* thisPtr, uint32_t, uint32_t);
void CNWSCombatRound__AddEquipAction(CNWSCombatRound* thisPtr, uint32_t, uint32_t);
void CNWSCombatRound__AddParryAttack(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__AddParryIndex(CNWSCombatRound* thisPtr);
void CNWSCombatRound__AddReaction(CNWSCombatRound* thisPtr, int32_t, int32_t);
void CNWSCombatRound__AddSpecialAttack(CNWSCombatRound* thisPtr, uint16_t);
void CNWSCombatRound__AddSpellAction(CNWSCombatRound* thisPtr);
void CNWSCombatRound__AddUnequipAction(CNWSCombatRound* thisPtr, uint32_t, uint32_t, unsigned char, unsigned char);
void CNWSCombatRound__AddWhirlwindAttack(CNWSCombatRound* thisPtr, uint32_t, int32_t);
int32_t CNWSCombatRound__CalculateOffHandAttacks(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__CheckActionLength(CNWSCombatRound* thisPtr, uint32_t, int32_t);
int32_t CNWSCombatRound__CheckActionLengthAtTime(CNWSCombatRound* thisPtr, uint32_t, int32_t, int32_t);
void CNWSCombatRound__ClearAllAttacks(CNWSCombatRound* thisPtr);
void CNWSCombatRound__ClearAllSpecialAttacks(CNWSCombatRound* thisPtr);
void CNWSCombatRound__DecrementPauseTimer(CNWSCombatRound* thisPtr, int32_t);
void CNWSCombatRound__DecrementRoundLength(CNWSCombatRound* thisPtr, int32_t, int32_t);
void CNWSCombatRound__EndCombatRound(CNWSCombatRound* thisPtr);
CNWSCombatRoundAction* CNWSCombatRound__GetAction(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__GetActionPending(CNWSCombatRound* thisPtr);
CNWSCombatAttackData* CNWSCombatRound__GetAttack(CNWSCombatRound* thisPtr, int32_t);
int32_t CNWSCombatRound__GetAttackActionPending(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__GetCombatStepRequired(CNWSCombatRound* thisPtr, uint32_t);
CNWSItem* CNWSCombatRound__GetCurrentAttackWeapon(CNWSCombatRound* thisPtr, int32_t);
int32_t CNWSCombatRound__GetExtraAttack(CNWSCombatRound* thisPtr);
uint16_t CNWSCombatRound__GetNewAttackID(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__GetNumSpecialAttacks(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__GetOffHandAttack(CNWSCombatRound* thisPtr);
uint16_t CNWSCombatRound__GetSpecialAttack(CNWSCombatRound* thisPtr, int32_t);
uint16_t CNWSCombatRound__GetSpecialAttackID(CNWSCombatRound* thisPtr, int32_t);
int32_t CNWSCombatRound__GetSpellActionPending(CNWSCombatRound* thisPtr);
unsigned char CNWSCombatRound__GetTotalAttacks(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__GetWeaponAttackType(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__HasCreatureWeapons(CNWSCombatRound* thisPtr);
void CNWSCombatRound__IncrementTimer(CNWSCombatRound* thisPtr, int32_t);
void CNWSCombatRound__InitializeAttackActions(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__InitializeCombatModes(CNWSCombatRound* thisPtr);
void CNWSCombatRound__InitializeNumberOfAttacks(CNWSCombatRound* thisPtr);
void CNWSCombatRound__InsertSpecialAttack(CNWSCombatRound* thisPtr, uint16_t, int32_t);
int32_t CNWSCombatRound__LoadCombatRound(CNWSCombatRound* thisPtr, CResGFF*, CResStruct*);
void CNWSCombatRound__RecomputeRound(CNWSCombatRound* thisPtr);
void CNWSCombatRound__RemoveAllActions(CNWSCombatRound* thisPtr);
void CNWSCombatRound__RemoveSpecialAttack(CNWSCombatRound* thisPtr, int32_t);
void CNWSCombatRound__RemoveSpellAction(CNWSCombatRound* thisPtr);
int32_t CNWSCombatRound__SaveCombatRound(CNWSCombatRound* thisPtr, CResGFF*, CResStruct*);
void CNWSCombatRound__SetCurrentAttack(CNWSCombatRound* thisPtr, unsigned char);
void CNWSCombatRound__SetDeflectArrow(CNWSCombatRound* thisPtr, int32_t);
void CNWSCombatRound__SetPauseTimer(CNWSCombatRound* thisPtr, int32_t, int32_t);
void CNWSCombatRound__SetRoundPaused(CNWSCombatRound* thisPtr, int32_t, uint32_t);
void CNWSCombatRound__SignalCombatRoundStarted(CNWSCombatRound* thisPtr);
void CNWSCombatRound__StartCombatRound(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__StartCombatRoundCast(CNWSCombatRound* thisPtr, uint32_t);
void CNWSCombatRound__UpdateAttackTargetForAllActions(CNWSCombatRound* thisPtr, uint32_t);

}

}
