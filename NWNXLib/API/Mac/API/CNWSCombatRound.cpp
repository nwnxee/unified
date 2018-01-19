#include "CNWSCombatRound.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListTemplatedCNWSCombatRoundAction.hpp"
#include "CNWSCombatRoundAction.hpp"
#include "CNWSCreature.hpp"
#include "CNWSItem.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSCombatRound::CNWSCombatRound(CNWSCreature* a0)
{
    CNWSCombatRound__CNWSCombatRoundCtor__0(this, a0);
}

CNWSCombatRound::~CNWSCombatRound()
{
    CNWSCombatRound__CNWSCombatRoundDtor__0(this);
}

void CNWSCombatRound::AddAction(CNWSCombatRoundAction* a0)
{
    return CNWSCombatRound__AddAction(this, a0);
}

void CNWSCombatRound::AddAttackOfOpportunity(uint32_t a0)
{
    return CNWSCombatRound__AddAttackOfOpportunity(this, a0);
}

void CNWSCombatRound::AddCircleKickAttack(uint32_t a0)
{
    return CNWSCombatRound__AddCircleKickAttack(this, a0);
}

void CNWSCombatRound::AddCleaveAttack(uint32_t a0, int32_t a1)
{
    return CNWSCombatRound__AddCleaveAttack(this, a0, a1);
}

void CNWSCombatRound::AddCombatStepAction(uint32_t a0, uint32_t a1)
{
    return CNWSCombatRound__AddCombatStepAction(this, a0, a1);
}

void CNWSCombatRound::AddEquipAction(uint32_t a0, uint32_t a1)
{
    return CNWSCombatRound__AddEquipAction(this, a0, a1);
}

void CNWSCombatRound::AddParryAttack(uint32_t a0)
{
    return CNWSCombatRound__AddParryAttack(this, a0);
}

void CNWSCombatRound::AddParryIndex()
{
    return CNWSCombatRound__AddParryIndex(this);
}

void CNWSCombatRound::AddReaction(int32_t a0, int32_t a1)
{
    return CNWSCombatRound__AddReaction(this, a0, a1);
}

void CNWSCombatRound::AddSpecialAttack(uint16_t a0)
{
    return CNWSCombatRound__AddSpecialAttack(this, a0);
}

void CNWSCombatRound::AddSpellAction()
{
    return CNWSCombatRound__AddSpellAction(this);
}

void CNWSCombatRound::AddUnequipAction(uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    return CNWSCombatRound__AddUnequipAction(this, a0, a1, a2, a3);
}

void CNWSCombatRound::AddWhirlwindAttack(uint32_t a0, int32_t a1)
{
    return CNWSCombatRound__AddWhirlwindAttack(this, a0, a1);
}

int32_t CNWSCombatRound::CalculateOffHandAttacks()
{
    return CNWSCombatRound__CalculateOffHandAttacks(this);
}

int32_t CNWSCombatRound::CheckActionLength(uint32_t a0, int32_t a1)
{
    return CNWSCombatRound__CheckActionLength(this, a0, a1);
}

int32_t CNWSCombatRound::CheckActionLengthAtTime(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCombatRound__CheckActionLengthAtTime(this, a0, a1, a2);
}

void CNWSCombatRound::ClearAllAttacks()
{
    return CNWSCombatRound__ClearAllAttacks(this);
}

void CNWSCombatRound::ClearAllSpecialAttacks()
{
    return CNWSCombatRound__ClearAllSpecialAttacks(this);
}

void CNWSCombatRound::DecrementPauseTimer(int32_t a0)
{
    return CNWSCombatRound__DecrementPauseTimer(this, a0);
}

void CNWSCombatRound::DecrementRoundLength(int32_t a0, int32_t a1)
{
    return CNWSCombatRound__DecrementRoundLength(this, a0, a1);
}

void CNWSCombatRound::EndCombatRound()
{
    return CNWSCombatRound__EndCombatRound(this);
}

CNWSCombatRoundAction* CNWSCombatRound::GetAction()
{
    return CNWSCombatRound__GetAction(this);
}

int32_t CNWSCombatRound::GetActionPending()
{
    return CNWSCombatRound__GetActionPending(this);
}

CNWSCombatAttackData* CNWSCombatRound::GetAttack(int32_t a0)
{
    return CNWSCombatRound__GetAttack(this, a0);
}

