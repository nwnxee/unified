#include "Events.hpp"
#include "API/CExoString.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "Events/AssociateEvents.hpp"
#include "Events/BarterEvents.hpp"
#include "Events/CalendarEvents.hpp"
#include "Events/ClientEvents.hpp"
#include "Events/CombatEvents.hpp"
#include "Events/DMActionEvents.hpp"
#include "Events/ExamineEvents.hpp"
#include "Events/FactionEvents.hpp"
#include "Events/FeatEvents.hpp"
#include "Events/ItemEvents.hpp"
#include "Events/MapEvents.hpp"
#include "Events/StealthEvents.hpp"
#include "Events/SpellEvents.hpp"
#include "Events/PartyEvents.hpp"
#include "Events/HealingEvents.hpp"
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
#include "Events/QuickbarEvents.hpp"
#include "Events/DebugEvents.hpp"
#include "Events/StoreEvents.hpp"
#include "Events/JournalEvents.hpp"

#include <algorithm>
#include <regex>
#include <string>

static Events::Events* g_plugin;
using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;


NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new ::Events::Events(services);
    return g_plugin;
}

namespace Events {

Events::Events(Services::ProxyServiceList* services)
    : Plugin(services), m_eventDepth(0)
{
    if (g_plugin == nullptr) // :(
        g_plugin = this;

#define REGISTER(func) \
    NWNXLib::Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](NWNXLib::Events::ArgumentStack&& args){ return func(std::move(args)); })

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
    REGISTER(ToggleIDWhitelist);
    REGISTER(AddIDToWhitelist);
    REGISTER(RemoveIDFromWhitelist);

#undef REGISTER

    MessageBus::Subscribe("NWNX_EVENT_SIGNAL_EVENT",
        [](const std::vector<std::string>& message)
        {
            ASSERT(message.size() == 2);
            SignalEvent(message[0], std::strtoul(message[1].c_str(), nullptr, 16));
        });

    MessageBus::Subscribe("NWNX_EVENT_PUSH_EVENT_DATA",
        [](const std::vector<std::string>& message)
        {
            ASSERT(message.size() == 2);
            PushEventData(message[0], message[1]);
        });

    m_associateEvents   = std::make_unique<AssociateEvents>();
    m_barterEvents      = std::make_unique<BarterEvents>();
    m_calendarEvents    = std::make_unique<CalendarEvents>();
    m_clientEvents      = std::make_unique<ClientEvents>();
    m_combatEvents      = std::make_unique<CombatEvents>();
    m_dmActionEvents    = std::make_unique<DMActionEvents>();
    m_examineEvents     = std::make_unique<ExamineEvents>();
    m_factionEvents     = std::make_unique<FactionEvents>();
    m_itemEvents        = std::make_unique<ItemEvents>();
    m_featEvents        = std::make_unique<FeatEvents>();
    m_stealthEvents     = std::make_unique<StealthEvents>();
    m_spellEvents       = std::make_unique<SpellEvents>();
    m_partyEvents       = std::make_unique<PartyEvents>();
    m_healingEvents     = std::make_unique<HealingEvents>();
    m_skillEvents       = std::make_unique<SkillEvents>();
    m_mapEvents         = std::make_unique<MapEvents>();
    m_polymorphEvents   = std::make_unique<PolymorphEvents>();
    m_effectEvents      = std::make_unique<EffectEvents>();
    m_quickChatEvents   = std::make_unique<QuickChatEvents>();
    m_inventoryEvents   = std::make_unique<InventoryEvents>();
    m_trapEvents        = std::make_unique<TrapEvents>();
    m_timingBarEvents   = std::make_unique<TimingBarEvents>();
    m_levelEvents       = std::make_unique<LevelEvents>();
    m_PVPEvents         = std::make_unique<PVPEvents>();
    m_inputEvents       = std::make_unique<InputEvents>();
    m_matChangeEvents   = std::make_unique<MaterialChangeEvents>();
    m_objectEvents      = std::make_unique<ObjectEvents>();
    m_uuidEvents        = std::make_unique<UUIDEvents>();
    m_resourceEvents    = std::make_unique<ResourceEvents>();
    m_quickbarEvents    = std::make_unique<QuickbarEvents>();
    m_debugEvents       = std::make_unique<DebugEvents>();
    m_storeEvents       = std::make_unique<StoreEvents>();
    m_journalEvents     = std::make_unique<JournalEvents>();
}

Events::~Events()
{
}

void Events::PushEventData(const std::string& tag, const std::string& data)
{
    LOG_DEBUG("Pushing event data: '%s' -> '%s'.", tag, data);
    g_plugin->CreateNewEventDataIfNeeded();
    g_plugin->m_eventData.top().m_EventDataMap[tag] = data;
}

std::string Events::GetEventData(const std::string& tag)
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

