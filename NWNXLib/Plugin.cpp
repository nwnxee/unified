#include "nwnx.hpp"
#include <dlfcn.h>

namespace NWNXLib
{

constexpr char PluginEntryName[] = "PluginLoad";

void* Plugin::GetExportedSymbol(const std::string& symbolName)
{
    if (symbolName[0] == '_')
        return nullptr;
    return dlsym(m_handle, symbolName.c_str());
}

Plugin::Plugin(Services::ProxyServiceList* services) :
    m_services(services) { }


Plugin* Plugin::Find(const std::string& pluginName)
{
    for (auto* plugin : s_plugins)
    {
        if (!strcasecmp(pluginName.c_str(), plugin->m_name.c_str()))
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

    void* handle = dlopen(path.c_str(), RTLD_NOW | RTLD_NODELETE);
    if (!handle)
    {
        LOG_ERROR("Unable to load plugin '%s': %s", path, dlerror());
        return nullptr;
    }

    Plugin* plugin;
    if (auto entry = (EntryFunction) dlsym(handle, PluginEntryName))
    {
        LOG_DEBUG("Plugin '%s' exposed entry function %s()", path, PluginEntryName);
        plugin = entry(services.get());
        if (plugin == nullptr)
        {
            LOG_ERROR("Plugin '%s' entry function returned nullptr", path);
            dlclose(handle);
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
        dlclose(handle);
    }
}

}
