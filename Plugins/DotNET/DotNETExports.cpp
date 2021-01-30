#include "DotNET.hpp"

#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CWorldTimer.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

static CVirtualMachineScript* CreateScriptForClosure(uint64_t eventId)
{
    CVirtualMachineScript* script = new CVirtualMachineScript();
    script->m_pCode = NULL;
    script->m_nSecondaryInstructPtr = 0;
    script->m_nInstructPtr = 0;
    script->m_nStackSize = 0;
    script->m_pStack = new CVirtualMachineStack();

    char buff[128];
    sprintf(buff, "%s %lu", "NWNX_DOTNET_INTERNAL", eventId);
    script->m_sScriptName = CExoString(buff);

    return script;
}

void DotNET::CallBuiltIn(int32_t id)
{
    auto vm = Globals::VirtualMachine();
    auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
    LOG_DEBUG("Calling BuiltIn %i.", id);
    ASSERT(vm->m_nRecursionLevel >= 0);
    cmd->ExecuteCommand(id, PushedCount);
    PushedCount = 0;
}

void DotNET::StackPushInteger(int32_t value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing integer %i.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushInteger(value))
    {
        ++PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push integer %s - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

void DotNET::StackPushFloat(float value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing float %f.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushFloat(value))
    {
        ++PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push float %f - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

void DotNET::StackPushString(const char* value)
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    LOG_DEBUG("Pushing string '%s'.", value);
    CExoString str(String::FromUTF8(value).c_str());

    if (vm->StackPushString(str))
    {
        ++PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push string '%s' - recursion level %i.",
            str.m_sString, vm->m_nRecursionLevel);
    }
}

void DotNET::StackPushObject(uint32_t value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing object 0x%x.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushObject(value))
    {
        ++PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push object 0x%x - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

void DotNET::StackPushVector(Vector value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing vector { %f, %f, %f }.", value.x, value.y, value.z);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushVector(value))
    {
        ++PushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push vector { %f, %f, %f } - recursion level %i.",
            value.x, value.y, value.z, vm->m_nRecursionLevel);
    }
}

void DotNET::StackPushGameDefinedStructure(int32_t structId, void* value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing game defined structure %i at 0x%x.", structId, value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    auto ret = vm->StackPushEngineStructure(structId, value);
    if (!ret)
    {
        LOG_WARNING("Failed to push game defined structure %i at 0x%x - recursion level %i.",
            structId, value, vm->m_nRecursionLevel);
    }

    PushedCount += ret;
}

int32_t DotNET::StackPopInteger()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    int32_t value;
    if (!vm->StackPopInteger(&value))
    {
        LOG_WARNING("Failed to pop integer - recursion level %i.", vm->m_nRecursionLevel);
        return -1;
    }

    LOG_DEBUG("Popped integer %d.", value);
    return value;
}

float DotNET::StackPopFloat()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    float value;
    if (!vm->StackPopFloat(&value))
    {
        LOG_WARNING("Failed to pop float - recursion level %i.", vm->m_nRecursionLevel);
        return 0.0f;
    }

    LOG_DEBUG("Popped float %f.", value);
    return value;
}

const char* DotNET::StackPopString()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    CExoString value;
    if (!vm->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", vm->m_nRecursionLevel);
        return "";
    }

    LOG_DEBUG("Popped string '%s'.", value.m_sString);

    // TODO: Less copies
    return strdup(String::ToUTF8(value.CStr()).c_str());
}

uint32_t DotNET::StackPopObject()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    uint32_t value;
    if (!vm->StackPopObject(&value))
    {
        LOG_WARNING("Failed to pop object - recursion level %i.", vm->m_nRecursionLevel);
        return Constants::OBJECT_INVALID;
    }

    LOG_DEBUG("Popped object 0x%x.", value);
    return value;
}

