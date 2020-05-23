
template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, T&& value)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        event->m_arguments.insert(std::forward<T>(value));
        LOG_DEBUG("Pushing argument '%s'. Event '%s', Plugin: '%s'.",
            event->m_arguments.top(), eventName, pluginName);
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
}

template <typename T>
std::optional<T> Events::Pop(const std::string& pluginName, const std::string& eventName)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        if (event->m_returns.empty())
        {
            LOG_ERROR("Plugin '%s', event '%s': Tried to get a return value when one did not exist.",
                pluginName, eventName);
            return std::optional<T>();
        }

        if (!event->m_returns.top().Holds<T>())
        {
            LOG_ERROR("Plugin '%s', event '%s': Type mismatch in return values",
                pluginName, eventName);
        }
        else
        {
            LOG_DEBUG("Returning value '%s'. Event '%s', Plugin: '%s'.",
                event->m_returns.top(), eventName, pluginName);
            return std::make_optional<T>(event->m_returns.extract<T>());
        }
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
    return std::optional<T>();
}

template <typename T>
void Events::InsertArgument(ArgumentStack& stack, T&& arg)
{
    stack.insert(std::forward<T>(arg));
}

template <typename... Args>
void Events::InsertArguments(ArgumentStack& stack, Args&&... args)
{
    stack.insert(std::forward<Args>(args)...);
}

template <typename... Args>
Events::ArgumentStack Events::Arguments(Args&&... args)
{
    return { std::forward<Args>(args)... };
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    return arguments.extract<T>();
}