bool Events::SignalEvent(const std::string& eventName, const ObjectID target, std::string *result)
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

    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT_RESULT",  { eventName, g_plugin->m_eventData.top().m_Result});
    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT_SKIPPED", { eventName, skipped ? "1" : "0"});

    g_plugin->m_eventData.pop();

    return !skipped;
}

void Events::InitOnFirstSubscribe(const std::string& eventName, std::function<void(void)> init)
{
    g_plugin->m_initList[eventName] = std::move(init);
}

bool Events::IsIDInWhitelist(const std::string& eventName, int32_t id)
{
    bool retVal = false;
    auto idWhitelist = g_plugin->m_idWhitelist.find(eventName);

    if (idWhitelist == g_plugin->m_idWhitelist.end())
        retVal = true;// Whitelist is not enabled for eventName
    else
    {
        if(idWhitelist->second.find(id) != idWhitelist->second.end())
            retVal = true;
    }

    return retVal;
}

void Events::ForceEnableWhitelist(const std::string& eventName)
{
    g_plugin->m_idWhitelist[eventName];
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

void Events::RunEventInit(const std::string& eventName)
{
    std::vector<std::string> erase;
    for (const auto& it: m_initList)
    {
        if (std::regex_search(eventName, std::regex(it.first)))
        {
            LOG_DEBUG("Running init function for events '%s' (requested by event '%s')", it.first, eventName);
            it.second();
            erase.push_back(it.first);
        }
    }

    for (const auto& e: erase)
    {
        m_initList.erase(e);
    }
}

ArgumentStack Events::SubscribeEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
    auto script = args.extract<std::string>();

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

    return {};
}

ArgumentStack Events::UnsubscribeEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());
    const auto script = args.extract<std::string>();
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

    return {};
}

ArgumentStack Events::PushEventData(ArgumentStack&& args)
{
    const auto tag = args.extract<std::string>();
    const auto data = args.extract<std::string>();
    PushEventData(tag, data);
    return {};
}

ArgumentStack Events::SignalEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
    const auto object = args.extract<ObjectID>();
    bool signalled = SignalEvent(event, object);

    return signalled ? 1 : 0;
}

ArgumentStack Events::GetEventData(ArgumentStack&& args)
{
    std::string data = GetEventData(args.extract<std::string>());

    return data;
}

ArgumentStack Events::SkipEvent(ArgumentStack&&)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    m_eventData.top().m_Skipped = true;

    LOG_DEBUG("Skipping last event.");

    return {};
}

ArgumentStack Events::SetEventResult(ArgumentStack&& args)
{
    if (m_eventDepth == 0 || m_eventData.empty())
    {
        throw std::runtime_error("Attempted to set event result in an invalid context.");
    }
    const auto data = args.extract<std::string>();

    m_eventData.top().m_Result = data;

    LOG_DEBUG("Received event result '%s'.", data);

    return {};
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

    return retVal;
}

ArgumentStack Events::ToggleDispatchListMode(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptName.empty());
    const bool bEnable = args.extract<int32_t>() != 0;

    if (bEnable)
        g_plugin->m_dispatchList[eventName+scriptName];
    else
        g_plugin->m_dispatchList.erase(eventName+scriptName);

    return {};
}

ArgumentStack Events::AddObjectToDispatchList(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptName.empty());
    const auto oidObject = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = g_plugin->m_dispatchList.find(eventName+scriptName);
    if (eventDispatchList != g_plugin->m_dispatchList.end())
    {
        eventDispatchList->second.insert(oidObject);
    }

    return {};
}

ArgumentStack Events::RemoveObjectFromDispatchList(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptName = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptName.empty());
    const auto oidObject = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = g_plugin->m_dispatchList.find(eventName+scriptName);
    if (eventDispatchList != g_plugin->m_dispatchList.end())
    {
        eventDispatchList->second.erase(oidObject);
    }

    return {};
}

ArgumentStack Events::ToggleIDWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const bool bEnable = args.extract<int32_t>() != 0;

    if (bEnable)
        g_plugin->m_idWhitelist[eventName];
    else
        g_plugin->m_idWhitelist.erase(eventName);

    return {};
}

ArgumentStack Events::AddIDToWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto id = args.extract<int32_t>();

    auto idWhitelist = g_plugin->m_idWhitelist.find(eventName);
    if (idWhitelist != g_plugin->m_idWhitelist.end())
    {
        idWhitelist->second.insert(id);
    }

    return {};
}

ArgumentStack Events::RemoveIDFromWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto id = args.extract<int32_t>();

    auto idWhitelist = g_plugin->m_idWhitelist.find(eventName);
    if (idWhitelist != g_plugin->m_idWhitelist.end())
    {
        idWhitelist->second.erase(id);
    }

    return {};
}

}
