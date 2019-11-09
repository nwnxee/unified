#pragma once

#include "Services/Services.hpp"
#include <algorithm>
#include <string>
#include <optional>

namespace NWNXLib {

namespace Services {

class Config : public ServiceBase
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

#include "Services/Config/Config.inl"

}

}
