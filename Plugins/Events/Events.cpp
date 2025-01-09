#include "Events.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CScriptCompiler.hpp"
#include "API/CTlkTable.hpp"
#include <set>
#include <regex>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

struct EventParams
{
    std::unordered_map<std::string, std::string> m_EventDataMap; // This maps between event data key -> event data value.
    bool m_Skipped; // This is true if SkipEvent() has been called on this event during its execution.
    std::string m_Result; // The result of the event, if any, is stored here
    std::string m_EventName; // The current event name
};

static std::unordered_map<std::string, std::vector<std::pair<int32_t, std::string>>> s_eventMap; // {EventName} -> {{0=Script, 1=Chunk, 2=Chunk+WrapInMain}, ScriptName/Chunk}
static std::stack<EventParams> s_eventData; // Data tag -> data for currently executing event.
static uint8_t s_eventDepth;
static std::unordered_map<std::string, std::function<void(void)>> s_initList;
static std::unordered_map<std::string, std::set<ObjectID>> s_dispatchList;
static std::unordered_map<std::string, std::set<int32_t>> s_idWhitelist;

static auto s_idSignal = MessageBus::Subscribe("NWNX_EVENT_SIGNAL_EVENT",
    [](const std::vector<std::string> &message)
    {
        ASSERT(message.size() == 2);
        SignalEvent(message[0], std::strtoul(message[1].c_str(), nullptr, 16));
    });

static auto s_idPush = MessageBus::Subscribe("NWNX_EVENT_PUSH_EVENT_DATA",
    [](const std::vector<std::string> &message)
    {
        ASSERT(message.size() == 2);
        PushEventData(message[0], message[1]);
    });

static std::string GetEventData(const std::string& tag);
static void CreateNewEventDataIfNeeded();
static void RunEventInit(const std::string& eventName);

void PushEventData(const std::string& tag, const std::string& data)
{
    LOG_DEBUG("Pushing event data: '%s' -> '%s'.", tag, data);
    CreateNewEventDataIfNeeded();
    s_eventData.top().m_EventDataMap[tag] = data;
}

std::string GetEventData(const std::string& tag)
{
    std::string retVal;
    if (s_eventDepth == 0 || s_eventData.empty())
    {
        LOG_ERROR("Attempted to access invalid event data or in an invalid context.");
        return retVal;
    }

    auto& eventData = s_eventData.top();
    auto data = eventData.m_EventDataMap.find(tag);

    if (data == std::end(eventData.m_EventDataMap))
    {
        LOG_ERROR("Tried to access event data with invalid tag: '%s'.", tag);
        return retVal;
    }

    retVal = data->second;
    LOG_DEBUG("Getting event data: '%s' -> '%s'.", tag, retVal);
    return retVal;
}

