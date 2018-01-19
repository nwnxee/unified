#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CPlayOptions
{
    int32_t bAllKillable;
    int32_t bNonPartyKillable;
    int32_t bRequireResurrection;
    int32_t bLoseStolenItems;
    int32_t bLoseItems;
    int32_t bLoseExp;
    int32_t bLoseGold;
    int32_t nLoseGoldNum;
    int32_t nLoseExpNum;
    int32_t nLoseItemsNum;
    int32_t nPVPSetting;
    int32_t bPauseAndPlay;
    int32_t bOnePartyOnly;
    int32_t bEnforceLegalCharacters;
    int32_t bItemLevelRestrictions;
    int32_t bCDKeyBanListAllowList;
    int32_t bDisallowShouting;
    int32_t bShowDMJoinMessage;
    int32_t bBackupSavedCharacters;
    int32_t bAutoFailSaveOn1;
    int32_t bValidateSpells;
    int32_t bExamineEffects;
    int32_t bExamineChallengeRating;
    int32_t bUseMaxHitPoints;
    int32_t bRestoreSpellsUses;
    int32_t bResetEncounterSpawnPool;
    int32_t bHideHitPointsGained;
};

}

}
