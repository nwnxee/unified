template<> std::optional<std::string> ConfigProxy::Get<std::string>(const std::string&) const;
template<> std::optional<bool> ConfigProxy::Get<bool>(const std::string&) const;
template<> std::optional<int64_t> ConfigProxy::Get<int64_t>(const std::string&) const;
template<> std::optional<int32_t> ConfigProxy::Get<int32_t>(const std::string&) const;
template<> std::optional<uint64_t> ConfigProxy::Get<uint64_t>(const std::string&) const;
template<> std::optional<uint32_t> ConfigProxy::Get<uint32_t>(const std::string&) const;
template<> std::optional<float> ConfigProxy::Get<float>(const std::string&) const;
template<> std::optional<double> ConfigProxy::Get<double>(const std::string&) const;

template<typename T>
T ConfigProxy::Get(const std::string& key, T&& def) const
{
    return Get<T>(key).value_or(std::forward<T>(def));
}

template <typename T>
T ConfigProxy::Require(const std::string& key) const
{
    std::optional<T> r = Get<T>(key);

    if (!r)
    {
        std::string resolvedKey = m_moduleName + "_" + key;
        std::transform(std::begin(resolvedKey), std::end(resolvedKey), std::begin(resolvedKey), ::toupper);
        throw std::runtime_error("Required config key missing or invalid: " + resolvedKey);
    }

    return r.value();
}
