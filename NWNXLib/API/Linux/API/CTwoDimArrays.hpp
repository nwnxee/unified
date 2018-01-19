#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct C2DA;
struct CExoLinkedListTemplatedC2DA;

struct CTwoDimArrays
{
    C2DA** m_paIPRPCostTables;
    uint8_t m_nNumIPRPCostTables;
    uint8_t m_lstEpicBaseAttackBonus[60];
    uint8_t m_lstEpicFortificationSaveThrowBonus[60];
    uint8_t m_lstEpicWillSaveThrowBonus[60];
    uint8_t m_lstEpicReflexSaveThrowBonus[60];
    C2DA* m_pAppearanceTable;
    C2DA* m_pGenderTable;
    C2DA* m_pSurfaceMaterialTable;
    C2DA* m_pAreaTransitionTable;
    C2DA* m_pPersistentVisualEffectTable;
    C2DA* m_pCreatureSpeedTable;
    C2DA* m_pDoorTypesTable;
    C2DA* m_pGenericDoorsTable;
    C2DA* m_pPlaceablesTable;
    C2DA* m_pIPRPSpells;
    C2DA* m_pIPRPLightTable;
    C2DA* m_pIPRPColor;
    C2DA* m_pIPRPMelee;
    C2DA* m_pItemPropDefTable;
    C2DA* m_pItemPropsTable;
    C2DA* m_pCreatureSizeTable;
    C2DA* m_pArmorTable;
    C2DA* m_pPortraitTable;
    C2DA* m_pPartTable;
    C2DA* m_pArmorTypesTable;
    C2DA* m_pTileColorTable;
    C2DA* m_pLightColorTable;
    C2DA* m_pReplaceTextureTable;
    C2DA* m_pTailModelTable;
    C2DA* m_pWingModelTable;
    C2DA* m_pCloakModelTable;
    C2DA* m_pCursorTable;
    C2DA* m_pActionsTable;
    C2DA* m_pAmbientMusicTable;
    C2DA* m_pAmbientSoundTable;
    C2DA* m_pFootstepSoundsTable;
    C2DA* m_pAppearanceSoundsTable;
    C2DA* m_pWeaponSoundsTable;
    C2DA* m_pDefaultACSoundsTable;
    C2DA* m_pAmmunitionTypesTable;
    C2DA* m_pKeymapTable;
    C2DA* m_pPlaceableSoundsTable;
    C2DA* m_pDamageLevelTable;
    C2DA* m_pEffectIconsTable;
    C2DA* m_pLoadHintsTable;
    C2DA* m_pSwearFilterTable;
    C2DA* m_pPhenoTypeTable;
    C2DA* m_pStateScriptsTable;
    C2DA* m_pVisualEffectTable;
    C2DA* m_pTrapTable;
    C2DA* m_pSpellSchoolTable;
    C2DA* m_pPoisonTable;
    C2DA* m_pDiseaseTable;
    C2DA* m_pRepAdjustmentsTable;
    C2DA* m_pFractionalCRTable;
    C2DA* m_pCategoryTable;
    C2DA* m_pExcitedDurationTable;
    C2DA* m_pRestDurationTable;
    C2DA* m_pEncounterDifficultyTable;
    C2DA* m_pIPRPMonsterDamageTable;
    C2DA* m_pAssociatesAnimalCompanionTable;
    C2DA* m_pAssociatesFamiliarTable;
    C2DA* m_pIPRPDamageTable;
    C2DA* m_pSkillVsItemCostTable;
    C2DA* m_pIPRPBonusCostTable;
    C2DA* m_pIPRPSRCostTable;
    C2DA* m_pIPRPNeg5CostTable;
    C2DA* m_pIPRPArcSpell;
    C2DA* m_pEncumbranceTable;
    C2DA* m_pPartsBelt;
    C2DA* m_pPartsBicep;
    C2DA* m_pPartsChest;
    C2DA* m_pPartsFoot;
    C2DA* m_pPartsForearm;
    C2DA* m_pPartsHand;
    C2DA* m_pPartsLegs;
    C2DA* m_pPartsNeck;
    C2DA* m_pPartsPelvis;
    C2DA* m_pPartsShin;
    C2DA* m_pPartsShoulder;
    C2DA* m_pPartsRobe;
    C2DA* m_pItemValue;
    C2DA* m_pPackages;
    C2DA* m_pXpBase;
    C2DA* m_pRangesTable;
    C2DA* m_pPolymorphTable;
    C2DA* m_pOnHitTable;
    C2DA* m_pOnHitSpellTable;
    C2DA* m_pOnHitDurationTable;
    C2DA* m_pDamageHitVisualTable;
    C2DA* m_pIPRPACModTypeTable;
    C2DA* m_pIPRPWeightIncTable;
    C2DA* m_pBodyBagTable;
    C2DA* m_pIPRPFeatsTable;
    CExoLinkedListTemplatedC2DA* m_lstCached2DAs;
    uint8_t m_n2daCacheSize;
    CExoLinkedListTemplatedC2DA* m_lstUserCached2DAs;
    uint8_t m_nUser2daCacheSize;

