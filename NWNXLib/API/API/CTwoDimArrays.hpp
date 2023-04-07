#pragma once
#include "nwn_api.hpp"

#include "C2DA.hpp"
#include "CExoLinkedList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTwoDimArrays)
#endif



typedef int BOOL;


struct CTwoDimArrays
{
    C2DA * * m_paIPRPCostTables;
    uint8_t m_nNumIPRPCostTables;
    uint8_t m_lstEpicBaseAttackBonus[60];
    uint8_t m_lstEpicFortificationSaveThrowBonus[60];
    uint8_t m_lstEpicWillSaveThrowBonus[60];
    uint8_t m_lstEpicReflexSaveThrowBonus[60];
    C2DA * m_pAppearanceTable;
    C2DA * m_pGenderTable;
    C2DA * m_pSurfaceMaterialTable;
    C2DA * m_pAreaTransitionTable;
    C2DA * m_pPersistentVisualEffectTable;
    C2DA * m_pCreatureSpeedTable;
    C2DA * m_pDoorTypesTable;
    C2DA * m_pGenericDoorsTable;
    C2DA * m_pPlaceablesTable;
    C2DA * m_pIPRPSpells;
    C2DA * m_pIPRPLightTable;
    C2DA * m_pIPRPColor;
    C2DA * m_pIPRPMelee;
    C2DA * m_pItemPropDefTable;
    C2DA * m_pItemPropsTable;
    C2DA * m_pCreatureSizeTable;
    C2DA * m_pArmorTable;
    C2DA * m_pPortraitTable;
    C2DA * m_pPartTable;
    C2DA * m_pArmorTypesTable;
    C2DA * m_pTileColorTable;
    C2DA * m_pLightColorTable;
    C2DA * m_pReplaceTextureTable;
    C2DA * m_pTailModelTable;
    C2DA * m_pWingModelTable;
    C2DA * m_pCloakModelTable;
    C2DA * m_pCursorTable;
    C2DA * m_pActionsTable;
    C2DA * m_pAmbientMusicTable;
    C2DA * m_pAmbientSoundTable;
    C2DA * m_pFootstepSoundsTable;
    C2DA * m_pAppearanceSoundsTable;
    C2DA * m_pWeaponSoundsTable;
    C2DA * m_pDefaultACSoundsTable;
    C2DA * m_pAmmunitionTypesTable;
    C2DA * m_pKeymapTable;
    C2DA * m_pPlaceableSoundsTable;
    C2DA * m_pDamageLevelTable;
    C2DA * m_pEffectIconsTable;
    C2DA * m_pLoadHintsTable;
    C2DA * m_pSwearFilterTable;
    C2DA * m_pPhenoTypeTable;
    C2DA * m_pIPRPVisualFxTable;
    C2DA * m_pWeatherTypesTable;
    C2DA * m_pProgFxTable;
    C2DA * m_pStateScriptsTable;
    C2DA * m_pVisualEffectTable;
    C2DA * m_pTrapTable;
    C2DA * m_pSpellSchoolTable;
    C2DA * m_pPoisonTable;
    C2DA * m_pDiseaseTable;
    C2DA * m_pRepAdjustmentsTable;
    C2DA * m_pFractionalCRTable;
    C2DA * m_pCategoryTable;
    C2DA * m_pExcitedDurationTable;
    C2DA * m_pRestDurationTable;
    C2DA * m_pEncounterDifficultyTable;
    C2DA * m_pIPRPMonsterDamageTable;
    C2DA * m_pAssociatesAnimalCompanionTable;
    C2DA * m_pAssociatesFamiliarTable;
    C2DA * m_pIPRPDamageTable;
    C2DA * m_pSkillVsItemCostTable;
    C2DA * m_pIPRPBonusCostTable;
    C2DA * m_pIPRPSRCostTable;
    C2DA * m_pIPRPNeg5CostTable;
    C2DA * m_pIPRPArcSpell;
    C2DA * m_pEncumbranceTable;
    C2DA * m_pPartsBelt;
    C2DA * m_pPartsBicep;
    C2DA * m_pPartsChest;
    C2DA * m_pPartsFoot;
    C2DA * m_pPartsForearm;
    C2DA * m_pPartsHand;
    C2DA * m_pPartsLegs;
    C2DA * m_pPartsNeck;
    C2DA * m_pPartsPelvis;
    C2DA * m_pPartsShin;
    C2DA * m_pPartsShoulder;
    C2DA * m_pPartsRobe;
    C2DA * m_pItemValue;
    C2DA * m_pPackages;
    C2DA * m_pRuleset;
    C2DA * m_pDamageTypes;
    C2DA * m_pDamageTypeGroups;
    C2DA * m_pXpBase;
    C2DA * m_pRangesTable;
    C2DA * m_pPolymorphTable;
    C2DA * m_pOnHitTable;
    C2DA * m_pOnHitSpellTable;
    C2DA * m_pOnHitDurationTable;
    C2DA * m_pDamageHitVisualTable;
    C2DA * m_pIPRPACModTypeTable;
    C2DA * m_pIPRPWeightIncTable;
    C2DA * m_pBodyBagTable;
    C2DA * m_pIPRPFeatsTable;
    CExoLinkedList<C2DA> * m_lstCached2DAs;
    uint8_t m_n2daCacheSize;
    CExoLinkedList<C2DA> * m_lstUserCached2DAs;
    uint8_t m_nUser2daCacheSize;

    uint8_t GetEpicFortSaveBonus(uint8_t nLevel);
    uint8_t GetEpicRefSaveBonus(uint8_t nLevel);
    uint8_t GetEpicWillSaveBonus(uint8_t nLevel);
    uint8_t GetEpicAttackBonus(uint8_t nLevel);
    CTwoDimArrays();
    ~CTwoDimArrays();
    BOOL Load2DArrays();
    BOOL UnLoad2DArrays();
    C2DA * GetCached2DA(const CExoString s2DAName, BOOL bUpdateUser2daCache = false);
    void ClearCached2DAs();
    C2DA * GetIPRPCostTable(uint8_t nCostTable);
    BOOL LoadIPRPCostTables();
    BOOL UnLoadIPRPCostTables();
    BOOL LoadEpicSaves();
    BOOL LoadEpicAttacks();
    void Update2DACache(CExoLinkedList<C2DA> * lstCached2DAs, int32_t nMaxCacheSize, C2DA * p2DA);


#ifdef NWN_CLASS_EXTENSION_CTwoDimArrays
    NWN_CLASS_EXTENSION_CTwoDimArrays
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTwoDimArrays)
#endif

