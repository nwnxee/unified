#include "DotNET.hpp"

#include "API/ALL_CLASSES.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CWorldTimer.hpp"
#include "Services/Services.hpp"
#include "Services/Events/Events.hpp"

#include "Assert.hpp"
#include "Encoding.hpp"
#include "Log.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

template <typename T>
static int StackPushGameDefinedStructure(int id, T value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing game defined structure %i at 0x%x.", id, value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    T gameStruct = reinterpret_cast<T>(value);
    auto ret = vm->StackPushEngineStructure(id, gameStruct);
    if (!ret)
    {
        LOG_WARNING("Failed to push game defined structure %i at 0x%x - recursion level %i.",
            id, value, vm->m_nRecursionLevel);
    }
    return ret;
}

template <typename T>
static T StackPopGameDefinedStructure(int id)
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    void* value;
    if (!vm->StackPopEngineStructure(id, &value))
    {
        LOG_WARNING("Failed to pop game defined structure %i - recursion level %i.",
            id, vm->m_nRecursionLevel);
        return nullptr;
    }

    LOG_DEBUG("Popped game defined structure %i at 0x%x.", id, value);
    return reinterpret_cast<T>(value);
}


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
    CExoString str(Encoding::FromUTF8(value).c_str());

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

void DotNET::StackPushEffect(CGameEffect* value)
{
    PushedCount += StackPushGameDefinedStructure(0, value);
}

void DotNET::StackPushEvent(CScriptEvent* value)
{
    PushedCount += StackPushGameDefinedStructure(1, value);
}

void DotNET::StackPushLocation(CScriptLocation* value)
{
    PushedCount += StackPushGameDefinedStructure(2, value);
}

void DotNET::StackPushTalent(CScriptTalent* value)
{
    PushedCount += StackPushGameDefinedStructure(3, value);
}

void DotNET::StackPushItemProperty(CGameEffect* value)
{
    PushedCount += StackPushGameDefinedStructure(4, value);
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
    return strdup(Encoding::ToUTF8(value.CStr()).c_str());
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

CGameEffect* DotNET::StackPopEffect()
{
    return StackPopGameDefinedStructure<CGameEffect*>(0);
}

CScriptEvent* DotNET::StackPopEvent()
{
    return StackPopGameDefinedStructure<CScriptEvent*>(1);
}

CScriptLocation* DotNET::StackPopLocation()
{
    return StackPopGameDefinedStructure<CScriptLocation*>(2);
}

CScriptTalent* DotNET::StackPopTalent()
{
    return StackPopGameDefinedStructure<CScriptTalent*>(3);
}

CGameEffect* DotNET::StackPopItemProperty()
{
    return StackPopGameDefinedStructure<CGameEffect*>(4);
}

void DotNET::FreeEffect(void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing effect at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(0, ptr);
    }
}

void DotNET::FreeEvent(void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing event at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(1, ptr);
    }
}

void DotNET::FreeLocation(void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing location at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(2, ptr);
    }
}

void DotNET::FreeTalent(void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing talent at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(3, ptr);
    }
}

void DotNET::FreeItemProperty(void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing item property at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(4, ptr);
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
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, n);
}
void DotNET::nwnxPushFloat(float f)
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, f);
}
void DotNET::nwnxPushObject(uint32_t o)
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, (ObjectID)o);
}
void DotNET::nwnxPushString(const char *s)
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, Encoding::FromUTF8(s));
}
void DotNET::nwnxPushEffect(CGameEffect *e)
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, e);
}
void DotNET::nwnxPushItemProperty(CGameEffect *ip)
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Push(nwnxActivePlugin, nwnxActiveFunction, ip);
}
int32_t DotNET::nwnxPopInt()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    return events->Pop<int32_t>(nwnxActivePlugin, nwnxActiveFunction).value_or(0);
}
float DotNET::nwnxPopFloat()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    return events->Pop<float>(nwnxActivePlugin, nwnxActiveFunction).value_or(0.0f);
}
uint32_t DotNET::nwnxPopObject()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    return events->Pop<ObjectID>(nwnxActivePlugin, nwnxActiveFunction).value_or(Constants::OBJECT_INVALID);
}
const char* DotNET::nwnxPopString()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    auto str = events->Pop<std::string>(nwnxActivePlugin, nwnxActiveFunction).value_or(std::string{""});
    return strdup(Encoding::ToUTF8(str).c_str());
}
CGameEffect* DotNET::nwnxPopEffect()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    return events->Pop<CGameEffect*>(nwnxActivePlugin, nwnxActiveFunction).value_or(nullptr);
}
CGameEffect* DotNET::nwnxPopItemProperty()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    return events->Pop<CGameEffect*>(nwnxActivePlugin, nwnxActiveFunction).value_or(nullptr);
}
void DotNET::nwnxCallFunction()
{
    auto events = Instance->GetServices()->m_events->GetProxyBase();
    events->Call(nwnxActivePlugin, nwnxActiveFunction);
}

}