    // The below are auto generated stubs.
    CTwoDimArrays(const CTwoDimArrays&) = default;
    CTwoDimArrays& operator=(const CTwoDimArrays&) = default;

    CTwoDimArrays();
    ~CTwoDimArrays();
    void ClearCached2DAs();
    C2DA* GetCached2DA(CExoString, int32_t);
    unsigned char GetEpicAttackBonus(unsigned char);
    unsigned char GetEpicFortSaveBonus(unsigned char);
    unsigned char GetEpicRefSaveBonus(unsigned char);
    unsigned char GetEpicWillSaveBonus(unsigned char);
    C2DA* GetIPRPCostTable(unsigned char);
    int32_t Load2DArrays();
    int32_t LoadEpicAttacks();
    int32_t LoadEpicSaves();
    int32_t LoadIPRPCostTables();
    int32_t UnLoad2DArrays();
    int32_t UnLoadIPRPCostTables();
    void Update2DACache(CExoLinkedListTemplatedC2DA*, int32_t, C2DA*);
};

void CTwoDimArrays__CTwoDimArraysCtor(CTwoDimArrays* thisPtr);
void CTwoDimArrays__CTwoDimArraysDtor(CTwoDimArrays* thisPtr);
void CTwoDimArrays__ClearCached2DAs(CTwoDimArrays* thisPtr);
C2DA* CTwoDimArrays__GetCached2DA(CTwoDimArrays* thisPtr, CExoString, int32_t);
unsigned char CTwoDimArrays__GetEpicAttackBonus(CTwoDimArrays* thisPtr, unsigned char);
unsigned char CTwoDimArrays__GetEpicFortSaveBonus(CTwoDimArrays* thisPtr, unsigned char);
unsigned char CTwoDimArrays__GetEpicRefSaveBonus(CTwoDimArrays* thisPtr, unsigned char);
unsigned char CTwoDimArrays__GetEpicWillSaveBonus(CTwoDimArrays* thisPtr, unsigned char);
C2DA* CTwoDimArrays__GetIPRPCostTable(CTwoDimArrays* thisPtr, unsigned char);
int32_t CTwoDimArrays__Load2DArrays(CTwoDimArrays* thisPtr);
int32_t CTwoDimArrays__LoadEpicAttacks(CTwoDimArrays* thisPtr);
int32_t CTwoDimArrays__LoadEpicSaves(CTwoDimArrays* thisPtr);
int32_t CTwoDimArrays__LoadIPRPCostTables(CTwoDimArrays* thisPtr);
int32_t CTwoDimArrays__UnLoad2DArrays(CTwoDimArrays* thisPtr);
int32_t CTwoDimArrays__UnLoadIPRPCostTables(CTwoDimArrays* thisPtr);
void CTwoDimArrays__Update2DACache(CTwoDimArrays* thisPtr, CExoLinkedListTemplatedC2DA*, int32_t, C2DA*);

}

}
