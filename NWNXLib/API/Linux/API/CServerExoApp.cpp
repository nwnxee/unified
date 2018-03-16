#include "CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CCodeBase.hpp"
#include "CExoArrayListTemplatedCExoString.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CExoLinkedListTemplatedunsignedlong.hpp"
#include "CExtendedServerInfo.hpp"
#include "CGameObject.hpp"
#include "CGameObjectArray.hpp"
#include "CNWPlaceMeshManager.hpp"
#include "CNWSArea.hpp"
#include "CNWSAreaOfEffectObject.hpp"
#include "CNWSClient.hpp"
#include "CNWSCreature.hpp"
#include "CNWSDoor.hpp"
#include "CNWSEncounter.hpp"
#include "CNWSItem.hpp"
#include "CNWSModule.hpp"
#include "CNWSPlaceable.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSSoundObject.hpp"
#include "CNWSStore.hpp"
#include "CNWSTrigger.hpp"
#include "CNWSWaypoint.hpp"
#include "CNetLayer.hpp"
#include "CServerAIMaster.hpp"
#include "CServerExoAppInternal.hpp"
#include "CServerInfo.hpp"
#include "CWorldTimer.hpp"

namespace NWNXLib {

namespace API {

CServerExoApp::CServerExoApp()
{
    CServerExoApp__CServerExoAppCtor(this);
}

CServerExoApp::~CServerExoApp()
{
    CServerExoApp__CServerExoAppDtor__0(this);
}

void CServerExoApp::AddCDKeyToBannedList(CExoString a0)
{
    return CServerExoApp__AddCDKeyToBannedList(this, a0);
}

void CServerExoApp::AddCharListRequest(uint32_t a0)
{
    return CServerExoApp__AddCharListRequest(this, a0);
}

void CServerExoApp::AddExportPlayersCharacterRequest(uint32_t a0)
{
    return CServerExoApp__AddExportPlayersCharacterRequest(this, a0);
}

void CServerExoApp::AddIPToBannedList(CExoString a0)
{
    return CServerExoApp__AddIPToBannedList(this, a0);
}

void CServerExoApp::AddPlayerNameToBannedList(CExoString a0)
{
    return CServerExoApp__AddPlayerNameToBannedList(this, a0);
}

void CServerExoApp::AddSubNetProfileSendSize(uint32_t a0, uint32_t a1)
{
    return CServerExoApp__AddSubNetProfileSendSize(this, a0, a1);
}

void CServerExoApp::AddToExclusionList(uint32_t a0, unsigned char a1)
{
    return CServerExoApp__AddToExclusionList(this, a0, a1);
}

int32_t CServerExoApp::AdmitNetworkAddress(uint32_t a0, CExoString a1)
{
    return CServerExoApp__AdmitNetworkAddress(this, a0, a1);
}

int32_t CServerExoApp::AdmitPlayerName(CExoString a0)
{
    return CServerExoApp__AdmitPlayerName(this, a0);
}

int32_t CServerExoApp::CheckStickyPlayerNameReserved(CExoString a0, CExoString a1, CExoString a2, int32_t a3)
{
    return CServerExoApp__CheckStickyPlayerNameReserved(this, a0, a1, a2, a3);
}

void CServerExoApp::ClearExportPlayerCharacterRequests()
{
    return CServerExoApp__ClearExportPlayerCharacterRequests(this);
}

int32_t CServerExoApp::ContinueMessageProcessing()
{
    return CServerExoApp__ContinueMessageProcessing(this);
}

int32_t CServerExoApp::ExportAllPlayers()
{
    return CServerExoApp__ExportAllPlayers(this);
}

int32_t CServerExoApp::GetAbilityBonusLimit()
{
    return CServerExoApp__GetAbilityBonusLimit(this);
}

int32_t CServerExoApp::GetAbilityPenaltyLimit()
{
    return CServerExoApp__GetAbilityPenaltyLimit(this);
}

CExoLinkedListTemplatedunsignedlong* CServerExoApp::GetActiveExclusionList()
{
    return CServerExoApp__GetActiveExclusionList(this);
}

unsigned char CServerExoApp::GetActivePauseState()
{
    return CServerExoApp__GetActivePauseState(this);
}

CWorldTimer* CServerExoApp::GetActiveTimer(uint32_t a0)
{
    return CServerExoApp__GetActiveTimer(this, a0);
}

uint32_t CServerExoApp::GetApplicationId()
{
    return CServerExoApp__GetApplicationId(this);
}

CNWSArea* CServerExoApp::GetAreaByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetAreaByGameObjectID(this, a0);
}

CNWSAreaOfEffectObject* CServerExoApp::GetAreaOfEffectByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetAreaOfEffectByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetAttackBonusLimit()
{
    return CServerExoApp__GetAttackBonusLimit(this);
}

int32_t CServerExoApp::GetAutoSavePending()
{
    return CServerExoApp__GetAutoSavePending(this);
}

CExoString CServerExoApp::GetBannedListString()
{
    return CServerExoApp__GetBannedListString(this);
}

int32_t CServerExoApp::GetCDKeys(CExoArrayListTemplatedCExoString** a0)
{
    return CServerExoApp__GetCDKeys(this, a0);
}

CNWSPlayer* CServerExoApp::GetClientObjectByObjectId(uint32_t a0)
{
    return CServerExoApp__GetClientObjectByObjectId(this, a0);
}

CNWSClient* CServerExoApp::GetClientObjectByPlayerId(uint32_t a0, unsigned char a1)
{
    return CServerExoApp__GetClientObjectByPlayerId(this, a0, a1);
}

uint32_t CServerExoApp::GetClientsRequiredToDisableCPUSleep()
{
    return CServerExoApp__GetClientsRequiredToDisableCPUSleep(this);
}

CCodeBase* CServerExoApp::GetCodeBase()
{
    return CServerExoApp__GetCodeBase(this);
}

void CServerExoApp::GetConnectionLib()
{
    return CServerExoApp__GetConnectionLib(this);
}

CNWSCreature* CServerExoApp::GetCreatureByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetCreatureByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetCreatureDeathLogging()
{
    return CServerExoApp__GetCreatureDeathLogging(this);
}

int32_t CServerExoApp::GetDamageBonusLimit()
{
    return CServerExoApp__GetDamageBonusLimit(this);
}

int32_t CServerExoApp::GetDebugMode()
{
    return CServerExoApp__GetDebugMode(this);
}

int32_t CServerExoApp::GetDifficultyOption(int32_t a0)
{
    return CServerExoApp__GetDifficultyOption(this, a0);
}

CNWSDoor* CServerExoApp::GetDoorByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetDoorByGameObjectID(this, a0);
}

