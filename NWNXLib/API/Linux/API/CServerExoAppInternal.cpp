#include "CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "C2DA.hpp"
#include "CCodeBase.hpp"
#include "CConnectionLib.hpp"
#include "CExoLinkedListNode.hpp"
#include "CExoLinkedListTemplatedCNWSClient.hpp"
#include "CExoLinkedListTemplatedlongunsignedint.hpp"
#include "CExoLinkedListTemplatedunsignedlong.hpp"
#include "CExtendedServerInfo.hpp"
#include "CFactionManager.hpp"
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
#include "CNWSMessage.hpp"
#include "CNWSModule.hpp"
#include "CNWSPlaceable.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSSoundObject.hpp"
#include "CNWSStore.hpp"
#include "CNWSTrigger.hpp"
#include "CNWSWaypoint.hpp"
#include "CNWVirtualMachineCommands.hpp"
#include "CNetLayer.hpp"
#include "CServerAIMaster.hpp"
#include "CServerInfo.hpp"
#include "CWorldTimer.hpp"

namespace NWNXLib {

namespace API {

CServerExoAppInternal::CServerExoAppInternal()
{
    CServerExoAppInternal__CServerExoAppInternalCtor(this);
}

CServerExoAppInternal::~CServerExoAppInternal()
{
    CServerExoAppInternal__CServerExoAppInternalDtor(this);
}

void CServerExoAppInternal::AddCDKeyToBannedList(CExoString a0)
{
    return CServerExoAppInternal__AddCDKeyToBannedList(this, a0);
}

void CServerExoAppInternal::AddCharListRequest(uint32_t a0)
{
    return CServerExoAppInternal__AddCharListRequest(this, a0);
}

void CServerExoAppInternal::AddIPToBannedList(CExoString a0)
{
    return CServerExoAppInternal__AddIPToBannedList(this, a0);
}

int32_t CServerExoAppInternal::AddPendingAuthorization(uint32_t a0)
{
    return CServerExoAppInternal__AddPendingAuthorization(this, a0);
}

void CServerExoAppInternal::AddPlayerNameToBannedList(CExoString a0)
{
    return CServerExoAppInternal__AddPlayerNameToBannedList(this, a0);
}

void CServerExoAppInternal::AddSubNetProfile(uint32_t a0, CExoString a1, CExoString a2)
{
    return CServerExoAppInternal__AddSubNetProfile(this, a0, a1, a2);
}

void CServerExoAppInternal::AddSubNetProfileRecvSize(uint32_t a0, uint32_t a1)
{
    return CServerExoAppInternal__AddSubNetProfileRecvSize(this, a0, a1);
}

void CServerExoAppInternal::AddSubNetProfileSendSize(uint32_t a0, uint32_t a1)
{
    return CServerExoAppInternal__AddSubNetProfileSendSize(this, a0, a1);
}

void CServerExoAppInternal::AddToExclusionList(uint32_t a0, unsigned char a1)
{
    return CServerExoAppInternal__AddToExclusionList(this, a0, a1);
}

int32_t CServerExoAppInternal::AdmitNetworkAddress(uint32_t a0, CExoString a1)
{
    return CServerExoAppInternal__AdmitNetworkAddress(this, a0, a1);
}

int32_t CServerExoAppInternal::AdmitPlayerName(CExoString a0)
{
    return CServerExoAppInternal__AdmitPlayerName(this, a0);
}

void CServerExoAppInternal::CheckMasterServerTranslation()
{
    return CServerExoAppInternal__CheckMasterServerTranslation(this);
}

int32_t CServerExoAppInternal::CheckStickyPlayerNameReserved(CExoString a0, CExoString a1, CExoString a2, int32_t a3)
{
    return CServerExoAppInternal__CheckStickyPlayerNameReserved(this, a0, a1, a2, a3);
}

void CServerExoAppInternal::ConnectionLibMainLoop()
{
    return CServerExoAppInternal__ConnectionLibMainLoop(this);
}

int32_t CServerExoAppInternal::ContinueMessageProcessing()
{
    return CServerExoAppInternal__ContinueMessageProcessing(this);
}

int32_t CServerExoAppInternal::CopyModuleToCurrentGame(CExoString& a0, CExoString& a1, uint16_t a2)
{
    return CServerExoAppInternal__CopyModuleToCurrentGame(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::CreateServerVaultLostAndFound()
{
    return CServerExoAppInternal__CreateServerVaultLostAndFound(this);
}

void CServerExoAppInternal::DealWithLoadGameError(uint32_t a0)
{
    return CServerExoAppInternal__DealWithLoadGameError(this, a0);
}

int32_t CServerExoAppInternal::EndGame(const CExoString& a0)
{
    return CServerExoAppInternal__EndGame(this, a0);
}

int32_t CServerExoAppInternal::ExportAllPlayers()
{
    return CServerExoAppInternal__ExportAllPlayers(this);
}

int32_t CServerExoAppInternal::ExportPlayer(CNWSPlayer* a0)
{
    return CServerExoAppInternal__ExportPlayer(this, a0);
}

CExoLinkedListTemplatedunsignedlong* CServerExoAppInternal::GetActiveExclusionList()
{
    return CServerExoAppInternal__GetActiveExclusionList(this);
}

unsigned char CServerExoAppInternal::GetActivePauseState()
{
    return CServerExoAppInternal__GetActivePauseState(this);
}

CWorldTimer* CServerExoAppInternal::GetActiveTimer(uint32_t a0)
{
    return CServerExoAppInternal__GetActiveTimer(this, a0);
}

CNWSArea* CServerExoAppInternal::GetAreaByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetAreaByGameObjectID(this, a0);
}

CNWSAreaOfEffectObject* CServerExoAppInternal::GetAreaOfEffectByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetAreaOfEffectByGameObjectID(this, a0);
}

CExoString CServerExoAppInternal::GetBannedListString()
{
    return CServerExoAppInternal__GetBannedListString(this);
}

CNWSPlayer* CServerExoAppInternal::GetClientObjectByObjectId(uint32_t a0)
{
    return CServerExoAppInternal__GetClientObjectByObjectId(this, a0);
}

CNWSClient* CServerExoAppInternal::GetClientObjectByPlayerId(uint32_t a0, unsigned char a1)
{
    return CServerExoAppInternal__GetClientObjectByPlayerId(this, a0, a1);
}

CNWSCreature* CServerExoAppInternal::GetCreatureByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetCreatureByGameObjectID(this, a0);
}

int32_t CServerExoAppInternal::GetDifficultyOption(int32_t a0)
{
    return CServerExoAppInternal__GetDifficultyOption(this, a0);
}

CNWSDoor* CServerExoAppInternal::GetDoorByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetDoorByGameObjectID(this, a0);
}

