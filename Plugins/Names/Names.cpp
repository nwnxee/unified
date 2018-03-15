#include "Names.hpp"
#include "API/CAppManager.hpp"
#include "API/CLastUpdateObject.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CNWSClient.hpp"
#include "API/CNWSDungeonMaster.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Patching/Patching.hpp"
#include "ViewPtr.hpp"

#include <algorithm>

using namespace NWNXLib;

static ViewPtr<Names::Names> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Names",
        "TODO",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Names::Names(params);
    return g_plugin;
}

using namespace NWNXLib::API;
using namespace NWNXLib::Platform;
using namespace NWNXLib::Services;

namespace Names {

namespace {

CNWSCreature* ObjectIDToCreature(Types::ObjectID objectId)
{
    return static_cast<CNWSCreature*>(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId));
}

Types::PlayerID ClientToPlayerID(CNWSPlayer* client)
{
    return client->m_nPlayerID;
}

CNWSCreature* ClientToCreature(CNWSClient* client)
{
    return ObjectIDToCreature(static_cast<CNWSPlayer*>(client)->m_oidNWSObject);
}

}

Names::Names(const Plugin::CreateParams& params)
    : Plugin(params)
{
    GetServices()->m_events->RegisterEvent("SET_NAME", std::bind(&Names::OnSetName, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_NAME", std::bind(&Names::OnGetName, this, std::placeholders::_1));

    using namespace NWNXLib::Platform::Assembly;

    // This function handles all of the network-related communications.
    // N/A  [CNWSMessage::WriteCExoLocStringServer] 0x080524FD]
    //      <---

    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateObject] 0x080733FC (first name)
    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateObject] 0x08073413 (last name)
    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateObject] 0x080732AA (first name)
    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateObject] 0x080732C4 (last name)
    //              Observer (CNWSPlayer*) at EBP+12, Target (CNWSCreature*) at EBP+16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080733F2, 0x08073401 - 0x080733F2,
        PushRegMemByteInstruction(Register::EBP, 16), // pAreaObject
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0807340D, 0x08073418 - 0x0807340D,
        PushRegMemByteInstruction(Register::EBP, 16), // pAreaObject
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080732A1, 0x080732AF - 0x080732A1,
        PushRegMemByteInstruction(Register::EBP, 16), // pAreaObject
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080732BE, 0x080732C9 - 0x080732BE,
        PushRegMemByteInstruction(Register::EBP, 16), // pAreaObject
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateAppearance] 0x0806A372 (First name)
    // PATCH    [CNWSMessage::WriteGameObjUpdate_UpdateAppearance] 0x0806A389 (Last name)
    //              Target (CNWSCreature*) at EBP+12
    //          <---
    // N/A          [CNWSMessage::WriteGameObjUpdate_UpdateObject]
    //                  Observer (CNWSPlayer*) at EBP+12

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0806A36C, 0x0806A377 - 0x0806A36C,
        PushRegMemByteInstruction(Register::EBP, 12), // pAreaObject
        MovRegRegInstruction(Register::EAX, Register::EBP),
        MovRegRegMemInstruction(Register::EAX, Register::EAX), // EBP from WriteGameObjUpdate_UpdateObject
        PushRegMemByteInstruction(Register::EAX, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0806A383, 0x0806A38E - 0x0806A383,
        PushRegMemByteInstruction(Register::EBP, 12), // pAreaObject
        MovRegRegInstruction(Register::EAX, Register::EBP),
        MovRegRegMemInstruction(Register::EAX, Register::EAX), // EBP from WriteGameObjUpdate_UpdateObject
        PushRegMemByteInstruction(Register::EAX, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerPlayerList_Add] 0x080772FC (first name)
    // PATCH    [CNWSMessage::SendServerToPlayerPlayerList_Add] 0x0807730F (last name)
    //              Observer (PlayerID) at EBP + 12, Target (CNWSPlayer*) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080772F1, 0x08077301 - 0x080772F1,
        PushRegMemByteInstruction(Register::EBP, 16), // pNewPlayer
        CallRelInstruction(&ClientToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08077304, 0x08077314 - 0x08077304,
        PushRegMemByteInstruction(Register::EBP, 16), // pNewPlayer
        CallRelInstruction(&ClientToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage:SendServerToPlayerPlayerList_All] 0x08077822 (first name)
    // PATCH    [CNWSMessage:SendServerToPlayerPlayerList_All] 0x08077833 (last name)
    //              Observer (CNWSPlayer*) at EBP + 12, Target (ObjectID) at EBP - 168

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08077819, 0x08077827 - 0x08077819,
        PushRegMemDwordInstruction(Register::EBP, -168), // local variable player
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0807782A, 0x08077838 - 0x0807782A,
        PushRegMemDwordInstruction(Register::EBP, -168), // local variable player
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse] 0x0807E512 (first name)
    // PATCH    [CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse] 0x0807E521 (last name)
    //              Observer (PlayerID) at EBP + 12, Target (ObjectID) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0807E50D, 0x0807E517 - 0x0807E50D,
        PushRegMemByteInstruction(Register::EBP, 16), // nCharacterId
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x0807E51A, 0x0807E526 - 0x0807E51A,
        PushRegMemByteInstruction(Register::EBP, 16), // nCharacterId
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerExamineGui_CreatureData] 0x08073BB9 (first name)
    // PATCH    [CNWSMessage::SendServerToPlayerExamineGui_CreatureData] 0x08073BDA (last name)
    //              Observer (CNWSPlayer*) at EBP + 12, Target (ObjectID) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08073BB5, 0x08073BBE - 0x08073BB5,
        PushRegMemByteInstruction(Register::EBP, 16), // oidCreatureID
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08073BD6, 0x08073BDF - 0x08073BD6,
        PushRegMemByteInstruction(Register::EBP, 16), // oidCreatureID
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        CallRelInstruction(&ClientToPlayerID),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerChat_Party] 0x0806911D
    // PATCH    [CNWSMessage::SendServerToPlayerChat_Party] 0x08069138
    //              Observer (PlayerID) EBP + 12, Target (ObjectID) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08069119, 0x08069122 - 0x08069119,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08069134, 0x0806913D - 0x08069134,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerChat_Tell] 0x080695E5
    // PATCH    [CNWSMessage::SendServerToPlayerChat_Tell] 0x08069600
    //              Observer (PlayerID) EBP + 12, Target (ObjectID) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080695E1, 0x080695EA - 0x080695E1,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x080695FC, 0x08069605 - 0x080695FC,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::SendServerToPlayerChat_Shout] 0x0806983C
    // PATCH    [CNWSMessage::SendServerToPlayerChat_Shout] 0x08069857
    //              Observer (PlayerID) EBP + 12, Target (ObjectID) at EBP + 16

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08069838, 0x08069841 - 0x08069838,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFirstName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08069853, 0x0806985C - 0x08069853,
        PushRegMemByteInstruction(Register::EBP, 16), // oidSpeaker
        CallRelInstruction(&ObjectIDToCreature),
        AddRegImmByteInstruction(Register::ESP, 4),
        PushRegInstruction(Register::EAX),
        PushRegMemByteInstruction(Register::EBP, 12), // nPlayerId
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteLastName),
        AddRegImmByteInstruction(Register::ESP, 4)
    ); NWNX_EXPECT_VERSION(8109);

    // PATCH    [CNWSMessage::HandlePlayerToServerParty] 0x08197E91
    //              Observer (ObjectID) at EBP-136, Target (CNWSPlayer*) at EBP+12,

    GetServices()->m_patching->PatchWithInstructionsTrampoline(0x08197E91, 0x08197ECB - 0x08197E91,
        PushRegMemByteInstruction(Register::EBP, 12), // pPlayer
        PushRegMemDwordInstruction(Register::EBP, -136),
        PushRegMemByteInstruction(Register::EBP, 8), // this
        CallRelInstruction(&WriteFullName),
        AddRegImmByteInstruction(Register::ESP, 12)
    ); NWNX_EXPECT_VERSION(8109);
}

