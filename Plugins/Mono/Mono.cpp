#include "Mono.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"

#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Mono::Mono> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Mono",
        "Allows users to see sharp.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Mono::Mono(params);
    return g_plugin;
}

namespace {

CVirtualMachine* GetVm()
{
    return Globals::VirtualMachine();
}

CNWVirtualMachineCommands* GetVmCommands()
{
    return static_cast<CNWVirtualMachineCommands*>(GetVm()->m_pCmdImplementer);
}

}

static bool s_InScriptContext = false;
static uint32_t s_PushedCount = 0;

extern "C" {

struct Vector
{
    float m_X;
    float m_Y;
    float m_Z;
};

void CallBuiltIn(int32_t id)
{
    ASSERT(s_InScriptContext);
    GetVmCommands()->ExecuteCommand(id, s_PushedCount);
    s_PushedCount = 0;
}

void StackPushInt(int32_t id)
{
    ASSERT(s_InScriptContext);

    if (GetVm()->StackPushInteger(id))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push integer %s - recursion level %i.", id, GetVm()->m_nRecursionLevel);
    }
}

void StackPushFloat(float id);
void StackPushString(const char* str);
void StackPushObject(int32_t objId);
void StackPushVector(::Vector* vec);
void StackPushEffect(uintptr_t effect);
void StackPushEvent(uintptr_t event);
void StackPushLocation(uintptr_t location);
void StackPushTalent(uintptr_t event);
void StackPushItemProperty(uintptr_t itemProperty);

int32_t StackPopInt();
float StackPopFloat();
const char* StackPopString();
int32_t StackPopObject();
::Vector StackPopVector();
uintptr_t StackPopEffect();
uintptr_t StackPopEvent();
uintptr_t StackPopLocation();
uintptr_t StackPopTalent();
uintptr_t StackPopItemProperty();

}

using namespace NWNXLib::Services;

namespace Mono {

Mono::Mono(const Plugin::CreateParams& params)
    : Plugin(params), m_Domain(nullptr)
{
    Maybe<std::string> configPath = GetServices()->m_config->Get<std::string>("CONFIG_PATH");
    mono_config_parse(configPath ? configPath->c_str() : nullptr);

    m_Domain = mono_jit_init("nwnx");

    std::string assembly = GetServices()->m_config->Require<std::string>("ASSEMBLY");
    LOG_INFO("Loading assembly %s.", assembly.c_str());
    m_Assembly = mono_domain_assembly_open(m_Domain, assembly.c_str());

    if (!m_Assembly)
    {
        throw std::logic_error("Could not open the mono assembly.");
    }
}

Mono::~Mono()
{
    if (m_Domain)
    {
        mono_jit_cleanup(m_Domain);
    }
}

bool Mono::RunMonoScript(const char* scriptName)
{
    auto iter = m_ScriptMap.find(scriptName);
    if (iter == std::end(m_ScriptMap))
    {
        iter = m_ScriptMap.insert(std::make_pair(scriptName, GetScriptEntryFromClass(scriptName))).first;
    }

    MonoMethod* method = iter->second;
    if (!method)
    {
        return false;
    }

    LOG_DEBUG("Invoking NWN.Scripts.%s::Main.", scriptName);

    MonoObject* ex = nullptr;
    mono_runtime_invoke(method, nullptr, nullptr, &ex);

    if (ex)
    {
        LOG_WARNING("Caught unhandled exception when invoking NWN.Scripts.%s::Main.", scriptName);
    }

    return true;
}

MonoMethod* Mono::GetScriptEntryFromClass(const char* className)
{
    MonoImage* image = mono_assembly_get_image(m_Assembly);
    ASSERT(image);

    MonoClass* cls = mono_class_from_name(image, "NWN.Scripts", className);

    if (!cls)
    {
        LOG_DEBUG("Failed to find class %s.", className);
        return nullptr;
    }

    MonoMethod* method = mono_class_get_method_from_name(cls, "Main", 0);

    if (method)
    {
        LOG_INFO("Resolved NWN.Scripts.%s::Main.", className);
    }
    else
    {
        LOG_WARNING("Failed to resolve NWN.Scripts.%s::Main - ill-formed script?", className);
    }

    return method;
}

}
