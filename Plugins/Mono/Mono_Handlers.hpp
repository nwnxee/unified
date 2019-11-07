#pragma once

#include "API/NWNXLibApi.hpp"
#include "API/Vector.hpp"

#include <unordered_map>
#include <stack>
#include <vector>
#include <cstring>
#include <memory>

#include <mono/jit/jit.h>

namespace Mono {

extern MonoDomain* g_Domain;
extern MonoAssembly* g_Assembly;

CVirtualMachine* GetVm();
CNWVirtualMachineCommands* GetVmCommands();

void CallBuiltIn(int32_t id);

void StackPushInteger(int32_t value);
void StackPushFloat(float value);
void StackPushString(MonoString* value);
void StackPushObject(uint32_t value);
void StackPushVector(Vector value);
void StackPushEffect(CGameEffect* value);
void StackPushEvent(CScriptEvent* value);
void StackPushLocation(CScriptLocation* value);
void StackPushTalent(CScriptTalent* value);
void StackPushItemProperty(CGameEffect* value);

int32_t StackPopInteger();
float StackPopFloat();
MonoString* StackPopString();
uint32_t StackPopObject();
Vector StackPopVector();
CGameEffect* StackPopEffect();
CScriptEvent* StackPopEvent();
CScriptLocation* StackPopLocation();
CScriptTalent* StackPopTalent();
CGameEffect* StackPopItemProperty();

void FreeEffect(void* ptr);
void FreeEvent(void* ptr);
void FreeLocation(void* ptr);
void FreeTalent(void* ptr);
void FreeItemProperty(void* ptr);

void BeginClosure(uint32_t value);
int32_t ClosureAssignCommand(uint32_t oid, uint64_t eventId);
int32_t ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId);
int32_t ClosureActionDoCommand(uint32_t oid, uint64_t eventId);

}
