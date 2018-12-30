#include "Events.hpp"
#include "API/CExoString.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Events/AssociateEvents.hpp"
#include "Events/ClientEvents.hpp"
#include "Events/CombatEvents.hpp"
#include "Events/DMActionEvents.hpp"
#include "Events/ExamineEvents.hpp"
#include "Events/FeatEvents.hpp"
#include "Events/ItemEvents.hpp"
#include "Events/StealthEvents.hpp"
#include "Events/SpellEvents.hpp"
#include "Events/PartyEvents.hpp"
#include "Events/HealerKitEvents.hpp"
#include "Events/SkillEvents.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "ViewPtr.hpp"
#include <algorithm>

using namespace NWNXLib;

static ViewPtr<Events::Events> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Events",
        "Provides an interface for plugins to create event-based systems, and exposes some events through that interface.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Events::Events(params);
    return g_plugin;
}

namespace Events {

Events::Events(const Plugin::CreateParams& params)
    : Plugin(params), m_eventDepth(0)
{
    GetServices()->m_events->RegisterEvent("SUBSCRIBE_EVENT", std::bind(&Events::OnSubscribeEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PUSH_EVENT_DATA", std::bind(&Events::OnPushEventData, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("SIGNAL_EVENT", std::bind(&Events::OnSignalEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_EVENT_DATA", std::bind(&Events::OnGetEventData, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("SKIP_EVENT", std::bind(&Events::OnSkipEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("EVENT_RESULT", std::bind(&Events::OnEventResult, this, std::placeholders::_1));

    GetServices()->m_messaging->SubscribeMessage("NWNX_EVENT_SIGNAL_EVENT",
        [](const std::vector<std::string> message)
        {
            ASSERT(message.size() == 2);
            SignalEvent(message[0], std::strtoul(message[1].c_str(), nullptr, 16));
        });

    GetServices()->m_messaging->SubscribeMessage("NWNX_EVENT_PUSH_EVENT_DATA",
        [](const std::vector<std::string> message)
        {
            ASSERT(message.size() == 2);
            PushEventData(message[0], message[1]);
        });

    if (GetServices()->m_config->Get<bool>("ENABLE_ASSOCIATE_EVENTS", true))
    {
        m_associateEvents = std::make_unique<AssociateEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_CLIENT_EVENTS", true))
    {
        m_clientEvents = std::make_unique<ClientEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_COMBAT_EVENTS", true))
    {
        m_combatEvents = std::make_unique<CombatEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_DM_ACTION_EVENTS", true))
    {
        m_dmActionEvents = std::make_unique<DMActionEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_EXAMINE_EVENTS", true))
    {
        m_examineEvents = std::make_unique<ExamineEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_ITEM_EVENTS", true))
    {
        m_itemEvents = std::make_unique<ItemEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_FEAT_EVENTS", true))
    {
        m_featEvents = std::make_unique<FeatEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_STEALTH_EVENTS", true))
    {
        m_stealthEvents = std::make_unique<StealthEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_SPELL_EVENTS", true))
    {
        m_spellEvents = std::make_unique<SpellEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_PARTY_EVENTS", true))
    {
        m_partyEvents = std::make_unique<PartyEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_HEALER_KIT_EVENTS", true))
    {
        m_healerKitEvents = std::make_unique<HealerKitEvents>(GetServices()->m_hooks);
    }

    if (GetServices()->m_config->Get<bool>("ENABLE_SKILL_EVENTS", true))
    {
        m_skillEvents = std::make_unique<SkillEvents>(GetServices()->m_hooks);
    }        
}

Events::~Events()
{
}

void Events::PushEventData(const std::string tag, const std::string data)
{
    LOG_DEBUG("Pushing event data: '%s' -> '%s'.", tag.c_str(), data.c_str());
    g_plugin->CreateNewEventDataIfNeeded();
    g_plugin->m_eventData.top().m_EventDataMap[tag] = std::move(data);
}


std::string Events::GetEventData(const std::string tag)
{
    std::string retVal="";
    if (g_plugin->m_eventDepth == 0 || g_plugin->m_eventData.empty())
    {
        LOG_ERROR("Attempted to access invalid event data or in an invalid context.");
        return retVal;
    }

    auto& eventData = g_plugin->m_eventData.top();
    auto data = eventData.m_EventDataMap.find(tag);

    if (data == std::end(eventData.m_EventDataMap))
    {
        LOG_ERROR("Tried to access event data with invalid tag.");
        return retVal;
    }

    retVal=data->second;
    LOG_DEBUG("Getting event data: '%s' -> '%s'.", tag.c_str(), retVal.c_str());
    return retVal;
}

bool Events::SignalEvent(const std::string& eventName, const API::Types::ObjectID target, std::string *result)
{
    bool skipped = false;

    g_plugin->CreateNewEventDataIfNeeded();

    for (const auto& script : g_plugin->m_eventMap[eventName])
    {
        LOG_DEBUG("Dispatching notification for event '%s' to script '%s'.", eventName.c_str(), script.c_str());
        API::CExoString scriptExoStr = script.c_str();

        ++g_plugin->m_eventDepth;
        API::Globals::VirtualMachine()->RunScript(&scriptExoStr, target, 1);

        skipped |= g_plugin->m_eventData.top().m_Skipped;

        if (result)
        {
            *result = g_plugin->m_eventData.top().m_Result;
        }

        --g_plugin->m_eventDepth;
    }

    g_plugin->m_eventData.pop();

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT_RESULT",  { eventName, result ? *result : ""});
    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT_SKIPPED", { eventName, skipped ? "1" : "0"});    

    return !skipped;
}

Services::Events::ArgumentStack Events::OnSubscribeEvent(Services::Events::ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    auto script = Services::Events::ExtractArgument<std::string>(args);

    auto& eventVector = m_eventMap[event];

    if (std::find(std::begin(eventVector), std::end(eventVector), script) != std::end(eventVector))
    {
        throw std::runtime_error("Attempted to subscribe to an event with a script that already subscribed!");
    }

    LOG_INFO("Script '%s' subscribed to event '%s'.", script.c_str(), event.c_str());
    eventVector.emplace_back(std::move(script));

    return Services::Events::ArgumentStack();
}

Services::Events::ArgumentStack Events::OnPushEventData(Services::Events::ArgumentStack&& args)
{
    const auto tag = Services::Events::ExtractArgument<std::string>(args);
    const auto data = Services::Events::ExtractArgument<std::string>(args);
    PushEventData(tag, data);
    return Services::Events::ArgumentStack();
}

Services::Events::ArgumentStack Events::OnSignalEvent(Services::Events::ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    const auto object = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    bool signalled = SignalEvent(event, object);
    Services::Events::ArgumentStack stack;
    Services::Events::InsertArgument(stack, signalled ? 1 : 0);
    return stack;
}

Services::Events::ArgumentStack Events::OnGetEventData(Services::Events::ArgumentStack&& args)
{
    std::string data = GetEventData(Services::Events::ExtractArgument<std::string>(args));
    Services::Events::ArgumentStack stack;
    Services::Events::InsertArgument(stack, data);
    return stack;
}

Services::Events::ArgumentStack Events::OnSkipEvent(Services::Events::ArgumentStack&& args)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    m_eventData.top().m_Skipped = true;

    LOG_DEBUG("Skipping last event.");

    return Services::Events::ArgumentStack();
}

Services::Events::ArgumentStack Events::OnEventResult(Services::Events::ArgumentStack&& args)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    const auto data = Services::Events::ExtractArgument<std::string>(args);

    m_eventData.top().m_Result = data;

    LOG_DEBUG("Received event result '%s'.", data.c_str());

    return Services::Events::ArgumentStack();
}

void Events::CreateNewEventDataIfNeeded()
{
    if (m_eventData.size() <= m_eventDepth)
    {
        EventParams params;
        params.m_Skipped = false;
        m_eventData.emplace(std::move(params));
    }
}

}
