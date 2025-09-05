#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoResMan.hpp"
#include "API/CResGFF.hpp"
#include "API/CResStruct.hpp"
#include "API/NWPlayerCharacterList_st.hpp"
#include "API/CResList.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CExoLocStringInternal.hpp"

#include <algorithm>
#include <vector>
#include <sys/stat.h>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static BOOL SendServerToPlayerCharListHook(CNWSMessage* pMessage, CNWSPlayer* pPlayer);
static Hooks::Hook s_SendServerToPlayerCharListHook;

struct CharInfoWithFileTime
{
    NWPlayerCharacterList_st* pInfo;
    std::time_t fLastFileModified;
};

void SortCharListByLastPlayedDate() __attribute__((constructor));
void SortCharListByLastPlayedDate()
{
    if (!Config::Get<bool>("CHARLIST_SORT_BY_LAST_PLAYED_DATE", false))
        return;

    LOG_INFO("Character list will be sorted by last played date");
    s_SendServerToPlayerCharListHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerCharList, &SendServerToPlayerCharListHook, Hooks::Order::Final);
}

static void SetCharacterListIndex(NWPlayerCharacterList_st* pCharInfo, int nIndex)
{
    auto& pStrList = pCharInfo->sLocFirstName.m_pExoLocStringInternal->m_lstString;
    for (auto *pNode = pStrList.GetHeadPos(); pNode; pNode = pNode->pNext)
    {
        if (EXOLOCSTRING* sCharName = pStrList.GetAtPos(pNode))
        {
            sCharName->sString = CExoString::F("<c%c\x01\x01></c>", (char)(nIndex + 1)) + sCharName->sString;
        }
    }
}

static std::time_t GetBICFileTime(CExoString sVaultPath, NWPlayerCharacterList_st* pCharInfo)
{
    CExoString sFilename = sVaultPath + CExoString(pCharInfo->resFileName) + ".bic";
    struct stat fileStats;
    if (stat(sFilename.c_str(), &fileStats) == 0) 
        return fileStats.st_mtime;
    else
        return 0;
}

static void GetServerVaultBasePaths(CNWSPlayer* pPlayer, CExoString& sOutRootServerVault, CExoString& sOutPlayerServerVault)
{
    CServerExoApp* pExoApp = Globals::AppManager()->m_pServerExoApp;

    sOutRootServerVault = Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("SERVERVAULT");
    CExoString sPlayerdir;
    if (pExoApp->GetServerInfo()->m_PersistantWorldOptions.bServerVaultByPlayerName)
        sPlayerdir = pPlayer->GetPlayerName();
    else
        sPlayerdir = pExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID)->m_cCDKey.sPublic;

    sOutPlayerServerVault = sOutRootServerVault + sPlayerdir + "/";
}

static void SortCharacterListByLastPlayedDate(CNWSPlayer* pPlayer, const CExoArrayList<NWPlayerCharacterList_st*>& pCharList)
{
    std::vector<CharInfoWithFileTime> vecCharInfoWithTime;
    vecCharInfoWithTime.reserve(pCharList.num);

    CExoString sRootServerVault;
    CExoString sPlayerServerVault;
    GetServerVaultBasePaths(pPlayer, sRootServerVault, sPlayerServerVault);
    for (int i=0; i < pCharList.num; i++)
    {
        CharInfoWithFileTime ciwft;
        ciwft.pInfo = pCharList[i];

        if (ciwft.pInfo->nType == MessageLoginMinor::ServerSubDirectoryCharacter)
            ciwft.fLastFileModified = GetBICFileTime(sPlayerServerVault, ciwft.pInfo);
        else if (ciwft.pInfo->nType == MessageLoginMinor::ServerCharacter)
            ciwft.fLastFileModified = GetBICFileTime(sRootServerVault, ciwft.pInfo);
        else // MessageLoginMinor::ServerSaveGameCharacter)
            ciwft.fLastFileModified = std::time(0);

        vecCharInfoWithTime.push_back(ciwft);
    }

    std::sort(vecCharInfoWithTime.begin(), vecCharInfoWithTime.end(), 
    [](CharInfoWithFileTime a, CharInfoWithFileTime b)
    {
        return a.fLastFileModified > b.fLastFileModified; 
    });

    for (size_t i=0; i < vecCharInfoWithTime.size(); i++)
    {
        SetCharacterListIndex(vecCharInfoWithTime[i].pInfo, i);
        pCharList[i] = vecCharInfoWithTime[i].pInfo;
    }
}