CNWSEncounter* CServerExoApp::GetEncounterByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetEncounterByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetExportCharacterPending()
{
    return CServerExoApp__GetExportCharacterPending(this);
}

const CExoArrayListTemplatedunsignedlong& CServerExoApp::GetExportPlayersCharacterRequests()
{
    return CServerExoApp__GetExportPlayersCharacterRequests(this);
}

CExtendedServerInfo* CServerExoApp::GetExtendedServerInfo()
{
    return CServerExoApp__GetExtendedServerInfo__0(this);
}

void CServerExoApp::GetExtendedServerInfo(CExtendedServerInfo* a0)
{
    return CServerExoApp__GetExtendedServerInfo__1(this, a0);
}

int32_t CServerExoApp::GetFactionOfObject(uint32_t a0, int32_t* a1)
{
    return CServerExoApp__GetFactionOfObject(this, a0, a1);
}

uint32_t CServerExoApp::GetFirstPCObject()
{
    return CServerExoApp__GetFirstPCObject(this);
}

float CServerExoApp::GetFPS()
{
    return CServerExoApp__GetFPS(this);
}

CGameObject* CServerExoApp::GetGameObject(uint32_t a0)
{
    return CServerExoApp__GetGameObject(this, a0);
}

int32_t CServerExoApp::GetGameSpyEnabled()
{
    return CServerExoApp__GetGameSpyEnabled(this);
}

CExoString CServerExoApp::GetHostedPublicInternetAddressAndPort()
{
    return CServerExoApp__GetHostedPublicInternetAddressAndPort(this);
}

int32_t CServerExoApp::GetImportingChar()
{
    return CServerExoApp__GetImportingChar(this);
}

int32_t CServerExoApp::GetIsCDKeyOnBannedList(CExoString a0)
{
    return CServerExoApp__GetIsCDKeyOnBannedList(this, a0);
}

int32_t CServerExoApp::GetIsControlledByPlayer(uint32_t a0)
{
    return CServerExoApp__GetIsControlledByPlayer(this, a0);
}

int32_t CServerExoApp::GetIsIPOnBannedList(CExoString a0)
{
    return CServerExoApp__GetIsIPOnBannedList(this, a0);
}

int32_t CServerExoApp::GetIsPlayerNameOnBannedList(CExoString a0)
{
    return CServerExoApp__GetIsPlayerNameOnBannedList(this, a0);
}

CNWSItem* CServerExoApp::GetItemByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetItemByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetLoadingModule()
{
    return CServerExoApp__GetLoadingModule(this);
}

void* CServerExoApp::GetModule()
{
    return CServerExoApp__GetModule(this);
}

CNWSModule* CServerExoApp::GetModuleByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetModuleByGameObjectID(this, a0);
}

CExoLocString CServerExoApp::GetModuleDescription()
{
    return CServerExoApp__GetModuleDescription(this);
}

int32_t CServerExoApp::GetModuleLanguage()
{
    return CServerExoApp__GetModuleLanguage(this);
}

CExoString CServerExoApp::GetModuleName()
{
    return CServerExoApp__GetModuleName(this);
}

int32_t CServerExoApp::GetMoveToModulePending()
{
    return CServerExoApp__GetMoveToModulePending(this);
}

