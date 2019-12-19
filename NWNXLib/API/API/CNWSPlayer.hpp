#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CLastUpdateObject.hpp"
#include "CLastUpdatePartyObject.hpp"
#include "CNWSClient.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayer)
#endif

struct CNWSCreature;
struct CNWSItem;
struct CNWSObject;
struct CNWSPlayerCharSheetGUI;
struct CNWSPlayerInventoryGUI;
struct CNWSPlayerJournalQuest;
struct CNWSPlayerLastUpdateObject;
struct CNWSPlayerStoreGUI;
struct CNWSPlayerTURD;


typedef int BOOL;
typedef uint32_t OBJECT_ID;
typedef uint32_t STRREF;


struct CNWSPlayer : CNWSClient
{
    CExoLinkedList<CLastUpdateObject> * m_pActiveObjectsLastUpdate;
    CExoLinkedList<CLastUpdatePartyObject> * m_pActivePartyObjectsLastUpdate;
    int32_t m_nAreaTransitionBMP;
    CExoString m_sAreaTransitionName;
    BOOL m_bFloatyEffects;
    int32_t m_nAreas;
    OBJECT_ID * m_pAreas;
    uint8_t m_nLoginState;
    OBJECT_ID m_oidNWSObject;
    uint64_t m_nLastUpdatedTime;
    OBJECT_ID m_oidLastObjectControlled;
    OBJECT_ID m_oidPCObject;
    BOOL m_bIsPrimaryPlayer;
    BOOL m_bFromSaveGame;
    BOOL m_bFromTURD;
    uint32_t m_nPlayerListIndex;
    BOOL m_bPlayModuleListingCharacters;
    CNWSPlayerJournalQuest * m_pJournalQuest;
    CNWSPlayerStoreGUI * m_pStoreGUI;
    CNWSPlayerCharSheetGUI * m_pCharSheetGUI;
    CNWSPlayerInventoryGUI * m_pInventoryGUI;
    CNWSPlayerInventoryGUI * m_pOtherInventoryGUI;
    CNWSPlayerLastUpdateObject * m_pPlayerLUO;
    BOOL m_bAlwaysRun;
    uint8_t m_nCharacterType;
    CResRef m_resFileName;
    BOOL m_bCommunityNameAuthorized;
    BOOL m_bModuleInfoSucceeded;
    uint32_t m_nIFOCharacterIndex;
    BOOL m_bCutsceneState;

    CNWSPlayer(uint32_t nPlayerID);
    virtual ~CNWSPlayer();
    void ClearPlayerOnDestroyGame();
    virtual CNWSPlayer * AsNWSPlayer();
    STRREF LoadLocalCharacter();
    STRREF LoadDMCharacter();
    STRREF LoadServerCharacter(CResRef cResRef, BOOL bSubDirChar = false);
    CNWSCreature * LoadCharacterFromIFO(uint32_t nIndex, BOOL bAreaLoaded = true, BOOL bRunPostProcess = true, BOOL bAddObjectToArray = true, BOOL bDoingCharacterCopy = false);
    void LoadTURDInfoFromIFO(uint32_t nIndex);
    BOOL GetCharacterInfoFromIFO(uint8_t & nNumClasses, int32_t * pClasses, uint8_t * pLevels, uint32_t & nXP);
    STRREF LoadCreatureData(CResRef cResRef, CNWSCreature * pCreature);
    BOOL SaveServerCharacter(BOOL bBackupPlayer = false);
    BOOL BackupServerCharacter(const CExoString & sFilename);
    STRREF ValidateCharacter(BOOL * bFailedServerRestriction);
    void ValidateCharacter_SetNormalBonusFlags(uint16_t nFeatID, BOOL & bNormalListFeat, BOOL & bBonusListFeat, uint8_t nClass);
    void StripAllInvalidItemPropertiesInInventory(CNWSCreature * pCreature);
    void StripAllInvalidItemPropertiesOnItem(CNWSItem * pItem);
    void AddDMAbilities(CNWSCreature * pCreature);
    BOOL PackCreatureIntoMessage();
    CNWSObject * GetGameObject();
    void SetGameObject(CNWSObject * pObject);
    CLastUpdateObject * GetLastUpdateObject(OBJECT_ID oidLastUpdateObject);
    void SetAreaTransitionBMP(int32_t nIndex, CExoString sString);
    CExoString GetPlayerName();
    void AllocateAreas(int32_t nAreas);
    BOOL AddArea(OBJECT_ID oidArea);
    BOOL GetIsAllowedToSave();
    void DropTURD();
    void EatTURD(CNWSPlayerTURD * pTURD);
    void CleanMyTURDs();
    CNWSPlayerLastUpdateObject * CreateNewPlayerLastUpdateObject();
    void ClearPlayerLastUpdateObject();
    BOOL PermittedToDisplayCharacterSheet(OBJECT_ID oidCreature);
    BOOL HasExpansionPack(uint8_t nPack, BOOL bOrBetter = true);
    void StoreCameraSettings();
    void RestoreCameraSettings();


#ifdef NWN_CLASS_EXTENSION_CNWSPlayer
    NWN_CLASS_EXTENSION_CNWSPlayer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayer)
#endif

