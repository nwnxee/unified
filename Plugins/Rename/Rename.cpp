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


using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Rename::Rename> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
  {
    "Rename",
    "Functions to facilitate renaming, overriding and customization of player names.",
    "Silvard",
    "jusenkyo at gmail.com",
    1,
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

  m_blankLocStr.AddString(0, CExoString(""),0); 
  
  GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSMessage__SendServerToPlayerPlayerList_All,int32_t,CNWSMessage*,CNWSPlayer*>(&HookPlayerList);
  
  m_SendServerToPlayerPlayerList_All = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSMessage__SendServerToPlayerPlayerList_All);

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

int32_t Rename::HookPlayerList(CNWSMessage* message, CNWSPlayer* pPlayer)
{
    Rename& plugin = *g_plugin;
    int32_t retVal;
    API::CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    std::vector<Types::PlayerID> playerIDList;
    
    API::CExoLinkedListInternal* playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    
    //traverse the player list and replace the names of all players on the override list
    for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext) 
    {
        CNWSClient* client = reinterpret_cast<API::CNWSClient*>(head->pObject);
        Types::ObjectID clientID = static_cast<CNWSPlayer*>(client)->m_oidNWSObject;
        auto overrideName = plugin.m_ObjectIDtoNameOverride.find(clientID);
        CNWSCreature* pCreature = static_cast<CNWSCreature*>(Globals::AppManager()->m_pServerExoApp->GetGameObject(clientID));
        
        if (client && overrideName != std::end(plugin.m_ObjectIDtoNameOverride) && !pCreature->m_sDisplayName.IsEmpty())
        {
            pCreature->m_pStats->m_lsFirstName = overrideName->second;
            pCreature->m_pStats->m_lsLastName = plugin.m_blankLocStr;
        }
    }
    
    retVal = plugin.m_SendServerToPlayerPlayerList_All->CallOriginal<int32_t>(message, pPlayer); //send the list
    
    //And now we do it again to restore the names after the player list has been sent over 
    for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext)
    {
        CNWSClient* client = reinterpret_cast<API::CNWSClient*>(head->pObject);
        Types::ObjectID clientID = static_cast<CNWSPlayer*>(client)->m_oidNWSObject;
        auto firstName = plugin.m_ObjectIDtoRealFirstName.find(clientID);
        auto lastName = plugin.m_ObjectIDtoRealLastName.find(clientID);
        
        if (client && firstName != std::end(plugin.m_ObjectIDtoRealFirstName))
        {
            CNWSCreature* pCreature = static_cast<CNWSCreature*>(Globals::AppManager()->m_pServerExoApp->GetGameObject(clientID));
            pCreature->m_pStats->m_lsFirstName = firstName->second;
            pCreature->m_pStats->m_lsLastName = lastName->second;
        }
    }

    return retVal;
    
}

void Rename::UpdateName(CNWSCreature* targetObject)
{
    API::CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    std::vector<Types::PlayerID> playersToNotify;
    
    API::CExoLinkedListInternal* playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    
    for (API::CExoLinkedListNode* head = playerList->pHead; head; head = head->pNext)
    {
        API::CNWSClient* client = reinterpret_cast<API::CNWSClient*>(head->pObject);
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
        
        pCreature->m_sDisplayName = fullDisplayName.c_str();
        pCreature->m_bUpdateDisplayName = true; //unsure if this is necessary

        API::CExoLocString locStr;
        locStr.AddString(0, CExoString(newName.c_str()), 0);
        m_ObjectIDtoNameOverride[playerObjectID] = locStr;
        m_ObjectIDtoRealFirstName[playerObjectID] = pCreature->m_pStats->m_lsFirstName; //store original first name
        m_ObjectIDtoRealLastName[playerObjectID] = pCreature->m_pStats->m_lsLastName; //store original last name
        
        UpdateName(pCreature); //this sends an update message to all clients. 

    }
    return stack;
}


}