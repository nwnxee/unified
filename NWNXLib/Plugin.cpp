#include "nwnx.hpp"

namespace NWNXLib
{

constexpr char PluginEntryName[] = "PluginLoad";

void* Plugin::GetExportedSymbol(const std::string& symbolName)
{
    if (symbolName[0] == '_')
        return nullptr;
    return Platform::GetSymbol(m_handle, symbolName.c_str());
}

Plugin::Plugin(Services::ProxyServiceList* services) :
    m_services(services) { }


Plugin* Plugin::Find(const std::string& pluginName)
{
    for (auto* plugin : s_plugins)
    {
        if (!String::CompareIgnoreCase(pluginName.c_str(), plugin->m_name.c_str()))
            return plugin;
    }
    return nullptr;
}

Plugin* Plugin::Load(const std::string& path, std::unique_ptr<Services::ProxyServiceList>&& services)
{
    auto basename = String::Basename(path);

    LOG_DEBUG("Loading plugin '%s'", basename);
    if (Find(basename))
    {
        LOG_ERROR("Plugin '%s' already loaded.", basename);
        return nullptr;
    }

    void* handle = Platform::OpenLibrary(path.c_str(), Platform::RTLD_NOW | Platform::RTLD_NODELETE);
    if (!handle)
    {
        LOG_ERROR("Unable to load plugin '%s': %s", path, Platform::GetError());
        return nullptr;
    }

    Plugin* plugin;
    if (auto entry = (EntryFunction) Platform::GetSymbol(handle, PluginEntryName))
    {
        LOG_DEBUG("Plugin '%s' exposed entry function %s()", path, PluginEntryName);
        plugin = entry(services.get());
        if (plugin == nullptr)
        {
            LOG_ERROR("Plugin '%s' entry function returned nullptr", path);
            Platform::CloseLibrary(handle);
            return nullptr;
        }
    }
    else
    {
        plugin = new Plugin(services.get());
    }

    plugin->m_servicesOwning = std::move(services);
    plugin->m_name = basename;
    plugin->m_path = path;
    plugin->m_handle = handle;
    s_plugins.push_back(plugin);

    LOG_INFO("Loaded plugin %s", path);
    return plugin;
}

void Plugin::UnloadAll()
{
    while (!s_plugins.empty())
    {
        auto* plugin = s_plugins.back();
        s_plugins.pop_back();
        LOG_INFO("Unloading plugin %s", plugin->m_name);

        auto handle = plugin->m_handle;
        delete plugin;
        Platform::CloseLibrary(handle);
    }
}

}
