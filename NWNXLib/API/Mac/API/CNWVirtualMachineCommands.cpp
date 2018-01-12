#include "CNWVirtualMachineCommands.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "C2DA.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "pfCVMCommands.hpp"

namespace NWNXLib {

namespace API {

CNWVirtualMachineCommands::~CNWVirtualMachineCommands()
{
    CNWVirtualMachineCommands__CNWVirtualMachineCommandsDtor__0(this);
}

void* CNWVirtualMachineCommands::CopyGameDefinedStructure(int32_t a0, void* a1)
{
    return CNWVirtualMachineCommands__CopyGameDefinedStructure(this, a0, a1);
}

void* CNWVirtualMachineCommands::CreateGameDefinedStructure(int32_t a0)
{
    return CNWVirtualMachineCommands__CreateGameDefinedStructure(this, a0);
}

int32_t CNWVirtualMachineCommands::DebugGUIGetMessageFrom(char** a0, int32_t* a1)
{
    return CNWVirtualMachineCommands__DebugGUIGetMessageFrom(this, a0, a1);
}

void CNWVirtualMachineCommands::DebugGUISendMessageTo(char* a0, int32_t a1)
{
    return CNWVirtualMachineCommands__DebugGUISendMessageTo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::DebugGUIStart()
{
    return CNWVirtualMachineCommands__DebugGUIStart(this);
}

void CNWVirtualMachineCommands::DebugGUIStop()
{
    return CNWVirtualMachineCommands__DebugGUIStop(this);
}

void CNWVirtualMachineCommands::DebugGUIUpdate()
{
    return CNWVirtualMachineCommands__DebugGUIUpdate(this);
}

void CNWVirtualMachineCommands::DestroyGameDefinedStructure(int32_t a0, void* a1)
{
    return CNWVirtualMachineCommands__DestroyGameDefinedStructure(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommand(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommand(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionCounterSpell(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionCounterSpell(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionDoCommand(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionDoCommand(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingMelee(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingMelee(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingRanged(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingRanged(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionEquipMostEffectiveArmor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionEquipMostEffectiveArmor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionExamine(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionExamine(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionExchangeItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionExchangeItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionFollowObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionFollowObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionInteractObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionInteractObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionJumpToObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionJumpToObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionJumpToPoint(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionJumpToPoint(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionLockActions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionLockActions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionMoveAwayFromLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionMoveAwayFromLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionPauseConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionPauseConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionRandomWalk(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionRandomWalk(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionRest(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionRest(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionResumeConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionResumeConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionSit(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionSit(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionStartConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionStartConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionUseFeat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionUseFeat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionUseSkill(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionUseSkill(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActionUseTalent(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActionUseTalent(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandActivatePortal(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandActivatePortal(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAddItemProperty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAddItemProperty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAddJournalQuestEntry(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAddJournalQuestEntry(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAddToParty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAddToParty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAdjustAlignment(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAdjustAlignment(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAdjustReputation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAdjustReputation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAmbientSound(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAmbientSound(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandApplyEffectAtPoint(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandApplyEffectAtPoint(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandApplyEffectOnObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandApplyEffectOnObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAreaManagement(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAreaManagement(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAssignCommand(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAssignCommand(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAssociateAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAssociateAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAttack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAttack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandAutoMapExplorationManagement(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandAutoMapExplorationManagement(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandBeginConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandBeginConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandBlackScreen(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandBlackScreen(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandBootPC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandBootPC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCastSpell(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCastSpell(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandChangeFaction(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandChangeFaction(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandClearAllActions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandClearAllActions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCloseDoor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCloseDoor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCopyItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCopyItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCopyItemAndModify(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCopyItemAndModify(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCopyObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCopyObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCreateItemOnObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCreateItemOnObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCreateObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCreateObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCreateTrapAtLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCreateTrapAtLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandCreateTrapOnObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandCreateTrapOnObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDayNightCycle(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDayNightCycle(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDecrementFeatUses(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDecrementFeatUses(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDecrementSpellUses(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDecrementSpellUses(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDelayCommand(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDelayCommand(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDeleteCampaignVariable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDeleteCampaignVariable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDeleteVar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDeleteVar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDestroyCampaignDatabase(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDestroyCampaignDatabase(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDestroyObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDestroyObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDistanceConversions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDistanceConversions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDoDoorAction(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDoDoorAction(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDoSinglePlayerAutoSave(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDoSinglePlayerAutoSave(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDoTouchAttack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDoTouchAttack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandDoWhirlwindAttack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandDoWhirlwindAttack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAbilityDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAbilityDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAbilityIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAbilityIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectACDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectACDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectACIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectACIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAppear(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAppear(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAreaEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAreaEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAttackDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAttackDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectAttackIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectAttackIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectBeam(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectBeam(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectBlindness(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectBlindness(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectComplex(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectComplex(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectConcealment(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectConcealment(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectCutsceneGhost(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectCutsceneGhost(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageReduction(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageReduction(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageResistance(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageResistance(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDamageShield(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDamageShield(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDarkness(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDarkness(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDisappear(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDisappear(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDisappearAppear(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDisappearAppear(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectDisease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectDisease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectEthereal(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectEthereal(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectHeal(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectHeal(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectHitPointChangeWhenDying(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectHitPointChangeWhenDying(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectImmunity(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectImmunity(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectInvisibility(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectInvisibility(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectLinkEffects(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectLinkEffects(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectMissChance(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectMissChance(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectModifyAttacks(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectModifyAttacks(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectNegativeLevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectNegativeLevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectPetrify(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectPetrify(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectPoison(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectPoison(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectResurrection(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectResurrection(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSanctuary(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSanctuary(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSeeInvisible(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSeeInvisible(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSkillDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSkillDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSkillIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSkillIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSpellFailure(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSpellFailure(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSpellImmunity(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSpellImmunity(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSpellLevelAbsorption(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSpellLevelAbsorption(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceDecrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceDecrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceIncrease(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceIncrease(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSummonCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSummonCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectSwarm(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectSwarm(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectTemporaryHP(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectTemporaryHP(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectTrueSeeing(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectTrueSeeing(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectTurnResistance(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectTurnResistance(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectUltravision(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectUltravision(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEffectVisualEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEffectVisualEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEndGame(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEndGame(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEquipItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEquipItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEventActivateItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEventActivateItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEventConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEventConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEventSpellCastAt(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEventSpellCastAt(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandEventUserDefined(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandEventUserDefined(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandExecuteScript(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandExecuteScript(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandExploreAreaForPlayer(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandExploreAreaForPlayer(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandExportAllCharacters(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandExportAllCharacters(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandExportSingleCharacter(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandExportSingleCharacter(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandFindSubString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandFindSubString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandFloatingText(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandFloatingText(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandFloatToInt(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandFloatToInt(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandFloatToString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandFloatToString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandForceRest(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandForceRest(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGet2DAString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGet2DAString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAbilityModifier(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAbilityModifier(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAbilityScore(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAbilityScore(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetActionMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetActionMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAge(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAge(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAILevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAILevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAlignment(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAlignment(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionCreatureType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionCreatureType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAOEObjectCreator(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAOEObjectCreator(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAppearanceType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAppearanceType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetArcaneSpellFailure(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetArcaneSpellFailure(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetArea(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetArea(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAreaSize(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAreaSize(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAssociate(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAssociate(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAssociateType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAssociateType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAttackTarget(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAttackTarget(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAttemptedAttackTarget(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAttemptedAttackTarget(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetAttemptedSpellTarget(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetAttemptedSpellTarget(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetBaseAttackBonus(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetBaseAttackBonus(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetBaseItemType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetBaseItemType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetBattleTrack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetBattleTrack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetBlockingDoor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetBlockingDoor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCalendarDay(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCalendarDay(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCalendarMonth(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCalendarMonth(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCalendarYear(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCalendarYear(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCampaignFloat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCampaignFloat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCampaignInt(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCampaignInt(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCampaignLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCampaignLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCampaignString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCampaignString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCampaignVector(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCampaignVector(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCasterLevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetChallengeRating(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetChallengeRating(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetClassInformation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetClassInformation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCommandable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCommandable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureBodyPart(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureBodyPart(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureHasTalent(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureHasTalent(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureSize(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureSize(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureTailType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureTailType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureTalent(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureTalent(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCreatureWingType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCreatureWingType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCurrentAction(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCurrentAction(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCutsceneCameraMoveRate(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCutsceneCameraMoveRate(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetCutsceneMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetCutsceneMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDamageDealtByType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDamageDealtByType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDayTrack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDayTrack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDeity(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDeity(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDescription(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDescription(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDialogSoundLength(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDialogSoundLength(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetween(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetween(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetweenLocations(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetweenLocations(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDistanceToObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDistanceToObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetDroppableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetDroppableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectCasterLevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectCasterLevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectCreator(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectCreator(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectDuration(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectDuration(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectDurationRemaining(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationRemaining(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectDurationType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectSpellId(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectSpellId(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectSubType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectSubType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEffectType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEffectType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEmotions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEmotions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEncounterData(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEncounterData(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetEnteringObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetEnteringObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFacing(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFacing(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageGoodEvilAlignment(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageGoodEvilAlignment(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLawChaosAlignment(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLawChaosAlignment(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageReputation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageReputation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageXP(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageXP(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionBestAC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionBestAC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionEqual(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionEqual(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionGold(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionGold(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionLeader(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionLeader(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionLeastDamagedMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionLeastDamagedMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionMostDamagedMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionMostDamagedMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionMostFrequentClass(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionMostFrequentClass(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionNthNearestMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionNthNearestMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionStrongestMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionStrongestMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionWeakestMember(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionWeakestMember(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFactionWorstAC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFactionWorstAC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFamiliarCreatureType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFamiliarCreatureType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFamiliarName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFamiliarName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFogAmount(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFogAmount(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFogColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFogColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFootstepType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFootstepType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetFortitudeSavingThrow(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetFortitudeSavingThrow(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetGameDifficulty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetGameDifficulty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetGoingToBeAttackedBy(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetGoingToBeAttackedBy(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetGold(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetGold(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetGoldPieceValue(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetGoldPieceValue(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHardness(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHardness(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasFeat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasFeat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasFeatEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasFeatEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasInventory(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasInventory(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasSkill(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasSkill(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasSpell(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasSpell(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHasSpellEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHasSpellEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHenchman(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHenchman(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHiddenWhenEquipped(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHiddenWhenEquipped(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHitDice(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHitDice(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetHitpoints(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetHitpoints(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIdentified(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIdentified(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetImmortal(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetImmortal(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetInfiniteFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetInfiniteFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetInPersistentObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetInPersistentObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsAreaAboveGround(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsAreaAboveGround(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsAreaInterior(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsAreaInterior(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsAreaNatural(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsAreaNatural(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsCreatureDisarmable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsCreatureDisarmable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsDawn(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsDawn(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsDay(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsDay(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsDMPossessed(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsDMPossessed(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsDoorActionPossible(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsDoorActionPossible(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsDusk(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsDusk(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsEncounterCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsEncounterCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsImmune(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsImmune(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsInCombat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsInCombat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsInTrigger(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsInTrigger(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsNight(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsNight(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsOpen(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsOpen(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsPossessedFamiliar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsPossessedFamiliar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsRacialTypePlayable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsRacialTypePlayable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsReactionType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsReactionType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsResting(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsResting(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsSkillSuccessful(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsSkillSuccessful(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsTalentValid(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsTalentValid(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsTrapped(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsTrapped(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetIsWeaponEffective(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetIsWeaponEffective(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemACValue(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemACValue(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemAppearance(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemAppearance(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemCharges(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemCharges(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemCursedFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemCursedFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemHasItemProperty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemHasItemProperty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemInInventory(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemInInventory(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemInSlot(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemInSlot(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPossessedBy(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPossessedBy(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPossessor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPossessor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemProperty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemProperty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyDuration(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDuration(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyDurationRemaining(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationRemaining(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyDurationType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyInfo(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyInfo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetItemStackSize(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetItemStackSize(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetJournalQuestExperience(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetJournalQuestExperience(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetKeyRequiredFeedbackMessage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetKeyRequiredFeedbackMessage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastAssociateCommand(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastAssociateCommand(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastAttacker(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastAttacker(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastAttackMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastAttackMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastAttackType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastAttackType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastClosedBy(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastClosedBy(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastDamager(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastDamager(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastDisarmed(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastDisarmed(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastDisturbed(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastDisturbed(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastEquipped(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastEquipped(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastHostileActor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastHostileActor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastKiller(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastKiller(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastLocked(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastLocked(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastOpenedBy(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastOpenedBy(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastPCRested(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastPCRested(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastPerceived(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastPerceived(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastPerception(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastPerception(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastRestEventType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastRestEventType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastSpeaker(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastSpeaker(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastSpellCastClass(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastSpellCastClass(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastTrapDetected(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastTrapDetected(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastUnlocked(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastUnlocked(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastUsedBy(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastUsedBy(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLastWeaponUsed(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLastWeaponUsed(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLeavingObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLeavingObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLocked(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLocked(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLockInfo(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLockInfo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetLootable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetLootable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMaster(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMaster(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMatchedString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMatchedString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsCount(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsCount(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsNum(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsNum(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMaxHenchmen(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMaxHenchmen(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMetaMagicFeat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMetaMagicFeat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetModeState(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetModeState(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetModule(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetModule(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetModuleItemStuff(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetModuleItemStuff(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetModuleName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetModuleName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetMovementRate(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetMovementRate(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetNearestObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetNearestObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetNearestTrap(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetNearestTrap(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetNightTrack(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetNightTrack(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetNumStackedItems(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetNumStackedItems(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectByTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectByTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectInArea(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectInArea(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectInShape(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectInShape(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectValid(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectValid(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetObjectVisibility(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetObjectVisibility(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCChatMessage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCChatMessage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCChatSpeaker(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCChatSpeaker(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCChatVolume(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCChatVolume(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCIPAddress(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCIPAddress(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCLevellingUp(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCLevellingUp(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCPlayerName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCPlayerName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCPublicCDKey(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCPublicCDKey(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPCSpeaker(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPCSpeaker(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPhenoType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPhenoType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPickpocketableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPickpocketableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPlaceableIllumination(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPlaceableIllumination(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPlotFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPlotFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPortraitId(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPortraitId(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPortraitResRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPortraitResRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetPosition(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetPosition(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetRacialType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetRacialType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetReflexAdjustedDamage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetReflexAdjustedDamage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetReflexSavingThrow(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetReflexSavingThrow(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetReputation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetReputation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetResRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetResRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSittingCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSittingCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSkillRank(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSkillRank(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSkyBox(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSkyBox(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellCast(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellCast(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellCasterItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellCasterItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellId(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellId(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellResistance(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellResistance(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellSaveDC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellSaveDC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetLoc(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetLoc(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStartingPackage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStartingPackage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStolenFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStolenFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStrByStrRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStrByStrRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStringLeft(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStringLeft(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStringLength(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStringLength(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStringLowerCase(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStringLowerCase(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStringRight(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStringRight(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStringUpperCase(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStringUpperCase(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetStrRefSoundDuration(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetStrRefSoundDuration(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSubRace(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSubRace(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetSubString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetSubString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTileLightColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTileLightColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTimeHour(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTimeHour(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTimeMillisecond(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTimeMillisecond(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTimeMinute(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTimeMinute(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTimeSecond(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTimeSecond(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTotalDamageDealt(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTotalDamageDealt(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTransitionTarget(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTransitionTarget(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTrapInfo(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTrapInfo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetTurnResistanceHD(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetTurnResistanceHD(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetUseableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetUseableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetUserDefinedEventNumber(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetUserDefinedEventNumber(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetVar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetVar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetWaypointByTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetWaypointByTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetWeaponRanged(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetWeaponRanged(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetWeather(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetWeather(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetWeight(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetWeight(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetWillSavingThrow(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetWillSavingThrow(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetXP(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetXP(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGetXPScale(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGetXPScale(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGiveGoldToCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGiveGoldToCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandGiveXPToCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandGiveXPToCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIncrementRemainingFeatUses(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIncrementRemainingFeatUses(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandInsertString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandInsertString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIntToFloat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIntToFloat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIntToHexString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIntToHexString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIntToString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIntToString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsAIState(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsAIState(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsDM(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsDM(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsEffectValid(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsEffectValid(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsInConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsInConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsItemPropertyValid(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsItemPropertyValid(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsListening(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsListening(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandIsPC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandIsPC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandItemActivated(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandItemActivated(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandItemPropertyEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandLevelUpHenchman(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandLevelUpHenchman(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandLineOfSight(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandLineOfSight(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandLocationAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandLocationAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandLockCamera(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandLockCamera(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMath(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMath(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandModuleAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandModuleAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMoveAwayFromObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMoveAwayFromObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMoveToObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMoveToObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMoveToPoint(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMoveToPoint(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMusicBackground(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMusicBackground(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandMusicBattle(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandMusicBattle(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandObjectToString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandObjectToString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandOpenDoor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandOpenDoor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandOpenInventory(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandOpenInventory(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandOpenStore(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandOpenStore(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPersonalReputationAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPersonalReputationAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPickUpItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPickUpItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPlayAnimation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPlayAnimation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPlaySound(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPlaySound(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPlaySoundByStrRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPlaySoundByStrRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPopUpGUIPanel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPopUpGUIPanel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintFloat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintFloat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintInteger(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintInteger(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintLogEntry(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintLogEntry(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPrintVector(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPrintVector(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandPutDownItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandPutDownItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRandom(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRandom(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRandomName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRandomName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRecomputeStaticLighting(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRecomputeStaticLighting(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRemoveEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRemoveEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRemoveFromParty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRemoveFromParty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRemoveItemProperty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRemoveItemProperty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRemoveJournalQuestEntry(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRemoveJournalQuestEntry(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandResistSpell(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandResistSpell(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRestoreBaseAttackBonus(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRestoreBaseAttackBonus(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRestoreCameraFacing(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRestoreCameraFacing(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRetrieveCampaignObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRetrieveCampaignObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandRollDice(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandRollDice(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSavingThrow(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSavingThrow(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSendMessageToAllDMs(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSendMessageToAllDMs(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSendMessageToPC(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSendMessageToPC(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSendMessageToPCByStrRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSendMessageToPCByStrRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetActionMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetActionMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetAILevel(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetAILevel(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetAreaTransitionBMP(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetAreaTransitionBMP(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetAssociateListenPatterns(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetAssociateListenPatterns(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetBaseAttackBonus(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetBaseAttackBonus(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCalendar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCalendar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCameraHeight(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCameraHeight(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCameraLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCameraLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCameraMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCameraMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCampaignFloat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCampaignFloat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCampaignInt(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCampaignInt(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCampaignLocation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCampaignLocation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCampaignString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCampaignString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCampaignVector(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCampaignVector(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCommandable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCommandable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCreatureAppearanceType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCreatureAppearanceType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCreatureBodyPart(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCreatureBodyPart(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCreatureTailType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCreatureTailType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCreatureWingType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCreatureWingType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCustomToken(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCustomToken(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCutsceneCameraMoveRate(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCutsceneCameraMoveRate(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetCutsceneMode(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetCutsceneMode(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetDeity(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetDeity(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetDescription(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetDescription(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetDislike(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetDislike(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetDroppableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetDroppableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetEncounterData(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetEncounterData(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetFacing(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetFacing(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetFade(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetFade(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetFogAmount(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetFogAmount(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetFogColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetFogColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetFootstepType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetFootstepType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetHardness(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetHardness(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetHiddenWhenEquipped(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetHiddenWhenEquipped(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetIdentified(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetIdentified(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetImmortal(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetImmortal(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetInfiniteFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetInfiniteFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetIsDestroyable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetIsDestroyable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetItemCharges(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetItemCharges(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetItemCursedFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetItemCursedFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetItemStackSize(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetItemStackSize(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetKeyRequiredFeedbackMessage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetKeyRequiredFeedbackMessage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetLike(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetLike(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetListening(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetListening(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetListenString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetListenString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetLocked(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetLocked(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetLockInfo(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetLockInfo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetLootable(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetLootable(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetMapPinEnabled(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetMapPinEnabled(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetMaxHenchmen(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetMaxHenchmen(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetName(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetName(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPanelButtonFlash(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPanelButtonFlash(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPCChatMessage(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPCChatMessage(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPCChatVolume(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPCChatVolume(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPhenoType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPhenoType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPickpocketableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPickpocketableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPlaceableIllumination(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPlaceableIllumination(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPlotFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPlotFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPortraitId(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPortraitId(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetPortraitResRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetPortraitResRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetSavingThrow(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetSavingThrow(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetSkyBox(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetSkyBox(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetStolenFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetStolenFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetSubRace(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetSubRace(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetSubType(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetSubType(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetTag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetTag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetTileLightColor(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetTileLightColor(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetTime(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetTime(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetTransitionTarget(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetTransitionTarget(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetTrapInfo(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetTrapInfo(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetUseableFlag(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetUseableFlag(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetVar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetVar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetWeather(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetWeather(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetXP(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetXP(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSetXPScale(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSetXPScale(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSignalEvent(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSignalEvent(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSoundObjectPlay(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSoundObjectPlay(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetPosition(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetPosition(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetVolume(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetVolume(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSoundObjectStop(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSoundObjectStop(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSpawnScriptDebugger(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSpawnScriptDebugger(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSpeakOneLinerConversation(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSpeakOneLinerConversation(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSpeakString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSpeakString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSpeakStrRef(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSpeakStrRef(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStandardFactionReputationAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStandardFactionReputationAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStartNewModule(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStartNewModule(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStopFade(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStopFade(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStoreCameraFacing(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStoreCameraFacing(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStoreCampaignObject(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStoreCampaignObject(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStoreGet(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStoreGet(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStoreSet(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStoreSet(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandStringConversions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandStringConversions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSummonAssociate(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSummonAssociate(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandSurrenderToEnemies(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandSurrenderToEnemies(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTagEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTagEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTagItemProperty(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTagItemProperty(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTakeGoldFromCreature(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTakeGoldFromCreature(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTalent(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTalent(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTalentAccess(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTalentAccess(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTestString(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTestString(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTileExplorationManagement(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTileExplorationManagement(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandTimeConversions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandTimeConversions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandUnequipItem(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandUnequipItem(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandUnpossessFamiliar(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandUnpossessFamiliar(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVector(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVector(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVectorConversions(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVectorConversions(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVectorMagnitude(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVectorMagnitude(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVectorNormalize(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVectorNormalize(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVersusEffect(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVersusEffect(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandVoiceChat(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandVoiceChat(this, a0, a1);
}

int32_t CNWVirtualMachineCommands::ExecuteCommandWait(int32_t a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ExecuteCommandWait(this, a0, a1);
}

CExoString CNWVirtualMachineCommands::GetDebuggerLabelName(int32_t a0)
{
    return CNWVirtualMachineCommands__GetDebuggerLabelName(this, a0);
}

void CNWVirtualMachineCommands::GetEngineStructureWatchView(int32_t a0, void* a1, int32_t* a2, CExoString** a3, CExoString** a4)
{
    return CNWVirtualMachineCommands__GetEngineStructureWatchView(this, a0, a1, a2, a3, a4);
}

int32_t CNWVirtualMachineCommands::GetEqualGameDefinedStructure(int32_t a0, void* a1, void* a2)
{
    return CNWVirtualMachineCommands__GetEqualGameDefinedStructure(this, a0, a1, a2);
}

CExoString CNWVirtualMachineCommands::GetGameDefinedStructureName(int32_t a0)
{
    return CNWVirtualMachineCommands__GetGameDefinedStructureName(this, a0);
}

void CNWVirtualMachineCommands::GetObjectWatchView(uint32_t a0, int32_t* a1, CExoString** a2, CExoString** a3)
{
    return CNWVirtualMachineCommands__GetObjectWatchView(this, a0, a1, a2, a3);
}

C2DA* CNWVirtualMachineCommands::GetTableFromArmorPart(int32_t a0)
{
    return CNWVirtualMachineCommands__GetTableFromArmorPart(this, a0);
}

void CNWVirtualMachineCommands::InitializeCommands()
{
    return CNWVirtualMachineCommands__InitializeCommands(this);
}

int32_t CNWVirtualMachineCommands::LoadGameDefinedStructure(int32_t a0, void** a1, CResGFF* a2, CResStruct* a3)
{
    return CNWVirtualMachineCommands__LoadGameDefinedStructure(this, a0, a1, a2, a3);
}

void CNWVirtualMachineCommands::ReportError(CExoString& a0, int32_t a1)
{
    return CNWVirtualMachineCommands__ReportError(this, a0, a1);
}

void CNWVirtualMachineCommands::RunScriptCallback(CExoString& a0)
{
    return CNWVirtualMachineCommands__RunScriptCallback(this, a0);
}

int32_t CNWVirtualMachineCommands::SaveGameDefinedStructure(int32_t a0, void* a1, CResGFF* a2, CResStruct* a3)
{
    return CNWVirtualMachineCommands__SaveGameDefinedStructure(this, a0, a1, a2, a3);
}

void CNWVirtualMachineCommands__CNWVirtualMachineCommandsDtor__0(CNWVirtualMachineCommands* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__CNWVirtualMachineCommandsDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void* CNWVirtualMachineCommands__CopyGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0, void* a1)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__CopyGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void* CNWVirtualMachineCommands__CreateGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__CreateGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWVirtualMachineCommands__DebugGUIGetMessageFrom(CNWVirtualMachineCommands* thisPtr, char** a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, char**, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DebugGUIGetMessageFrom);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWVirtualMachineCommands__DebugGUISendMessageTo(CNWVirtualMachineCommands* thisPtr, char* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DebugGUISendMessageTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__DebugGUIStart(CNWVirtualMachineCommands* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DebugGUIStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWVirtualMachineCommands__DebugGUIStop(CNWVirtualMachineCommands* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DebugGUIStop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWVirtualMachineCommands__DebugGUIUpdate(CNWVirtualMachineCommands* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DebugGUIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWVirtualMachineCommands__DestroyGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0, void* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__DestroyGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommand(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionCounterSpell(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionCounterSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionDoCommand(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionDoCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingMelee(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingMelee);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingRanged(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingRanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionEquipMostEffectiveArmor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionEquipMostEffectiveArmor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionExamine(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionExamine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionExchangeItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionExchangeItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionFollowObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionFollowObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionInteractObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionInteractObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionJumpToObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionJumpToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionJumpToPoint(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionJumpToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionLockActions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionLockActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionMoveAwayFromLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionMoveAwayFromLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionPauseConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionPauseConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionRandomWalk(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionRandomWalk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionRest(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionRest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionResumeConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionResumeConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionSit(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionSit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionStartConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionStartConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionUseFeat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionUseFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionUseSkill(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionUseSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActionUseTalent(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActionUseTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandActivatePortal(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandActivatePortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAddItemProperty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAddItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAddJournalQuestEntry(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAddJournalQuestEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAddToParty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAddToParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAdjustAlignment(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAdjustAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAdjustReputation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAdjustReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAmbientSound(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAmbientSound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandApplyEffectAtPoint(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandApplyEffectAtPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandApplyEffectOnObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandApplyEffectOnObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAreaManagement(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAreaManagement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAssignCommand(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAssignCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAssociateAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAssociateAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAttack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandAutoMapExplorationManagement(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandAutoMapExplorationManagement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandBeginConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandBeginConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandBlackScreen(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandBlackScreen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandBootPC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandBootPC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCastSpell(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandChangeFaction(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandChangeFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandClearAllActions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandClearAllActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCloseDoor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCloseDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCopyItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCopyItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCopyItemAndModify(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCopyItemAndModify);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCopyObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCopyObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCreateItemOnObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCreateItemOnObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCreateObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCreateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCreateTrapAtLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCreateTrapAtLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandCreateTrapOnObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandCreateTrapOnObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDayNightCycle(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDayNightCycle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDecrementFeatUses(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDecrementFeatUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDecrementSpellUses(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDecrementSpellUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDelayCommand(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDelayCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDeleteCampaignVariable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDeleteCampaignVariable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDeleteVar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDeleteVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDestroyCampaignDatabase(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDestroyCampaignDatabase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDestroyObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDestroyObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDistanceConversions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDistanceConversions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDoDoorAction(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDoDoorAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDoSinglePlayerAutoSave(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDoSinglePlayerAutoSave);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDoTouchAttack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDoTouchAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandDoWhirlwindAttack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandDoWhirlwindAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAbilityDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAbilityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAbilityIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAbilityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectACDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectACDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectACIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectACIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAppear(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAreaEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAreaEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAttackDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAttackDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectAttackIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectAttackIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectBeam(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectBeam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectBlindness(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectBlindness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectComplex(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectComplex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectConcealment(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectConcealment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectCutsceneGhost(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectCutsceneGhost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageReduction(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageReduction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageResistance(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDamageShield(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDamageShield);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDarkness(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDarkness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDisappear(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDisappear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDisappearAppear(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDisappearAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectDisease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectDisease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectEthereal(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectEthereal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectHeal(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectHeal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectHitPointChangeWhenDying(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectHitPointChangeWhenDying);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectImmunity(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectInvisibility(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectInvisibility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectLinkEffects(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectLinkEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectMissChance(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectMissChance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectModifyAttacks(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectModifyAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectNegativeLevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectNegativeLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectPetrify(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectPetrify);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectPoison(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectPoison);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectResurrection(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectResurrection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSanctuary(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSanctuary);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSeeInvisible(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSeeInvisible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSkillDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSkillDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSkillIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSkillIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSpellFailure(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSpellImmunity(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSpellImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSpellLevelAbsorption(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSpellLevelAbsorption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceDecrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceIncrease(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSummonCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSummonCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectSwarm(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectSwarm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectTemporaryHP(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectTemporaryHP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectTrueSeeing(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectTrueSeeing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectTurnResistance(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectTurnResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectUltravision(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectUltravision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEffectVisualEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEffectVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEndGame(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEndGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEquipItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEquipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEventActivateItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEventActivateItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEventConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEventConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEventSpellCastAt(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEventSpellCastAt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandEventUserDefined(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandEventUserDefined);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandExecuteScript(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandExecuteScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandExploreAreaForPlayer(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandExploreAreaForPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandExportAllCharacters(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandExportAllCharacters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandExportSingleCharacter(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandExportSingleCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandFindSubString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandFindSubString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandFloatingText(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandFloatingText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandFloatToInt(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandFloatToInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandFloatToString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandFloatToString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandForceRest(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandForceRest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGet2DAString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGet2DAString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAbilityModifier(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAbilityModifier);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAbilityScore(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAbilityScore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetActionMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetActionMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAge(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAge);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAILevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAILevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAlignment(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionCreatureType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionCreatureType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAOEObjectCreator(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAOEObjectCreator);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAppearanceType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAppearanceType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetArcaneSpellFailure(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetArcaneSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetArea(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAreaSize(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAreaSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAssociate(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAssociate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAssociateType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAssociateType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAttackTarget(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAttackTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAttemptedAttackTarget(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAttemptedAttackTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetAttemptedSpellTarget(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetAttemptedSpellTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetBaseAttackBonus(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetBaseAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetBaseItemType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetBaseItemType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetBattleTrack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetBattleTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetBlockingDoor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetBlockingDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCalendarDay(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCalendarDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCalendarMonth(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCalendarMonth);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCalendarYear(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCalendarYear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCampaignFloat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCampaignFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCampaignInt(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCampaignInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCampaignLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCampaignLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCampaignString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCampaignString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCampaignVector(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCampaignVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetChallengeRating(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetChallengeRating);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetClassInformation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetClassInformation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCommandable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCommandable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureBodyPart(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureBodyPart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureHasTalent(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureHasTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureSize(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureTailType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureTailType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureTalent(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCreatureWingType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCreatureWingType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCurrentAction(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCurrentAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCutsceneCameraMoveRate(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCutsceneCameraMoveRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetCutsceneMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetCutsceneMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDamageDealtByType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDamageDealtByType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDayTrack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDayTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDeity(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDeity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDescription(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDialogSoundLength(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDialogSoundLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetween(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetween);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetweenLocations(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetweenLocations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDistanceToObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDistanceToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetDroppableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetDroppableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectCasterLevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectCasterLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectCreator(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectCreator);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectDuration(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectDuration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationRemaining(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationRemaining);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectSpellId(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectSubType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectSubType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEffectType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEffectType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEmotions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEmotions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEncounterData(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEncounterData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetEnteringObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetEnteringObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFacing(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFacing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageGoodEvilAlignment(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageGoodEvilAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLawChaosAlignment(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLawChaosAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageReputation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageXP(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageXP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionBestAC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionBestAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionEqual(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionEqual);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionGold(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionLeader(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionLeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionLeastDamagedMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionLeastDamagedMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionMostDamagedMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionMostDamagedMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionMostFrequentClass(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionMostFrequentClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionNthNearestMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionNthNearestMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionStrongestMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionStrongestMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionWeakestMember(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionWeakestMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFactionWorstAC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFactionWorstAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFamiliarCreatureType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFamiliarCreatureType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFamiliarName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFamiliarName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFogAmount(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFogAmount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFogColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFogColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFootstepType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFootstepType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetFortitudeSavingThrow(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetFortitudeSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetGameDifficulty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetGameDifficulty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetGoingToBeAttackedBy(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetGoingToBeAttackedBy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetGold(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetGoldPieceValue(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetGoldPieceValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHardness(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHardness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasFeat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasFeatEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasFeatEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasInventory(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasSkill(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasSpell(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHasSpellEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHasSpellEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHenchman(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHenchman);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHiddenWhenEquipped(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHiddenWhenEquipped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHitDice(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHitDice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetHitpoints(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetHitpoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIdentified(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIdentified);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetImmortal(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetImmortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetInfiniteFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetInfiniteFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetInPersistentObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetInPersistentObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsAreaAboveGround(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsAreaAboveGround);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsAreaInterior(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsAreaInterior);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsAreaNatural(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsAreaNatural);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsCreatureDisarmable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsCreatureDisarmable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsDawn(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsDawn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsDay(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsDMPossessed(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsDMPossessed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsDoorActionPossible(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsDoorActionPossible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsDusk(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsDusk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsEncounterCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsEncounterCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsImmune(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsImmune);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsInCombat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsInCombat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsInTrigger(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsInTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsNight(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsNight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsOpen(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsOpen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsPossessedFamiliar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsPossessedFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsRacialTypePlayable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsRacialTypePlayable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsReactionType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsReactionType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsResting(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsResting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsSkillSuccessful(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsSkillSuccessful);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsTalentValid(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsTalentValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsTrapped(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsTrapped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetIsWeaponEffective(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetIsWeaponEffective);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemACValue(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemACValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemAppearance(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemAppearance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemCharges(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemCharges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemCursedFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemCursedFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemHasItemProperty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemHasItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemInInventory(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemInInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemInSlot(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemInSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPossessedBy(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPossessedBy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPossessor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPossessor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemProperty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDuration(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDuration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationRemaining(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationRemaining);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyInfo(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetItemStackSize(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetItemStackSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetJournalQuestExperience(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetJournalQuestExperience);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetKeyRequiredFeedbackMessage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetKeyRequiredFeedbackMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastAssociateCommand(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastAssociateCommand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastAttacker(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastAttacker);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastAttackMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastAttackMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastAttackType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastAttackType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastClosedBy(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastClosedBy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastDamager(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastDamager);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastDisarmed(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastDisarmed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastDisturbed(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastDisturbed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastEquipped(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastEquipped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastHostileActor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastHostileActor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastKiller(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastKiller);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastLocked(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastLocked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastOpenedBy(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastOpenedBy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastPCRested(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastPCRested);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastPerceived(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastPerceived);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastPerception(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastPerception);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastRestEventType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastRestEventType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastSpeaker(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastSpeaker);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastSpellCastClass(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastSpellCastClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastTrapDetected(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastTrapDetected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastUnlocked(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastUnlocked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastUsedBy(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastUsedBy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLastWeaponUsed(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLastWeaponUsed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLeavingObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLeavingObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLocked(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLocked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLockInfo(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLockInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetLootable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetLootable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMaster(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMaster);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMatchedString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMatchedString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsCount(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsNum(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsNum);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMaxHenchmen(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMaxHenchmen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMetaMagicFeat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMetaMagicFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetModeState(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetModeState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetModule(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetModuleItemStuff(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetModuleItemStuff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetModuleName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetMovementRate(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetMovementRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetNearestObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetNearestObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetNearestTrap(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetNearestTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetNightTrack(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetNightTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetNumStackedItems(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetNumStackedItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectByTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectByTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectInArea(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectInShape(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectInShape);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectValid(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetObjectVisibility(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetObjectVisibility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCChatMessage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCChatSpeaker(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCChatSpeaker);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCChatVolume(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCChatVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCIPAddress(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCIPAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCLevellingUp(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCLevellingUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCPlayerName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCPlayerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCPublicCDKey(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCPublicCDKey);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPCSpeaker(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPCSpeaker);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPhenoType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPhenoType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPickpocketableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPickpocketableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPlaceableIllumination(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPlaceableIllumination);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPlotFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPlotFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPortraitId(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPortraitId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPortraitResRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPortraitResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetPosition(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetRacialType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetRacialType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetReflexAdjustedDamage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetReflexAdjustedDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetReflexSavingThrow(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetReflexSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetReputation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetResRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSittingCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSittingCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSkillRank(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSkillRank);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSkyBox(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSkyBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellCast(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellCast);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellCasterItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellCasterItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellId(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellResistance(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellSaveDC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellSaveDC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetLoc(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetLoc);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStartingPackage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStartingPackage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStolenFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStolenFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStrByStrRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStrByStrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStringLeft(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStringLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStringLength(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStringLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStringLowerCase(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStringLowerCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStringRight(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStringRight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStringUpperCase(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStringUpperCase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetStrRefSoundDuration(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetStrRefSoundDuration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSubRace(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSubRace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetSubString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetSubString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTileLightColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTileLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTimeHour(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTimeHour);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTimeMillisecond(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTimeMillisecond);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTimeMinute(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTimeMinute);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTimeSecond(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTimeSecond);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTotalDamageDealt(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTotalDamageDealt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTransitionTarget(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTransitionTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTrapInfo(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTrapInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetTurnResistanceHD(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetTurnResistanceHD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetUseableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetUseableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetUserDefinedEventNumber(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetUserDefinedEventNumber);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetVar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetWaypointByTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetWaypointByTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetWeaponRanged(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetWeaponRanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetWeather(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetWeather);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetWeight(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetWeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetWillSavingThrow(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetWillSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetXP(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetXP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGetXPScale(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGetXPScale);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGiveGoldToCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGiveGoldToCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandGiveXPToCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandGiveXPToCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIncrementRemainingFeatUses(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIncrementRemainingFeatUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandInsertString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandInsertString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIntToFloat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIntToFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIntToHexString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIntToHexString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIntToString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIntToString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsAIState(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsDM(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsDM);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsEffectValid(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsEffectValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsInConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsInConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsItemPropertyValid(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsItemPropertyValid);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsListening(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsListening);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandIsPC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandIsPC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandItemActivated(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandItemActivated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandLevelUpHenchman(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandLevelUpHenchman);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandLineOfSight(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandLineOfSight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandLocationAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandLocationAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandLockCamera(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandLockCamera);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMath(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandModuleAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandModuleAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMoveAwayFromObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMoveAwayFromObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMoveToObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMoveToObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMoveToPoint(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMoveToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMusicBackground(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMusicBackground);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandMusicBattle(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandMusicBattle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandObjectToString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandObjectToString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandOpenDoor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandOpenDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandOpenInventory(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandOpenInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandOpenStore(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandOpenStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPersonalReputationAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPersonalReputationAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPickUpItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPickUpItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPlayAnimation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPlayAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPlaySound(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPlaySound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPlaySoundByStrRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPlaySoundByStrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPopUpGUIPanel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPopUpGUIPanel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintFloat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintInteger(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintLogEntry(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintLogEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPrintVector(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPrintVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandPutDownItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandPutDownItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRandom(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRandom);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRandomName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRandomName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRecomputeStaticLighting(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRecomputeStaticLighting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRemoveEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRemoveEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRemoveFromParty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRemoveFromParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRemoveItemProperty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRemoveItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRemoveJournalQuestEntry(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRemoveJournalQuestEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandResistSpell(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandResistSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRestoreBaseAttackBonus(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRestoreBaseAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRestoreCameraFacing(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRestoreCameraFacing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRetrieveCampaignObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRetrieveCampaignObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandRollDice(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandRollDice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSavingThrow(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSendMessageToAllDMs(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSendMessageToAllDMs);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSendMessageToPC(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSendMessageToPC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSendMessageToPCByStrRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSendMessageToPCByStrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetActionMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetActionMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetAILevel(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetAILevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetAreaTransitionBMP(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetAreaTransitionBMP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetAssociateListenPatterns(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetAssociateListenPatterns);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetBaseAttackBonus(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetBaseAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCalendar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCalendar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCameraHeight(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCameraHeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCameraLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCameraLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCameraMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCameraMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCampaignFloat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCampaignFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCampaignInt(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCampaignInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCampaignLocation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCampaignLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCampaignString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCampaignString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCampaignVector(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCampaignVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCommandable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCommandable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCreatureAppearanceType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCreatureAppearanceType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCreatureBodyPart(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCreatureBodyPart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCreatureTailType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCreatureTailType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCreatureWingType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCreatureWingType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCustomToken(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCustomToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCutsceneCameraMoveRate(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCutsceneCameraMoveRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetCutsceneMode(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetCutsceneMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetDeity(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetDeity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetDescription(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetDislike(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetDislike);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetDroppableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetDroppableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetEncounterData(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetEncounterData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetFacing(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetFacing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetFade(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetFade);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetFogAmount(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetFogAmount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetFogColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetFogColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetFootstepType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetFootstepType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetHardness(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetHardness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetHiddenWhenEquipped(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetHiddenWhenEquipped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetIdentified(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetIdentified);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetImmortal(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetImmortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetInfiniteFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetInfiniteFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetIsDestroyable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetIsDestroyable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetItemCharges(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetItemCharges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetItemCursedFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetItemCursedFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetItemStackSize(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetItemStackSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetKeyRequiredFeedbackMessage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetKeyRequiredFeedbackMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetLike(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetLike);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetListening(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetListening);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetListenString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetListenString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetLocked(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetLocked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetLockInfo(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetLockInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetLootable(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetLootable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetMapPinEnabled(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetMapPinEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetMaxHenchmen(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetMaxHenchmen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetName(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPanelButtonFlash(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPanelButtonFlash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPCChatMessage(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPCChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPCChatVolume(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPCChatVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPhenoType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPhenoType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPickpocketableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPickpocketableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPlaceableIllumination(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPlaceableIllumination);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPlotFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPlotFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPortraitId(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPortraitId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetPortraitResRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetPortraitResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetSavingThrow(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetSavingThrow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetSkyBox(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetSkyBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetStolenFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetStolenFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetSubRace(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetSubRace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetSubType(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetSubType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetTag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetTileLightColor(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetTileLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetTime(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetTransitionTarget(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetTransitionTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetTrapInfo(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetTrapInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetUseableFlag(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetUseableFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetVar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetWeather(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetWeather);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetXP(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetXP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSetXPScale(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSetXPScale);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSignalEvent(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSignalEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSoundObjectPlay(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSoundObjectPlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetPosition(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetVolume(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSoundObjectStop(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSoundObjectStop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSpawnScriptDebugger(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSpawnScriptDebugger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSpeakOneLinerConversation(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSpeakOneLinerConversation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSpeakString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSpeakString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSpeakStrRef(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSpeakStrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStandardFactionReputationAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStandardFactionReputationAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStartNewModule(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStartNewModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStopFade(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStopFade);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStoreCameraFacing(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStoreCameraFacing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStoreCampaignObject(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStoreCampaignObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStoreGet(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStoreGet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStoreSet(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStoreSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandStringConversions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandStringConversions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSummonAssociate(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSummonAssociate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandSurrenderToEnemies(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandSurrenderToEnemies);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTagEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTagEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTagItemProperty(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTagItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTakeGoldFromCreature(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTakeGoldFromCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTalent(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTalentAccess(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTalentAccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTestString(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTestString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTileExplorationManagement(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTileExplorationManagement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandTimeConversions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandTimeConversions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandUnequipItem(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandUnequipItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandUnpossessFamiliar(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandUnpossessFamiliar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVector(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVectorConversions(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVectorConversions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVectorMagnitude(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVectorMagnitude);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVectorNormalize(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVectorNormalize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVersusEffect(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVersusEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandVoiceChat(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandVoiceChat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWVirtualMachineCommands__ExecuteCommandWait(CNWVirtualMachineCommands* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ExecuteCommandWait);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CNWVirtualMachineCommands__GetDebuggerLabelName(CNWVirtualMachineCommands* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetDebuggerLabelName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWVirtualMachineCommands__GetEngineStructureWatchView(CNWVirtualMachineCommands* thisPtr, int32_t a0, void* a1, int32_t* a2, CExoString** a3, CExoString** a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void*, int32_t*, CExoString**, CExoString**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetEngineStructureWatchView);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWVirtualMachineCommands__GetEqualGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0, void* a1, void* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetEqualGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CNWVirtualMachineCommands__GetGameDefinedStructureName(CNWVirtualMachineCommands* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetGameDefinedStructureName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWVirtualMachineCommands__GetObjectWatchView(CNWVirtualMachineCommands* thisPtr, uint32_t a0, int32_t* a1, CExoString** a2, CExoString** a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, uint32_t, int32_t*, CExoString**, CExoString**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetObjectWatchView);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

C2DA* CNWVirtualMachineCommands__GetTableFromArmorPart(CNWVirtualMachineCommands* thisPtr, int32_t a0)
{
    using FuncPtrType = C2DA*(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__GetTableFromArmorPart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWVirtualMachineCommands__InitializeCommands(CNWVirtualMachineCommands* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__InitializeCommands);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWVirtualMachineCommands__LoadGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0, void** a1, CResGFF* a2, CResStruct* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void**, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__LoadGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWVirtualMachineCommands__ReportError(CNWVirtualMachineCommands* thisPtr, CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__ReportError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWVirtualMachineCommands__RunScriptCallback(CNWVirtualMachineCommands* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__RunScriptCallback);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWVirtualMachineCommands__SaveGameDefinedStructure(CNWVirtualMachineCommands* thisPtr, int32_t a0, void* a1, CResGFF* a2, CResStruct* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWVirtualMachineCommands*, int32_t, void*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWVirtualMachineCommands__SaveGameDefinedStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