CExoString CServerExoApp::GetMoveToModuleString()
{
    return CServerExoApp__GetMoveToModuleString(this);
}

int32_t CServerExoApp::GetMultiplayerEnabled()
{
    return CServerExoApp__GetMultiplayerEnabled(this);
}

CNetLayer* CServerExoApp::GetNetLayer()
{
    return CServerExoApp__GetNetLayer(this);
}

uint32_t CServerExoApp::GetNextPCObject()
{
    return CServerExoApp__GetNextPCObject(this);
}

void* CServerExoApp::GetNWSMessage()
{
    return CServerExoApp__GetNWSMessage(this);
}

CGameObjectArray* CServerExoApp::GetObjectArray()
{
    return CServerExoApp__GetObjectArray(this);
}

int32_t CServerExoApp::GetPauseState(unsigned char a0)
{
    return CServerExoApp__GetPauseState(this, a0);
}

CWorldTimer* CServerExoApp::GetPauseTimer()
{
    return CServerExoApp__GetPauseTimer(this);
}

CNWSPlaceable* CServerExoApp::GetPlaceableByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetPlaceableByGameObjectID(this, a0);
}

CNWPlaceMeshManager* CServerExoApp::GetPlaceMeshManager()
{
    return CServerExoApp__GetPlaceMeshManager(this);
}

int32_t CServerExoApp::GetPlayerAddressData(uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    return CServerExoApp__GetPlayerAddressData(this, a0, a1, a2, a3, a4);
}

uint32_t CServerExoApp::GetPlayerIDByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetPlayerIDByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetPlayerLanguage(uint32_t a0)
{
    return CServerExoApp__GetPlayerLanguage(this, a0);
}

void* CServerExoApp::GetPlayerList()
{
    return CServerExoApp__GetPlayerList(this);
}

CExoString CServerExoApp::GetPlayerListString()
{
    return CServerExoApp__GetPlayerListString(this);
}

CExoString CServerExoApp::GetPortalListString()
{
    return CServerExoApp__GetPortalListString(this);
}

int32_t CServerExoApp::GetReloadModuleWhenEmpty()
{
    return CServerExoApp__GetReloadModuleWhenEmpty(this);
}

int32_t CServerExoApp::GetSavingThrowBonusLimit()
{
    return CServerExoApp__GetSavingThrowBonusLimit(this);
}

CServerAIMaster* CServerExoApp::GetServerAIMaster()
{
    return CServerExoApp__GetServerAIMaster(this);
}

CServerInfo* CServerExoApp::GetServerInfo()
{
    return CServerExoApp__GetServerInfo(this);
}

int16_t CServerExoApp::GetServerMode()
{
    return CServerExoApp__GetServerMode(this);
}

int32_t CServerExoApp::GetSkillBonusLimit()
{
    return CServerExoApp__GetSkillBonusLimit(this);
}

CNWSSoundObject* CServerExoApp::GetSoundObjectByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetSoundObjectByGameObjectID(this, a0);
}

int32_t CServerExoApp::GetStickyCombatModesEnabled()
{
    return CServerExoApp__GetStickyCombatModesEnabled(this);
}

CNWSStore* CServerExoApp::GetStoreByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetStoreByGameObjectID(this, a0);
}

void* CServerExoApp::GetSysAdminList()
{
    return CServerExoApp__GetSysAdminList(this);
}

CWorldTimer* CServerExoApp::GetTimestopTimer()
{
    return CServerExoApp__GetTimestopTimer(this);
}

CNWSTrigger* CServerExoApp::GetTriggerByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetTriggerByGameObjectID(this, a0);
}

CNWSWaypoint* CServerExoApp::GetWaypointByGameObjectID(uint32_t a0)
{
    return CServerExoApp__GetWaypointByGameObjectID(this, a0);
}

CWorldTimer* CServerExoApp::GetWorldTimer()
{
    return CServerExoApp__GetWorldTimer(this);
}

void CServerExoApp::GSClientAddServer(void* a0, char* a1, char* a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, char* a7, int32_t a8, int32_t a9, char* a10, int32_t a11, int32_t a12, int32_t a13, char* a14, char* a15, int32_t a16, int32_t a17, int32_t a18, int32_t a19, int32_t a20, int32_t a21)
{
    return CServerExoApp__GSClientAddServer(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21);
}

void CServerExoApp::GSClientChatMessage(int32_t a0, CExoString a1, CExoString a2)
{
    return CServerExoApp__GSClientChatMessage(this, a0, a1, a2);
}

void CServerExoApp::GSClientClearServers()
{
    return CServerExoApp__GSClientClearServers(this);
}

void CServerExoApp::GSClientGroupRoomAdded(int32_t a0, uint32_t a1)
{
    return CServerExoApp__GSClientGroupRoomAdded(this, a0, a1);
}

void CServerExoApp::GSClientRemoveServer(void* a0)
{
    return CServerExoApp__GSClientRemoveServer(this, a0);
}

