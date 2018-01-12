#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CNWSClient.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListTemplatedCLastUpdateObject;
struct CExoLinkedListTemplatedCLastUpdatePartyObject;
struct CLastUpdateObject;
struct CNWSCreature;
struct CNWSItem;
struct CNWSObject;
struct CNWSPlayerCharSheetGUI;
struct CNWSPlayerInventoryGUI;
struct CNWSPlayerJournalQuest;
struct CNWSPlayerLastUpdateObject;
struct CNWSPlayerStoreGUI;
struct CNWSPlayerTURD;

struct CNWSPlayer
    : CNWSClient
{
    CExoLinkedListTemplatedCLastUpdateObject* m_pActiveObjectsLastUpdate;
    CExoLinkedListTemplatedCLastUpdatePartyObject* m_pActivePartyObjectsLastUpdate;
    int32_t m_nAreaTransitionBMP;
    CExoString m_sAreaTransitionName;
    int32_t m_bFloatyEffects;
    int32_t m_nAreas;
    uint32_t* m_pAreas;
    uint8_t m_nLoginState;
    uint32_t m_oidNWSObject;
    uint64_t m_nLastUpdatedTime;
    uint32_t m_oidLastObjectControlled;
    uint32_t m_oidPCObject;
    int32_t m_bIsPrimaryPlayer;
    int32_t m_bFromSaveGame;
    int32_t m_bFromTURD;
    uint32_t m_nPlayerListIndex;
    int32_t m_bPlayModuleListingCharacters;
    CNWSPlayerJournalQuest* m_pJournalQuest;
    CNWSPlayerStoreGUI* m_pStoreGUI;
    CNWSPlayerCharSheetGUI* m_pCharSheetGUI;
    CNWSPlayerInventoryGUI* m_pInventoryGUI;
    CNWSPlayerInventoryGUI* m_pOtherInventoryGUI;
    CNWSPlayerLastUpdateObject* m_pPlayerLUO;
    int32_t m_bAlwaysRun;
    uint8_t m_nCharacterType;
    CResRef m_resFileName;
    int32_t m_bCommunityNameAuthorized;
    int32_t m_bModuleInfoSucceeded;
    uint32_t m_nIFOCharacterIndex;
    int32_t m_bCutsceneState;

    // The below are auto generated stubs.
    CNWSPlayer() = default;
    CNWSPlayer(const CNWSPlayer&) = default;
    CNWSPlayer& operator=(const CNWSPlayer&) = default;

    CNWSPlayer(uint32_t);
    ~CNWSPlayer();
    int32_t AddArea(uint32_t);
    void AddDMAbilities(CNWSCreature*);
    void AllocateAreas(int32_t);
    CNWSPlayer* AsNWSPlayer();
    int32_t BackupServerCharacter(const CExoString&);
    void CleanMyTURDs();
    void ClearPlayerLastUpdateObject();
    void ClearPlayerOnDestroyGame();
    CNWSPlayerLastUpdateObject* CreateNewPlayerLastUpdateObject();
    void DropTURD();
    void EatTURD(CNWSPlayerTURD*);
    int32_t GetCharacterInfoFromIFO(unsigned char&, int32_t*, unsigned char*, uint32_t&);
    CNWSObject* GetGameObject();
    int32_t GetIsAllowedToSave();
    CLastUpdateObject* GetLastUpdateObject(uint32_t);
    CExoString GetPlayerName();
    int32_t HasExpansionPack(unsigned char, int32_t);
    CNWSCreature* LoadCharacterFromIFO(uint32_t, int32_t, int32_t, int32_t, int32_t);
    uint32_t LoadCreatureData(CResRef, CNWSCreature*);
    uint32_t LoadDMCharacter();
    uint32_t LoadLocalCharacter();
    uint32_t LoadServerCharacter(CResRef, int32_t);
    void LoadTURDInfoFromIFO(uint32_t);
    int32_t PackCreatureIntoMessage();
    int32_t PermittedToDisplayCharacterSheet(uint32_t);
    void RestoreCameraSettings();
    int32_t SaveServerCharacter(int32_t);
    void SetAreaTransitionBMP(int32_t, CExoString);
    void SetGameObject(CNWSObject*);
    void StoreCameraSettings();
    void StripAllInvalidItemPropertiesInInventory(CNWSCreature*);
    void StripAllInvalidItemPropertiesOnItem(CNWSItem*);
    uint32_t ValidateCharacter(int32_t*);
    void ValidateCharacter_SetNormalBonusFlags(uint16_t, int32_t&, int32_t&, unsigned char);
};

