#include "Services/Plugins/Plugins.hpp"
#include "Utils/String.hpp"

#include <dlfcn.h>

namespace NWNXLib::Services {

Plugins::Plugins()
{
}

Plugins::~Plugins()
{
    while (!m_plugins.empty())
    {
        UnloadPluginInternal(std::begin(m_plugins));
    }
}

Plugins::RegistrationToken Plugins::LoadPlugin(const std::string& path, ProxyServiceList* services)
{
    auto existingPlugin = FindPluginByPath(path);

    if (existingPlugin)
    {
        throw std::runtime_error("Plugin is already loaded.");
    }

    void* handle = dlopen(path.c_str(), RTLD_NOW | RTLD_NODELETE);

    if (!handle)
    {
        throw std::runtime_error(std::string{"Plugin failed to load: "} + dlerror());
    }

    const uintptr_t pluginLoadFuncAddr = (uintptr_t)dlsym(handle, "PluginLoad");
    if (pluginLoadFuncAddr == 0)
    {
        throw std::runtime_error("Plugin does not export PluginLoad()");
    }

    const PluginDataInternal::PluginLoadFuncPtr pluginLoadFuncPtr =
        reinterpret_cast<PluginDataInternal::PluginLoadFuncPtr>(pluginLoadFuncAddr);

    PluginID pluginId = GetNextAvailableId();
    PluginDataInternal data =
    {
        pluginId,
        path,
        nullptr,
        handle,
        pluginLoadFuncPtr
    };

    // We insert before creating because plugins may expect to be able to query themselves in the plugin manager.
    auto iter = m_plugins.insert(std::make_pair<PluginID, PluginDataInternal>(std::move(pluginId), std::move(data)));

    try
    {
        iter.first->second.m_plugin = std::unique_ptr<Plugin>(pluginLoadFuncPtr(services));
    }
    catch (const std::runtime_error&)
    {
        try
        {
            UnloadPluginInternal(iter.first);
        }
        catch (const std::runtime_error&)
        {
            // Do nothing -- we don't really care.
        }

        throw;
    }

    return { pluginId };
}

void Plugins::UnloadPlugin(RegistrationToken&& token)
{
    auto plugin = m_plugins.find(token.m_id);

    if (plugin == std::end(m_plugins))
    {
        throw std::runtime_error("Invalid or duplicated plugin registration token.");
    }

    UnloadPluginInternal(plugin);
}

std::optional<Plugins::PluginData> Plugins::FindPluginById(const Plugins::PluginID id) const
{
    auto plugin = m_plugins.find(id);

    if (plugin != m_plugins.end())
    {
        const PluginDataInternal& data = plugin->second;
        return std::make_optional<Plugins::PluginData>({ data.m_id, data.m_path, data.m_plugin.get() });
    }

    return std::optional<Plugins::PluginData>();
}

std::optional<Plugins::PluginData> Plugins::FindPluginByName(const std::string& name) const
{
    for (auto& plugin : m_plugins)
    {
        if (name == Utils::basename(plugin.second.m_path))
        {
            const PluginDataInternal& data = plugin.second;
            return std::make_optional<Plugins::PluginData>({ data.m_id, data.m_path, data.m_plugin.get() });
        }
    }

    return std::optional<Plugins::PluginData>();
}

std::optional<Plugins::PluginData> Plugins::FindPluginByPath(const std::string& path) const
{
    for (auto& plugin : m_plugins)
    {
        const PluginDataInternal& data = plugin.second;

        if (data.m_path == path)
        {
            return std::make_optional<Plugins::PluginData>({ data.m_id, data.m_path, data.m_plugin.get() });
        }
    }

    return std::optional<Plugins::PluginData>();
}

std::vector<Plugins::PluginData> Plugins::GetPlugins() const
{
    std::vector<PluginData> plugins;
    plugins.reserve(m_plugins.size());

    for (auto& plugin : m_plugins)
    {
        const PluginDataInternal& data = plugin.second;
        plugins.push_back({ data.m_id, data.m_path, data.m_plugin.get() });
    }

    return plugins;
}

std::string Plugins::GetCanonicalPluginName(const std::string& name) const
{
    for (auto pluginData : GetPlugins())
    {
        std::string str = Utils::basename(pluginData.m_path);
        if (!strcasecmp(name.c_str(), str.c_str()))
            return str;
    }
    return "";
}

void Plugins::UnloadPluginInternal(PluginMap::iterator plugin)
{
    ASSERT(plugin != m_plugins.end());
    dlclose(plugin->second.m_handle);
    m_plugins.erase(plugin);
}

Plugins::PluginID Plugins::GetNextAvailableId()
{
    PluginID newId = 0;
    auto highestId = m_plugins.rbegin();

    if (highestId != m_plugins.rend())
    {
        newId = highestId->first + 1;
    }

    return newId;
}

PluginsProxy::PluginsProxy(Plugins& plugins)
    : ServiceProxy<Plugins>(plugins)
{
}

PluginsProxy::~PluginsProxy()
{
}

std::optional<Plugins::PluginData> PluginsProxy::FindPluginById(const Plugins::PluginID id) const
{
    return m_proxyBase.FindPluginById(id);
}

std::optional<Plugins::PluginData> PluginsProxy::FindPluginByName(const std::string& name) const
{
    return m_proxyBase.FindPluginByName(name);
}

std::optional<Plugins::PluginData> PluginsProxy::FindPluginByPath(const std::string& path) const
{
    return m_proxyBase.FindPluginByPath(path);
}

std::vector<Plugins::PluginData> PluginsProxy::GetPlugins() const
{
    return m_proxyBase.GetPlugins();
}

std::string PluginsProxy::GetCanonicalPluginName(const std::string& name) const
{
    return m_proxyBase.GetCanonicalPluginName(name);
}

}
