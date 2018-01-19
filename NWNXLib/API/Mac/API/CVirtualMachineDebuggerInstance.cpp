#include "CVirtualMachineDebuggerInstance.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CVirtualMachine.hpp"

namespace NWNXLib {

namespace API {

CVirtualMachineDebuggerInstance::CVirtualMachineDebuggerInstance()
{
    CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceCtor__0(this);
}

CVirtualMachineDebuggerInstance::~CVirtualMachineDebuggerInstance()
{
    CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceDtor__0(this);
}

int32_t CVirtualMachineDebuggerInstance::DebuggerDisplayCurrentLocation(int32_t a0, int32_t a1)
{
    return CVirtualMachineDebuggerInstance__DebuggerDisplayCurrentLocation(this, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance::DebuggerMainLoop()
{
    return CVirtualMachineDebuggerInstance__DebuggerMainLoop(this);
}

int32_t CVirtualMachineDebuggerInstance::DebuggerSingleStep(int32_t a0)
{
    return CVirtualMachineDebuggerInstance__DebuggerSingleStep(this, a0);
}

int32_t CVirtualMachineDebuggerInstance::FindEmptyWatchViewEntry()
{
    return CVirtualMachineDebuggerInstance__FindEmptyWatchViewEntry(this);
}

int32_t CVirtualMachineDebuggerInstance::FindWatchViewEntry(CExoString* a0, CExoString* a1, int32_t a2)
{
    return CVirtualMachineDebuggerInstance__FindWatchViewEntry(this, a0, a1, a2);
}

CExoString CVirtualMachineDebuggerInstance::GenerateCallStackParameterView(int32_t a0, CExoString* a1, CExoString* a2)
{
    return CVirtualMachineDebuggerInstance__GenerateCallStackParameterView(this, a0, a1, a2);
}

CExoString CVirtualMachineDebuggerInstance::GenerateCallStackView(int32_t a0, int32_t a1, int32_t a2)
{
    return CVirtualMachineDebuggerInstance__GenerateCallStackView(this, a0, a1, a2);
}

int32_t CVirtualMachineDebuggerInstance::GenerateDebugVariableLocationForParameter(int32_t a0, int32_t a1)
{
    return CVirtualMachineDebuggerInstance__GenerateDebugVariableLocationForParameter(this, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance::GenerateFunctionIDFromInstructionPointer(int32_t a0)
{
    return CVirtualMachineDebuggerInstance__GenerateFunctionIDFromInstructionPointer(this, a0);
}

int32_t CVirtualMachineDebuggerInstance::GenerateLineNumberFromInstructionPointer(int32_t a0, int32_t a1)
{
    return CVirtualMachineDebuggerInstance__GenerateLineNumberFromInstructionPointer(this, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance::GenerateStackSizeAtInstructionPointer(int32_t a0, int32_t a1)
{
    return CVirtualMachineDebuggerInstance__GenerateStackSizeAtInstructionPointer(this, a0, a1);
}

CExoString CVirtualMachineDebuggerInstance::GenerateTypeName(CExoString* a0)
{
    return CVirtualMachineDebuggerInstance__GenerateTypeName(this, a0);
}

int32_t CVirtualMachineDebuggerInstance::GenerateTypeSize(CExoString* a0)
{
    return CVirtualMachineDebuggerInstance__GenerateTypeSize(this, a0);
}

CExoString CVirtualMachineDebuggerInstance::GenerateTypeValueFromStackLocation(int32_t a0, CExoString* a1)
{
    return CVirtualMachineDebuggerInstance__GenerateTypeValueFromStackLocation(this, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance::GetNextDebugVariable(int32_t a0, int32_t a1, int32_t a2)
{
    return CVirtualMachineDebuggerInstance__GetNextDebugVariable(this, a0, a1, a2);
}

int32_t CVirtualMachineDebuggerInstance::LoadDebugInfo(CVirtualMachineDebugLoader* a0)
{
    return CVirtualMachineDebuggerInstance__LoadDebugInfo(this, a0);
}

char* CVirtualMachineDebuggerInstance::LoadDebugInfoLine(unsigned char* a0, uint32_t a1, uint32_t a2, uint32_t* a3)
{
    return CVirtualMachineDebuggerInstance__LoadDebugInfoLine(this, a0, a1, a2, a3);
}

char* CVirtualMachineDebuggerInstance::LoadScriptLine(unsigned char* a0, uint32_t a1, uint32_t a2, uint32_t* a3, int32_t a4)
{
    return CVirtualMachineDebuggerInstance__LoadScriptLine(this, a0, a1, a2, a3, a4);
}

int32_t CVirtualMachineDebuggerInstance::ParseAndExecuteMessage(int32_t* a0)
{
    return CVirtualMachineDebuggerInstance__ParseAndExecuteMessage(this, a0);
}

int32_t CVirtualMachineDebuggerInstance::ReadIntegerFromInput(int32_t* a0, int32_t* a1)
{
    return CVirtualMachineDebuggerInstance__ReadIntegerFromInput(this, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance::ReadStringFromInput(int32_t* a0, CExoString* a1)
{
    return CVirtualMachineDebuggerInstance__ReadStringFromInput(this, a0, a1);
}

void CVirtualMachineDebuggerInstance::SendCallStackWindowUpdateCommands()
{
    return CVirtualMachineDebuggerInstance__SendCallStackWindowUpdateCommands(this);
}

void CVirtualMachineDebuggerInstance::SendCodeWindowUpdateCommands(CExoString a0, int32_t a1)
{
    return CVirtualMachineDebuggerInstance__SendCodeWindowUpdateCommands(this, a0, a1);
}

void CVirtualMachineDebuggerInstance::SendLabelsAndKeywords()
{
    return CVirtualMachineDebuggerInstance__SendLabelsAndKeywords(this);
}

void CVirtualMachineDebuggerInstance::SendWatchWindowEntry(CExoString* a0, CExoString* a1, CExoString* a2, CExoString* a3, int32_t a4)
{
    return CVirtualMachineDebuggerInstance__SendWatchWindowEntry(this, a0, a1, a2, a3, a4);
}

void CVirtualMachineDebuggerInstance::SendWatchWindowUpdateCommands(int32_t a0)
{
    return CVirtualMachineDebuggerInstance__SendWatchWindowUpdateCommands(this, a0);
}

void CVirtualMachineDebuggerInstance::ShutDownDebugger()
{
    return CVirtualMachineDebuggerInstance__ShutDownDebugger(this);
}

int32_t CVirtualMachineDebuggerInstance::SpawnDebugger()
{
    return CVirtualMachineDebuggerInstance__SpawnDebugger(this);
}

void CVirtualMachineDebuggerInstance::ToggleWatchWindowExpansion(CExoString a0)
{
    return CVirtualMachineDebuggerInstance__ToggleWatchWindowExpansion(this, a0);
}

void CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceCtor__0(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceDtor__0(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CVirtualMachineDebuggerInstance__DebuggerDisplayCurrentLocation(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__DebuggerDisplayCurrentLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance__DebuggerMainLoop(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__DebuggerMainLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CVirtualMachineDebuggerInstance__DebuggerSingleStep(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__DebuggerSingleStep);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachineDebuggerInstance__FindEmptyWatchViewEntry(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__FindEmptyWatchViewEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CVirtualMachineDebuggerInstance__FindWatchViewEntry(CVirtualMachineDebuggerInstance* thisPtr, CExoString* a0, CExoString* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString*, CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__FindWatchViewEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CVirtualMachineDebuggerInstance__GenerateCallStackParameterView(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, CExoString* a1, CExoString* a2)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, CExoString*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateCallStackParameterView);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CVirtualMachineDebuggerInstance__GenerateCallStackView(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateCallStackView);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachineDebuggerInstance__GenerateDebugVariableLocationForParameter(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateDebugVariableLocationForParameter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance__GenerateFunctionIDFromInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateFunctionIDFromInstructionPointer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachineDebuggerInstance__GenerateLineNumberFromInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateLineNumberFromInstructionPointer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance__GenerateStackSizeAtInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateStackSizeAtInstructionPointer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CVirtualMachineDebuggerInstance__GenerateTypeName(CVirtualMachineDebuggerInstance* thisPtr, CExoString* a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateTypeName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachineDebuggerInstance__GenerateTypeSize(CVirtualMachineDebuggerInstance* thisPtr, CExoString* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateTypeSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CVirtualMachineDebuggerInstance__GenerateTypeValueFromStackLocation(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, CExoString* a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GenerateTypeValueFromStackLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance__GetNextDebugVariable(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__GetNextDebugVariable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachineDebuggerInstance__LoadDebugInfo(CVirtualMachineDebuggerInstance* thisPtr, CVirtualMachineDebugLoader* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CVirtualMachineDebugLoader*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__LoadDebugInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char* CVirtualMachineDebuggerInstance__LoadDebugInfoLine(CVirtualMachineDebuggerInstance* thisPtr, unsigned char* a0, uint32_t a1, uint32_t a2, uint32_t* a3)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, unsigned char*, uint32_t, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__LoadDebugInfoLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

char* CVirtualMachineDebuggerInstance__LoadScriptLine(CVirtualMachineDebuggerInstance* thisPtr, unsigned char* a0, uint32_t a1, uint32_t a2, uint32_t* a3, int32_t a4)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, unsigned char*, uint32_t, uint32_t, uint32_t*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__LoadScriptLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CVirtualMachineDebuggerInstance__ParseAndExecuteMessage(CVirtualMachineDebuggerInstance* thisPtr, int32_t* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__ParseAndExecuteMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachineDebuggerInstance__ReadIntegerFromInput(CVirtualMachineDebuggerInstance* thisPtr, int32_t* a0, int32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__ReadIntegerFromInput);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineDebuggerInstance__ReadStringFromInput(CVirtualMachineDebuggerInstance* thisPtr, int32_t* a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__ReadStringFromInput);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CVirtualMachineDebuggerInstance__SendCallStackWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SendCallStackWindowUpdateCommands);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CVirtualMachineDebuggerInstance__SendCodeWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SendCodeWindowUpdateCommands);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CVirtualMachineDebuggerInstance__SendLabelsAndKeywords(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SendLabelsAndKeywords);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CVirtualMachineDebuggerInstance__SendWatchWindowEntry(CVirtualMachineDebuggerInstance* thisPtr, CExoString* a0, CExoString* a1, CExoString* a2, CExoString* a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString*, CExoString*, CExoString*, CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SendWatchWindowEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CVirtualMachineDebuggerInstance__SendWatchWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SendWatchWindowUpdateCommands);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CVirtualMachineDebuggerInstance__ShutDownDebugger(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__ShutDownDebugger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CVirtualMachineDebuggerInstance__SpawnDebugger(CVirtualMachineDebuggerInstance* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__SpawnDebugger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CVirtualMachineDebuggerInstance__ToggleWatchWindowExpansion(CVirtualMachineDebuggerInstance* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineDebuggerInstance*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineDebuggerInstance__ToggleWatchWindowExpansion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
