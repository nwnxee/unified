#include "CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCNWSInvitationDetails.hpp"
#include "CExoArrayListTemplatedCNWSPVPEntry.hpp"
#include "CExoArrayListTemplatedCNWSPersonalReputation.hpp"
#include "CExoArrayListTemplatedint.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CExoLocString.hpp"
#include "CGameEffect.hpp"
#include "CItemRepository.hpp"
#include "CNWCCMessageData.hpp"
#include "CNWItemProperty.hpp"
#include "CNWSArea.hpp"
#include "CNWSBarter.hpp"
#include "CNWSCombatAttackData.hpp"
#include "CNWSCombatRound.hpp"
#include "CNWSCreRestorePolymorphData.hpp"
#include "CNWSCreatureStats.hpp"
#include "CNWSFaction.hpp"
#include "CNWSForcedAction.hpp"
#include "CNWSInventory.hpp"
#include "CNWSItem.hpp"
#include "CNWSJournal.hpp"
#include "CNWSObjectActionNode.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSQuickbarButton.hpp"
#include "CNWVisibilityNode.hpp"
#include "CPathfindInformation.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSCreature::CNWSCreature(uint32_t a0, int32_t a1, int32_t a2)
{
    CNWSCreature__CNWSCreatureCtor(this, a0, a1, a2);
}

CNWSCreature::~CNWSCreature()
{
    CNWSCreature__CNWSCreatureDtor__0(this);
}