Vector DotNET::StackPopVector()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    Vector value;
    if (!vm->StackPopVector(&value))
    {
        LOG_WARNING("Failed to pop vector - recursion level %i.", vm->m_nRecursionLevel);
        return value;
    }

    LOG_DEBUG("Popping vector { %f, %f, %f }.", value.x, value.y, value.z);
    return value;
}

void* DotNET::StackPopGameDefinedStructure(int32_t structId)
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    void* value;
    if (!vm->StackPopEngineStructure(structId, &value))
    {
        LOG_WARNING("Failed to pop game defined structure %i - recursion level %i.",
            structId, vm->m_nRecursionLevel);
        return nullptr;
    }

    LOG_DEBUG("Popped game defined structure %i at 0x%x.", structId, value);
    return value;
}

void DotNET::FreeGameDefinedStructure(int32_t structId, void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing game structure at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(structId, ptr);
    }
}

int32_t DotNET::ClosureAssignCommand(uint32_t oid, uint64_t eventId)
{
    if (Utils::GetGameObject(oid))
    {
        CServerAIMaster* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(0, 0, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

int32_t DotNET::ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId)
{
    if (Utils::GetGameObject(oid))
    {
        int32_t days = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetCalendarDayFromSeconds(duration);
        int32_t time = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetTimeOfDayFromSeconds(duration);

        CServerAIMaster* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(days, time, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

int32_t DotNET::ClosureActionDoCommand(uint32_t oid, uint64_t eventId)
{
    if (auto *obj = Utils::AsNWSObject(Utils::GetGameObject(oid)))
    {
        obj->AddDoCommandAction(CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

void DotNET::nwnxSetFunction(const char *plugin, const char *function)
{
    nwnxActivePlugin = plugin;
    nwnxActiveFunction = function;
}
void DotNET::nwnxPushInt(int32_t n)
{
    Events::Push(n);
}
void DotNET::nwnxPushFloat(float f)
{
    Events::Push(f);
}
void DotNET::nwnxPushObject(uint32_t o)
{
    Events::Push((ObjectID)o);
}
void DotNET::nwnxPushString(const char *s)
{
    Events::Push(String::FromUTF8(s));
}
void DotNET::nwnxPushEffect(CGameEffect *e)
{
    Events::Push(e);
}
void DotNET::nwnxPushItemProperty(CGameEffect *ip)
{
    Events::Push(ip);
}
int32_t DotNET::nwnxPopInt()
{
    return Events::Pop<int32_t>().value_or(0);
}
float DotNET::nwnxPopFloat()
{
    return Events::Pop<float>().value_or(0.0f);
}
uint32_t DotNET::nwnxPopObject()
{
    return Events::Pop<ObjectID>().value_or(Constants::OBJECT_INVALID);
}
const char* DotNET::nwnxPopString()
{
    auto str = Events::Pop<std::string>().value_or(std::string{""});
    return strdup(String::ToUTF8(str).c_str());
}
CGameEffect* DotNET::nwnxPopEffect()
{
    return Events::Pop<CGameEffect*>().value_or(nullptr);
}
CGameEffect* DotNET::nwnxPopItemProperty()
{
    return Events::Pop<CGameEffect*>().value_or(nullptr);
}
void DotNET::nwnxCallFunction()
{
    Events::Call(nwnxActivePlugin, nwnxActiveFunction);
}

NWNXLib::API::Globals::NWNXExportedGlobals DotNET::GetNWNXExportedGlobals()
{
    return NWNXLib::API::Globals::ExportedGlobals;
}

void* DotNET::RequestHook(uintptr_t address, void* managedFuncPtr, int32_t order)
{
    auto funchook = s_managed_hooks.emplace_back(Hooks::HookFunction(address, managedFuncPtr, order)).get();
    return funchook->GetOriginal();
}

void DotNET::ReturnHook(void* trampoline)
{
    for (auto it = s_managed_hooks.begin(); it != s_managed_hooks.end(); it++)
    {
        if (it->get()->GetOriginal() == trampoline)
        {
            s_managed_hooks.erase(it);
            return;
        }
    }
}

}
