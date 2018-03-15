#include "Services/Events/Events.hpp"
#include "API/CExoString.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <sstream>

namespace {

std::vector<std::string> SplitString(const std::string& str)
{
    std::vector<std::string> tokens;

    size_t start = 0;
    size_t end = 0;

    while ((end = str.find('!', start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}

}

namespace NWNXLib {

namespace Services {

Events::Events()
{
}

Events::~Events()
{
}

void Events::OnSetLocalString(std::string&& index, std::string&& value)
{
    try
    {
        const ParsedCommand command = FindEventDataFromIndex(index);

        if (command.m_eventData)
        {
            if (!command.m_eventData->m_returns.empty())
            {
                throw std::runtime_error("Tried to operate on an event without first retrieving all the return values.");
            }

            switch (command.m_function)
            {
                case BuiltInFunction::CALL_FUNCTION:
                    LOG_DEBUG("Calling event handler. Event '%s', Plugin: '%s'.",
                        command.m_eventData->m_data.m_eventName.c_str(),
                        command.m_eventData->m_data.m_pluginName.c_str());
                    command.m_eventData->m_returns = command.m_eventData->m_callback(std::move(command.m_eventData->m_arguments));
                    break;

                case BuiltInFunction::PUSH_ARGUMENT:
                    LOG_DEBUG("Pushing argument '%s'. Event '%s', Plugin: '%s'.",
                        value.c_str(),
                        command.m_eventData->m_data.m_eventName.c_str(),
                        command.m_eventData->m_data.m_pluginName.c_str());
                    command.m_eventData->m_arguments.push(std::forward<std::string>(value));
                    break;

                case BuiltInFunction::GET_RETURN_VALUE:
                case BuiltInFunction::INVALID:
                    throw std::runtime_error("Malformed input.");
            }
        }
    }
    catch (const std::runtime_error& err)
    {
        LOG_ERROR("SetLocalString encountered error '%s' for input '%s' and value '%s'.", err.what(), index.c_str(), value.c_str());
        return;
    }
}

Maybe<std::string> Events::OnGetLocalString(std::string&& index)
{
    try
    {
        const ParsedCommand command = FindEventDataFromIndex(index);

        if (command.m_eventData)
        {
            if (command.m_eventData->m_returns.empty())
            {
                throw std::runtime_error("Tried to get a return value when one did not exist.");
            }

            switch (command.m_function)
            {
                case BuiltInFunction::GET_RETURN_VALUE:
                {
                    std::string retVal = command.m_eventData->m_returns.top();
                    command.m_eventData->m_returns.pop();

                    if (retVal.size() < TYPE_SIZE_IN_CHARACTERS || command.m_specifiers.size() < TYPE_SIZE_IN_CHARACTERS)
                    {
                        throw std::runtime_error("Invalid type sizes.");
                    }

                    const bool typeMatches = std::strncmp(
                        command.m_specifiers.c_str(),
                        retVal.c_str(),
                        TYPE_SIZE_IN_CHARACTERS) == 0;

                    if (!typeMatches)
                    {
                        throw std::runtime_error("Type mismatch.");
                    }

                    // Strip typeinfo
                    retVal = retVal.substr(2);

                    LOG_DEBUG("Returning value '%s'. Event '%s', Plugin: '%s'.",
                        retVal.c_str(),
                        command.m_eventData->m_data.m_eventName.c_str(),
                        command.m_eventData->m_data.m_pluginName.c_str());

                    return Maybe<std::string>(std::move(retVal));
                }

                case BuiltInFunction::CALL_FUNCTION:
                case BuiltInFunction::PUSH_ARGUMENT:
                case BuiltInFunction::INVALID:
                    throw std::runtime_error("Malformed input.");
            }
        }
    }
    catch (const std::runtime_error& err)
    {
        LOG_ERROR("GetLocalString encountered error '%s' for input '%s'.", err.what(), index.c_str());
    }

    return Maybe<std::string>();
}

Maybe<API::Types::ObjectID> Events::OnGetLocalObject(std::string&& index)
{
    auto objectAsStr = OnGetLocalString(std::forward<std::string>(index));
    return objectAsStr ? Maybe<API::Types::ObjectID>(std::strtoul((*objectAsStr).c_str(), nullptr, 16)) : Maybe<API::Types::ObjectID>();
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

Events::BuiltInFunction Events::FromString(const std::string& str)
{
    if (str == "PUSH_ARGUMENT")
    {
        return BuiltInFunction::PUSH_ARGUMENT;
    }
    else if (str == "CALL_FUNCTION")
    {
        return BuiltInFunction::CALL_FUNCTION;
    }
    else if (str == "GET_RETURN_VALUE")
    {
        return BuiltInFunction::GET_RETURN_VALUE;
    }
    else
    {
        ASSERT_FAIL();
        return BuiltInFunction::INVALID;
    }
}

std::string Events::ToString(const Events::BuiltInFunction func)
{
    switch (func)
    {
        case BuiltInFunction::PUSH_ARGUMENT: return "PUSH_ARGUMENT";
        case BuiltInFunction::CALL_FUNCTION:  return "CALL_FUNCTION";
        case BuiltInFunction::GET_RETURN_VALUE: return "GET_RETURN_VALUE";
        case BuiltInFunction::INVALID: break;
    }

    ASSERT_FAIL();
    return "";
}

Events::ParsedCommand Events::FindEventDataFromIndex(const std::string& index)
{
    const std::vector<std::string> split = SplitString(index);
    const bool correctInputFormat = split.size() == 3 || split.size() == 4;

    if (!correctInputFormat)
    {
        throw std::runtime_error("Input string size mismatch.");
    }

    const BuiltInFunction function = FromString(split[0]);
    const std::string& pluginName = split[1];
    const std::string& eventName = split[2];

    auto plugin = m_eventMap.find(pluginName);

    if (plugin == std::end(m_eventMap))
    {
        throw std::runtime_error("Plugin was not found in the event map.");
    }

    auto event = std::find_if(std::begin(plugin->second), std::end(plugin->second),
        [&eventName](const std::unique_ptr<EventDataInternal>& data) -> bool
        {
            return data->m_data.m_eventName == eventName;
        }
    );

    if (event == std::end(plugin->second))
    {
        throw std::runtime_error("Event was not registered for the provided plugin.");
    }

    std::string specifiers;

    if (split.size() == 4)
    {
        specifiers = split[3];
    }

    return { function, specifiers, event->get() };
}

Events::CastableTypes Events::ExtractType(const std::string& data)
{
    std::array<char, TYPE_SIZE_IN_CHARACTERS + 1> buffer; // + 1 for null term
    std::memcpy(buffer.data(), data.c_str(), TYPE_SIZE_IN_CHARACTERS);
    buffer[TYPE_SIZE_IN_CHARACTERS] = '\0';
    return static_cast<CastableTypes>(std::strtol(buffer.data(), nullptr, 10));
}

template <>
Maybe<float> Events::StringToTypeCast<float>(std::string&& data)
{
    using MaybeTempl = Maybe<float>;
    const CastableTypes type = ExtractType(data);
    data.erase(0, TYPE_SIZE_IN_CHARACTERS);
    return type == CastableTypes::FLOAT ? MaybeTempl(static_cast<float>(std::atof(data.c_str()))) : MaybeTempl();
}

template <>
Maybe<int32_t> Events::StringToTypeCast<int32_t>(std::string&& data)
{
    using MaybeTempl = Maybe<int32_t>;
    const CastableTypes type = ExtractType(data);
    data.erase(0, TYPE_SIZE_IN_CHARACTERS);
    return type == CastableTypes::INT ? MaybeTempl(std::strtol(data.c_str(), nullptr, 10)) : MaybeTempl();
}

template <>
Maybe<API::Types::ObjectID> Events::StringToTypeCast<API::Types::ObjectID>(std::string&& data)
{
    using MaybeTempl = Maybe<API::Types::ObjectID>;
    const CastableTypes type = ExtractType(data);
    data.erase(0, TYPE_SIZE_IN_CHARACTERS);
    return type == CastableTypes::OBJECT ? MaybeTempl({ std::strtoul(data.c_str(), nullptr, 16) }) : MaybeTempl();
}

template <>
Maybe<std::string> Events::StringToTypeCast<std::string>(std::string&& data)
{
    using MaybeTempl = Maybe<std::string>;
    const CastableTypes type = ExtractType(data);
    data.erase(0, TYPE_SIZE_IN_CHARACTERS);
    return type == CastableTypes::STRING ? MaybeTempl(std::forward<std::string>(data)) : MaybeTempl();
}

template <>
std::string Events::TypeToStringCast<float>(float&& arg)
{
    std::stringstream ss;
    ss << +(static_cast<uint8_t>(CastableTypes::FLOAT)) << " " << std::forward<float>(arg);
    return ss.str();
}

template <>
std::string Events::TypeToStringCast<int32_t>(int32_t&& arg)
{
    std::stringstream ss;
    ss << +(static_cast<uint8_t>(CastableTypes::INT)) << " " << std::forward<int32_t>(arg);
    return ss.str();
}

template <>
std::string Events::TypeToStringCast<API::Types::ObjectID>(API::Types::ObjectID&& arg)
{
    std::stringstream ss;
    ss << +(static_cast<uint8_t>(CastableTypes::OBJECT)) << " " << std::hex << std::forward<API::Types::ObjectID>(arg);
    return ss.str();
}

template <>
std::string Events::TypeToStringCast<std::string>(std::string&& arg)
{
    std::stringstream ss;
    ss << +(static_cast<uint8_t>(CastableTypes::STRING)) << " " << std::forward<std::string>(arg);
    return ss.str();
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

}

}