Names::~Names()
{
}

void Names::WriteFullName(CNWSMessage* msg, Types::ObjectID observer, CNWSPlayer* target)
{
    API::CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    API::CNWSCreature* targetGameObject = static_cast<CNWSCreature*>(server->GetGameObject(target->m_oidNWSObject));
    Types::PlayerID observerPlayerId = server->GetPlayerIDByGameObjectID(observer);

    ViewPtr<API::CExoLocString> overrideName = g_plugin->GetStringAsObservedBy(observer, targetGameObject->m_idSelf);

    if (overrideName)
    {
        API::CExoString str;
        overrideName->GetStringLoc(0, &str, 0);
        msg->SendServerToPlayerPopUpGUIPanel(observer, 1, 0, 0, 0, str);
    }
    else
    {
        msg->SendServerToPlayerPopUpGUIPanel(observer, 1, 0, 0, 0, targetGameObject->m_pStats->GetFullName());
    }

    g_plugin->GetServices()->m_log->Debug("Request to write full name for party invite GUI popup received. %s. "
        "Observer (PlayerID): '0x%08x', Observer (ObjectID): '0x%08x', Target (PlayerID): '0x%08x', Target (ObjectID): '0x%08x'",
        overrideName != nullptr ? "Used manual name" : "Did not use manual name", observerPlayerId, observer, target->m_nPlayerID,
        targetGameObject->m_idSelf);
}

