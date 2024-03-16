#include "nwnx.hpp"

#include "API/CExoBase.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CServerInfo.hpp"
#include "API/CJoiningRestrictions.hpp"
#include "API/CPersistantWorldOptions.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CNWSCreRestorePolymorphData.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CEffectIconObject.hpp"
#include "API/CNWSPlayerLastUpdateObject.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CTlkTable.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CPathfindInformation.hpp"
#include "API/CFactionManager.hpp"
#include "API/CNWSFaction.hpp"
#include "API/NWVMachineUtils.hpp"

#include <sqlite_modern_cpp.h>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace sqlite;

struct SwitchCharacterEventData
{
    CNWSPlayer *m_pPlayer = nullptr;
    int32_t m_nCharacterId = 0;
    CNWSArea *m_pArea = nullptr;
    Vector m_vPosition{};
    Vector m_vOrientation{};
    ObjectID m_oidOld = Constants::OBJECT_INVALID;
    std::vector<std::tuple<uint8_t, int32_t, int32_t>> m_effectIcons;
    CNWActionNode m_actionNodes[10];
    CExoArrayList<uint32_t> m_knownSpellList[8][10];
    bool m_bSkipLUO = false;
};

constexpr uint32_t SWITCH_CHARACTER_EVENT = 1234;

namespace VaultEventType
{
    enum TYPE
    {
        Created = 1,
        Login,
        Logout,
        Migrated
    };
}

static void InitializeServervault();

static std::string GetPlayerCDKey(CNWSPlayer*);
static int32_t GetPlayerCharacterId(CNWSPlayer*);
static json PlayerCreatureToJson(CNWSPlayer*);
static STRREF LoadCreatureData(CNWSPlayer*, int32_t, CNWSCreature*);
static void UpdatePlayerList(CNWSPlayer*, ObjectID, ObjectID);
static void RemovePlayerCreature(CNWSPlayer*, bool);

static bool VaultOpenDatabase();
static int32_t VaultInsertCharacter(const std::string& sCDKey, const json& jCharacter, const std::string& sFileName = "");
static bool VaultUpdateCharacter(int32_t nCharacterId, const json& jCharacter);
static void VaultInsertLogEvent(int32_t nCharacterId, const std::string& sCDKey, VaultEventType::TYPE type);
static void VaultSetPlayerAccess(int32_t nCharacterId, const std::string& sCDKey);
static void VaultSetPlayerOnline(int32_t nCharacterId, const std::string& sCDKey);
static void VaultSetPlayerOffline(int32_t nCharacterId, const std::string& sCDKey);
static void VaultInsertObjectId(int32_t nCharacterId, ObjectID oid);
static ObjectID VaultGetObjectId(int32_t nCharacterId);
static bool VaultGetCharacterInUse(int32_t nCharacterId);
static json VaultGetCharacter(int32_t nCharacterId);

static void MigrateVault(CNWSPlayer*);

static BOOL SaveServerCharacterHook(CNWSPlayer*, BOOL);
static STRREF LoadServerCharacterHook(CNWSPlayer*, CResRef, BOOL);

static BOOL SendServerToPlayerCharListHook(CNWSMessage*, CNWSPlayer*);
static BOOL SendServerToPlayerUpdateCharResponseHook(CNWSMessage*, CNWSPlayer*, uint8_t, CResRef);
static void RemovePCFromWorldHook(CServerExoAppInternal*, CNWSPlayer*);
static void EatTURDHook(CNWSPlayer*, CNWSPlayerTURD*);
static void ModuleEventHandlerHook(CNWSModule*, uint32_t, ObjectID, void*, uint32_t, uint32_t);

static Hooks::Hook s_SaveServerCharacterHook = nullptr;
static Hooks::Hook s_LoadServerCharacterHook = nullptr;
static Hooks::Hook s_SendServerToPlayerCharListHook = nullptr;
static Hooks::Hook s_SendServerToPlayerUpdateCharResponseHook = nullptr;
static Hooks::Hook s_RemovePCFromWorldHook = nullptr;
static Hooks::Hook s_SendServerToPlayerLogin_FailHook = nullptr;
static Hooks::Hook s_ModuleEventHandlerHook = nullptr;
static Hooks::Hook s_EatTURDHook = nullptr;

static std::string s_VaultDatabaseName = Config::Get<std::string>("DATABASE_NAME", "servervault");
static bool s_PersistHitPoints = Config::Get<bool>("PERSIST_HITPOINTS", false);
static bool s_MigrationEnabled = Config::Get<bool>("ENABLE_MIGRATION", false);
static std::string s_VaultDatabasePath;
static bool s_PluginInitialized = false;
static std::unique_ptr<database> s_ServerVault = nullptr;

void Vault() __attribute__((constructor));
void Vault()
{
    if (!Config::Get<bool>("ENABLE_SERVERVAULT_DATABASE", false))
    {
        LOG_WARNING("NWNX_VAULT_ENABLE_SERVERVAULT_DATABASE is FALSE, not enabling alternate servervault implementation.");
        LOG_WARNING("If you're not using NWNX_Vault, you can disable this message with 'NWNX_VAULT_SKIP=y'");
        return;
    }

    MessageBus::Subscribe("NWNX_CORE_SIGNAL",
        [](const std::vector<std::string>& message)
        {
          if (message[0] == "ON_CREATE_SERVER")
          {
              // Have to do this here because the database alias won't be available yet in the ctor
              InitializeServervault();
          }
        });
}

