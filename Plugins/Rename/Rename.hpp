#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
    Rename(const Plugin::CreateParams& params);
    virtual ~Rename();

private:
    int32_t m_RenameOnModuleCharList;
    bool m_RenameOnPlayerList;
    bool m_RenameOnSelf;

    static void WriteGameObjUpdate_UpdateObjectHook(
            Services::Hooks::CallType,
            CNWSMessage*,
            CNWSPlayer*,
            CNWSObject*,
            CLastUpdateObject*,
            uint32_t,
            uint32_t);
    static void SendServerToPlayerPlayerList_AllHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSMessage*,
            CNWSPlayer*);
    static void SendServerToPlayerPlayerList_AddHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSMessage*,
            Types::PlayerID,
            CNWSPlayer*);
    static void SendServerToPlayerPlayerList_DeleteHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSMessage*,
            Types::PlayerID,
            CNWSPlayer*);
    static void SendServerToPlayerExamineGui_CreatureDataHook(
            Services::Hooks::CallType,
            CNWSMessage*,
            CNWSPlayer*,
            Types::ObjectID);
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(
            CNWSMessage*,
            Types::PlayerID,
            Types::ObjectID,
            int32_t);
    static void SendServerToPlayerChatHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSMessage*,
            Types::PlayerID,
            Types::ObjectID,
            CExoString*);
    static int32_t SendServerToPlayerPopUpGUIPanelHook(
            CNWSMessage*,
            Types::ObjectID,
            int32_t, int32_t, int32_t, int32_t, CExoString*);

    static void SetOrRestorePlayerName(NWNXLib::Services::Hooks::CallType, CNWSPlayer*, CNWSPlayer*, bool playerList=false);
    static void SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, Types::ObjectID, bool playerList=false);
    static void RestorePlayerName(CNWSCreature *targetCreature, bool playerList=false);
    void GlobalNameChange(NWNXLib::Services::Hooks::CallType, Types::PlayerID, Types::PlayerID);

    CExoLocString ContainString(const std::string& str);
    std::string GenerateRandomPlayerName(size_t length);

    ArgumentStack SetPCNameOverride(ArgumentStack&& args);
    ArgumentStack GetPCNameOverride(ArgumentStack&& args);

    CNWSPlayer *player(Types::ObjectID playerId);
};

}
