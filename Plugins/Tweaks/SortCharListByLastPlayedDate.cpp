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

struct CharacterInfoWithFiletime : NWPlayerCharacterList_st
{
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

static void SetCharacterListIndex(CharacterInfoWithFiletime* pCharInfo, int nIndex)
{
    // Set lowest bit of each rgb component to 1, reducing the range of available indices from 2^24 to 2^21 
    // while avoiding null bytes and preserving uniqueness + order
    nIndex = nIndex << 1;
    int b = (nIndex & 0xFF) | 1;
    int g = ((nIndex >> 7) & 0xFF) | 1;
    int r = ((nIndex >> 14) & 0xFF) | 1;
        
    auto& pStrList = pCharInfo->sLocFirstName.m_pExoLocStringInternal->m_lstString;
    for (auto *pNode = pStrList.GetHeadPos(); pNode; pNode = pNode->pNext)
    {
        if (EXOLOCSTRING* sCharName = pStrList.GetAtPos(pNode))
            sCharName->sString = CExoString::F("<c%c%c%c></c>", r, g, b) + sCharName->sString;
    }
}

static std::time_t GetBICFileTime(CExoString sVaultPath, const CResRef& sBicResRef)
{
    CExoString sFilename = sVaultPath + CExoString(sBicResRef) + ".bic";

    struct stat fileStats;
    if (stat(sFilename.c_str(), &fileStats) == 0) 
        return fileStats.st_mtime;
    else
        return 0;
}

static void GetServerVaultBasePaths(CNWSPlayer* pPlayer, CExoString* sOutRootServerVault, CExoString* sOutPlayerServerVault)
{
    CServerExoApp* pExoApp = Globals::AppManager()->m_pServerExoApp;

    *sOutRootServerVault = Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("SERVERVAULT");
    CExoString sPlayerdir;
    if (pExoApp->GetServerInfo()->m_PersistantWorldOptions.bServerVaultByPlayerName)
        sPlayerdir = pPlayer->GetPlayerName();
    else
        sPlayerdir = pExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID)->m_cCDKey.sPublic;

    *sOutPlayerServerVault = *sOutRootServerVault + sPlayerdir + "/";
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
        std::vector<CharacterInfoWithFiletime> lstChars;

        CExoString sRootServerVault;
        CExoString sPlayerServerVault;
        GetServerVaultBasePaths(pPlayer, &sRootServerVault, &sPlayerServerVault);

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

                        CharacterInfoWithFiletime charInfo;
                        charInfo.sLocFirstName = pRes->ReadFieldCExoLocString(&topLevelStruct, "FirstName", bSuccess);
                        charInfo.sLocLastName = pRes->ReadFieldCExoLocString(&topLevelStruct, "LastName", bSuccess);
                        charInfo.resFileName = sBicResRef;
                        charInfo.nType = MessageLoginMinor::ServerSubDirectoryCharacter;
                        charInfo.nPortraitId = pRes->ReadFieldWORD(&topLevelStruct, "PortraitId", bSuccess, 0xFFFF);
                        charInfo.resPortrait = pRes->ReadFieldCResRef(&topLevelStruct, "Portrait", bSuccess);
                        charInfo.fLastFileModified = GetBICFileTime(sPlayerServerVault, charInfo.resFileName);
                        
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
                                    charInfo.lstClasses.Add(classInfo);
                                }
                            }
                        }

                        lstChars.push_back(charInfo);
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

                            CharacterInfoWithFiletime charInfo;
                            charInfo.sLocFirstName = pRes->ReadFieldCExoLocString(&topLevelStruct, "FirstName", bSuccess);
                            charInfo.sLocLastName = pRes->ReadFieldCExoLocString(&topLevelStruct, "LastName", bSuccess);
                            charInfo.resFileName = sBicResRef;
                            charInfo.nType = MessageLoginMinor::ServerCharacter;
                            charInfo.nPortraitId = pRes->ReadFieldWORD(&topLevelStruct, "PortraitId", bSuccess, 0xFFFF);
                            charInfo.resPortrait = pRes->ReadFieldCResRef(&topLevelStruct, "Portrait", bSuccess);
                            charInfo.fLastFileModified = GetBICFileTime(sRootServerVault, charInfo.resFileName);

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
                                        charInfo.lstClasses.Add(classInfo);
                                    }
                                }
                            }

                            lstChars.push_back(charInfo);
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

        std::sort(lstChars.begin(), lstChars.end(), 
        [](CharacterInfoWithFiletime a, CharacterInfoWithFiletime b)
        {
            return a.fLastFileModified > b.fLastFileModified; 
        });

        for (size_t i=0; i < lstChars.size(); i++)
        {
            SetCharacterListIndex(&lstChars[i], i);
        }

        pMessage->WriteWORD(lstChars.size());
        for (size_t i = 0; i < lstChars.size(); i++)
        {
            auto& charInfo = lstChars[i];
            pMessage->WriteCExoLocStringServer(charInfo.sLocFirstName);
            pMessage->WriteCExoLocStringServer(charInfo.sLocLastName);
            pMessage->WriteCResRef(charInfo.resFileName);
            pMessage->WriteBYTE(charInfo.nType);
            pMessage->WriteWORD(charInfo.nPortraitId);
            pMessage->WriteCResRef(charInfo.resPortrait);

            uint32_t nClassCount = charInfo.lstClasses.num;
            pMessage->WriteBYTE((uint8_t)nClassCount);
            for (uint32_t j = 0; j < nClassCount; j++)
            {
                pMessage->WriteINT(charInfo.lstClasses[j].nClass);
                pMessage->WriteBYTE(charInfo.lstClasses[j].nClassLevel);
            }
        }
    }

    uint8_t* pMessageData;
    uint32_t nMessageSize;
    if (pMessage->GetWriteMessage(&pMessageData, &nMessageSize))
        return pMessage->SendServerToPlayerMessage(pPlayer->m_nPlayerID, MessageMajor::CharList, MessageCharListMinor::ListResponse, pMessageData, nMessageSize);

    return false;
}
