
template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, T&& value)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        event->m_arguments.push(Events::Argument(std::forward<T>(value)));
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

        std::optional<T>& data = event->m_returns.top().Get<T>();
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
            return std::make_optional<T>(std::move(real));
        }
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
    return std::optional<T>();
}



template<> std::optional<int32_t>&              Events::Argument::Get<int32_t>();
template<> std::optional<float>&                Events::Argument::Get<float>();
template<> std::optional<API::Types::ObjectID>& Events::Argument::Get<API::Types::ObjectID>();
template<> std::optional<std::string>&          Events::Argument::Get<std::string>();
template<> std::optional<CGameEffect*>&    Events::Argument::Get<CGameEffect*>();

template <typename T>
void Events::InsertArgument(ArgumentStack& stack, T&& arg)
{
    stack.emplace(std::forward<T>(arg));
}

template <typename... Args>
void Events::InsertArguments(ArgumentStack& stack, Args&&... args)
{
    (InsertArgument(stack, std::forward<Args>(args)), ...);
}

template <typename... Args>
Events::ArgumentStack Events::Arguments(Args&&... args)
{
    ArgumentStack stack;
    (InsertArgument(stack, std::forward<Args>(args)), ...);
    return std::move(stack);
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    if (arguments.empty())
    {
        throw std::runtime_error("Tried to extract an argument from an empty argument stack.");
    }

    std::optional<T>& data = arguments.top().Get<T>();

    if (!data)
    {
        throw std::runtime_error("Failed to match pushed argument to the provided type.");
    }

    T real = std::move(data.value());
    arguments.pop();

    return real;
}