static void InitializeServervault()
{
    if (s_VaultDatabaseName.empty())
    {
        LOG_ERROR("Servervault Database Name cannot be empty.");
        return;
    }

    s_VaultDatabasePath = Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("DATABASE").CStr() + s_VaultDatabaseName + ".sqlite3";

    LOG_INFO("Initializing Servervault Database: %s", s_VaultDatabasePath);

    if (VaultOpenDatabase())
    {
        s_PluginInitialized = true;

        try
        {
            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_characters ( "
                              "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                              "owner TEXT NOT NULL, "
                              "filename TEXT, "
                              "character TEXT NOT NULL, "
                              "timestamp INTEGER NOT NULL "
                              ");";

            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_access ( "
                              "id INTEGER NOT NULL, "
                              "cdkey TEXT NOT NULL, "
                              "PRIMARY KEY(id, cdkey)"
                              ");";

            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_status ( "
                              "id INTEGER NOT NULL, "
                              "cdkey TEXT NOT NULL, "
                              "PRIMARY KEY(id, cdkey)"
                              ");";

            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_oids ( "
                              "id INTEGER NOT NULL, "
                              "oid INTEGER NOT NULL, "
                              "PRIMARY KEY(id, oid)"
                              ");";

            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_migration ("
                              "cdkey TEXT PRIMARY KEY NOT NULL, "
                              "timestamp INTEGER NOT NULL "
                              ");";

            *s_ServerVault << "CREATE TABLE IF NOT EXISTS vault_log ("
                              "id TEXT NOT NULL, "
                              "cdkey TEXT NOT NULL, "
                              "event INTEGER NOT NULL, "
                              "timestamp INTEGER NOT NULL"
                              ");";

            *s_ServerVault << "DELETE FROM vault_status;";
            *s_ServerVault << "DELETE FROM vault_oids;";

        }
        catch (sqlite_exception& e)
        {
            LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
            s_PluginInitialized = false;
        }
    }

    if (s_PluginInitialized)
    {
        s_SaveServerCharacterHook = Hooks::HookFunction(&CNWSPlayer::SaveServerCharacter, &SaveServerCharacterHook, Hooks::Order::Final);
        s_LoadServerCharacterHook = Hooks::HookFunction(&CNWSPlayer::LoadServerCharacter, &LoadServerCharacterHook, Hooks::Order::Final);
        s_SendServerToPlayerCharListHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerCharList, &SendServerToPlayerCharListHook, Hooks::Order::Final);
        s_SendServerToPlayerUpdateCharResponseHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerUpdateCharResponse, &SendServerToPlayerUpdateCharResponseHook, Hooks::Order::Final);
        s_RemovePCFromWorldHook = Hooks::HookFunction(&CServerExoAppInternal::RemovePCFromWorld, &RemovePCFromWorldHook, Hooks::Order::Early);
        s_SendServerToPlayerLogin_FailHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerLogin_Fail,
            (void*)+[](CNWSMessage *pThis, uint32_t nPlayerId, STRREF strReason) -> BOOL
            {
                strReason = strReason == 0 ? 57925 : strReason;
                return s_SendServerToPlayerLogin_FailHook->CallOriginal<BOOL>(pThis, nPlayerId, strReason);
            }, Hooks::Order::Early);
        s_ModuleEventHandlerHook = Hooks::HookFunction(&CNWSModule::EventHandler, &ModuleEventHandlerHook, Hooks::Order::Late);
        s_EatTURDHook = Hooks::HookFunction(&CNWSPlayer::EatTURD, &EatTURDHook, Hooks::Order::Final);
    }
}

// *** Helper Functions

static std::string GetPlayerCDKey(CNWSPlayer *pPlayer)
{
    auto *pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);
    return pPlayerInfo ? pPlayerInfo->m_lstKeys.element[0].sPublic.CStr() : "";
}

static int32_t GetPlayerCharacterId(CNWSPlayer *pPlayer)
{
    int32_t retVal = 0;
    try
    {
        retVal = std::stoi(pPlayer->m_resFileName.GetResRefStr());
    }
    catch (...) {}

    return retVal;
}

static json PlayerCreatureToJson(CNWSPlayer *pPlayer)
{
    if (pPlayer->GetIsDM() && !pPlayer->GetIsPlayerDM())
        return {};

    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
    {
        if (pCreature->GetIsPossessedFamiliar() ||
            (pCreature->m_nAssociateType == Constants::AssociateType::DMImpersonate || pCreature->m_nAssociateType == Constants::AssociateType::DMPossess))
        {
            if (auto *pMaster = Utils::AsNWSCreature(Utils::GetGameObject(pCreature->m_oidMaster)))
                pCreature = pMaster;
            else
                return {};
        }

        auto *pPolymorphData = pCreature->RemovePolymorphFromOutputCreature();
        CResGFF gff;
        CResStruct root{};

        if (!gff.CreateGFFFile(&root, "BIC ", "V2.0"))
        {
            delete pPolymorphData;
            return {};
        }

        if (pCreature->m_nInTransit)
        {
            pCreature->m_bPlotObject = false;
            if (!pCreature->SaveCreature(&gff, &root, false))
            {
                pCreature->m_bPlotObject = true;
                delete pPolymorphData;
                return {};
            }
            pCreature->m_bPlotObject = true;
        }
        else
        {
            if (!pCreature->SaveCreature(&gff, &root, false))
            {
                delete pPolymorphData;
                return {};
            }
        }

        if (pPolymorphData)
            pCreature->RestorePolymorphToOutputCreature(pPolymorphData);

        return NWVMachineUtils::StructToJson(&gff, &root, 0xFFFFFFFF);
    }

    return {};
}

static STRREF LoadCreatureData(CNWSPlayer *pPlayer, int32_t nCharacterId, CNWSCreature *pCreature)
{
    LOG_DEBUG("LoadCreatureData");

    json jCharacter = VaultGetCharacter(nCharacterId);

    if (jCharacter.is_null())
    {
        return 63767;
    }

    CResGFF gff;
    CResStruct root{};

    if (gff.CreateGFFFile(&root, "BIC ", "V2.0"))
    {
        NWVMachineUtils::JsonToStruct(jCharacter, &gff, &root);

        pPlayer->m_resFileName = std::to_string(nCharacterId);

        auto *pStats = pCreature->m_pStats;

        STRREF errorCode = pStats->ReadStatsFromGff(&gff, &root, &pCreature->m_cAppearance, false, true);

        if (errorCode)
            return errorCode;

        pStats->m_bIsPC = true;

        auto CheckString = [&](CExoLocString *sString, int32_t length)
        {
            for (size_t nCount = 0; nCount < sString->GetStringCount(); nCount++)
            {
                int32_t nID;
                uint8_t nGender;
                CExoString sTemp;

                if (sString->GetString(nCount, &nID, &sTemp, &nGender))
                {
                    if (sTemp.GetLength() > length)
                        sTemp = sTemp.Left(length);

                    Globals::AppManager()->m_pServerExoApp->StripColorTokens(sTemp);
                    sString->AddString(nID, sTemp, nGender);
                }
            }
        };

        CheckString(&pStats->m_lsFirstName, 250);
        CheckString(&pStats->m_lsLastName, 250);
        CheckString(&pStats->m_sDescription, 8192);

        CExoString sOverrideDescription = pStats->m_sDescriptionOverride;
        if (sOverrideDescription.GetLength() > 8192)
            pStats->m_sDescriptionOverride = sOverrideDescription.Left(8192);

        pCreature->m_sDisplayName = "";
        pStats->m_nACNaturalBase = 0;
        pStats->m_nOverrideBaseAttackBonus = 0;
        pCreature->m_bDisarmable = false;

        if (!s_PersistHitPoints)
            pCreature->m_nCurrentHitPoints = pCreature->GetMaxHitPoints();

        pCreature->m_bAbleToModifyActionQueue = true;

        BOOL bSuccess;
        pCreature->SetActivity(0x00000002, gff.ReadFieldBYTE(&root, (char*)"DetectMode", bSuccess));
        pCreature->SetActivity(0x00000001, gff.ReadFieldBYTE(&root, (char*)"StealthMode", bSuccess));
        pCreature->m_nLastAnimationCalendarDay = gff.ReadFieldDWORD(&root, (char*)"AnimationDay", bSuccess);
        pCreature->m_nLastAnimationTimeOfDay = gff.ReadFieldDWORD(&root, (char*)"AnimationTime", bSuccess);
        pCreature->m_nCreatureSize = gff.ReadFieldINT(&root, (char*)"CreatureSize", bSuccess, 3);

        pCreature->LoadPolymorphData(&gff, &root);
        pCreature->ReadItemsFromGff(&gff, &root, false, true);

        bool bRestoreSpellsFromSaveData = false;
        if (!Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerInfo->m_JoiningRestrictions.bAllowLocalVaultChars)
            bRestoreSpellsFromSaveData = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerInfo->m_PlayOptions.bRestoreSpellsUses;

        pStats->ReadSpellsFromGff(&gff, &root, bRestoreSpellsFromSaveData);

        /*
        if (pPlayer->GetIsDM())
        {
            pPlayer->AddDMAbilities(pCreature);
            pPlayer->m_nPossessState = 0;
            pPlayer->m_oidDungeonMasterAvatar = Constants::OBJECT_INVALID;
        }
        */

        pCreature->LoadVisualTransform(&gff, &root);
        pCreature->LoadMaterialOverrides(&gff, &root);
        pCreature->LoadTextureOverrides(&gff, &root);
        pCreature->LoadMiscVisuals(&gff, &root);
        pCreature->m_pUUID.LoadFromGff(&gff, &root);
        pCreature->LoadSqliteDatabase(&gff, &root);

        pCreature->PostProcess();

        pCreature->LoadQuickButtons( &gff, &root );

        return 0;
    }

    return 63767;
}

static void UpdatePlayerList(CNWSPlayer *pSwitchingPlayer, ObjectID oidOld, ObjectID oidNew)
{
    auto *pPlayerList = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;

    for (auto *pHead = pPlayerList->pHead; pHead; pHead = pHead->pNext)
    {
        if (auto *pServerPlayer = static_cast<CNWSPlayer*>(pHead->pObject))
        {
            if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            {
                if (pServerPlayer->m_bPlayModuleListingCharacters)
                {
                    pMessage->SendServerToPlayerPlayModuleCharacterListResponse(pServerPlayer->m_nPlayerID, oidOld, false);
                    pMessage->SendServerToPlayerPlayModuleCharacterListResponse(pServerPlayer->m_nPlayerID, oidNew, true);
                }
                else
                {
                    if (pServerPlayer->m_nPlayerID != pSwitchingPlayer->m_nPlayerID)
                    {
                        if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pServerPlayer->m_oidNWSObject)))
                        {
                            pCreature->RemoveFromPVPList(oidOld);
                            pCreature->AddToPVPList(oidNew);
                        }
                    }

                    pMessage->SendServerToPlayerPlayerList_Delete(pServerPlayer->m_nPlayerID, pSwitchingPlayer);
                    pMessage->SendServerToPlayerPlayerList_Add(pServerPlayer->m_nPlayerID, pSwitchingPlayer);
                }
            }
        }
    }
}

