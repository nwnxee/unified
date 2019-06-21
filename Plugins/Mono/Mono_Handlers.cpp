#include "Mono_Handlers.hpp"
#include "Assert.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/Constants.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CWorldTimer.hpp"
#include "API/Globals.hpp"

#include "Encoding.hpp"
#include "Log.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Mono {

MonoDomain* g_Domain;
MonoAssembly* g_Assembly;

CVirtualMachine* GetVm()
{
    return Globals::VirtualMachine();
}

CNWVirtualMachineCommands* GetVmCommands()
{
    return static_cast<CNWVirtualMachineCommands*>(GetVm()->m_pCmdImplementer);
}

CVirtualMachineScript* CreateScriptForClosure(uint64_t eventId)
{
    CVirtualMachineScript* script = new CVirtualMachineScript();
    script->m_nCodeSize = 0;
    script->m_pCode = NULL;
    script->m_nLoadedFromSave = 0;
    script->m_nSecondaryInstructPtr = 0;
    script->m_nInstructPtr = 0;
    script->m_nStackSize = 0;
    script->m_pStack = new CVirtualMachineStack();

    char buff[128];
    sprintf(buff, "%s %llu", "NWNX_MONO_INTERNAL", eventId);
    script->m_sScriptName = CExoString(buff);

    return script;
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

    LOG_DEBUG("Popped game defined structure %i at 0x%x.", id, value);
    return reinterpret_cast<T>(value);
}

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

void StackPushString(MonoString* value)
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    char* valueAsCStr = mono_string_to_utf8(value);
    LOG_DEBUG("Pushing string '%s'.", valueAsCStr);
    CExoString str(Encoding::FromUTF8(valueAsCStr).c_str());
    mono_free(valueAsCStr);

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
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    int32_t value;
    if (!GetVm()->StackPopInteger(&value))
    {
        LOG_WARNING("Failed to pop integer - recursion level %i.", GetVm()->m_nRecursionLevel);
        return -1;
    }

    LOG_DEBUG("Popped integer %d.", value);
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

    LOG_DEBUG("Popped float %f.", value);
    return value;
}

MonoString* StackPopString()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    CExoString value;
    if (!GetVm()->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", GetVm()->m_nRecursionLevel);
        return mono_string_new(g_Domain, "");
    }

    LOG_DEBUG("Popped string '%s'.", value.m_sString);

    return mono_string_new(g_Domain, Encoding::ToUTF8(value.CStr()).c_str());
}

uint32_t StackPopObject()
{
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    uint32_t value;
    if (!GetVm()->StackPopObject(&value))
    {
        LOG_WARNING("Failed to pop object - recursion level %i.", GetVm()->m_nRecursionLevel);
        return Constants::OBJECT_INVALID;
    }

    LOG_DEBUG("Popped object 0x%x.", value);
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

    LOG_DEBUG("Popping vector { %f, %f, %f }.", value.x, value.y, value.z);
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

void FreeEffect(void* ptr)
{
    if (ptr)
    {
        LOG_DEBUG("Freeing effect at 0x%x", ptr);
        GetVmCommands()->DestroyGameDefinedStructure(0, ptr);
    }
}

void FreeEvent(void* ptr)
{
    if (ptr)
    {
        LOG_DEBUG("Freeing event at 0x%x", ptr);
        GetVmCommands()->DestroyGameDefinedStructure(1, ptr);
    }
}

void FreeLocation(void* ptr)
{
    if (ptr)
    {
        LOG_DEBUG("Freeing location at 0x%x", ptr);
        GetVmCommands()->DestroyGameDefinedStructure(2, ptr);
    }
}

void FreeTalent(void* ptr)
{
    if (ptr)
    {
        LOG_DEBUG("Freeing talent at 0x%x", ptr);
        GetVmCommands()->DestroyGameDefinedStructure(3, ptr);
    }
}

void FreeItemProperty(void* ptr)
{
    if (ptr)
    {
        LOG_DEBUG("Freeing item property at 0x%x", ptr);
        GetVmCommands()->DestroyGameDefinedStructure(4, ptr);
    }
}

void BeginClosure(uint32_t value)
{
    GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = value;
    GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = 1;
    GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
    GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
}

int32_t ClosureAssignCommand(uint32_t oid, uint64_t eventId)
{
    CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
    if (obj)
    {
        CServerAIMaster* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(0, 0, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

int32_t ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId)
{
    CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
    if (obj)
    {
        int32_t days = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetCalendarDayFromSeconds(duration);
        int32_t time = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetTimeOfDayFromSeconds(duration);

        CServerAIMaster* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(days, time, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

int32_t ClosureActionDoCommand(uint32_t oid, uint64_t eventId)
{
    CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
    if (obj && obj->m_nObjectType > Constants::ObjectType::Area)
    {
        ((CNWSObject*)obj)->AddDoCommandAction(CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

}