void CNWSPlayer__CNWSPlayerCtor__0(CNWSPlayer* thisPtr, uint32_t);
void CNWSPlayer__CNWSPlayerDtor__0(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__AddArea(CNWSPlayer* thisPtr, uint32_t);
void CNWSPlayer__AddDMAbilities(CNWSPlayer* thisPtr, CNWSCreature*);
void CNWSPlayer__AllocateAreas(CNWSPlayer* thisPtr, int32_t);
CNWSPlayer* CNWSPlayer__AsNWSPlayer(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__BackupServerCharacter(CNWSPlayer* thisPtr, const CExoString&);
void CNWSPlayer__CleanMyTURDs(CNWSPlayer* thisPtr);
void CNWSPlayer__ClearPlayerLastUpdateObject(CNWSPlayer* thisPtr);
void CNWSPlayer__ClearPlayerOnDestroyGame(CNWSPlayer* thisPtr);
CNWSPlayerLastUpdateObject* CNWSPlayer__CreateNewPlayerLastUpdateObject(CNWSPlayer* thisPtr);
void CNWSPlayer__DropTURD(CNWSPlayer* thisPtr);
void CNWSPlayer__EatTURD(CNWSPlayer* thisPtr, CNWSPlayerTURD*);
int32_t CNWSPlayer__GetCharacterInfoFromIFO(CNWSPlayer* thisPtr, unsigned char&, int32_t*, unsigned char*, uint32_t&);
CNWSObject* CNWSPlayer__GetGameObject(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__GetIsAllowedToSave(CNWSPlayer* thisPtr);
CLastUpdateObject* CNWSPlayer__GetLastUpdateObject(CNWSPlayer* thisPtr, uint32_t);
CExoString CNWSPlayer__GetPlayerName(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__HasExpansionPack(CNWSPlayer* thisPtr, unsigned char, int32_t);
CNWSCreature* CNWSPlayer__LoadCharacterFromIFO(CNWSPlayer* thisPtr, uint32_t, int32_t, int32_t, int32_t, int32_t);
uint32_t CNWSPlayer__LoadCreatureData(CNWSPlayer* thisPtr, CResRef, CNWSCreature*);
uint32_t CNWSPlayer__LoadDMCharacter(CNWSPlayer* thisPtr);
uint32_t CNWSPlayer__LoadLocalCharacter(CNWSPlayer* thisPtr);
uint32_t CNWSPlayer__LoadServerCharacter(CNWSPlayer* thisPtr, CResRef, int32_t);
void CNWSPlayer__LoadTURDInfoFromIFO(CNWSPlayer* thisPtr, uint32_t);
int32_t CNWSPlayer__PackCreatureIntoMessage(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__PermittedToDisplayCharacterSheet(CNWSPlayer* thisPtr, uint32_t);
void CNWSPlayer__RestoreCameraSettings(CNWSPlayer* thisPtr);
int32_t CNWSPlayer__SaveServerCharacter(CNWSPlayer* thisPtr, int32_t);
void CNWSPlayer__SetAreaTransitionBMP(CNWSPlayer* thisPtr, int32_t, CExoString);
void CNWSPlayer__SetGameObject(CNWSPlayer* thisPtr, CNWSObject*);
void CNWSPlayer__StoreCameraSettings(CNWSPlayer* thisPtr);
void CNWSPlayer__StripAllInvalidItemPropertiesInInventory(CNWSPlayer* thisPtr, CNWSCreature*);
void CNWSPlayer__StripAllInvalidItemPropertiesOnItem(CNWSPlayer* thisPtr, CNWSItem*);
uint32_t CNWSPlayer__ValidateCharacter(CNWSPlayer* thisPtr, int32_t*);
void CNWSPlayer__ValidateCharacter_SetNormalBonusFlags(CNWSPlayer* thisPtr, uint16_t, int32_t&, int32_t&, unsigned char);

}

}
