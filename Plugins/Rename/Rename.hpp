#pragma once

#include "nwnx.hpp"
#include <unordered_set>

using namespace NWNXLib;
using namespace NWNXLib::API;

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
    Rename(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Rename();

private:
    std::unordered_map<ObjectID, std::unordered_map<ObjectID, std::tuple<CExoString, CExoString, int32_t>>> m_RenamePlayerNames;
    std::unordered_map<ObjectID, std::tuple<CExoString, CExoLocString, CExoLocString>> m_RenameOriginalNames;
    std::unordered_map<ObjectID, std::string> m_ObfuscatedNames;
    bool m_RenameOnModuleCharList;
    std::unordered_set<PlayerID> m_RenameAddedToPlayerList;
    bool m_RenameOnPlayerList;
    bool m_RenameAllowDM;
    std::string m_RenameAnonymousPlayerName;
    bool m_RenameOverwriteDisplayName;

    static void WriteGameObjUpdate_UpdateObjectHook(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);
    static int32_t SendServerToPlayerPlayerList_AllHook(CNWSMessage*, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_AddHook(CNWSMessage*, PlayerID, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_DeleteHook(CNWSMessage*, PlayerID, CNWSPlayer*);
    static int32_t SendServerToPlayerDungeonMasterUpdatePartyListHook(CNWSMessage*, PlayerID);
    static int32_t SendServerToPlayerExamineGui_CreatureDataHook(CNWSMessage*, CNWSPlayer*, ObjectID);
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage*, PlayerID, ObjectID, int32_t);
    static int32_t SendServerToPlayerPopUpGUIPanelHook(CNWSMessage*, ObjectID, int32_t, int32_t, int32_t, int32_t, CExoString*);
    static void SetOrRestorePlayerName(bool, CNWSPlayer*, CNWSPlayer*, bool playerList=false);
    static void SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, ObjectID, bool playerList=false);
    static void RestorePlayerName(CNWSCreature *targetCreature, bool playerList=false);
    void GlobalNameChange(bool, PlayerID, PlayerID);

    std::string GenerateRandomPlayerName(size_t length, ObjectID targetOid);
    bool IsCreatureInLastUpdateObjectList(CNWSPlayer *player, ObjectID creatureId);

    void SendNameUpdate(CNWSCreature *targetCreature, PlayerID observerPlayerId);

    ArgumentStack SetPCNameOverride(ArgumentStack&& args);
    ArgumentStack GetPCNameOverride(ArgumentStack&& args);
    ArgumentStack ClearPCNameOverride(ArgumentStack&& args);

    CNWSPlayer *player(ObjectID playerId);
};

}