// Because all of the writes happen as firstname->lastname, by flagging when we've hit Names::WriteFirstName
// we can avoid an additional lookup in Names::WriteLastName.
static bool s_wroteFirstName;

void Names::WriteFirstName(CNWSMessage* msg, Types::PlayerID observer, CNWSCreature* target)
{
    ViewPtr<API::CExoLocString> overrideName = g_plugin->GetStringAsObservedBy(observer, target->m_idSelf);
    s_wroteFirstName = overrideName != nullptr;

    if (s_wroteFirstName)
    {
        msg->WriteCExoLocStringServer(*overrideName, 0);
    }
    else
    {
        msg->WriteCExoLocStringServer(target->m_pStats->m_lsFirstName, 0);
    }

    g_plugin->GetServices()->m_log->Debug("Request to write first name received. %s. Observer (PlayerID): '0x%08x', Target (ObjectID): '0x%08x'",
        s_wroteFirstName ? "Used manual name" : "Did not use manual name", observer, target->m_idSelf);
}

void Names::WriteLastName(CNWSMessage* msg, Types::PlayerID observer, CNWSCreature* target)
{
    if (s_wroteFirstName)
    {
        API::CExoLocString locStr;
        locStr.AddString(0, API::CExoString(""), 0);
        msg->WriteCExoLocStringServer(locStr, 0);
    }
    else
    {
        msg->WriteCExoLocStringServer(target->m_pStats->m_lsLastName, 0);
    }

    g_plugin->GetServices()->m_log->Debug("Request to write last name received. %s. Observer (PlayerID): '0x%08x', Target (ObjectID): '0x%08x'",
        s_wroteFirstName ? "Used manual name" : "Did not use manual name", observer, target->m_idSelf);

    s_wroteFirstName = false;
}

