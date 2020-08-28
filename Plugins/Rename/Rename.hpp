#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "Common.hpp"
#include <unordered_set>

using namespace NWNXLib;
using namespace NWNXLib::API;

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
    Rename(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Rename();

private:
    std::unordered_map<ObjectID, std::unordered_map<ObjectID, std::tuple<CExoString, CExoString, int32_t>>> m_RenamePlayerNames;
    std::unordered_map<ObjectID, std::tuple<CExoString, CExoLocString, CExoLocString>> m_RenameOriginalNames;
    int32_t m_RenameOnModuleCharList;
    std::unordered_set<PlayerID> m_RenameAddedToPlayerList;
    bool m_RenameOnPlayerList;
    bool m_RenameAllowDM;
    std::string m_RenameAnonymousPlayerName;
    bool m_RenameOverwriteDisplayName;

    static void WriteGameObjUpdate_UpdateObjectHook(bool, CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);
    static void SendServerToPlayerPlayerList_AllHook(bool, CNWSMessage*, CNWSPlayer*);
    static void SendServerToPlayerPlayerList_AddHook(bool, CNWSMessage*, PlayerID, CNWSPlayer*);
    static void SendServerToPlayerPlayerList_DeleteHook(bool, CNWSMessage*, PlayerID, CNWSPlayer*);
    static void SendServerToPlayerDungeonMasterUpdatePartyListHook(bool, CNWSMessage*, PlayerID);
    static void SendServerToPlayerExamineGui_CreatureDataHook(bool, CNWSMessage*, CNWSPlayer*, ObjectID);
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage*, PlayerID, ObjectID, int32_t);
    static void SendServerToPlayerChatHook(bool, CNWSMessage*, PlayerID, ObjectID, CExoString*);
    static int32_t SendServerToPlayerPopUpGUIPanelHook(CNWSMessage*, ObjectID, int32_t, int32_t, int32_t, int32_t, CExoString*);
    static void SetOrRestorePlayerName(bool, CNWSPlayer*, CNWSPlayer*, bool playerList=false);
    static void SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, ObjectID, bool playerList=false);
    static void RestorePlayerName(CNWSCreature *targetCreature, bool playerList=false);
    void GlobalNameChange(bool, PlayerID, PlayerID);

    CExoLocString ContainString(const std::string& str);
    std::string GenerateRandomPlayerName(size_t length);

    void SendNameUpdate(CNWSCreature *targetCreature, PlayerID observerPlayerId);

    ArgumentStack SetPCNameOverride(ArgumentStack&& args);
    ArgumentStack GetPCNameOverride(ArgumentStack&& args);
    ArgumentStack ClearPCNameOverride(ArgumentStack&& args);

    CNWSPlayer *player(ObjectID playerId);
};

}
