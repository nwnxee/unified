#pragma once

#include "Services/Services.hpp"
#include "ViewPtr.hpp"

#include <string>
#include <unordered_map>

namespace NWNXLib {

#ifdef _WIN32
    #define NWNX_PLUGIN_ENTRY extern "C" __declspec(dllexport)
#else
    #define NWNX_PLUGIN_ENTRY extern "C"
#endif

// All plugins should extend this class if they want to use the API!
// This class performs neccessary initialisation of shared API state.
class Plugin
{
public: // Structures
    struct Info
    {
    public: // Structures
        using Version = uint32_t;

    public:
        Info(std::string&& name,
            std::string&& description,
            std::string&& author,
            std::string&& contact,
            const Version version,
            const bool hotswap,
            const uint32_t flags = 0,
            const Version targetVersion = NWNX_TARGET_NWN_BUILD);

        std::string m_name; // The plugin's name.
        std::string m_description; // The plugin's description.
        std::string m_author; // The author's name.
        std::string m_contact; // The author's or plugin's contact information.
        Version m_version; // The plugin's version..
        bool m_hotswap; // Whether this plugin should be monitored and reloaded if the plugin changes.
        uint32_t m_flags; // Any additional flags.
        Version m_targetVersion; // The targetted build version
    };

    struct CreateParams
    {
    public:
        ViewPtr<Services::ProxyServiceList> m_services;
    };

    enum class UnloadReason
    {
        HOT_SWAP,
        SHUTTING_DOWN,
        CREATION_FAILED
    };

public:
    Plugin(const CreateParams& params);
    virtual ~Plugin();

protected:
    ViewPtr<Services::ProxyServiceList> GetServices();

private:
    ViewPtr<Services::ProxyServiceList> m_services;
};

}