static void RemovePlayerCreature(CNWSPlayer *pPlayer, bool bSaveCharacter)
{
    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_CLIENT_DISCONNECT_BEFORE", Utils::ObjectIDToString(pPlayer->m_oidNWSObject)});

    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
    {
        if (pCreature->m_oidMaster != Constants::OBJECT_INVALID)
        {
            if (auto *pMaster = Utils::AsNWSCreature(Utils::GetGameObject(pCreature->m_oidMaster)))
            {
                pCreature = pMaster;
            }
        }

        if (pCreature->m_bSummonedFamiliar)
        {
            pCreature->UnpossessFamiliar();
        }
        else
        {
            // UnpossessFamiliar already does this
            if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            {
                pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 0);
            }
        }

        pCreature->StopDialog();
        pCreature->RemoveAllAssociates();
        pCreature->AutoCloseGUIPanels(false);
        pCreature->CleanInvitationLists(true);
        pCreature->SetCombatMode(Constants::CombatMode::None, true);

        if (bSaveCharacter)
        {
            pPlayer->SaveServerCharacter();
        }

        auto *pEventData = new CScriptEvent;
        pEventData->m_nType = Constants::ScriptEvent::OnPlayerExit;
        pEventData->SetObjectID(0, pCreature->m_idSelf);
        Utils::GetModule()->EventHandler(Constants::AIMasterEvent::SignalEvent, pPlayer->m_nPlayerID, pEventData, 0, 0);

        if (!pPlayer->m_bCutsceneState)
        {
            pPlayer->DropTURD();
        }

        if (pCreature->GetArea())
        {
            pCreature->RemoveFromArea();
        }

        if (auto *pFaction = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFaction(pCreature->m_pStats->m_nFactionId))
        {
            pFaction->RemoveMember(pCreature->m_idSelf);
        }

        int32_t characterId = GetPlayerCharacterId(pPlayer);

        if (characterId && !pPlayer->GetIsDM())
        {
            std::string cdkey = GetPlayerCDKey(pPlayer);
            VaultSetPlayerOffline(characterId, cdkey);
            VaultInsertLogEvent(characterId, cdkey, VaultEventType::Logout);
        }

        auto *pDestroyEvent = new CScriptEvent;
        pDestroyEvent->m_nType = Constants::ScriptEvent::OnDestroyPlayerCreature;
        Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->AddEventDeltaTime(0, 0, pCreature->m_idSelf,
                                                                                       Utils::GetModule()->m_idSelf,
                                                                                       Constants::AIMasterEvent::SignalEvent, pDestroyEvent);
    }

    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_CLIENT_DISCONNECT_AFTER", Utils::ObjectIDToString(pPlayer->m_oidNWSObject)});
}

