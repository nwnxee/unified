#pragma once

#include "Services/Services.hpp"

namespace NWNXLib {

#define NWNX_PLUGIN_ENTRY extern "C"
#define NWNX_EXPORT       extern "C"

constexpr char PluginEntryName[] = "PluginLoad";

// All plugins should extend this class if they want to use the API!
// This class performs neccessary initialisation of shared API state.
class Plugin
{
public:
    using EntryFunction = Plugin*(*)(Services::ProxyServiceList*);

    Plugin(Services::ProxyServiceList*);
    virtual ~Plugin() {}

    Services::ProxyServiceList* GetServices() { return m_services; }
    std::string GetName() { return m_name; }

    void* GetExportedSymbol(const std::string& symbolName);

    static Plugin* Find(const std::string& pluginName);
    static Plugin* Load(const std::string& path, std::unique_ptr<Services::ProxyServiceList>&& services);
    static void UnloadAll();

private:
    std::string m_name;
    std::string m_path;
    void* m_handle;
    // HACK: While the API is migrated, we need both of these..
    Services::ProxyServiceList* m_services;
    std::unique_ptr<Services::ProxyServiceList> m_servicesOwning;

    static inline std::vector<Plugin*> s_plugins;
};

}
