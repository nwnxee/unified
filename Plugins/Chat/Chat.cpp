#include "Chat.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNWSClient.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/Constants.hpp"
#include "API/CServerInfo.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedList.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"

using namespace NWNXLib;

static Chat::Chat* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Chat::Chat(services);
    return g_plugin;
}

using namespace NWNXLib::API;
using namespace NWNXLib::Services;

namespace Chat {

Chat::Chat(Services::ProxyServiceList* services)
    : Plugin(services), m_skipMessage(false), m_depth(0)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SendMessage);
    REGISTER(RegisterChatScript);
    REGISTER(SkipMessage);
    REGISTER(GetChannel);
    REGISTER(GetMessage);
    REGISTER(GetSender);
    REGISTER(GetTarget);
    REGISTER(SetChatHearingDistance);
    REGISTER(GetChatHearingDistance);

#undef REGISTER

    m_chatScript = GetServices()->m_config->Get<std::string>("CHAT_SCRIPT", "");
    m_hearingDistances[Constants::ChatChannel::DmTalk]        = 20.0f;
    m_hearingDistances[Constants::ChatChannel::PlayerTalk]    = 20.0f;
    m_hearingDistances[Constants::ChatChannel::DmWhisper]     = 3.0f;
    m_hearingDistances[Constants::ChatChannel::PlayerWhisper] = 3.0f;
    m_customHearingDistances = false;

    m_hook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN11CNWSMessage29SendServerToPlayerChatMessageEhj10CExoStringjRKS0_>(&Chat::SendServerToPlayerChatMessage);
}

Chat::~Chat()
{
}

