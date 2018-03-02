#include "CNetLayerInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CBaseExoApp.hpp"
#include "CExoArrayListTemplatedCExoString.hpp"
#include "CExoNet.hpp"
#include "CExoNetExtendableBuffer.hpp"
#include "CNetLayerSessionInfo.hpp"

namespace NWNXLib {

namespace API {

CNetLayerInternal::CNetLayerInternal()
{
    CNetLayerInternal__CNetLayerInternalCtor(this);
}

CNetLayerInternal::~CNetLayerInternal()
{
    CNetLayerInternal__CNetLayerInternalDtor(this);
}

int32_t CNetLayerInternal::BroadcastMessageToAddress(uint32_t a0, uint32_t a1, unsigned char* a2, uint32_t a3)
{
    return CNetLayerInternal__BroadcastMessageToAddress(this, a0, a1, a2, a3);
}

void CNetLayerInternal::CheckMasterServerTimeouts()
{
    return CNetLayerInternal__CheckMasterServerTimeouts(this);
}

void CNetLayerInternal::CleanUpEnumerateSpecific()
{
    return CNetLayerInternal__CleanUpEnumerateSpecific(this);
}

void CNetLayerInternal::ClearSessionInfoChanged(uint32_t a0)
{
    return CNetLayerInternal__ClearSessionInfoChanged(this, a0);
}

int32_t CNetLayerInternal::CloseStandardConnection(int32_t a0)
{
    return CNetLayerInternal__CloseStandardConnection(this, a0);
}

int32_t CNetLayerInternal::ConnectionIdToSlidingWindow(uint32_t a0, uint32_t* a1)
{
    return CNetLayerInternal__ConnectionIdToSlidingWindow(this, a0, a1);
}

uint32_t CNetLayerInternal::ConnectToSessionLoop()
{
    return CNetLayerInternal__ConnectToSessionLoop(this);
}

uint32_t CNetLayerInternal::CRCBlock(unsigned char* a0, uint32_t a1)
{
    return CNetLayerInternal__CRCBlock(this, a0, a1);
}

void CNetLayerInternal::CRCBuildTable()
{
    return CNetLayerInternal__CRCBuildTable(this);
}

void CNetLayerInternal::CRCEncodeFrame(unsigned char* a0, uint32_t a1)
{
    return CNetLayerInternal__CRCEncodeFrame(this, a0, a1);
}

int32_t CNetLayerInternal::CRCVerifyFrame(unsigned char* a0, uint32_t a1)
{
    return CNetLayerInternal__CRCVerifyFrame(this, a0, a1);
}

int32_t CNetLayerInternal::DisconnectFromSession()
{
    return CNetLayerInternal__DisconnectFromSession(this);
}

int32_t CNetLayerInternal::DisconnectPlayer(uint32_t a0, uint32_t a1, int32_t a2, int32_t a3, const CExoString& a4)
{
    return CNetLayerInternal__DisconnectPlayer(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal::DropConnectionToServer()
{
    return CNetLayerInternal__DropConnectionToServer(this);
}

int32_t CNetLayerInternal::EndConnectToSession()
{
    return CNetLayerInternal__EndConnectToSession(this);
}

int32_t CNetLayerInternal::EndEnumerateSessions()
{
    return CNetLayerInternal__EndEnumerateSessions(this);
}

int32_t CNetLayerInternal::EndEnumerateSessionsSection(uint32_t a0)
{
    return CNetLayerInternal__EndEnumerateSessionsSection(this, a0);
}

int32_t CNetLayerInternal::EndInternetAddressTranslation()
{
    return CNetLayerInternal__EndInternetAddressTranslation(this);
}

int32_t CNetLayerInternal::EndPing(uint32_t a0)
{
    return CNetLayerInternal__EndPing(this, a0);
}

int32_t CNetLayerInternal::EndProtocol(uint32_t a0)
{
    return CNetLayerInternal__EndProtocol(this, a0);
}

int32_t CNetLayerInternal::EndServerMode()
{
    return CNetLayerInternal__EndServerMode(this);
}

uint32_t CNetLayerInternal::EnumerateSessionsList(unsigned char a0)
{
    return CNetLayerInternal__EnumerateSessionsList(this, a0);
}

int32_t CNetLayerInternal::EnumerateSessionsLoop()
{
    return CNetLayerInternal__EnumerateSessionsLoop(this);
}

int32_t CNetLayerInternal::FindPlayerName(CExoString a0, uint32_t a1)
{
    return CNetLayerInternal__FindPlayerName(this, a0, a1);
}

uint32_t CNetLayerInternal::GetConnectionError()
{
    return CNetLayerInternal__GetConnectionError(this);
}

CBaseExoApp* CNetLayerInternal::GetExoApp()
{
    return CNetLayerInternal__GetExoApp(this);
}

CExoString CNetLayerInternal::GetGameMasterPassword()
{
    return CNetLayerInternal__GetGameMasterPassword(this);
}

uint32_t CNetLayerInternal::GetInternetAddressTranslationStatus(unsigned char* a0)
{
    return CNetLayerInternal__GetInternetAddressTranslationStatus(this, a0);
}

int32_t CNetLayerInternal::GetIPBySessionId(uint32_t a0, CExoString* a1)
{
    return CNetLayerInternal__GetIPBySessionId(this, a0, a1);
}

CExoString CNetLayerInternal::GetLocalAdapterString(uint32_t a0, uint32_t a1)
{
    return CNetLayerInternal__GetLocalAdapterString(this, a0, a1);
}

uint32_t CNetLayerInternal::GetLocalPrivileges(uint32_t a0)
{
    return CNetLayerInternal__GetLocalPrivileges(this, a0);
}

int32_t CNetLayerInternal::GetMessageFromStandardConnection(int32_t* a0, char** a1, int32_t* a2)
{
    return CNetLayerInternal__GetMessageFromStandardConnection(this, a0, a1, a2);
}

int32_t CNetLayerInternal::GetNumberLocalAdapters(uint32_t a0)
{
    return CNetLayerInternal__GetNumberLocalAdapters(this, a0);
}

int32_t CNetLayerInternal::GetPasswordRequired()
{
    return CNetLayerInternal__GetPasswordRequired(this);
}

CExoString CNetLayerInternal::GetPlayerAddress(uint32_t a0)
{
    return CNetLayerInternal__GetPlayerAddress(this, a0);
}

int32_t CNetLayerInternal::GetPlayerAddressData(uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    return CNetLayerInternal__GetPlayerAddressData(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal::GetPlayerAddressRelayed(uint32_t a0)
{
    return CNetLayerInternal__GetPlayerAddressRelayed(this, a0);
}

CExoString CNetLayerInternal::GetPlayerPassword()
{
    return CNetLayerInternal__GetPlayerPassword(this);
}

uint32_t CNetLayerInternal::GetPortBySessionId(uint32_t a0)
{
    return CNetLayerInternal__GetPortBySessionId(this, a0);
}

CExoString CNetLayerInternal::GetRouterPortMapDescription()
{
    return CNetLayerInternal__GetRouterPortMapDescription(this);
}

uint32_t CNetLayerInternal::GetSendUDPSocket()
{
    return CNetLayerInternal__GetSendUDPSocket(this);
}

CExoString CNetLayerInternal::GetServerAdminPassword()
{
    return CNetLayerInternal__GetServerAdminPassword(this);
}

int32_t CNetLayerInternal::GetServerConnected()
{
    return CNetLayerInternal__GetServerConnected(this);
}

CExoString CNetLayerInternal::GetServerNetworkAddress()
{
    return CNetLayerInternal__GetServerNetworkAddress(this);
}

uint32_t CNetLayerInternal::GetServerPlayerCount()
{
    return CNetLayerInternal__GetServerPlayerCount(this);
}

CNetLayerSessionInfo* CNetLayerInternal::GetSessionInfo(uint32_t a0)
{
    return CNetLayerInternal__GetSessionInfo(this, a0);
}

uint32_t CNetLayerInternal::GetSessionMaxPlayers()
{
    return CNetLayerInternal__GetSessionMaxPlayers(this);
}

CExoString CNetLayerInternal::GetSessionName()
{
    return CNetLayerInternal__GetSessionName(this);
}

uint32_t CNetLayerInternal::GetSessionSection(uint32_t a0)
{
    return CNetLayerInternal__GetSessionSection(this, a0);
}

uint32_t CNetLayerInternal::GetSessionSectionSize(uint32_t a0)
{
    return CNetLayerInternal__GetSessionSectionSize(this, a0);
}

uint32_t CNetLayerInternal::GetSessionSectionStart(uint32_t a0)
{
    return CNetLayerInternal__GetSessionSectionStart(this, a0);
}

uint32_t CNetLayerInternal::GetUDPRecievePort()
{
    return CNetLayerInternal__GetUDPRecievePort(this);
}

int32_t CNetLayerInternal::GetWindowSendIdByReceiveId(uint32_t a0, uint32_t* a1)
{
    return CNetLayerInternal__GetWindowSendIdByReceiveId(this, a0, a1);
}

int32_t CNetLayerInternal::HandleBNCRMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNCRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNCSMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNCSMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNDMMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNDMMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNDPMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNDPMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNDRMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNDRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNDSMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNDSMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNERMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNERMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNESMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNESMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNLMMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNLMMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNLRMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNLRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNVRMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNVRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNVSMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNVSMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNXIMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNXIMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::HandleBNXRMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__HandleBNXRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::Initialize(CBaseExoApp* a0)
{
    return CNetLayerInternal__Initialize(this, a0);
}

int32_t CNetLayerInternal::IsConnectedToLocalhost()
{
    return CNetLayerInternal__IsConnectedToLocalhost(this);
}

int32_t CNetLayerInternal::IsPlayerIpSameAsConnection(uint32_t a0, uint32_t a1)
{
    return CNetLayerInternal__IsPlayerIpSameAsConnection(this, a0, a1);
}

int32_t CNetLayerInternal::MessageArrived(uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNetLayerInternal__MessageArrived(this, a0, a1, a2, a3);
}

int32_t CNetLayerInternal::NonWindowMessages(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__NonWindowMessages(this, a0, a1, a2);
}

int32_t CNetLayerInternal::OpenStandardConnection(int32_t a0, CExoString a1, int32_t a2)
{
    return CNetLayerInternal__OpenStandardConnection(this, a0, a1, a2);
}

int32_t CNetLayerInternal::PacketizeSendMessageToPlayer(uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    return CNetLayerInternal__PacketizeSendMessageToPlayer(this, a0, a1, a2, a3);
}

int32_t CNetLayerInternal::PacketizeSmallMessageToPlayer(uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    return CNetLayerInternal__PacketizeSmallMessageToPlayer(this, a0, a1, a2, a3);
}

int32_t CNetLayerInternal::PlacePacketInSendQueues(uint32_t a0, int32_t a1, unsigned char* a2, uint32_t a3, int32_t a4)
{
    return CNetLayerInternal__PlacePacketInSendQueues(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal::PlayerIdToConnectionId(uint32_t a0, uint32_t* a1)
{
    return CNetLayerInternal__PlayerIdToConnectionId(this, a0, a1);
}

int32_t CNetLayerInternal::PlayerIdToSlidingWindow(uint32_t a0, uint32_t* a1)
{
    return CNetLayerInternal__PlayerIdToSlidingWindow(this, a0, a1);
}

void CNetLayerInternal::ProcessReceivedFrames(int32_t a0)
{
    return CNetLayerInternal__ProcessReceivedFrames(this, a0);
}

int32_t CNetLayerInternal::PurgeConnections()
{
    return CNetLayerInternal__PurgeConnections(this);
}

int32_t CNetLayerInternal::RequestExtendedServerInfo(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNetLayerInternal__RequestExtendedServerInfo(this, a0, a1, a2);
}

void CNetLayerInternal::ResetEnumerateSessionsList(unsigned char a0)
{
    return CNetLayerInternal__ResetEnumerateSessionsList(this, a0);
}

int32_t CNetLayerInternal::SendBNCRMessage(uint32_t a0, unsigned char a1, uint32_t a2)
{
    return CNetLayerInternal__SendBNCRMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::SendBNCSMessage(uint32_t a0, unsigned char a1, int32_t a2, int32_t a3, const CExoString& a4, const CExoString& a5, const CExoString& a6, uint32_t& a7)
{
    return CNetLayerInternal__SendBNCSMessage(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNetLayerInternal::SendBNDMMessage()
{
    return CNetLayerInternal__SendBNDMMessage(this);
}

void CNetLayerInternal::SendBNDPMessage(uint32_t a0, uint32_t a1, const CExoString& a2)
{
    return CNetLayerInternal__SendBNDPMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::SendBNDSMessage(uint32_t a0)
{
    return CNetLayerInternal__SendBNDSMessage(this, a0);
}

int32_t CNetLayerInternal::SendBNESDirectMessageToAddress(CExoString a0, unsigned char a1)
{
    return CNetLayerInternal__SendBNESDirectMessageToAddress(this, a0, a1);
}

int32_t CNetLayerInternal::SendBNLMMessage(uint32_t a0, uint32_t a1)
{
    return CNetLayerInternal__SendBNLMMessage(this, a0, a1);
}

int32_t CNetLayerInternal::SendBNVRMessage(uint32_t a0, unsigned char a1)
{
    return CNetLayerInternal__SendBNVRMessage(this, a0, a1);
}

int32_t CNetLayerInternal::SendBNVSMessage(const CExoArrayListTemplatedCExoString* a0, const CExoString& a1, const CExoString& a2)
{
    return CNetLayerInternal__SendBNVSMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::SendDirectMessage(uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    return CNetLayerInternal__SendDirectMessage(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal::SendMessageToAddress(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__SendMessageToAddress(this, a0, a1, a2);
}

int32_t CNetLayerInternal::SendMessageToPlayer(uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    return CNetLayerInternal__SendMessageToPlayer(this, a0, a1, a2, a3);
}

int32_t CNetLayerInternal::SendMessageToStandardConnection(int32_t a0, char* a1, int32_t a2)
{
    return CNetLayerInternal__SendMessageToStandardConnection(this, a0, a1, a2);
}

int32_t CNetLayerInternal::SetGameMasterPassword(CExoString a0)
{
    return CNetLayerInternal__SetGameMasterPassword(this, a0);
}

void CNetLayerInternal::SetMasterServerInternetAddress(const unsigned char* a0, uint32_t a1)
{
    return CNetLayerInternal__SetMasterServerInternetAddress(this, a0, a1);
}

uint32_t CNetLayerInternal::SetNetworkAddressData(uint32_t a0, unsigned char* a1, unsigned char* a2, uint32_t a3, RelayModeChange a4, const char* a5)
{
    return CNetLayerInternal__SetNetworkAddressData(this, a0, a1, a2, a3, a4, a5);
}

void CNetLayerInternal::SetPlayerConnected(uint32_t a0)
{
    return CNetLayerInternal__SetPlayerConnected(this, a0);
}

int32_t CNetLayerInternal::SetPlayerPassword(CExoString a0)
{
    return CNetLayerInternal__SetPlayerPassword(this, a0);
}

int32_t CNetLayerInternal::SetServerAdminPassword(CExoString a0)
{
    return CNetLayerInternal__SetServerAdminPassword(this, a0);
}

void CNetLayerInternal::SetServerLanguage(int32_t a0)
{
    return CNetLayerInternal__SetServerLanguage(this, a0);
}

void CNetLayerInternal::SetSessionInfoChanged(uint32_t a0, int32_t a1)
{
    return CNetLayerInternal__SetSessionInfoChanged(this, a0, a1);
}

void CNetLayerInternal::SetSessionMaxPlayers(uint32_t a0)
{
    return CNetLayerInternal__SetSessionMaxPlayers(this, a0);
}

void CNetLayerInternal::SetSessionName(CExoString a0)
{
    return CNetLayerInternal__SetSessionName(this, a0);
}

int32_t CNetLayerInternal::SetSlidingWindow(uint32_t a0, uint32_t a1, uint32_t* a2)
{
    return CNetLayerInternal__SetSlidingWindow(this, a0, a1, a2);
}

void CNetLayerInternal::SetUpPlayBackConnection()
{
    return CNetLayerInternal__SetUpPlayBackConnection(this);
}

int32_t CNetLayerInternal::ShutDown()
{
    return CNetLayerInternal__ShutDown(this);
}

void CNetLayerInternal::ShutDownClientInterfaceWithReason(uint32_t a0, const CExoString& a1)
{
    return CNetLayerInternal__ShutDownClientInterfaceWithReason(this, a0, a1);
}

int32_t CNetLayerInternal::StartConnectToSession(uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3, const CExoString& a4, uint32_t a5, uint32_t a6, const CExoString& a7, const CExoString& a8)
{
    return CNetLayerInternal__StartConnectToSession(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNetLayerInternal::StartEnumerateSessions(uint32_t* a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    return CNetLayerInternal__StartEnumerateSessions(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal::StartEnumerateSessionsSection(uint32_t a0, uint32_t a1, CExoString* a2)
{
    return CNetLayerInternal__StartEnumerateSessionsSection(this, a0, a1, a2);
}

int32_t CNetLayerInternal::StartInternetAddressTranslation(CExoString a0, uint32_t a1, uint32_t a2)
{
    return CNetLayerInternal__StartInternetAddressTranslation(this, a0, a1, a2);
}

int32_t CNetLayerInternal::StartPing(uint32_t a0)
{
    return CNetLayerInternal__StartPing(this, a0);
}

int32_t CNetLayerInternal::StartProtocol(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CNetLayerInternal__StartProtocol(this, a0, a1, a2, a3);
}

int32_t CNetLayerInternal::StartServerMode(CExoString a0, uint32_t a1)
{
    return CNetLayerInternal__StartServerMode(this, a0, a1);
}

void CNetLayerInternal::StoreMessage(unsigned char* a0, uint32_t a1)
{
    return CNetLayerInternal__StoreMessage(this, a0, a1);
}

int32_t CNetLayerInternal::UncompressMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayerInternal__UncompressMessage(this, a0, a1, a2);
}

int32_t CNetLayerInternal::UpdateStatusLoop(uint32_t a0)
{
    return CNetLayerInternal__UpdateStatusLoop(this, a0);
}

int32_t CNetLayerInternal::ValidatePlayerAgainstLastSuccessfulLogin(CExoString a0, CExoString a1)
{
    return CNetLayerInternal__ValidatePlayerAgainstLastSuccessfulLogin(this, a0, a1);
}

void CNetLayerInternal__CNetLayerInternalCtor(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CNetLayerInternalCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNetLayerInternal__CNetLayerInternalDtor(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CNetLayerInternalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNetLayerInternal__BroadcastMessageToAddress(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, unsigned char* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__BroadcastMessageToAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNetLayerInternal__CheckMasterServerTimeouts(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CheckMasterServerTimeouts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerInternal__CleanUpEnumerateSpecific(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CleanUpEnumerateSpecific);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerInternal__ClearSessionInfoChanged(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ClearSessionInfoChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__CloseStandardConnection(CNetLayerInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CloseStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__ConnectionIdToSlidingWindow(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ConnectionIdToSlidingWindow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNetLayerInternal__ConnectToSessionLoop(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ConnectToSessionLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__CRCBlock(CNetLayerInternal* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CRCBlock);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayerInternal__CRCBuildTable(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CRCBuildTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerInternal__CRCEncodeFrame(CNetLayerInternal* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CRCEncodeFrame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__CRCVerifyFrame(CNetLayerInternal* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__CRCVerifyFrame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__DisconnectFromSession(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__DisconnectFromSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__DisconnectPlayer(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, int32_t a2, int32_t a3, const CExoString& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, int32_t, int32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__DisconnectPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal__DropConnectionToServer(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__DropConnectionToServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__EndConnectToSession(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndConnectToSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__EndEnumerateSessions(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndEnumerateSessions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__EndEnumerateSessionsSection(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndEnumerateSessionsSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__EndInternetAddressTranslation(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndInternetAddressTranslation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__EndPing(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndPing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__EndProtocol(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndProtocol);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__EndServerMode(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EndServerMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__EnumerateSessionsList(CNetLayerInternal* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EnumerateSessionsList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__EnumerateSessionsLoop(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__EnumerateSessionsLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__FindPlayerName(CNetLayerInternal* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__FindPlayerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNetLayerInternal__GetConnectionError(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetConnectionError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CBaseExoApp* CNetLayerInternal__GetExoApp(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CBaseExoApp*(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetExoApp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayerInternal__GetGameMasterPassword(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetGameMasterPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__GetInternetAddressTranslationStatus(CNetLayerInternal* thisPtr, unsigned char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetInternetAddressTranslationStatus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__GetIPBySessionId(CNetLayerInternal* thisPtr, uint32_t a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetIPBySessionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CNetLayerInternal__GetLocalAdapterString(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetLocalAdapterString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNetLayerInternal__GetLocalPrivileges(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetLocalPrivileges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__GetMessageFromStandardConnection(CNetLayerInternal* thisPtr, int32_t* a0, char** a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t*, char**, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetMessageFromStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__GetNumberLocalAdapters(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetNumberLocalAdapters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__GetPasswordRequired(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPasswordRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayerInternal__GetPlayerAddress(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPlayerAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__GetPlayerAddressData(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPlayerAddressData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal__GetPlayerAddressRelayed(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPlayerAddressRelayed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNetLayerInternal__GetPlayerPassword(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPlayerPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__GetPortBySessionId(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetPortBySessionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNetLayerInternal__GetRouterPortMapDescription(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetRouterPortMapDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__GetSendUDPSocket(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSendUDPSocket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayerInternal__GetServerAdminPassword(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetServerAdminPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__GetServerConnected(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetServerConnected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayerInternal__GetServerNetworkAddress(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetServerNetworkAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__GetServerPlayerCount(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetServerPlayerCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNetLayerSessionInfo* CNetLayerInternal__GetSessionInfo(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNetLayerSessionInfo*(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayerInternal__GetSessionMaxPlayers(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionMaxPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayerInternal__GetSessionName(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayerInternal__GetSessionSection(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayerInternal__GetSessionSectionSize(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionSectionSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayerInternal__GetSessionSectionStart(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetSessionSectionStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayerInternal__GetUDPRecievePort(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetUDPRecievePort);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__GetWindowSendIdByReceiveId(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__GetWindowSendIdByReceiveId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__HandleBNCRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNCRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNCSMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNCSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNDMMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNDMMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNDPMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNDPMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNDRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNDRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNDSMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNDSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNERMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNERMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNESMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNESMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNLMMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNLMMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNLRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNLRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNVRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNVRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNVSMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNVSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNXIMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNXIMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__HandleBNXRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__HandleBNXRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__Initialize(CNetLayerInternal* thisPtr, CBaseExoApp* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CBaseExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__IsConnectedToLocalhost(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__IsConnectedToLocalhost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__IsPlayerIpSameAsConnection(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__IsPlayerIpSameAsConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__MessageArrived(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__MessageArrived);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayerInternal__NonWindowMessages(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__NonWindowMessages);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__OpenStandardConnection(CNetLayerInternal* thisPtr, int32_t a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__OpenStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__PacketizeSendMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PacketizeSendMessageToPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayerInternal__PacketizeSmallMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PacketizeSmallMessageToPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayerInternal__PlacePacketInSendQueues(CNetLayerInternal* thisPtr, uint32_t a0, int32_t a1, unsigned char* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, int32_t, unsigned char*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PlacePacketInSendQueues);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal__PlayerIdToConnectionId(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PlayerIdToConnectionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__PlayerIdToSlidingWindow(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PlayerIdToSlidingWindow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayerInternal__ProcessReceivedFrames(CNetLayerInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ProcessReceivedFrames);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__PurgeConnections(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__PurgeConnections);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__RequestExtendedServerInfo(CNetLayerInternal* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__RequestExtendedServerInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNetLayerInternal__ResetEnumerateSessionsList(CNetLayerInternal* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ResetEnumerateSessionsList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__SendBNCRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNCRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__SendBNCSMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char a1, int32_t a2, int32_t a3, const CExoString& a4, const CExoString& a5, const CExoString& a6, uint32_t& a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char, int32_t, int32_t, const CExoString&, const CExoString&, const CExoString&, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNCSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNetLayerInternal__SendBNDMMessage(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNDMMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerInternal__SendBNDPMessage(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNDPMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__SendBNDSMessage(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNDSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__SendBNESDirectMessageToAddress(CNetLayerInternal* thisPtr, CExoString a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNESDirectMessageToAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__SendBNLMMessage(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNLMMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__SendBNVRMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNVRMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__SendBNVSMessage(CNetLayerInternal* thisPtr, const CExoArrayListTemplatedCExoString* a0, const CExoString& a1, const CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, const CExoArrayListTemplatedCExoString*, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendBNVSMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__SendDirectMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendDirectMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal__SendMessageToAddress(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendMessageToAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__SendMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendMessageToPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayerInternal__SendMessageToStandardConnection(CNetLayerInternal* thisPtr, int32_t a0, char* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t, char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SendMessageToStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__SetGameMasterPassword(CNetLayerInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetGameMasterPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerInternal__SetMasterServerInternetAddress(CNetLayerInternal* thisPtr, const unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, const unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetMasterServerInternetAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNetLayerInternal__SetNetworkAddressData(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, unsigned char* a2, uint32_t a3, RelayModeChange a4, const char* a5)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, unsigned char*, uint32_t, RelayModeChange, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetNetworkAddressData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNetLayerInternal__SetPlayerConnected(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetPlayerConnected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__SetPlayerPassword(CNetLayerInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetPlayerPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__SetServerAdminPassword(CNetLayerInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetServerAdminPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerInternal__SetServerLanguage(CNetLayerInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetServerLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerInternal__SetSessionInfoChanged(CNetLayerInternal* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetSessionInfoChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayerInternal__SetSessionMaxPlayers(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetSessionMaxPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerInternal__SetSessionName(CNetLayerInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetSessionName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__SetSlidingWindow(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, uint32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetSlidingWindow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNetLayerInternal__SetUpPlayBackConnection(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__SetUpPlayBackConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayerInternal__ShutDown(CNetLayerInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ShutDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerInternal__ShutDownClientInterfaceWithReason(CNetLayerInternal* thisPtr, uint32_t a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ShutDownClientInterfaceWithReason);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__StartConnectToSession(CNetLayerInternal* thisPtr, uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3, const CExoString& a4, uint32_t a5, uint32_t a6, const CExoString& a7, const CExoString& a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartConnectToSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNetLayerInternal__StartEnumerateSessions(CNetLayerInternal* thisPtr, uint32_t* a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t*, int32_t, unsigned char*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartEnumerateSessions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayerInternal__StartEnumerateSessionsSection(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartEnumerateSessionsSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__StartInternetAddressTranslation(CNetLayerInternal* thisPtr, CExoString a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartInternetAddressTranslation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__StartPing(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartPing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__StartProtocol(CNetLayerInternal* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartProtocol);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayerInternal__StartServerMode(CNetLayerInternal* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StartServerMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayerInternal__StoreMessage(CNetLayerInternal* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerInternal*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__StoreMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerInternal__UncompressMessage(CNetLayerInternal* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__UncompressMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayerInternal__UpdateStatusLoop(CNetLayerInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__UpdateStatusLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerInternal__ValidatePlayerAgainstLastSuccessfulLogin(CNetLayerInternal* thisPtr, CExoString a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerInternal*, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerInternal__ValidatePlayerAgainstLastSuccessfulLogin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
