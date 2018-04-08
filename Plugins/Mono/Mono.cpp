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

static bool s_InScriptContext = false;
static uint32_t s_PushedCount = 0;

namespace {

CVirtualMachine* GetVm()
{
    return Globals::VirtualMachine();
}

CNWVirtualMachineCommands* GetVmCommands()
{
    return static_cast<CNWVirtualMachineCommands*>(GetVm()->m_pCmdImplementer);
}

template <typename T>
void StackPushGameDefinedStructure(int id, uintptr_t value)
{
    ASSERT(s_InScriptContext);

    T* ptr = reinterpret_cast<T*>(value);
    if (GetVm()->StackPushEngineStructure(id, ptr))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push game defined structure %i at 0x%x - recursion level %i.",
            id, value, GetVm()->m_nRecursionLevel);
    }
}

}

extern "C" {

void CallBuiltIn(int32_t id)
{
    ASSERT(s_InScriptContext);
    GetVmCommands()->ExecuteCommand(id, s_PushedCount);
    s_PushedCount = 0;
}

void StackPushInt(int32_t value)
{
    ASSERT(s_InScriptContext);

    if (GetVm()->StackPushInteger(value))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push integer %s - recursion level %i.",
            value, GetVm()->m_nRecursionLevel);
    }
}

void StackPushFloat(float value)
{
    ASSERT(s_InScriptContext);

    if (GetVm()->StackPushFloat(value))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push float %f - recursion level %i.",
            value, GetVm()->m_nRecursionLevel);
    }
}

void StackPushString(const char* value)
{
    ASSERT(s_InScriptContext);

    CExoString str(value);
    if (GetVm()->StackPushString(str))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push string '%s' - recursion level %i.",
            str.m_sString, GetVm()->m_nRecursionLevel);
    }
}

void StackPushObject(int32_t value)
{
    ASSERT(s_InScriptContext);

    if (GetVm()->StackPushObject(value))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push object 0x%x - recursion level %i.",
            value, GetVm()->m_nRecursionLevel);
    }
}

void StackPushVector(Vector value)
{
    ASSERT(s_InScriptContext);

    if (GetVm()->StackPushVector(value))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push vector { %f, %f, %f } - recursion level %i.",
            value.x, value.y, value.z, GetVm()->m_nRecursionLevel);
    }
}

void StackPushEffect(uintptr_t value)
{
    StackPushGameDefinedStructure<CGameEffect*>(0, value);
}

void StackPushEvent(uintptr_t value)
{
    StackPushGameDefinedStructure<CScriptEvent*>(1, value);
}

void StackPushLocation(uintptr_t value)
{
    StackPushGameDefinedStructure<CScriptLocation*>(2, value);
}

void StackPushTalent(uintptr_t value)
{
    StackPushGameDefinedStructure<CScriptTalent*>(3, value);
}

void StackPushItemProperty(uintptr_t value)
{
    StackPushGameDefinedStructure<CGameEffect*>(4, value);
}

int32_t StackPopInt();
float StackPopFloat();
const char* StackPopString();
int32_t StackPopObject();
Vector StackPopVector();
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