int32_t CNWSCreature::AcquireItem(CNWSItem** a0, uint32_t a1, uint32_t a2, unsigned char a3, unsigned char a4, int32_t a5, int32_t a6)
{
    return CNWSCreature__AcquireItem(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature::ActionManager(uint32_t a0)
{
    return CNWSCreature__ActionManager(this, a0);
}

void CNWSCreature::ActivityManager(uint32_t a0)
{
    return CNWSCreature__ActivityManager(this, a0);
}

int32_t CNWSCreature::AddAnimalEmpathyAction(uint32_t a0)
{
    return CNWSCreature__AddAnimalEmpathyAction(this, a0);
}

int32_t CNWSCreature::AddAppearActions(int32_t a0)
{
    return CNWSCreature__AddAppearActions(this, a0);
}

void CNWSCreature::AddAssociate(uint32_t a0, uint16_t a1)
{
    return CNWSCreature__AddAssociate(this, a0, a1);
}

int32_t CNWSCreature::AddAttackActions(uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__AddAttackActions(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::AddCastSpellActions(uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, Vector a5, uint32_t a6, int32_t a7, int32_t a8, int32_t a9, unsigned char a10, int32_t a11, int32_t a12, int32_t a13, unsigned char a14)
{
    return CNWSCreature__AddCastSpellActions(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}

int32_t CNWSCreature::AddCounterSpellActions(uint32_t a0)
{
    return CNWSCreature__AddCounterSpellActions(this, a0);
}

int32_t CNWSCreature::AddDisappearActions(int32_t a0, int32_t a1)
{
    return CNWSCreature__AddDisappearActions(this, a0, a1);
}

int32_t CNWSCreature::AddDriveAction(uint16_t a0, const Vector& a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSCreature__AddDriveAction(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature::AddDropItemActions(uint32_t a0, Vector a1, int32_t a2)
{
    return CNWSCreature__AddDropItemActions(this, a0, a1, a2);
}

int32_t CNWSCreature::AddEquipItemActions(CNWSItem* a0, uint32_t a1, int32_t a2, int32_t a3, uint32_t a4)
{
    return CNWSCreature__AddEquipItemActions(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::AddGold(int32_t a0, int32_t a1)
{
    return CNWSCreature__AddGold(this, a0, a1);
}

int32_t CNWSCreature::AddHealActions(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSCreature__AddHealActions(this, a0, a1, a2);
}

int32_t CNWSCreature::AddItemCastSpellActions(uint32_t a0, int32_t a1, int32_t a2, Vector a3, uint32_t a4, int32_t a5)
{
    return CNWSCreature__AddItemCastSpellActions(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature::AddMoveToPointAction(uint16_t a0, Vector a1, uint32_t a2, uint32_t a3, int32_t a4, float a5, float a6, int32_t a7, int32_t a8, int32_t a9, int32_t a10, int32_t a11, int32_t a12)
{
    return CNWSCreature__AddMoveToPointAction(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

int32_t CNWSCreature::AddMoveToPointActionToFront(uint16_t a0, Vector a1, uint32_t a2, uint32_t a3, int32_t a4, float a5, float a6, int32_t a7, int32_t a8, int32_t a9, int32_t a10, int32_t a11, int32_t a12)
{
    return CNWSCreature__AddMoveToPointActionToFront(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

int32_t CNWSCreature::AddPathfindingWaitActionToFront(uint16_t a0)
{
    return CNWSCreature__AddPathfindingWaitActionToFront(this, a0);
}

int32_t CNWSCreature::AddPickPocketActions(uint32_t a0)
{
    return CNWSCreature__AddPickPocketActions(this, a0);
}

int32_t CNWSCreature::AddPickUpItemActions(uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    return CNWSCreature__AddPickUpItemActions(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::AddRepositoryMoveActions(CNWSItem* a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    return CNWSCreature__AddRepositoryMoveActions(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::AddSitActions(uint32_t a0)
{
    return CNWSCreature__AddSitActions(this, a0);
}

int32_t CNWSCreature::AddTauntActions(uint32_t a0)
{
    return CNWSCreature__AddTauntActions(this, a0);
}

void CNWSCreature::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSCreature__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::AddToAssociateList(uint32_t a0)
{
    return CNWSCreature__AddToAssociateList(this, a0);
}

void CNWSCreature::AddToInvitationsIgnored(uint32_t a0)
{
    return CNWSCreature__AddToInvitationsIgnored(this, a0);
}

void CNWSCreature::AddToInvitationsOffered(uint32_t a0)
{
    return CNWSCreature__AddToInvitationsOffered(this, a0);
}

void CNWSCreature::AddToPersonalReputationList(uint32_t a0, int32_t a1, int32_t a2, float a3)
{
    return CNWSCreature__AddToPersonalReputationList(this, a0, a1, a2, a3);
}

void CNWSCreature::AddToPVPList(uint32_t a0)
{
    return CNWSCreature__AddToPVPList(this, a0);
}

void CNWSCreature::AddToVisibleList(uint32_t a0, int32_t a1, int32_t a2, unsigned char a3, int32_t a4)
{
    return CNWSCreature__AddToVisibleList(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature::AddTrapActions(uint32_t a0, unsigned char a1, uint32_t a2, Vector a3, uint32_t a4)
{
    return CNWSCreature__AddTrapActions(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature::AddUnequipActions(CNWSItem* a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4, int32_t a5, uint32_t a6)
{
    return CNWSCreature__AddUnequipActions(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreature::AddUseTalentAtLocationActions(int32_t a0, int32_t a1, Vector a2, unsigned char a3, uint32_t a4, int32_t a5, unsigned char a6, unsigned char a7)
{
    return CNWSCreature__AddUseTalentAtLocationActions(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSCreature::AddUseTalentOnObjectActions(int32_t a0, int32_t a1, uint32_t a2, unsigned char a3, uint32_t a4, int32_t a5, unsigned char a6, unsigned char a7)
{
    return CNWSCreature__AddUseTalentOnObjectActions(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNWSCreature::AdjustReputation(int32_t a0, int32_t a1)
{
    return CNWSCreature__AdjustReputation(this, a0, a1);
}

uint32_t CNWSCreature::AIActionAnimalEmpathy(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionAnimalEmpathy(this, a0);
}

uint32_t CNWSCreature::AIActionAppear(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionAppear(this, a0);
}

uint32_t CNWSCreature::AIActionAreaWait(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionAreaWait(this, a0);
}

uint32_t CNWSCreature::AIActionAttackObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionAttackObject(this, a0);
}

uint32_t CNWSCreature::AIActionBarter(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionBarter(this, a0);
}

uint32_t CNWSCreature::AIActionCastSpell(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCastSpell(this, a0);
}

uint32_t CNWSCreature::AIActionChangeFacingObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionChangeFacingObject(this, a0);
}

uint32_t CNWSCreature::AIActionChangeFacingPoint(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionChangeFacingPoint(this, a0);
}

uint32_t CNWSCreature::AIActionCheckForceFollowObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckForceFollowObject(this, a0);
}

uint32_t CNWSCreature::AIActionCheckInterAreaPathfinding(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckInterAreaPathfinding(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveAwayFromLocation(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveAwayFromLocation(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveAwayFromObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveAwayFromObject(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveToObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveToObject(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveToObjectRadius(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveToObjectRadius(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveToPoint(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveToPoint(this, a0);
}

uint32_t CNWSCreature::AIActionCheckMoveToPointRadius(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCheckMoveToPointRadius(this, a0);
}

uint32_t CNWSCreature::AIActionCounterSpell(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionCounterSpell(this, a0);
}

uint32_t CNWSCreature::AIActionDisappear(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionDisappear(this, a0);
}

uint32_t CNWSCreature::AIActionDisarmTrap(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionDisarmTrap(this, a0);
}

uint32_t CNWSCreature::AIActionDrive(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionDrive(this, a0);
}

uint32_t CNWSCreature::AIActionDropItem(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionDropItem(this, a0);
}

uint32_t CNWSCreature::AIActionEncounterCreatureDestroySelf()
{
    return CNWSCreature__AIActionEncounterCreatureDestroySelf(this);
}

uint32_t CNWSCreature::AIActionEquipItem(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionEquipItem(this, a0);
}

uint32_t CNWSCreature::AIActionExamine(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionExamine(this, a0);
}

uint32_t CNWSCreature::AIActionExamineTrap(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionExamineTrap(this, a0);
}

uint32_t CNWSCreature::AIActionFlagTrap(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionFlagTrap(this, a0);
}

uint32_t CNWSCreature::AIActionForceFollowObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionForceFollowObject(this, a0);
}

uint32_t CNWSCreature::AIActionHeal(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionHeal(this, a0);
}

uint32_t CNWSCreature::AIActionItemCastSpell(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionItemCastSpell(this, a0);
}

uint32_t CNWSCreature::AIActionJumpToObject(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionJumpToObject(this, a0);
}

uint32_t CNWSCreature::AIActionJumpToPoint(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionJumpToPoint(this, a0);
}

uint32_t CNWSCreature::AIActionMoveToPoint(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionMoveToPoint(this, a0);
}

uint32_t CNWSCreature::AIActionOrientCamera(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionOrientCamera(this, a0);
}

uint32_t CNWSCreature::AIActionPickPocket(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionPickPocket(this, a0);
}

uint32_t CNWSCreature::AIActionPickUpItem(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionPickUpItem(this, a0);
}

uint32_t CNWSCreature::AIActionRandomWalk(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionRandomWalk(this, a0);
}

uint32_t CNWSCreature::AIActionRecoverTrap(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionRecoverTrap(this, a0);
}

uint32_t CNWSCreature::AIActionRepositoryMove(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionRepositoryMove(this, a0);
}

uint32_t CNWSCreature::AIActionRest(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionRest(this, a0);
}

uint32_t CNWSCreature::AIActionSetTrap(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionSetTrap(this, a0);
}

uint32_t CNWSCreature::AIActionSit(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionSit(this, a0);
}

uint32_t CNWSCreature::AIActionTaunt(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionTaunt(this, a0);
}

uint32_t CNWSCreature::AIActionUnequipItem(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionUnequipItem(this, a0);
}

uint32_t CNWSCreature::AIActionWaitForEndOfRound(CNWSObjectActionNode* a0)
{
    return CNWSCreature__AIActionWaitForEndOfRound(this, a0);
}

void CNWSCreature::AIUpdate()
{
    return CNWSCreature__AIUpdate(this);
}

void CNWSCreature::ApplyDeathExperience()
{
    return CNWSCreature__ApplyDeathExperience(this);
}

int32_t CNWSCreature::ApplyDiseasePayload(CGameEffect* a0, uint32_t a1, uint32_t a2)
{
    return CNWSCreature__ApplyDiseasePayload(this, a0, a1, a2);
}

void CNWSCreature::ApplyOnHitAbilityDamage(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitAbilityDamage(this, a0, a1);
}

void CNWSCreature::ApplyOnHitBlindness(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitBlindness(this, a0, a1);
}

void CNWSCreature::ApplyOnHitCastSpell(CNWSObject* a0, CNWItemProperty* a1, CNWSItem* a2)
{
    return CNWSCreature__ApplyOnHitCastSpell(this, a0, a1, a2);
}

void CNWSCreature::ApplyOnHitConfusion(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitConfusion(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDaze(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitDaze(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDeafness(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitDeafness(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDeathAttack(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitDeathAttack(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDisease(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitDisease(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDispelMagic(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitDispelMagic__0(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDispelMagic(CNWSObject* a0, uint32_t a1)
{
    return CNWSCreature__ApplyOnHitDispelMagic__1(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDominate(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitDominate(this, a0, a1);
}

void CNWSCreature::ApplyOnHitDoom(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitDoom(this, a0, a1);
}

void CNWSCreature::ApplyOnHitFear(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitFear(this, a0, a1);
}

void CNWSCreature::ApplyOnHitGreaterDispel(CNWSObject* a0, uint32_t a1)
{
    return CNWSCreature__ApplyOnHitGreaterDispel(this, a0, a1);
}

void CNWSCreature::ApplyOnHitHold(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitHold(this, a0, a1);
}

void CNWSCreature::ApplyOnHitKnock(CNWSObject* a0, uint32_t a1)
{
    return CNWSCreature__ApplyOnHitKnock(this, a0, a1);
}

void CNWSCreature::ApplyOnHitLesserDispel(CNWSObject* a0, uint32_t a1)
{
    return CNWSCreature__ApplyOnHitLesserDispel(this, a0, a1);
}

void CNWSCreature::ApplyOnHitLevelDrain(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitLevelDrain(this, a0, a1);
}

void CNWSCreature::ApplyOnHitMordysDisjunction(CNWSObject* a0, uint32_t a1)
{
    return CNWSCreature__ApplyOnHitMordysDisjunction(this, a0, a1);
}

void CNWSCreature::ApplyOnHitPoison(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitPoison(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSilence(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitSilence(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSlayAlignment(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitSlayAlignment(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSlayAlignmentGroup(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitSlayAlignmentGroup(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSlayRacialGroup(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitSlayRacialGroup(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSleep(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitSleep(this, a0, a1);
}

void CNWSCreature::ApplyOnHitSlow(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitSlow(this, a0, a1);
}

void CNWSCreature::ApplyOnHitStun(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ApplyOnHitStun(this, a0, a1);
}

void CNWSCreature::ApplyOnHitVampiricRegeneration(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitVampiricRegeneration(this, a0, a1);
}

void CNWSCreature::ApplyOnHitVorpal(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitVorpal(this, a0, a1);
}

void CNWSCreature::ApplyOnHitWounding(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__ApplyOnHitWounding(this, a0, a1);
}

int32_t CNWSCreature::ApplyPoisonPayload(CGameEffect* a0, uint32_t a1, uint32_t a2)
{
    return CNWSCreature__ApplyPoisonPayload(this, a0, a1, a2);
}

int32_t CNWSCreature::ApplyWounding(CGameEffect* a0)
{
    return CNWSCreature__ApplyWounding(this, a0);
}

CNWSCreature* CNWSCreature::AsNWSCreature()
{
    return CNWSCreature__AsNWSCreature(this);
}

void CNWSCreature::AutoCloseGUIPanels(int32_t a0)
{
    return CNWSCreature__AutoCloseGUIPanels(this, a0);
}

void CNWSCreature::BringAssociatesToNewFaction(int32_t a0)
{
    return CNWSCreature__BringAssociatesToNewFaction(this, a0);
}

void CNWSCreature::BroadcastAssociateCommand(int32_t a0)
{
    return CNWSCreature__BroadcastAssociateCommand(this, a0);
}

void CNWSCreature::BroadcastAttackDataToParty(CNWCCMessageData* a0, CNWSCombatAttackData* a1, CNWSCreature* a2)
{
    return CNWSCreature__BroadcastAttackDataToParty(this, a0, a1, a2);
}

void CNWSCreature::BroadcastAttackOfOpportunity(uint32_t a0, int32_t a1)
{
    return CNWSCreature__BroadcastAttackOfOpportunity(this, a0, a1);
}

void CNWSCreature::BroadcastBattleCry()
{
    return CNWSCreature__BroadcastBattleCry(this);
}

void CNWSCreature::BroadcastCombatStateToParty()
{
    return CNWSCreature__BroadcastCombatStateToParty(this);
}

void CNWSCreature::BroadcastDamageDataToParty(CNWCCMessageData* a0, CNWSCreature* a1)
{
    return CNWSCreature__BroadcastDamageDataToParty(this, a0, a1);
}

void CNWSCreature::BroadcastDeathDataToParty(CNWCCMessageData* a0, CNWSCreature* a1)
{
    return CNWSCreature__BroadcastDeathDataToParty(this, a0, a1);
}

void CNWSCreature::BroadcastFloatyData(CNWCCMessageData* a0)
{
    return CNWSCreature__BroadcastFloatyData(this, a0);
}

void CNWSCreature::BroadcastSavingThrowData(CNWCCMessageData* a0)
{
    return CNWSCreature__BroadcastSavingThrowData(this, a0);
}

void CNWSCreature::BroadcastSkillData(CNWCCMessageData* a0)
{
    return CNWSCreature__BroadcastSkillData(this, a0);
}

void CNWSCreature::BroadcastSpellCast(uint32_t a0, unsigned char a1, uint16_t a2)
{
    return CNWSCreature__BroadcastSpellCast(this, a0, a1, a2);
}

void CNWSCreature::BroadcastVoiceChat(unsigned char a0)
{
    return CNWSCreature__BroadcastVoiceChat(this, a0);
}

void CNWSCreature::BroadcastWhirlwindAttack(int32_t a0)
{
    return CNWSCreature__BroadcastWhirlwindAttack(this, a0);
}

int32_t CNWSCreature::BumpFriends(CNWSCreature* a0, const Vector& a1, const Vector& a2)
{
    return CNWSCreature__BumpFriends(this, a0, a1, a2);
}

unsigned char CNWSCreature::CalculateDamagePower(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__CalculateDamagePower(this, a0, a1);
}

float CNWSCreature::CalculateDeathExperience(int32_t a0, int32_t a1)
{
    return CNWSCreature__CalculateDeathExperience(this, a0, a1);
}

int32_t CNWSCreature::CalculateMaxElementalDamage(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__CalculateMaxElementalDamage(this, a0, a1);
}

int32_t CNWSCreature::CalculatePersonalReputationAdjustment(uint32_t a0)
{
    return CNWSCreature__CalculatePersonalReputationAdjustment(this, a0);
}

uint32_t CNWSCreature::CalculateProjectileTimeToTarget(Vector a0, int32_t a1)
{
    return CNWSCreature__CalculateProjectileTimeToTarget(this, a0, a1);
}

int32_t CNWSCreature::CalculateSpellSaveDC(int32_t a0)
{
    return CNWSCreature__CalculateSpellSaveDC(this, a0);
}

int32_t CNWSCreature::CancelAction(uint16_t a0, uint16_t a1)
{
    return CNWSCreature__CancelAction(this, a0, a1);
}

void CNWSCreature::CancelGoldTransfer(uint32_t a0)
{
    return CNWSCreature__CancelGoldTransfer(this, a0);
}

void CNWSCreature::CancelRest(uint16_t a0)
{
    return CNWSCreature__CancelRest(this, a0);
}

unsigned char CNWSCreature::CanEquipItem(CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3, int32_t a4, CNWSPlayer* a5)
{
    return CNWSCreature__CanEquipItem(this, a0, a1, a2, a3, a4, a5);
}

unsigned char CNWSCreature::CanEquipMiscellaneous(CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__CanEquipMiscellaneous(this, a0, a1, a2, a3);
}

unsigned char CNWSCreature::CanEquipShield(CNWSItem* a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__CanEquipShield(this, a0, a1, a2);
}

unsigned char CNWSCreature::CanEquipWeapon(CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3, CNWSPlayer* a4)
{
    return CNWSCreature__CanEquipWeapon(this, a0, a1, a2, a3, a4);
}

unsigned char CNWSCreature::CanUnEquipWeapon(CNWSItem* a0)
{
    return CNWSCreature__CanUnEquipWeapon(this, a0);
}

int32_t CNWSCreature::CanUseItem(CNWSItem* a0, int32_t a1)
{
    return CNWSCreature__CanUseItem(this, a0, a1);
}

void CNWSCreature::CheckInventoryForPlotItems()
{
    return CNWSCreature__CheckInventoryForPlotItems(this);
}

int32_t CNWSCreature::CheckItemAlignmentRestrictions(CNWSItem* a0)
{
    return CNWSCreature__CheckItemAlignmentRestrictions(this, a0);
}

int32_t CNWSCreature::CheckItemClassRestrictions(CNWSItem* a0)
{
    return CNWSCreature__CheckItemClassRestrictions(this, a0);
}

int32_t CNWSCreature::CheckItemRaceRestrictions(CNWSItem* a0)
{
    return CNWSCreature__CheckItemRaceRestrictions(this, a0);
}

void CNWSCreature::CheckMasterIsValid(uint32_t a0, uint32_t a1)
{
    return CNWSCreature__CheckMasterIsValid(this, a0, a1);
}

int32_t CNWSCreature::CheckProficiencies(CNWSItem* a0, uint32_t a1)
{
    return CNWSCreature__CheckProficiencies(this, a0, a1);
}

int32_t CNWSCreature::CheckUseMagicDeviceSkill(CNWSItem* a0, int32_t a1)
{
    return CNWSCreature__CheckUseMagicDeviceSkill(this, a0, a1);
}

int32_t CNWSCreature::CheckVisibleList(uint32_t a0)
{
    return CNWSCreature__CheckVisibleList(this, a0);
}

void CNWSCreature::CleanInvitationLists(int32_t a0)
{
    return CNWSCreature__CleanInvitationLists(this, a0);
}

void CNWSCreature::CleanOutPersonalReputationList()
{
    return CNWSCreature__CleanOutPersonalReputationList(this);
}

int32_t CNWSCreature::ClearAction(CNWSObjectActionNode* a0, int32_t a1)
{
    return CNWSCreature__ClearAction(this, a0, a1);
}

void CNWSCreature::ClearActivities(int32_t a0)
{
    return CNWSCreature__ClearActivities(this, a0);
}

void CNWSCreature::ClearAutoMapData()
{
    return CNWSCreature__ClearAutoMapData(this);
}

void CNWSCreature::ClearHostileActionsVersus(CNWSCreature* a0)
{
    return CNWSCreature__ClearHostileActionsVersus(this, a0);
}

void CNWSCreature::ClearPersonalReputation(uint32_t a0)
{
    return CNWSCreature__ClearPersonalReputation(this, a0);
}

void CNWSCreature::ClearVisibleList()
{
    return CNWSCreature__ClearVisibleList(this);
}

void CNWSCreature::ComputeAIState()
{
    return CNWSCreature__ComputeAIState(this);
}

void CNWSCreature::ComputeAIStateOnAction(int32_t a0, uint32_t a1)
{
    return CNWSCreature__ComputeAIStateOnAction(this, a0, a1);
}

void CNWSCreature::ComputeArmourClass(CNWSItem* a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__ComputeArmourClass(this, a0, a1, a2);
}

void CNWSCreature::ComputeModifiedMovementRate()
{
    return CNWSCreature__ComputeModifiedMovementRate(this);
}

float CNWSCreature::ComputeSpellRange(CExoString a0, uint32_t a1)
{
    return CNWSCreature__ComputeSpellRange(this, a0, a1);
}

int32_t CNWSCreature::ComputeTotalEquippedWeight()
{
    return CNWSCreature__ComputeTotalEquippedWeight(this);
}

float CNWSCreature::ComputeTotalWalkDistance()
{
    return CNWSCreature__ComputeTotalWalkDistance(this);
}

int32_t CNWSCreature::ComputeTotalWeightCarried()
{
    return CNWSCreature__ComputeTotalWeightCarried(this);
}

void CNWSCreature::ConvertModeToggleQuickButton(CNWSQuickbarButton* a0)
{
    return CNWSCreature__ConvertModeToggleQuickButton(this, a0);
}

void CNWSCreature::CopyQuickButtonsFromDM(CNWSPlayer* a0)
{
    return CNWSCreature__CopyQuickButtonsFromDM(this, a0);
}

void CNWSCreature::CreateDefaultQuickButtons()
{
    return CNWSCreature__CreateDefaultQuickButtons(this);
}

void CNWSCreature::CreateDefaultQuickButtons_AddFeat(unsigned char& a0, uint16_t a1, int32_t a2)
{
    return CNWSCreature__CreateDefaultQuickButtons_AddFeat(this, a0, a1, a2);
}

void CNWSCreature::CreateDefaultQuickButtons_CheckItem(CNWSItem* a0, uint32_t& a1, uint32_t& a2, uint32_t& a3, uint32_t& a4)
{
    return CNWSCreature__CreateDefaultQuickButtons_CheckItem(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::CreateDefaultQuickButtonsDM()
{
    return CNWSCreature__CreateDefaultQuickButtonsDM(this);
}

void CNWSCreature::CutWaypointPath()
{
    return CNWSCreature__CutWaypointPath(this);
}

int32_t CNWSCreature::DecrementSpellReadyCount(uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4)
{
    return CNWSCreature__DecrementSpellReadyCount(this, a0, a1, a2, a3, a4);
}

float CNWSCreature::DesiredAttackRange(uint32_t a0, int32_t a1)
{
    return CNWSCreature__DesiredAttackRange(this, a0, a1);
}

void CNWSCreature::DestroyEquippedItems()
{
    return CNWSCreature__DestroyEquippedItems(this);
}

void CNWSCreature::DisplayFloatyDataToSelf(uint32_t a0)
{
    return CNWSCreature__DisplayFloatyDataToSelf(this, a0);
}

void CNWSCreature::DMClearScripts(int32_t a0)
{
    return CNWSCreature__DMClearScripts(this, a0);
}

void CNWSCreature::DMResetClearedScripts(int32_t a0)
{
    return CNWSCreature__DMResetClearedScripts(this, a0);
}

void CNWSCreature::DoCombatStep(unsigned char a0, int32_t a1, uint32_t a2)
{
    return CNWSCreature__DoCombatStep(this, a0, a1, a2);
}

void CNWSCreature::DoDamage(int32_t a0)
{
    return CNWSCreature__DoDamage(this, a0);
}

int32_t CNWSCreature::DoListenDetection(CNWSCreature* a0, int32_t a1)
{
    return CNWSCreature__DoListenDetection(this, a0, a1);
}

void CNWSCreature::DoPerceptionUpdateOnCreature(CNWSCreature* a0, int32_t a1)
{
    return CNWSCreature__DoPerceptionUpdateOnCreature(this, a0, a1);
}

int32_t CNWSCreature::DoSpotDetection(CNWSCreature* a0, int32_t a1)
{
    return CNWSCreature__DoSpotDetection(this, a0, a1);
}

int32_t CNWSCreature::DoStealthDetection(CNWSCreature* a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t a4)
{
    return CNWSCreature__DoStealthDetection(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSCreature::DriveUpdateLocation(int32_t a0)
{
    return CNWSCreature__DriveUpdateLocation(this, a0);
}

void CNWSCreature::DumpToLog()
{
    return CNWSCreature__DumpToLog(this);
}

int32_t CNWSCreature::EquipItem(uint32_t a0, CNWSItem* a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__EquipItem(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::EquipMostDamagingAmmunition(uint32_t a0, CNWSItem* a1)
{
    return CNWSCreature__EquipMostDamagingAmmunition(this, a0, a1);
}

int32_t CNWSCreature::EquipMostDamagingMeleeWeapon(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__EquipMostDamagingMeleeWeapon(this, a0, a1, a2);
}

int32_t CNWSCreature::EquipMostDamagingRangedWeapon(uint32_t a0)
{
    return CNWSCreature__EquipMostDamagingRangedWeapon(this, a0);
}

int32_t CNWSCreature::EquipMostEffectiveArmor()
{
    return CNWSCreature__EquipMostEffectiveArmor(this);
}

int32_t CNWSCreature::EvaluateLock(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__EvaluateLock(this, a0, a1);
}

void CNWSCreature::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSCreature__EventHandler(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::ExternalResolveAttack(uint32_t a0, int32_t a1)
{
    return CNWSCreature__ExternalResolveAttack(this, a0, a1);
}

void CNWSCreature::FailedOpenInformAssociates()
{
    return CNWSCreature__FailedOpenInformAssociates(this);
}

int32_t CNWSCreature::ForceMoveToPoint(CNWSForcedAction* a0)
{
    return CNWSCreature__ForceMoveToPoint(this, a0);
}

int32_t CNWSCreature::GetActivity(int32_t a0)
{
    return CNWSCreature__GetActivity(this, a0);
}

int32_t CNWSCreature::GetAmmunitionAvailable(int32_t a0)
{
    return CNWSCreature__GetAmmunitionAvailable(this, a0);
}

int16_t CNWSCreature::GetArmorClass()
{
    return CNWSCreature__GetArmorClass(this);
}

uint32_t CNWSCreature::GetAssociateId(uint16_t a0, int32_t a1)
{
    return CNWSCreature__GetAssociateId(this, a0, a1);
}

int32_t CNWSCreature::GetAttackResultHit(CNWSCombatAttackData* a0)
{
    return CNWSCreature__GetAttackResultHit(this, a0);
}

CNWSBarter* CNWSCreature::GetBarterInfo(int32_t a0)
{
    return CNWSCreature__GetBarterInfo(this, a0);
}

int32_t CNWSCreature::GetBlind()
{
    return CNWSCreature__GetBlind(this);
}

uint16_t CNWSCreature::GetBodyBagAppearance()
{
    return CNWSCreature__GetBodyBagAppearance(this);
}

int32_t CNWSCreature::GetCanSlayAlignment(CNWSObject* a0, CNWItemProperty* a1)
{
    return CNWSCreature__GetCanSlayAlignment(this, a0, a1);
}

int32_t CNWSCreature::GetCreatureReputation(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__GetCreatureReputation(this, a0, a1, a2);
}

uint16_t CNWSCreature::GetDamageFlags()
{
    return CNWSCreature__GetDamageFlags(this);
}

unsigned char CNWSCreature::GetDetectMode()
{
    return CNWSCreature__GetDetectMode(this);
}

int32_t CNWSCreature::GetDialogInterruptable()
{
    return CNWSCreature__GetDialogInterruptable(this);
}

CResRef CNWSCreature::GetDialogResref()
{
    return CNWSCreature__GetDialogResref(this);
}

uint32_t CNWSCreature::GetDominatedCreatureId()
{
    return CNWSCreature__GetDominatedCreatureId(this);
}

uint32_t CNWSCreature::GetEffectSpellId()
{
    return CNWSCreature__GetEffectSpellId(this);
}

CNWSFaction* CNWSCreature::GetFaction()
{
    return CNWSCreature__GetFaction(this);
}

CExoArrayListTemplatedCGameEffectPtr CNWSCreature::GetFilteredEffectList(unsigned char a0)
{
    return CNWSCreature__GetFilteredEffectList(this, a0);
}

CExoLocString& CNWSCreature::GetFirstName()
{
    return CNWSCreature__GetFirstName(this);
}

int32_t CNWSCreature::GetFlanked(CNWSCreature* a0)
{
    return CNWSCreature__GetFlanked(this, a0);
}

int32_t CNWSCreature::GetFlatFooted()
{
    return CNWSCreature__GetFlatFooted(this);
}

unsigned char CNWSCreature::GetGender()
{
    return CNWSCreature__GetGender(this);
}

int32_t CNWSCreature::GetHasInvisbilityEffectApplied()
{
    return CNWSCreature__GetHasInvisbilityEffectApplied(this);
}

int32_t CNWSCreature::GetHenchmanIndex(uint32_t a0)
{
    return CNWSCreature__GetHenchmanIndex(this, a0);
}

int32_t CNWSCreature::GetInvisible(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__GetInvisible(this, a0, a1);
}

int32_t CNWSCreature::GetIsAbleToPossessFamiliar()
{
    return CNWSCreature__GetIsAbleToPossessFamiliar(this);
}

int32_t CNWSCreature::GetIsCreatureBumpable(CNWSCreature* a0)
{
    return CNWSCreature__GetIsCreatureBumpable(this, a0);
}

int32_t CNWSCreature::GetIsInInvitationsIgnored(uint32_t a0)
{
    return CNWSCreature__GetIsInInvitationsIgnored(this, a0);
}

int32_t CNWSCreature::GetIsInInvitationsOffered(uint32_t a0)
{
    return CNWSCreature__GetIsInInvitationsOffered(this, a0);
}

int32_t CNWSCreature::GetIsInMelee()
{
    return CNWSCreature__GetIsInMelee(this);
}

int32_t CNWSCreature::GetIsInUseRange(uint32_t a0, float a1, int32_t a2)
{
    return CNWSCreature__GetIsInUseRange(this, a0, a1, a2);
}

int32_t CNWSCreature::GetIsPossessedFamiliar()
{
    return CNWSCreature__GetIsPossessedFamiliar(this);
}

int32_t CNWSCreature::GetIsWeaponEffective(uint32_t a0, int32_t a1)
{
    return CNWSCreature__GetIsWeaponEffective(this, a0, a1);
}

uint32_t CNWSCreature::GetItemCount(int32_t a0)
{
    return CNWSCreature__GetItemCount(this, a0);
}

CNWSJournal* CNWSCreature::GetJournal()
{
    return CNWSCreature__GetJournal(this);
}

CExoLocString& CNWSCreature::GetLastName()
{
    return CNWSCreature__GetLastName(this);
}

float CNWSCreature::GetListenCheckDistance()
{
    return CNWSCreature__GetListenCheckDistance(this);
}

uint32_t CNWSCreature::GetLockOrientationToObject()
{
    return CNWSCreature__GetLockOrientationToObject(this);
}

int16_t CNWSCreature::GetMaxHitPoints(int32_t a0)
{
    return CNWSCreature__GetMaxHitPoints(this, a0);
}

int32_t CNWSCreature::GetMode(unsigned char a0)
{
    return CNWSCreature__GetMode(this, a0);
}

float CNWSCreature::GetMovementRateFactor()
{
    return CNWSCreature__GetMovementRateFactor(this);
}

uint32_t CNWSCreature::GetNearestEnemy(float a0, uint32_t a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__GetNearestEnemy(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::GetNumAssociatesOfType(uint16_t a0)
{
    return CNWSCreature__GetNumAssociatesOfType(this, a0);
}

int32_t CNWSCreature::GetNumCounterSpellingCreatures(uint32_t a0)
{
    return CNWSCreature__GetNumCounterSpellingCreatures(this, a0);
}

int32_t CNWSCreature::GetNumInvited()
{
    return CNWSCreature__GetNumInvited(this);
}

CResRef CNWSCreature::GetPortrait()
{
    return CNWSCreature__GetPortrait(this);
}

int32_t CNWSCreature::GetPVPPlayerLikesMe(uint32_t a0)
{
    return CNWSCreature__GetPVPPlayerLikesMe(this, a0);
}

int32_t CNWSCreature::GetPVPReputation(uint32_t a0)
{
    return CNWSCreature__GetPVPReputation(this, a0);
}

CNWSQuickbarButton* CNWSCreature::GetQuickbarButton(unsigned char a0)
{
    return CNWSCreature__GetQuickbarButton(this, a0);
}

int32_t CNWSCreature::GetRangeWeaponEquipped()
{
    return CNWSCreature__GetRangeWeaponEquipped(this);
}

int32_t CNWSCreature::GetRelativeWeaponSize(CNWSItem* a0)
{
    return CNWSCreature__GetRelativeWeaponSize(this, a0);
}

float CNWSCreature::GetRunRate()
{
    return CNWSCreature__GetRunRate(this);
}

int32_t CNWSCreature::GetSpellOrHealActionQueued()
{
    return CNWSCreature__GetSpellOrHealActionQueued(this);
}

float CNWSCreature::GetSpotCheckDistance()
{
    return CNWSCreature__GetSpotCheckDistance(this);
}

int32_t CNWSCreature::GetStandardFactionReputation(int32_t a0)
{
    return CNWSCreature__GetStandardFactionReputation(this, a0);
}

int32_t CNWSCreature::GetTileExplored(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__GetTileExplored(this, a0, a1, a2);
}

int32_t CNWSCreature::GetTotalEffectBonus(unsigned char a0, CNWSObject* a1, int32_t a2, int32_t a3, unsigned char a4, unsigned char a5, unsigned char a6, unsigned char a7, int32_t a8)
{
    return CNWSCreature__GetTotalEffectBonus(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSCreature::GetTurnResistanceHD()
{
    return CNWSCreature__GetTurnResistanceHD(this);
}

int32_t CNWSCreature::GetUnarmed()
{
    return CNWSCreature__GetUnarmed(this);
}

int32_t CNWSCreature::GetUseMonkAbilities()
{
    return CNWSCreature__GetUseMonkAbilities(this);
}

int32_t CNWSCreature::GetUseRange(uint32_t a0, Vector& a1, float& a2)
{
    return CNWSCreature__GetUseRange(this, a0, a1, a2);
}

CNWVisibilityNode* CNWSCreature::GetVisibleListElement(uint32_t a0)
{
    return CNWSCreature__GetVisibleListElement(this, a0);
}

float CNWSCreature::GetWalkRate()
{
    return CNWSCreature__GetWalkRate(this);
}

int32_t CNWSCreature::GetWeaponPower(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__GetWeaponPower(this, a0, a1);
}

int32_t CNWSCreature::HandleSubAreaStateChanges(CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1, int32_t a2)
{
    return CNWSCreature__HandleSubAreaStateChanges(this, a0, a1, a2);
}

void CNWSCreature::InitialisePVPList()
{
    return CNWSCreature__InitialisePVPList(this);
}

void CNWSCreature::InitializeQuickbar()
{
    return CNWSCreature__InitializeQuickbar(this);
}

int32_t CNWSCreature::LearnScroll(uint32_t a0)
{
    return CNWSCreature__LearnScroll(this, a0);
}

void CNWSCreature::LoadAssociateList(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__LoadAssociateList(this, a0, a1);
}

void CNWSCreature::LoadAutoMapData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__LoadAutoMapData(this, a0, a1);
}

int32_t CNWSCreature::LoadCreature(CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSCreature__LoadCreature(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature::LoadFromTemplate(CResRef a0, CExoString* a1)
{
    return CNWSCreature__LoadFromTemplate(this, a0, a1);
}

void CNWSCreature::LoadPersonalReputationList(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__LoadPersonalReputationList(this, a0, a1);
}

int32_t CNWSCreature::LoadPolymorphData(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSCreature__LoadPolymorphData(this, a0, a1, a2);
}

void CNWSCreature::LoadQuickBarHack(CExoString a0)
{
    return CNWSCreature__LoadQuickBarHack(this, a0);
}

void CNWSCreature::LoadQuickButtons(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__LoadQuickButtons(this, a0, a1);
}

float CNWSCreature::MaxAttackRange(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__MaxAttackRange(this, a0, a1, a2);
}

void CNWSCreature::MergeItem(CNWSItem* a0, CNWSItem* a1)
{
    return CNWSCreature__MergeItem(this, a0, a1);
}

void CNWSCreature::NotifyAssociateActionToggle(int32_t a0)
{
    return CNWSCreature__NotifyAssociateActionToggle(this, a0);
}

void CNWSCreature::PacifyCreature()
{
    return CNWSCreature__PacifyCreature__0(this);
}

void CNWSCreature::PacifyCreature(uint32_t a0)
{
    return CNWSCreature__PacifyCreature__1(this, a0);
}

void CNWSCreature::PayToIdentifyItem(uint32_t a0, uint32_t a1)
{
    return CNWSCreature__PayToIdentifyItem(this, a0, a1);
}

int32_t CNWSCreature::Polymorph(int32_t a0, CGameEffect* a1, int32_t a2)
{
    return CNWSCreature__Polymorph(this, a0, a1, a2);
}

void CNWSCreature::PossessCreature(uint32_t a0)
{
    return CNWSCreature__PossessCreature(this, a0);
}

void CNWSCreature::PossessCreatureDM(uint32_t a0, unsigned char a1)
{
    return CNWSCreature__PossessCreatureDM(this, a0, a1);
}

void CNWSCreature::PossessFamiliar()
{
    return CNWSCreature__PossessFamiliar(this);
}

void CNWSCreature::PostProcess()
{
    return CNWSCreature__PostProcess(this);
}

void CNWSCreature::ProcessMasterDeathForAssociates()
{
    return CNWSCreature__ProcessMasterDeathForAssociates(this);
}

void CNWSCreature::ProcessPendingCombatActions()
{
    return CNWSCreature__ProcessPendingCombatActions(this);
}

void CNWSCreature::QuickbarButton_RemoveItem(uint32_t a0)
{
    return CNWSCreature__QuickbarButton_RemoveItem(this, a0);
}

void CNWSCreature::QuickbarButton_RemoveSpell(uint32_t a0)
{
    return CNWSCreature__QuickbarButton_RemoveSpell(this, a0);
}

void CNWSCreature::ReadItemsFromGff(CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__ReadItemsFromGff(this, a0, a1, a2, a3);
}

void CNWSCreature::ReadScriptsFromGff(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__ReadScriptsFromGff(this, a0, a1);
}

void CNWSCreature::RealizeAssociateList()
{
    return CNWSCreature__RealizeAssociateList(this);
}

void CNWSCreature::ReceiveAssociateCommand(int32_t a0)
{
    return CNWSCreature__ReceiveAssociateCommand(this, a0);
}

void CNWSCreature::RecomputeAmbientAnimationState()
{
    return CNWSCreature__RecomputeAmbientAnimationState(this);
}

void CNWSCreature::ReconcileAutoMapData()
{
    return CNWSCreature__ReconcileAutoMapData(this);
}

void CNWSCreature::RelayQuickChatCommandToAssociates(uint16_t a0)
{
    return CNWSCreature__RelayQuickChatCommandToAssociates(this, a0);
}

void CNWSCreature::RemoveAllAssociates()
{
    return CNWSCreature__RemoveAllAssociates(this);
}

void CNWSCreature::RemoveAssociate(uint32_t a0)
{
    return CNWSCreature__RemoveAssociate(this, a0);
}

void CNWSCreature::RemoveBadEffects()
{
    return CNWSCreature__RemoveBadEffects(this);
}

int32_t CNWSCreature::RemoveCharmEffectsByFactionID(int32_t a0, int32_t a1)
{
    return CNWSCreature__RemoveCharmEffectsByFactionID(this, a0, a1);
}

int32_t CNWSCreature::RemoveCharmEffectsByOBJECTID(uint32_t a0, int32_t a1)
{
    return CNWSCreature__RemoveCharmEffectsByOBJECTID(this, a0, a1);
}

void CNWSCreature::RemoveCombatInvisibilityEffects()
{
    return CNWSCreature__RemoveCombatInvisibilityEffects(this);
}

void CNWSCreature::RemoveCounterspeller(uint32_t a0)
{
    return CNWSCreature__RemoveCounterspeller(this, a0);
}

void CNWSCreature::RemoveDomination()
{
    return CNWSCreature__RemoveDomination(this);
}

void CNWSCreature::RemoveDominationEffect()
{
    return CNWSCreature__RemoveDominationEffect(this);
}

void CNWSCreature::RemoveFromArea(int32_t a0)
{
    return CNWSCreature__RemoveFromArea(this, a0);
}

void CNWSCreature::RemoveFromAssociateList(uint32_t a0)
{
    return CNWSCreature__RemoveFromAssociateList(this, a0);
}

void CNWSCreature::RemoveFromInvitationsOffered(uint32_t a0)
{
    return CNWSCreature__RemoveFromInvitationsOffered(this, a0);
}

void CNWSCreature::RemoveFromPVPList(uint32_t a0)
{
    return CNWSCreature__RemoveFromPVPList(this, a0);
}

void CNWSCreature::RemoveFromVisibleList(uint32_t a0)
{
    return CNWSCreature__RemoveFromVisibleList(this, a0);
}

void CNWSCreature::RemoveGold(int32_t a0, int32_t a1)
{
    return CNWSCreature__RemoveGold(this, a0, a1);
}

int32_t CNWSCreature::RemoveItem(CNWSItem* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CNWSCreature__RemoveItem(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature::RemoveItemFromRepository(CNWSItem* a0, int32_t a1)
{
    return CNWSCreature__RemoveItemFromRepository(this, a0, a1);
}

CNWSCreRestorePolymorphData* CNWSCreature::RemovePolymorphFromOutputCreature()
{
    return CNWSCreature__RemovePolymorphFromOutputCreature(this);
}

void CNWSCreature::RemoveSleepEffects()
{
    return CNWSCreature__RemoveSleepEffects(this);
}

void CNWSCreature::RemoveSpellActionFromRound()
{
    return CNWSCreature__RemoveSpellActionFromRound(this);
}

void CNWSCreature::RemoveWoundingEffects()
{
    return CNWSCreature__RemoveWoundingEffects(this);
}

int32_t CNWSCreature::ReplyToInvitation(int32_t a0, uint32_t a1)
{
    return CNWSCreature__ReplyToInvitation(this, a0, a1);
}

void CNWSCreature::ReprocessAssociateList()
{
    return CNWSCreature__ReprocessAssociateList(this);
}

int32_t CNWSCreature::RequestBuy(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNWSCreature__RequestBuy(this, a0, a1, a2);
}

int32_t CNWSCreature::RequestSell(uint32_t a0, uint32_t a1)
{
    return CNWSCreature__RequestSell(this, a0, a1);
}

void CNWSCreature::ResetItemPossessor()
{
    return CNWSCreature__ResetItemPossessor(this);
}

void CNWSCreature::ResetPCDominatedScripts()
{
    return CNWSCreature__ResetPCDominatedScripts(this);
}

void CNWSCreature::ResetUpdateTimes(uint32_t a0, uint32_t a1)
{
    return CNWSCreature__ResetUpdateTimes(this, a0, a1);
}

void CNWSCreature::ResolveAmmunition(uint32_t a0)
{
    return CNWSCreature__ResolveAmmunition(this, a0);
}

void CNWSCreature::ResolveAttack(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__ResolveAttack(this, a0, a1, a2);
}

void CNWSCreature::ResolveAttackRoll(CNWSObject* a0)
{
    return CNWSCreature__ResolveAttackRoll(this, a0);
}

void CNWSCreature::ResolveCachedSpecialAttacks()
{
    return CNWSCreature__ResolveCachedSpecialAttacks(this);
}

void CNWSCreature::ResolveDamage(CNWSObject* a0)
{
    return CNWSCreature__ResolveDamage(this, a0);
}

void CNWSCreature::ResolveDamageShields(CNWSCreature* a0)
{
    return CNWSCreature__ResolveDamageShields(this, a0);
}

void CNWSCreature::ResolveDeathAttack(CNWSCreature* a0)
{
    return CNWSCreature__ResolveDeathAttack(this, a0);
}

int32_t CNWSCreature::ResolveDefensiveEffects(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ResolveDefensiveEffects(this, a0, a1);
}

void CNWSCreature::ResolveElementalDamage(CNWSObject* a0)
{
    return CNWSCreature__ResolveElementalDamage(this, a0);
}

void CNWSCreature::ResolveInitiative()
{
    return CNWSCreature__ResolveInitiative(this);
}

void CNWSCreature::ResolveItemCastSpell(CNWSObject* a0)
{
    return CNWSCreature__ResolveItemCastSpell(this, a0);
}

void CNWSCreature::ResolveMeleeAnimations(int32_t a0, int32_t a1, CNWSObject* a2, int32_t a3)
{
    return CNWSCreature__ResolveMeleeAnimations(this, a0, a1, a2, a3);
}

void CNWSCreature::ResolveMeleeAttack(CNWSObject* a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__ResolveMeleeAttack(this, a0, a1, a2);
}

void CNWSCreature::ResolveMeleeSpecialAttack(int32_t a0, int32_t a1, CNWSObject* a2, int32_t a3)
{
    return CNWSCreature__ResolveMeleeSpecialAttack(this, a0, a1, a2, a3);
}

void CNWSCreature::ResolveOnHitEffect(CNWSObject* a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__ResolveOnHitEffect(this, a0, a1, a2);
}

void CNWSCreature::ResolveOnHitVisuals(CNWSObject* a0)
{
    return CNWSCreature__ResolveOnHitVisuals(this, a0);
}

void CNWSCreature::ResolvePostMeleeDamage(CNWSObject* a0)
{
    return CNWSCreature__ResolvePostMeleeDamage(this, a0);
}

void CNWSCreature::ResolvePostRangedDamage(CNWSObject* a0)
{
    return CNWSCreature__ResolvePostRangedDamage(this, a0);
}

void CNWSCreature::ResolveRangedAnimations(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ResolveRangedAnimations(this, a0, a1);
}

void CNWSCreature::ResolveRangedAttack(CNWSObject* a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__ResolveRangedAttack(this, a0, a1, a2);
}

void CNWSCreature::ResolveRangedMiss(CNWSObject* a0)
{
    return CNWSCreature__ResolveRangedMiss(this, a0);
}

void CNWSCreature::ResolveRangedSpecialAttack(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__ResolveRangedSpecialAttack(this, a0, a1);
}

void CNWSCreature::ResolveSafeProjectile(uint32_t a0, int32_t a1)
{
    return CNWSCreature__ResolveSafeProjectile(this, a0, a1);
}

void CNWSCreature::ResolveSituationalModifiers(CNWSObject* a0)
{
    return CNWSCreature__ResolveSituationalModifiers(this, a0);
}

void CNWSCreature::ResolveSneakAttack(CNWSCreature* a0)
{
    return CNWSCreature__ResolveSneakAttack(this, a0);
}

void CNWSCreature::Rest(int32_t a0, int32_t a1)
{
    return CNWSCreature__Rest(this, a0, a1);
}

void CNWSCreature::RestoreCutsceneVars()
{
    return CNWSCreature__RestoreCutsceneVars(this);
}

void CNWSCreature::RestoreItemProperties()
{
    return CNWSCreature__RestoreItemProperties(this);
}

void CNWSCreature::RestoreItemPropertiesInRepository(CItemRepository* a0)
{
    return CNWSCreature__RestoreItemPropertiesInRepository(this, a0);
}

void CNWSCreature::RestorePolymorphToOutputCreature(CNWSCreRestorePolymorphData* a0)
{
    return CNWSCreature__RestorePolymorphToOutputCreature(this, a0);
}

int32_t CNWSCreature::RunEquip(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNWSCreature__RunEquip(this, a0, a1, a2);
}

int32_t CNWSCreature::RunUnequip(uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4, uint32_t a5)
{
    return CNWSCreature__RunUnequip(this, a0, a1, a2, a3, a4, a5);
}

void CNWSCreature::SaveAssociateList(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSCreature__SaveAssociateList(this, a0, a1, a2);
}

void CNWSCreature::SaveAutoMapData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__SaveAutoMapData(this, a0, a1);
}

int32_t CNWSCreature::SaveCreature(CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSCreature__SaveCreature(this, a0, a1, a2, a3, a4, a5);
}

void CNWSCreature::SavePersonalReputationList(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__SavePersonalReputationList(this, a0, a1);
}

void CNWSCreature::SaveQuickBarHack(CExoString a0)
{
    return CNWSCreature__SaveQuickBarHack(this, a0);
}

void CNWSCreature::SaveQuickButtons(CResGFF* a0, CResStruct* a1)
{
    return CNWSCreature__SaveQuickButtons(this, a0, a1);
}

unsigned char CNWSCreature::SavingThrowRoll(unsigned char a0, uint16_t a1, unsigned char a2, uint32_t a3, int32_t a4, uint16_t a5, int32_t a6)
{
    return CNWSCreature__SavingThrowRoll(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature::SawTrapInformAssociates(uint32_t a0)
{
    return CNWSCreature__SawTrapInformAssociates(this, a0);
}

void CNWSCreature::SendFeedbackMessage(uint16_t a0, CNWCCMessageData* a1, CNWSPlayer* a2)
{
    return CNWSCreature__SendFeedbackMessage(this, a0, a1, a2);
}

void CNWSCreature::SendFeedbackString(CExoString a0, CNWSPlayer* a1)
{
    return CNWSCreature__SendFeedbackString(this, a0, a1);
}

void CNWSCreature::SetActivity(int32_t a0, int32_t a1)
{
    return CNWSCreature__SetActivity(this, a0, a1);
}

void CNWSCreature::SetAllTilesExplored(uint32_t a0, int32_t a1)
{
    return CNWSCreature__SetAllTilesExplored(this, a0, a1);
}

void CNWSCreature::SetAnimation(int32_t a0)
{
    return CNWSCreature__SetAnimation(this, a0);
}

void CNWSCreature::SetAssociateListenPatterns()
{
    return CNWSCreature__SetAssociateListenPatterns(this);
}

void CNWSCreature::SetAssociatesToForgetAggression(uint32_t a0)
{
    return CNWSCreature__SetAssociatesToForgetAggression(this, a0);
}

void CNWSCreature::SetAssociateType(uint16_t a0)
{
    return CNWSCreature__SetAssociateType(this, a0);
}

void CNWSCreature::SetAutoMapData(int32_t a0, uint32_t* a1, unsigned char** a2)
{
    return CNWSCreature__SetAutoMapData(this, a0, a1, a2);
}

void CNWSCreature::SetBroadcastedAOOTo(int32_t a0)
{
    return CNWSCreature__SetBroadcastedAOOTo(this, a0);
}

void CNWSCreature::SetCombatMode(unsigned char a0, int32_t a1)
{
    return CNWSCreature__SetCombatMode(this, a0, a1);
}

void CNWSCreature::SetCombatState(int32_t a0)
{
    return CNWSCreature__SetCombatState(this, a0);
}

void CNWSCreature::SetDefensiveCastingMode(unsigned char a0)
{
    return CNWSCreature__SetDefensiveCastingMode(this, a0);
}

void CNWSCreature::SetDetectMode(unsigned char a0)
{
    return CNWSCreature__SetDetectMode(this, a0);
}

void CNWSCreature::SetEffectSpellId(uint32_t a0)
{
    return CNWSCreature__SetEffectSpellId(this, a0);
}

void CNWSCreature::SetExcitedState(unsigned char a0)
{
    return CNWSCreature__SetExcitedState(this, a0);
}

void CNWSCreature::SetGold(int32_t a0)
{
    return CNWSCreature__SetGold(this, a0);
}

void CNWSCreature::SetId(uint32_t a0)
{
    return CNWSCreature__SetId(this, a0);
}

void CNWSCreature::SetInTransit(int32_t a0)
{
    return CNWSCreature__SetInTransit(this, a0);
}

void CNWSCreature::SetInvitedToParty(int32_t a0)
{
    return CNWSCreature__SetInvitedToParty(this, a0);
}

void CNWSCreature::SetLockOrientationToObject(uint32_t a0)
{
    return CNWSCreature__SetLockOrientationToObject(this, a0);
}

void CNWSCreature::SetMode(unsigned char a0, int32_t a1)
{
    return CNWSCreature__SetMode(this, a0, a1);
}

void CNWSCreature::SetMovementRateFactor(float a0)
{
    return CNWSCreature__SetMovementRateFactor(this, a0);
}

void CNWSCreature::SetPCDominatedScripts()
{
    return CNWSCreature__SetPCDominatedScripts(this);
}

void CNWSCreature::SetPortrait(CResRef a0)
{
    return CNWSCreature__SetPortrait(this, a0);
}

void CNWSCreature::SetPortraitId(uint16_t a0)
{
    return CNWSCreature__SetPortraitId(this, a0);
}

void CNWSCreature::SetPVPPlayerLikesMe(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSCreature__SetPVPPlayerLikesMe(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_AssociateCommand(unsigned char a0, int32_t a1, uint16_t a2, uint32_t a3)
{
    return CNWSCreature__SetQuickbarButton_AssociateCommand(this, a0, a1, a2, a3);
}

void CNWSCreature::SetQuickbarButton_CommandLine(unsigned char a0, const CExoString& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_CommandLine(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DM_General_ResRefParam(unsigned char a0, unsigned char a1, const CResRef& a2)
{
    return CNWSCreature__SetQuickbarButton_DM_General_ResRefParam(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateCreature(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateEncounter(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateItem(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePlaceable(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePortal(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateTrigger(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateWaypoint(unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    return CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_GeneralINTParam(unsigned char a0, unsigned char a1, int32_t a2)
{
    return CNWSCreature__SetQuickbarButton_GeneralINTParam(this, a0, a1, a2);
}

void CNWSCreature::SetQuickbarButton_GeneralNoParam(unsigned char a0, unsigned char a1)
{
    return CNWSCreature__SetQuickbarButton_GeneralNoParam(this, a0, a1);
}

void CNWSCreature::SetQuickbarButton_Item(unsigned char a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    return CNWSCreature__SetQuickbarButton_Item(this, a0, a1, a2, a3);
}

void CNWSCreature::SetQuickbarButton_Spell(unsigned char a0, unsigned char a1, uint32_t a2, unsigned char a3, unsigned char a4)
{
    return CNWSCreature__SetQuickbarButton_Spell(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::SetQuickbarButton_SpellLikeAbility(unsigned char a0, uint32_t a1, unsigned char a2)
{
    return CNWSCreature__SetQuickbarButton_SpellLikeAbility(this, a0, a1, a2);
}

void CNWSCreature::SetStandardFactionReputation(int32_t a0, int32_t a1)
{
    return CNWSCreature__SetStandardFactionReputation(this, a0, a1);
}

void CNWSCreature::SetStealthMode(unsigned char a0)
{
    return CNWSCreature__SetStealthMode(this, a0);
}

void CNWSCreature::SetTileExplored(uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSCreature__SetTileExplored(this, a0, a1, a2, a3);
}

void CNWSCreature::SignalMeleeDamage(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__SignalMeleeDamage(this, a0, a1);
}

void CNWSCreature::SignalRangedDamage(CNWSObject* a0, int32_t a1)
{
    return CNWSCreature__SignalRangedDamage(this, a0, a1);
}

void CNWSCreature::SpawnInHeartbeatPerception(int32_t a0)
{
    return CNWSCreature__SpawnInHeartbeatPerception(this, a0);
}

void CNWSCreature::SplitItem(CNWSItem* a0, int32_t a1)
{
    return CNWSCreature__SplitItem(this, a0, a1);
}

int32_t CNWSCreature::StartBarter(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSCreature__StartBarter(this, a0, a1, a2);
}

void CNWSCreature::StartGuiTimingBar(uint32_t a0, unsigned char a1)
{
    return CNWSCreature__StartGuiTimingBar(this, a0, a1);
}

void CNWSCreature::StopGuiTimingBar()
{
    return CNWSCreature__StopGuiTimingBar(this);
}

void CNWSCreature::StoreCutsceneVars()
{
    return CNWSCreature__StoreCutsceneVars(this);
}

void CNWSCreature::SummonAnimalCompanion()
{
    return CNWSCreature__SummonAnimalCompanion(this);
}

void CNWSCreature::SummonAssociate(CResRef a0, CExoString a1, uint16_t a2)
{
    return CNWSCreature__SummonAssociate(this, a0, a1, a2);
}

void CNWSCreature::SummonFamiliar()
{
    return CNWSCreature__SummonFamiliar(this);
}

void CNWSCreature::TerminateClientSidePath(int32_t a0)
{
    return CNWSCreature__TerminateClientSidePath(this, a0);
}

int32_t CNWSCreature::TestAIStateAsMode(int32_t a0)
{
    return CNWSCreature__TestAIStateAsMode(this, a0);
}

int32_t CNWSCreature::ToggleMode(unsigned char a0)
{
    return CNWSCreature__ToggleMode(this, a0);
}

int32_t CNWSCreature::TransferGold(uint32_t a0, Vector a1, uint32_t a2, int32_t a3, unsigned char a4, unsigned char a5)
{
    return CNWSCreature__TransferGold(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature::TranslateAddress(uint32_t a0, int32_t a1, int32_t a2, int32_t* a3, int32_t* a4)
{
    return CNWSCreature__TranslateAddress(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature::UnequipItem(CNWSItem* a0, int32_t a1)
{
    return CNWSCreature__UnequipItem(this, a0, a1);
}

int32_t CNWSCreature::UnPolymorph(CGameEffect* a0)
{
    return CNWSCreature__UnPolymorph(this, a0);
}

void CNWSCreature::UnpossessCreature()
{
    return CNWSCreature__UnpossessCreature(this);
}

void CNWSCreature::UnpossessCreatureDM()
{
    return CNWSCreature__UnpossessCreatureDM(this);
}

void CNWSCreature::UnpossessFamiliar()
{
    return CNWSCreature__UnpossessFamiliar(this);
}

void CNWSCreature::UnsummonMyself()
{
    return CNWSCreature__UnsummonMyself(this);
}

void CNWSCreature::UpdateActionQueue()
{
    return CNWSCreature__UpdateActionQueue(this);
}

void CNWSCreature::UpdateAppearanceDependantInfo()
{
    return CNWSCreature__UpdateAppearanceDependantInfo(this);
}

void CNWSCreature::UpdateAppearanceForEquippedItems()
{
    return CNWSCreature__UpdateAppearanceForEquippedItems(this);
}

void CNWSCreature::UpdateAttributesOnEffect(CGameEffect* a0, int32_t a1)
{
    return CNWSCreature__UpdateAttributesOnEffect(this, a0, a1);
}

void CNWSCreature::UpdateAutoMap(uint32_t a0)
{
    return CNWSCreature__UpdateAutoMap(this, a0);
}

void CNWSCreature::UpdateCombatRoundTimer()
{
    return CNWSCreature__UpdateCombatRoundTimer(this);
}

void CNWSCreature::UpdateEffectPtrs()
{
    return CNWSCreature__UpdateEffectPtrs(this);
}

void CNWSCreature::UpdateEncumbranceState(int32_t a0)
{
    return CNWSCreature__UpdateEncumbranceState(this, a0);
}

void CNWSCreature::UpdateExcitedStateTimer()
{
    return CNWSCreature__UpdateExcitedStateTimer(this);
}

void CNWSCreature::UpdatePersonalSpace()
{
    return CNWSCreature__UpdatePersonalSpace(this);
}

int32_t CNWSCreature::UpdateSpecialAttacks()
{
    return CNWSCreature__UpdateSpecialAttacks(this);
}

int32_t CNWSCreature::UpdateSubareasOnJumpPosition(Vector a0, uint32_t a1)
{
    return CNWSCreature__UpdateSubareasOnJumpPosition(this, a0, a1);
}

int32_t CNWSCreature::UpdateSubareasOnMoveTo(Vector a0, Vector a1, int32_t a2, CExoArrayListTemplatedunsignedlong* a3, int32_t a4)
{
    return CNWSCreature__UpdateSubareasOnMoveTo(this, a0, a1, a2, a3, a4);
}

void CNWSCreature::UpdateTrapCheck()
{
    return CNWSCreature__UpdateTrapCheck(this);
}

void CNWSCreature::UpdateTrapCheckDM()
{
    return CNWSCreature__UpdateTrapCheckDM(this);
}

void CNWSCreature::UpdateVisibleList()
{
    return CNWSCreature__UpdateVisibleList(this);
}

int32_t CNWSCreature::UseFeat(uint16_t a0, uint16_t a1, uint32_t a2, uint32_t a3, Vector* a4)
{
    return CNWSCreature__UseFeat(this, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature::UseItem(uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3, Vector a4, uint32_t a5)
{
    return CNWSCreature__UseItem(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature::UseLoreOnItem(uint32_t a0)
{
    return CNWSCreature__UseLoreOnItem(this, a0);
}

int32_t CNWSCreature::UseSkill(unsigned char a0, unsigned char a1, uint32_t a2, Vector a3, uint32_t a4, uint32_t a5, int32_t a6)
{
    return CNWSCreature__UseSkill(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature::ValidateCounterSpellData(uint32_t a0, unsigned char a1, unsigned char a2)
{
    return CNWSCreature__ValidateCounterSpellData(this, a0, a1, a2);
}

uint32_t CNWSCreature::WalkUpdateLocation()
{
    return CNWSCreature__WalkUpdateLocation(this);
}

int32_t CNWSCreature::WalkUpdateLocationDistance(float a0, Vector* a1, Vector* a2, CExoArrayListTemplatedunsignedlong* a3)
{
    return CNWSCreature__WalkUpdateLocationDistance(this, a0, a1, a2, a3);
}

int32_t CNWSCreature::WalkUpdateLocationTestDistance(Vector a0, Vector a1)
{
    return CNWSCreature__WalkUpdateLocationTestDistance(this, a0, a1);
}

void CNWSCreature__CNWSCreatureCtor(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CNWSCreatureCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CNWSCreature__CNWSCreatureDtor__0(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CNWSCreatureDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSCreature__AcquireItem(CNWSCreature* thisPtr, CNWSItem** a0, uint32_t a1, uint32_t a2, unsigned char a3, unsigned char a4, int32_t a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem**, uint32_t, uint32_t, unsigned char, unsigned char, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AcquireItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature__ActionManager(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ActionManager);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ActivityManager(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ActivityManager);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddAnimalEmpathyAction(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddAnimalEmpathyAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddAppearActions(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddAppearActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddAssociate(CNWSCreature* thisPtr, uint32_t a0, uint16_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddAssociate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__AddAttackActions(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddAttackActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__AddCastSpellActions(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, Vector a5, uint32_t a6, int32_t a7, int32_t a8, int32_t a9, unsigned char a10, int32_t a11, int32_t a12, int32_t a13, unsigned char a14)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t, int32_t, Vector, uint32_t, int32_t, int32_t, int32_t, unsigned char, int32_t, int32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddCastSpellActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}

int32_t CNWSCreature__AddCounterSpellActions(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddCounterSpellActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddDisappearActions(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddDisappearActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__AddDriveAction(CNWSCreature* thisPtr, uint16_t a0, const Vector& a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, const Vector&, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddDriveAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature__AddDropItemActions(CNWSCreature* thisPtr, uint32_t a0, Vector a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, Vector, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddDropItemActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__AddEquipItemActions(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t a1, int32_t a2, int32_t a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t, int32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddEquipItemActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__AddGold(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__AddHealActions(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddHealActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__AddItemCastSpellActions(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, Vector a3, uint32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, Vector, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddItemCastSpellActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature__AddMoveToPointAction(CNWSCreature* thisPtr, uint16_t a0, Vector a1, uint32_t a2, uint32_t a3, int32_t a4, float a5, float a6, int32_t a7, int32_t a8, int32_t a9, int32_t a10, int32_t a11, int32_t a12)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, Vector, uint32_t, uint32_t, int32_t, float, float, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddMoveToPointAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

int32_t CNWSCreature__AddMoveToPointActionToFront(CNWSCreature* thisPtr, uint16_t a0, Vector a1, uint32_t a2, uint32_t a3, int32_t a4, float a5, float a6, int32_t a7, int32_t a8, int32_t a9, int32_t a10, int32_t a11, int32_t a12)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, Vector, uint32_t, uint32_t, int32_t, float, float, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddMoveToPointActionToFront);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

int32_t CNWSCreature__AddPathfindingWaitActionToFront(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddPathfindingWaitActionToFront);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddPickPocketActions(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddPickPocketActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddPickUpItemActions(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddPickUpItemActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__AddRepositoryMoveActions(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddRepositoryMoveActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__AddSitActions(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddSitActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__AddTauntActions(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddTauntActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddToArea(CNWSCreature* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__AddToAssociateList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddToInvitationsIgnored(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToInvitationsIgnored);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddToInvitationsOffered(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToInvitationsOffered);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddToPersonalReputationList(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, float a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToPersonalReputationList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__AddToPVPList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToPVPList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AddToVisibleList(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddToVisibleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature__AddTrapActions(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1, uint32_t a2, Vector a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char, uint32_t, Vector, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddTrapActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature__AddUnequipActions(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4, int32_t a5, uint32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t, unsigned char, unsigned char, int32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddUnequipActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSCreature__AddUseTalentAtLocationActions(CNWSCreature* thisPtr, int32_t a0, int32_t a1, Vector a2, unsigned char a3, uint32_t a4, int32_t a5, unsigned char a6, unsigned char a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t, Vector, unsigned char, uint32_t, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddUseTalentAtLocationActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSCreature__AddUseTalentOnObjectActions(CNWSCreature* thisPtr, int32_t a0, int32_t a1, uint32_t a2, unsigned char a3, uint32_t a4, int32_t a5, unsigned char a6, unsigned char a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t, uint32_t, unsigned char, uint32_t, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AddUseTalentOnObjectActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNWSCreature__AdjustReputation(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AdjustReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSCreature__AIActionAnimalEmpathy(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionAnimalEmpathy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionAppear(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionAreaWait(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionAreaWait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionAttackObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionAttackObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionBarter(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCastSpell(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionChangeFacingObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionChangeFacingObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionChangeFacingPoint(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionChangeFacingPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckForceFollowObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckForceFollowObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckInterAreaPathfinding(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckInterAreaPathfinding);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveAwayFromLocation(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveAwayFromLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveAwayFromObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveAwayFromObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveToObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveToObjectRadius(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveToObjectRadius);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveToPoint(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCheckMoveToPointRadius(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCheckMoveToPointRadius);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionCounterSpell(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionCounterSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionDisappear(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionDisappear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionDisarmTrap(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionDisarmTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionDrive(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionDrive);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionDropItem(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionDropItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionEncounterCreatureDestroySelf(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionEncounterCreatureDestroySelf);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__AIActionEquipItem(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionEquipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionExamine(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionExamine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionExamineTrap(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionExamineTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionFlagTrap(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionFlagTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionForceFollowObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionForceFollowObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionHeal(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionHeal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionItemCastSpell(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionItemCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionJumpToObject(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionJumpToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionJumpToPoint(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionJumpToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionMoveToPoint(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionMoveToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionOrientCamera(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionOrientCamera);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionPickPocket(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionPickPocket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionPickUpItem(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionPickUpItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionRandomWalk(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionRandomWalk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionRecoverTrap(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionRecoverTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionRepositoryMove(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionRepositoryMove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionRest(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionRest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionSetTrap(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionSetTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionSit(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionSit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionTaunt(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionTaunt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionUnequipItem(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionUnequipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__AIActionWaitForEndOfRound(CNWSCreature* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIActionWaitForEndOfRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__AIUpdate(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ApplyDeathExperience(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyDeathExperience);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__ApplyDiseasePayload(CNWSCreature* thisPtr, CGameEffect* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CGameEffect*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyDiseasePayload);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ApplyOnHitAbilityDamage(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitAbilityDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitBlindness(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitBlindness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitCastSpell(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1, CNWSItem* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ApplyOnHitConfusion(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitConfusion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDaze(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDaze);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDeafness(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDeafness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDeathAttack(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDeathAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDisease(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDisease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDispelMagic__0(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDispelMagic__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDispelMagic__1(CNWSCreature* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDispelMagic__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDominate(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDominate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitDoom(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitDoom);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitFear(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitFear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitGreaterDispel(CNWSCreature* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitGreaterDispel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitHold(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitHold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitKnock(CNWSCreature* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitKnock);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitLesserDispel(CNWSCreature* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitLesserDispel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitLevelDrain(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitLevelDrain);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitMordysDisjunction(CNWSCreature* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitMordysDisjunction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitPoison(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitPoison);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSilence(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSilence);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSlayAlignment(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSlayAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSlayAlignmentGroup(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSlayAlignmentGroup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSlayRacialGroup(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSlayRacialGroup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSleep(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSleep);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitSlow(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitSlow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitStun(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitStun);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitVampiricRegeneration(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitVampiricRegeneration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitVorpal(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitVorpal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ApplyOnHitWounding(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyOnHitWounding);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__ApplyPoisonPayload(CNWSCreature* thisPtr, CGameEffect* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CGameEffect*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyPoisonPayload);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__ApplyWounding(CNWSCreature* thisPtr, CGameEffect* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ApplyWounding);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSCreature* CNWSCreature__AsNWSCreature(CNWSCreature* thisPtr)
{
    using FuncPtrType = CNWSCreature*(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AsNWSCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__AutoCloseGUIPanels(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__AutoCloseGUIPanels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BringAssociatesToNewFaction(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BringAssociatesToNewFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastAssociateCommand(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastAssociateCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastAttackDataToParty(CNWSCreature* thisPtr, CNWCCMessageData* a0, CNWSCombatAttackData* a1, CNWSCreature* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*, CNWSCombatAttackData*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastAttackDataToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__BroadcastAttackOfOpportunity(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastAttackOfOpportunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__BroadcastBattleCry(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastBattleCry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__BroadcastCombatStateToParty(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastCombatStateToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__BroadcastDamageDataToParty(CNWSCreature* thisPtr, CNWCCMessageData* a0, CNWSCreature* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastDamageDataToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__BroadcastDeathDataToParty(CNWSCreature* thisPtr, CNWCCMessageData* a0, CNWSCreature* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastDeathDataToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__BroadcastFloatyData(CNWSCreature* thisPtr, CNWCCMessageData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastFloatyData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastSavingThrowData(CNWSCreature* thisPtr, CNWCCMessageData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastSavingThrowData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastSkillData(CNWSCreature* thisPtr, CNWCCMessageData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastSkillData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastSpellCast(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1, uint16_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastSpellCast);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__BroadcastVoiceChat(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastVoiceChat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__BroadcastWhirlwindAttack(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BroadcastWhirlwindAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__BumpFriends(CNWSCreature* thisPtr, CNWSCreature* a0, const Vector& a1, const Vector& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*, const Vector&, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__BumpFriends);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreature__CalculateDamagePower(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculateDamagePower);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CNWSCreature__CalculateDeathExperience(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculateDeathExperience);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CalculateMaxElementalDamage(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculateMaxElementalDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CalculatePersonalReputationAdjustment(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculatePersonalReputationAdjustment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreature__CalculateProjectileTimeToTarget(CNWSCreature* thisPtr, Vector a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, Vector, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculateProjectileTimeToTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CalculateSpellSaveDC(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CalculateSpellSaveDC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__CancelAction(CNWSCreature* thisPtr, uint16_t a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CancelAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__CancelGoldTransfer(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CancelGoldTransfer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CancelRest(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CancelRest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreature__CanEquipItem(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3, int32_t a4, CNWSPlayer* a5)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t*, int32_t, int32_t, int32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanEquipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

unsigned char CNWSCreature__CanEquipMiscellaneous(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanEquipMiscellaneous);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

unsigned char CNWSCreature__CanEquipShield(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanEquipShield);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSCreature__CanEquipWeapon(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t* a1, int32_t a2, int32_t a3, CNWSPlayer* a4)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t*, int32_t, int32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanEquipWeapon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

unsigned char CNWSCreature__CanUnEquipWeapon(CNWSCreature* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanUnEquipWeapon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__CanUseItem(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CanUseItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__CheckInventoryForPlotItems(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckInventoryForPlotItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__CheckItemAlignmentRestrictions(CNWSCreature* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckItemAlignmentRestrictions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__CheckItemClassRestrictions(CNWSCreature* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckItemClassRestrictions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__CheckItemRaceRestrictions(CNWSCreature* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckItemRaceRestrictions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CheckMasterIsValid(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckMasterIsValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CheckProficiencies(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckProficiencies);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CheckUseMagicDeviceSkill(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckUseMagicDeviceSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__CheckVisibleList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CheckVisibleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CleanInvitationLists(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CleanInvitationLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CleanOutPersonalReputationList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CleanOutPersonalReputationList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__ClearAction(CNWSCreature* thisPtr, CNWSObjectActionNode* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObjectActionNode*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ClearActivities(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearActivities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ClearAutoMapData(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ClearHostileActionsVersus(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearHostileActionsVersus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ClearPersonalReputation(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearPersonalReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ClearVisibleList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ClearVisibleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ComputeAIState(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ComputeAIStateOnAction(CNWSCreature* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeAIStateOnAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ComputeArmourClass(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeArmourClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ComputeModifiedMovementRate(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeModifiedMovementRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSCreature__ComputeSpellRange(CNWSCreature* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeSpellRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__ComputeTotalEquippedWeight(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeTotalEquippedWeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSCreature__ComputeTotalWalkDistance(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeTotalWalkDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__ComputeTotalWeightCarried(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ComputeTotalWeightCarried);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ConvertModeToggleQuickButton(CNWSCreature* thisPtr, CNWSQuickbarButton* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSQuickbarButton*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ConvertModeToggleQuickButton);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CopyQuickButtonsFromDM(CNWSCreature* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CopyQuickButtonsFromDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__CreateDefaultQuickButtons(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CreateDefaultQuickButtons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__CreateDefaultQuickButtons_AddFeat(CNWSCreature* thisPtr, unsigned char& a0, uint16_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char&, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CreateDefaultQuickButtons_AddFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__CreateDefaultQuickButtons_CheckItem(CNWSCreature* thisPtr, CNWSItem* a0, uint32_t& a1, uint32_t& a2, uint32_t& a3, uint32_t& a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CreateDefaultQuickButtons_CheckItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__CreateDefaultQuickButtonsDM(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CreateDefaultQuickButtonsDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__CutWaypointPath(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__CutWaypointPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__DecrementSpellReadyCount(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DecrementSpellReadyCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

float CNWSCreature__DesiredAttackRange(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DesiredAttackRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__DestroyEquippedItems(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DestroyEquippedItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__DisplayFloatyDataToSelf(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DisplayFloatyDataToSelf);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__DMClearScripts(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DMClearScripts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__DMResetClearedScripts(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DMResetClearedScripts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__DoCombatStep(CNWSCreature* thisPtr, unsigned char a0, int32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoCombatStep);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__DoDamage(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__DoListenDetection(CNWSCreature* thisPtr, CNWSCreature* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoListenDetection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__DoPerceptionUpdateOnCreature(CNWSCreature* thisPtr, CNWSCreature* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoPerceptionUpdateOnCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__DoSpotDetection(CNWSCreature* thisPtr, CNWSCreature* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoSpotDetection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__DoStealthDetection(CNWSCreature* thisPtr, CNWSCreature* a0, int32_t a1, int32_t* a2, int32_t* a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*, int32_t, int32_t*, int32_t*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DoStealthDetection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSCreature__DriveUpdateLocation(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DriveUpdateLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__DumpToLog(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__DumpToLog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__EquipItem(CNWSCreature* thisPtr, uint32_t a0, CNWSItem* a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, CNWSItem*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EquipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__EquipMostDamagingAmmunition(CNWSCreature* thisPtr, uint32_t a0, CNWSItem* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EquipMostDamagingAmmunition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__EquipMostDamagingMeleeWeapon(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EquipMostDamagingMeleeWeapon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__EquipMostDamagingRangedWeapon(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EquipMostDamagingRangedWeapon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__EquipMostEffectiveArmor(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EquipMostEffectiveArmor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__EvaluateLock(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EvaluateLock);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__EventHandler(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__ExternalResolveAttack(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ExternalResolveAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__FailedOpenInformAssociates(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__FailedOpenInformAssociates);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__ForceMoveToPoint(CNWSCreature* thisPtr, CNWSForcedAction* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSForcedAction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ForceMoveToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetActivity(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetActivity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetAmmunitionAvailable(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetAmmunitionAvailable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int16_t CNWSCreature__GetArmorClass(CNWSCreature* thisPtr)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetArmorClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__GetAssociateId(CNWSCreature* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetAssociateId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__GetAttackResultHit(CNWSCreature* thisPtr, CNWSCombatAttackData* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCombatAttackData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetAttackResultHit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSBarter* CNWSCreature__GetBarterInfo(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSBarter*(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetBarterInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetBlind(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetBlind);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWSCreature__GetBodyBagAppearance(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetBodyBagAppearance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetCanSlayAlignment(CNWSCreature* thisPtr, CNWSObject* a0, CNWItemProperty* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetCanSlayAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__GetCreatureReputation(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetCreatureReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint16_t CNWSCreature__GetDamageFlags(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetDamageFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreature__GetDetectMode(CNWSCreature* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetDetectMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetDialogInterruptable(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetDialogInterruptable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSCreature__GetDialogResref(CNWSCreature* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetDialogResref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__GetDominatedCreatureId(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetDominatedCreatureId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__GetEffectSpellId(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSFaction* CNWSCreature__GetFaction(CNWSCreature* thisPtr)
{
    using FuncPtrType = CNWSFaction*(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoArrayListTemplatedCGameEffectPtr CNWSCreature__GetFilteredEffectList(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = CExoArrayListTemplatedCGameEffectPtr(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetFilteredEffectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLocString& CNWSCreature__GetFirstName(CNWSCreature* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetFlanked(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetFlanked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetFlatFooted(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetFlatFooted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSCreature__GetGender(CNWSCreature* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetGender);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetHasInvisbilityEffectApplied(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetHasInvisbilityEffectApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetHenchmanIndex(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetHenchmanIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetInvisible(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetInvisible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__GetIsAbleToPossessFamiliar(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsAbleToPossessFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetIsCreatureBumpable(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsCreatureBumpable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetIsInInvitationsIgnored(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsInInvitationsIgnored);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetIsInInvitationsOffered(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsInInvitationsOffered);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetIsInMelee(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsInMelee);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetIsInUseRange(CNWSCreature* thisPtr, uint32_t a0, float a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsInUseRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__GetIsPossessedFamiliar(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsPossessedFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetIsWeaponEffective(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetIsWeaponEffective);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSCreature__GetItemCount(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetItemCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSJournal* CNWSCreature__GetJournal(CNWSCreature* thisPtr)
{
    using FuncPtrType = CNWSJournal*(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetJournal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSCreature__GetLastName(CNWSCreature* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetLastName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSCreature__GetListenCheckDistance(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetListenCheckDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__GetLockOrientationToObject(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetLockOrientationToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int16_t CNWSCreature__GetMaxHitPoints(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetMaxHitPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetMode(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWSCreature__GetMovementRateFactor(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetMovementRateFactor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSCreature__GetNearestEnemy(CNWSCreature* thisPtr, float a0, uint32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*, float, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetNearestEnemy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__GetNumAssociatesOfType(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetNumAssociatesOfType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetNumCounterSpellingCreatures(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetNumCounterSpellingCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetNumInvited(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetNumInvited);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSCreature__GetPortrait(CNWSCreature* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetPortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetPVPPlayerLikesMe(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetPVPPlayerLikesMe);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetPVPReputation(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetPVPReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSQuickbarButton* CNWSCreature__GetQuickbarButton(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = CNWSQuickbarButton*(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetQuickbarButton);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetRangeWeaponEquipped(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetRangeWeaponEquipped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetRelativeWeaponSize(CNWSCreature* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetRelativeWeaponSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWSCreature__GetRunRate(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetRunRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetSpellOrHealActionQueued(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetSpellOrHealActionQueued);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSCreature__GetSpotCheckDistance(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetSpotCheckDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetStandardFactionReputation(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetStandardFactionReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__GetTileExplored(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetTileExplored);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__GetTotalEffectBonus(CNWSCreature* thisPtr, unsigned char a0, CNWSObject* a1, int32_t a2, int32_t a3, unsigned char a4, unsigned char a5, unsigned char a6, unsigned char a7, int32_t a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, CNWSObject*, int32_t, int32_t, unsigned char, unsigned char, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetTotalEffectBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSCreature__GetTurnResistanceHD(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetTurnResistanceHD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetUnarmed(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetUnarmed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetUseMonkAbilities(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetUseMonkAbilities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetUseRange(CNWSCreature* thisPtr, uint32_t a0, Vector& a1, float& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, Vector&, float&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetUseRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWVisibilityNode* CNWSCreature__GetVisibleListElement(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWVisibilityNode*(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetVisibleListElement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWSCreature__GetWalkRate(CNWSCreature* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetWalkRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__GetWeaponPower(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__GetWeaponPower);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__HandleSubAreaStateChanges(CNWSCreature* thisPtr, CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__HandleSubAreaStateChanges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__InitialisePVPList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__InitialisePVPList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__InitializeQuickbar(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__InitializeQuickbar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__LearnScroll(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LearnScroll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__LoadAssociateList(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__LoadAutoMapData(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__LoadCreature(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature__LoadFromTemplate(CNWSCreature* thisPtr, CResRef a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CResRef, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__LoadPersonalReputationList(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadPersonalReputationList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__LoadPolymorphData(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadPolymorphData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__LoadQuickBarHack(CNWSCreature* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadQuickBarHack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__LoadQuickButtons(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__LoadQuickButtons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CNWSCreature__MaxAttackRange(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__MaxAttackRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__MergeItem(CNWSCreature* thisPtr, CNWSItem* a0, CNWSItem* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__MergeItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__NotifyAssociateActionToggle(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__NotifyAssociateActionToggle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__PacifyCreature__0(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PacifyCreature__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__PacifyCreature__1(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PacifyCreature__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__PayToIdentifyItem(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PayToIdentifyItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__Polymorph(CNWSCreature* thisPtr, int32_t a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__Polymorph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__PossessCreature(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PossessCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__PossessCreatureDM(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PossessCreatureDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__PossessFamiliar(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PossessFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__PostProcess(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__PostProcess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ProcessMasterDeathForAssociates(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ProcessMasterDeathForAssociates);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ProcessPendingCombatActions(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ProcessPendingCombatActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__QuickbarButton_RemoveItem(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__QuickbarButton_RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__QuickbarButton_RemoveSpell(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__QuickbarButton_RemoveSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ReadItemsFromGff(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReadItemsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__ReadScriptsFromGff(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReadScriptsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__RealizeAssociateList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RealizeAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ReceiveAssociateCommand(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReceiveAssociateCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RecomputeAmbientAnimationState(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RecomputeAmbientAnimationState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ReconcileAutoMapData(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReconcileAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RelayQuickChatCommandToAssociates(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RelayQuickChatCommandToAssociates);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveAllAssociates(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveAllAssociates);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveAssociate(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveAssociate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveBadEffects(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveBadEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__RemoveCharmEffectsByFactionID(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveCharmEffectsByFactionID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__RemoveCharmEffectsByOBJECTID(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveCharmEffectsByOBJECTID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__RemoveCombatInvisibilityEffects(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveCombatInvisibilityEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveCounterspeller(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveCounterspeller);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveDomination(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveDomination);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveDominationEffect(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveDominationEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveFromArea(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveFromAssociateList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveFromAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveFromInvitationsOffered(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveFromInvitationsOffered);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveFromPVPList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveFromPVPList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveFromVisibleList(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveFromVisibleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RemoveGold(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__RemoveItem(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature__RemoveItemFromRepository(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveItemFromRepository);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSCreRestorePolymorphData* CNWSCreature__RemovePolymorphFromOutputCreature(CNWSCreature* thisPtr)
{
    using FuncPtrType = CNWSCreRestorePolymorphData*(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemovePolymorphFromOutputCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveSleepEffects(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveSleepEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveSpellActionFromRound(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveSpellActionFromRound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RemoveWoundingEffects(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RemoveWoundingEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__ReplyToInvitation(CNWSCreature* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReplyToInvitation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ReprocessAssociateList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ReprocessAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__RequestBuy(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RequestBuy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__RequestSell(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RequestSell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResetItemPossessor(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResetItemPossessor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ResetPCDominatedScripts(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResetPCDominatedScripts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ResetUpdateTimes(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResetUpdateTimes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResolveAmmunition(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveAmmunition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveAttack(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ResolveAttackRoll(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveAttackRoll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveCachedSpecialAttacks(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveCachedSpecialAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ResolveDamage(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveDamageShields(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveDamageShields);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveDeathAttack(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveDeathAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__ResolveDefensiveEffects(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveDefensiveEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResolveElementalDamage(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveElementalDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveInitiative(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveInitiative);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__ResolveItemCastSpell(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveItemCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveMeleeAnimations(CNWSCreature* thisPtr, int32_t a0, int32_t a1, CNWSObject* a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveMeleeAnimations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__ResolveMeleeAttack(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveMeleeAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ResolveMeleeSpecialAttack(CNWSCreature* thisPtr, int32_t a0, int32_t a1, CNWSObject* a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveMeleeSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__ResolveOnHitEffect(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveOnHitEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ResolveOnHitVisuals(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveOnHitVisuals);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolvePostMeleeDamage(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolvePostMeleeDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolvePostRangedDamage(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolvePostRangedDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveRangedAnimations(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveRangedAnimations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResolveRangedAttack(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveRangedAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__ResolveRangedMiss(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveRangedMiss);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveRangedSpecialAttack(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveRangedSpecialAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResolveSafeProjectile(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveSafeProjectile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__ResolveSituationalModifiers(CNWSCreature* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveSituationalModifiers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__ResolveSneakAttack(CNWSCreature* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ResolveSneakAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__Rest(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__Rest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__RestoreCutsceneVars(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RestoreCutsceneVars);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RestoreItemProperties(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RestoreItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__RestoreItemPropertiesInRepository(CNWSCreature* thisPtr, CItemRepository* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CItemRepository*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RestoreItemPropertiesInRepository);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__RestorePolymorphToOutputCreature(CNWSCreature* thisPtr, CNWSCreRestorePolymorphData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSCreRestorePolymorphData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RestorePolymorphToOutputCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__RunEquip(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RunEquip);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSCreature__RunUnequip(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4, uint32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, unsigned char, unsigned char, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__RunUnequip);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSCreature__SaveAssociateList(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SaveAssociateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SaveAutoMapData(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SaveAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__SaveCreature(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SaveCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSCreature__SavePersonalReputationList(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SavePersonalReputationList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SaveQuickBarHack(CNWSCreature* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SaveQuickBarHack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SaveQuickButtons(CNWSCreature* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SaveQuickButtons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreature__SavingThrowRoll(CNWSCreature* thisPtr, unsigned char a0, uint16_t a1, unsigned char a2, uint32_t a3, int32_t a4, uint16_t a5, int32_t a6)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, uint16_t, unsigned char, uint32_t, int32_t, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SavingThrowRoll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature__SawTrapInformAssociates(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SawTrapInformAssociates);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SendFeedbackMessage(CNWSCreature* thisPtr, uint16_t a0, CNWCCMessageData* a1, CNWSPlayer* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, CNWCCMessageData*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SendFeedbackMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SendFeedbackString(CNWSCreature* thisPtr, CExoString a0, CNWSPlayer* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CExoString, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SendFeedbackString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetActivity(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetActivity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetAllTilesExplored(CNWSCreature* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAllTilesExplored);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetAnimation(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetAssociateListenPatterns(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAssociateListenPatterns);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__SetAssociatesToForgetAggression(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAssociatesToForgetAggression);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetAssociateType(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAssociateType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetAutoMapData(CNWSCreature* thisPtr, int32_t a0, uint32_t* a1, unsigned char** a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, uint32_t*, unsigned char**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetBroadcastedAOOTo(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetBroadcastedAOOTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetCombatMode(CNWSCreature* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetCombatMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetCombatState(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetCombatState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetDefensiveCastingMode(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetDefensiveCastingMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetDetectMode(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetDetectMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetEffectSpellId(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetExcitedState(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetExcitedState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetGold(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetId(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetInTransit(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetInTransit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetInvitedToParty(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetInvitedToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetLockOrientationToObject(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetLockOrientationToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetMode(CNWSCreature* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetMovementRateFactor(CNWSCreature* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetMovementRateFactor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetPCDominatedScripts(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetPCDominatedScripts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__SetPortrait(CNWSCreature* thisPtr, CResRef a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetPortrait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetPortraitId(CNWSCreature* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetPortraitId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetPVPPlayerLikesMe(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetPVPPlayerLikesMe);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_AssociateCommand(CNWSCreature* thisPtr, unsigned char a0, int32_t a1, uint16_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, int32_t, uint16_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_AssociateCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__SetQuickbarButton_CommandLine(CNWSCreature* thisPtr, unsigned char a0, const CExoString& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_CommandLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DM_General_ResRefParam(CNWSCreature* thisPtr, unsigned char a0, unsigned char a1, const CResRef& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, unsigned char, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DM_General_ResRefParam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint(CNWSCreature* thisPtr, unsigned char a0, const CResRef& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, const CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_GeneralINTParam(CNWSCreature* thisPtr, unsigned char a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_GeneralINTParam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetQuickbarButton_GeneralNoParam(CNWSCreature* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_GeneralNoParam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetQuickbarButton_Item(CNWSCreature* thisPtr, unsigned char a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, uint32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_Item);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__SetQuickbarButton_Spell(CNWSCreature* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2, unsigned char a3, unsigned char a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, unsigned char, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_Spell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__SetQuickbarButton_SpellLikeAbility(CNWSCreature* thisPtr, unsigned char a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetQuickbarButton_SpellLikeAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SetStandardFactionReputation(CNWSCreature* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetStandardFactionReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SetStealthMode(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetStealthMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SetTileExplored(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SetTileExplored);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSCreature__SignalMeleeDamage(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SignalMeleeDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SignalRangedDamage(CNWSCreature* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SignalRangedDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__SpawnInHeartbeatPerception(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SpawnInHeartbeatPerception);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__SplitItem(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SplitItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__StartBarter(CNWSCreature* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__StartBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__StartGuiTimingBar(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__StartGuiTimingBar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__StopGuiTimingBar(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__StopGuiTimingBar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__StoreCutsceneVars(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__StoreCutsceneVars);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__SummonAnimalCompanion(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SummonAnimalCompanion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__SummonAssociate(CNWSCreature* thisPtr, CResRef a0, CExoString a1, uint16_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CResRef, CExoString, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SummonAssociate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreature__SummonFamiliar(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__SummonFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__TerminateClientSidePath(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__TerminateClientSidePath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__TestAIStateAsMode(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__TestAIStateAsMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__ToggleMode(CNWSCreature* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ToggleMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__TransferGold(CNWSCreature* thisPtr, uint32_t a0, Vector a1, uint32_t a2, int32_t a3, unsigned char a4, unsigned char a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, Vector, uint32_t, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__TransferGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature__TranslateAddress(CNWSCreature* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t* a3, int32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__TranslateAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature__UnequipItem(CNWSCreature* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnequipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__UnPolymorph(CNWSCreature* thisPtr, CGameEffect* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnPolymorph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__UnpossessCreature(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnpossessCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UnpossessCreatureDM(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnpossessCreatureDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UnpossessFamiliar(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnpossessFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UnsummonMyself(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UnsummonMyself);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateActionQueue(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateAppearanceDependantInfo(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateAppearanceDependantInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateAppearanceForEquippedItems(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateAppearanceForEquippedItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateAttributesOnEffect(CNWSCreature* thisPtr, CGameEffect* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateAttributesOnEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreature__UpdateAutoMap(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateAutoMap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__UpdateCombatRoundTimer(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateCombatRoundTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateEffectPtrs(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateEffectPtrs);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateEncumbranceState(CNWSCreature* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateEncumbranceState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreature__UpdateExcitedStateTimer(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateExcitedStateTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdatePersonalSpace(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdatePersonalSpace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__UpdateSpecialAttacks(CNWSCreature* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateSpecialAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__UpdateSubareasOnJumpPosition(CNWSCreature* thisPtr, Vector a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, Vector, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateSubareasOnJumpPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreature__UpdateSubareasOnMoveTo(CNWSCreature* thisPtr, Vector a0, Vector a1, int32_t a2, CExoArrayListTemplatedunsignedlong* a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, Vector, Vector, int32_t, CExoArrayListTemplatedunsignedlong*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateSubareasOnMoveTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreature__UpdateTrapCheck(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateTrapCheck);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateTrapCheckDM(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateTrapCheckDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCreature__UpdateVisibleList(CNWSCreature* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UpdateVisibleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__UseFeat(CNWSCreature* thisPtr, uint16_t a0, uint16_t a1, uint32_t a2, uint32_t a3, Vector* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint16_t, uint16_t, uint32_t, uint32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UseFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSCreature__UseItem(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3, Vector a4, uint32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char, unsigned char, uint32_t, Vector, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UseItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSCreature__UseLoreOnItem(CNWSCreature* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UseLoreOnItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreature__UseSkill(CNWSCreature* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2, Vector a3, uint32_t a4, uint32_t a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, unsigned char, unsigned char, uint32_t, Vector, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__UseSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSCreature__ValidateCounterSpellData(CNWSCreature* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreature*, uint32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__ValidateCounterSpellData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWSCreature__WalkUpdateLocation(CNWSCreature* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__WalkUpdateLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSCreature__WalkUpdateLocationDistance(CNWSCreature* thisPtr, float a0, Vector* a1, Vector* a2, CExoArrayListTemplatedunsignedlong* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, float, Vector*, Vector*, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__WalkUpdateLocationDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSCreature__WalkUpdateLocationTestDistance(CNWSCreature* thisPtr, Vector a0, Vector a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreature*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreature__WalkUpdateLocationTestDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
