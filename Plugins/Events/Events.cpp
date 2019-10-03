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
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "ViewPtr.hpp"
#include <algorithm>
#include <regex>
#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

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
    if (g_plugin == nullptr) // :(
        g_plugin = this;

    // TODO-64bit: Bring this stuff more in line with how the other plugins handle this
    GetServices()->m_events->RegisterEvent("SUBSCRIBE_EVENT", std::bind(&Events::OnSubscribeEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PUSH_EVENT_DATA", std::bind(&Events::OnPushEventData, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("SIGNAL_EVENT", std::bind(&Events::OnSignalEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_EVENT_DATA", std::bind(&Events::OnGetEventData, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("SKIP_EVENT", std::bind(&Events::OnSkipEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("EVENT_RESULT", std::bind(&Events::OnEventResult, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_CURRENT_EVENT", std::bind(&Events::OnGetCurrentEvent, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("ToggleDispatchListMode", std::bind(&Events::ToggleDispatchListMode, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("AddObjectToDispatchList", std::bind(&Events::AddObjectToDispatchList, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("RemoveObjectFromDispatchList", std::bind(&Events::RemoveObjectFromDispatchList, this, std::placeholders::_1));

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

    m_associateEvents   = std::make_unique<AssociateEvents>(GetServices()->m_hooks);
    m_barterEvents      = std::make_unique<BarterEvents>(GetServices()->m_hooks);
    m_clientEvents      = std::make_unique<ClientEvents>(GetServices()->m_hooks);
    m_combatEvents      = std::make_unique<CombatEvents>(GetServices()->m_hooks);
    m_dmActionEvents    = std::make_unique<DMActionEvents>(GetServices()->m_hooks);
    m_examineEvents     = std::make_unique<ExamineEvents>(GetServices()->m_hooks);
    m_itemEvents        = std::make_unique<ItemEvents>(GetServices()->m_hooks);
    m_featEvents        = std::make_unique<FeatEvents>(GetServices()->m_hooks);
    m_stealthEvents     = std::make_unique<StealthEvents>(GetServices()->m_hooks);
    m_spellEvents       = std::make_unique<SpellEvents>(GetServices()->m_hooks);
    m_partyEvents       = std::make_unique<PartyEvents>(GetServices()->m_hooks);
    m_healerKitEvents   = std::make_unique<HealerKitEvents>(GetServices()->m_hooks);
    m_skillEvents       = std::make_unique<SkillEvents>(GetServices()->m_hooks);
    m_mapEvents         = std::make_unique<MapEvents>(GetServices()->m_hooks);
    m_polymorphEvents   = std::make_unique<PolymorphEvents>(GetServices()->m_hooks);
    m_effectEvents      = std::make_unique<EffectEvents>(GetServices()->m_hooks);
    m_quickChatEvents   = std::make_unique<QuickChatEvents>(GetServices()->m_hooks);
    m_inventoryEvents   = std::make_unique<InventoryEvents>(GetServices()->m_hooks);
    m_trapEvents        = std::make_unique<TrapEvents>(GetServices()->m_hooks);
    m_timingBarEvents   = std::make_unique<TimingBarEvents>(GetServices()->m_hooks);
    m_levelEvents       = std::make_unique<LevelEvents>(GetServices()->m_hooks);
    m_PVPEvents         = std::make_unique<PVPEvents>(GetServices()->m_hooks);
    m_inputEvents       = std::make_unique<InputEvents>(GetServices()->m_hooks);
    m_matChangeEvents   = std::make_unique<MaterialChangeEvents>(GetServices()->m_hooks);
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
    LOG_DEBUG("Getting event data: '%s' -> '%s'.", tag.c_str(), retVal.c_str());
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
                        it.first.c_str(), eventName.c_str());
            it.second();
            erase.push_back(it.first);
        }
    }
    for (auto e: erase)
    {
        m_initList.erase(e);
    }

}

ArgumentStack Events::OnSubscribeEvent(ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    auto script = Services::Events::ExtractArgument<std::string>(args);

    RunEventInit(event);
    auto& eventVector = m_eventMap[event];

    if (std::find(std::begin(eventVector), std::end(eventVector), script) != std::end(eventVector))
    {
        throw std::runtime_error("Attempted to subscribe to an event with a script that already subscribed!");
    }

    LOG_INFO("Script '%s' subscribed to event '%s'.", script.c_str(), event.c_str());
    eventVector.emplace_back(std::move(script));

    return ArgumentStack();
}

ArgumentStack Events::OnPushEventData(ArgumentStack&& args)
{
    const auto tag = Services::Events::ExtractArgument<std::string>(args);
    const auto data = Services::Events::ExtractArgument<std::string>(args);
    PushEventData(tag, data);
    return ArgumentStack();
}

ArgumentStack Events::OnSignalEvent(ArgumentStack&& args)
{
    const auto event = Services::Events::ExtractArgument<std::string>(args);
    const auto object = Services::Events::ExtractArgument<Types::ObjectID>(args);
    bool signalled = SignalEvent(event, object);
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, signalled ? 1 : 0);
    return stack;
}

ArgumentStack Events::OnGetEventData(ArgumentStack&& args)
{
    std::string data = GetEventData(Services::Events::ExtractArgument<std::string>(args));
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, data);
    return stack;
}

ArgumentStack Events::OnSkipEvent(ArgumentStack&&)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    m_eventData.top().m_Skipped = true;

    LOG_DEBUG("Skipping last event.");

    return ArgumentStack();
}

ArgumentStack Events::OnEventResult(ArgumentStack&& args)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    const auto data = Services::Events::ExtractArgument<std::string>(args);

    m_eventData.top().m_Result = data;

    LOG_DEBUG("Received event result '%s'.", data.c_str());

    return ArgumentStack();
}

ArgumentStack Events::OnGetCurrentEvent(ArgumentStack&&)
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

    ArgumentStack stack;
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Events::ToggleDispatchListMode(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto eventName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
    const bool bEnable = Services::Events::ExtractArgument<int32_t>(args) != 0;

    if (bEnable)
        g_plugin->m_dispatchList[eventName+scriptName];
    else
        g_plugin->m_dispatchList.erase(eventName+scriptName);

    return stack;
}

ArgumentStack Events::AddObjectToDispatchList(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}

ArgumentStack Events::RemoveObjectFromDispatchList(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
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