Events::ArgumentStack Names::OnSetName(Events::ArgumentStack&& args)
{
    const auto observerObjectId = Events::ExtractArgument<Types::ObjectID>(args);
    const auto name = Events::ExtractArgument<std::string>(args);
    const auto targetObjectId = Events::ExtractArgument<Types::ObjectID>(args);

    API::CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    API::CNWSCreature* targetObject = static_cast<API::CNWSCreature*>(server->GetGameObject(targetObjectId));

    if (targetObjectId == Constants::OBJECT_INVALID || !targetObject)
    {
        throw std::runtime_error("Invalid target object provided.");
    }

    const Types::PlayerID targetPlayerId = server->GetPlayerIDByGameObjectID(targetObjectId);
    const Types::PlayerID observerPlayerId = observerObjectId == Constants::OBJECT_INVALID ? Constants::PLAYERID_ALL_CLIENTS : server->GetPlayerIDByGameObjectID(observerObjectId);

    if (targetPlayerId == Constants::PLAYERID_INVALIDID || observerPlayerId == Constants::PLAYERID_INVALIDID)
    {
        throw std::runtime_error("Invalid observer object provided.");
    }

    std::unique_ptr<API::CExoLocString> locStr = std::make_unique<API::CExoLocString>();
    locStr->AddString(0, API::CExoString(name.c_str()), 0);
    m_namesMap[targetObjectId][observerPlayerId] = std::move(locStr);

    std::vector<Types::PlayerID> playersToNotify;

    if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS)
    {
        // Get all the connected players.
        API::CExoLinkedListInternal* playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;

        for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext)
        {
            API::CNWSClient* client = reinterpret_cast<API::CNWSClient*>(head->pObject);
            if (client)
            {
                playersToNotify.emplace_back(client->m_nPlayerID);
            }
        }
    }
    else
    {
        playersToNotify.emplace_back(observerPlayerId);
    }

    API::CNWSMessage* message = server->m_pcExoAppInternal->m_pMessage;

    for (auto& pid : playersToNotify)
    {
        bool success = false;
        API::CNWSPlayer* observerPlayerObject = static_cast<API::CNWSPlayer*>(server->GetClientObjectByPlayerId(pid, 0));

        if (observerPlayerObject)
        {
            // Write a message notifying an object update.
            message->CreateWriteMessage(0x400, pid, 1);

            // We don't need one for our update.
            // However, the appearance update is contingent on receivinga pointer which isn't nullptr.
            API::CLastUpdateObject* lastUpdateObj = reinterpret_cast<API::CLastUpdateObject*>(0xDEADBEEF);

            message->WriteGameObjUpdate_UpdateObject(observerPlayerObject, targetObject, lastUpdateObj, 0, 0x400);

            uint8_t* data = nullptr;
            uint32_t size = 0;

            if (message->GetWriteMessage(&data, &size) && size)
            {
                message->SendServerToPlayerMessage(pid, 5, 1, data, size);
                success = true;
            }

            // Update the player list. This handles updating the hover-over GUI elements too.
            message->SendServerToPlayerPlayerList_All(observerPlayerObject);
        }

        g_plugin->GetServices()->m_log->Debug("%s sending name update message for observer (PlayerID): '0x%08x', target (ObjectID): '0x%08x'.",
            success ? "Succeeded" : "Failed", pid, targetObjectId);
    }

    return Events::ArgumentStack();
}

Events::ArgumentStack Names::OnGetName(Events::ArgumentStack&& args)
{
    const auto observerObjectId = Events::ExtractArgument<Types::ObjectID>(args);
    const auto targetObjectId = Events::ExtractArgument<Types::ObjectID>(args);

    const Types::PlayerID observerPlayerId = observerObjectId == Constants::OBJECT_INVALID ?
        Constants::PLAYERID_ALL_CLIENTS : Globals::AppManager()->m_pServerExoApp->GetPlayerIDByGameObjectID(observerObjectId);

    if (observerPlayerId == Constants::PLAYERID_INVALIDID)
    {
        throw std::runtime_error("Invalid observer object provided.");
    }

    Events::ArgumentStack stack;
    ViewPtr<API::CExoLocString> name = GetStringAsObservedBy(observerPlayerId, targetObjectId);

    if (name)
    {
        API::CExoString str;
        name->GetStringLoc(0, &str, 0);
        Events::InsertArgument(stack, std::string(str.m_sString));
    }
    else
    {
        Events::InsertArgument(stack, std::string(""));
    }

    return stack;
}

ViewPtr<API::CExoLocString> Names::GetStringAsObservedBy(API::Types::PlayerID observer, API::Types::ObjectID target)
{
    auto targetBucket = m_namesMap.find(target);

    if (targetBucket != std::end(m_namesMap))
    {
        PlayerIdToNameMap& names = targetBucket->second;

        // Check for player override.
        auto locatedName = names.find(observer);

        if (locatedName == std::end(names))
        {
            // None found -- check for general override instead.
            for (auto& elem : names)
            {
                if (elem.first >= API::Constants::PLAYERID_ALL_GAMEMASTERS)
                {
                    // General broadcast override.
                    return elem.second.get();
                }
            }
        }
        else
        {
            // Specific player->object override.
            return locatedName->second.get();
        }
    }

    return nullptr;
}

}
