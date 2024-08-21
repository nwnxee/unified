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
    enum TwoDAIndex {
        TwoDA_AppearanceTable,
        TwoDA_GenderTable,
        TwoDA_SurfaceMaterialTable,
        TwoDA_AreaTransitionTable,
        TwoDA_PersistentVisualEffectTable,
        TwoDA_CreatureSpeedTable,
        TwoDA_DoorTypesTable,
        TwoDA_GenericDoorsTable,
        TwoDA_PlaceablesTable,

        TwoDA_IPRPSpells,
        TwoDA_IPRPLightTable,
        TwoDA_IPRPColor,
        TwoDA_IPRPMelee,
        TwoDA_ItemPropDefTable,
        TwoDA_ItemPropsTable,

        TwoDA_CreatureSizeTable,

        TwoDA_ArmorTable,

        TwoDA_PortraitTable,

        TwoDA_SavingThrowTypesTable,
        TwoDA_IPRPSaveElementTable,

        // client only
        TwoDA_PartTable,
        TwoDA_ArmorTypesTable,
        TwoDA_TileColorTable,
        TwoDA_LightColorTable,
        TwoDA_ReplaceTextureTable,
        TwoDA_TailModelTable,
        TwoDA_WingModelTable,
        TwoDA_CloakModelTable,
        TwoDA_CursorTable,
        TwoDA_ActionsTable,
        TwoDA_AmbientMusicTable,
        TwoDA_AmbientSoundTable,
        TwoDA_FootstepSoundsTable,
        TwoDA_AppearanceSoundsTable,
        TwoDA_WeaponSoundsTable,
        TwoDA_DefaultACSoundsTable,
        TwoDA_AmmunitionTypesTable,
        TwoDA_KeymapTable,
        TwoDA_PlaceableSoundsTable,
        TwoDA_DamageLevelTable,
        TwoDA_EffectIconsTable,
        TwoDA_LoadHintsTable,
        TwoDA_SwearFilterTable,
        TwoDA_PhenoTypeTable,
        TwoDA_IPRPVisualFxTable,
        TwoDA_WeatherTypesTable,
        TwoDA_ProgFxTable,

        // server only
        TwoDA_StateScriptsTable,
        TwoDA_VisualEffectTable,
        TwoDA_TrapTable,
        TwoDA_SpellSchoolTable,
        TwoDA_PoisonTable,
        TwoDA_DiseaseTable,
        TwoDA_RepAdjustmentsTable,
        TwoDA_FractionalCRTable,
        TwoDA_CategoryTable,
        TwoDA_ExcitedDurationTable,
        TwoDA_RestDurationTable,
        TwoDA_EncounterDifficultyTable,
        TwoDA_IPRPMonsterDamageTable,
        TwoDA_AssociatesAnimalCompanionTable,
        TwoDA_AssociatesFamiliarTable,
        TwoDA_IPRPDamageTable,
        TwoDA_SkillVsItemCostTable,
        TwoDA_IPRPBonusCostTable,
        TwoDA_IPRPSRCostTable,
        TwoDA_IPRPNeg5CostTable,
        TwoDA_IPRPArcSpell,
        TwoDA_EncumbranceTable,

        TwoDA_PartsBelt,
        TwoDA_PartsBicep,
        TwoDA_PartsChest,
        TwoDA_PartsFoot,
        TwoDA_PartsForearm,
        TwoDA_PartsHand,
        TwoDA_PartsLegs,
        TwoDA_PartsNeck,
        TwoDA_PartsPelvis,
        TwoDA_PartsShin,
        TwoDA_PartsShoulder,
        TwoDA_PartsRobe,
        TwoDA_ItemValue,
        TwoDA_Packages,
        TwoDA_Ruleset,
        TwoDA_DamageTypes,
        TwoDA_DamageTypeGroups,

        TwoDA_XpBase,

        TwoDA_RangesTable,

        TwoDA_PolymorphTable,

        TwoDA_OnHitTable,
        TwoDA_OnHitSpellTable,
        TwoDA_OnHitDurationTable,

        TwoDA_DamageHitVisualTable,

        TwoDA_IPRPACModTypeTable,

        TwoDA_IPRPWeightIncTable,

        TwoDA_BodyBagTable,

        TwoDA_IPRPFeatsTable,

        TWODA_COUNT // Keep this last
    };
    C2DA *m_p2DAs[TWODA_COUNT];
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

    inline C2DA * GetAppearanceTable()                 { return m_p2DAs[TwoDA_AppearanceTable]; }
    inline C2DA * GetGenderTable()                     { return m_p2DAs[TwoDA_GenderTable]; }
    inline C2DA * GetSurfaceMaterialTable()            { return m_p2DAs[TwoDA_SurfaceMaterialTable]; }
    inline C2DA * GetVisualEffectTable()               { return m_p2DAs[TwoDA_VisualEffectTable]; }
    inline C2DA * GetPersistentVisualEffectTable()     { return m_p2DAs[TwoDA_PersistentVisualEffectTable]; }
    inline C2DA * GetCreatureSpeedTable()              { return m_p2DAs[TwoDA_CreatureSpeedTable]; }
    inline C2DA * GetDoorTypesTable()                  { return m_p2DAs[TwoDA_DoorTypesTable]; }
    inline C2DA * GetGenericDoorsTable()               { return m_p2DAs[TwoDA_GenericDoorsTable]; }
    inline C2DA * GetPlaceablesTable()                 { return m_p2DAs[TwoDA_PlaceablesTable]; }
    inline C2DA * GetAreaTransitionTable()             { return m_p2DAs[TwoDA_AreaTransitionTable]; }
    inline C2DA * GetIPRPSpells()                      { return m_p2DAs[TwoDA_IPRPSpells]; }
    inline C2DA * GetLightTable()                      { return m_p2DAs[TwoDA_IPRPLightTable]; }
    inline C2DA * GetIPRPColor()                       { return m_p2DAs[TwoDA_IPRPColor]; }
    inline C2DA * GetIPRPMelee()                       { return m_p2DAs[TwoDA_IPRPMelee]; }
    inline C2DA * GetItemPropDefTable()                { return m_p2DAs[TwoDA_ItemPropDefTable]; }
    inline C2DA * GetItemPropsTable()                  { return m_p2DAs[TwoDA_ItemPropsTable]; }
    inline C2DA * GetCreatureSizeTable()               { return m_p2DAs[TwoDA_CreatureSizeTable]; }
    inline C2DA * GetArmorTable()                      { return m_p2DAs[TwoDA_ArmorTable]; }
    inline C2DA * GetEncumbranceTable()                { return m_p2DAs[TwoDA_EncumbranceTable]; }
    inline C2DA * GetPortraitTable()                   { return m_p2DAs[TwoDA_PortraitTable]; }
    inline C2DA * GetPartsChest()                      { return m_p2DAs[TwoDA_PartsChest]; }
    inline C2DA * GetSpellSchoolTable()                { return m_p2DAs[TwoDA_SpellSchoolTable]; }
    inline C2DA * GetTrapTable()                       { return m_p2DAs[TwoDA_TrapTable]; }
    inline C2DA * GetLightColorTable()                 { return m_p2DAs[TwoDA_LightColorTable]; }
    inline C2DA * GetDamageTable()                     { return m_p2DAs[TwoDA_IPRPDamageTable]; }
    inline C2DA * GetPartsRobe()                       { return m_p2DAs[TwoDA_PartsRobe]; }
    inline C2DA * GetItemValueTable()                  { return m_p2DAs[TwoDA_ItemValue]; }
    inline C2DA * GetPackagesTable()                   { return m_p2DAs[TwoDA_Packages]; }
    inline C2DA * GetRulesetTable()                    { return m_p2DAs[TwoDA_Ruleset]; }
    inline C2DA * GetDamageTypesTable()                { return m_p2DAs[TwoDA_DamageTypes]; }
    inline C2DA * GetDamageTypeGroupsTable()           { return m_p2DAs[TwoDA_DamageTypeGroups]; }
    inline C2DA * GetSavingThrowTypesTable()           { return m_p2DAs[TwoDA_SavingThrowTypesTable]; }
    inline C2DA * GetIPRPSaveElementTable()            { return m_p2DAs[TwoDA_IPRPSaveElementTable]; }
    inline C2DA * GetPartTable()                       { return m_p2DAs[TwoDA_PartTable]; }
    inline C2DA * GetArmorTypesTable()                 { return m_p2DAs[TwoDA_ArmorTypesTable]; }
    inline C2DA * GetTileColorTable()                  { return m_p2DAs[TwoDA_TileColorTable]; }
    inline C2DA * GetReplaceTextureTable()             { return m_p2DAs[TwoDA_ReplaceTextureTable]; }
    inline C2DA * GetTailModelTable()                  { return m_p2DAs[TwoDA_TailModelTable]; }
    inline C2DA * GetWingModelTable()                  { return m_p2DAs[TwoDA_WingModelTable]; }
    inline C2DA * GetCloakModelTable()                 { return m_p2DAs[TwoDA_CloakModelTable]; }
    inline C2DA * GetCursorTable()                     { return m_p2DAs[TwoDA_CursorTable]; }
    inline C2DA * GetActionsTable()                    { return m_p2DAs[TwoDA_ActionsTable]; }
    inline C2DA * GetAmbientMusicTable()               { return m_p2DAs[TwoDA_AmbientMusicTable]; }
    inline C2DA * GetAmbientSoundTable()               { return m_p2DAs[TwoDA_AmbientSoundTable]; }
    inline C2DA * GetFootstepSoundsTable()             { return m_p2DAs[TwoDA_FootstepSoundsTable]; }
    inline C2DA * GetAppearanceSoundsTable()           { return m_p2DAs[TwoDA_AppearanceSoundsTable]; }
    inline C2DA * GetWeaponSoundsTable()               { return m_p2DAs[TwoDA_WeaponSoundsTable]; }
    inline C2DA * GetDefaultACSoundsTable()            { return m_p2DAs[TwoDA_DefaultACSoundsTable]; }
    inline C2DA * GetAmmunitionTypesTable()            { return m_p2DAs[TwoDA_AmmunitionTypesTable]; }
    inline C2DA * GetKeymapTable()                     { return m_p2DAs[TwoDA_KeymapTable]; }
    inline C2DA * GetPlaceableSoundsTable()            { return m_p2DAs[TwoDA_PlaceableSoundsTable]; }
    inline C2DA * GetDamageLevelTable( )               { return m_p2DAs[TwoDA_DamageLevelTable]; }
    inline C2DA * GetEffectIconsTable( )               { return m_p2DAs[TwoDA_EffectIconsTable]; }
    inline C2DA * GetLoadHintsTable( )                 { return m_p2DAs[TwoDA_LoadHintsTable]; }
    inline C2DA * GetSwearFilterTable( )               { return m_p2DAs[TwoDA_SwearFilterTable]; }
    inline C2DA * GetPhenoTypeTable( )                 { return m_p2DAs[TwoDA_PhenoTypeTable]; }
    inline C2DA * GetIPRPVisualFxTable( )              { return m_p2DAs[TwoDA_IPRPVisualFxTable]; }
    inline C2DA * GetWeatherTypesTable( )              { return m_p2DAs[TwoDA_WeatherTypesTable]; }
    inline C2DA * GetProgFxTable( )                    { return m_p2DAs[TwoDA_ProgFxTable]; }
    inline C2DA * GetStateScriptsTable()               { return m_p2DAs[TwoDA_StateScriptsTable]; }
    inline C2DA * GetPoisonTable()                     { return m_p2DAs[TwoDA_PoisonTable]; }
    inline C2DA * GetDiseaseTable()                    { return m_p2DAs[TwoDA_DiseaseTable]; }
    inline C2DA * GetRepAdjustmentsTable()             { return m_p2DAs[TwoDA_RepAdjustmentsTable]; }
    inline C2DA * GetFractionalCRTable()               { return m_p2DAs[TwoDA_FractionalCRTable]; }
    inline C2DA * GetEncounterDifficultyTable()        { return m_p2DAs[TwoDA_EncounterDifficultyTable]; }
    inline C2DA * GetCategoryTable()                   { return m_p2DAs[TwoDA_CategoryTable]; }
    inline C2DA * GetExcitedDurationTable()            { return m_p2DAs[TwoDA_ExcitedDurationTable]; }
    inline C2DA * GetRestDurationTable()               { return m_p2DAs[TwoDA_RestDurationTable]; }
    inline C2DA * GetPartsBelt()                       { return m_p2DAs[TwoDA_PartsBelt]; }
    inline C2DA * GetPartsBicep()                      { return m_p2DAs[TwoDA_PartsBicep]; }
    inline C2DA * GetPartsFoot()                       { return m_p2DAs[TwoDA_PartsFoot]; }
    inline C2DA * GetPartsForearm()                    { return m_p2DAs[TwoDA_PartsForearm]; }
    inline C2DA * GetPartsHand()                       { return m_p2DAs[TwoDA_PartsHand]; }
    inline C2DA * GetPartsLegs()                       { return m_p2DAs[TwoDA_PartsLegs]; }
    inline C2DA * GetPartsNeck()                       { return m_p2DAs[TwoDA_PartsNeck]; }
    inline C2DA * GetPartsPelvis()                     { return m_p2DAs[TwoDA_PartsPelvis]; }
    inline C2DA * GetPartsShin()                       { return m_p2DAs[TwoDA_PartsShin]; }
    inline C2DA * GetPartsShoulder()                   { return m_p2DAs[TwoDA_PartsShoulder]; }
    inline C2DA * GetXpBase()                          { return m_p2DAs[TwoDA_XpBase]; }
    inline C2DA * GetAssociatesAnimalCompanionTable()  { return m_p2DAs[TwoDA_AssociatesAnimalCompanionTable]; }
    inline C2DA * GetAssociatesFamiliarTable()         { return m_p2DAs[TwoDA_AssociatesFamiliarTable]; }
    inline C2DA * GetSkillVsItemCostTable()            { return m_p2DAs[TwoDA_SkillVsItemCostTable]; }
    inline C2DA * GetRangesTable()                     { return m_p2DAs[TwoDA_RangesTable]; }
    inline C2DA * GetPolymorphTable()                  { return m_p2DAs[TwoDA_PolymorphTable]; }
    inline C2DA * GetDamageHitVisualTable()            { return m_p2DAs[TwoDA_DamageHitVisualTable]; }
    inline C2DA * GetBodyBagTable()                    { return m_p2DAs[TwoDA_BodyBagTable]; }
    inline C2DA * GetIPRPFeatsTable()                  { return m_p2DAs[TwoDA_IPRPFeatsTable]; }
    inline C2DA * GetMonsterDamageTable()              { return m_p2DAs[TwoDA_IPRPMonsterDamageTable]; }
    inline C2DA * GetOnHitTable()                      { return m_p2DAs[TwoDA_OnHitTable]; }
    inline C2DA * GetOnHitSpellTable()                 { return m_p2DAs[TwoDA_OnHitSpellTable]; }
    inline C2DA * GetOnHitDurationTable()              { return m_p2DAs[TwoDA_OnHitDurationTable]; }
    inline C2DA * GetACModTypeTable()                  { return m_p2DAs[TwoDA_IPRPACModTypeTable]; }
    inline C2DA * GetWeightIncTable()                  { return m_p2DAs[TwoDA_IPRPWeightIncTable]; }
    inline C2DA * GetArcaneSpellFailureTable()         { return m_p2DAs[TwoDA_IPRPArcSpell]; }
    inline C2DA * GetItemPropBonusCostTable()          { return m_p2DAs[TwoDA_IPRPBonusCostTable]; }
    inline C2DA * GetItemPropSRTable()                 { return m_p2DAs[TwoDA_IPRPSRCostTable]; }
    inline C2DA * GetItemPropNeg5CostTable()           { return m_p2DAs[TwoDA_IPRPNeg5CostTable]; }


#ifdef NWN_CLASS_EXTENSION_CTwoDimArrays
    NWN_CLASS_EXTENSION_CTwoDimArrays
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTwoDimArrays)
#endif