void CServerExoApp::GSClientUpdateConnectionPhase(unsigned char a0, const CExoString& a1)
{
    return CServerExoApp__GSClientUpdateConnectionPhase(this, a0, a1);
}

void CServerExoApp::GSClientUpdateServer(void* a0, char* a1, char* a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, char* a7, int32_t a8, int32_t a9, char* a10, int32_t a11, int32_t a12, int32_t a13, char* a14, char* a15, int32_t a16, int32_t a17, int32_t a18, int32_t a19, int32_t a20, int32_t a21)
{
    return CServerExoApp__GSClientUpdateServer(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21);
}

void CServerExoApp::HandleGameSpyToServerMessage(int32_t a0, void* a1, int32_t a2)
{
    return CServerExoApp__HandleGameSpyToServerMessage(this, a0, a1, a2);
}

int32_t CServerExoApp::HandleMessage(uint32_t a0, unsigned char* a1, uint32_t a2, int32_t a3)
{
    return CServerExoApp__HandleMessage(this, a0, a1, a2, a3);
}

void CServerExoApp::HandleOldServerVaultMigration(CExoString a0, CExoString a1, CExoString a2)
{
    return CServerExoApp__HandleOldServerVaultMigration(this, a0, a1, a2);
}

int32_t CServerExoApp::Initialize()
{
    return CServerExoApp__Initialize(this);
}

void CServerExoApp::InitiateModuleForPlayer(void* a0)
{
    return CServerExoApp__InitiateModuleForPlayer(this, a0);
}

int32_t CServerExoApp::IsOnActiveExclusionList(uint32_t a0)
{
    return CServerExoApp__IsOnActiveExclusionList(this, a0);
}

int32_t CServerExoApp::IsOnExclusionList(uint32_t a0)
{
    return CServerExoApp__IsOnExclusionList(this, a0);
}

int32_t CServerExoApp::IsPlayerNameSticky()
{
    return CServerExoApp__IsPlayerNameSticky(this);
}

int32_t CServerExoApp::LoadCharacterFinish(CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    return CServerExoApp__LoadCharacterFinish(this, a0, a1, a2);
}

int32_t CServerExoApp::LoadCharacterStart(unsigned char a0, CNWSPlayer* a1, CResRef a2, void* a3, uint32_t a4)
{
    return CServerExoApp__LoadCharacterStart(this, a0, a1, a2, a3, a4);
}

int32_t CServerExoApp::LoadGame(uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3)
{
    return CServerExoApp__LoadGame(this, a0, a1, a2, a3);
}

int32_t CServerExoApp::LoadModule(CExoString a0, int32_t a1, CNWSPlayer* a2)
{
    return CServerExoApp__LoadModule(this, a0, a1, a2);
}

int32_t CServerExoApp::LoadPrimaryPlayer(CNWSPlayer* a0)
{
    return CServerExoApp__LoadPrimaryPlayer(this, a0);
}

int32_t CServerExoApp::MainLoop()
{
    return CServerExoApp__MainLoop(this);
}

void CServerExoApp::MovePlayerToArea(void* a0)
{
    return CServerExoApp__MovePlayerToArea(this, a0);
}

void CServerExoApp::OnCDChange()
{
    return CServerExoApp__OnCDChange(this);
}

void CServerExoApp::OnExit()
{
    return CServerExoApp__OnExit(this);
}

void CServerExoApp::OnGainFocus()
{
    return CServerExoApp__OnGainFocus(this);
}

void CServerExoApp::OnLostFocus()
{
    return CServerExoApp__OnLostFocus(this);
}

void CServerExoApp::OnVideoChange()
{
    return CServerExoApp__OnVideoChange(this);
}

void CServerExoApp::PlayerListChange(uint32_t a0, int32_t a1, int32_t a2)
{
    return CServerExoApp__PlayerListChange(this, a0, a1, a2);
}

void CServerExoApp::PushMessageOverWall(unsigned char* a0, uint32_t a1)
{
    return CServerExoApp__PushMessageOverWall(this, a0, a1);
}

void CServerExoApp::RemoveCDKeyFromBannedList(CExoString a0)
{
    return CServerExoApp__RemoveCDKeyFromBannedList(this, a0);
}

void CServerExoApp::RemoveFromExclusionList(uint32_t a0, unsigned char a1)
{
    return CServerExoApp__RemoveFromExclusionList(this, a0, a1);
}

void CServerExoApp::RemoveIPFromBannedList(CExoString a0)
{
    return CServerExoApp__RemoveIPFromBannedList(this, a0);
}

void CServerExoApp::RemovePCFromWorld(CNWSPlayer* a0)
{
    return CServerExoApp__RemovePCFromWorld(this, a0);
}

void CServerExoApp::RemovePlayerNameFromBannedList(CExoString a0)
{
    return CServerExoApp__RemovePlayerNameFromBannedList(this, a0);
}

uint32_t CServerExoApp::ResolvePlayerByFirstName(const CExoString& a0)
{
    return CServerExoApp__ResolvePlayerByFirstName(this, a0);
}

