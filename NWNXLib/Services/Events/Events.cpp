#include "Services/Events/Events.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "Utils.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <sstream>

namespace NWNXLib {

namespace Services {

Events::Events()
{
}

Events::~Events()
{
}

Events::EventDataInternal* Events::GetEventData(const std::string& pluginName, const std::string& eventName)
{
    EventList& events = m_eventMap[pluginName];
    auto it = std::find_if(std::begin(events), std::end(events),
        [&eventName](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == eventName;
        }
    );
    return (it == std::end(events)) ? nullptr : it->get();
}

void Events::Call(const std::string& pluginName, const std::string& eventName)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        LOG_DEBUG("Calling event handler. Event '%s', Plugin: '%s'.",
            eventName.c_str(), pluginName.c_str());
        event->m_returns = event->m_callback(std::move(event->m_arguments));
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName.c_str(), eventName.c_str());
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
    eventDataInternal->m_callback = std::forward<FunctionCallback>(cb);
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
    m_registrationTokens.push_back(m_proxyBase.RegisterEvent(m_pluginName, eventName, std::forward<Events::FunctionCallback>(cb)));
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



template<> Maybe<int32_t>&              Events::Argument::Get<int32_t>()             { return m_int; }
template<> Maybe<float>&                Events::Argument::Get<float>()               { return m_float; }
template<> Maybe<API::Types::ObjectID>& Events::Argument::Get<API::Types::ObjectID>(){ return m_object; }
template<> Maybe<std::string>&          Events::Argument::Get<std::string>()         { return m_string; }
template<> Maybe<API::CGameEffect*>&    Events::Argument::Get<API::CGameEffect*>()   { return m_effect; }

std::string Events::Argument::toString()
{
    if (m_int)    return std::to_string(*m_int);
    if (m_float)  return std::to_string(*m_float);
    if (m_object) return Utils::ObjectIDToString(*m_object);
    if (m_string) return *m_string;
    if (m_effect) return *m_effect ? std::string("EffectID:") + std::to_string((*m_effect)->m_nID) : std::string("nullptr effect");

    return std::string("");
}

}

}
