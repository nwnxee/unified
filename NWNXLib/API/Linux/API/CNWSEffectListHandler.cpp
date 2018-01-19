#include "CNWSEffectListHandler.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CGameEffect.hpp"
#include "CNWSObject.hpp"
#include "pfAECommands.hpp"
#include "pfRECommands.hpp"

namespace NWNXLib {

namespace API {

CNWSEffectListHandler::~CNWSEffectListHandler()
{
    CNWSEffectListHandler__CNWSEffectListHandlerDtor__0(this);
}

void CNWSEffectListHandler::InitializeEffects()
{
    return CNWSEffectListHandler__InitializeEffects(this);
}

int32_t CNWSEffectListHandler::OnApplyAbilityDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAbilityDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyAbilityIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAbilityIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyACDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyACDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyACIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyACIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyAppear(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAppear(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyArcaneSpellFailure(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyArcaneSpellFailure(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyAreaOfEffect(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAreaOfEffect(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyAttackDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAttackDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyAttackIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyAttackIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyBeam(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyBeam(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyBlindness(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyBlindness(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyBlindnessInactive(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyBlindnessInactive(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyBonusFeat(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyBonusFeat(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyBonusSpellOfLevel(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyBonusSpellOfLevel(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyConcealment(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyConcealment(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyCurse(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyCurse(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyCutsceneGhost(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyCutsceneGhost(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyCutsceneImmobile(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyCutsceneImmobile(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamage(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamage(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageImmunityDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageImmunityDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageImmunityIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageImmunityIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageReduction(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageReduction(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageResistance(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageResistance(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDamageShield(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDamageShield(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDarkness(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDarkness(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDeaf(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDeaf(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDeath(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDeath(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDefensiveStance(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDefensiveStance(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDisappear(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDisappear(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDisappearAppear(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDisappearAppear(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDisarm(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDisarm(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDisease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDisease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDispelAllMagic(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDispelAllMagic(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyDispelBestMagic(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyDispelBestMagic(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyEffectIcon(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyEffectIcon(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyEffectImmunity(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyEffectImmunity(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyEnemyAttackBonus(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyEnemyAttackBonus(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyEntangled(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyEntangled(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyHasteInternal(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyHasteInternal(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyHasteOrSlow(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyHasteOrSlow(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyHeal(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyHeal(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyHitPointChangeWhenDying(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyHitPointChangeWhenDying(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyInvisibility(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyInvisibility(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyItemProperty(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyItemProperty(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyKnockdown(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyKnockdown(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyLight(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyLight(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyLimitMovementSpeed(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyLimitMovementSpeed(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyLink(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyLink(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyMissChance(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyMissChance(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyModifyNumAttacks(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyModifyNumAttacks(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyMovementSpeedDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyMovementSpeedDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyMovementSpeedIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyMovementSpeedIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyNegativeLevel(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyNegativeLevel(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyPetrify(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyPetrify(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyPoison(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyPoison(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyPolymorph(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyPolymorph(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyRacialType(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyRacialType(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyRegenerate(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyRegenerate(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyResurrection(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyResurrection(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySanctuary(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySanctuary(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySavingThrowDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySavingThrowDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySavingThrowIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySavingThrowIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySeeInvisible(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySeeInvisible(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySetAIState(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySetAIState(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySetState(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySetState(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySetStateInternal(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySetStateInternal(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySilence(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySilence(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySkillDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySkillDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySkillIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySkillIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySlowInternal(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySlowInternal(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpecialWalkAnimation(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpecialWalkAnimation(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpellFailure(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpellFailure(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpellImmunity(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpellImmunity(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpellLevelAbsorption(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpellLevelAbsorption(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpellResistanceDecrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpellResistanceDecrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySpellResistanceIncrease(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySpellResistanceIncrease(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySummonCreature(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySummonCreature(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplySwarm(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplySwarm(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyTaunt(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyTaunt(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyTemporaryHitpoints(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyTemporaryHitpoints(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyTimestop(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyTimestop(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyTrueSeeing(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyTrueSeeing(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyTurnResistance(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyTurnResistance(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyUltraVision(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyUltraVision(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyVampiricRegeneration(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyVampiricRegeneration(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyVision(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyVision(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyVisualEffect(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyVisualEffect(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnApplyWounding(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnApplyWounding(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnEffectApplied(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CNWSEffectListHandler__OnEffectApplied(this, a0, a1, a2);
}

int32_t CNWSEffectListHandler::OnEffectRemoved(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnEffectRemoved(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveAbilityDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveAbilityDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveAbilityIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveAbilityIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveACDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveACDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveACIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveACIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveArcaneSpellFailure(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveArcaneSpellFailure(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveAreaOfEffect(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveAreaOfEffect(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveAttackDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveAttackDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveAttackIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveAttackIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveBeam(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveBeam(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveBlindness(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveBlindness(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveBonusFeat(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveBonusFeat(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveBonusSpellOfLevel(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveBonusSpellOfLevel(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveConcealment(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveConcealment(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveCurse(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveCurse(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveCutsceneGhost(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveCutsceneGhost(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDamageDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDamageDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDamageImmunityDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDamageImmunityDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDamageImmunityIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDamageImmunityIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDamageIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDamageIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDamageShield(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDamageShield(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDarkness(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDarkness(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDisappearAppear(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDisappearAppear(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveDisarm(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveDisarm(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveEffectIcon(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveEffectIcon(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveEffectImmunity(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveEffectImmunity(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveEnemyAttackBonus(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveEnemyAttackBonus(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveEntangled(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveEntangled(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveHasteInternal(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveHasteInternal(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveHasteOrSlow(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveHasteOrSlow(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveHitPointChangeWhenDying(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveHitPointChangeWhenDying(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveInvisibility(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveInvisibility(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveItemProperty(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveItemProperty(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveKnockdown(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveKnockdown(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveLight(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveLight(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveLimitMovementSpeed(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveLimitMovementSpeed(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveMissChance(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveMissChance(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveModifyNumAttacks(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveModifyNumAttacks(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveMovementSpeedDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveMovementSpeedDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveMovementSpeedIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveMovementSpeedIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveNegativeLevel(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveNegativeLevel(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemovePetrify(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemovePetrify(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemovePolymorph(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemovePolymorph(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveRacialType(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveRacialType(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSanctuary(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSanctuary(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSavingThrowDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSavingThrowDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSavingThrowIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSavingThrowIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSeeInvisible(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSeeInvisible(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSetAIState(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSetAIState(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSetState(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSetState(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSetStateInternal(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSetStateInternal(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSilence(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSilence(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSkillDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSkillDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSkillIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSkillIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSlowInternal(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSlowInternal(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpecialWalkAnimation(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpecialWalkAnimation(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpellFailure(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpellFailure(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpellImmunity(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpellImmunity(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpellLevelAbsorption(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpellLevelAbsorption(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpellResistanceDecrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpellResistanceDecrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSpellResistanceIncrease(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSpellResistanceIncrease(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSummonCreature(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSummonCreature(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveSwarm(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveSwarm(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveTaunt(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveTaunt(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveTemporaryHitpoints(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveTemporaryHitpoints(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveTimestop(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveTimestop(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveTrueSeeing(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveTrueSeeing(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveTurnResistance(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveTurnResistance(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveUltraVision(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveUltraVision(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveVision(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveVision(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveVisualEffect(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveVisualEffect(this, a0, a1);
}

int32_t CNWSEffectListHandler::OnRemoveWounding(CNWSObject* a0, CGameEffect* a1)
{
    return CNWSEffectListHandler__OnRemoveWounding(this, a0, a1);
}

void CNWSEffectListHandler::SendFloatyEffect(uint32_t a0, uint32_t a1)
{
    return CNWSEffectListHandler__SendFloatyEffect(this, a0, a1);
}

void CNWSEffectListHandler__CNWSEffectListHandlerDtor__0(CNWSEffectListHandler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEffectListHandler*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__CNWSEffectListHandlerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSEffectListHandler__InitializeEffects(CNWSEffectListHandler* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEffectListHandler*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__InitializeEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSEffectListHandler__OnApplyAbilityDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAbilityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyAbilityIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAbilityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyACDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyACDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyACIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyACIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyAppear(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyArcaneSpellFailure(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyArcaneSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyAreaOfEffect(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAreaOfEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyAttackDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAttackDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyAttackIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyAttackIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyBeam(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyBeam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyBlindness(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyBlindness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyBlindnessInactive(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyBlindnessInactive);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyBonusFeat(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyBonusFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyBonusSpellOfLevel(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyBonusSpellOfLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyConcealment(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyConcealment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyCurse(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyCurse);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyCutsceneGhost(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyCutsceneGhost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyCutsceneImmobile(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyCutsceneImmobile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamage(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageImmunityDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageImmunityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageImmunityIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageImmunityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageReduction(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageReduction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageResistance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDamageShield(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDamageShield);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDarkness(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDarkness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDeaf(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDeaf);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDeath(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDeath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDefensiveStance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDefensiveStance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDisappear(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDisappear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDisappearAppear(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDisappearAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDisarm(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDisarm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDisease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDisease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDispelAllMagic(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDispelAllMagic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyDispelBestMagic(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyDispelBestMagic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyEffectIcon(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyEffectIcon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyEffectImmunity(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyEffectImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyEnemyAttackBonus(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyEnemyAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyEntangled(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyEntangled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyHasteInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyHasteInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyHasteOrSlow(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyHasteOrSlow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyHeal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyHeal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyHitPointChangeWhenDying(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyHitPointChangeWhenDying);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyInvisibility(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyInvisibility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyItemProperty(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyKnockdown(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyKnockdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyLight(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyLight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyLimitMovementSpeed(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyLimitMovementSpeed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyLink(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyLink);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyMissChance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyMissChance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyModifyNumAttacks(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyModifyNumAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyMovementSpeedDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyMovementSpeedDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyMovementSpeedIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyMovementSpeedIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyNegativeLevel(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyNegativeLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyPetrify(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyPetrify);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyPoison(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyPoison);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyPolymorph(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyPolymorph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyRacialType(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyRacialType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyRegenerate(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyRegenerate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyResurrection(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyResurrection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySanctuary(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySanctuary);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySavingThrowDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySavingThrowDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySavingThrowIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySavingThrowIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySeeInvisible(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySeeInvisible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySetAIState(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySetAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySetState(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySetState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySetStateInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySetStateInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySilence(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySilence);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySkillDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySkillDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySkillIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySkillIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySlowInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySlowInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpecialWalkAnimation(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpecialWalkAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpellFailure(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpellImmunity(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpellImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpellLevelAbsorption(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpellLevelAbsorption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpellResistanceDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpellResistanceDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySpellResistanceIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySpellResistanceIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySummonCreature(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySummonCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplySwarm(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplySwarm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyTaunt(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyTaunt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyTemporaryHitpoints(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyTemporaryHitpoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyTimestop(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyTimestop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyTrueSeeing(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyTrueSeeing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyTurnResistance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyTurnResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyUltraVision(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyUltraVision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyVampiricRegeneration(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyVampiricRegeneration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyVision(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyVision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyVisualEffect(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnApplyWounding(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnApplyWounding);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnEffectApplied(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnEffectApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSEffectListHandler__OnEffectRemoved(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnEffectRemoved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveAbilityDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveAbilityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveAbilityIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveAbilityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveACDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveACDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveACIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveACIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveArcaneSpellFailure(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveArcaneSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveAreaOfEffect(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveAreaOfEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveAttackDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveAttackDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveAttackIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveAttackIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveBeam(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveBeam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveBlindness(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveBlindness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveBonusFeat(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveBonusFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveBonusSpellOfLevel(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveBonusSpellOfLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveConcealment(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveConcealment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveCurse(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveCurse);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveCutsceneGhost(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveCutsceneGhost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDamageDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDamageDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDamageImmunityDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDamageImmunityDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDamageImmunityIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDamageImmunityIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDamageIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDamageIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDamageShield(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDamageShield);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDarkness(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDarkness);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDisappearAppear(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDisappearAppear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveDisarm(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveDisarm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveEffectIcon(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveEffectIcon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveEffectImmunity(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveEffectImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveEnemyAttackBonus(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveEnemyAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveEntangled(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveEntangled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveHasteInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveHasteInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveHasteOrSlow(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveHasteOrSlow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveHitPointChangeWhenDying(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveHitPointChangeWhenDying);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveInvisibility(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveInvisibility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveItemProperty(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveItemProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveKnockdown(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveKnockdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveLight(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveLight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveLimitMovementSpeed(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveLimitMovementSpeed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveMissChance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveMissChance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveModifyNumAttacks(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveModifyNumAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveMovementSpeedDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveMovementSpeedDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveMovementSpeedIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveMovementSpeedIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveNegativeLevel(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveNegativeLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemovePetrify(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemovePetrify);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemovePolymorph(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemovePolymorph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveRacialType(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveRacialType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSanctuary(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSanctuary);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSavingThrowDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSavingThrowDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSavingThrowIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSavingThrowIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSeeInvisible(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSeeInvisible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSetAIState(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSetAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSetState(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSetState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSetStateInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSetStateInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSilence(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSilence);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSkillDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSkillDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSkillIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSkillIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSlowInternal(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSlowInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpecialWalkAnimation(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpecialWalkAnimation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpellFailure(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpellFailure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpellImmunity(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpellImmunity);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpellLevelAbsorption(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpellLevelAbsorption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpellResistanceDecrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpellResistanceDecrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSpellResistanceIncrease(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSpellResistanceIncrease);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSummonCreature(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSummonCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveSwarm(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveSwarm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveTaunt(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveTaunt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveTemporaryHitpoints(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveTemporaryHitpoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveTimestop(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveTimestop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveTrueSeeing(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveTrueSeeing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveTurnResistance(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveTurnResistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveUltraVision(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveUltraVision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveVision(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveVision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveVisualEffect(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEffectListHandler__OnRemoveWounding(CNWSEffectListHandler* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__OnRemoveWounding);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEffectListHandler__SendFloatyEffect(CNWSEffectListHandler* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEffectListHandler*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEffectListHandler__SendFloatyEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
