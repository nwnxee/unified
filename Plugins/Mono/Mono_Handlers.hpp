#pragma once

#include "API/NWNXLibApi.hpp"
#include "API/Vector.hpp"

#include <unordered_map>
#include <stack>
#include <vector>

#include <mono/jit/jit.h>

namespace Mono {

extern MonoDomain* g_Domain;
extern MonoAssembly* g_Assembly;

NWNXLib::API::CVirtualMachine* GetVm();
NWNXLib::API::CNWVirtualMachineCommands* GetVmCommands();

void CallBuiltIn(int32_t id);

void StackPushInteger(int32_t value);
void StackPushFloat(float value);
void StackPushString(MonoString* value);
void StackPushObject(uint32_t value);
void StackPushVector(NWNXLib::API::Vector value);
void StackPushEffect(NWNXLib::API::CGameEffect* value);
void StackPushEvent(NWNXLib::API::CScriptEvent* value);
void StackPushLocation(NWNXLib::API::CScriptLocation* value);
void StackPushTalent(NWNXLib::API::CScriptTalent* value);
void StackPushItemProperty(NWNXLib::API::CGameEffect* value);

int32_t StackPopInteger();
float StackPopFloat();
MonoString* StackPopString();
uint32_t StackPopObject();
NWNXLib::API::Vector StackPopVector();
NWNXLib::API::CGameEffect* StackPopEffect();
NWNXLib::API::CScriptEvent* StackPopEvent();
NWNXLib::API::CScriptLocation* StackPopLocation();
NWNXLib::API::CScriptTalent* StackPopTalent();
NWNXLib::API::CGameEffect* StackPopItemProperty();

void BeginClosure(uint32_t value);

void FreeEffect(void* ptr);
void FreeEvent(void* ptr);
void FreeLocation(void* ptr);
void FreeTalent(void* ptr);
void FreeItemProperty(void* ptr);

}
