#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CNWSClient.hpp"
#include "CResRef.hpp"
#include "NWSyncAdvertisement.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerExoAppInternal)
#endif

struct C2DA;
struct CCampaignDB;
struct CConnectionLib;
struct CFactionManager;
struct CGameObject;
struct CGameObjectArray;
struct CNWPlaceMeshManager;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSCreature;
struct CNWSDoor;
struct CNWSEncounter;
struct CNWSItem;
struct CNWSMessage;
struct CNWSModule;
struct CNWSObject;
struct CNWSPlaceable;
struct CNWSPlayer;
struct CNWSSoundObject;
struct CNWSStore;
struct CNWSTrigger;
struct CNWSWaypoint;
struct CNWVirtualMachineCommands;
struct CNetLayer;
struct CServerAIMaster;
struct CServerInfo;
struct CWorldTimer;
struct SSubNetProfile;

namespace NWSync {
struct Advertisement; // NWSyncAdvertisement
}
struct AdvertLUT {
    std::unordered_map<CExoString, std::vector<void*>> m_map;
};

typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;
typedef uint32_t OBJECT_ID;
typedef uint16_t RESTYPE;
typedef uint32_t STRREF;


struct CServerExoAppInternal
{
    uint8_t ScratchMessageBuffer[65536];
    BOOL m_bMultiplayerEnabled;
    BOOL m_bGameSpyEnabled;
    BOOL m_bCDResponseReceived;
    CServerInfo * m_pServerInfo;
    int16_t m_nServerMode;
    CNWVirtualMachineCommands * m_pVirtualMachineCommandImplementer;
    CNWSMessage * m_pMessage;
    BOOL m_bForceUpdate;
    uint32_t * m_pPendingAuthorization;
    CExoArrayList<OBJECT_ID> m_lstClientDisconnectPending;
    uint64_t m_nShutdownTimer;
    uint64_t m_nShutdownTimeStamp;
    uint64_t m_nShutdownMaxTimeLocalLogins;
    BOOL m_bReloadModuleWhenEmpty;
    CExoString m_sLastModuleLoadedFilename;
    BOOL m_bLastModuleLoadedWasSaveGame;
    BOOL m_bConnectionLoopFirstRun;
    CNetLayer * m_pNetLayer;
    CServerAIMaster * m_pServerAIMaster;
    CWorldTimer * m_pWorldTimer;
    CWorldTimer * m_pTimestopTimer;
    CWorldTimer * m_pPauseTimer;
    CFactionManager * m_pFactionManager;
    CConnectionLib * m_pConnectionLib;
    CCampaignDB * m_pCampaignDB;
    CGameObjectArray * m_pGameObjArray;
    OBJECT_ID m_oidModule;
    CExoLinkedList<CNWSClient> * m_pNWSPlayerList;
    CExoLinkedList<CNWSClient> * m_pNWSSysAdminList;
    CNWPlaceMeshManager * m_pPlaceMeshManager;
    BOOL m_bDebugMode;
    CExoArrayList<OBJECT_ID> * m_lstPauseExclusionList;
    CExoArrayList<OBJECT_ID> * m_lstTimestopExclusionList;
    uint8_t m_nPauseState;
    BOOL m_bDoingStartNewModule;
    BOOL m_bMoveToModulePending;
    CExoString m_sMoveToModuleString;
    BOOL m_bEndGamePending;
    CExoString m_sEndGameMovie;
    BOOL m_bLoadingModule;
    BOOL m_bImportingChar;
    BOOL m_bAutoSavePending;
    BOOL m_bDisableAutoSave;
    BOOL m_bExportCharacterPending;
    CExoArrayList<OBJECT_ID> m_exportPlayerCharacterRequests;
    BOOL m_bNeedSinglePlayerCharacter;
    uint32_t m_nEstimatedSaveSize;
    uint64_t m_nLogHeartbeatTimer;
    uint64_t m_nLogHeartbeatTimeStamp;
    CExoArrayList<uint32_t> m_nCharListRequests;
    CExoArrayList<CExoString> m_lstBannedListIP;
    CExoArrayList<CExoString> m_lstBannedListCDKey;
    CExoArrayList<CExoString> m_lstBannedListPlayerName;
    C2DA * m_pOldServerVault2DA;
    C2DA * m_pKnownServerNames2DA;
    uint16_t m_nBannedListsTimeStampSecond;
    uint16_t m_nBannedListsTimeStampMinute;
    uint16_t m_nBannedListsTimeStampHour;
    uint32_t m_nBannedListsTimeStamp;
    CExoLinkedListPosition m_posPCObject;
    uint64_t m_nAutoSaveTimer;
    CExoArrayList<SSubNetProfile *> m_acSubNetProfiles;
    uint64_t m_nTotalSubNetSent;
    uint64_t m_nTotalSubNetRecv;
    uint64_t m_nServerStartupTime;
    BOOL m_nEnableSubNetProfiling;
    BOOL m_bHeartBeatLoggingEnabled;
    BOOL m_bCreatureDeathLoggingEnabled;
    uint32_t m_nClientsRequiredToDisableCPUSleep;
    BOOL m_bStickyCombatModesEnabled;
    int32_t m_AttackBonusLimit;
    int32_t m_DamageBonusLimit;
    int32_t m_SavingThrowBonusLimit;
    int32_t m_AbilityBonusLimit;
    int32_t m_AbilityPenaltyLimit;
    int32_t m_SkillBonusLimit;
    int32_t m_AttackBonusLimitModule;
    int32_t m_DamageBonusLimitModule;
    int32_t m_SavingThrowBonusLimitModule;
    int32_t m_AbilityBonusLimitModule;
    int32_t m_AbilityPenaltyLimitModule;
    int32_t m_SkillBonusLimitModule;
    NWSyncAdvertisement m_nwsyncModuleSourceAdvert;
    AdvertLUT m_nwsyncAdvertLUT;