static BOOL SendServerToPlayerCharListHook(CNWSMessage* pMessage, CNWSPlayer* pPlayer)
{
    auto* pAppManager = Globals::AppManager();
    auto* pExoApp = pAppManager->m_pServerExoApp;
    auto* pServerInfo = pExoApp->GetServerInfo();
    CNetLayerPlayerInfo* pPlayerInfo = pExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);

    pMessage->CreateWriteMessage(sizeof(uint16_t), pPlayer->m_nPlayerID);
    if ((pAppManager->m_bMultiplayerEnabled && pServerInfo->m_JoiningRestrictions.bAllowLocalVaultChars) ||
        (pPlayerInfo->m_bPlayerInUse && pPlayerInfo->m_bGameMasterPrivileges))
    {
        pMessage->WriteWORD(0);
    }
    else
    {
        CExoArrayList<NWPlayerCharacterList_st*> lstChars;

        CExoString sSubdirectory = pPlayerInfo->m_cCDKey.sPublic;
        if (pServerInfo->m_PersistantWorldOptions.bServerVaultByPlayerName)
            sSubdirectory = pPlayer->GetPlayerName();

        CExoArrayList<CExoString> lstBicFiles;
        lstBicFiles.SetSize(0);
        CExoString sDirectory = CExoString::F("SERVERVAULT:%s", sSubdirectory.CStr());
        Globals::ExoBase()->GetDirectoryList(&lstBicFiles, sDirectory, ResRefType::BIC);
        if (lstBicFiles.num > 0)
        {
            Globals::ExoResMan()->AddResourceDirectory(sDirectory, 81000000);
            for (int i = 0; i < lstBicFiles.num; i++)
            {
                CExoString sBicResRef = lstBicFiles[i];
                sBicResRef = sBicResRef.SubString(0, sBicResRef.m_nStringLength - 4);

                CResGFF* pRes = new CResGFF(ResRefType::BIC, "BIC ", sBicResRef);
                if (pRes->m_bLoaded)
                {
                    if (!pRes->m_bValidationFailed)
                    {
                        BOOL bSuccess;
                        CResStruct topLevelStruct;
                        
                        pRes->GetTopLevelStruct(&topLevelStruct);

                        auto* pCharInfo = new NWPlayerCharacterList_st();
                        pCharInfo->sLocFirstName = pRes->ReadFieldCExoLocString(&topLevelStruct, "FirstName", bSuccess);
                        pCharInfo->sLocLastName = pRes->ReadFieldCExoLocString(&topLevelStruct, "LastName", bSuccess);
                        pCharInfo->resFileName = sBicResRef;
                        pCharInfo->nType = MessageLoginMinor::ServerSubDirectoryCharacter;
                        pCharInfo->nPortraitId = pRes->ReadFieldWORD(&topLevelStruct, "PortraitId", bSuccess, 0xFFFF);
                        pCharInfo->resPortrait = pRes->ReadFieldCResRef(&topLevelStruct, "Portrait", bSuccess);
                        
                        CResList classList;
                        if (pRes->GetList(&classList, &topLevelStruct, "ClassList"))
                        {
                            uint32_t nClassCount = pRes->GetListCount(&classList);
                            for (uint32_t i = 0; i < nClassCount; i++)
                            {
                                CResStruct classStruct;
                                if (pRes->GetListElement(&classStruct, &classList, i))
                                {
                                    NWPlayerCharacterListClass_st classInfo;
                                    classInfo.nClass = pRes->ReadFieldINT(&classStruct, "Class", bSuccess, -1);
                                    classInfo.nClassLevel = (uint8_t)pRes->ReadFieldSHORT(&classStruct, "ClassLevel", bSuccess);
                                    pCharInfo->lstClasses.Add(classInfo);
                                }
                            }
                        }

                        if (lstChars.DerefContains(pCharInfo) || !lstChars.AddUnique(pCharInfo))
                            delete pCharInfo;
                    }
                    else
                    {
                        LOG_ERROR("Corrupt BIC file in servervault of player: '%s' (%s) -> '%s.bic', character skipped.",
                            pPlayer->GetPlayerName().CStr(), 
                            pPlayerInfo->m_cCDKey.sPublic.CStr(), 
                            sBicResRef.CStr());
                    }
                }

                delete pRes;
            }

            Globals::ExoResMan()->RemoveResourceDirectory(sDirectory);
        }

        lstBicFiles.SetSize(0);
        if (!pServerInfo->m_PersistantWorldOptions.bSuppressBaseServerVault)
        {
            Globals::ExoBase()->GetDirectoryList(&lstBicFiles, "SERVERVAULT:", ResRefType::BIC);
            if (lstBicFiles.num > 0)
            {
                for (int i = 0; i < lstBicFiles.num; i++)
                {
                    CExoString sBicResRef = lstBicFiles[i];
                    sBicResRef = sBicResRef.SubString(0, sBicResRef.m_nStringLength - 4);

                    CResGFF* pRes = new CResGFF(ResRefType::BIC, "BIC ", sBicResRef);
                    if (pRes->m_bLoaded)
                    {
                        if (!pRes->m_bValidationFailed)
                        {
                            BOOL bSuccess;
                            CResStruct topLevelStruct;

                            pRes->GetTopLevelStruct(&topLevelStruct);

                            auto* pCharInfo = new NWPlayerCharacterList_st();
                            pCharInfo->sLocFirstName = pRes->ReadFieldCExoLocString(&topLevelStruct, "FirstName", bSuccess);
                            pCharInfo->sLocLastName = pRes->ReadFieldCExoLocString(&topLevelStruct, "LastName", bSuccess);
                            pCharInfo->resFileName = sBicResRef;
                            pCharInfo->nType = MessageLoginMinor::ServerCharacter;
                            pCharInfo->nPortraitId = pRes->ReadFieldWORD(&topLevelStruct, "PortraitId", bSuccess, 0xFFFF);
                            pCharInfo->resPortrait = pRes->ReadFieldCResRef(&topLevelStruct, "Portrait", bSuccess);

                            CResList classList;
                            if (pRes->GetList(&classList, &topLevelStruct, "ClassList"))
                            {
                                uint32_t nClassCount = pRes->GetListCount(&classList);
                                for (uint32_t i = 0; i < nClassCount; i++)
                                {
                                    CResStruct classStruct;
                                    if (pRes->GetListElement(&classStruct, &classList, i))
                                    {
                                        NWPlayerCharacterListClass_st classInfo;
                                        classInfo.nClass = pRes->ReadFieldINT(&classStruct, "Class", bSuccess, -1);
                                        classInfo.nClassLevel = (uint8_t)pRes->ReadFieldSHORT(&classStruct, "ClassLevel", bSuccess);
                                        pCharInfo->lstClasses.Add(classInfo);
                                    }
                                }
                            }

                            if (lstChars.DerefContains(pCharInfo) || !lstChars.AddUnique(pCharInfo))
                                delete pCharInfo;
                        }
                        else
                        {
                            LOG_ERROR("Corrupt BIC file in base servervault: '%s.bic', character skipped.", sBicResRef.CStr());
                        }
                    }

                    delete pRes;
                }
            }
        }

        auto* pModule = pExoApp->GetModule();
        if ((pModule->m_bIsSaveGame) && (!pAppManager->m_bMultiplayerEnabled || !pServerInfo->m_PersistantWorldOptions.bVaultCharsOnly))
            pModule->PackPlayerCharacterListIntoMessage(pPlayer, lstChars);

        SortCharacterListByLastPlayedDate(pPlayer, lstChars);

        pMessage->WriteWORD(lstChars.num);
        for (int i = 0; i < lstChars.num; i++)
        {
            auto* pCharInfo = lstChars[i];
            pMessage->WriteCExoLocStringServer(pCharInfo->sLocFirstName);
            pMessage->WriteCExoLocStringServer(pCharInfo->sLocLastName);
            pMessage->WriteCResRef(pCharInfo->resFileName);
            pMessage->WriteBYTE(pCharInfo->nType);
            pMessage->WriteWORD(pCharInfo->nPortraitId);
            pMessage->WriteCResRef(pCharInfo->resPortrait);

            uint32_t nClassCount = pCharInfo->lstClasses.num;
            pMessage->WriteBYTE((uint8_t)nClassCount);
            for (uint32_t j = 0; j < nClassCount; j++)
            {
                pMessage->WriteINT(pCharInfo->lstClasses[j].nClass);
                pMessage->WriteBYTE(pCharInfo->lstClasses[j].nClassLevel);
            }

            delete pCharInfo;
        }
    }

    uint8_t* pMessageData;
    uint32_t nMessageSize;
    if (pMessage->GetWriteMessage(&pMessageData, &nMessageSize))
        return pMessage->SendServerToPlayerMessage(pPlayer->m_nPlayerID, MessageMajor::CharList, MessageCharListMinor::ListResponse, pMessageData, nMessageSize);

    return false;
}
