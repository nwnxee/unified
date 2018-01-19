#pragma once

#include <cstdint>

#include "CAutoSave.hpp"
#include "CExoString.hpp"
#include "CJoiningRestrictions.hpp"
#include "CPersistantWorldOptions.hpp"
#include "CPlayOptions.hpp"
#include "CResetOption.hpp"
#include "CServerNetOptions.hpp"
#include "CServerOptionLookup.hpp"

namespace NWNXLib {

namespace API {

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
    int32_t m_bConversationMultiPlayer;
    int32_t m_bConversationMultiPlayerViewOnly;
    int32_t m_nDifficulty;
    CServerOptionLookup m_pOptionsTable[50];

    // The below are auto generated stubs.
    CServerInfo(const CServerInfo&) = default;
    CServerInfo& operator=(const CServerInfo&) = default;

    CServerInfo();
    int32_t FindOptionIndex(CExoString, CExoString);
    void SetDifficultyLevel(int32_t, int32_t);
};

void CServerInfo__CServerInfoCtor(CServerInfo* thisPtr);
int32_t CServerInfo__FindOptionIndex(CServerInfo* thisPtr, CExoString, CExoString);
void CServerInfo__SetDifficultyLevel(CServerInfo* thisPtr, int32_t, int32_t);

}

}
