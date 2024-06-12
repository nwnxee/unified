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
struct CServerExoApp;


typedef int BOOL;


struct CAppManager
{
    CClientExoApp * m_pClientExoApp;
    CServerExoApp * m_pServerExoApp;
    CNWTileSetManager * m_pNWTileSetManager;
    CNWReentrantServerStats * m_pReentrantServerStats;
    BOOL m_bDungeonMasterEXERunning;
    uint32_t m_nApplicationId;
    BOOL m_bMultiplayerEnabled;
    BOOL m_bWasPaused;
    uint32_t m_nPlayerTimeout;
    BOOL m_bLogModelErrors;

    CAppManager();
    ~CAppManager();
    void DoSaveGameScreenShot(CExoString & sFile);
    void ShowServerMem();
    void CreateServer(void );
    void DestroyServer();
    void SetDungeonMasterEXERunning(BOOL bDM);
    BOOL GetDungeonMasterEXERunning();
    void DisplayScriptDebuggerPopup();
    void DestroyScriptDebuggerPopup();
    uint8_t ReadProgressFromINI(uint8_t m_nCampaign);
    void ConnectToServer(CExoString sAddress, BOOL bPasswordRequired);
    class CWorldTimer * GetWorldTimer();
    CExoString GetCryptoKxPublicKeyBase64();
    CExoString GetPublicCdKey();
    uint8_t GetPlatformId() const;
    uint8_t GetLanguageId() const;
    CExoString GetAdvancedVersionString() const;


#ifdef NWN_CLASS_EXTENSION_CAppManager
    NWN_CLASS_EXTENSION_CAppManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAppManager)
#endif

