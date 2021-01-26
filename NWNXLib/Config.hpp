#pragma once

#include "Utils/String.hpp"
#include <algorithm>
#include <string>
#include <optional>

namespace NWNXLib {

class Config
{
public:
    // Retrieves a configuration value. Note that key is case-insensitive, but
    // configuration is expected to be defined all-upcase in ENV.
    static std::optional<std::string> GetRaw(const std::string& key, const std::string& section)
    {
        std::string mykey = section + "_" + key;
        std::transform(mykey.begin(), mykey.end(), mykey.begin(), ::toupper);

        const char* ev = std::getenv(mykey.c_str());
        std::string v = ev ? ev : "";
        Utils::trim(v);

        return v.empty() ? std::optional<std::string>() : std::make_optional<std::string>(std::move(v));
    }

    // Gets a config value.
    template<typename T>
    static std::optional<T> Get(const std::string& key, const std::string& module = PLUGIN_NAME)
    {
        if constexpr (std::is_same_v<T, std::string>) {
            return GetRaw(key, module);
        }
        else
        {
            auto opt = GetRaw(key, module);
            return opt ? Utils::from_string<T>(*opt) : std::optional<T>();
        }
    }

    template<typename T>
    static T Get(const std::string& key, T&& def, const std::string& module = PLUGIN_NAME)
    {
        return Get<T>(key, module).value_or(std::forward<T>(def));
    }
};

}
