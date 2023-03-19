#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CPlayOptions)
#endif



typedef int BOOL;


struct CPlayOptions
{
    BOOL bAllKillable;
    BOOL bNonPartyKillable;
    BOOL bRequireResurrection;
    BOOL bLoseStolenItems;
    BOOL bLoseItems;
    BOOL bLoseExp;
    BOOL bLoseGold;
    int32_t nLoseGoldNum;
    int32_t nLoseExpNum;
    int32_t nLoseItemsNum;
    int32_t nPVPSetting;
    BOOL bPauseAndPlay;
    BOOL bOnePartyOnly;
    BOOL bEnforceLegalCharacters;
    BOOL bItemLevelRestrictions;
    BOOL bCDKeyBanListAllowList;
    BOOL bDisallowShouting;
    BOOL bShowDMJoinMessage;
    BOOL bBackupSavedCharacters;
    BOOL bAutoFailSaveOn1;
    BOOL bValidateSpells;
    BOOL bExamineEffects;
    BOOL bExamineChallengeRating;
    BOOL bUseMaxHitPoints;
    BOOL bRestoreSpellsUses;
    BOOL bResetEncounterSpawnPool;
    BOOL bHideHitPointsGained;
    BOOL bPlayerPartyControl;
    BOOL bShowPlayerJoinMessages;



#ifdef NWN_CLASS_EXTENSION_CPlayOptions
    NWN_CLASS_EXTENSION_CPlayOptions
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CPlayOptions)
#endif

