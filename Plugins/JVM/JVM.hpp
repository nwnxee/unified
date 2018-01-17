#pragma once

#include "Common.hpp"
#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

namespace JVM
{

// Plugin configuration, emitted here for your convenience.
struct Configuration {
    // Print all events to log.
    // bool m_logEvents = true;

    // Print all nwscript calls to log.
    // bool m_debugNWScriptCalls = false;

    std::string m_classpath                 = "";

    std::string m_addtional_arguments       = "";

    std::string m_classname_initListener    = "";
    std::string m_classname_eventListener   = "";
    std::string m_classname_tokenListener   = "";
    std::string m_classname_scorcoListener  = "";
    std::string m_classname_resmanListener  = "";
    std::string m_classname_convClass       = "";
};

// Implemention details.
class Internal;

class JVM : public NWNXLib::Plugin
{
public:
    JVM(const Plugin::CreateParams& params);
    virtual ~JVM();

private:
    Configuration m_config;

    friend class Internal;
    Internal* m_internal;

    void Reconfigure();
};

}
