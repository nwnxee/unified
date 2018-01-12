#include "CNWSObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListNode.hpp"
#include "CGameEffect.hpp"
#include "CNWCCMessageData.hpp"
#include "CNWSAnimBase.hpp"
#include "CNWSArea.hpp"
#include "CNWSCreature.hpp"
#include "CNWSDialog.hpp"
#include "CNWSExpression.hpp"
#include "CNWSObjectActionNode.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSpell.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSObject::CNWSObject(unsigned char a0, uint32_t a1, int32_t a2, int32_t a3)
{
    CNWSObject__CNWSObjectCtor(this, a0, a1, a2, a3);
}

CNWSObject::~CNWSObject()
{
    CNWSObject__CNWSObjectDtor__0(this);
}

void CNWSObject::AddAction(uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    return CNWSObject__AddAction(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

void CNWSObject::AddActionAfterFront(uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    return CNWSObject__AddActionAfterFront(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

void CNWSObject::AddActionNodeParameter(CNWSObjectActionNode* a0, uint32_t a1, uint32_t a2, void* a3)
{
    return CNWSObject__AddActionNodeParameter(this, a0, a1, a2, a3);
}

void CNWSObject::AddActionToFront(uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    return CNWSObject__AddActionToFront(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

int32_t CNWSObject::AddCloseDoorAction(uint32_t a0, int32_t a1)
{
    return CNWSObject__AddCloseDoorAction(this, a0, a1);
}

int32_t CNWSObject::AddDoCommandAction(void* a0)
{
    return CNWSObject__AddDoCommandAction(this, a0);
}

int32_t CNWSObject::AddGiveItemActions(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSObject__AddGiveItemActions(this, a0, a1, a2);
}

int32_t CNWSObject::AddLockObjectAction(uint32_t a0)
{
    return CNWSObject__AddLockObjectAction(this, a0);
}

void CNWSObject::AddLoopingVisualEffect(uint16_t a0, uint32_t a1, unsigned char a2)
{
    return CNWSObject__AddLoopingVisualEffect(this, a0, a1, a2);
}

void CNWSObject::AddMatchedExpressionString(const CExoString& a0)
{
    return CNWSObject__AddMatchedExpressionString(this, a0);
}

int32_t CNWSObject::AddOpenDoorAction(uint32_t a0, int32_t a1)
{
    return CNWSObject__AddOpenDoorAction(this, a0, a1);
}

int32_t CNWSObject::AddTakeItemActions(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSObject__AddTakeItemActions(this, a0, a1, a2);
}

int32_t CNWSObject::AddUnlockObjectAction(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSObject__AddUnlockObjectAction(this, a0, a1, a2);
}

int32_t CNWSObject::AddUseObjectAction(uint32_t a0)
{
    return CNWSObject__AddUseObjectAction(this, a0);
}

uint32_t CNWSObject::AIActionCloseDoor(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionCloseDoor(this, a0);
}

uint32_t CNWSObject::AIActionDialogObject(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionDialogObject(this, a0);
}

uint32_t CNWSObject::AIActionDoCommand(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionDoCommand(this, a0);
}

uint32_t CNWSObject::AIActionGiveItem(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionGiveItem(this, a0);
}

uint32_t CNWSObject::AIActionLockObject(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionLockObject(this, a0);
}

uint32_t CNWSObject::AIActionOpenDoor(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionOpenDoor(this, a0);
}

uint32_t CNWSObject::AIActionPauseDialog(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionPauseDialog(this, a0);
}

uint32_t CNWSObject::AIActionPlayAnimation(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionPlayAnimation(this, a0);
}

uint32_t CNWSObject::AIActionPlaySound(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionPlaySound(this, a0);
}

uint32_t CNWSObject::AIActionResumeDialog(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionResumeDialog(this, a0);
}

uint32_t CNWSObject::AIActionSetCommandable(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionSetCommandable(this, a0);
}

uint32_t CNWSObject::AIActionSpeak(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionSpeak(this, a0);
}

uint32_t CNWSObject::AIActionSpeakStrRef(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionSpeakStrRef(this, a0);
}

uint32_t CNWSObject::AIActionTakeItem(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionTakeItem(this, a0);
}

uint32_t CNWSObject::AIActionUnlockObject(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionUnlockObject(this, a0);
}

uint32_t CNWSObject::AIActionUseObject(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionUseObject(this, a0);
}

uint32_t CNWSObject::AIActionWait(CNWSObjectActionNode* a0)
{
    return CNWSObject__AIActionWait(this, a0);
}

int32_t CNWSObject::AnimationStationary(uint16_t a0)
{
    return CNWSObject__AnimationStationary(this, a0);
}

void CNWSObject::ApplyEffect(CGameEffect* a0, int32_t a1, int32_t a2)
{
    return CNWSObject__ApplyEffect(this, a0, a1, a2);
}

CNWSObject* CNWSObject::AsNWSObject()
{
    return CNWSObject__AsNWSObject(this);
}

void CNWSObject::BroadcastCounterSpellData(CNWSpell* a0, CNWCCMessageData* a1)
{
    return CNWSObject__BroadcastCounterSpellData(this, a0, a1);
}

void CNWSObject::BroadcastDialog(CExoString a0, float a1)
{
    return CNWSObject__BroadcastDialog(this, a0, a1);
}

void CNWSObject::BroadcastFloatyData(CNWCCMessageData* a0)
{
    return CNWSObject__BroadcastFloatyData(this, a0);
}

void CNWSObject::BroadcastFloatyDataSTRREF(uint32_t a0)
{
    return CNWSObject__BroadcastFloatyDataSTRREF(this, a0);
}

void CNWSObject::BroadcastSafeProjectile(uint32_t a0, uint32_t a1, Vector a2, Vector a3, uint32_t a4, unsigned char a5, uint32_t a6, unsigned char a7, unsigned char a8)
{
    return CNWSObject__BroadcastSafeProjectile(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void CNWSObject::BroadcastSpellData(CNWSpell* a0, CNWCCMessageData* a1)
{
    return CNWSObject__BroadcastSpellData(this, a0, a1);
}

void CNWSObject::CalculateLastSpellProjectileTime(unsigned char a0)
{
    return CNWSObject__CalculateLastSpellProjectileTime(this, a0);
}

Vector CNWSObject::CalculateSpellRangedMissTarget(uint32_t a0, uint32_t a1)
{
    return CNWSObject__CalculateSpellRangedMissTarget(this, a0, a1);
}

int32_t CNWSObject::ClearAction(CNWSObjectActionNode* a0, int32_t a1)
{
    return CNWSObject__ClearAction(this, a0, a1);
}

void CNWSObject::ClearAllActions()
{
    return CNWSObject__ClearAllActions(this);
}

void CNWSObject::ClearAllHostileActions(uint32_t a0)
{
    return CNWSObject__ClearAllHostileActions(this, a0);
}

void CNWSObject::ClearMatchedExpressionStrings()
{
    return CNWSObject__ClearMatchedExpressionStrings(this);
}

void CNWSObject::ClearSpellEffectsOnOthers()
{
    return CNWSObject__ClearSpellEffectsOnOthers(this);
}

void CNWSObject::CopyScriptVars(CNWSScriptVarTable* a0)
{
    return CNWSObject__CopyScriptVars(this, a0);
}

void CNWSObject::DeleteCurrentAIAction()
{
    return CNWSObject__DeleteCurrentAIAction(this);
}

void CNWSObject::DoDamage(int32_t a0)
{
    return CNWSObject__DoDamage(this, a0);
}

int32_t CNWSObject::DoDamageImmunity(CNWSCreature* a0, int32_t a1, uint16_t a2, int32_t a3, int32_t a4)
{
    return CNWSObject__DoDamageImmunity(this, a0, a1, a2, a3, a4);
}

int32_t CNWSObject::DoDamageReduction(CNWSCreature* a0, int32_t a1, unsigned char a2, int32_t a3, int32_t a4)
{
    return CNWSObject__DoDamageReduction(this, a0, a1, a2, a3, a4);
}

int32_t CNWSObject::DoDamageResistance(CNWSCreature* a0, int32_t a1, uint16_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSObject__DoDamageResistance(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSObject::DoSpellImmunity(CNWSObject* a0)
{
    return CNWSObject__DoSpellImmunity(this, a0);
}

int32_t CNWSObject::DoSpellLevelAbsorption(CNWSObject* a0)
{
    return CNWSObject__DoSpellLevelAbsorption(this, a0);
}

int32_t CNWSObject::GetAcceptableAction(uint32_t a0)
{
    return CNWSObject__GetAcceptableAction(this, a0);
}

uint16_t CNWSObject::GetActionByGroupId(uint16_t a0, CNWSObjectActionNode** a1)
{
    return CNWSObject__GetActionByGroupId(this, a0, a1);
}

unsigned char CNWSObject::GetAIStateReaction(uint32_t a0)
{
    return CNWSObject__GetAIStateReaction(this, a0);
}

uint16_t CNWSObject::GetAQActionIDByID(uint16_t a0, int32_t a1)
{
    return CNWSObject__GetAQActionIDByID(this, a0, a1);
}

CNWSArea* CNWSObject::GetArea()
{
    return CNWSObject__GetArea(this);
}

int16_t CNWSObject::GetCurrentHitPoints(int32_t a0)
{
    return CNWSObject__GetCurrentHitPoints(this, a0);
}

char CNWSObject::GetDamageImmunity(unsigned char a0)
{
    return CNWSObject__GetDamageImmunity(this, a0);
}

char CNWSObject::GetDamageImmunityByFlags(uint16_t a0)
{
    return CNWSObject__GetDamageImmunityByFlags(this, a0);
}

unsigned char CNWSObject::GetDamageLevel()
{
    return CNWSObject__GetDamageLevel(this);
}

int32_t CNWSObject::GetDead()
{
    return CNWSObject__GetDead(this);
}

int32_t CNWSObject::GetDialogInterruptable()
{
    return CNWSObject__GetDialogInterruptable(this);
}

CResRef CNWSObject::GetDialogResref()
{
    return CNWSObject__GetDialogResref(this);
}

uint32_t CNWSObject::GetEffectSpellId()
{
    return CNWSObject__GetEffectSpellId(this);
}

CExoLocString& CNWSObject::GetFirstName()
{
    return CNWSObject__GetFirstName(this);
}

unsigned char CNWSObject::GetGender()
{
    return CNWSObject__GetGender(this);
}

int32_t CNWSObject::GetHasFeatEffectApplied(uint16_t a0)
{
    return CNWSObject__GetHasFeatEffectApplied(this, a0);
}

uint16_t CNWSObject::GetIDByAQActionID(uint16_t a0)
{
    return CNWSObject__GetIDByAQActionID(this, a0);
}

int32_t CNWSObject::GetIsPCDying()
{
    return CNWSObject__GetIsPCDying(this);
}

int32_t CNWSObject::GetLastDamageAmountByFlags(int32_t a0)
{
    return CNWSObject__GetLastDamageAmountByFlags(this, a0);
}

CExoLocString& CNWSObject::GetLastName()
{
    return CNWSObject__GetLastName(this);
}

CNWSExpression* CNWSObject::GetListenExpressionObj(int32_t a0)
{
    return CNWSObject__GetListenExpressionObj(this, a0);
}

uint32_t CNWSObject::GetLockOrientationToObject()
{
    return CNWSObject__GetLockOrientationToObject(this);
}

int16_t CNWSObject::GetMaxHitPoints(int32_t a0)
{
    return CNWSObject__GetMaxHitPoints(this, a0);
}

int32_t CNWSObject::GetMaximumDamageResistanceVsDamageFlag(uint16_t a0, int32_t* a1)
{
    return CNWSObject__GetMaximumDamageResistanceVsDamageFlag(this, a0, a1);
}

uint32_t CNWSObject::GetNearestObjectByName(const CExoString& a0, float a1)
{
    return CNWSObject__GetNearestObjectByName(this, a0, a1);
}

uint16_t CNWSObject::GetNewGroupID()
{
    return CNWSObject__GetNewGroupID(this);
}

CNWSObjectActionNode* CNWSObject::GetNodeById(uint16_t a0, uint16_t a1)
{
    return CNWSObject__GetNodeById(this, a0, a1);
}

int32_t CNWSObject::GetNumActionGroups()
{
    return CNWSObject__GetNumActionGroups(this);
}

CResRef CNWSObject::GetPortrait()
{
    return CNWSObject__GetPortrait(this);
}

uint16_t CNWSObject::GetPortraitId()
{
    return CNWSObject__GetPortraitId(this);
}

CExoLinkedListNode* CNWSObject::GetPositionByGroupIndex(int32_t a0)
{
    return CNWSObject__GetPositionByGroupIndex(this, a0);
}

int32_t CNWSObject::GetReputation(uint32_t a0, int32_t& a1, int32_t a2)
{
    return CNWSObject__GetReputation(this, a0, a1, a2);
}

CScriptLocation CNWSObject::GetScriptLocation()
{
    return CNWSObject__GetScriptLocation(this);
}

int32_t CNWSObject::HasSpellEffectApplied(uint32_t a0)
{
    return CNWSObject__HasSpellEffectApplied(this, a0);
}

int32_t CNWSObject::IsDialogDelay()
{
    return CNWSObject__IsDialogDelay(this);
}

void CNWSObject::LoadActionQueue(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__LoadActionQueue(this, a0, a1);
}

void CNWSObject::LoadEffectList(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__LoadEffectList(this, a0, a1);
}

void CNWSObject::LoadListenData(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__LoadListenData(this, a0, a1);
}

void CNWSObject::LoadObjectState(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__LoadObjectState(this, a0, a1);
}

void CNWSObject::LoadVarTable(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__LoadVarTable(this, a0, a1);
}

void CNWSObject::PlaySoundSet(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSObject__PlaySoundSet(this, a0, a1);
}

void CNWSObject::RemoveEffect(CGameEffect* a0)
{
    return CNWSObject__RemoveEffect(this, a0);
}

void CNWSObject::RemoveEffectByCreator(uint32_t a0)
{
    return CNWSObject__RemoveEffectByCreator(this, a0);
}

int32_t CNWSObject::RemoveEffectById(uint64_t a0)
{
    return CNWSObject__RemoveEffectById(this, a0);
}

void CNWSObject::RemoveEffectBySpellId(uint32_t a0)
{
    return CNWSObject__RemoveEffectBySpellId(this, a0);
}

void CNWSObject::RemoveEffectTarget(uint32_t a0)
{
    return CNWSObject__RemoveEffectTarget(this, a0);
}

void CNWSObject::RemoveGroup(uint16_t a0)
{
    return CNWSObject__RemoveGroup(this, a0);
}

void CNWSObject::RemoveLoopingVisualEffect(uint16_t a0)
{
    return CNWSObject__RemoveLoopingVisualEffect(this, a0);
}

int32_t CNWSObject::RemoveObjectFromDialog(uint32_t a0)
{
    return CNWSObject__RemoveObjectFromDialog(this, a0);
}

void CNWSObject::RemoveSomeEffectsOfDurationType(uint16_t a0)
{
    return CNWSObject__RemoveSomeEffectsOfDurationType(this, a0);
}

int32_t CNWSObject::ReplyDialog(uint32_t a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    return CNWSObject__ReplyDialog(this, a0, a1, a2, a3);
}

void CNWSObject::ReportOverflow(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSObject__ReportOverflow(this, a0, a1, a2, a3);
}

void CNWSObject::RunActions(uint32_t a0, uint32_t a1, uint64_t a2)
{
    return CNWSObject__RunActions(this, a0, a1, a2);
}

int32_t CNWSObject::RunDialogOneLiner(const CExoString& a0, uint32_t a1)
{
    return CNWSObject__RunDialogOneLiner(this, a0, a1);
}

void CNWSObject::SaveActionQueue(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__SaveActionQueue(this, a0, a1);
}

void CNWSObject::SaveEffectList(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__SaveEffectList(this, a0, a1);
}

void CNWSObject::SaveListenData(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__SaveListenData(this, a0, a1);
}

void CNWSObject::SaveObjectState(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__SaveObjectState(this, a0, a1);
}

void CNWSObject::SaveVarTable(CResGFF* a0, CResStruct* a1)
{
    return CNWSObject__SaveVarTable(this, a0, a1);
}

int32_t CNWSObject::SendDialogEntry(uint32_t a0, int32_t a1)
{
    return CNWSObject__SendDialogEntry(this, a0, a1);
}

int32_t CNWSObject::SendDialogReplies()
{
    return CNWSObject__SendDialogReplies(this);
}

void CNWSObject::SetAnimation(int32_t a0)
{
    return CNWSObject__SetAnimation(this, a0);
}

void CNWSObject::SetArea(CNWSArea* a0)
{
    return CNWSObject__SetArea(this, a0);
}

void CNWSObject::SetDamageImmunity(uint16_t a0, int32_t a1)
{
    return CNWSObject__SetDamageImmunity(this, a0, a1);
}

void CNWSObject::SetDialogDelay(float a0)
{
    return CNWSObject__SetDialogDelay(this, a0);
}

void CNWSObject::SetDialogOwner(uint32_t a0)
{
    return CNWSObject__SetDialogOwner(this, a0);
}

void CNWSObject::SetEffectSpellId(uint32_t a0)
{
    return CNWSObject__SetEffectSpellId(this, a0);
}

void CNWSObject::SetGroupInterruptable(uint16_t a0, int32_t a1)
{
    return CNWSObject__SetGroupInterruptable(this, a0, a1);
}

void CNWSObject::SetLastHostileActor(uint32_t a0, int32_t a1)
{
    return CNWSObject__SetLastHostileActor(this, a0, a1);
}

int32_t CNWSObject::SetListenExpression(CExoString a0, int32_t a1)
{
    return CNWSObject__SetListenExpression(this, a0, a1);
}

void CNWSObject::SetLockOrientationToObject(uint32_t a0)
{
    return CNWSObject__SetLockOrientationToObject(this, a0);
}

void CNWSObject::SetOrientation(Vector a0)
{
    return CNWSObject__SetOrientation(this, a0);
}

void CNWSObject::SetPortrait(CResRef a0)
{
    return CNWSObject__SetPortrait(this, a0);
}

void CNWSObject::SetPortraitId(uint16_t a0)
{
    return CNWSObject__SetPortraitId(this, a0);
}

void CNWSObject::SetPosition(Vector a0, int32_t a1)
{
    return CNWSObject__SetPosition(this, a0, a1);
}

void CNWSObject::SpawnBodyBag()
{
    return CNWSObject__SpawnBodyBag(this);
}

void CNWSObject::SpellCastAndImpact(uint32_t a0, Vector a1, uint32_t a2, unsigned char a3, uint32_t a4, int32_t a5, int32_t a6, unsigned char a7, int32_t a8)
{
    return CNWSObject__SpellCastAndImpact(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSObject::StartDialog(uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3)
{
    return CNWSObject__StartDialog(this, a0, a1, a2, a3);
}

int32_t CNWSObject::StopDialog()
{
    return CNWSObject__StopDialog(this);
}

int32_t CNWSObject::TerminateAISliceAfterAction(uint32_t a0)
{
    return CNWSObject__TerminateAISliceAfterAction(this, a0);
}

void CNWSObject::TestActionList()
{
    return CNWSObject__TestActionList(this);
}

int32_t CNWSObject::TestListenExpression(CExoString a0)
{
    return CNWSObject__TestListenExpression(this, a0);
}

void CNWSObject::UpdateAttributesOnEffect(CGameEffect* a0, int32_t a1)
{
    return CNWSObject__UpdateAttributesOnEffect(this, a0, a1);
}

int32_t CNWSObject::UpdateDialog()
{
    return CNWSObject__UpdateDialog(this);
}

void CNWSObject::UpdateEffectList(uint32_t a0, uint32_t a1)
{
    return CNWSObject__UpdateEffectList(this, a0, a1);
}

void CNWSObject::UpdateEffectPtrs()
{
    return CNWSObject__UpdateEffectPtrs(this);
}

void CNWSObject__CNWSObjectCtor(CNWSObject* thisPtr, unsigned char a0, uint32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, unsigned char, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__CNWSObjectCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2, a3);
}

void CNWSObject__CNWSObjectDtor__0(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__CNWSObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSObject__AddAction(CNWSObject* thisPtr, uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint16_t, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

void CNWSObject__AddActionAfterFront(CNWSObject* thisPtr, uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint16_t, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddActionAfterFront);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

void CNWSObject__AddActionNodeParameter(CNWSObject* thisPtr, CNWSObjectActionNode* a0, uint32_t a1, uint32_t a2, void* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddActionNodeParameter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSObject__AddActionToFront(CNWSObject* thisPtr, uint32_t a0, uint16_t a1, uint32_t a2, void* a3, uint32_t a4, void* a5, uint32_t a6, void* a7, uint32_t a8, void* a9, uint32_t a10, void* a11, uint32_t a12, void* a13, uint32_t a14, void* a15, uint32_t a16, void* a17, uint32_t a18, void* a19, uint32_t a20, void* a21, uint32_t a22, void* a23, uint32_t a24, void* a25)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint16_t, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddActionToFront);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25);
}

int32_t CNWSObject__AddCloseDoorAction(CNWSObject* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddCloseDoorAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__AddDoCommandAction(CNWSObject* thisPtr, void* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddDoCommandAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__AddGiveItemActions(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddGiveItemActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSObject__AddLockObjectAction(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddLockObjectAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__AddLoopingVisualEffect(CNWSObject* thisPtr, uint16_t a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddLoopingVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSObject__AddMatchedExpressionString(CNWSObject* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddMatchedExpressionString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__AddOpenDoorAction(CNWSObject* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddOpenDoorAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__AddTakeItemActions(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddTakeItemActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSObject__AddUnlockObjectAction(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddUnlockObjectAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSObject__AddUseObjectAction(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AddUseObjectAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionCloseDoor(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionCloseDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionDialogObject(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionDialogObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionDoCommand(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionDoCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionGiveItem(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionGiveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionLockObject(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionLockObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionOpenDoor(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionOpenDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionPauseDialog(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionPauseDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionPlayAnimation(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionPlayAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionPlaySound(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionPlaySound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionResumeDialog(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionResumeDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionSetCommandable(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionSetCommandable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionSpeak(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionSpeak);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionSpeakStrRef(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionSpeakStrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionTakeItem(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionTakeItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionUnlockObject(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionUnlockObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionUseObject(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionUseObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__AIActionWait(CNWSObject* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AIActionWait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__AnimationStationary(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AnimationStationary);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__ApplyEffect(CNWSObject* thisPtr, CGameEffect* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CGameEffect*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ApplyEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWSObject* CNWSObject__AsNWSObject(CNWSObject* thisPtr)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__AsNWSObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__BroadcastCounterSpellData(CNWSObject* thisPtr, CNWSpell* a0, CNWCCMessageData* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSpell*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastCounterSpellData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__BroadcastDialog(CNWSObject* thisPtr, CExoString a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CExoString, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__BroadcastFloatyData(CNWSObject* thisPtr, CNWCCMessageData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastFloatyData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__BroadcastFloatyDataSTRREF(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastFloatyDataSTRREF);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__BroadcastSafeProjectile(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, Vector a2, Vector a3, uint32_t a4, unsigned char a5, uint32_t a6, unsigned char a7, unsigned char a8)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, Vector, Vector, uint32_t, unsigned char, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastSafeProjectile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void CNWSObject__BroadcastSpellData(CNWSObject* thisPtr, CNWSpell* a0, CNWCCMessageData* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSpell*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__BroadcastSpellData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__CalculateLastSpellProjectileTime(CNWSObject* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__CalculateLastSpellProjectileTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

Vector CNWSObject__CalculateSpellRangedMissTarget(CNWSObject* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__CalculateSpellRangedMissTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__ClearAction(CNWSObject* thisPtr, CNWSObjectActionNode* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObjectActionNode*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ClearAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__ClearAllActions(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ClearAllActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__ClearAllHostileActions(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ClearAllHostileActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__ClearMatchedExpressionStrings(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ClearMatchedExpressionStrings);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__ClearSpellEffectsOnOthers(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ClearSpellEffectsOnOthers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__CopyScriptVars(CNWSObject* thisPtr, CNWSScriptVarTable* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSScriptVarTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__CopyScriptVars);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__DeleteCurrentAIAction(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DeleteCurrentAIAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__DoDamage(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__DoDamageImmunity(CNWSObject* thisPtr, CNWSCreature* a0, int32_t a1, uint16_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSCreature*, int32_t, uint16_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoDamageImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSObject__DoDamageReduction(CNWSObject* thisPtr, CNWSCreature* a0, int32_t a1, unsigned char a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSCreature*, int32_t, unsigned char, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoDamageReduction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSObject__DoDamageResistance(CNWSObject* thisPtr, CNWSCreature* a0, int32_t a1, uint16_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSCreature*, int32_t, uint16_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoDamageResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSObject__DoSpellImmunity(CNWSObject* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoSpellImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__DoSpellLevelAbsorption(CNWSObject* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__DoSpellLevelAbsorption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__GetAcceptableAction(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetAcceptableAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSObject__GetActionByGroupId(CNWSObject* thisPtr, uint16_t a0, CNWSObjectActionNode** a1)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, CNWSObjectActionNode**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetActionByGroupId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSObject__GetAIStateReaction(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetAIStateReaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSObject__GetAQActionIDByID(CNWSObject* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetAQActionIDByID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSArea* CNWSObject__GetArea(CNWSObject* thisPtr)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int16_t CNWSObject__GetCurrentHitPoints(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetCurrentHitPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWSObject__GetDamageImmunity(CNWSObject* thisPtr, unsigned char a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSObject*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDamageImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWSObject__GetDamageImmunityByFlags(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDamageImmunityByFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSObject__GetDamageLevel(CNWSObject* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDamageLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__GetDead(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__GetDialogInterruptable(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDialogInterruptable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSObject__GetDialogResref(CNWSObject* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetDialogResref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSObject__GetEffectSpellId(CNWSObject* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSObject__GetFirstName(CNWSObject* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSObject__GetGender(CNWSObject* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetGender);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__GetHasFeatEffectApplied(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetHasFeatEffectApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSObject__GetIDByAQActionID(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetIDByAQActionID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__GetIsPCDying(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetIsPCDying);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__GetLastDamageAmountByFlags(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetLastDamageAmountByFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLocString& CNWSObject__GetLastName(CNWSObject* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetLastName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSExpression* CNWSObject__GetListenExpressionObj(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSExpression*(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetListenExpressionObj);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSObject__GetLockOrientationToObject(CNWSObject* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetLockOrientationToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int16_t CNWSObject__GetMaxHitPoints(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetMaxHitPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__GetMaximumDamageResistanceVsDamageFlag(CNWSObject* thisPtr, uint16_t a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetMaximumDamageResistanceVsDamageFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSObject__GetNearestObjectByName(CNWSObject* thisPtr, const CExoString& a0, float a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSObject*, const CExoString&, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetNearestObjectByName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint16_t CNWSObject__GetNewGroupID(CNWSObject* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetNewGroupID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSObjectActionNode* CNWSObject__GetNodeById(CNWSObject* thisPtr, uint16_t a0, uint16_t a1)
{
    using FuncPtrType = CNWSObjectActionNode*(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetNodeById);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__GetNumActionGroups(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetNumActionGroups);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSObject__GetPortrait(CNWSObject* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetPortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSObject__GetPortraitId(CNWSObject* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetPortraitId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLinkedListNode* CNWSObject__GetPositionByGroupIndex(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoLinkedListNode*(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetPositionByGroupIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__GetReputation(CNWSObject* thisPtr, uint32_t a0, int32_t& a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, int32_t&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CScriptLocation CNWSObject__GetScriptLocation(CNWSObject* thisPtr)
{
    using FuncPtrType = CScriptLocation(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__GetScriptLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__HasSpellEffectApplied(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__HasSpellEffectApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__IsDialogDelay(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__IsDialogDelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__LoadActionQueue(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__LoadActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__LoadEffectList(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__LoadEffectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__LoadListenData(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__LoadListenData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__LoadObjectState(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__LoadObjectState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__LoadVarTable(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__LoadVarTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__PlaySoundSet(CNWSObject* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__PlaySoundSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__RemoveEffect(CNWSObject* thisPtr, CGameEffect* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveEffectByCreator(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveEffectByCreator);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__RemoveEffectById(CNWSObject* thisPtr, uint64_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveEffectById);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveEffectBySpellId(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveEffectBySpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveEffectTarget(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveEffectTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveGroup(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveGroup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveLoopingVisualEffect(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveLoopingVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__RemoveObjectFromDialog(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveObjectFromDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__RemoveSomeEffectsOfDurationType(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RemoveSomeEffectsOfDurationType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSObject__ReplyDialog(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ReplyDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSObject__ReportOverflow(CNWSObject* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__ReportOverflow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSObject__RunActions(CNWSObject* thisPtr, uint32_t a0, uint32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RunActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSObject__RunDialogOneLiner(CNWSObject* thisPtr, const CExoString& a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, const CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__RunDialogOneLiner);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SaveActionQueue(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SaveActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SaveEffectList(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SaveEffectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SaveListenData(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SaveListenData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SaveObjectState(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SaveObjectState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SaveVarTable(CNWSObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SaveVarTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__SendDialogEntry(CNWSObject* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SendDialogEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__SendDialogReplies(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SendDialogReplies);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__SetAnimation(CNWSObject* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetArea(CNWSObject* thisPtr, CNWSArea* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetDamageImmunity(CNWSObject* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetDamageImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SetDialogDelay(CNWSObject* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetDialogDelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetDialogOwner(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetDialogOwner);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetEffectSpellId(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetGroupInterruptable(CNWSObject* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetGroupInterruptable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SetLastHostileActor(CNWSObject* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetLastHostileActor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__SetListenExpression(CNWSObject* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetListenExpression);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SetLockOrientationToObject(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetLockOrientationToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetOrientation(CNWSObject* thisPtr, Vector a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetOrientation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetPortrait(CNWSObject* thisPtr, CResRef a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetPortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetPortraitId(CNWSObject* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetPortraitId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__SetPosition(CNWSObject* thisPtr, Vector a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, Vector, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SetPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__SpawnBodyBag(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SpawnBodyBag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__SpellCastAndImpact(CNWSObject* thisPtr, uint32_t a0, Vector a1, uint32_t a2, unsigned char a3, uint32_t a4, int32_t a5, int32_t a6, unsigned char a7, int32_t a8)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, Vector, uint32_t, unsigned char, uint32_t, int32_t, int32_t, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__SpellCastAndImpact);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSObject__StartDialog(CNWSObject* thisPtr, uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, const CExoString&, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__StartDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSObject__StopDialog(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__StopDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__TerminateAISliceAfterAction(CNWSObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__TerminateAISliceAfterAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__TestActionList(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__TestActionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSObject__TestListenExpression(CNWSObject* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__TestListenExpression);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSObject__UpdateAttributesOnEffect(CNWSObject* thisPtr, CGameEffect* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__UpdateAttributesOnEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSObject__UpdateDialog(CNWSObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__UpdateDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSObject__UpdateEffectList(CNWSObject* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__UpdateEffectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSObject__UpdateEffectPtrs(CNWSObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObject__UpdateEffectPtrs);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
