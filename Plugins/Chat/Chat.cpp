#include "Chat.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNWSClient.hpp"
#include "API/CNWSDungeonMaster.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<Chat::Chat> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Chat",
        "Allows chat events to be captured, skipped, and manual chat messages to be dispatched.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Chat::Chat(params);
    return g_plugin;
}

using namespace NWNXLib::API;
using namespace NWNXLib::Services;

namespace Chat {

Chat::Chat(const Plugin::CreateParams& params)
    : Plugin(params), m_skipMessage(false), m_depth(0)
{
    m_chatScript = GetServices()->m_config->Get<std::string>("CHAT_SCRIPT", "");

    GetServices()->m_events->RegisterEvent("SEND_MESSAGE", std::bind(&Chat::OnSendMessage, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("REGISTER_CHAT_SCRIPT", std::bind(&Chat::OnRegisterChatScript, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("SKIP_MESSAGE", std::bind(&Chat::OnSkipMessage, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_CHANNEL", std::bind(&Chat::OnGetChannel, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_MESSAGE", std::bind(&Chat::OnGetMessage, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_SENDER", std::bind(&Chat::OnGetSender, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_TARGET", std::bind(&Chat::OnGetTarget, this, std::placeholders::_1));

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSMessage__SendServerToPlayerChatMessage>(&Chat::SendServerToPlayerChatMessage);
    m_hook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSMessage__SendServerToPlayerChatMessage);
}

Chat::~Chat()
{
}

void Chat::SendServerToPlayerChatMessage(CNWSMessage* thisPtr, ChatChannel channel, Types::ObjectID sender,
    CExoString message, Types::PlayerID target, CExoString* tellName)
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

    LOG_DEBUG("%s chat message. Channel: '%i', Message: '%s', Sender (ObjID): '0x%08x', Target (PlayerID): '0x%08x'",
        plugin.m_skipMessage ? "Skipped" : "Sent", channel, message.m_sString, sender, target);

    if (!plugin.m_skipMessage)
    {
        plugin.m_hook->CallOriginal<void>(thisPtr, channel, sender, message, target, tellName);
    }

    if (plugin.m_depth == 0)
    {
        plugin.m_skipMessage = false;
    }
}

Events::ArgumentStack Chat::OnSendMessage(Events::ArgumentStack&& args)
{
    const auto channel = static_cast<ChatChannel>(Events::ExtractArgument<int32_t>(args));
    const auto message = Events::ExtractArgument<std::string>(args);
    const auto speaker = Events::ExtractArgument<Types::ObjectID>(args);
    const auto target = Events::ExtractArgument<Types::ObjectID>(args);

    const bool hasManualPlayerId = target != Constants::OBJECT_INVALID;

    const Types::PlayerID playerId = hasManualPlayerId ?
        Globals::AppManager()->m_pServerExoApp->GetPlayerIDByGameObjectID(target) :
        Constants::PLAYERID_ALL_CLIENTS;

    Events::ArgumentStack stack;

    if (playerId != Constants::PLAYERID_INVALIDID)
    {
        bool sentMessage = false;
        CNWSMessage* messageDispatch = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());

        if (hasManualPlayerId)
        {
            // This means we're sending this to one player only.
            // The normal function broadcasts in an area for talk, shout, and whisper, therefore
            // we need to call these functions directly if we are in those categories.
            if (channel == ChatChannel::PLAYER_TALK || channel == ChatChannel::DM_TALK)
            {
                messageDispatch->SendServerToPlayerChat_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == ChatChannel::PLAYER_SHOUT || channel == ChatChannel::DM_SHOUT)
            {
                messageDispatch->SendServerToPlayerChat_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == ChatChannel::PLAYER_WHISPER || channel == ChatChannel::DM_WHISPER)
            {
                messageDispatch->SendServerToPlayerChat_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
        }

        if (!sentMessage)
        {
            messageDispatch->SendServerToPlayerChatMessage(static_cast<uint8_t>(channel), speaker, message.c_str(), playerId, nullptr);
        }

        Events::InsertArgument(stack, 1);
    }
    else
    {
        Events::InsertArgument(stack, 0);
    }

    return stack;
}

Events::ArgumentStack Chat::OnRegisterChatScript(Events::ArgumentStack&& args)
{
    m_chatScript = Events::ExtractArgument<std::string>(args);
    return Events::ArgumentStack();
}

Events::ArgumentStack Chat::OnSkipMessage(Events::ArgumentStack&&)
{
    m_skipMessage = true;
    return Events::ArgumentStack();
}

Events::ArgumentStack Chat::OnGetChannel(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, static_cast<int32_t>(m_activeChannel));
    return stack;
}

Events::ArgumentStack Chat::OnGetMessage(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeMessage);
    return stack;
}

Events::ArgumentStack Chat::OnGetSender(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeSenderObjectId);
    return stack;
}

Events::ArgumentStack Chat::OnGetTarget(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeTargetObjectId);
    return stack;
}

}
