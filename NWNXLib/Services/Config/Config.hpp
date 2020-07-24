#pragma once

#include "Services/Services.hpp"
#include <algorithm>
#include <string>
#include <optional>

namespace NWNXLib::Services {

class Config
{
public:
    Config();

    // Retrieves a configuration value. Note that key is case-insensitive, but
    // configuration is expected to be defined all-upcase in ENV.
    static std::optional<std::string> Get(const std::string& section, const std::string& key,
        bool trim = false);

    static std::optional<std::string> Set(const std::string& section, const std::string& key,
        const std::string& value);
};

class ConfigProxy : public ServiceProxy<Config>
{
public:
    ConfigProxy(Config& config, std::string moduleName) :
        ServiceProxy<Config>(config), m_moduleName(std::move(moduleName)) {}
    ~ConfigProxy() {}

    // Gets a config value.
    template<typename T>
    std::optional<T> Get(const std::string& key) const;

    template<typename T>
    T Get(const std::string& key, T&& def) const;

    // Same as Get, except this will throw a runtime_error when the value is missing or malformed.
    template<typename T>
    T Require(const std::string& key) const;

    // Sets a new config value and returns the old one.
    template<typename T>
    std::optional<T> Set(const std::string& key, const T& value);

private:
    std::string m_moduleName;
};

template <typename T>
std::optional<T> ConfigProxy::Get(const std::string& key) const
{
    if constexpr (std::is_same_v<T, std::string>) {
        return m_proxyBase.Get(m_moduleName, key);
    }
    else
    {
        auto opt = m_proxyBase.Get(m_moduleName, key);
        return opt ? Utils::from_string<T>(*opt) : std::optional<T>();
    }
}

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

}