// *** Database Functions

static bool VaultOpenDatabase()
{
    try
    {
        s_ServerVault = std::make_unique<database>(s_VaultDatabasePath);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        return false;
    }
    return true;
}

static int32_t VaultInsertCharacter(const std::string& sCDKey, const json& jCharacter, const std::string& sFileName)
{
    try
    {
        *s_ServerVault << "INSERT INTO vault_characters (owner, filename, character, timestamp) VALUES(?, ?, ?, strftime('%s','now'));" << sCDKey << sFileName << jCharacter.dump();
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        return 0;
    }

    auto characterId = (int32_t)s_ServerVault->last_insert_rowid();

    LOG_DEBUG("VaultInsertCharacter: CDKey = %s, CharacterId = %i", sCDKey, characterId);

    return characterId;
}

static bool VaultUpdateCharacter(int32_t nCharacterId, const json& jCharacter)
{
    try
    {
        *s_ServerVault << "UPDATE vault_characters SET character = ?, timestamp = strftime('%s','now') WHERE id = ?;" << jCharacter.dump() << nCharacterId;
        LOG_DEBUG("VaultUpdateCharacter: CharacterId = %i", nCharacterId);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        return false;
    }
    return true;
}

static void VaultInsertLogEvent(int32_t nCharacterId, const std::string& sCDKey, VaultEventType::TYPE type)
{
    try
    {
        *s_ServerVault << "INSERT INTO vault_log (id, cdkey, event, timestamp) VALUES(?, ?, ?, strftime('%s','now'));" << nCharacterId << sCDKey << type;
        LOG_DEBUG("VaultInsertLogEvent: CDKey = %s, CharacterId = %i, Type = %i", sCDKey, nCharacterId, type);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

static void VaultSetPlayerAccess(int32_t nCharacterId, const std::string& sCDKey)
{
    try
    {
        *s_ServerVault << "INSERT INTO vault_access (id, cdkey) VALUES(?, ?);" << nCharacterId << sCDKey;
        LOG_DEBUG("VaultSetPlayerAccess: CDKey = %s, CharacterId = %i", sCDKey, nCharacterId);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

static void VaultSetPlayerOnline(int32_t nCharacterId, const std::string& sCDKey)
{
    try
    {
        *s_ServerVault << "INSERT INTO vault_status (id, cdkey) VALUES(?, ?);" << nCharacterId << sCDKey;
        LOG_DEBUG("VaultSetPlayerOnline: CDKey = %s, CharacterId = %i", sCDKey, nCharacterId);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

static void VaultSetPlayerOffline(int32_t nCharacterId, const std::string& sCDKey)
{
    try
    {
        *s_ServerVault << "DELETE FROM vault_status WHERE id = ? AND cdkey = ?;" << nCharacterId << sCDKey;
        LOG_DEBUG("VaultSetPlayerOffline: CDKey = %s, CharacterId = %i", sCDKey, nCharacterId);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

static void VaultInsertObjectId(int32_t nCharacterId, ObjectID oid)
{
    try
    {
        *s_ServerVault << "INSERT INTO vault_oids (id, oid) VALUES(?, ?);" << nCharacterId << oid;
        LOG_DEBUG("VaultInsertObjectId: CharacterId = %i, ObjectId = %s", nCharacterId, Utils::ObjectIDToString(oid));
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

static ObjectID VaultGetObjectId(int32_t nCharacterId)
{
    ObjectID retVal = Constants::OBJECT_INVALID;
    try
    {
        *s_ServerVault << "SELECT oid FROM vault_oids WHERE id = ?;" << nCharacterId >> [&](ObjectID oid) { retVal = oid; };
        LOG_DEBUG("VaultGetObjectId: CharacterId = %i, ObjectId = %s", nCharacterId, Utils::ObjectIDToString(retVal));
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
    return retVal;
}

static bool VaultGetCharacterInUse(int32_t nCharacterId)
{
    bool bInUse = true;
    try
    {
        *s_ServerVault << "SELECT COUNT(cdkey) > 0 FROM vault_status WHERE id = ?;" << nCharacterId >> bInUse;
        LOG_DEBUG("VaultGetCharacterInUse: CharacterId = %i, InUse = %i", nCharacterId, bInUse);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
    return bInUse;
}

static json VaultGetCharacter(int32_t nCharacterId)
{
    json jCharacter;
    try
    {
        *s_ServerVault << "SELECT character FROM vault_characters WHERE id = ?;" << nCharacterId >>
            [&](const std::string &character)
            {
                jCharacter = json::parse(character);
            };
        LOG_DEBUG("VaultGetCharacter: CharacterId = %i", nCharacterId);
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
    return jCharacter;
}

// *** Migration

static void MigrateVault(CNWSPlayer *pPlayer)
{
    if (!s_MigrationEnabled)
        return;

    LOG_DEBUG("MigrateVault");

    auto *pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);
    if (!pPlayerInfo || (pPlayerInfo->m_bPlayerInUse && pPlayerInfo->m_bGameMasterPrivileges))
        return;

    std::string cdkey = GetPlayerCDKey(pPlayer);
    bool bMigrated = true;

    try
    {
        *s_ServerVault << "SELECT COUNT(cdkey) > 0 FROM vault_migration WHERE cdkey = ?;" << cdkey >> bMigrated;
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        return;
    }

    if (bMigrated)
        return;

    CExoString sVaultDirectory;
    sVaultDirectory.Format("SERVERVAULT:%s", cdkey.c_str());

    CExoArrayList<CExoString> lstFileNames;
    Globals::ExoBase()->GetDirectoryList(&lstFileNames, sVaultDirectory, Constants::ResRefType::BIC);
    int32_t numFiles = lstFileNames.num;

    LOG_INFO("Vault Migration for '%s' -> Characters: %i", cdkey, numFiles);

    if (numFiles)
    {
        Globals::ExoResMan()->AddResourceDirectory(sVaultDirectory, 81 * 1000000);

        for (int32_t i = 0; i < numFiles; i++)
        {
            CExoString sFileName = lstFileNames[i];
            sFileName = sFileName.SubString(0, sFileName.GetLength() - 4);

            CResGFF gff(Constants::ResRefType::BIC, (char*)"BIC ", sFileName);
            CResStruct root{};
            gff.GetTopLevelStruct(&root);

            if (gff.m_bLoaded)
            {
                json jCharacter = NWVMachineUtils::StructToJson(&gff, &root, 0xFFFFFFFF);

                if (auto characterId = VaultInsertCharacter(cdkey, jCharacter, sFileName.CStr()))
                {
                    VaultSetPlayerAccess(characterId, cdkey);
                    VaultInsertLogEvent(characterId, cdkey, VaultEventType::Migrated);
                    LOG_DEBUG("Character Migrated: %s -> id=%i", sFileName.CStr(), characterId);
                }
                else
                {
                    LOG_WARNING("Failed to migrate character: %s", sFileName.CStr());
                }
            }
        }

        Globals::ExoResMan()->RemoveResourceDirectory(sVaultDirectory);
    }

    try
    {
        *s_ServerVault << "INSERT INTO vault_migration (cdkey, timestamp) VALUES(?, strftime('%s','now'));" << cdkey;
    }
    catch (sqlite_exception& e)
    {
        LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
    }
}

// *** Hooks

static BOOL SaveServerCharacterHook(CNWSPlayer *pPlayer, BOOL)
{
    LOG_DEBUG("SaveServerCharacter");

    if (pPlayer->m_nCharacterType != 3 && pPlayer->m_nCharacterType != 4)
        return false;

    json jCharacter = PlayerCreatureToJson(pPlayer);

    if (jCharacter.is_null())
        return false;

    int32_t characterId = GetPlayerCharacterId(pPlayer);

    if (!characterId)
    {
        std::string cdkey = GetPlayerCDKey(pPlayer);
        if ((characterId = VaultInsertCharacter(cdkey, jCharacter)))
        {
            VaultInsertLogEvent(characterId, cdkey, VaultEventType::Created);
            VaultSetPlayerAccess(characterId, cdkey);
            VaultSetPlayerOnline(characterId, cdkey);
            VaultInsertLogEvent(characterId, cdkey, VaultEventType::Login);
            VaultInsertObjectId(characterId, pPlayer->m_oidNWSObject);

            pPlayer->m_resFileName = std::to_string(characterId);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return VaultUpdateCharacter(characterId, jCharacter);
    }

    return true;
}

static STRREF LoadServerCharacterHook(CNWSPlayer *pPlayer, CResRef cResRef, BOOL /*bSubDirChar*/)
{
    LOG_DEBUG("LoadServerCharacter");

    int32_t characterId = 0;
    try
    {
        characterId = std::stoi(cResRef.GetResRefStr());
    }
    catch (...)
    {
        return 57925;
    }

    if (!characterId)
        return 57925;

    if (VaultGetCharacterInUse(characterId))
        return 57925;

    ObjectID oid = VaultGetObjectId(characterId);

    auto *pCreature = new CNWSCreature(oid, true);
    pPlayer->SetGameObject(pCreature);
    pPlayer->m_oidPCObject = pCreature->m_idSelf;
    pPlayer->m_nCharacterType = 4;

    STRREF errorCode = LoadCreatureData(pPlayer, characterId, pCreature);

    if (errorCode)
    {
        pPlayer->SetGameObject(nullptr);
        pPlayer->m_oidPCObject = Constants::OBJECT_INVALID;
        delete pCreature;
        return errorCode;
    }

    std::string cdkey = GetPlayerCDKey(pPlayer);
    VaultSetPlayerOnline(characterId, cdkey);
    VaultInsertLogEvent(characterId, cdkey, VaultEventType::Login);

    if (oid == Constants::OBJECT_INVALID)
    {
        VaultInsertObjectId(characterId, pCreature->m_idSelf);
    }

    return 0;
}

static BOOL SendServerToPlayerCharListHook(CNWSMessage *pThis, CNWSPlayer *pPlayer)
{
    LOG_DEBUG("SendServerToPlayerCharList");

    struct VaultListCharacter
    {
        int32_t nId;
        CExoLocString sName;
        int32_t nPortraitId;
        CResRef sPortrait;
        std::vector<std::pair<int32_t, int32_t>> classes;
        bool bInUse;
        bool bShared;
    };

    uint8_t *pMessage;
    uint32_t nSize = sizeof(uint16_t);

    pThis->CreateWriteMessage(nSize, pPlayer->m_nPlayerID);

    auto *pServer = Globals::AppManager()->m_pServerExoApp;
    auto *pPlayerInfo = pServer->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);

    if ((Globals::AppManager()->m_bMultiplayerEnabled && pServer->GetServerInfo()->m_JoiningRestrictions.bAllowLocalVaultChars) ||
        (pPlayerInfo->m_bPlayerInUse && pPlayerInfo->m_bGameMasterPrivileges))
    {
        pThis->WriteWORD(0);
    }
    else
    {
        MigrateVault(pPlayer);

        std::string cdkey = GetPlayerCDKey(pPlayer);
        std::vector<VaultListCharacter> characters;

        try
        {
            *s_ServerVault << "SELECT vault_characters.id, vault_characters.owner, "
                  "JSON_EXTRACT(vault_characters.character, '$.FirstName.value.0'), "
                  "JSON_EXTRACT(vault_characters.character, '$.LastName.value.0'), "
                  "JSON_EXTRACT(vault_characters.character, '$.Portrait.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.PortraitId.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[0].Class.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[0].ClassLevel.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[1].Class.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[1].ClassLevel.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[2].Class.value'), "
                  "JSON_EXTRACT(vault_characters.character, '$.ClassList.value[2].ClassLevel.value') "
                  "FROM vault_characters INNER JOIN vault_access ON vault_access.id = vault_characters.id WHERE vault_access.cdkey = ?;"
               << cdkey
               >> [&](int32_t id, const std::string &owner,
                      const std::optional<std::string>& firstName, const std::optional<std::string>& lastName,
                      const std::optional<std::string>& portrait, std::optional<int32_t> portraitId,
                      std::optional<int32_t> class1Type, std::optional<int32_t> class1Level,
                      std::optional<int32_t> class2Type, std::optional<int32_t> class2Level,
                      std::optional<int32_t> class3Type, std::optional<int32_t> class3Level)
               {
                   VaultListCharacter vaultCharacter{};
                   vaultCharacter.nId = id;
                   vaultCharacter.sName = Utils::CreateLocString(firstName.value_or("") + " " + lastName.value_or(""));
                   vaultCharacter.nPortraitId = portraitId.value_or(0xFFFF);
                   vaultCharacter.sPortrait = portrait.value_or("");

                   if (class1Type && class1Level)
                       vaultCharacter.classes.emplace_back(*class1Type, *class1Level);
                   if (class2Type && class2Level)
                       vaultCharacter.classes.emplace_back(*class2Type, *class2Level);
                   if (class3Type && class3Level)
                       vaultCharacter.classes.emplace_back(*class3Type, *class3Level);

                   vaultCharacter.bInUse = VaultGetCharacterInUse(id);
                   vaultCharacter.bShared = owner != cdkey;

                   characters.emplace_back(vaultCharacter);
               };
        }
        catch (sqlite_exception& e)
        {
            LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        }

        pThis->WriteWORD(characters.size());

        for (const auto& character : characters)
        {
            pThis->WriteCExoLocStringServer(character.sName);
            std::string sShared = character.bShared ? "<c\x66\xcc\xff>(Shared)</c>" : "";
            std::string sInUse = character.bInUse ? "<c\xff\x01\x01>(In Use)</c>" : "";
            pThis->WriteCExoLocStringServer(Utils::CreateLocString(sShared + sInUse));
            pThis->WriteCResRef(CResRef(std::to_string(character.nId)));
            pThis->WriteBYTE(0x02);
            pThis->WriteWORD(character.nPortraitId);
            pThis->WriteCResRef(character.sPortrait);
            pThis->WriteBYTE(character.classes.size());
            for (auto multiclass : character.classes)
            {
                pThis->WriteINT(multiclass.first);
                pThis->WriteBYTE(multiclass.second);
            }
        }
    }

    if (!pThis->GetWriteMessage(&pMessage, &nSize))
        return false;

    return pThis->SendServerToPlayerMessage(pPlayer->m_nPlayerID, Constants::MessageMajor::CharList,
                                            Constants::MessageCharListMinor::ListResponse, pMessage, nSize);
}

static BOOL SendServerToPlayerUpdateCharResponseHook(CNWSMessage *pThis, CNWSPlayer *pPlayer, uint8_t nCharType, CResRef cResRef)
{
    LOG_DEBUG("SendServerToPlayerUpdateCharResponse -> CharType: %i, ResRef: %s", nCharType, cResRef.GetResRefStr());

    uint8_t *pMessage;
    uint32_t nSize;

    if (nCharType == 1)
    {
        int32_t characterId = 0;
        try
        {
            characterId = std::stoi(cResRef.GetResRefStr());
        }
        catch (...)
        {
            return false;
        }

        try
        {
            *s_ServerVault << "SELECT character FROM vault_characters WHERE id = ?;"
               << characterId
               >> [&](const std::string &character)
               {
                   CResGFF gff;
                   CResStruct root{};
                   if (gff.CreateGFFFile(&root, "BIC ", "V2.0"))
                   {
                       NWVMachineUtils::JsonToStruct(json::parse(character), &gff, &root);

                       uint8_t *pData = nullptr;
                       int32_t nSize = 0;

                       gff.WriteGFFToPointer((void **)&pData, nSize);

                       pThis->CreateWriteMessage(sizeof(uint8_t) + sizeof(CResRef) + sizeof(uint32_t));

                       pThis->WriteBYTE(nCharType);
                       pThis->WriteCResRef(cResRef);
                       pThis->WriteDWORD(nSize);
                       pThis->WriteVOIDPtr((void *)pData, nSize);
                       delete[] pData;
                   }
               };
        }
        catch (sqlite_exception& e)
        {
            LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
            return false;
        }
    }

    if (!pThis->GetWriteMessage(&pMessage, &nSize))
        return false;

    return pThis->SendServerToPlayerMessage(pPlayer->m_nPlayerID, Constants::MessageMajor::CharList,
                                            Constants::MessageCharListMinor::UpdateCharResponse, pMessage, nSize);
}

static void RemovePCFromWorldHook(CServerExoAppInternal *pThis, CNWSPlayer *pPlayer)
{
    int32_t characterId = GetPlayerCharacterId(pPlayer);

    if (characterId && (!pPlayer->GetIsDM() || pPlayer->GetIsPlayerDM()))
    {
        std::string cdkey = GetPlayerCDKey(pPlayer);
        VaultSetPlayerOffline(characterId, cdkey);
        VaultInsertLogEvent(characterId, cdkey, VaultEventType::Logout);
    }

    s_RemovePCFromWorldHook->CallOriginal<void>(pThis, pPlayer);
}

static void ModuleEventHandlerHook(CNWSModule *pModule, uint32_t nEventId, ObjectID nCallerObjectId, void *pEventData, uint32_t nCalendarDay, uint32_t nTimeOfDay)
{
    if (nEventId == SWITCH_CHARACTER_EVENT)
    {
        auto *pSCED = static_cast<SwitchCharacterEventData*>(pEventData);
        auto *pPlayer = pSCED->m_pPlayer;

        if (!pPlayer)
        {
            delete pSCED;
            return;
        }

        STRREF errorCode = pPlayer->LoadServerCharacter(CResRef(std::to_string(pSCED->m_nCharacterId)));
        pPlayer->m_nCharacterType = 4;

        if (errorCode != 0 || !pPlayer->GetGameObject())
        {
            LOG_ERROR("NWNX_Vault_SwitchCharacter(): Something went horribly wrong, good luck! :D (CharacterId: %i) -> %s",
                      pSCED->m_nCharacterId, Globals::TlkTable()->GetSimpleString(errorCode).CStr());

            // Disconnect the poor player :(
            Globals::AppManager()->m_pServerExoApp->GetNetLayer()->DisconnectPlayer(
                    pPlayer->m_nPlayerID, 5838, true, "Something went wrong trying to switch your character.");

            delete pSCED;
            return;
        }

        if (auto *pTURD = Utils::GetModule()->GetPlayerTURDFromList(pPlayer))
        {
            pPlayer->EatTURD(pTURD);
        }

        // Restore our saved LUO stuff ...
        if (!pSCED->m_bSkipLUO)
        {
            if (!pPlayer->m_pPlayerLUO)
                pPlayer->CreateNewPlayerLastUpdateObject();
            for (const auto &[nIcon, bFlashing, nPlayerBar]: pSCED->m_effectIcons)
            {
                auto *pIcon = new CEffectIconObject;
                pIcon->m_nIcon = nIcon;
                pIcon->m_bFlashing = bFlashing;
                pIcon->m_nPlayerBar = nPlayerBar;

                pPlayer->m_pPlayerLUO->m_aEffectIcons.Add(pIcon);
            }
            for (int32_t i = 0; i < 10; i++)
            {
                pPlayer->m_pPlayerLUO->m_pActionQueueList[i] = pSCED->m_actionNodes[i];
            }
            for (int32_t nMultiClass = 0; nMultiClass < 8; nMultiClass++)
            {
                for (int32_t nSpellLevel = 0; nSpellLevel < 10; nSpellLevel++)
                {
                    for (int32_t nSpell = 0; nSpell < pSCED->m_knownSpellList[nMultiClass][nSpellLevel].num; nSpell++)
                    {
                        pPlayer->m_pPlayerLUO->m_pKnownSpellList[nMultiClass][nSpellLevel].Add(
                                pSCED->m_knownSpellList[nMultiClass][nSpellLevel][nSpell]);
                    }
                }
            }
        }

        auto *pNewCreatureObject = Utils::AsNWSCreature(pPlayer->GetGameObject());

        auto *pScriptEventData = new CScriptEvent;
        pScriptEventData->m_nType = Constants::ScriptEvent::OnPlayerEnter;
        pScriptEventData->SetObjectID(0, pNewCreatureObject->m_idSelf);
        Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->AddEventDeltaTime(0, 0, pPlayer->m_nPlayerID,
                                                                                       Utils::GetModule()->m_idSelf,
                                                                                       Constants::AIMasterEvent::SignalEvent, pScriptEventData);


        pNewCreatureObject->SetOrientation(pSCED->m_vOrientation);
        pNewCreatureObject->m_oidDesiredArea = pSCED->m_pArea->m_idSelf;
        pNewCreatureObject->m_vDesiredAreaLocation = pSCED->m_vPosition;
        pNewCreatureObject->m_bDesiredAreaUpdateComplete = false;
        pNewCreatureObject->m_pcPathfindInformation->m_oidSelf = pNewCreatureObject->m_idSelf;
        Vector vNewPosition;

        if (!pSCED->m_pArea->ComputeSafeLocation(pNewCreatureObject->m_vDesiredAreaLocation, 20.0f,
                                                 pNewCreatureObject->m_pcPathfindInformation, true, &vNewPosition))
        {
            vNewPosition = pSCED->m_vPosition;
        }

        pNewCreatureObject->UpdateSubareasOnJumpPosition(vNewPosition, pSCED->m_pArea->m_idSelf);
        pNewCreatureObject->AddToArea(pSCED->m_pArea, vNewPosition.x, vNewPosition.y, vNewPosition.z, true, true);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, 0, true);

        UpdatePlayerList(pPlayer, pSCED->m_oidOld, pNewCreatureObject->m_idSelf);

        delete pSCED;
    }
    else
    {
        s_ModuleEventHandlerHook->CallOriginal<void>(pModule, nEventId, nCallerObjectId, pEventData, nCalendarDay, nTimeOfDay);
    }
}

static void EatTURDHook(CNWSPlayer *pPlayer, CNWSPlayerTURD *pTURD)
{
    auto *pCreature = Utils::AsNWSCreature(pPlayer->GetGameObject());

    delete pCreature->m_pReputation;
    pCreature->m_pReputation = pTURD->m_pReputation;
    pTURD->m_pReputation = nullptr;

    delete pCreature->m_pPersonalReputationList;
    pCreature->m_pPersonalReputationList = pTURD->m_pPersonalReputationList;
    pTURD->m_pPersonalReputationList = nullptr;

    pCreature->m_oidDesiredArea = pTURD->m_oidArea;
    pCreature->m_vDesiredAreaLocation = pTURD->m_vPosition;
    pCreature->m_bDesiredAreaUpdateComplete = false;
    pCreature->SetOrientation(pTURD->m_vOrientation);

    pCreature->CopyScriptVars(&pTURD->m_ScriptVars);
    pCreature->SetAutoMapData(pTURD->m_nNumAutomapAreas, pTURD->m_poidAutomapAreasList, pTURD->m_pAutoMapTileData);

    for (int i = 0; i < pTURD->m_appliedEffects.num; i++)
    {
        if (!pTURD->m_appliedEffects.element[i]->m_bSkipOnLoad && pTURD->m_appliedEffects.element[i]->GetDurationType() != Constants::EffectDurationType::Equipped)
        {
            auto *pEffect = new CGameEffect();
            pEffect->CopyEffect(pTURD->m_appliedEffects.element[i]);
            pCreature->ApplyEffect(pEffect, true);
        }
    }

    while (!pCreature->m_lQueuedActions.IsEmpty())
    {
        auto *pNode = pCreature->m_lQueuedActions.RemoveHead();
        delete pNode;
    }

    pPlayer->m_bFromTURD = true;

    pTURD->RemoveFromArea();
    Utils::GetModule()->RemoveFromTURDList(pPlayer);
}

// NWSCRIPT EXPORTS
NWNX_EXPORT ArgumentStack SwitchCharacter(ArgumentStack&& args)
{
    if (auto *pPlayer = Utils::PopPlayer(args))
    {
        const auto characterId = args.extract<int32_t>();
          ASSERT_OR_THROW(characterId > 0);
        const auto bSaveCurrent = args.extract<int32_t>() != 0;

        if (!s_PluginInitialized)
        {
            LOG_ERROR("NWNX_Vault_SwitchCharacter(): Plugin failed to initialize.");
            return {};
        }

        if (pPlayer->GetIsDM() && !pPlayer->GetIsPlayerDM())
        {
            LOG_ERROR("NWNX_Vault_SwitchCharacter(): Player is a DM.");
            return {};
        }

        auto *pCreature = Utils::AsNWSCreature(pPlayer->GetGameObject());
        if (!pCreature || !pCreature->GetArea())
            return {};

        try
        {
            std::string owner;
            *s_ServerVault << "SELECT owner FROM vault_characters WHERE id = ?;"
               << characterId
               >> owner;

            if (owner.empty())
            {
                LOG_ERROR("NWNX_Vault_SwitchCharacter(): Character does not exist: %i", characterId);
                return {};
            }
        }
        catch (sqlite_exception& e)
        {
            LOG_ERROR("NWNX_Vault SQLite Error: %i:%i -> %s (SQL: %s)", e.get_code(), e.get_extended_code(), e.what(), e.get_sql());
        }

        auto *pSCED = new SwitchCharacterEventData;
        pSCED->m_pPlayer = pPlayer;
        pSCED->m_nCharacterId = characterId;
        pSCED->m_oidOld = pCreature->m_idSelf;
        pSCED->m_pArea = pCreature->GetArea();
        pSCED->m_vPosition = pCreature->m_vPosition;
        pSCED->m_vOrientation = pCreature->m_vOrientation;
        pSCED->m_bSkipLUO = GetPlayerCharacterId(pPlayer) == characterId;

        if (!pSCED->m_bSkipLUO)
        {
            if (auto *pPlayerLastUpdateObject = pPlayer->m_pPlayerLUO)
            {
                // We need to make a copy of the effect icon list in the player LUO because it will be nuked at some point which causes effect icons to linger.
                for (int32_t i = 0; i < pPlayerLastUpdateObject->m_aEffectIcons.num; i++)
                {
                    if (auto *pIcon = pPlayerLastUpdateObject->m_aEffectIcons[i])
                    {
                        pSCED->m_effectIcons.emplace_back(pIcon->m_nIcon, pIcon->m_bFlashing, pIcon->m_nPlayerBar);
                    }
                }
                // The same for any action queue nodes...
                for (int32_t i = 0; i < 10; i++)
                {
                    pSCED->m_actionNodes[i] = pPlayerLastUpdateObject->m_pActionQueueList[i];
                }
                // Also need to make a copy of the known spell list...
                for (int32_t nMultiClass = 0; nMultiClass < 8; nMultiClass++)
                {
                    for (int32_t nSpellLevel = 0; nSpellLevel < 10; nSpellLevel++)
                    {
                        for (int32_t nSpell = 0; nSpell < pPlayerLastUpdateObject->m_pKnownSpellList[nMultiClass][nSpellLevel].num; nSpell++)
                        {
                            pSCED->m_knownSpellList[nMultiClass][nSpellLevel].Add(
                                    pPlayerLastUpdateObject->m_pKnownSpellList[nMultiClass][nSpellLevel][nSpell]);
                        }
                    }
                }
                // TODO: Maybe memorized spell list too..?
            }
        }

        RemovePlayerCreature(pPlayer, bSaveCurrent);

        Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->AddEventDeltaTime(
                0, 0, pPlayer->m_nPlayerID,
                Utils::GetModule()->m_idSelf,SWITCH_CHARACTER_EVENT, pSCED);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetCharacterJson(ArgumentStack&& args)
{
    JsonEngineStructure retVal;

    if (auto *pPlayer = Utils::PopPlayer(args))
        retVal.m_shared->m_json = PlayerCreatureToJson(pPlayer);
    else
        retVal.m_shared->m_error = "Invalid Player";

    return retVal;
}
