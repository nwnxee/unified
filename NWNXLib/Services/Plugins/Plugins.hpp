#pragma once

#include "Maybe.hpp"
#include "Platform/DynamicLibraries.hpp"
#include "Plugin.hpp"
#include "Services/Services.hpp"
#include "ViewPtr.hpp"

#include <cstdint>
#include <map>
#include <utility>
#include <vector>

namespace NWNXLib {

namespace Services {

class Plugins : public ServiceBase
{
public: // Structures
    using PluginID = uint8_t;

    struct PluginData
    {
        PluginID m_id;
        std::string m_path;
        ViewPtr<Plugin::Info> m_info;
        ViewPtr<Plugin> m_plugin;
    };

    struct RegistrationToken
    {
        PluginID m_id;
    };

private: // Structures
    struct PluginDataInternal
    {
    public: // Structures
        using PluginInfoFuncPtr = Plugin::Info*(*)();
        using PluginLoadFuncPtr = Plugin*(*)(Plugin::CreateParams);
        using PluginUnloadFuncPtr = void(*)(const Plugin::UnloadReason);

    public:
        PluginID m_id;
        std::string m_path;
        std::unique_ptr<Plugin::Info> m_info;
        std::unique_ptr<Plugin> m_plugin;
        Platform::DynamicLibraries::HandleType m_handle;
        PluginInfoFuncPtr m_pluginInfoFunc;
        PluginLoadFuncPtr m_pluginLoadFunc;
        PluginUnloadFuncPtr m_pluginUnloadFunc;
    };

    using PluginMap = std::map<PluginID, PluginDataInternal>;

public:
    Plugins();
    ~Plugins();

    RegistrationToken LoadPlugin(const std::string& path, Plugin::CreateParams&& params);
    void UnloadPlugin(RegistrationToken&& token, const Plugin::UnloadReason reason);

    Maybe<PluginData> FindPluginById(const PluginID id) const;
    Maybe<PluginData> FindPluginByName(const std::string& name) const;
    Maybe<PluginData> FindPluginByPath(const std::string& path) const;
    std::vector<PluginData> GetPlugins() const;

private:
    PluginMap m_plugins;
    void UnloadPluginInternal(PluginMap::iterator plugin, const Plugin::UnloadReason reason);
    PluginID GetNextAvailableId();
};

class PluginsProxy : public ServiceProxy<Plugins>
{
public:
    PluginsProxy(Plugins& plugins);
    ~PluginsProxy();

    Maybe<Plugins::PluginData> FindPluginById(const Plugins::PluginID id) const;
    Maybe<Plugins::PluginData> FindPluginByName(const std::string& name) const;
    Maybe<Plugins::PluginData> FindPluginByPath(const std::string& path) const;
    std::vector<Plugins::PluginData> GetPlugins() const;
};

}

}