int32_t CNWSCombatRound::GetAttackActionPending()
{
    return CNWSCombatRound__GetAttackActionPending(this);
}

int32_t CNWSCombatRound::GetCombatStepRequired(uint32_t a0)
{
    return CNWSCombatRound__GetCombatStepRequired(this, a0);
}

CNWSItem* CNWSCombatRound::GetCurrentAttackWeapon(int32_t a0)
{
    return CNWSCombatRound__GetCurrentAttackWeapon(this, a0);
}

int32_t CNWSCombatRound::GetExtraAttack()
{
    return CNWSCombatRound__GetExtraAttack(this);
}

uint16_t CNWSCombatRound::GetNewAttackID()
{
    return CNWSCombatRound__GetNewAttackID(this);
}

int32_t CNWSCombatRound::GetNumSpecialAttacks()
{
    return CNWSCombatRound__GetNumSpecialAttacks(this);
}

int32_t CNWSCombatRound::GetOffHandAttack()
{
    return CNWSCombatRound__GetOffHandAttack(this);
}

uint16_t CNWSCombatRound::GetSpecialAttack(int32_t a0)
{
    return CNWSCombatRound__GetSpecialAttack(this, a0);
}

uint16_t CNWSCombatRound::GetSpecialAttackID(int32_t a0)
{
    return CNWSCombatRound__GetSpecialAttackID(this, a0);
}

int32_t CNWSCombatRound::GetSpellActionPending()
{
    return CNWSCombatRound__GetSpellActionPending(this);
}

unsigned char CNWSCombatRound::GetTotalAttacks()
{
    return CNWSCombatRound__GetTotalAttacks(this);
}

int32_t CNWSCombatRound::GetWeaponAttackType()
{
    return CNWSCombatRound__GetWeaponAttackType(this);
}

int32_t CNWSCombatRound::HasCreatureWeapons()
{
    return CNWSCombatRound__HasCreatureWeapons(this);
}

void CNWSCombatRound::IncrementTimer(int32_t a0)
{
    return CNWSCombatRound__IncrementTimer(this, a0);
}

void CNWSCombatRound::InitializeAttackActions(uint32_t a0)
{
    return CNWSCombatRound__InitializeAttackActions(this, a0);
}

void CNWSCombatRound::InitializeCombatModes()
{
    return CNWSCombatRound__InitializeCombatModes(this);
}

void CNWSCombatRound::InitializeNumberOfAttacks()
{
    return CNWSCombatRound__InitializeNumberOfAttacks(this);
}

void CNWSCombatRound::InsertSpecialAttack(uint16_t a0, int32_t a1)
{
    return CNWSCombatRound__InsertSpecialAttack(this, a0, a1);
}

int32_t CNWSCombatRound::LoadCombatRound(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatRound__LoadCombatRound(this, a0, a1);
}

void CNWSCombatRound::RecomputeRound()
{
    return CNWSCombatRound__RecomputeRound(this);
}

void CNWSCombatRound::RemoveAllActions()
{
    return CNWSCombatRound__RemoveAllActions(this);
}

void CNWSCombatRound::RemoveSpecialAttack(int32_t a0)
{
    return CNWSCombatRound__RemoveSpecialAttack(this, a0);
}

void CNWSCombatRound::RemoveSpellAction()
{
    return CNWSCombatRound__RemoveSpellAction(this);
}

int32_t CNWSCombatRound::SaveCombatRound(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatRound__SaveCombatRound(this, a0, a1);
}

void CNWSCombatRound::SetCurrentAttack(unsigned char a0)
{
    return CNWSCombatRound__SetCurrentAttack(this, a0);
}

void CNWSCombatRound::SetDeflectArrow(int32_t a0)
{
    return CNWSCombatRound__SetDeflectArrow(this, a0);
}

void CNWSCombatRound::SetPauseTimer(int32_t a0, int32_t a1)
{
    return CNWSCombatRound__SetPauseTimer(this, a0, a1);
}

void CNWSCombatRound::SetRoundPaused(int32_t a0, uint32_t a1)
{
    return CNWSCombatRound__SetRoundPaused(this, a0, a1);
}

void CNWSCombatRound::SignalCombatRoundStarted()
{
    return CNWSCombatRound__SignalCombatRoundStarted(this);
}

void CNWSCombatRound::StartCombatRound(uint32_t a0)
{
    return CNWSCombatRound__StartCombatRound(this, a0);
}

