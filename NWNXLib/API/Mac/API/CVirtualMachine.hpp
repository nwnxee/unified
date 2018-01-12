#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCScriptLogPtr.hpp"
#include "CExoString.hpp"
#include "CVirtualMachineFile.hpp"
#include "CVirtualMachineScript.hpp"
#include "CVirtualMachineStack.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;
struct CScriptLog;
struct CVirtualMachineCache;
struct CVirtualMachineCmdImplementer;
struct CVirtualMachineDebuggingContext;

struct CVirtualMachine
{
    int32_t m_nReturnValueParameterType;
    void* m_pReturnValue;
    uint32_t m_nInstructionsExecuted;
    int32_t m_nRecursionLevel;
    CVirtualMachineScript m_pVirtualMachineScript[8];
    int32_t m_bValidObjectRunScript[8];
    uint32_t m_oidObjectRunScript[8];
    CVirtualMachineStack m_cRunTimeStack;
    int32_t m_nInstructPtrLevel;
    int32_t m_pnRunTimeInstructPtr[128];
    int32_t m_nSecondaryInstructionPointer;
    int32_t m_nStackSizeToSave;
    int32_t m_nBaseStackSizeToSave;
    CVirtualMachineCmdImplementer* m_pCmdImplementer;
    int32_t m_bDebugGUIRequired;
    int32_t m_bDebuggerSpawned;
    CVirtualMachineFile m_cVMFile;
    CVirtualMachineCache* m_pCache;
    CScriptLog* m_pLog;
    CExoArrayListTemplatedCScriptLogPtr m_aScriptLog;
    int32_t m_bEnableScriptLogging;
    int32_t m_bEnableScriptProfiling;
    uint32_t m_nScriptStartTime;
    uint32_t m_nScriptEndTime;
    uint32_t m_nInstructionLimit;

    // The below are auto generated stubs.
    CVirtualMachine(const CVirtualMachine&) = default;
    CVirtualMachine& operator=(const CVirtualMachine&) = default;

    CVirtualMachine();
    ~CVirtualMachine();
    void Debugger(int32_t*);
    int32_t DeleteScript(CVirtualMachineScript*);
    void DeleteScriptSituation(void*);
    int32_t ExecuteCode(int32_t*, char*, int32_t, CVirtualMachineDebuggingContext*);
    int32_t GetRunScriptReturnValue(int32_t*, void**);
    CScriptLog* GetScriptLog(const CExoString&);
    void InitializeScript(CVirtualMachineScript*, char*, int32_t);
    int32_t LoadScriptSituation_Internal(CVirtualMachineScript**, CResGFF*, CResStruct*);
    int32_t PopInstructionPtr(int32_t*);
    int32_t PushInstructionPtr(int32_t);
    int32_t ReadScriptFile(CExoString*);
    int32_t RunScript(CExoString*, uint32_t, int32_t);
    int32_t RunScriptFile(int32_t);
    int32_t RunScriptSituation(void*, uint32_t, int32_t);
    int32_t SaveScriptSituation_Internal(CVirtualMachineScript*, CResGFF*, CResStruct*);
    void SetCommandImplementer(CVirtualMachineCmdImplementer*);
    void SetDebugGUIFlag(int32_t);
    int32_t SetUpScriptSituation(CVirtualMachineScript*);
    int32_t StackPopCommand_Internal(CVirtualMachineScript**);
    int32_t StackPopEngineStructure(int32_t, void**);
    int32_t StackPopFloat(float*);
    int32_t StackPopInteger(int32_t*);
    int32_t StackPopObject(uint32_t*);
    int32_t StackPopString(CExoString*);
    int32_t StackPopVector(Vector*);
    int32_t StackPushEngineStructure(int32_t, void*);
    int32_t StackPushFloat(float);
    int32_t StackPushInteger(int32_t);
    int32_t StackPushObject(uint32_t);
    int32_t StackPushString(const CExoString&);
    int32_t StackPushVector(Vector);
    int32_t Test_RunAllScriptsInDirectory(CExoString&);
};