CNWSEncounter* CServerExoAppInternal::GetEncounterByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetEncounterByGameObjectID(this, a0);
}

void CServerExoAppInternal::GetExtendedServerInfo(CExtendedServerInfo* a0)
{
    return CServerExoAppInternal__GetExtendedServerInfo(this, a0);
}

int32_t CServerExoAppInternal::GetFactionOfObject(uint32_t a0, int32_t* a1)
{
    return CServerExoAppInternal__GetFactionOfObject(this, a0, a1);
}

uint32_t CServerExoAppInternal::GetFirstPCObject()
{
    return CServerExoAppInternal__GetFirstPCObject(this);
}

CGameObject* CServerExoAppInternal::GetGameObject(uint32_t a0)
{
    return CServerExoAppInternal__GetGameObject(this, a0);
}

CExoString CServerExoAppInternal::GetHostedPublicInternetAddressAndPort()
{
    return CServerExoAppInternal__GetHostedPublicInternetAddressAndPort(this);
}

int32_t CServerExoAppInternal::GetIsCDKeyOnBannedList(CExoString a0)
{
    return CServerExoAppInternal__GetIsCDKeyOnBannedList(this, a0);
}

int32_t CServerExoAppInternal::GetIsIPOnBannedList(CExoString a0)
{
    return CServerExoAppInternal__GetIsIPOnBannedList(this, a0);
}

int32_t CServerExoAppInternal::GetIsPlayerNameOnBannedList(CExoString a0)
{
    return CServerExoAppInternal__GetIsPlayerNameOnBannedList(this, a0);
}

CNWSItem* CServerExoAppInternal::GetItemByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetItemByGameObjectID(this, a0);
}

CNWSModule* CServerExoAppInternal::GetModule()
{
    return CServerExoAppInternal__GetModule(this);
}

CNWSModule* CServerExoAppInternal::GetModuleByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetModuleByGameObjectID(this, a0);
}

int32_t CServerExoAppInternal::GetModuleExists(const CExoString& a0)
{
    return CServerExoAppInternal__GetModuleExists(this, a0);
}

