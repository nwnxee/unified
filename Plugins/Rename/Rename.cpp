#include "Rename.hpp"

#include <sstream>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CLastUpdateObject.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Messaging/Messaging.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Rename::Rename> g_plugin;

const std::string firstNameKey = "REAL FIRST NAME";
const std::string lastNameKey = "REAL LAST NAME";
const std::string overrideNameKey = "OVERRIDE NAME";

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
  {
    "Rename",
    "Functions to facilitate renaming, overriding and customization of player names.",
    "Silvard",
    "jusenkyo at gmail.com",
    2,
    true
  };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
  g_plugin = new Rename::Rename(params);
  return g_plugin;
}

namespace Rename {
    
Rename::Rename(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
  GetServices()->m_events->RegisterEvent(#func, std::bind(&Rename::func, this, std::placeholders::_1))

  REGISTER(SetPlayerNameOverride);

#undef REGISTER
  
  GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerPlayerList_All,int32_t,CNWSMessage*,CNWSPlayer*>(&HookPlayerList); 
  
  try //try to request a hook. If it fails that means that NWNX_EVENTS_PARTY_EVENTS is enabled, which should broadcast a message to trigger the name change anyway.
  {
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__HandlePlayerToServerParty,int32_t,CNWSMessage*,CNWSPlayer*,unsigned char>(&HookPartyInvite);
  } 
  catch (...){}
  GetServices()->m_messaging->SubscribeMessage("NWNX_EVENT_SIGNAL_EVENT_SKIPPED",
        [this](const std::vector<std::string> message)
        {   if (message[1] == "0") //if the event was skipped it doesn't matter what the event was. 
            {
                if (message[0] == "NWNX_ON_PARTY_INVITE_BEFORE") this->GlobalNameChange(false);
                if (message[0] == "NWNX_ON_PARTY_INVITE_AFTER") this->GlobalNameChange(true);
            }
        });  
}

Rename::~Rename()
{
}

CNWSPlayer *Rename::player(Types::ObjectID playerId)
{

    if (playerId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Rename function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerId);
    if (!pPlayer)
    {
        LOG_NOTICE("NWNX_Rename function called on non-player object %x", playerId);
    }
    return pPlayer;
}

void Rename::HookPlayerList(Services::Hooks::CallType cType, CNWSMessage* message, CNWSPlayer* pPlayer)
{
    Rename& plugin = *g_plugin;
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        //traverse the player list and replace the names of all players on the override list
        plugin.GlobalNameChange(false);
    }
    else
    { 
        //And now we do it again to restore the names after the player list has been sent over 
        plugin.GlobalNameChange(true);
    }
}

void Rename::HookPartyInvite(Services::Hooks::CallType cType, NWNXLib::API::CNWSMessage* message, CNWSPlayer* pPlayer, unsigned char c)
{
    Rename& plugin = *g_plugin;
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        //traverse the player list and replace the names of all players on the override list
        plugin.GlobalNameChange(false);
    }
    else
    {
        //And now we do it again to restore the names after the party invite
        plugin.GlobalNameChange(true);
    }
}

void Rename::GlobalNameChange(bool bOriginal)
{
    API::CServerExoAppInternal* server = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
    API::CExoLinkedListInternal* playerList = server->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    
    std::string lsFirstName;
    std::string lsLastName;
    
    //go through all the players and change their names or restore them based on bOriginal.
    for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext) 
    {
        CNWSClient* client = static_cast<API::CNWSClient*>(head->pObject);
        Types::ObjectID pcObjectID = static_cast<CNWSPlayer*>(client)->m_oidNWSObject;
        lsFirstName = (bOriginal) ?  *g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(pcObjectID,firstNameKey) :  *g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(pcObjectID,overrideNameKey);
        lsLastName = (bOriginal) ?  *g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(pcObjectID,lastNameKey) : std::string("");
        CNWSCreature* pCreature = server->GetCreatureByGameObjectID(pcObjectID);
        
        if (pCreature && !lsFirstName.empty() && ( bOriginal || !pCreature->m_sDisplayName.IsEmpty()))
        {
            pCreature->m_pStats->m_lsFirstName = ContainString(lsFirstName);
            pCreature->m_pStats->m_lsLastName = ContainString(lsLastName);
        }
    }
}

