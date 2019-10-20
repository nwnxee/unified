
template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, const T& value)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        event->m_arguments.push(Events::Argument(value));
        LOG_DEBUG("Pushing argument '%s'. Event '%s', Plugin: '%s'.",
            event->m_arguments.top(), eventName, pluginName);
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
}

template <typename T>
Maybe<T> Events::Pop(const std::string& pluginName, const std::string& eventName)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        if (event->m_returns.empty())
        {
            LOG_ERROR("Plugin '%s', event '%s': Tried to get a return value when one did not exist.",
                pluginName, eventName);
            return Maybe<T>();
        }

        Maybe<T>& data = event->m_returns.top().Get<T>();
        if (!data)
        {
            LOG_ERROR("Plugin '%s', event '%s': Type mismatch in return values",
                pluginName, eventName);
        }
        else
        {
            LOG_DEBUG("Returning value '%s'. Event '%s', Plugin: '%s'.",
                event->m_returns.top(), eventName, pluginName);

            // I'm probably using all these moves wrong..
            T real = std::move(*data);
            event->m_returns.pop();
            return Maybe<T>(std::move(real));
        }
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
    return Maybe<T>();
}



template<> Maybe<int32_t>&              Events::Argument::Get<int32_t>();
template<> Maybe<float>&                Events::Argument::Get<float>();
template<> Maybe<API::Types::ObjectID>& Events::Argument::Get<API::Types::ObjectID>();
template<> Maybe<std::string>&          Events::Argument::Get<std::string>();
template<> Maybe<CGameEffect*>&    Events::Argument::Get<CGameEffect*>();

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

    if (!data)
    {
        throw std::runtime_error("Failed to match pushed argument to the provided type.");
    }

    T real = std::move(data.Extract());
    arguments.pop();

    return real;
}
