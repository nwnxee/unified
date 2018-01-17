#include "JVM.hpp"
#include "Internal.hpp"

#include "Services/Log/Log.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "ViewPtr.hpp"

#include "API/Functions.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

#include "API/Globals.hpp"
#include "API/CExoBase.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<JVM::JVM> g_module;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info {
        "JVM",
        "Java Virtual Machine support for NWNXEE",
        "niv",
        "niv@nwnx.io",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    return (g_module = new JVM::JVM(params));
}

namespace JVM
{

using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;

JVM::JVM(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_config.m_classpath = GetServices()->m_config->Get<std::string>("CLASSPATH",
        std::string(Globals::ExoBase()->m_sUserDirectory.CStr()) + "/org.nwnx.nwnx2.jvm.jar");
    m_config.m_addtional_arguments = GetServices()->m_config->Get<std::string>("JVM_ARGUMENTS",
        "");

    m_config.m_classname_initListener = GetServices()->m_config->Get<std::string>("INIT_LISTENER",
        "org/nwnx/nwnx2/jvm/TestRunner");
    m_config.m_classname_eventListener = GetServices()->m_config->Get<std::string>("EVENT_LISTENER",
        "org/nwnx/nwnx2/jvm/Scheduler");
    m_config.m_classname_tokenListener = GetServices()->m_config->Get<std::string>("TOKEN_LISTENER",
        "org/nwnx/nwnx2/jvm/Scheduler");
    m_config.m_classname_scorcoListener = GetServices()->m_config->Get<std::string>("SCORCO_LISTENER",
        "org/nwnx/nwnx2/jvm/SCORCO");
    m_config.m_classname_resmanListener = GetServices()->m_config->Get<std::string>("RESMAN_LISTENER",
        "org/nwnx/nwnx2/jvm/ResMan");
    m_config.m_classname_convClass = GetServices()->m_config->Get<std::string>("CONV_CLASS",
        "org/nwnx/nwnx2/jvm/Conv");

    m_internal = new Internal(this);

    GetServices()->m_events->RegisterEvent("Event", std::bind(&Internal::OnEvent, m_internal, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("Token", std::bind(&Internal::OnToken, m_internal, std::placeholders::_1));
}

JVM::~JVM()
{
	if (m_internal)
	delete m_internal;
}

}