void Chat::SendServerToPlayerChatMessage(CNWSMessage* thisPtr, Constants::ChatChannel::TYPE channel, ObjectID sender,
    CExoString message, PlayerID target, CExoString* tellName)
{
    Chat& plugin = *g_plugin;

    if (plugin.m_depth == 0 && !plugin.m_chatScript.empty())
    {
        plugin.m_activeChannel = channel;
        plugin.m_activeMessage = message.m_sString ? std::string(message.m_sString) : "";
        plugin.m_activeSenderObjectId = sender;

        CNWSClient* client = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(target, 0);
        plugin.m_activeTargetObjectId = client ? static_cast<CNWSPlayer*>(client)->m_oidPCObject : Constants::OBJECT_INVALID;

        CExoString script = plugin.m_chatScript.c_str();

        ++plugin.m_depth;
        Globals::VirtualMachine()->RunScript(&script, sender, 1);
        --plugin.m_depth;
    }
    // Suppress player to player tells
    if ((channel != Constants::ChatChannel::PlayerTell && channel != Constants::ChatChannel::DmTell) || sender == target)
    {
        LOG_DEBUG("%s chat message. Channel: '%i', Message: '%s', Sender (ObjID): '0x%08x', Target (PlayerID): '0x%08x'",
            plugin.m_skipMessage ? "Skipped" : "Sent", channel, message.m_sString, sender, target);
    }
    else
    {
        LOG_DEBUG("%s chat message. Channel: '%i'", plugin.m_skipMessage ? "Skipped" : "Sent", channel);
    }

    if (plugin.m_depth > 0 || !plugin.m_skipMessage)
    {
        if (g_plugin->m_customHearingDistances)
        {
            auto server = Globals::AppManager()->m_pServerExoApp;
            auto *playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
            if (playerList)
            {
                if (channel == Constants::ChatChannel::PlayerShout &&
                        server->GetServerInfo()->m_PlayOptions.bDisallowShouting)
                {
                    channel = Constants::ChatChannel::PlayerTalk;
                }
                if (channel == Constants::ChatChannel::PlayerTalk ||
                    channel == Constants::ChatChannel::PlayerWhisper ||
                    channel == Constants::ChatChannel::DmTalk ||
                    channel == Constants::ChatChannel::DmWhisper)
                {
                    auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
                    auto pSpeaker = Utils::AsNWSObject(server->GetGameObject(sender));
                    auto distance = g_plugin->m_hearingDistances[channel];
                    auto speakerPos = Vector{0.0f, 0.0f, 0.0f};
                    CNWSArea *speakerArea = nullptr;
                    if (pSpeaker != nullptr)
                    {
                        speakerArea = pSpeaker->GetArea();
                        speakerPos = pSpeaker->m_vPosition;
                        pSpeaker->BroadcastDialog(*tellName, distance);
                    }

                    for (auto *head = playerList->pHead; head; head = head->pNext)
                    {
                        auto *pClient = static_cast<CNWSClient*>(head->pObject);
                        auto *listenerClient =  server->GetClientObjectByPlayerId(pClient->m_nPlayerID, 0);
                        auto *listener = static_cast<CNWSPlayer*>(listenerClient);
                        auto *listenerObj = Utils::AsNWSObject(listener->GetGameObject());

                        auto pDistance = *pPOS->Get<float>(listenerObj->m_idSelf, "HEARING_DISTANCE:" + std::to_string(channel));
                        if (pDistance >= 0)
                        {
                            distance = pDistance;

                            auto v = listenerObj->m_vPosition;
                            v.x -= speakerPos.x;
                            v.y -= speakerPos.y;
                            v.z -= speakerPos.z;
                            float vSquared = v.x*v.x + v.y*v.y + v.z*v.z;
                            if (speakerArea == listenerObj->GetArea() && vSquared <= distance*distance)
                            {
                                switch (channel)
                                {
                                    case Constants::ChatChannel::PlayerTalk:
                                        thisPtr->SendServerToPlayerChat_Talk(listener->m_nPlayerID, sender, message);
                                        break;
                                    case Constants::ChatChannel::DmTalk:
                                        thisPtr->SendServerToPlayerChat_DM_Talk(listener->m_nPlayerID, sender, message);
                                        break;
                                    case Constants::ChatChannel::PlayerWhisper:
                                        thisPtr->SendServerToPlayerChat_Whisper(listener->m_nPlayerID, sender, message);
                                        break;
                                    case Constants::ChatChannel::DmWhisper:
                                        thisPtr->SendServerToPlayerChat_DM_Whisper(listener->m_nPlayerID, sender, message);
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    plugin.m_hook->CallOriginal<void>(thisPtr, channel, sender, message, target, tellName);
                }
            }
        }
        else
        {
            plugin.m_hook->CallOriginal<void>(thisPtr, channel, sender, message, target, tellName);
        }
    }

    if (plugin.m_depth == 0)
    {
        plugin.m_skipMessage = false;
    }
}

Events::ArgumentStack Chat::SendMessage(Events::ArgumentStack&& args)
{
    int32_t retVal = false;
    const auto channel = static_cast<Constants::ChatChannel::TYPE>(Events::ExtractArgument<int32_t>(args));
    const auto message = Events::ExtractArgument<std::string>(args);
    const auto speaker = Events::ExtractArgument<ObjectID>(args);
    const auto target = Events::ExtractArgument<ObjectID>(args);

    const bool hasManualPlayerId = target != Constants::OBJECT_INVALID;

    const PlayerID playerId = hasManualPlayerId ?
        Globals::AppManager()->m_pServerExoApp->GetPlayerIDByGameObjectID(target) :
        Constants::PLAYERID_ALL_CLIENTS;

    if (playerId != Constants::PLAYERID_INVALIDID)
    {
        bool sentMessage = false;
        CNWSMessage* messageDispatch = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());

        if (hasManualPlayerId)
        {
            // This means we're sending this to one player only.
            // The normal function broadcasts in an area for talk, shout, and whisper, therefore
            // we need to call these functions directly if we are in those categories.
            if (channel == Constants::ChatChannel::PlayerTalk)
            {
                messageDispatch->SendServerToPlayerChat_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmTalk)
            {
                messageDispatch->SendServerToPlayerChat_DM_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerShout || channel == Constants::ChatChannel::DmShout)
            {
                messageDispatch->SendServerToPlayerChat_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerWhisper)
            {
                messageDispatch->SendServerToPlayerChat_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmWhisper)
            {
                messageDispatch->SendServerToPlayerChat_DM_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
        }

        if (!sentMessage)
        {
            messageDispatch->SendServerToPlayerChatMessage(static_cast<uint8_t>(channel), speaker, message.c_str(), playerId, nullptr);
        }

        retVal = true;
    }

    return Events::Arguments(retVal);
}

Events::ArgumentStack Chat::RegisterChatScript(Events::ArgumentStack&& args)
{
    m_chatScript = Events::ExtractArgument<std::string>(args);
    return Events::Arguments();
}

Events::ArgumentStack Chat::SkipMessage(Events::ArgumentStack&&)
{
    m_skipMessage = true;
    return Events::Arguments();
}

Events::ArgumentStack Chat::GetChannel(Events::ArgumentStack&&)
{
    return Events::Arguments(static_cast<int32_t>(m_activeChannel));
}

Events::ArgumentStack Chat::GetMessage(Events::ArgumentStack&&)
{
    return Events::Arguments(m_activeMessage);
}

Events::ArgumentStack Chat::GetSender(Events::ArgumentStack&&)
{
    return Events::Arguments(m_activeSenderObjectId);
}

Events::ArgumentStack Chat::GetTarget(Events::ArgumentStack&&)
{
    return Events::Arguments(m_activeTargetObjectId);
}

Events::ArgumentStack Chat::SetChatHearingDistance(Events::ArgumentStack&& args)
{
    const auto distance = Services::Events::ExtractArgument<float>(args);
    const auto playerOid = Services::Events::ExtractArgument<ObjectID>(args);
    const auto channel = (Constants::ChatChannel::TYPE)Services::Events::ExtractArgument<int32_t>(args);

    if (playerOid == Constants::OBJECT_INVALID)
    {
        m_customHearingDistances = true;
        m_hearingDistances[channel] = distance;
    }
    else
    {
        auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerOid);
        if (!pPlayer)
        {
            LOG_NOTICE("NWNX_Chat function called on non-player object %x", playerOid);
        }
        else
        {
            auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
            m_customHearingDistances = true;
            pPOS->Set(playerOid, "HEARING_DISTANCE:" + std::to_string(channel), distance, true);
        }
    }

    return Events::Arguments();
}

Events::ArgumentStack Chat::GetChatHearingDistance(Events::ArgumentStack&& args)
{
    const auto playerOid = Services::Events::ExtractArgument<ObjectID>(args);
    const auto channel = (Constants::ChatChannel::TYPE)Services::Events::ExtractArgument<int32_t>(args);
    float retVal = m_hearingDistances[channel];

    if (playerOid != Constants::OBJECT_INVALID)
    {
        auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
        auto playerHearingDistance = *pPOS->Get<float>(playerOid, "HEARING_DISTANCE:" + std::to_string(channel));
        retVal = playerHearingDistance > 0 ? playerHearingDistance : m_hearingDistances[channel];
    }
    return Events::Arguments(retVal);
}

}