bool SignalEvent(const std::string& eventName, const ObjectID target, std::string *result)
{
    INSTR_SCOPE();
    INSTR_SCOPE_PROP_STR("Event", eventName.c_str());

    bool skipped = false;

    CreateNewEventDataIfNeeded();

    s_eventData.top().m_EventName = eventName;

    for (const auto& subscribers : s_eventMap[eventName])
    {
        auto DispatchEvent = [&]() -> void
        {
            LOG_DEBUG("Dispatching notification for event '%s' to script(chunk) '%s'.", eventName, subscribers.second);

            ++s_eventDepth;

            CExoString sScriptOrChunk = subscribers.second;

            if (subscribers.first == 0)
            {
                Globals::VirtualMachine()->RunScript(&sScriptOrChunk, target, true);
            }
            else
            {
                int32_t ret = Globals::VirtualMachine()->RunScriptChunk(sScriptOrChunk, target, true, (subscribers.first - 1));

                if (ret < 0)
                {
                    LOG_ERROR("Script chunk '%s' for event '%s' failed with error -> %s: %s", subscribers.second, eventName,
                                Globals::TlkTable()->GetSimpleString(-ret).CStr(), Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
                }
            }

            skipped |= s_eventData.top().m_Skipped;

            if (result)
            {
                *result = s_eventData.top().m_Result;
            }

            --s_eventDepth;
        };

        auto eventDispatchList = s_dispatchList.find(eventName + subscribers.second);
        if (eventDispatchList != s_dispatchList.end())
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

    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT_RESULT",  { eventName, s_eventData.top().m_Result});
    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT_SKIPPED", { eventName, skipped ? "1" : "0"});

    s_eventData.pop();

    return !skipped;
}

void InitOnFirstSubscribe(const std::string& eventName, std::function<void(void)> init)
{
    s_initList[eventName] = std::move(init);
}

bool IsIDInWhitelist(const std::string& eventName, int32_t id)
{
    bool retVal = false;
    auto idWhitelist = s_idWhitelist.find(eventName);

    if (idWhitelist == s_idWhitelist.end())
        retVal = true;// Whitelist is not enabled for eventName
    else
    {
        if(idWhitelist->second.find(id) != idWhitelist->second.end())
            retVal = true;
    }

    return retVal;
}

void ForceEnableWhitelist(const std::string& eventName)
{
    s_idWhitelist[eventName];
}

// Pushes a brand new event data onto the event data stack, set up with the correct defaults.
// Only does it if needed though, based on the current event depth!
void CreateNewEventDataIfNeeded()
{
    if (s_eventData.size() <= s_eventDepth)
    {
        EventParams params;
        params.m_Skipped = false;
        s_eventData.emplace(std::move(params));
    }
}

void RunEventInit(const std::string& eventName)
{
    std::vector<std::string> erase;
    for (const auto& it: s_initList)
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
        s_initList.erase(e);
    }
}

NWNX_EXPORT ArgumentStack SubscribeEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());
    const auto script = args.extract<std::string>();
      ASSERT_OR_THROW(!script.empty());

    RunEventInit(event);

    auto& eventVector = s_eventMap[event];
    auto pair = std::make_pair(0, script);

    if (std::find(std::begin(eventVector), std::end(eventVector), pair) != std::end(eventVector))
    {
        LOG_NOTICE("Script '%s' attempted to subscribe to event '%s' but is already subscribed!", script, event);
    }
    else
    {
        LOG_INFO("Script '%s' subscribed to event '%s'.", script, event);
        eventVector.emplace_back(pair);
    }

    return {};
}

NWNX_EXPORT ArgumentStack UnsubscribeEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());
    const auto script = args.extract<std::string>();
      ASSERT_OR_THROW(!script.empty());

    auto& eventVector = s_eventMap[event];
    auto pair = std::make_pair(0, script);
    auto it = std::find(std::begin(eventVector), std::end(eventVector), pair);

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

NWNX_EXPORT ArgumentStack UnsubscribeAllStartingWith(ArgumentStack&& args)
{
    const auto prefix = args.extract<std::string>();

    for (auto& eventMapPair : s_eventMap)
    {
        auto it = eventMapPair.second.begin();
        while (it != eventMapPair.second.end())
        {
            if (it->second.rfind(prefix, 0) == 0)
            {
                LOG_INFO("Script '%s' unsubscribed from event '%s'.", it->second, eventMapPair.first);
                it = eventMapPair.second.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack SubscribeEventScriptChunk(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());
    auto scriptChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptChunk.empty());
    const auto wrapIntoMain = args.extract<int32_t>() != 0;

    RunEventInit(event);

    auto& eventVector = s_eventMap[event];
    auto pair = std::make_pair(wrapIntoMain + 1, scriptChunk);

    if (std::find(std::begin(eventVector), std::end(eventVector), pair) != std::end(eventVector))
    {
        LOG_NOTICE("Script Chunk '%s' attempted to subscribe to event '%s' but is already subscribed!", scriptChunk, event);
    }
    else
    {
        LOG_INFO("Script Chunk '%s' subscribed to event '%s'.", scriptChunk, event);
        eventVector.emplace_back(pair);
    }

    return {};
}

NWNX_EXPORT ArgumentStack UnsubscribeEventScriptChunk(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());
    auto scriptChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptChunk.empty());
    const auto wrapIntoMain = args.extract<int32_t>() != 0;

    auto& eventVector = s_eventMap[event];
    auto pair = std::make_pair(wrapIntoMain + 1, scriptChunk);
    auto it = std::find(std::begin(eventVector), std::end(eventVector), pair);

    if (it == std::end(eventVector))
    {
        LOG_NOTICE("Script Chunk '%s' attempted to unsubscribe from event '%s' but is not subscribed!", scriptChunk, event);
    }
    else
    {
        LOG_INFO("Script Chunk '%s' unsubscribed from event '%s'.", scriptChunk, event);
        eventVector.erase(it);
    }

    return {};
}