void CServerExoApp::RestartNetLayer()
{
    return CServerExoApp__RestartNetLayer(this);
}

int32_t CServerExoApp::RunModule()
{
    return CServerExoApp__RunModule(this);
}

int32_t CServerExoApp::SaveGame(uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3, int32_t a4, CExoString& a5)
{
    return CServerExoApp__SaveGame(this, a0, a1, a2, a3, a4, a5);
}

int32_t CServerExoApp::SendCharacterQuery(CNWSPlayer* a0)
{
    return CServerExoApp__SendCharacterQuery(this, a0);
}

void CServerExoApp::SetAbilityBonusLimit(int32_t a0)
{
    return CServerExoApp__SetAbilityBonusLimit(this, a0);
}

void CServerExoApp::SetAbilityPenaltyLimit(int32_t a0)
{
    return CServerExoApp__SetAbilityPenaltyLimit(this, a0);
}

void CServerExoApp::SetApplicationIdsMatch(int32_t a0)
{
    return CServerExoApp__SetApplicationIdsMatch(this, a0);
}

void CServerExoApp::SetAttackBonusLimit(int32_t a0)
{
    return CServerExoApp__SetAttackBonusLimit(this, a0);
}

void CServerExoApp::SetAutoSavePending(int32_t a0)
{
    return CServerExoApp__SetAutoSavePending(this, a0);
}

void CServerExoApp::SetDamageBonusLimit(int32_t a0)
{
    return CServerExoApp__SetDamageBonusLimit(this, a0);
}

int32_t CServerExoApp::SetDDCipherForModule(CExoString a0)
{
    return CServerExoApp__SetDDCipherForModule(this, a0);
}

void CServerExoApp::SetDebugMode(int32_t a0)
{
    return CServerExoApp__SetDebugMode(this, a0);
}

void CServerExoApp::SetEndGamePending(int32_t a0)
{
    return CServerExoApp__SetEndGamePending(this, a0);
}

void CServerExoApp::SetEndGameString(CExoString& a0)
{
    return CServerExoApp__SetEndGameString(this, a0);
}

void CServerExoApp::SetExportCharacterPending(int32_t a0)
{
    return CServerExoApp__SetExportCharacterPending(this, a0);
}

void CServerExoApp::SetForceUpdate()
{
    return CServerExoApp__SetForceUpdate(this);
}

void CServerExoApp::SetGameSpyEnabled(int32_t a0)
{
    return CServerExoApp__SetGameSpyEnabled(this, a0);
}

void CServerExoApp::SetGameSpyReporting(int32_t a0)
{
    return CServerExoApp__SetGameSpyReporting(this, a0);
}

void CServerExoApp::SetImportingChar(int32_t a0)
{
    return CServerExoApp__SetImportingChar(this, a0);
}

void CServerExoApp::SetLoadingModule(int32_t a0)
{
    return CServerExoApp__SetLoadingModule(this, a0);
}

void CServerExoApp::SetMoveToModulePending(int32_t a0)
{
    return CServerExoApp__SetMoveToModulePending(this, a0);
}

void CServerExoApp::SetMoveToModuleString(CExoString& a0)
{
    return CServerExoApp__SetMoveToModuleString(this, a0);
}

int32_t CServerExoApp::SetNetworkAddressBan(uint32_t a0, CExoString a1, int32_t a2)
{
    return CServerExoApp__SetNetworkAddressBan(this, a0, a1, a2);
}

void CServerExoApp::SetPauseState(unsigned char a0, int32_t a1)
{
    return CServerExoApp__SetPauseState(this, a0, a1);
}

void CServerExoApp::SetReloadModuleWhenEmpty(int32_t a0)
{
    return CServerExoApp__SetReloadModuleWhenEmpty(this, a0);
}

void CServerExoApp::SetSavingThrowBonusLimit(int32_t a0)
{
    return CServerExoApp__SetSavingThrowBonusLimit(this, a0);
}

void CServerExoApp::SetSkillBonusLimit(int32_t a0)
{
    return CServerExoApp__SetSkillBonusLimit(this, a0);
}

void CServerExoApp::SetWeGotDisconnected()
{
    return CServerExoApp__SetWeGotDisconnected(this);
}

void CServerExoApp::Shutdown(int32_t a0, int32_t a1)
{
    return CServerExoApp__Shutdown(this, a0, a1);
}

void CServerExoApp::ShutdownNetLayer()
{
    return CServerExoApp__ShutdownNetLayer(this);
}

void CServerExoApp::ShutDownToMainMenu()
{
    return CServerExoApp__ShutDownToMainMenu(this);
}

int32_t CServerExoApp::StartNewModule(CExoString& a0)
{
    return CServerExoApp__StartNewModule(this, a0);
}

void CServerExoApp::StartServices()
{
    return CServerExoApp__StartServices(this);
}

void CServerExoApp::StopServices()
{
    return CServerExoApp__StopServices(this);
}

