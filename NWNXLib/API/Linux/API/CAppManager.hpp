#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CClientExoApp;
struct CNWReentrantServerStats;
struct CNWTileSetManager;
struct CObjectTableManager;
struct CServerExoApp;

struct CAppManager
{
    CClientExoApp* m_pClientExoApp;
    CServerExoApp* m_pServerExoApp;
    CNWTileSetManager* m_pNWTileSetManager;
    CObjectTableManager* m_pClientObjectTableManager;
    CObjectTableManager* m_pServerObjectTableManager;
    CNWReentrantServerStats* m_pReentrantServerStats;
    int32_t m_bDungeonMasterEXERunning;
    uint32_t m_nApplicationId;
    int32_t m_bMultiplayerEnabled;
    int32_t m_bWasPaused;
    int32_t m_bDigitalDistributionModule;
    uint8_t* m_pDDCipher;
    uint32_t m_nDDOffset;
    uint32_t m_nPlayerTimeout;
    int32_t m_bLogModelErrors;

    // The below are auto generated stubs.
    CAppManager(const CAppManager&) = default;
    CAppManager& operator=(const CAppManager&) = default;

    CAppManager();
    ~CAppManager();
    void ConnectToServer(CExoString, int32_t);
    void CreateServer();
    void DestroyScriptDebuggerPopup();
    void DestroyServer();
    void DisplayScriptDebuggerPopup();
    void DoSaveGameScreenShot(CExoString&);
    int32_t GetDungeonMasterEXERunning();
    CObjectTableManager* GetObjectTableManager(uint32_t);
    unsigned char GetProgressFromCodeword(CExoString&);
    unsigned char ReadProgressFromINI(unsigned char);
    int32_t SetDDCipherForModule(CExoString);
    void SetDungeonMasterEXERunning(int32_t);
    void ShowServerMem();
    int32_t SpawnExternalScriptDebugger();
};

void CAppManager__CAppManagerCtor(CAppManager* thisPtr);
void CAppManager__CAppManagerDtor(CAppManager* thisPtr);
void CAppManager__ConnectToServer(CAppManager* thisPtr, CExoString, int32_t);
void CAppManager__CreateServer(CAppManager* thisPtr);
void CAppManager__DestroyScriptDebuggerPopup(CAppManager* thisPtr);
void CAppManager__DestroyServer(CAppManager* thisPtr);
void CAppManager__DisplayScriptDebuggerPopup(CAppManager* thisPtr);
void CAppManager__DoSaveGameScreenShot(CAppManager* thisPtr, CExoString&);
int32_t CAppManager__GetDungeonMasterEXERunning(CAppManager* thisPtr);
CObjectTableManager* CAppManager__GetObjectTableManager(CAppManager* thisPtr, uint32_t);
unsigned char CAppManager__GetProgressFromCodeword(CAppManager* thisPtr, CExoString&);
unsigned char CAppManager__ReadProgressFromINI(CAppManager* thisPtr, unsigned char);
int32_t CAppManager__SetDDCipherForModule(CAppManager* thisPtr, CExoString);
void CAppManager__SetDungeonMasterEXERunning(CAppManager* thisPtr, int32_t);
void CAppManager__ShowServerMem(CAppManager* thisPtr);
int32_t CAppManager__SpawnExternalScriptDebugger(CAppManager* thisPtr);

}

}
