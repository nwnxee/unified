#pragma once
#include "nwn_api.hpp"

#include "CGameEffectApplierRemover.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSEffectListHandler)
#endif

struct CGameEffect;
struct CNWSObject;



typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSEffectListHandler : CGameEffectApplierRemover
{
    typedef int32_t (CNWSEffectListHandler::*pfAECommands)(CNWSObject *, CGameEffect *, BOOL);
    pfAECommands * m_pApplyEffectCommands;
    typedef int32_t (CNWSEffectListHandler::*pfRECommands)(CNWSObject *, CGameEffect *);
    pfRECommands * m_pRemoveEffectCommands;

    ~CNWSEffectListHandler();
    void InitializeEffects();
    int32_t OnEffectApplied(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnEffectRemoved(CNWSObject * pObject, CGameEffect * pEffect);
    void SendFloatyEffect(uint32_t nStrRef, OBJECT_ID oTarget);
    int32_t OnApplyEffectIcon(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveEffectIcon(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyPoison(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDisease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyRegenerate(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDamageReduction(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDamageResistance(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyLimitMovementSpeed(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveLimitMovementSpeed(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyHitPointChangeWhenDying(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveHitPointChangeWhenDying(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpecialWalkAnimation(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpecialWalkAnimation(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyItemProperty(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveItemProperty(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyCutsceneGhost(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveCutsceneGhost(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySetAIState(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSetAIState(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDamage(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyHeal(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDeath(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyResurrection(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplySummonCreature(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSummonCreature(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDispelAllMagic(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDispelBestMagic(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyAbilityIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveAbilityIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyAbilityDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveAbilityDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySavingThrowIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSavingThrowIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySavingThrowDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSavingThrowDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyACIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveACIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyACDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveACDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyAttackIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveAttackIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyAttackDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveAttackDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDamageIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDamageIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDamageDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDamageDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTemporaryHitpoints(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTemporaryHitpoints(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDamageImmunityIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDamageImmunityIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDamageImmunityDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDamageImmunityDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyEnemyAttackBonus(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveEnemyAttackBonus(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyArcaneSpellFailure(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveArcaneSpellFailure(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyMovementSpeedIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveMovementSpeedIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyMovementSpeedDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveMovementSpeedDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpellResistanceIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpellResistanceIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpellResistanceDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpellResistanceDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyModifyNumAttacks(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveModifyNumAttacks(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyConcealment(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveConcealment(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyMissChance(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveMissChance(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySkillIncrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSkillIncrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySkillDecrease(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSkillDecrease(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTurnResistance(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTurnResistance(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyLink(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyEntangled(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveEntangled(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDeaf(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyEffectImmunity(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveEffectImmunity(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySetState(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSetState(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySetStateInternal(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSetStateInternal(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyHasteOrSlow(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveHasteOrSlow(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyHasteInternal(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveHasteInternal(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySlowInternal(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSlowInternal(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyCurse(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveCurse(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySilence(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSilence(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpellImmunity(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpellImmunity(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpellLevelAbsorption(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpellLevelAbsorption(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTaunt(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTaunt(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyRacialType(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveRacialType(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyBonusSpellOfLevel(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveBonusSpellOfLevel(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyNegativeLevel(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveNegativeLevel(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyPetrify(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemovePetrify(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyCutsceneImmobile(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    //int32_t OnRemoveCutsceneImmobile(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDefensiveStance(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    //int32_t OnRemoveDefensiveStance(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyKnockdown(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveKnockdown(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDisarm(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDisarm(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyWounding(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveWounding(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyVampiricRegeneration(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyVisualEffect(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveVisualEffect(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyAreaOfEffect(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveAreaOfEffect(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyBeam(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveBeam(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyLight(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveLight(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyVision(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveVision(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyInvisibility(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveInvisibility(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySanctuary(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSanctuary(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySeeInvisible(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSeeInvisible(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyUltraVision(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveUltraVision(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTrueSeeing(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTrueSeeing(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyBlindness(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveBlindness(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyBlindnessInactive(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDarkness(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDarkness(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDisappearAppear(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDisappearAppear(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyDisappear(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyAppear(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnApplyDamageShield(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveDamageShield(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyPolymorph(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemovePolymorph(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTimestop(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTimestop(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyBonusFeat(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveBonusFeat(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySwarm(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSwarm(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplySpellFailure(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveSpellFailure(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyRunScript(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveRunScript(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyPacify(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemovePacify(CNWSObject * pObject, CGameEffect * pEffect);
    int32_t OnApplyTimeStopImmunity(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame = false);
    int32_t OnRemoveTimeStopImmunity(CNWSObject * pObject, CGameEffect * pEffect);

    BOOL CheckEffectAppliesToObject(CNWSObject * pObject, CGameEffect * pEffect, BOOL bLoadingGame, BOOL bCheckDyingState = false);

#ifdef NWN_CLASS_EXTENSION_CNWSEffectListHandler
    NWN_CLASS_EXTENSION_CNWSEffectListHandler
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSEffectListHandler)
#endif