int32_t CServerExoApp::StripColorTokens(CExoString& a0)
{
    return CServerExoApp__StripColorTokens(this, a0);
}

void CServerExoApp::TogglePauseState(unsigned char a0)
{
    return CServerExoApp__TogglePauseState(this, a0);
}

void CServerExoApp::Uninitialize()
{
    return CServerExoApp__Uninitialize(this);
}

int32_t CServerExoApp::UnloadModule()
{
    return CServerExoApp__UnloadModule(this);
}

int32_t CServerExoApp::ValidatePlayerLogin(void* a0)
{
    return CServerExoApp__ValidatePlayerLogin(this, a0);
}

void CServerExoApp::VomitServerOptionsToLog()
{
    return CServerExoApp__VomitServerOptionsToLog(this);
}

void CServerExoApp__CServerExoAppCtor(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__CServerExoAppCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CServerExoApp__CServerExoAppDtor__0(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__CServerExoAppDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CServerExoApp__AddCDKeyToBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddCDKeyToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__AddCharListRequest(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddCharListRequest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__AddExportPlayersCharacterRequest(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddExportPlayersCharacterRequest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__AddIPToBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddIPToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__AddPlayerNameToBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddPlayerNameToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__AddSubNetProfileSendSize(CServerExoApp* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddSubNetProfileSendSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__AddToExclusionList(CServerExoApp* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AddToExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerExoApp__AdmitNetworkAddress(CServerExoApp* thisPtr, uint32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AdmitNetworkAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerExoApp__AdmitPlayerName(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__AdmitPlayerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__CheckStickyPlayerNameReserved(CServerExoApp* thisPtr, CExoString a0, CExoString a1, CExoString a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString, CExoString, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__CheckStickyPlayerNameReserved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CServerExoApp__ClearExportPlayerCharacterRequests(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ClearExportPlayerCharacterRequests);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__ContinueMessageProcessing(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ContinueMessageProcessing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__ExportAllPlayers(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ExportAllPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetAbilityBonusLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAbilityBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetAbilityPenaltyLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAbilityPenaltyLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLinkedListTemplatedunsignedlong* CServerExoApp__GetActiveExclusionList(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoLinkedListTemplatedunsignedlong*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetActiveExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CServerExoApp__GetActivePauseState(CServerExoApp* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetActivePauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CWorldTimer* CServerExoApp__GetActiveTimer(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CWorldTimer*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetActiveTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CServerExoApp__GetApplicationId(CServerExoApp* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetApplicationId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSArea* CServerExoApp__GetAreaByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAreaByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSAreaOfEffectObject* CServerExoApp__GetAreaOfEffectByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSAreaOfEffectObject*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAreaOfEffectByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetAttackBonusLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAttackBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetAutoSavePending(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetAutoSavePending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetBannedListString(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetBannedListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetCDKeys(CServerExoApp* thisPtr, CExoArrayListTemplatedCExoString** a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoArrayListTemplatedCExoString**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetCDKeys);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSPlayer* CServerExoApp__GetClientObjectByObjectId(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSPlayer*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetClientObjectByObjectId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSClient* CServerExoApp__GetClientObjectByPlayerId(CServerExoApp* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = CNWSClient*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetClientObjectByPlayerId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CServerExoApp__GetClientsRequiredToDisableCPUSleep(CServerExoApp* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetClientsRequiredToDisableCPUSleep);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CCodeBase* CServerExoApp__GetCodeBase(CServerExoApp* thisPtr)
{
    using FuncPtrType = CCodeBase*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetCodeBase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__GetConnectionLib(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetConnectionLib);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

CNWSCreature* CServerExoApp__GetCreatureByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSCreature*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetCreatureByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetCreatureDeathLogging(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetCreatureDeathLogging);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetDamageBonusLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetDamageBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetDebugMode(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetDebugMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetDifficultyOption(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetDifficultyOption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSDoor* CServerExoApp__GetDoorByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSDoor*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetDoorByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSEncounter* CServerExoApp__GetEncounterByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSEncounter*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetEncounterByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetExportCharacterPending(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetExportCharacterPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

const CExoArrayListTemplatedunsignedlong& CServerExoApp__GetExportPlayersCharacterRequests(CServerExoApp* thisPtr)
{
    using FuncPtrType = const CExoArrayListTemplatedunsignedlong&(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetExportPlayersCharacterRequests);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExtendedServerInfo* CServerExoApp__GetExtendedServerInfo__0(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExtendedServerInfo*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetExtendedServerInfo__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__GetExtendedServerInfo__1(CServerExoApp* thisPtr, CExtendedServerInfo* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExtendedServerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetExtendedServerInfo__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetFactionOfObject(CServerExoApp* thisPtr, uint32_t a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetFactionOfObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CServerExoApp__GetFirstPCObject(CServerExoApp* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetFirstPCObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CServerExoApp__GetFPS(CServerExoApp* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetFPS);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CGameObject* CServerExoApp__GetGameObject(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CGameObject*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetGameSpyEnabled(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetGameSpyEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetHostedPublicInternetAddressAndPort(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetHostedPublicInternetAddressAndPort);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetImportingChar(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetImportingChar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetIsCDKeyOnBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetIsCDKeyOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetIsControlledByPlayer(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetIsControlledByPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetIsIPOnBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetIsIPOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetIsPlayerNameOnBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetIsPlayerNameOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSItem* CServerExoApp__GetItemByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetItemByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetLoadingModule(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetLoadingModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void* CServerExoApp__GetModule(CServerExoApp* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSModule* CServerExoApp__GetModuleByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSModule*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetModuleByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLocString CServerExoApp__GetModuleDescription(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoLocString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetModuleDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetModuleLanguage(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetModuleLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetModuleName(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetMoveToModulePending(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetMoveToModulePending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetMoveToModuleString(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetMoveToModuleString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetMultiplayerEnabled(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetMultiplayerEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNetLayer* CServerExoApp__GetNetLayer(CServerExoApp* thisPtr)
{
    using FuncPtrType = CNetLayer*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CServerExoApp__GetNextPCObject(CServerExoApp* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetNextPCObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void* CServerExoApp__GetNWSMessage(CServerExoApp* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetNWSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CGameObjectArray* CServerExoApp__GetObjectArray(CServerExoApp* thisPtr)
{
    using FuncPtrType = CGameObjectArray*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetObjectArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetPauseState(CServerExoApp* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CWorldTimer* CServerExoApp__GetPauseTimer(CServerExoApp* thisPtr)
{
    using FuncPtrType = CWorldTimer*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPauseTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlaceable* CServerExoApp__GetPlaceableByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSPlaceable*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlaceableByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWPlaceMeshManager* CServerExoApp__GetPlaceMeshManager(CServerExoApp* thisPtr)
{
    using FuncPtrType = CNWPlaceMeshManager*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlaceMeshManager);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetPlayerAddressData(CServerExoApp* thisPtr, uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlayerAddressData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CServerExoApp__GetPlayerIDByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlayerIDByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetPlayerLanguage(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlayerLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CServerExoApp__GetPlayerList(CServerExoApp* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlayerList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetPlayerListString(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPlayerListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoApp__GetPortalListString(CServerExoApp* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetPortalListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetReloadModuleWhenEmpty(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetReloadModuleWhenEmpty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetSavingThrowBonusLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetSavingThrowBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CServerAIMaster* CServerExoApp__GetServerAIMaster(CServerExoApp* thisPtr)
{
    using FuncPtrType = CServerAIMaster*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetServerAIMaster);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CServerInfo* CServerExoApp__GetServerInfo(CServerExoApp* thisPtr)
{
    using FuncPtrType = CServerInfo*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetServerInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int16_t CServerExoApp__GetServerMode(CServerExoApp* thisPtr)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetServerMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__GetSkillBonusLimit(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetSkillBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSSoundObject* CServerExoApp__GetSoundObjectByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSSoundObject*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetSoundObjectByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__GetStickyCombatModesEnabled(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetStickyCombatModesEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSStore* CServerExoApp__GetStoreByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSStore*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetStoreByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CServerExoApp__GetSysAdminList(CServerExoApp* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetSysAdminList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CWorldTimer* CServerExoApp__GetTimestopTimer(CServerExoApp* thisPtr)
{
    using FuncPtrType = CWorldTimer*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetTimestopTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSTrigger* CServerExoApp__GetTriggerByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSTrigger*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetTriggerByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSWaypoint* CServerExoApp__GetWaypointByGameObjectID(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSWaypoint*(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetWaypointByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CWorldTimer* CServerExoApp__GetWorldTimer(CServerExoApp* thisPtr)
{
    using FuncPtrType = CWorldTimer*(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GetWorldTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__GSClientAddServer(CServerExoApp* thisPtr, void* a0, char* a1, char* a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, char* a7, int32_t a8, int32_t a9, char* a10, int32_t a11, int32_t a12, int32_t a13, char* a14, char* a15, int32_t a16, int32_t a17, int32_t a18, int32_t a19, int32_t a20, int32_t a21)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientAddServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21);
}

void CServerExoApp__GSClientChatMessage(CServerExoApp* thisPtr, int32_t a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoApp__GSClientClearServers(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientClearServers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__GSClientGroupRoomAdded(CServerExoApp* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientGroupRoomAdded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__GSClientRemoveServer(CServerExoApp* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientRemoveServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__GSClientUpdateConnectionPhase(CServerExoApp* thisPtr, unsigned char a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientUpdateConnectionPhase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__GSClientUpdateServer(CServerExoApp* thisPtr, void* a0, char* a1, char* a2, int32_t a3, int32_t a4, int32_t a5, int32_t a6, char* a7, int32_t a8, int32_t a9, char* a10, int32_t a11, int32_t a12, int32_t a13, char* a14, char* a15, int32_t a16, int32_t a17, int32_t a18, int32_t a19, int32_t a20, int32_t a21)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__GSClientUpdateServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21);
}

void CServerExoApp__HandleGameSpyToServerMessage(CServerExoApp* thisPtr, int32_t a0, void* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__HandleGameSpyToServerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoApp__HandleMessage(CServerExoApp* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, unsigned char*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__HandleMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CServerExoApp__HandleOldServerVaultMigration(CServerExoApp* thisPtr, CExoString a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__HandleOldServerVaultMigration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoApp__Initialize(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__InitiateModuleForPlayer(CServerExoApp* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__InitiateModuleForPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__IsOnActiveExclusionList(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__IsOnActiveExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__IsOnExclusionList(CServerExoApp* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__IsOnExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__IsPlayerNameSticky(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__IsPlayerNameSticky);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__LoadCharacterFinish(CServerExoApp* thisPtr, CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CNWSPlayer*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__LoadCharacterFinish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoApp__LoadCharacterStart(CServerExoApp* thisPtr, unsigned char a0, CNWSPlayer* a1, CResRef a2, void* a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char, CNWSPlayer*, CResRef, void*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__LoadCharacterStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CServerExoApp__LoadGame(CServerExoApp* thisPtr, uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, CExoString&, CExoString&, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__LoadGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CServerExoApp__LoadModule(CServerExoApp* thisPtr, CExoString a0, int32_t a1, CNWSPlayer* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString, int32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__LoadModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoApp__LoadPrimaryPlayer(CServerExoApp* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__LoadPrimaryPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__MainLoop(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__MainLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__MovePlayerToArea(CServerExoApp* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__MovePlayerToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__OnCDChange(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__OnCDChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__OnExit(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__OnExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__OnGainFocus(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__OnGainFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__OnLostFocus(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__OnLostFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__OnVideoChange(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__OnVideoChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__PlayerListChange(CServerExoApp* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__PlayerListChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoApp__PushMessageOverWall(CServerExoApp* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__PushMessageOverWall);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__RemoveCDKeyFromBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RemoveCDKeyFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__RemoveFromExclusionList(CServerExoApp* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RemoveFromExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__RemoveIPFromBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RemoveIPFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__RemovePCFromWorld(CServerExoApp* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RemovePCFromWorld);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__RemovePlayerNameFromBannedList(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RemovePlayerNameFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CServerExoApp__ResolvePlayerByFirstName(CServerExoApp* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoApp*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ResolvePlayerByFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__RestartNetLayer(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RestartNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__RunModule(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__RunModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__SaveGame(CServerExoApp* thisPtr, uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3, int32_t a4, CExoString& a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SaveGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CServerExoApp__SendCharacterQuery(CServerExoApp* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SendCharacterQuery);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetAbilityBonusLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetAbilityBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetAbilityPenaltyLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetAbilityPenaltyLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetApplicationIdsMatch(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetApplicationIdsMatch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetAttackBonusLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetAttackBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetAutoSavePending(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetAutoSavePending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetDamageBonusLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetDamageBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__SetDDCipherForModule(CServerExoApp* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetDDCipherForModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetDebugMode(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetDebugMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetEndGamePending(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetEndGamePending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetEndGameString(CServerExoApp* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetEndGameString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetExportCharacterPending(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetExportCharacterPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetForceUpdate(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetForceUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__SetGameSpyEnabled(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetGameSpyEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetGameSpyReporting(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetGameSpyReporting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetImportingChar(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetImportingChar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetLoadingModule(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetLoadingModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetMoveToModulePending(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetMoveToModulePending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetMoveToModuleString(CServerExoApp* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetMoveToModuleString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoApp__SetNetworkAddressBan(CServerExoApp* thisPtr, uint32_t a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, uint32_t, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetNetworkAddressBan);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoApp__SetPauseState(CServerExoApp* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetPauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__SetReloadModuleWhenEmpty(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetReloadModuleWhenEmpty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetSavingThrowBonusLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetSavingThrowBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetSkillBonusLimit(CServerExoApp* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetSkillBonusLimit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__SetWeGotDisconnected(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__SetWeGotDisconnected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__Shutdown(CServerExoApp* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__Shutdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoApp__ShutdownNetLayer(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ShutdownNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__ShutDownToMainMenu(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ShutDownToMainMenu);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__StartNewModule(CServerExoApp* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__StartNewModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__StartServices(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__StartServices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoApp__StopServices(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__StopServices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__StripColorTokens(CServerExoApp* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__StripColorTokens);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__TogglePauseState(CServerExoApp* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__TogglePauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__Uninitialize(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__Uninitialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__UnloadModule(CServerExoApp* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__UnloadModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoApp__ValidatePlayerLogin(CServerExoApp* thisPtr, void* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoApp*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__ValidatePlayerLogin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoApp__VomitServerOptionsToLog(CServerExoApp* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoApp__VomitServerOptionsToLog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
