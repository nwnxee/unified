template<> Maybe<float> Events::StringToTypeCast<float>(std::string&&);
template<> Maybe<int32_t> Events::StringToTypeCast<int32_t>(std::string&&);
template<> Maybe<API::Types::ObjectID> Events::StringToTypeCast<API::Types::ObjectID>(std::string&&);
template<> Maybe<std::string> Events::StringToTypeCast<std::string>(std::string&&);

template<> std::string Events::TypeToStringCast(float&& data);
template<> std::string Events::TypeToStringCast(int32_t&& data);
template<> std::string Events::TypeToStringCast(API::Types::ObjectID&& data);
template<> std::string Events::TypeToStringCast(std::string&& data);

template <typename T>
Maybe<std::tuple<T>> Events::MakeTupleFromArgs(Events::ArgumentStack& arguments)
{
    using MaybeTempl = Maybe<std::tuple<T>>;
    auto data = StringToTypeCast<T>(std::move(arguments.top()));
    arguments.pop();
    return data ? MaybeTempl(std::make_tuple(data.Extract())) : MaybeTempl();
}

template <typename T1, typename T2, typename ... Ts>
Maybe<std::tuple<T1, T2, Ts ...>> Events::MakeTupleFromArgs(Events::ArgumentStack& arguments)
{
    using MaybeTempl = Maybe<std::tuple<T1, T2, Ts ...>>;
    auto first = MakeTupleFromArgs<T1>(arguments);
    auto others = MakeTupleFromArgs<T2, Ts ...>(arguments);
    return first && others ? MaybeTempl(std::tuple_cat(first.Extract(), others.Extract())) : MaybeTempl();
}

template <typename T>
void Events::InsertArgument(ArgumentStack& stack, T arg)
{
    stack.push(TypeToStringCast<T>(std::move(arg)));
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    if (arguments.empty())
    {
        throw std::runtime_error("Tried to extract an argument from an empty argument stack.");
    }

    Maybe<T> data = StringToTypeCast<T>(std::move(arguments.top()));
    arguments.pop();

    if (!data)
    {
        throw std::runtime_error("Failed to match pushed argument to the provided type.");
    }

    return data.Extract();
}

template <typename ... Params>
std::tuple<Params ...> Events::ExtractArguments(Events::ArgumentStack&& arguments)
{
    constexpr size_t paramCount = sizeof...(Params);

    if (arguments.size() != paramCount)
    {
        throw std::runtime_error("Mismatch between requested argument count and actual argument count.");
    }

    auto data = MakeTupleFromArgs<Params ...>(arguments);
    ASSERT(arguments.empty()); // Logically, arguments should now be empty.

    if (!data)
    {
        throw std::runtime_error("Failed to match pushed arguments to the provided type.");
    }

    return data.Extract();
}