std::string Rename::ExtractString(CExoLocString& locStr)
{
    CExoString str;
    locStr.GetStringLoc(0,&str,0);
    return std::string(str.CStr());
}

CExoLocString Rename::ContainString(const std::string& str)
{
    CExoLocString locStr;
    locStr.AddString(0,CExoString(str.c_str()),0);
    return locStr;
}

void Rename::UpdateName(CNWSCreature* targetObject)
{
    API::CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    std::vector<Types::PlayerID> playersToNotify;
    
    API::CExoLinkedListInternal* playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    
    for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext)
    {
        API::CNWSClient* client = static_cast<API::CNWSClient*>(head->pObject);
        if (client)
        {
            playersToNotify.emplace_back(client->m_nPlayerID); //gather a list of players to iterate through and notify of the name change
        }
    }

    API::CNWSMessage* message = server->m_pcExoAppInternal->m_pMessage;

    for (auto& pid : playersToNotify)
    {
        API::CNWSPlayer* observerPlayerObject = static_cast<API::CNWSPlayer*>(server->GetClientObjectByPlayerId(pid, 0));

        if (observerPlayerObject)
        {
            // Write a message notifying an object update.
            message->CreateWriteMessage(0x400, pid, 1);

            // We don't need one for our update.
            // However, the appearance update is contingent on receiving a pointer which isn't nullptr.
            API::CLastUpdateObject* lastUpdateObj = reinterpret_cast<API::CLastUpdateObject*>(0xDEADBEEF);

            message->WriteGameObjUpdate_UpdateObject(observerPlayerObject, targetObject, lastUpdateObj, 0, 0x400);

            uint8_t* data = nullptr;
            uint32_t size = 0;

            if (message->GetWriteMessage(&data, &size) && size)
            {
                message->SendServerToPlayerMessage(pid, 5, 1, data, size);
            }

            // Update the player list. This handles updating the hover-over GUI elements too.
            message->SendServerToPlayerPlayerList_All(observerPlayerObject);
        }   
    }
}


ArgumentStack Rename::SetPlayerNameOverride(ArgumentStack&& args)
{
     ArgumentStack stack;
    auto playerObjectID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    if (auto *pPlayer = player(playerObjectID))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(playerObjectID);
        if (!pCreature)
        {
            LOG_ERROR("No creature object found for Player ID %x, oidNWSObject %x",
                pPlayer->m_oidPCObject, playerObjectID);
            return stack;
        }
        
        const auto sPrefix = Services::Events::ExtractArgument<std::string>(args);
        const auto newName = Services::Events::ExtractArgument<std::string>(args);
        const auto sSuffix = Services::Events::ExtractArgument<std::string>(args);
        
        const std::string fullDisplayName = sPrefix + newName + sSuffix; //put together the floaty/chat/hover name
        
        pCreature->m_sDisplayName = fullDisplayName.c_str(); //sets the override floaty name, this goes away on logout/reset
        pCreature->m_bUpdateDisplayName = true; //unsure if this is necessary

        g_plugin->GetServices()->m_perObjectStorage->Set(playerObjectID,overrideNameKey, newName); //store affix-less override
        g_plugin->GetServices()->m_perObjectStorage->Set(playerObjectID,firstNameKey, ExtractString(pCreature->m_pStats->m_lsFirstName)); //store original first name
        g_plugin->GetServices()->m_perObjectStorage->Set(playerObjectID,lastNameKey, ExtractString(pCreature->m_pStats->m_lsLastName)); //store original last name
        
        UpdateName(pCreature); //this sends an update message to all clients. 

    }
    return stack;
}


}