template<> Maybe<std::string> ConfigProxy::Get<std::string>(const std::string&) const;
template<> Maybe<bool> ConfigProxy::Get<bool>(const std::string&) const;
template<> Maybe<int64_t> ConfigProxy::Get<int64_t>(const std::string&) const;
template<> Maybe<int32_t> ConfigProxy::Get<int32_t>(const std::string&) const;
template<> Maybe<uint64_t> ConfigProxy::Get<uint64_t>(const std::string&) const;
template<> Maybe<uint32_t> ConfigProxy::Get<uint32_t>(const std::string&) const;
template<> Maybe<float> ConfigProxy::Get<float>(const std::string&) const;
template<> Maybe<double> ConfigProxy::Get<double>(const std::string&) const;
template<> Maybe<double> ConfigProxy::Get<double>(const std::string&) const;


template<typename T>
T ConfigProxy::Get(const std::string& key, T&& def) const
{
    return Get<T>(key).Extract(std::forward<T>(def));
}

template <typename T>
T ConfigProxy::Require(const std::string& key) const
{
    Maybe<T> r = Get<T>(key);

    if (!r)
    {
        std::string resolvedKey = m_moduleName + "_" + key;
        std::transform(std::begin(resolvedKey), std::end(resolvedKey), std::begin(resolvedKey), ::toupper);
        throw std::runtime_error("Required config key missing or invalid: " + resolvedKey);
    }

    return r.Extract();
}
