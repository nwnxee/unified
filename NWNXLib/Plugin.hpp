#pragma once

#include "Services/Services.hpp"

#include <string>
#include <unordered_map>

namespace NWNXLib {


#define NWNX_PLUGIN_ENTRY extern "C"

// All plugins should extend this class if they want to use the API!
// This class performs neccessary initialisation of shared API state.
class Plugin
{
public: // Structures
    struct Info
    {
        Info(std::string name,
            std::string description,
            std::string author,
            std::string contact,
            const uint32_t version,
            const bool hotswap);

        std::string m_name; // The plugin's name.
        std::string m_description; // The plugin's description.
        std::string m_author; // The author's name.
        std::string m_contact; // The author's or plugin's contact information.
        uint32_t m_version; // The plugin's version..
        bool m_hotswap; // Whether this plugin should be monitored and reloaded if the plugin changes.

        static const uint32_t s_targetBuild = NWNX_TARGET_NWN_BUILD; // The targetted build version
        static const uint32_t s_targetBuildRevision = NWNX_TARGET_NWN_BUILD_REVISION;
    };

    struct CreateParams
    {
    public:
        Services::ProxyServiceList* m_services;
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
    Services::ProxyServiceList* GetServices();

private:
    Services::ProxyServiceList* m_services;
};

}
