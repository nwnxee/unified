#include "Mono.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <cstring>
#include <stack>
#include <vector>
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

static uint32_t s_PushedCount = 0;

template <typename T>
void StackPushGameDefinedStructure(int id, T value)
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    T gameStruct = reinterpret_cast<T>(value);
    if (GetVm()->StackPushEngineStructure(id, gameStruct))
    {
        ++s_PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push game defined structure %i at 0x%x - recursion level %i.",
            id, value, GetVm()->m_nRecursionLevel);
    }
}

struct GameDefinedStructure
{
    int m_Id;
    void* m_Ptr;
};

static std::stack<std::vector<GameDefinedStructure>> s_StructureFreeList;

template <typename T>
T StackPopGameDefinedStructure(int id)
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    void* value;
    if (!GetVm()->StackPopEngineStructure(id, &value))
    {
        LOG_WARNING("Failed to pop game defined structure %i - recursion level %i.",
            id, GetVm()->m_nRecursionLevel);
        return nullptr;
    }

    // Every single time we pop a game defined structure, we now have a copy floating around.
    // We will collect these in a big list - and at the end of the script context, we will
    // handle freeing them, else we will leak memory.

    GameDefinedStructure gameDefStruct;
    gameDefStruct.m_Id = id;
    gameDefStruct.m_Ptr = value;
    s_StructureFreeList.top().emplace_back(gameDefStruct);

    return reinterpret_cast<T>(value);
}

}

extern "C" {

void CallBuiltIn(int32_t id)
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);
    GetVmCommands()->ExecuteCommand(id, s_PushedCount);
    s_PushedCount = 0;
}

void StackPushInteger(int32_t value)
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

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
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

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
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

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
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

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
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

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

void StackPushEffect(CGameEffect* value)
{
    StackPushGameDefinedStructure(0, value);
}

void StackPushEvent(CScriptEvent* value)
{
    StackPushGameDefinedStructure(1, value);
}

void StackPushLocation(CScriptLocation* value)
{
    StackPushGameDefinedStructure(2, value);
}

void StackPushTalent(CScriptTalent* value)
{
    StackPushGameDefinedStructure(3, value);
}

void StackPushItemProperty(CGameEffect* value)
{
    StackPushGameDefinedStructure(4, value);
}

int32_t StackPopInteger()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    int32_t value;
    if (!GetVm()->StackPopInteger(&value))
    {
        LOG_WARNING("Failed to pop integer - recursion level %i.", GetVm()->m_nRecursionLevel);
        return -1;
    }

    return value;
}

float StackPopFloat()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    float value;
    if (!GetVm()->StackPopFloat(&value))
    {
        LOG_WARNING("Failed to pop float - recursion level %i.", GetVm()->m_nRecursionLevel);
        return 0.0f;
    }

    return value;
}

const char* StackPopString()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    CExoString value;
    if (!GetVm()->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", GetVm()->m_nRecursionLevel);
        return "";
    }

    static char s_StrBuf[128*1024];
    strcpy(s_StrBuf, value.m_sString);
    return s_StrBuf;
}

int32_t StackPopObject()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    uint32_t value;
    if (!GetVm()->StackPopObject(&value))
    {
        LOG_WARNING("Failed to pop object - recursion level %i.", GetVm()->m_nRecursionLevel);
        return Constants::OBJECT_INVALID;
    }

    return value;
}

Vector StackPopVector()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    Vector value;
    if (!GetVm()->StackPopVector(&value))
    {
        LOG_WARNING("Failed to pop vector - recursion level %i.", GetVm()->m_nRecursionLevel);
        return value;
    }

    return value;
}

CGameEffect* StackPopEffect()
{
    return StackPopGameDefinedStructure<CGameEffect*>(0);
}

CScriptEvent* StackPopEvent()
{
    return StackPopGameDefinedStructure<CScriptEvent*>(1);
}

CScriptLocation* StackPopLocation()
{
    return StackPopGameDefinedStructure<CScriptLocation*>(2);
}

CScriptTalent* StackPopTalent()
{
    return StackPopGameDefinedStructure<CScriptTalent*>(3);
}

CGameEffect* StackPopItemProperty()
{
    return StackPopGameDefinedStructure<CGameEffect*>(4);
}

}

using namespace NWNXLib::Services;

namespace Mono {

static Hooking::FunctionHook* s_RunScriptHook;

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

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CVirtualMachine__RunScript, void>(
        +[](CVirtualMachine* thisPtr, CExoString* script, Types::ObjectID objId, int32_t valid)
        {
            bool skip = script->m_sString && g_plugin->RunMonoScript(script->m_sString, objId, !!valid);
            if (!skip)
            {
                LOG_DEBUG("Passing original through - %s", script->m_sString ? script->m_sString : "(unknown)");
                s_RunScriptHook->CallOriginal<void>(thisPtr, script, objId, valid);
            }
        }
    );

    s_RunScriptHook = GetServices()->m_hooks->FindHookByAddress(Functions::CVirtualMachine__RunScript);
}

Mono::~Mono()
{
    if (m_Domain)
    {
        mono_jit_cleanup(m_Domain);
    }
}

bool Mono::RunMonoScript(const char* scriptName, Types::ObjectID objId, bool valid)
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

    { // PREPARE VM
        GetVm()->m_nRecursionLevel += 1;
        GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = objId;
        GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = valid;
        GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];

        s_StructureFreeList.emplace();
    }

    { // RUN C# SCRIPT
        MonoObject* ex = nullptr;
        mono_runtime_invoke(method, nullptr, nullptr, &ex);

        if (ex)
        {
            char* exMsg = mono_string_to_utf8(mono_object_to_string(ex, nullptr));
            LOG_WARNING("Caught unhandled exception when invoking NWN.Scripts.%s::Main: %s", scriptName, exMsg);
            mono_free(exMsg);
        }
    }

    { // CLEANUP VM
        GetVm()->m_nRecursionLevel -= 1;
        GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];

        for (GameDefinedStructure& gameDefStruct : s_StructureFreeList.top())
        {
            GetVmCommands()->DestroyGameDefinedStructure(gameDefStruct.m_Id, gameDefStruct.m_Ptr);
        }

        s_StructureFreeList.pop();
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
