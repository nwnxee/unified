
template <typename T>
void Push(const std::string& pluginName, const std::string& eventName, const T& value);

template <typename T>
Maybe<T> Pop(const std::string& pluginName, const std::string& eventName);



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
