#include "Services/Events/Events.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "Utils.hpp"
#include "../../../Core/NWNXCore.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <sstream>

namespace Core {
extern NWNXCore* g_core;
}

namespace NWNXLib::Services {

Events::EventDataInternal* Events::GetEventData(const std::string& pluginName, const std::string& eventName)
{
    static Events::EventDataInternal* s_cached = nullptr;
    if(s_cached && s_cached->m_data.m_pluginName == pluginName && s_cached->m_data.m_eventName == eventName)
    {
        return s_cached;
    }

    EventList& events = m_eventMap[pluginName];
    auto it = std::find_if(std::begin(events), std::end(events),
        [&eventName](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == eventName;
        }
    );

    return s_cached = (it == std::end(events) ? nullptr : it->get());
}

void Events::Call(const std::string& pluginName, const std::string& eventName)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        LOG_DEBUG("Calling event handler. Event '%s', Plugin: '%s'.",
            eventName, pluginName);
        try
        {
            event->m_returns = event->m_callback(std::move(event->m_arguments));
        }
        catch (const std::exception& err)
        {
            LOG_ERROR("Plugin '%s' failed event '%s'. Error: %s", pluginName, eventName, err.what());
        }
    }
    else
    {
        if (!Core::g_core->m_services->m_plugins->FindPluginByName(pluginName))
        {
            LOG_ERROR("Plugin '%s' is not loaded but NWScript '%s' tried to call function '%s'.",
                    pluginName, Utils::GetCurrentScript(), eventName);
        }
        else
        {
            LOG_ERROR("Plugin '%s' does not have an event '%s' registered. (NWScript: '%s', are your nwnx_*.nss files up to date?)",
                    pluginName, eventName, Utils::GetCurrentScript());
        }
    }
}


Events::RegistrationToken Events::RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb)
{
    EventList& events = m_eventMap[pluginName];

    auto event = std::find_if(std::begin(events), std::end(events),
        [&eventName](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == eventName;
        }
    );

    if (event != std::end(events))
    {
        throw std::runtime_error("Tried to register an event twice with the same name.");
    }

    EventData eventData = { pluginName, eventName };
    auto eventDataInternal = std::make_unique<EventDataInternal>();
    eventDataInternal->m_data = eventData;
    eventDataInternal->m_callback = std::move(cb);
    events.emplace_back(std::move(eventDataInternal));

    return { std::move(eventData) };
}

void Events::ClearEvent(RegistrationToken&& token)
{
    auto pluginEvents = m_eventMap.find(token.m_data.m_pluginName);

    if (pluginEvents == std::end(m_eventMap))
    {
        throw std::runtime_error("Invalid or duplicate event registration token.");
    }

    EventList& eventsList = pluginEvents->second;

    auto event = std::find_if(std::begin(eventsList), std::end(eventsList),
        [&token](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == token.m_data.m_eventName;
        }
    );

    if (event == std::end(eventsList))
    {
        throw std::runtime_error("Invalid or duplicate event registration token.");
    }

    eventsList.erase(event);
}


EventsProxy::EventsProxy(Events& events, std::string pluginName)
    : ServiceProxy<Events>(events), m_pluginName(pluginName)
{
}

EventsProxy::~EventsProxy()
{
    for (Events::RegistrationToken& token : m_registrationTokens)
    {
        m_proxyBase.ClearEvent(std::move(token));
    }
}

void EventsProxy::RegisterEvent(const std::string& eventName, Events::FunctionCallback&& cb)
{
    m_registrationTokens.push_back(m_proxyBase.RegisterEvent(m_pluginName, eventName, std::move(cb)));
}

void EventsProxy::ClearEvent(const std::string& eventName)
{
    auto token = std::find_if(std::begin(m_registrationTokens), std::end(m_registrationTokens),
        [this, &eventName](const Events::RegistrationToken& check)
        {
            return check.m_data.m_pluginName == m_pluginName && check.m_data.m_eventName == eventName;
        }
    );

    if (token == std::end(m_registrationTokens))
    {
        throw std::runtime_error("Tried to clear unrecognised event.");
    }

    Events::RegistrationToken concreteToken = std::move(*token);
    m_registrationTokens.erase(token);
    m_proxyBase.ClearEvent(std::move(concreteToken));
}

}
