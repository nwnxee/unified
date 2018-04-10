#include "Mono.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
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
    LOG_DEBUG("Pushing game defined structure %i at 0x%x.", id, value);
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

template <typename T>
T StackPopGameDefinedStructure(int id, Mono::FreeList* freeList)
{
    LOG_DEBUG("Popping game defined structure.");
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
    Mono::GameDefinedStructure gameDefStruct;
    gameDefStruct.m_Id = id;
    gameDefStruct.m_Ptr = value;
    freeList->top().emplace_back(gameDefStruct);

    return reinterpret_cast<T>(value);
}

}

extern "C" {

void CallBuiltIn(int32_t id)
{
    LOG_DEBUG("Calling BuiltIn %i.", id);
    ASSERT(GetVm()->m_nRecursionLevel >= 0);
    GetVmCommands()->ExecuteCommand(id, s_PushedCount);
    s_PushedCount = 0;
}

void StackPushInteger(int32_t value)
{
    LOG_DEBUG("Pushing integer %i.", value);
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
    LOG_DEBUG("Pushing float %f.", value);
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
    LOG_DEBUG("Pushing string %s.", value);
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

void StackPushObject(uint32_t value)
{
    LOG_DEBUG("Pushing object 0x%x.", value);
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
    LOG_DEBUG("Pushing vector { %f, %f, %f }.", value.x, value.y, value.z);
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
    LOG_DEBUG("Popping integer.");
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
    LOG_DEBUG("Popping float.");
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
    LOG_DEBUG("Popping string.");
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

uint32_t StackPopObject()
{
    LOG_DEBUG("Popping object.");
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
    LOG_DEBUG("Popping vector.");
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    Vector value;
    if (!GetVm()->StackPopVector(&value))
    {
        LOG_WARNING("Failed to pop vector - recursion level %i.", GetVm()->m_nRecursionLevel);
        return value;
    }

    return value;
}

CGameEffect* StackPopEffect(Mono::FreeList* freeList)
{
    return StackPopGameDefinedStructure<CGameEffect*>(0, freeList);
}

CScriptEvent* StackPopEvent(Mono::FreeList* freeList)
{
    return StackPopGameDefinedStructure<CScriptEvent*>(1, freeList);
}

CScriptLocation* StackPopLocation(Mono::FreeList* freeList)
{
    return StackPopGameDefinedStructure<CScriptLocation*>(2, freeList);
}

CScriptTalent* StackPopTalent(Mono::FreeList* freeList)
{
    return StackPopGameDefinedStructure<CScriptTalent*>(3, freeList);
}

CGameEffect* StackPopItemProperty(Mono::FreeList* freeList)
{
    return StackPopGameDefinedStructure<CGameEffect*>(4, freeList);
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

    m_PushScriptContext = GetInternalHandler("PushScriptContext", 1);
    m_PopScriptContext = GetInternalHandler("PopScriptContext", 0);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CVirtualMachine__RunScript, void>(
        +[](CVirtualMachine* thisPtr, CExoString* script, Types::ObjectID objId, int32_t valid)
        {
            bool skip = script->m_sString && g_plugin->RunMonoScript(script->m_sString, objId, !!valid);
            if (!skip)
            {
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

struct ScriptContext
{
    // NOTE! This needs to be in sync with Internal.cs.
    Types::ObjectID m_Oid;
    FreeList* m_FreeList;
};

bool Mono::RunMonoScript(const char* scriptName, Types::ObjectID objId, bool valid)
{
    std::string scriptNameAsLower = scriptName;
    std::transform(std::begin(scriptNameAsLower), std::end(scriptNameAsLower), std::begin(scriptNameAsLower), ::tolower);

    auto iter = m_ScriptMap.find(scriptNameAsLower);
    if (iter == std::end(m_ScriptMap))
    {
        MonoMethod* method = GetScriptEntryFromClass(scriptNameAsLower.c_str());
        iter = m_ScriptMap.insert(std::make_pair(std::move(scriptNameAsLower), method)).first;
    }

    MonoMethod* method = iter->second;
    if (!method)
    {
        return false;
    }

    { // PREPARE VM
        GetVm()->m_nRecursionLevel += 1;
        GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = objId;
        GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = valid;
        GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
        m_StructureFreeList.emplace();
    }

    { // RUN C# SCRIPT
        MonoObject* ex = nullptr;

        LOG_DEBUG("Invoking NWN.Scripts.%s::Main on OID 0x%x.", scriptName, objId);

        do
        {
            ScriptContext ctx;
            ctx.m_Oid = objId;
            ctx.m_FreeList = &m_StructureFreeList;

            void* pushArgs[1] = { &ctx };

            mono_runtime_invoke(m_PushScriptContext, nullptr, pushArgs, &ex);
            if (ex)
            {
                // If we fail to push, we can't possible continue - so bail.
                break;
            }

            // Even if we fail the actual method, we still need to pop.
            mono_runtime_invoke(method, nullptr, nullptr, &ex);

            // If we failed the actual method, we discard this exception and only report actual method.
            mono_runtime_invoke(m_PopScriptContext, nullptr, nullptr, ex ? nullptr : &ex);
        }
        while (false);

        if (ex)
        {
            char* exMsg = mono_string_to_utf8(mono_object_to_string(ex, nullptr));
            LOG_WARNING("Caught unhandled exception when invoking NWN.Scripts.%s::Main: %s", scriptName, exMsg);
            mono_free(exMsg);
        }
    }

    { // CLEANUP VM
        GetVm()->m_nRecursionLevel -= 1;

        if (GetVm()->m_nRecursionLevel != -1)
        {
            GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
            GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
        }

        for (GameDefinedStructure& gameDefStruct : m_StructureFreeList.top())
        {
            GetVmCommands()->DestroyGameDefinedStructure(gameDefStruct.m_Id, gameDefStruct.m_Ptr);
        }

        m_StructureFreeList.pop();
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

MonoMethod* Mono::GetInternalHandler(const char* handler, int paramCount)
{
    MonoImage* image = mono_assembly_get_image(m_Assembly);
    ASSERT(image);

    MonoClass* cls = mono_class_from_name(image, "NWN", "Internal");

    if (!cls)
    {
        throw std::logic_error("Failed to resolve NWN.Internal.");
    }

    MonoMethod* method = mono_class_get_method_from_name(cls, handler, paramCount);

    if (!method)
    {
        throw std::logic_error("Failed to resolve NWN.Internal.");
    }

    LOG_INFO("Resolved NWN.Internal::%s.", handler);
    return method;
}

}
