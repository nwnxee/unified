#include "Events.hpp"
#include "API/CExoString.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "Events/AssociateEvents.hpp"
#include "Events/BarterEvents.hpp"
#include "Events/ClientEvents.hpp"
#include "Events/CombatEvents.hpp"
#include "Events/DMActionEvents.hpp"
#include "Events/ExamineEvents.hpp"
#include "Events/FeatEvents.hpp"
#include "Events/ItemEvents.hpp"
#include "Events/MapEvents.hpp"
#include "Events/StealthEvents.hpp"
#include "Events/SpellEvents.hpp"
#include "Events/PartyEvents.hpp"
#include "Events/HealerKitEvents.hpp"
#include "Events/SkillEvents.hpp"
#include "Events/PolymorphEvents.hpp"
#include "Events/EffectEvents.hpp"
#include "Events/QuickChatEvents.hpp"
#include "Events/InventoryEvents.hpp"
#include "Events/TrapEvents.hpp"
#include "Events/TimingBarEvents.hpp"
#include "Events/LevelEvents.hpp"
#include "Events/PVPEvents.hpp"
#include "Events/InputEvents.hpp"
#include "Events/MaterialChangeEvents.hpp"
#include "Events/ObjectEvents.hpp"
#include "Events/UUIDEvents.hpp"
#include "Events/ResourceEvents.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"

#include <algorithm>
#include <regex>
#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Events::Events* g_plugin;

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
    if (g_plugin == nullptr) // :(
        g_plugin = this;

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SubscribeEvent);
    REGISTER(UnsubscribeEvent);
    REGISTER(PushEventData);
    REGISTER(SignalEvent);
    REGISTER(GetEventData);
    REGISTER(SkipEvent);
    REGISTER(SetEventResult);
    REGISTER(GetCurrentEvent);
    REGISTER(ToggleDispatchListMode);
    REGISTER(AddObjectToDispatchList);
    REGISTER(RemoveObjectFromDispatchList);

#undef REGISTER

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

    auto hooker = GetServices()->m_hooks.get();
    m_associateEvents   = std::make_unique<AssociateEvents>(hooker);
    m_barterEvents      = std::make_unique<BarterEvents>(hooker);
    m_clientEvents      = std::make_unique<ClientEvents>(hooker);
    m_combatEvents      = std::make_unique<CombatEvents>(hooker);
    m_dmActionEvents    = std::make_unique<DMActionEvents>(hooker);
    m_examineEvents     = std::make_unique<ExamineEvents>(hooker);
    m_itemEvents        = std::make_unique<ItemEvents>(hooker);
    m_featEvents        = std::make_unique<FeatEvents>(hooker);
    m_stealthEvents     = std::make_unique<StealthEvents>(hooker);
    m_spellEvents       = std::make_unique<SpellEvents>(hooker);
    m_partyEvents       = std::make_unique<PartyEvents>(hooker);
    m_healerKitEvents   = std::make_unique<HealerKitEvents>(hooker);
    m_skillEvents       = std::make_unique<SkillEvents>(hooker);
    m_mapEvents         = std::make_unique<MapEvents>(hooker);
    m_polymorphEvents   = std::make_unique<PolymorphEvents>(hooker);
    m_effectEvents      = std::make_unique<EffectEvents>(hooker);
    m_quickChatEvents   = std::make_unique<QuickChatEvents>(hooker);
    m_inventoryEvents   = std::make_unique<InventoryEvents>(hooker);
    m_trapEvents        = std::make_unique<TrapEvents>(hooker);
    m_timingBarEvents   = std::make_unique<TimingBarEvents>(hooker);
    m_levelEvents       = std::make_unique<LevelEvents>(hooker);
    m_PVPEvents         = std::make_unique<PVPEvents>(hooker);
    m_inputEvents       = std::make_unique<InputEvents>(hooker);
    m_matChangeEvents   = std::make_unique<MaterialChangeEvents>(hooker);
    m_objectEvents      = std::make_unique<ObjectEvents>(hooker);
    m_uuidEvents        = std::make_unique<UUIDEvents>(hooker);
    m_resourceEvents    = std::make_unique<ResourceEvents>(GetServices()->m_tasks.get());
}

Events::~Events()
{
}

void Events::PushEventData(const std::string tag, const std::string data)
{
    LOG_DEBUG("Pushing event data: '%s' -> '%s'.", tag, data);
    g_plugin->CreateNewEventDataIfNeeded();
    g_plugin->m_eventData.top().m_EventDataMap[tag] = std::move(data);
}

std::string Events::GetEventData(const std::string tag)
{
    std::string retVal;
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
    LOG_DEBUG("Getting event data: '%s' -> '%s'.", tag, retVal);
    return retVal;
}