void CVirtualMachine__CVirtualMachineCtor__0(CVirtualMachine* thisPtr);
void CVirtualMachine__CVirtualMachineDtor__0(CVirtualMachine* thisPtr);
void CVirtualMachine__Debugger(CVirtualMachine* thisPtr, int32_t*);
int32_t CVirtualMachine__DeleteScript(CVirtualMachine* thisPtr, CVirtualMachineScript*);
void CVirtualMachine__DeleteScriptSituation(CVirtualMachine* thisPtr, void*);
int32_t CVirtualMachine__ExecuteCode(CVirtualMachine* thisPtr, int32_t*, char*, int32_t, CVirtualMachineDebuggingContext*);
int32_t CVirtualMachine__GetRunScriptReturnValue(CVirtualMachine* thisPtr, int32_t*, void**);
CScriptLog* CVirtualMachine__GetScriptLog(CVirtualMachine* thisPtr, const CExoString&);
void CVirtualMachine__InitializeScript(CVirtualMachine* thisPtr, CVirtualMachineScript*, char*, int32_t);
int32_t CVirtualMachine__LoadScriptSituation_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript**, CResGFF*, CResStruct*);
int32_t CVirtualMachine__PopInstructionPtr(CVirtualMachine* thisPtr, int32_t*);
int32_t CVirtualMachine__PushInstructionPtr(CVirtualMachine* thisPtr, int32_t);
int32_t CVirtualMachine__ReadScriptFile(CVirtualMachine* thisPtr, CExoString*);
int32_t CVirtualMachine__RunScript(CVirtualMachine* thisPtr, CExoString*, uint32_t, int32_t);
int32_t CVirtualMachine__RunScriptFile(CVirtualMachine* thisPtr, int32_t);
int32_t CVirtualMachine__RunScriptSituation(CVirtualMachine* thisPtr, void*, uint32_t, int32_t);
int32_t CVirtualMachine__SaveScriptSituation_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript*, CResGFF*, CResStruct*);
void CVirtualMachine__SetCommandImplementer(CVirtualMachine* thisPtr, CVirtualMachineCmdImplementer*);
void CVirtualMachine__SetDebugGUIFlag(CVirtualMachine* thisPtr, int32_t);
int32_t CVirtualMachine__SetUpScriptSituation(CVirtualMachine* thisPtr, CVirtualMachineScript*);
int32_t CVirtualMachine__StackPopCommand_Internal(CVirtualMachine* thisPtr, CVirtualMachineScript**);
int32_t CVirtualMachine__StackPopEngineStructure(CVirtualMachine* thisPtr, int32_t, void**);
int32_t CVirtualMachine__StackPopFloat(CVirtualMachine* thisPtr, float*);
int32_t CVirtualMachine__StackPopInteger(CVirtualMachine* thisPtr, int32_t*);
int32_t CVirtualMachine__StackPopObject(CVirtualMachine* thisPtr, uint32_t*);
int32_t CVirtualMachine__StackPopString(CVirtualMachine* thisPtr, CExoString*);
int32_t CVirtualMachine__StackPopVector(CVirtualMachine* thisPtr, Vector*);
int32_t CVirtualMachine__StackPushEngineStructure(CVirtualMachine* thisPtr, int32_t, void*);
int32_t CVirtualMachine__StackPushFloat(CVirtualMachine* thisPtr, float);
int32_t CVirtualMachine__StackPushInteger(CVirtualMachine* thisPtr, int32_t);
int32_t CVirtualMachine__StackPushObject(CVirtualMachine* thisPtr, uint32_t);
int32_t CVirtualMachine__StackPushString(CVirtualMachine* thisPtr, const CExoString&);
int32_t CVirtualMachine__StackPushVector(CVirtualMachine* thisPtr, Vector);
int32_t CVirtualMachine__Test_RunAllScriptsInDirectory(CVirtualMachine* thisPtr, CExoString&);

}

}