int32_t CServerExoAppInternal::GetModuleLanguage()
{
    return CServerExoAppInternal__GetModuleLanguage(this);
}

CExoString CServerExoAppInternal::GetModuleName()
{
    return CServerExoAppInternal__GetModuleName(this);
}

uint32_t CServerExoAppInternal::GetNextPCObject()
{
    return CServerExoAppInternal__GetNextPCObject(this);
}

int32_t CServerExoAppInternal::GetPauseState(unsigned char a0)
{
    return CServerExoAppInternal__GetPauseState(this, a0);
}

CNWSPlaceable* CServerExoAppInternal::GetPlaceableByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetPlaceableByGameObjectID(this, a0);
}

int32_t CServerExoAppInternal::GetPlayerAddressData(uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    return CServerExoAppInternal__GetPlayerAddressData(this, a0, a1, a2, a3, a4);
}

uint32_t CServerExoAppInternal::GetPlayerIDByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetPlayerIDByGameObjectID(this, a0);
}

int32_t CServerExoAppInternal::GetPlayerLanguage(uint32_t a0)
{
    return CServerExoAppInternal__GetPlayerLanguage(this, a0);
}

CExoString CServerExoAppInternal::GetPlayerListString()
{
    return CServerExoAppInternal__GetPlayerListString(this);
}

CExoString CServerExoAppInternal::GetPortalListString()
{
    return CServerExoAppInternal__GetPortalListString(this);
}

void CServerExoAppInternal::GetServerInfoFromIniFile()
{
    return CServerExoAppInternal__GetServerInfoFromIniFile(this);
}

CNWSSoundObject* CServerExoAppInternal::GetSoundObjectByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetSoundObjectByGameObjectID(this, a0);
}

CNWSStore* CServerExoAppInternal::GetStoreByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetStoreByGameObjectID(this, a0);
}

CNWSTrigger* CServerExoAppInternal::GetTriggerByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetTriggerByGameObjectID(this, a0);
}

CNWSWaypoint* CServerExoAppInternal::GetWaypointByGameObjectID(uint32_t a0)
{
    return CServerExoAppInternal__GetWaypointByGameObjectID(this, a0);
}

