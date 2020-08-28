#pragma once

#include "Plugin.hpp"
#include "Services/Services.hpp"

#include <cstdint>
#include <map>
#include <utility>
#include <vector>
#include <optional>

namespace NWNXLib::Services {

class Plugins
{
public: // Structures
    using PluginID = uint8_t;

    struct PluginData
    {
        PluginID m_id;
        std::string m_path;
        Plugin* m_plugin;
    };

    struct RegistrationToken
    {
        PluginID m_id;
    };

private: // Structures
    struct PluginDataInternal
    {
    public: // Structures
        using PluginLoadFuncPtr = Plugin*(*)(ProxyServiceList*);

    public:
        PluginID m_id;
        std::string m_path;
        std::unique_ptr<Plugin> m_plugin;
        void* m_handle;
        PluginLoadFuncPtr m_pluginLoadFunc;
    };

    using PluginMap = std::map<PluginID, PluginDataInternal>;

public:
    Plugins();
    ~Plugins();

    RegistrationToken LoadPlugin(const std::string& path, ProxyServiceList* services);
    void UnloadPlugin(RegistrationToken&& token);

    std::optional<PluginData> FindPluginById(const PluginID id) const;
    std::optional<PluginData> FindPluginByName(const std::string& name) const;
    std::optional<PluginData> FindPluginByPath(const std::string& path) const;
    std::vector<PluginData> GetPlugins() const;
    std::string GetCanonicalPluginName(const std::string& name) const;

private:
    PluginMap m_plugins;
    void UnloadPluginInternal(PluginMap::iterator plugin);
    PluginID GetNextAvailableId();
};

class PluginsProxy : public ServiceProxy<Plugins>
{
public:
    PluginsProxy(Plugins& plugins);
    ~PluginsProxy();

    std::optional<Plugins::PluginData> FindPluginById(const Plugins::PluginID id) const;
    std::optional<Plugins::PluginData> FindPluginByName(const std::string& name) const;
    std::optional<Plugins::PluginData> FindPluginByPath(const std::string& path) const;
    std::vector<Plugins::PluginData> GetPlugins() const;
    std::string GetCanonicalPluginName(const std::string& name) const;
};

}