bool Events::SignalEvent(const std::string& eventName, const Types::ObjectID target, std::string *result)
{
    bool skipped = false;

    g_plugin->CreateNewEventDataIfNeeded();

    g_plugin->m_eventData.top().m_EventName = eventName;

    for (const auto& script : g_plugin->m_eventMap[eventName])
    {
        auto DispatchEvent = [&]() -> void {
            LOG_DEBUG("Dispatching notification for event '%s' to script '%s'.", eventName, script);
            CExoString scriptExoStr = script.c_str();

            ++g_plugin->m_eventDepth;
            API::Globals::VirtualMachine()->RunScript(&scriptExoStr, target, 1);

            skipped |= g_plugin->m_eventData.top().m_Skipped;

            if (result)
            {
                *result = g_plugin->m_eventData.top().m_Result;
            }

            --g_plugin->m_eventDepth;
        };

        auto eventDispatchList = g_plugin->m_dispatchList.find(eventName + script);
        if (eventDispatchList != g_plugin->m_dispatchList.end())
        {
            if(eventDispatchList->second.find(target) != eventDispatchList->second.end())
            {
                DispatchEvent();
            }
        }
        else
        {
            DispatchEvent();
        }
    }

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT_RESULT",  { eventName, g_plugin->m_eventData.top().m_Result});
    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT_SKIPPED", { eventName, skipped ? "1" : "0"});

    g_plugin->m_eventData.pop();

    return !skipped;
}

void Events::InitOnFirstSubscribe(const std::string& eventName, std::function<void(void)> init)
{
    g_plugin->m_initList[eventName] = init;
}

void Events::RunEventInit(const std::string& eventName)
{
    std::vector<std::string> erase;
    for (auto it: m_initList)
    {
        if (std::regex_search(eventName, std::regex(it.first)))
        {
            LOG_DEBUG("Running init function for events '%s' (requested by event '%s')",
                        it.first, eventName);
            it.second();
            erase.push_back(it.first);
        }
    }

    for (auto e: erase)
    {
        m_initList.erase(e);
    }
}

ArgumentStack Events::SubscribeEvent(ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    auto script = Services::Events::ExtractArgument<std::string>(args);

    RunEventInit(event);
    auto& eventVector = m_eventMap[event];

    if (std::find(std::begin(eventVector), std::end(eventVector), script) != std::end(eventVector))
    {
        LOG_NOTICE("Script '%s' attempted to subscribe to event '%s' but is already subscribed!", script, event);
    }
    else
    {
        LOG_INFO("Script '%s' subscribed to event '%s'.", script, event);
        eventVector.emplace_back(std::move(script));
    }

    return Services::Events::Arguments();
}

ArgumentStack Events::UnsubscribeEvent(ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!event.empty());
    const auto script = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!script.empty());

    auto& eventVector = m_eventMap[event];
    auto it = std::find(std::begin(eventVector), std::end(eventVector), script);

    if (it == std::end(eventVector))
    {
        LOG_NOTICE("Script '%s' attempted to unsubscribe from event '%s' but is not subscribed!", script, event);
    }
    else
    {
        LOG_INFO("Script '%s' unsubscribed from event '%s'.", script, event);
        eventVector.erase(it);
    }

    return Services::Events::Arguments();
}

ArgumentStack Events::PushEventData(ArgumentStack&& args)
{
    const auto tag = Services::Events::ExtractArgument<std::string>(args);
    const auto data = Services::Events::ExtractArgument<std::string>(args);
    PushEventData(tag, data);
    return Services::Events::Arguments();
}

ArgumentStack Events::SignalEvent(ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    const auto object = Services::Events::ExtractArgument<Types::ObjectID>(args);
    bool signalled = SignalEvent(event, object);

    return Services::Events::Arguments(signalled ? 1 : 0);
}

ArgumentStack Events::GetEventData(ArgumentStack&& args)
{
    std::string data = GetEventData(Services::Events::ExtractArgument<std::string>(args));

    return Services::Events::Arguments(data);
}

ArgumentStack Events::SkipEvent(ArgumentStack&&)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    m_eventData.top().m_Skipped = true;

    LOG_DEBUG("Skipping last event.");

    return Services::Events::Arguments();
}

ArgumentStack Events::SetEventResult(ArgumentStack&& args)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to set event result in an invalid context.");
    }
    const auto data = Services::Events::ExtractArgument<std::string>(args);

    m_eventData.top().m_Result = data;

    LOG_DEBUG("Received event result '%s'.", data);

    return Services::Events::Arguments();
}

ArgumentStack Events::GetCurrentEvent(ArgumentStack&&)
{
    std::string retVal;

    if (m_eventDepth == 0 || m_eventData.empty())
    {
        retVal = "";
    }
    else
    {
        retVal = g_plugin->m_eventData.top().m_EventName;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Events::ToggleDispatchListMode(ArgumentStack&& args)
{
    const auto eventName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
    const bool bEnable = Services::Events::ExtractArgument<int32_t>(args) != 0;

    if (bEnable)
        g_plugin->m_dispatchList[eventName+scriptName];
    else
        g_plugin->m_dispatchList.erase(eventName+scriptName);

    return Services::Events::Arguments();
}

ArgumentStack Events::AddObjectToDispatchList(ArgumentStack&& args)
{
    const auto eventName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = g_plugin->m_dispatchList.find(eventName+scriptName);
    if (eventDispatchList != g_plugin->m_dispatchList.end())
    {
        eventDispatchList->second.insert(oidObject);
    }

    return Services::Events::Arguments();
}

ArgumentStack Events::RemoveObjectFromDispatchList(ArgumentStack&& args)
{
    const auto eventName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = g_plugin->m_dispatchList.find(eventName+scriptName);
    if (eventDispatchList != g_plugin->m_dispatchList.end())
    {
        eventDispatchList->second.erase(oidObject);
    }

    return Services::Events::Arguments();
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