void CNWSCombatRound::StartCombatRoundCast(uint32_t a0)
{
    return CNWSCombatRound__StartCombatRoundCast(this, a0);
}

void CNWSCombatRound::UpdateAttackTargetForAllActions(uint32_t a0)
{
    return CNWSCombatRound__UpdateAttackTargetForAllActions(this, a0);
}

void CNWSCombatRound__CNWSCombatRoundCtor__0(CNWSCombatRound* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__CNWSCombatRoundCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSCombatRound__CNWSCombatRoundDtor__0(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__CNWSCombatRoundDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSCombatRound__AddAction(CNWSCombatRound* thisPtr, CNWSCombatRoundAction* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, CNWSCombatRoundAction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__AddAttackOfOpportunity(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddAttackOfOpportunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__AddCircleKickAttack(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddCircleKickAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__AddCleaveAttack(CNWSCombatRound* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddCleaveAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__AddCombatStepAction(CNWSCombatRound* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddCombatStepAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__AddEquipAction(CNWSCombatRound* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddEquipAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__AddParryAttack(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddParryAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__AddParryIndex(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddParryIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__AddReaction(CNWSCombatRound* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddReaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__AddSpecialAttack(CNWSCombatRound* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__AddSpellAction(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddSpellAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__AddUnequipAction(CNWSCombatRound* thisPtr, uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddUnequipAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCombatRound__AddWhirlwindAttack(CNWSCombatRound* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__AddWhirlwindAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatRound__CalculateOffHandAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__CalculateOffHandAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__CheckActionLength(CNWSCombatRound* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__CheckActionLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatRound__CheckActionLengthAtTime(CNWSCombatRound* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__CheckActionLengthAtTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCombatRound__ClearAllAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__ClearAllAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__ClearAllSpecialAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__ClearAllSpecialAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__DecrementPauseTimer(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__DecrementPauseTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__DecrementRoundLength(CNWSCombatRound* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__DecrementRoundLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__EndCombatRound(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__EndCombatRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSCombatRoundAction* CNWSCombatRound__GetAction(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = CNWSCombatRoundAction*(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__GetActionPending(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetActionPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSCombatAttackData* CNWSCombatRound__GetAttack(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSCombatAttackData*(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCombatRound__GetAttackActionPending(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetAttackActionPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__GetCombatStepRequired(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetCombatStepRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSItem* CNWSCombatRound__GetCurrentAttackWeapon(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetCurrentAttackWeapon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCombatRound__GetExtraAttack(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetExtraAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSCombatRound__GetNewAttackID(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetNewAttackID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__GetNumSpecialAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetNumSpecialAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__GetOffHandAttack(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetOffHandAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSCombatRound__GetSpecialAttack(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSCombatRound__GetSpecialAttackID(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetSpecialAttackID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCombatRound__GetSpellActionPending(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetSpellActionPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCombatRound__GetTotalAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetTotalAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__GetWeaponAttackType(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__GetWeaponAttackType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__HasCreatureWeapons(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__HasCreatureWeapons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__IncrementTimer(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__IncrementTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__InitializeAttackActions(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__InitializeAttackActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__InitializeCombatModes(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__InitializeCombatModes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__InitializeNumberOfAttacks(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__InitializeNumberOfAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__InsertSpecialAttack(CNWSCombatRound* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__InsertSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatRound__LoadCombatRound(CNWSCombatRound* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__LoadCombatRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__RecomputeRound(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__RecomputeRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__RemoveAllActions(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__RemoveAllActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__RemoveSpecialAttack(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__RemoveSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__RemoveSpellAction(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__RemoveSpellAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCombatRound__SaveCombatRound(CNWSCombatRound* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRound*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SaveCombatRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__SetCurrentAttack(CNWSCombatRound* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SetCurrentAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__SetDeflectArrow(CNWSCombatRound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SetDeflectArrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__SetPauseTimer(CNWSCombatRound* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SetPauseTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__SetRoundPaused(CNWSCombatRound* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SetRoundPaused);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatRound__SignalCombatRoundStarted(CNWSCombatRound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__SignalCombatRoundStarted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatRound__StartCombatRound(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__StartCombatRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__StartCombatRoundCast(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__StartCombatRoundCast);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatRound__UpdateAttackTargetForAllActions(CNWSCombatRound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRound__UpdateAttackTargetForAllActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
