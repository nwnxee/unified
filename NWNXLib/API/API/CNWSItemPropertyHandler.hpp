#pragma once
#include "nwn_api.hpp"
#include "CItemPropertyApplierRemover.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSItemPropertyHandler)
#endif

struct CNWItemProperty;
struct CNWSItem;
struct CNWSObject;
struct CNWSCreature;

typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSItemPropertyHandler : CItemPropertyApplierRemover
{
    typedef int32_t (CNWSItemPropertyHandler::*pfAIPCommands)(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, BOOL);
    pfAIPCommands * m_pApplyItemPropertyCommands;
    typedef int32_t (CNWSItemPropertyHandler::*pfRIPCommands)(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    pfRIPCommands * m_pRemoveItemPropertyCommands;

    ~CNWSItemPropertyHandler();
    void InitializeItemProperties();
    int32_t OnItemPropertyApplied(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t OnItemPropertyRemoved(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot);
    int32_t ApplyEnhancementBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyEnhancementPenalty(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamageBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamagePenalty(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamageReduction(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamageResistance(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamageVulnerability(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDarkVision(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDecreaseAbility(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDecreaseAC(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDecreaseSkill(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyAttackBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyAttackPenalty(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyFreeAction(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyLight(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyACBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyAbilityBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyImprovedSpellResistance(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyHaste(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyHolyAvenger(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplySkillBonus(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyImprovedSavingThrow(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyReducedSavingThrow(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyChangedSavingThrow(CNWSItem *pItem, int32_t nBonus, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, BOOL bLoadingGame);
    int32_t ApplyImprovedSavingThrowVsX(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyReducedSavingThrowVsX(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyChangedSavingThrowVsX(CNWSItem *pItem, int32_t nBonus, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, BOOL bLoadingGame);
    int32_t ApplyUnlimitedAmmo(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t RemoveUnlimitedAmmo(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot );
    int32_t ApplySpecialWalk(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyTrueSeeing(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyImprovedEvasion(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyTurnResistance(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyBonusSpellOfLevel(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t RemoveBonusSpellOfLevel(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot);
    int32_t ApplyBonusFeat(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyDamageImmunity(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyImmunity(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplySpellImmunitySpecific(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplySpellImmunitySchool(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplySpellImmunityLevel(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyRegeneration(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    int32_t ApplyArcaneSpellFailure(CNWSItem *pItem, CNWItemProperty *pItemProperty, CNWSCreature *pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);

#ifdef NWN_CLASS_EXTENSION_CNWSItemPropertyHandler
    NWN_CLASS_EXTENSION_CNWSItemPropertyHandler
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSItemPropertyHandler)
#endif
