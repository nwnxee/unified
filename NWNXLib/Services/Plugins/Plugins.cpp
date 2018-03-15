#include "Services/Plugins/Plugins.hpp"

namespace NWNXLib {

namespace Services {

Plugins::Plugins()
{
}

Plugins::~Plugins()
{
    while (!m_plugins.empty())
    {
        UnloadPluginInternal(std::begin(m_plugins), Plugin::UnloadReason::SHUTTING_DOWN);
    }
}

Plugins::RegistrationToken Plugins::LoadPlugin(const std::string& path, Plugin::CreateParams&& params)
{
    Maybe<PluginData> existingPlugin = FindPluginByPath(path);

    if (existingPlugin)
    {
        throw std::runtime_error("Plugin is already loaded.");
    }

    using namespace Platform::DynamicLibraries;
    HandleType handle = OpenDll(path);

    if (!IsHandleValid(handle))
    {
        throw std::runtime_error("Plugin failed to load: " + GetErrorFromHandle(handle));
    }

    const uintptr_t pluginInfoFuncAddr = GetFuncAddrInDll("PluginInfo", handle);
    const uintptr_t pluginLoadFuncAddr = GetFuncAddrInDll("PluginLoad", handle);
    const uintptr_t pluginUnloadFuncAddr = GetFuncAddrInDll("PluginUnload", handle);

    // Don't check pluginUnloadFuncAddr -- it's optional.
    const bool mandatoryPluginsPresent = IsFuncAddrFromDllValid(pluginInfoFuncAddr) && IsFuncAddrFromDllValid(pluginLoadFuncAddr);

    if (!mandatoryPluginsPresent)
    {
        throw std::runtime_error("Plugin does not export the required functions.");
    }

    const PluginDataInternal::PluginInfoFuncPtr pluginInfoFuncPtr =
        reinterpret_cast<PluginDataInternal::PluginInfoFuncPtr>(pluginInfoFuncAddr);

    const PluginDataInternal::PluginLoadFuncPtr pluginLoadFuncPtr =
        reinterpret_cast<PluginDataInternal::PluginLoadFuncPtr>(pluginLoadFuncAddr);

    const PluginDataInternal::PluginUnloadFuncPtr pluginUnloadFuncPtr =
        reinterpret_cast<PluginDataInternal::PluginUnloadFuncPtr>(pluginUnloadFuncAddr);

    // We capture a unique_ptr right away to avoid leak if the exception occurs.
    auto info = std::unique_ptr<Plugin::Info>(pluginInfoFuncPtr());

    if (info->m_targetVersion != NWNX_TARGET_NWN_BUILD)
    {
        throw std::runtime_error("Plugin version mismatch -- has the server updated?");
    }

    PluginID pluginId = GetNextAvailableId();

    PluginDataInternal data =
    {
        pluginId,
        path,
        std::move(info),
        nullptr,
        handle,
        pluginInfoFuncPtr,
        pluginLoadFuncPtr,
        pluginUnloadFuncPtr
    };

    // We insert before creating because plugins may expect to be able to query themselves in the plugin manager.
    auto iter = m_plugins.insert(std::make_pair<PluginID, PluginDataInternal>(std::move(pluginId), std::move(data)));

    try
    {
        iter.first->second.m_plugin = std::unique_ptr<Plugin>(pluginLoadFuncPtr(std::forward<Plugin::CreateParams>(params)));
    }
    catch (const std::runtime_error&)
    {
        try
        {
            UnloadPluginInternal(iter.first, Plugin::UnloadReason::CREATION_FAILED);
        }
        catch (const std::runtime_error&)
        {
            // Do nothing -- we don't really care.
        }

        throw;
    }

    return { pluginId };
}

void Plugins::UnloadPlugin(RegistrationToken&& token, const Plugin::UnloadReason reason)
{
    auto plugin = m_plugins.find(token.m_id);

    if (plugin == std::end(m_plugins))
    {
        throw std::runtime_error("Invalid or duplicated plugin registration token.");
    }

    UnloadPluginInternal(plugin, reason);
}

Maybe<Plugins::PluginData> Plugins::FindPluginById(const Plugins::PluginID id) const
{
    auto plugin = m_plugins.find(id);

    if (plugin != m_plugins.end())
    {
        const PluginDataInternal& data = plugin->second;
        return Maybe<Plugins::PluginData>({ data.m_id, data.m_path, data.m_info, data.m_plugin });
    }

    return Maybe<Plugins::PluginData>();
}

Maybe<Plugins::PluginData> Plugins::FindPluginByName(const std::string& name) const
{
    for (auto& plugin : m_plugins)
    {
        const std::string& pluginName = plugin.second.m_info->m_name;

        if (pluginName == name)
        {
            const PluginDataInternal& data = plugin.second;
            return Maybe<Plugins::PluginData>({ data.m_id, data.m_path, data.m_info, data.m_plugin });
        }
    }

    return Maybe<Plugins::PluginData>();
}

Maybe<Plugins::PluginData> Plugins::FindPluginByPath(const std::string& path) const
{
    for (auto& plugin : m_plugins)
    {
        const PluginDataInternal& data = plugin.second;

        if (data.m_path == path)
        {
            return Maybe<Plugins::PluginData>({ data.m_id, data.m_path, data.m_info, data.m_plugin });
        }
    }

    return Maybe<Plugins::PluginData>();
}

std::vector<Plugins::PluginData> Plugins::GetPlugins() const
{
    std::vector<PluginData> plugins;
    plugins.reserve(m_plugins.size());

    for (auto& plugin : m_plugins)
    {
        const PluginDataInternal& data = plugin.second;
        plugins.push_back({ data.m_id, data.m_path, data.m_info, data.m_plugin });
    }

    return plugins;
}

void Plugins::UnloadPluginInternal(PluginMap::iterator plugin, const Plugin::UnloadReason reason)
{
    ASSERT(plugin != m_plugins.end());
    PluginDataInternal::PluginUnloadFuncPtr unloadFunc = plugin->second.m_pluginUnloadFunc;

    if (unloadFunc)
    {
        try
        {
            unloadFunc(reason);
        }
        catch (const std::runtime_error& err)
        {
            LOG_ERROR("Encountered error when unloading plugin: '%s'", err.what());
        }
    }

    Platform::DynamicLibraries::CloseDll(plugin->second.m_handle);
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

Maybe<Plugins::PluginData> PluginsProxy::FindPluginById(const Plugins::PluginID id) const
{
    return m_proxyBase.FindPluginById(id);
}

Maybe<Plugins::PluginData> PluginsProxy::FindPluginByName(const std::string& name) const
{
    return m_proxyBase.FindPluginByName(name);
}

Maybe<Plugins::PluginData> PluginsProxy::FindPluginByPath(const std::string& path) const
{
    return m_proxyBase.FindPluginByName(path);
}

std::vector<Plugins::PluginData> PluginsProxy::GetPlugins() const
{
    return m_proxyBase.GetPlugins();
}

}

}