NWNX_EXPORT ArgumentStack PushEventData(ArgumentStack&& args)
{
    const auto tag = args.extract<std::string>();
    const auto data = args.extract<std::string>();
    PushEventData(tag, data);
    return {};
}

NWNX_EXPORT ArgumentStack SignalEvent(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
    const auto object = args.extract<ObjectID>();

    return SignalEvent(event, object);
}

NWNX_EXPORT ArgumentStack GetEventData(ArgumentStack&& args)
{
    return GetEventData(args.extract<std::string>());
}

NWNX_EXPORT ArgumentStack SkipEvent(ArgumentStack&&)
{
    if (s_eventDepth == 0 || s_eventData.empty())
    {
        throw std::runtime_error("Attempted to skip event in an invalid context.");
    }
    s_eventData.top().m_Skipped = true;

    LOG_DEBUG("Skipping last event.");

    return {};
}

NWNX_EXPORT ArgumentStack SetEventResult(ArgumentStack&& args)
{
    if (s_eventDepth == 0 || s_eventData.empty())
    {
        throw std::runtime_error("Attempted to set event result in an invalid context.");
    }

    const auto data = args.extract<std::string>();
    s_eventData.top().m_Result = data;

    LOG_DEBUG("Received event result '%s'.", data);

    return {};
}

NWNX_EXPORT ArgumentStack GetCurrentEvent(ArgumentStack&&)
{
    if (s_eventDepth == 0 || s_eventData.empty())
        return "";
    else
        return s_eventData.top().m_EventName;
}

NWNX_EXPORT ArgumentStack ToggleDispatchListMode(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptOrChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptOrChunk.empty());
    const bool bEnable = args.extract<int32_t>() != 0;

    if (bEnable)
        s_dispatchList[eventName+scriptOrChunk];
    else
        s_dispatchList.erase(eventName+scriptOrChunk);

    return {};
}

NWNX_EXPORT ArgumentStack AddObjectToDispatchList(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptOrChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptOrChunk.empty());
    const auto oidObject = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = s_dispatchList.find(eventName+scriptOrChunk);
    if (eventDispatchList != s_dispatchList.end())
    {
        eventDispatchList->second.insert(oidObject);
    }

    return {};
}

NWNX_EXPORT ArgumentStack RemoveObjectFromDispatchList(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto scriptOrChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptOrChunk.empty());
    const auto oidObject = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    auto eventDispatchList = s_dispatchList.find(eventName+scriptOrChunk);
    if (eventDispatchList != s_dispatchList.end())
    {
        eventDispatchList->second.erase(oidObject);
    }

    return {};
}

NWNX_EXPORT ArgumentStack ToggleIDWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const bool bEnable = args.extract<int32_t>() != 0;

    if (bEnable)
        s_idWhitelist[eventName];
    else
        s_idWhitelist.erase(eventName);

    return {};
}

NWNX_EXPORT ArgumentStack AddIDToWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto id = args.extract<int32_t>();

    auto idWhitelist = s_idWhitelist.find(eventName);
    if (idWhitelist != s_idWhitelist.end())
    {
        idWhitelist->second.insert(id);
    }

    return {};
}

NWNX_EXPORT ArgumentStack RemoveIDFromWhitelist(ArgumentStack&& args)
{
    const auto eventName = args.extract<std::string>();
      ASSERT_OR_THROW(!eventName.empty());
    const auto id = args.extract<int32_t>();

    auto idWhitelist = s_idWhitelist.find(eventName);
    if (idWhitelist != s_idWhitelist.end())
    {
        idWhitelist->second.erase(id);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetNumSubscribers(ArgumentStack&& args)
{
    const auto event = args.extract<std::string>();
      ASSERT_OR_THROW(!event.empty());

    auto subscribers = s_eventMap.find(event);
    if (subscribers != s_eventMap.end())
        return (int32_t)subscribers->second.size();
    else
        return 0;
}

}
