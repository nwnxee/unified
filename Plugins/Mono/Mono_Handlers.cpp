#include "Mono_Handlers.hpp"
#include "Assert.hpp"
#include "API/Constants.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "Log.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Mono {

FreeList g_StructureFreeList;
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
    g_StructureFreeList.top().emplace_back(gameDefStruct);

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
    LOG_DEBUG("Pushing string %s.", value);
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    char* valueAsCStr = mono_string_to_utf8(value);
    CExoString str(valueAsCStr);
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

MonoString* StackPopString()
{
    LOG_DEBUG("Popping string.");
    ASSERT(GetVm()->m_nRecursionLevel >= 0);

    CExoString value;
    if (!GetVm()->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", GetVm()->m_nRecursionLevel);
        return mono_string_new(g_Domain, "");
    }

    return mono_string_new(g_Domain, value.m_sString);
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
