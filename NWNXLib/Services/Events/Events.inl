
template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, const T& value)
{
    auto events = m_eventMap[pluginName];
    for (auto event: events)
    {
        if (event->m_data.m_eventName == eventName)
        {
            event->m_returns.push(Events::Argument(value));
            LOG_DEBUG("Pushing argument '%s'. Event '%s', Plugin: '%s'.",
                event->m_arguments.top().toString(), eventName.c_str(), pluginName.c_str());
            return;
        }
    }

    LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName.c_str(), eventName.c_str());
}

template <typename T>
Maybe<T> Events::Pop(const std::string& pluginName, const std::string& eventName)
{
    auto events = m_eventMap[pluginName];
    for (auto event: events)
    {
        if (event->m_data.m_eventName == eventName)
        {
            if (event->m_returns.empty())
            {
                LOG_ERROR("Plugin '%s', event '%s': Tried to get a return value when one did not exist.",
                    pluginName.c_str(), eventName.c_str());
                return Maybe<T>();
            }

            Maybe<T>& data = event->m_returns.top().Get<T>();
            if (!data)
            {
                LOG_ERROR("Plugin '%s', event '%s': Type mismatch in return values",
                    pluginName.c_str(), eventName.c_str());
            }
            else
            {
                LOG_DEBUG("Returning value '%s'. Event '%s', Plugin: '%s'.",
                    data->toString(), eventName.c_str(), pluginName.c_str());
            }
            return data;
        }
    }

    LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName.c_str(), eventName.c_str());
    return Maybe<T>();
}



template<> Maybe<int32_t>&              Events::Argument::Get<int32_t>();
template<> Maybe<float>&                Events::Argument::Get<float>();
template<> Maybe<API::Types::ObjectID>& Events::Argument::Get<API::Types::ObjectID>();
template<> Maybe<std::string>&          Events::Argument::Get<std::string>();
template<> Maybe<API::CGameEffect>&     Events::Argument::Get<API::CGameEffect>();

template <typename T>
void Events::InsertArgument(ArgumentStack& stack, T arg)
{
    stack.push(Events::Argument(arg));
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    if (arguments.empty())
    {
        throw std::runtime_error("Tried to extract an argument from an empty argument stack.");
    }

    Maybe<T>& data = arguments.top().Get<T>();
    arguments.pop();

    if (!data)
    {
        throw std::runtime_error("Failed to match pushed argument to the provided type.");
    }

    return data.Extract();
}