    CServerExoAppInternal();
    ~CServerExoAppInternal();
    BOOL Initialize();
    BOOL MainLoop();
    void StartServices();
    void StopServices();
    void ShutdownNetLayer();
    void RestartNetLayer();
    void Uninitialize();
    BOOL AdmitNetworkAddress(uint32_t nProtocol, CExoString sAddress);
    BOOL AdmitPlayerName(CExoString sPlayerName);
    BOOL HandleMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t dwSize, BOOL bRawMessage);
    BOOL SetNetworkAddressBan(uint32_t nProtocol, CExoString sAddress, BOOL bBanAddress);
    void PlayerListChange(uint32_t nPlayerId, BOOL bEnter, BOOL bPrimaryPlayer);
    BOOL ContinueMessageProcessing();
    void RemovePCFromWorld(CNWSPlayer * pPlayer);
    void Shutdown(BOOL bWarnLocals, BOOL bFromMessage = false);
    BOOL ValidatePlayerLogin(void * pPlayer);
    void OnCDChange();
    void OnExit();
    void OnGainFocus();
    void OnLostFocus();
    void OnVideoChange();
    CWorldTimer * GetActiveTimer(OBJECT_ID oid = 0x7f000000);
    void SetGameSpyReporting(BOOL bEnabled);
    CNWSPlayer * GetClientObjectByObjectId(OBJECT_ID nObjectId);
    CNWSClient * GetClientObjectByPlayerId(uint32_t nPlayerId, uint8_t nClientType = 0);
    BOOL CopyModuleToCurrentGame(CExoString & sOldFilename, CExoString & sNewFilename, RESTYPE nResType);
    BOOL LoadGame(uint32_t nSlot, CExoString & sSaveName, CExoString & sModuleName, CNWSPlayer * pPlayer = nullptr);
    void SetEstimatedSaveSize(const CExoString & sFile, RESTYPE nResType);
    BOOL StartNewModule(CExoString & sModuleName);
    BOOL EndGame(const CExoString & sMovieName);
    STRREF ValidateCreateServerCharacter(CNWSPlayer * pPlayer, void * pCharData, uint32_t nSize);
    BOOL LoadCharacterStart(uint8_t nType, CNWSPlayer * pPlayer, CResRef cResRef, void * pCharData = nullptr, uint32_t nSize = 0);
    BOOL LoadCharacterFinish(CNWSPlayer * pPlayer, BOOL bUseSaveGameCharacter = false, BOOL bUseStateDataInSaveGame = false);
    BOOL LoadPrimaryPlayer(CNWSPlayer * pPlayer);
    BOOL ExportAllPlayers();
    BOOL ExportPlayer(CNWSPlayer * pPlayer);
    void DealWithLoadGameError(uint32_t nLoadErr);
    BOOL SetDDCipherForModule(CExoString moduleName);
    CNWSModule * GetModule();
    CExoString GetModuleName();
    CGameObject * GetGameObject(OBJECT_ID nObjectID);
    CNWSStore * GetStoreByGameObjectID(OBJECT_ID nObjectID);
    CNWSItem * GetItemByGameObjectID(OBJECT_ID nObjectID);
    CNWSCreature * GetCreatureByGameObjectID(OBJECT_ID nObjectID);
    CNWSModule * GetModuleByGameObjectID(OBJECT_ID nObjectID);
    CNWSArea * GetAreaByGameObjectID(OBJECT_ID nObjectID);
    CNWSTrigger * GetTriggerByGameObjectID(OBJECT_ID nObjectID);
    CNWSPlaceable * GetPlaceableByGameObjectID(OBJECT_ID nObjectID);
    CNWSDoor * GetDoorByGameObjectID(OBJECT_ID nObjectID);
    CNWSAreaOfEffectObject * GetAreaOfEffectByGameObjectID(OBJECT_ID nObjectID);
    CNWSWaypoint * GetWaypointByGameObjectID(OBJECT_ID nObjectID);
    CNWSEncounter * GetEncounterByGameObjectID(OBJECT_ID nObjectID);
    CNWSSoundObject * GetSoundObjectByGameObjectID(OBJECT_ID nObjectID);
    uint32_t GetPlayerIDByGameObjectID(OBJECT_ID nObjectID);
    int32_t GetPlayerLanguage(uint32_t nPlayerID);
    int32_t GetModuleLanguage();
    BOOL GetPlayerAddressData(uint32_t nConnectionId, uint32_t * nProtocol, uint8_t * * pNetAddress1, uint8_t * * pNetAddress2, uint32_t * nPort);
    void GetExtendedServerInfo(class CExtendedServerInfo * pInfo);
    void HandleGameSpyToServerMessage(int32_t nKeyId, void * pOutBuf, int nIndex = - 1);
    void UpdateClientsForObject(OBJECT_ID oidObjectToUpdate);
    void MarkUpdateClientsForObject(OBJECT_ID oidObjectToUpdate);
    void UpdateClientGameObjectsForPlayer(CNWSPlayer * pPlayer, BOOL bForce, uint64_t nCurrentSystemTime = 0);
    BOOL UnloadModule();
    BOOL LoadModule(CExoString moduleResRef, CUUID uuidOverride, BOOL bIsSaveGame, CNWSPlayer * pPlayer, int32_t sourceType, const NWSync::Advertisement & nwsyncModuleSourceAdvert);
    BOOL GetModuleExists(const CExoString & sModuleResRef);
    BOOL RunModule();
    void VomitServerOptionsToLog();
    CExoString GetPlayerListString();
    CExoString GetBannedListString();
    CExoString GetPortalListString();
    void MovePlayerToArea(void * pPlayer);
    void InitiateModuleForPlayer(void * pPlayer);
    void UpdateWindowTitle();
    BOOL GetFactionOfObject(OBJECT_ID oObject, int32_t * nFaction);
    BOOL SendCharacterQuery(CNWSPlayer * pPlayer);
    BOOL SendStartStallEvent(uint32_t nStallEvent);
    void TogglePauseState(uint8_t nState);
    BOOL GetPauseState(uint8_t nState);
    uint8_t GetActivePauseState();
    void SetPauseState(uint8_t nState, BOOL bPause);
    CExoArrayList<OBJECT_ID> * GetActiveExclusionList();
    void AddToExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    void RemoveFromExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    BOOL IsOnActiveExclusionList(OBJECT_ID oidExclude);
    void ReprocessExclusionListActions(uint8_t nOldState);
    uint32_t ResolvePlayerByFirstName(const CExoString & sName);
    BOOL SendEnhancedHeartbeatToMasterServer();
    BOOL SendHeartbeatToRelay();
    int32_t GetDifficultyOption(int32_t nOption);
    void AddCharListRequest(uint32_t nPlayerId);
    BOOL IsOnExclusionList(OBJECT_ID oidToExamine);
    void AddIPToBannedList(CExoString sIP);
    void AddPlayerNameToBannedList(CExoString sPlayerName);
    void AddCDKeyToBannedList(CExoString sKey);
    void RemoveIPFromBannedList(CExoString sIP);
    void RemovePlayerNameFromBannedList(CExoString sPlayerName);
    void RemoveCDKeyFromBannedList(CExoString sKey);
    BOOL GetIsIPOnBannedList(CExoString sIP);
    BOOL GetIsPlayerNameOnBannedList(CExoString sPlayerName);
    BOOL GetIsCDKeyOnBannedList(CExoString sKey);
    void HandleOldServerVaultMigration(CExoString sClientCDKey, CExoString sLegacyCDKey, CExoString sPlayerName);
    BOOL IsPlayerNameSticky();
    BOOL CheckStickyPlayerNameReserved(CExoString sClientCDKey, CExoString sLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType);
    OBJECT_ID GetFirstPCObject();
    OBJECT_ID GetNextPCObject();
    void StallEventSaveGame();
    void PushMessageOverWall(uint8_t * pData, uint32_t nMsgLength);
    void UnlockBiowareModule(CNWSModule * pModule);
    BOOL CreateServerVaultLostAndFound();
    BOOL StripColorTokens(CExoString & sInput);
    void AddSubNetProfileSendSize(uint32_t nPlayerID, uint32_t nSize);
    CExoString GetHostedPublicInternetAddressAndPort();
    int GetGameObjectUpdateInterval(CNWSObject * creature);
    int GetGameObjectUpdateMessageLimit(CNWSObject * creature);
    void SetGameObjectUpdateIntervalTarget(int target);
    void SetGameObjectUpdateIntervalTargetLoading(int target);
    void SetGameObjectUpdateMessageLimit(int target);
    void SetGameObjectUpdateMessageLimitLoading(int target);
    BOOL StorePlayerCharacters();
    BOOL SendEnteringStartNewModuleMessage();
    BOOL SendExitingStartNewModuleMessage(BOOL bSuccess);
    void QuarantineInvalidCharacter(void * pData, uint32_t nSize);
    void UpdateClientGameObjects(BOOL bForce);
    void InitializeNetLayer();
    void GetServerInfoFromIniFile();
    void ReadBannedLists();
    void WriteServerInfoToIniFile();
    BOOL AddPendingAuthorization(uint32_t nPlayerID);
    BOOL RemovePendingAuthorization(uint32_t nPlayerID);
    void ConnectionLibMainLoop();
    void StartShutdownTimer(uint64_t nTime, uint64_t nDelay);
    BOOL UpdateShutdownTimer(uint64_t nTime);
    BOOL UpdateLogHeartbeatTimer(uint64_t nTime);
    BOOL UpdateAutoSaveTimer();
    void AddSubNetProfile(uint32_t nPlayerID, CExoString sPlayerName, CExoString sCDPublicKey);
    void RemoveSubNetProfile(uint32_t nPlayerID);
    void AddSubNetProfileRecvSize(uint32_t nPlayerID, uint32_t nSize);
    void ShutdownServerProfiles();


#ifdef NWN_CLASS_EXTENSION_CServerExoAppInternal
    NWN_CLASS_EXTENSION_CServerExoAppInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerExoAppInternal)
#endif

