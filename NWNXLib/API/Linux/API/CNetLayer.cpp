#include "CNetLayer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CBaseExoApp.hpp"
#include "CNetLayerInternal.hpp"
#include "CNetLayerPlayerInfo.hpp"
#include "CNetLayerSessionInfo.hpp"

namespace NWNXLib {

namespace API {

CNetLayer::CNetLayer()
{
    CNetLayer__CNetLayerCtor(this);
}

CNetLayer::~CNetLayer()
{
    CNetLayer__CNetLayerDtor(this);
}

void CNetLayer::CleanUpEnumerateSpecific()
{
    return CNetLayer__CleanUpEnumerateSpecific(this);
}

void CNetLayer::ClearSessionInfoChanged(uint32_t a0)
{
    return CNetLayer__ClearSessionInfoChanged(this, a0);
}

int32_t CNetLayer::CloseStandardConnection(int32_t a0)
{
    return CNetLayer__CloseStandardConnection(this, a0);
}

int32_t CNetLayer::DisconnectFromSession()
{
    return CNetLayer__DisconnectFromSession(this);
}

int32_t CNetLayer::DisconnectPlayer(uint32_t a0, uint32_t a1, int32_t a2, const CExoString& a3)
{
    return CNetLayer__DisconnectPlayer(this, a0, a1, a2, a3);
}

int32_t CNetLayer::DropConnectionToServer()
{
    return CNetLayer__DropConnectionToServer(this);
}

int32_t CNetLayer::EndConnectToSession()
{
    return CNetLayer__EndConnectToSession(this);
}

int32_t CNetLayer::EndEnumerateSessions()
{
    return CNetLayer__EndEnumerateSessions(this);
}

int32_t CNetLayer::EndEnumerateSessionsSection(uint32_t a0)
{
    return CNetLayer__EndEnumerateSessionsSection(this, a0);
}

int32_t CNetLayer::EndInternetAddressTranslation()
{
    return CNetLayer__EndInternetAddressTranslation(this);
}

int32_t CNetLayer::EndPing(uint32_t a0)
{
    return CNetLayer__EndPing(this, a0);
}

int32_t CNetLayer::EndProtocol(uint32_t a0)
{
    return CNetLayer__EndProtocol(this, a0);
}

int32_t CNetLayer::EndServerMode()
{
    return CNetLayer__EndServerMode(this);
}

int32_t CNetLayer::GetAnySessionsEnumerated()
{
    return CNetLayer__GetAnySessionsEnumerated(this);
}

int32_t CNetLayer::GetAnyWindowBehind()
{
    return CNetLayer__GetAnyWindowBehind(this);
}

int32_t CNetLayer::GetClientConnected()
{
    return CNetLayer__GetClientConnected(this);
}

uint32_t CNetLayer::GetConnectionError()
{
    return CNetLayer__GetConnectionError(this);
}

int32_t CNetLayer::GetConnectionsMustBeValidated()
{
    return CNetLayer__GetConnectionsMustBeValidated(this);
}

CExoString CNetLayer::GetDisconnectReason()
{
    return CNetLayer__GetDisconnectReason(this);
}

uint32_t CNetLayer::GetDisconnectStrref()
{
    return CNetLayer__GetDisconnectStrref(this);
}

int32_t CNetLayer::GetEnumerateSpecificOverRelay()
{
    return CNetLayer__GetEnumerateSpecificOverRelay(this);
}

CBaseExoApp* CNetLayer::GetExoApp()
{
    return CNetLayer__GetExoApp(this);
}

void CNetLayer::GetExoNet()
{
    return CNetLayer__GetExoNet(this);
}

uint16_t CNetLayer::GetExpansionPackReqd()
{
    return CNetLayer__GetExpansionPackReqd(this);
}

CExoString CNetLayer::GetGameMasterPassword()
{
    return CNetLayer__GetGameMasterPassword(this);
}

int32_t CNetLayer::GetGameMasterPermision()
{
    return CNetLayer__GetGameMasterPermision(this);
}

uint32_t CNetLayer::GetInternetAddressTranslationStatus(unsigned char* a0)
{
    return CNetLayer__GetInternetAddressTranslationStatus(this, a0);
}

int32_t CNetLayer::GetIPBySessionId(uint32_t a0, CExoString* a1)
{
    return CNetLayer__GetIPBySessionId(this, a0, a1);
}

CExoString CNetLayer::GetLocalAdapterString(uint32_t a0, uint32_t a1)
{
    return CNetLayer__GetLocalAdapterString(this, a0, a1);
}

uint32_t CNetLayer::GetLocalPrivileges(uint32_t a0)
{
    return CNetLayer__GetLocalPrivileges(this, a0);
}

int32_t CNetLayer::GetMessageFromStandardConnection(int32_t* a0, char** a1, int32_t* a2)
{
    return CNetLayer__GetMessageFromStandardConnection(this, a0, a1, a2);
}

int32_t CNetLayer::GetNumberLocalAdapters(uint32_t a0)
{
    return CNetLayer__GetNumberLocalAdapters(this, a0);
}

int32_t CNetLayer::GetPasswordRequired()
{
    return CNetLayer__GetPasswordRequired(this);
}

CExoString CNetLayer::GetPlayerAddress(uint32_t a0)
{
    return CNetLayer__GetPlayerAddress(this, a0);
}

int32_t CNetLayer::GetPlayerAddressData(uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    return CNetLayer__GetPlayerAddressData(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayer::GetPlayerAddressRelayed(uint32_t a0)
{
    return CNetLayer__GetPlayerAddressRelayed(this, a0);
}

CNetLayerPlayerInfo* CNetLayer::GetPlayerInfo(uint32_t a0)
{
    return CNetLayer__GetPlayerInfo(this, a0);
}

CExoString CNetLayer::GetPlayerPassword()
{
    return CNetLayer__GetPlayerPassword(this);
}

uint32_t CNetLayer::GetPortBySessionId(uint32_t a0)
{
    return CNetLayer__GetPortBySessionId(this, a0);
}

CExoString CNetLayer::GetRouterPortMapDescription()
{
    return CNetLayer__GetRouterPortMapDescription(this);
}

uint32_t CNetLayer::GetSendUDPSocket()
{
    return CNetLayer__GetSendUDPSocket(this);
}

CExoString CNetLayer::GetServerAdminPassword()
{
    return CNetLayer__GetServerAdminPassword(this);
}

int32_t CNetLayer::GetServerConnected()
{
    return CNetLayer__GetServerConnected(this);
}

CExoString CNetLayer::GetServerNetworkAddress()
{
    return CNetLayer__GetServerNetworkAddress(this);
}

CNetLayerSessionInfo* CNetLayer::GetSessionInfo(uint32_t a0)
{
    return CNetLayer__GetSessionInfo(this, a0);
}

int32_t CNetLayer::GetSessionInfoChanged(uint32_t a0)
{
    return CNetLayer__GetSessionInfoChanged(this, a0);
}

uint32_t CNetLayer::GetSessionMaxPlayers()
{
    return CNetLayer__GetSessionMaxPlayers(this);
}

CExoString CNetLayer::GetSessionName()
{
    return CNetLayer__GetSessionName(this);
}

uint32_t CNetLayer::GetSessionSectionStart(uint32_t a0)
{
    return CNetLayer__GetSessionSectionStart(this, a0);
}

uint32_t CNetLayer::GetUDPRecievePort()
{
    return CNetLayer__GetUDPRecievePort(this);
}

int32_t CNetLayer::Initialize(CBaseExoApp* a0)
{
    return CNetLayer__Initialize(this, a0);
}

int32_t CNetLayer::IsConnectedToLocalhost()
{
    return CNetLayer__IsConnectedToLocalhost(this);
}

int32_t CNetLayer::MessageArrived(uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNetLayer__MessageArrived(this, a0, a1, a2, a3);
}

int32_t CNetLayer::OpenStandardConnection(int32_t a0, CExoString a1, int32_t a2)
{
    return CNetLayer__OpenStandardConnection(this, a0, a1, a2);
}

int32_t CNetLayer::PlayerIdToConnectionId(uint32_t a0, uint32_t* a1)
{
    return CNetLayer__PlayerIdToConnectionId(this, a0, a1);
}

void CNetLayer::ProcessReceivedFrames(int32_t a0)
{
    return CNetLayer__ProcessReceivedFrames(this, a0);
}

int32_t CNetLayer::RequestExtendedServerInfo(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNetLayer__RequestExtendedServerInfo(this, a0, a1, a2);
}

int32_t CNetLayer::RequestServerDetails(uint32_t a0)
{
    return CNetLayer__RequestServerDetails(this, a0);
}

int32_t CNetLayer::SendMessageToAddress(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNetLayer__SendMessageToAddress(this, a0, a1, a2);
}

int32_t CNetLayer::SendMessageToPlayer(uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    return CNetLayer__SendMessageToPlayer(this, a0, a1, a2, a3);
}

int32_t CNetLayer::SendMessageToStandardConnection(int32_t a0, char* a1, int32_t a2)
{
    return CNetLayer__SendMessageToStandardConnection(this, a0, a1, a2);
}

void CNetLayer::SetConnectionsDisallowed(int32_t a0)
{
    return CNetLayer__SetConnectionsDisallowed(this, a0);
}

void CNetLayer::SetConnectionsMustBeValidated(int32_t a0)
{
    return CNetLayer__SetConnectionsMustBeValidated(this, a0);
}

void CNetLayer::SetDisconnectReason(const CExoString& a0)
{
    return CNetLayer__SetDisconnectReason(this, a0);
}

void CNetLayer::SetDisconnectStrref(uint32_t a0)
{
    return CNetLayer__SetDisconnectStrref(this, a0);
}

void CNetLayer::SetEnumerateSpecificOverRelay(int32_t a0, const char* a1)
{
    return CNetLayer__SetEnumerateSpecificOverRelay(this, a0, a1);
}

void CNetLayer::SetExpansionPackReqd(uint16_t a0)
{
    return CNetLayer__SetExpansionPackReqd(this, a0);
}

int32_t CNetLayer::SetGameMasterPassword(CExoString a0)
{
    return CNetLayer__SetGameMasterPassword(this, a0);
}

void CNetLayer::SetMasterServerInternetAddress(const unsigned char* a0, uint32_t a1)
{
    return CNetLayer__SetMasterServerInternetAddress(this, a0, a1);
}

void CNetLayer::SetMstServerPassword(CExoString a0)
{
    return CNetLayer__SetMstServerPassword(this, a0);
}

int32_t CNetLayer::SetPlayerPassword(CExoString a0)
{
    return CNetLayer__SetPlayerPassword(this, a0);
}

int32_t CNetLayer::SetServerAdminPassword(CExoString a0)
{
    return CNetLayer__SetServerAdminPassword(this, a0);
}

void CNetLayer::SetServerLanguage(int32_t a0)
{
    return CNetLayer__SetServerLanguage(this, a0);
}

void CNetLayer::SetSessionInfoChanged(uint32_t a0, int32_t a1)
{
    return CNetLayer__SetSessionInfoChanged(this, a0, a1);
}

void CNetLayer::SetSessionMaxPlayers(uint32_t a0)
{
    return CNetLayer__SetSessionMaxPlayers(this, a0);
}

void CNetLayer::SetSessionName(CExoString a0)
{
    return CNetLayer__SetSessionName(this, a0);
}

void CNetLayer::SetUpPlayBackConnection()
{
    return CNetLayer__SetUpPlayBackConnection(this);
}

int32_t CNetLayer::ShutDown()
{
    return CNetLayer__ShutDown(this);
}

void CNetLayer::ShutDownClientInterfaceWithReason(uint32_t a0, const CExoString& a1)
{
    return CNetLayer__ShutDownClientInterfaceWithReason(this, a0, a1);
}

int32_t CNetLayer::StartConnectToSession(uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3, const CExoString& a4, uint32_t a5, uint32_t a6, const CExoString& a7, const CExoString& a8)
{
    return CNetLayer__StartConnectToSession(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNetLayer::StartEnumerateSessions(uint32_t* a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    return CNetLayer__StartEnumerateSessions__0(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayer::StartEnumerateSessions(uint32_t a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    return CNetLayer__StartEnumerateSessions__1(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayer::StartEnumerateSessionsSection(uint32_t a0, uint32_t a1, CExoString* a2)
{
    return CNetLayer__StartEnumerateSessionsSection(this, a0, a1, a2);
}

int32_t CNetLayer::StartInternetAddressTranslation(CExoString a0, uint32_t a1, uint32_t a2)
{
    return CNetLayer__StartInternetAddressTranslation(this, a0, a1, a2);
}

int32_t CNetLayer::StartPing(uint32_t a0)
{
    return CNetLayer__StartPing(this, a0);
}

int32_t CNetLayer::StartProtocol(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CNetLayer__StartProtocol(this, a0, a1, a2, a3);
}

int32_t CNetLayer::StartServerMode(CExoString a0, uint32_t a1)
{
    return CNetLayer__StartServerMode(this, a0, a1);
}

void CNetLayer::StoreMessage(unsigned char* a0, uint32_t a1)
{
    return CNetLayer__StoreMessage(this, a0, a1);
}

int32_t CNetLayer::TranslateAddressFromString(char* a0, uint32_t* a1, unsigned char* a2, unsigned char* a3, uint32_t* a4)
{
    return CNetLayer__TranslateAddressFromString(this, a0, a1, a2, a3, a4);
}

int32_t CNetLayer::UpdateStatusLoop(uint32_t a0)
{
    return CNetLayer__UpdateStatusLoop(this, a0);
}

void CNetLayer__CNetLayerCtor(CNetLayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__CNetLayerCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNetLayer__CNetLayerDtor(CNetLayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__CNetLayerDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNetLayer__CleanUpEnumerateSpecific(CNetLayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__CleanUpEnumerateSpecific);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayer__ClearSessionInfoChanged(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__ClearSessionInfoChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__CloseStandardConnection(CNetLayer* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__CloseStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__DisconnectFromSession(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__DisconnectFromSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__DisconnectPlayer(CNetLayer* thisPtr, uint32_t a0, uint32_t a1, int32_t a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t, int32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__DisconnectPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayer__DropConnectionToServer(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__DropConnectionToServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__EndConnectToSession(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndConnectToSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__EndEnumerateSessions(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndEnumerateSessions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__EndEnumerateSessionsSection(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndEnumerateSessionsSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__EndInternetAddressTranslation(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndInternetAddressTranslation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__EndPing(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndPing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__EndProtocol(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndProtocol);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__EndServerMode(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__EndServerMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetAnySessionsEnumerated(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetAnySessionsEnumerated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetAnyWindowBehind(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetAnyWindowBehind);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetClientConnected(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetClientConnected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetConnectionError(CNetLayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetConnectionError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetConnectionsMustBeValidated(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetConnectionsMustBeValidated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetDisconnectReason(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetDisconnectReason);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetDisconnectStrref(CNetLayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetDisconnectStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetEnumerateSpecificOverRelay(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetEnumerateSpecificOverRelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CBaseExoApp* CNetLayer__GetExoApp(CNetLayer* thisPtr)
{
    using FuncPtrType = CBaseExoApp*(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetExoApp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayer__GetExoNet(CNetLayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetExoNet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

uint16_t CNetLayer__GetExpansionPackReqd(CNetLayer* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetExpansionPackReqd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetGameMasterPassword(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetGameMasterPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetGameMasterPermision(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetGameMasterPermision);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetInternetAddressTranslationStatus(CNetLayer* thisPtr, unsigned char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetInternetAddressTranslationStatus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__GetIPBySessionId(CNetLayer* thisPtr, uint32_t a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetIPBySessionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CNetLayer__GetLocalAdapterString(CNetLayer* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetLocalAdapterString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNetLayer__GetLocalPrivileges(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetLocalPrivileges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__GetMessageFromStandardConnection(CNetLayer* thisPtr, int32_t* a0, char** a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, int32_t*, char**, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetMessageFromStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__GetNumberLocalAdapters(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetNumberLocalAdapters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__GetPasswordRequired(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPasswordRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetPlayerAddress(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPlayerAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__GetPlayerAddressData(CNetLayer* thisPtr, uint32_t a0, uint32_t* a1, unsigned char** a2, unsigned char** a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPlayerAddressData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayer__GetPlayerAddressRelayed(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPlayerAddressRelayed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNetLayerPlayerInfo* CNetLayer__GetPlayerInfo(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNetLayerPlayerInfo*(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPlayerInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNetLayer__GetPlayerPassword(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPlayerPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetPortBySessionId(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetPortBySessionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNetLayer__GetRouterPortMapDescription(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetRouterPortMapDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetSendUDPSocket(CNetLayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSendUDPSocket);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetServerAdminPassword(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetServerAdminPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__GetServerConnected(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetServerConnected);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetServerNetworkAddress(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetServerNetworkAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNetLayerSessionInfo* CNetLayer__GetSessionInfo(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNetLayerSessionInfo*(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSessionInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__GetSessionInfoChanged(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSessionInfoChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayer__GetSessionMaxPlayers(CNetLayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSessionMaxPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNetLayer__GetSessionName(CNetLayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSessionName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNetLayer__GetSessionSectionStart(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetSessionSectionStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNetLayer__GetUDPRecievePort(CNetLayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__GetUDPRecievePort);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__Initialize(CNetLayer* thisPtr, CBaseExoApp* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CBaseExoApp*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__IsConnectedToLocalhost(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__IsConnectedToLocalhost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__MessageArrived(CNetLayer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__MessageArrived);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayer__OpenStandardConnection(CNetLayer* thisPtr, int32_t a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, int32_t, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__OpenStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__PlayerIdToConnectionId(CNetLayer* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__PlayerIdToConnectionId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayer__ProcessReceivedFrames(CNetLayer* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__ProcessReceivedFrames);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__RequestExtendedServerInfo(CNetLayer* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__RequestExtendedServerInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__RequestServerDetails(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__RequestServerDetails);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__SendMessageToAddress(CNetLayer* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SendMessageToAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__SendMessageToPlayer(CNetLayer* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, unsigned char*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SendMessageToPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayer__SendMessageToStandardConnection(CNetLayer* thisPtr, int32_t a0, char* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, int32_t, char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SendMessageToStandardConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNetLayer__SetConnectionsDisallowed(CNetLayer* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetConnectionsDisallowed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetConnectionsMustBeValidated(CNetLayer* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetConnectionsMustBeValidated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetDisconnectReason(CNetLayer* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetDisconnectReason);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetDisconnectStrref(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetDisconnectStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetEnumerateSpecificOverRelay(CNetLayer* thisPtr, int32_t a0, const char* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int32_t, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetEnumerateSpecificOverRelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayer__SetExpansionPackReqd(CNetLayer* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetExpansionPackReqd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__SetGameMasterPassword(CNetLayer* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetGameMasterPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetMasterServerInternetAddress(CNetLayer* thisPtr, const unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, const unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetMasterServerInternetAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayer__SetMstServerPassword(CNetLayer* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetMstServerPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__SetPlayerPassword(CNetLayer* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetPlayerPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__SetServerAdminPassword(CNetLayer* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetServerAdminPassword);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetServerLanguage(CNetLayer* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetServerLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetSessionInfoChanged(CNetLayer* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetSessionInfoChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayer__SetSessionMaxPlayers(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetSessionMaxPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetSessionName(CNetLayer* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetSessionName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayer__SetUpPlayBackConnection(CNetLayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__SetUpPlayBackConnection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNetLayer__ShutDown(CNetLayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__ShutDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayer__ShutDownClientInterfaceWithReason(CNetLayer* thisPtr, uint32_t a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__ShutDownClientInterfaceWithReason);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayer__StartConnectToSession(CNetLayer* thisPtr, uint32_t a0, const CExoString& a1, int32_t a2, int32_t a3, const CExoString& a4, uint32_t a5, uint32_t a6, const CExoString& a7, const CExoString& a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartConnectToSession);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNetLayer__StartEnumerateSessions__0(CNetLayer* thisPtr, uint32_t* a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t*, int32_t, unsigned char*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartEnumerateSessions__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayer__StartEnumerateSessions__1(CNetLayer* thisPtr, uint32_t a0, int32_t a1, unsigned char* a2, uint16_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, int32_t, unsigned char*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartEnumerateSessions__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayer__StartEnumerateSessionsSection(CNetLayer* thisPtr, uint32_t a0, uint32_t a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartEnumerateSessionsSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__StartInternetAddressTranslation(CNetLayer* thisPtr, CExoString a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CExoString, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartInternetAddressTranslation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNetLayer__StartPing(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartPing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayer__StartProtocol(CNetLayer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartProtocol);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNetLayer__StartServerMode(CNetLayer* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StartServerMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNetLayer__StoreMessage(CNetLayer* thisPtr, unsigned char* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayer*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__StoreMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayer__TranslateAddressFromString(CNetLayer* thisPtr, char* a0, uint32_t* a1, unsigned char* a2, unsigned char* a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, char*, uint32_t*, unsigned char*, unsigned char*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__TranslateAddressFromString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNetLayer__UpdateStatusLoop(CNetLayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayer__UpdateStatusLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
