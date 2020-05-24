#include "Services/Events/Events.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "Utils.hpp"
#include "../../../Core/NWNXCore.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <variant>
#include <sstream>

namespace Core {
extern NWNXCore* g_core;
}

namespace NWNXLib::Services {

Events::EventDataInternal* Events::GetEventData(const std::string& pluginName, const std::string& eventName)
{
    static Events::EventDataInternal* cached = nullptr;
    if(cached && cached->m_data.m_pluginName == pluginName && cached->m_data.m_eventName == eventName)
    {
        return cached;
    }

    EventList& events = m_eventMap[pluginName];
    auto it = std::find_if(std::begin(events), std::end(events),
        [&eventName](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == eventName;
        }
    );

    return cached = (it == std::end(events) ? nullptr : it->get());
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
        std::string pluginNameWithoutPrefix = pluginName.substr(5, pluginName.length() - 5);

        if (!Core::g_core->m_services->m_plugins->FindPluginByName(pluginNameWithoutPrefix))
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

std::string Events::Argument::toString() const
{
    if (Holds<int32_t>()) { return std::to_string(Get<int32_t>()); }
    else if (Holds<float>()) { return std::to_string(Get<float>()); }
    else if (Holds<API::Types::ObjectID>()) { return Utils::ObjectIDToString(Get<API::Types::ObjectID>()); }
    else if (Holds<std::string>()) { return Get<std::string>(); }
    else if (Holds<NullArgument>()) { return "(null)"; }
    else if (Holds<CGameEffect*>()) 
    {
        auto e = Get<CGameEffect*>();
        return e ? std::string("EffectID:") + std::to_string(e->m_nID) : std::string("nullptr effect");
    }
    return "(unknown argument type)";
}

}

std::ostream& operator<<(std::ostream& os, const NWNXLib::Services::Events::Argument& arg)
{
    os << arg.toString();
    return os;
}
