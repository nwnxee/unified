#pragma once
#include "nwn_api.hpp"

#include "CAutoSave.hpp"
#include "CExoString.hpp"
#include "CJoiningRestrictions.hpp"
#include "CPersistantWorldOptions.hpp"
#include "CPlayOptions.hpp"
#include "CResetOption.hpp"
#include "CServerNetOptions.hpp"
#include "CServerOptionLookup.hpp"
#include "NWSyncAdvertisement.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerInfo)
#endif



typedef int BOOL;


struct CServerInfo
{
    int32_t m_nDataChangedFlags;
    int16_t m_nServerMode;
    CExoString m_sModuleName;
    CExoString m_sServerSettings;
    CExoString m_sModulesList;
    CExoString m_sPlayerList;
    CExoString m_sBannedList;
    CExoString m_sPortalList;
    CExoString m_sSavegameList;
    CExoString m_sCharactervaultList;
    CJoiningRestrictions m_JoiningRestrictions;
    CPlayOptions m_PlayOptions;
    CResetOption m_ResetOption;
    CAutoSave m_AutoSave;
    CPersistantWorldOptions m_PersistantWorldOptions;
    CServerNetOptions m_NetOptions;
    NWSyncAdvertisement m_nwsyncAdvertisedData;
    BOOL m_bNWSyncPublishHaks;
    BOOL m_bConversationMultiPlayer;
    BOOL m_bConversationMultiPlayerViewOnly;
    int32_t m_nDifficulty;
    CServerOptionLookup m_pOptionsTable[50];

    CServerInfo(void );
    void SetDifficultyLevel(int32_t nDifficulty, BOOL bChangePVP = false);
    int FindOptionIndex(CExoString sOptionCategory, CExoString sOptionName);


#ifdef NWN_CLASS_EXTENSION_CServerInfo
    NWN_CLASS_EXTENSION_CServerInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerInfo)
#endif

