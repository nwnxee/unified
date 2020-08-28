#pragma once

#include "Services/Services.hpp"

namespace NWNXLib {

#define NWNX_PLUGIN_ENTRY extern "C"

// All plugins should extend this class if they want to use the API!
// This class performs neccessary initialisation of shared API state.
class Plugin
{
public:
    Plugin(Services::ProxyServiceList* services) : m_services(services) {}
    virtual ~Plugin() {};

protected:
    Services::ProxyServiceList* GetServices() { return m_services; }

private:
    Services::ProxyServiceList* m_services;
};

}
