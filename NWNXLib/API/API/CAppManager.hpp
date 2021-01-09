#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CAppManager)
#endif

struct CClientExoApp;
struct CNWReentrantServerStats;
struct CNWTileSetManager;
struct CObjectTableManager;
struct CServerExoApp;


typedef int BOOL;


struct CAppManager
{
    CClientExoApp * m_pClientExoApp;
    CServerExoApp * m_pServerExoApp;
    CNWTileSetManager * m_pNWTileSetManager;
    CObjectTableManager * m_pClientObjectTableManager;
    CObjectTableManager * m_pServerObjectTableManager;
    CNWReentrantServerStats * m_pReentrantServerStats;
    BOOL m_bDungeonMasterEXERunning;
    uint32_t m_nApplicationId;
    BOOL m_bMultiplayerEnabled;
    BOOL m_bWasPaused;
    BOOL m_bDigitalDistributionModule;
    uint8_t * m_pDDCipher;
    uint32_t m_nDDOffset;
    uint32_t m_nPlayerTimeout;
    BOOL m_bLogModelErrors;

    CAppManager();
    ~CAppManager();
    CObjectTableManager * GetObjectTableManager(uint32_t dwClientServer);
    void DoSaveGameScreenShot(CExoString & sFile);
    void ShowServerMem();
    void CreateServer(void );
    void DestroyServer();
    void SetDungeonMasterEXERunning(BOOL bDM);
    BOOL GetDungeonMasterEXERunning();
    BOOL SpawnExternalScriptDebugger();
    void DisplayScriptDebuggerPopup();
    void DestroyScriptDebuggerPopup();
    BOOL SetDDCipherForModule(CExoString moduleName);
    uint8_t ReadProgressFromINI(uint8_t m_nCampaign);
    // CExoLocString GetHostedModuleDescription();
    // CExoString GetHostedPublicInternetAddressAndPort();
    void ConnectToServer(CExoString sAddress, BOOL bPasswordRequired);


#ifdef NWN_CLASS_EXTENSION_CAppManager
    NWN_CLASS_EXTENSION_CAppManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAppManager)
#endif

