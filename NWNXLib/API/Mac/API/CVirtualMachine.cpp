#include "CVirtualMachine.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "CScriptLog.hpp"
#include "CVirtualMachineCache.hpp"
#include "CVirtualMachineCmdImplementer.hpp"
#include "CVirtualMachineDebuggingContext.hpp"

namespace NWNXLib {

namespace API {

CVirtualMachine::CVirtualMachine()
{
    CVirtualMachine__CVirtualMachineCtor__0(this);
}

CVirtualMachine::~CVirtualMachine()
{
    CVirtualMachine__CVirtualMachineDtor__0(this);
}

void CVirtualMachine::Debugger(int32_t* a0)
{
    return CVirtualMachine__Debugger(this, a0);
}

int32_t CVirtualMachine::DeleteScript(CVirtualMachineScript* a0)
{
    return CVirtualMachine__DeleteScript(this, a0);
}

void CVirtualMachine::DeleteScriptSituation(void* a0)
{
    return CVirtualMachine__DeleteScriptSituation(this, a0);
}

int32_t CVirtualMachine::ExecuteCode(int32_t* a0, char* a1, int32_t a2, CVirtualMachineDebuggingContext* a3)
{
    return CVirtualMachine__ExecuteCode(this, a0, a1, a2, a3);
}

int32_t CVirtualMachine::GetRunScriptReturnValue(int32_t* a0, void** a1)
{
    return CVirtualMachine__GetRunScriptReturnValue(this, a0, a1);
}

CScriptLog* CVirtualMachine::GetScriptLog(const CExoString& a0)
{
    return CVirtualMachine__GetScriptLog(this, a0);
}

void CVirtualMachine::InitializeScript(CVirtualMachineScript* a0, char* a1, int32_t a2)
{
    return CVirtualMachine__InitializeScript(this, a0, a1, a2);
}

int32_t CVirtualMachine::LoadScriptSituation_Internal(CVirtualMachineScript** a0, CResGFF* a1, CResStruct* a2)
{
    return CVirtualMachine__LoadScriptSituation_Internal(this, a0, a1, a2);
}

int32_t CVirtualMachine::PopInstructionPtr(int32_t* a0)
{
    return CVirtualMachine__PopInstructionPtr(this, a0);
}

int32_t CVirtualMachine::PushInstructionPtr(int32_t a0)
{
    return CVirtualMachine__PushInstructionPtr(this, a0);
}

int32_t CVirtualMachine::ReadScriptFile(CExoString* a0)
{
    return CVirtualMachine__ReadScriptFile(this, a0);
}

int32_t CVirtualMachine::RunScript(CExoString* a0, uint32_t a1, int32_t a2)
{
    return CVirtualMachine__RunScript(this, a0, a1, a2);
}

int32_t CVirtualMachine::RunScriptFile(int32_t a0)
{
    return CVirtualMachine__RunScriptFile(this, a0);
}

int32_t CVirtualMachine::RunScriptSituation(void* a0, uint32_t a1, int32_t a2)
{
    return CVirtualMachine__RunScriptSituation(this, a0, a1, a2);
}

int32_t CVirtualMachine::SaveScriptSituation_Internal(CVirtualMachineScript* a0, CResGFF* a1, CResStruct* a2)
{
    return CVirtualMachine__SaveScriptSituation_Internal(this, a0, a1, a2);
}

void CVirtualMachine::SetCommandImplementer(CVirtualMachineCmdImplementer* a0)
{
    return CVirtualMachine__SetCommandImplementer(this, a0);
}

void CVirtualMachine::SetDebugGUIFlag(int32_t a0)
{
    return CVirtualMachine__SetDebugGUIFlag(this, a0);
}

int32_t CVirtualMachine::SetUpScriptSituation(CVirtualMachineScript* a0)
{
    return CVirtualMachine__SetUpScriptSituation(this, a0);
}

int32_t CVirtualMachine::StackPopCommand_Internal(CVirtualMachineScript** a0)
{
    return CVirtualMachine__StackPopCommand_Internal(this, a0);
}

int32_t CVirtualMachine::StackPopEngineStructure(int32_t a0, void** a1)
{
    return CVirtualMachine__StackPopEngineStructure(this, a0, a1);
}

int32_t CVirtualMachine::StackPopFloat(float* a0)
{
    return CVirtualMachine__StackPopFloat(this, a0);
}

int32_t CVirtualMachine::StackPopInteger(int32_t* a0)
{
    return CVirtualMachine__StackPopInteger(this, a0);
}

int32_t CVirtualMachine::StackPopObject(uint32_t* a0)
{
    return CVirtualMachine__StackPopObject(this, a0);
}

int32_t CVirtualMachine::StackPopString(CExoString* a0)
{
    return CVirtualMachine__StackPopString(this, a0);
}

int32_t CVirtualMachine::StackPopVector(Vector* a0)
{
    return CVirtualMachine__StackPopVector(this, a0);
}

int32_t CVirtualMachine::StackPushEngineStructure(int32_t a0, void* a1)
{
    return CVirtualMachine__StackPushEngineStructure(this, a0, a1);
}

int32_t CVirtualMachine::StackPushFloat(float a0)
{
    return CVirtualMachine__StackPushFloat(this, a0);
}

int32_t CVirtualMachine::StackPushInteger(int32_t a0)
{
    return CVirtualMachine__StackPushInteger(this, a0);
}

int32_t CVirtualMachine::StackPushObject(uint32_t a0)
{
    return CVirtualMachine__StackPushObject(this, a0);
}

int32_t CVirtualMachine::StackPushString(const CExoString& a0)
{
    return CVirtualMachine__StackPushString(this, a0);
}

int32_t CVirtualMachine::StackPushVector(Vector a0)
{
    return CVirtualMachine__StackPushVector(this, a0);
}

int32_t CVirtualMachine::Test_RunAllScriptsInDirectory(CExoString& a0)
{
    return CVirtualMachine__Test_RunAllScriptsInDirectory(this, a0);
}

void CVirtualMachine__CVirtualMachineCtor__0(CVirtualMachine* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__CVirtualMachineCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CVirtualMachine__CVirtualMachineDtor__0(CVirtualMachine* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__CVirtualMachineDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CVirtualMachine__Debugger(CVirtualMachine* thisPtr, int32_t* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__Debugger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__DeleteScript(CVirtualMachine* thisPtr, CVirtualMachineScript* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__DeleteScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CVirtualMachine__DeleteScriptSituation(CVirtualMachine* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__DeleteScriptSituation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__ExecuteCode(CVirtualMachine* thisPtr, int32_t* a0, char* a1, int32_t a2, CVirtualMachineDebuggingContext* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t*, char*, int32_t, CVirtualMachineDebuggingContext*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__ExecuteCode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CVirtualMachine__GetRunScriptReturnValue(CVirtualMachine* thisPtr, int32_t* a0, void** a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t*, void**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__GetRunScriptReturnValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CScriptLog* CVirtualMachine__GetScriptLog(CVirtualMachine* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CScriptLog*(__attribute__((cdecl)) *)(CVirtualMachine*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__GetScriptLog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CVirtualMachine__InitializeScript(CVirtualMachine* thisPtr, CVirtualMachineScript* a0, char* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript*, char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__InitializeScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachine__LoadScriptSituation_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript** a0, CResGFF* a1, CResStruct* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript**, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__LoadScriptSituation_Internal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachine__PopInstructionPtr(CVirtualMachine* thisPtr, int32_t* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__PopInstructionPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__PushInstructionPtr(CVirtualMachine* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__PushInstructionPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__ReadScriptFile(CVirtualMachine* thisPtr, CExoString* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__ReadScriptFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__RunScript(CVirtualMachine* thisPtr, CExoString* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CExoString*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__RunScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachine__RunScriptFile(CVirtualMachine* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__RunScriptFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__RunScriptSituation(CVirtualMachine* thisPtr, void* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, void*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__RunScriptSituation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CVirtualMachine__SaveScriptSituation_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript* a0, CResGFF* a1, CResStruct* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__SaveScriptSituation_Internal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CVirtualMachine__SetCommandImplementer(CVirtualMachine* thisPtr, CVirtualMachineCmdImplementer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineCmdImplementer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__SetCommandImplementer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CVirtualMachine__SetDebugGUIFlag(CVirtualMachine* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__SetDebugGUIFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__SetUpScriptSituation(CVirtualMachine* thisPtr, CVirtualMachineScript* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__SetUpScriptSituation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopCommand_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript** a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CVirtualMachineScript**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopCommand_Internal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopEngineStructure(CVirtualMachine* thisPtr, int32_t a0, void** a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t, void**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopEngineStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachine__StackPopFloat(CVirtualMachine* thisPtr, float* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopInteger(CVirtualMachine* thisPtr, int32_t* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopObject(CVirtualMachine* thisPtr, uint32_t* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopString(CVirtualMachine* thisPtr, CExoString* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPopVector(CVirtualMachine* thisPtr, Vector* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPopVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPushEngineStructure(CVirtualMachine* thisPtr, int32_t a0, void* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushEngineStructure);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachine__StackPushFloat(CVirtualMachine* thisPtr, float a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPushInteger(CVirtualMachine* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPushObject(CVirtualMachine* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPushString(CVirtualMachine* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__StackPushVector(CVirtualMachine* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__StackPushVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CVirtualMachine__Test_RunAllScriptsInDirectory(CVirtualMachine* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachine*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachine__Test_RunAllScriptsInDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