void CServerExoAppInternal::HandleGameSpyToServerMessage(int32_t a0, void* a1, int32_t a2)
{
    return CServerExoAppInternal__HandleGameSpyToServerMessage(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::HandleMessage(uint32_t a0, unsigned char* a1, uint32_t a2, int32_t a3)
{
    return CServerExoAppInternal__HandleMessage(this, a0, a1, a2, a3);
}

void CServerExoAppInternal::HandleOldServerVaultMigration(CExoString a0, CExoString a1, CExoString a2)
{
    return CServerExoAppInternal__HandleOldServerVaultMigration(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::Initialize()
{
    return CServerExoAppInternal__Initialize(this);
}

void CServerExoAppInternal::InitializeNetLayer()
{
    return CServerExoAppInternal__InitializeNetLayer(this);
}

void CServerExoAppInternal::InitiateModuleForPlayer(void* a0)
{
    return CServerExoAppInternal__InitiateModuleForPlayer(this, a0);
}

int32_t CServerExoAppInternal::IsOnActiveExclusionList(uint32_t a0)
{
    return CServerExoAppInternal__IsOnActiveExclusionList(this, a0);
}

int32_t CServerExoAppInternal::IsOnExclusionList(uint32_t a0)
{
    return CServerExoAppInternal__IsOnExclusionList(this, a0);
}

int32_t CServerExoAppInternal::IsPlayerNameSticky()
{
    return CServerExoAppInternal__IsPlayerNameSticky(this);
}

int32_t CServerExoAppInternal::LoadCharacterFinish(CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    return CServerExoAppInternal__LoadCharacterFinish(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::LoadCharacterStart(unsigned char a0, CNWSPlayer* a1, CResRef a2, void* a3, uint32_t a4)
{
    return CServerExoAppInternal__LoadCharacterStart(this, a0, a1, a2, a3, a4);
}

int32_t CServerExoAppInternal::LoadGame(uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3)
{
    return CServerExoAppInternal__LoadGame(this, a0, a1, a2, a3);
}

int32_t CServerExoAppInternal::LoadModule(CExoString a0, int32_t a1, CNWSPlayer* a2)
{
    return CServerExoAppInternal__LoadModule(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::LoadPrimaryPlayer(CNWSPlayer* a0)
{
    return CServerExoAppInternal__LoadPrimaryPlayer(this, a0);
}

int32_t CServerExoAppInternal::MainLoop()
{
    return CServerExoAppInternal__MainLoop(this);
}

void CServerExoAppInternal::MarkUpdateClientsForObject(uint32_t a0)
{
    return CServerExoAppInternal__MarkUpdateClientsForObject(this, a0);
}

void CServerExoAppInternal::MovePlayerToArea(void* a0)
{
    return CServerExoAppInternal__MovePlayerToArea(this, a0);
}

void CServerExoAppInternal::OnCDChange()
{
    return CServerExoAppInternal__OnCDChange(this);
}

void CServerExoAppInternal::OnExit()
{
    return CServerExoAppInternal__OnExit(this);
}

void CServerExoAppInternal::OnGainFocus()
{
    return CServerExoAppInternal__OnGainFocus(this);
}

void CServerExoAppInternal::OnLostFocus()
{
    return CServerExoAppInternal__OnLostFocus(this);
}

void CServerExoAppInternal::OnVideoChange()
{
    return CServerExoAppInternal__OnVideoChange(this);
}

void CServerExoAppInternal::PlayerListChange(uint32_t a0, int32_t a1, int32_t a2)
{
    return CServerExoAppInternal__PlayerListChange(this, a0, a1, a2);
}

void CServerExoAppInternal::PushMessageOverWall(unsigned char* a0, uint32_t a1)
{
    return CServerExoAppInternal__PushMessageOverWall(this, a0, a1);
}

void CServerExoAppInternal::QuarantineInvalidCharacter(void* a0, uint32_t a1)
{
    return CServerExoAppInternal__QuarantineInvalidCharacter(this, a0, a1);
}

void CServerExoAppInternal::ReadBannedLists()
{
    return CServerExoAppInternal__ReadBannedLists(this);
}

void CServerExoAppInternal::RemoveCDKeyFromBannedList(CExoString a0)
{
    return CServerExoAppInternal__RemoveCDKeyFromBannedList(this, a0);
}

void CServerExoAppInternal::RemoveFromExclusionList(uint32_t a0, unsigned char a1)
{
    return CServerExoAppInternal__RemoveFromExclusionList(this, a0, a1);
}

void CServerExoAppInternal::RemoveIPFromBannedList(CExoString a0)
{
    return CServerExoAppInternal__RemoveIPFromBannedList(this, a0);
}

void CServerExoAppInternal::RemovePCFromWorld(CNWSPlayer* a0)
{
    return CServerExoAppInternal__RemovePCFromWorld(this, a0);
}

int32_t CServerExoAppInternal::RemovePendingAuthorization(uint32_t a0)
{
    return CServerExoAppInternal__RemovePendingAuthorization(this, a0);
}

void CServerExoAppInternal::RemovePlayerNameFromBannedList(CExoString a0)
{
    return CServerExoAppInternal__RemovePlayerNameFromBannedList(this, a0);
}

void CServerExoAppInternal::RemoveSubNetProfile(uint32_t a0)
{
    return CServerExoAppInternal__RemoveSubNetProfile(this, a0);
}

void CServerExoAppInternal::ReprocessExclusionListActions(unsigned char a0)
{
    return CServerExoAppInternal__ReprocessExclusionListActions(this, a0);
}

uint32_t CServerExoAppInternal::ResolvePlayerByFirstName(const CExoString& a0)
{
    return CServerExoAppInternal__ResolvePlayerByFirstName(this, a0);
}

void CServerExoAppInternal::RestartNetLayer()
{
    return CServerExoAppInternal__RestartNetLayer(this);
}

int32_t CServerExoAppInternal::RunModule()
{
    return CServerExoAppInternal__RunModule(this);
}

int32_t CServerExoAppInternal::SaveGame(uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3, int32_t a4, CExoString& a5)
{
    return CServerExoAppInternal__SaveGame(this, a0, a1, a2, a3, a4, a5);
}

int32_t CServerExoAppInternal::SendCharacterQuery(CNWSPlayer* a0)
{
    return CServerExoAppInternal__SendCharacterQuery(this, a0);
}

int32_t CServerExoAppInternal::SendEnhancedHeartbeatToMasterServer()
{
    return CServerExoAppInternal__SendEnhancedHeartbeatToMasterServer(this);
}

int32_t CServerExoAppInternal::SendEnteringStartNewModuleMessage()
{
    return CServerExoAppInternal__SendEnteringStartNewModuleMessage(this);
}

int32_t CServerExoAppInternal::SendExitingStartNewModuleMessage(int32_t a0)
{
    return CServerExoAppInternal__SendExitingStartNewModuleMessage(this, a0);
}

int32_t CServerExoAppInternal::SendHeartbeatToRelay()
{
    return CServerExoAppInternal__SendHeartbeatToRelay(this);
}

int32_t CServerExoAppInternal::SendStartStallEvent(uint32_t a0)
{
    return CServerExoAppInternal__SendStartStallEvent(this, a0);
}

int32_t CServerExoAppInternal::SetDDCipherForModule(CExoString a0)
{
    return CServerExoAppInternal__SetDDCipherForModule(this, a0);
}

void CServerExoAppInternal::SetEstimatedSaveSize(const CExoString& a0, uint16_t a1)
{
    return CServerExoAppInternal__SetEstimatedSaveSize(this, a0, a1);
}

void CServerExoAppInternal::SetGameSpyReporting(int32_t a0)
{
    return CServerExoAppInternal__SetGameSpyReporting(this, a0);
}

int32_t CServerExoAppInternal::SetNetworkAddressBan(uint32_t a0, CExoString a1, int32_t a2)
{
    return CServerExoAppInternal__SetNetworkAddressBan(this, a0, a1, a2);
}

void CServerExoAppInternal::SetPauseState(unsigned char a0, int32_t a1)
{
    return CServerExoAppInternal__SetPauseState(this, a0, a1);
}

void CServerExoAppInternal::Shutdown(int32_t a0, int32_t a1)
{
    return CServerExoAppInternal__Shutdown(this, a0, a1);
}

void CServerExoAppInternal::ShutdownNetLayer()
{
    return CServerExoAppInternal__ShutdownNetLayer(this);
}

void CServerExoAppInternal::ShutdownServerProfiles()
{
    return CServerExoAppInternal__ShutdownServerProfiles(this);
}

void CServerExoAppInternal::StallEventSaveGame()
{
    return CServerExoAppInternal__StallEventSaveGame(this);
}

int32_t CServerExoAppInternal::StartNewModule(CExoString& a0)
{
    return CServerExoAppInternal__StartNewModule(this, a0);
}

void CServerExoAppInternal::StartServices()
{
    return CServerExoAppInternal__StartServices(this);
}

void CServerExoAppInternal::StartShutdownTimer(uint64_t a0, uint64_t a1)
{
    return CServerExoAppInternal__StartShutdownTimer(this, a0, a1);
}

void CServerExoAppInternal::StopServices()
{
    return CServerExoAppInternal__StopServices(this);
}

int32_t CServerExoAppInternal::StorePlayerCharacters()
{
    return CServerExoAppInternal__StorePlayerCharacters(this);
}

int32_t CServerExoAppInternal::StripColorTokens(CExoString& a0)
{
    return CServerExoAppInternal__StripColorTokens(this, a0);
}

int32_t CServerExoAppInternal::Test_Unit_Script_Compile()
{
    return CServerExoAppInternal__Test_Unit_Script_Compile(this);
}

int32_t CServerExoAppInternal::Test_Unit_Script_Run()
{
    return CServerExoAppInternal__Test_Unit_Script_Run(this);
}

void CServerExoAppInternal::TogglePauseState(unsigned char a0)
{
    return CServerExoAppInternal__TogglePauseState(this, a0);
}

void CServerExoAppInternal::Uninitialize()
{
    return CServerExoAppInternal__Uninitialize(this);
}

int32_t CServerExoAppInternal::UnloadModule()
{
    return CServerExoAppInternal__UnloadModule(this);
}

void CServerExoAppInternal::UnlockBiowareModule(CNWSModule* a0)
{
    return CServerExoAppInternal__UnlockBiowareModule(this, a0);
}

int32_t CServerExoAppInternal::UpdateAutoSaveTimer()
{
    return CServerExoAppInternal__UpdateAutoSaveTimer(this);
}

void CServerExoAppInternal::UpdateClientGameObjects(int32_t a0)
{
    return CServerExoAppInternal__UpdateClientGameObjects(this, a0);
}

void CServerExoAppInternal::UpdateClientGameObjectsForPlayer(CNWSPlayer* a0, int32_t a1, uint64_t a2)
{
    return CServerExoAppInternal__UpdateClientGameObjectsForPlayer(this, a0, a1, a2);
}

void CServerExoAppInternal::UpdateClientsForObject(uint32_t a0)
{
    return CServerExoAppInternal__UpdateClientsForObject(this, a0);
}

int32_t CServerExoAppInternal::UpdateLogHeartbeatTimer(uint64_t a0)
{
    return CServerExoAppInternal__UpdateLogHeartbeatTimer(this, a0);
}

int32_t CServerExoAppInternal::UpdateShutdownTimer(uint64_t a0)
{
    return CServerExoAppInternal__UpdateShutdownTimer(this, a0);
}

void CServerExoAppInternal::UpdateWindowTitle()
{
    return CServerExoAppInternal__UpdateWindowTitle(this);
}

uint32_t CServerExoAppInternal::ValidateCreateServerCharacter(CNWSPlayer* a0, void* a1, uint32_t a2)
{
    return CServerExoAppInternal__ValidateCreateServerCharacter(this, a0, a1, a2);
}

int32_t CServerExoAppInternal::ValidatePlayerLogin(void* a0)
{
    return CServerExoAppInternal__ValidatePlayerLogin(this, a0);
}

void CServerExoAppInternal::VomitServerOptionsToLog()
{
    return CServerExoAppInternal__VomitServerOptionsToLog(this);
}

void CServerExoAppInternal::WriteServerInfoToIniFile()
{
    return CServerExoAppInternal__WriteServerInfoToIniFile(this);
}

void CServerExoAppInternal__CServerExoAppInternalCtor(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CServerExoAppInternalCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CServerExoAppInternal__CServerExoAppInternalDtor(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CServerExoAppInternalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CServerExoAppInternal__AddCDKeyToBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddCDKeyToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__AddCharListRequest(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddCharListRequest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__AddIPToBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddIPToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__AddPendingAuthorization(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddPendingAuthorization);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__AddPlayerNameToBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddPlayerNameToBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__AddSubNetProfile(CServerExoAppInternal* thisPtr, uint32_t a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddSubNetProfile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoAppInternal__AddSubNetProfileRecvSize(CServerExoAppInternal* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddSubNetProfileRecvSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__AddSubNetProfileSendSize(CServerExoAppInternal* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddSubNetProfileSendSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__AddToExclusionList(CServerExoAppInternal* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AddToExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerExoAppInternal__AdmitNetworkAddress(CServerExoAppInternal* thisPtr, uint32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AdmitNetworkAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerExoAppInternal__AdmitPlayerName(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__AdmitPlayerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__CheckMasterServerTranslation(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CheckMasterServerTranslation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__CheckStickyPlayerNameReserved(CServerExoAppInternal* thisPtr, CExoString a0, CExoString a1, CExoString a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString, CExoString, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CheckStickyPlayerNameReserved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CServerExoAppInternal__ConnectionLibMainLoop(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ConnectionLibMainLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__ContinueMessageProcessing(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ContinueMessageProcessing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__CopyModuleToCurrentGame(CServerExoAppInternal* thisPtr, CExoString& a0, CExoString& a1, uint16_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString&, CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CopyModuleToCurrentGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__CreateServerVaultLostAndFound(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__CreateServerVaultLostAndFound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__DealWithLoadGameError(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__DealWithLoadGameError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__EndGame(CServerExoAppInternal* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__EndGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__ExportAllPlayers(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ExportAllPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__ExportPlayer(CServerExoAppInternal* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ExportPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLinkedListTemplatedunsignedlong* CServerExoAppInternal__GetActiveExclusionList(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoLinkedListTemplatedunsignedlong*(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetActiveExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CServerExoAppInternal__GetActivePauseState(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetActivePauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CWorldTimer* CServerExoAppInternal__GetActiveTimer(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CWorldTimer*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetActiveTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSArea* CServerExoAppInternal__GetAreaByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetAreaByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSAreaOfEffectObject* CServerExoAppInternal__GetAreaOfEffectByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSAreaOfEffectObject*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetAreaOfEffectByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CServerExoAppInternal__GetBannedListString(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetBannedListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlayer* CServerExoAppInternal__GetClientObjectByObjectId(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSPlayer*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetClientObjectByObjectId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSClient* CServerExoAppInternal__GetClientObjectByPlayerId(CServerExoAppInternal* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = CNWSClient*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetClientObjectByPlayerId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSCreature* CServerExoAppInternal__GetCreatureByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSCreature*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetCreatureByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetDifficultyOption(CServerExoAppInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetDifficultyOption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSDoor* CServerExoAppInternal__GetDoorByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSDoor*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetDoorByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSEncounter* CServerExoAppInternal__GetEncounterByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSEncounter*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetEncounterByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__GetExtendedServerInfo(CServerExoAppInternal* thisPtr, CExtendedServerInfo* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExtendedServerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetExtendedServerInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetFactionOfObject(CServerExoAppInternal* thisPtr, uint32_t a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetFactionOfObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CServerExoAppInternal__GetFirstPCObject(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetFirstPCObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CGameObject* CServerExoAppInternal__GetGameObject(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CGameObject*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CServerExoAppInternal__GetHostedPublicInternetAddressAndPort(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetHostedPublicInternetAddressAndPort);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__GetIsCDKeyOnBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetIsCDKeyOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetIsIPOnBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetIsIPOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetIsPlayerNameOnBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetIsPlayerNameOnBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSItem* CServerExoAppInternal__GetItemByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetItemByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSModule* CServerExoAppInternal__GetModule(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CNWSModule*(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSModule* CServerExoAppInternal__GetModuleByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSModule*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetModuleByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetModuleExists(CServerExoAppInternal* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetModuleExists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetModuleLanguage(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetModuleLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoAppInternal__GetModuleName(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CServerExoAppInternal__GetNextPCObject(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetNextPCObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__GetPauseState(CServerExoAppInternal* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSPlaceable* CServerExoAppInternal__GetPlaceableByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSPlaceable*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPlaceableByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetPlayerAddressData(CServerExoAppInternal* thisPtr, uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPlayerAddressData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CServerExoAppInternal__GetPlayerIDByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPlayerIDByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__GetPlayerLanguage(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPlayerLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CServerExoAppInternal__GetPlayerListString(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPlayerListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CServerExoAppInternal__GetPortalListString(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetPortalListString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__GetServerInfoFromIniFile(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetServerInfoFromIniFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSSoundObject* CServerExoAppInternal__GetSoundObjectByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSSoundObject*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetSoundObjectByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSStore* CServerExoAppInternal__GetStoreByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSStore*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetStoreByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSTrigger* CServerExoAppInternal__GetTriggerByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSTrigger*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetTriggerByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSWaypoint* CServerExoAppInternal__GetWaypointByGameObjectID(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSWaypoint*(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__GetWaypointByGameObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__HandleGameSpyToServerMessage(CServerExoAppInternal* thisPtr, int32_t a0, void* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__HandleGameSpyToServerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__HandleMessage(CServerExoAppInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, unsigned char*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__HandleMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CServerExoAppInternal__HandleOldServerVaultMigration(CServerExoAppInternal* thisPtr, CExoString a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__HandleOldServerVaultMigration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__Initialize(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__InitializeNetLayer(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__InitializeNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__InitiateModuleForPlayer(CServerExoAppInternal* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__InitiateModuleForPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__IsOnActiveExclusionList(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__IsOnActiveExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__IsOnExclusionList(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__IsOnExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__IsPlayerNameSticky(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__IsPlayerNameSticky);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__LoadCharacterFinish(CServerExoAppInternal* thisPtr, CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__LoadCharacterFinish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__LoadCharacterStart(CServerExoAppInternal* thisPtr, unsigned char a0, CNWSPlayer* a1, CResRef a2, void* a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char, CNWSPlayer*, CResRef, void*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__LoadCharacterStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CServerExoAppInternal__LoadGame(CServerExoAppInternal* thisPtr, uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, CExoString&, CExoString&, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__LoadGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CServerExoAppInternal__LoadModule(CServerExoAppInternal* thisPtr, CExoString a0, int32_t a1, CNWSPlayer* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString, int32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__LoadModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__LoadPrimaryPlayer(CServerExoAppInternal* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__LoadPrimaryPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__MainLoop(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__MainLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__MarkUpdateClientsForObject(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__MarkUpdateClientsForObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__MovePlayerToArea(CServerExoAppInternal* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__MovePlayerToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__OnCDChange(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__OnCDChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__OnExit(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__OnExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__OnGainFocus(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__OnGainFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__OnLostFocus(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__OnLostFocus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__OnVideoChange(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__OnVideoChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__PlayerListChange(CServerExoAppInternal* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__PlayerListChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoAppInternal__PushMessageOverWall(CServerExoAppInternal* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__PushMessageOverWall);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__QuarantineInvalidCharacter(CServerExoAppInternal* thisPtr, void* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, void*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__QuarantineInvalidCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__ReadBannedLists(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ReadBannedLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__RemoveCDKeyFromBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemoveCDKeyFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__RemoveFromExclusionList(CServerExoAppInternal* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemoveFromExclusionList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__RemoveIPFromBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemoveIPFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__RemovePCFromWorld(CServerExoAppInternal* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemovePCFromWorld);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__RemovePendingAuthorization(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemovePendingAuthorization);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__RemovePlayerNameFromBannedList(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemovePlayerNameFromBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__RemoveSubNetProfile(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RemoveSubNetProfile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__ReprocessExclusionListActions(CServerExoAppInternal* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ReprocessExclusionListActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CServerExoAppInternal__ResolvePlayerByFirstName(CServerExoAppInternal* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ResolvePlayerByFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__RestartNetLayer(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RestartNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__RunModule(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__RunModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__SaveGame(CServerExoAppInternal* thisPtr, uint32_t a0, CExoString& a1, CExoString& a2, CNWSPlayer* a3, int32_t a4, CExoString& a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SaveGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CServerExoAppInternal__SendCharacterQuery(CServerExoAppInternal* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendCharacterQuery);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__SendEnhancedHeartbeatToMasterServer(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendEnhancedHeartbeatToMasterServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__SendEnteringStartNewModuleMessage(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendEnteringStartNewModuleMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__SendExitingStartNewModuleMessage(CServerExoAppInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendExitingStartNewModuleMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__SendHeartbeatToRelay(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendHeartbeatToRelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__SendStartStallEvent(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SendStartStallEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__SetDDCipherForModule(CServerExoAppInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SetDDCipherForModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__SetEstimatedSaveSize(CServerExoAppInternal* thisPtr, const CExoString& a0, uint16_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, const CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SetEstimatedSaveSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__SetGameSpyReporting(CServerExoAppInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SetGameSpyReporting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__SetNetworkAddressBan(CServerExoAppInternal* thisPtr, uint32_t a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SetNetworkAddressBan);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoAppInternal__SetPauseState(CServerExoAppInternal* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__SetPauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__Shutdown(CServerExoAppInternal* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__Shutdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__ShutdownNetLayer(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ShutdownNetLayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__ShutdownServerProfiles(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ShutdownServerProfiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__StallEventSaveGame(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StallEventSaveGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__StartNewModule(CServerExoAppInternal* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StartNewModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__StartServices(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StartServices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__StartShutdownTimer(CServerExoAppInternal* thisPtr, uint64_t a0, uint64_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint64_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StartShutdownTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerExoAppInternal__StopServices(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StopServices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__StorePlayerCharacters(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StorePlayerCharacters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__StripColorTokens(CServerExoAppInternal* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__StripColorTokens);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__Test_Unit_Script_Compile(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__Test_Unit_Script_Compile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__Test_Unit_Script_Run(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__Test_Unit_Script_Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__TogglePauseState(CServerExoAppInternal* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__TogglePauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__Uninitialize(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__Uninitialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerExoAppInternal__UnloadModule(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UnloadModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__UnlockBiowareModule(CServerExoAppInternal* thisPtr, CNWSModule* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UnlockBiowareModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__UpdateAutoSaveTimer(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateAutoSaveTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__UpdateClientGameObjects(CServerExoAppInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateClientGameObjects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__UpdateClientGameObjectsForPlayer(CServerExoAppInternal* thisPtr, CNWSPlayer* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateClientGameObjectsForPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerExoAppInternal__UpdateClientsForObject(CServerExoAppInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateClientsForObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__UpdateLogHeartbeatTimer(CServerExoAppInternal* thisPtr, uint64_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateLogHeartbeatTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerExoAppInternal__UpdateShutdownTimer(CServerExoAppInternal* thisPtr, uint64_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateShutdownTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__UpdateWindowTitle(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__UpdateWindowTitle);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CServerExoAppInternal__ValidateCreateServerCharacter(CServerExoAppInternal* thisPtr, CNWSPlayer* a0, void* a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, CNWSPlayer*, void*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ValidateCreateServerCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerExoAppInternal__ValidatePlayerLogin(CServerExoAppInternal* thisPtr, void* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerExoAppInternal*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__ValidatePlayerLogin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerExoAppInternal__VomitServerOptionsToLog(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__VomitServerOptionsToLog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerExoAppInternal__WriteServerInfoToIniFile(CServerExoAppInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerExoAppInternal__WriteServerInfoToIniFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
