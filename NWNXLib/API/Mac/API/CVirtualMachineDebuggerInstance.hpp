#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CScriptSourceFile.hpp"
#include "CVirtualMachineDebugLoader.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CVirtualMachine;

struct CVirtualMachineDebuggerInstance
{
    CVirtualMachine* m_pVMachine;
    int32_t* m_pnInstructionPointer;
    char* m_pDebugInputMessageBuffer;
    int32_t m_nDebugInputMessageSize;
    char* m_pDebugOutputMessageBuffer;
    int32_t m_nDebugOutputMessageSize;
    int32_t m_nDebugSourceFileNames;
    CExoString* m_pDebugSourceFileNames;
    int32_t m_nDebugStructureDefines;
    CExoString* m_pDebugStructureNames;
    int32_t* m_pDebugStructureFields;
    CExoString** m_ppDebugStructureFieldNames;
    CExoString** m_ppDebugStructureTypeNames;
    int32_t m_nDebugFunctionNames;
    CExoString* m_pDebugFunctionNames;
    int32_t* m_pDebugFunctionBinaryStart;
    int32_t* m_pDebugFunctionBinaryEnd;
    int32_t* m_pDebugFunctionParameters;
    CExoString* m_pDebugFunctionReturnTypeNames;
    CExoString** m_ppDebugFunctionParamTypeNames;
    int32_t m_nDebugVariables;
    int32_t* m_pDebugVariableBinaryStart;
    int32_t* m_pDebugVariableBinaryEnd;
    int32_t* m_pDebugVariableStackLocation;
    CExoString* m_pDebugVariableTypeNames;
    CExoString* m_pDebugVariableNames;
    int32_t m_nDebugLineNumbers;
    int32_t* m_pDebugLineNumberFileName;
    int32_t* m_pDebugLineNumberCodeLine;
    int32_t* m_pDebugLineNumberBinaryStart;
    int32_t* m_pDebugLineNumberBinaryEnd;
    int32_t m_nDebugWatchViewArraySize;
    int32_t* m_pDebugWatchViewEmpty;
    int32_t* m_pDebugWatchViewTouched;
    int32_t* m_pDebugWatchViewExpanded;
    int32_t* m_pDebugWatchViewStackLocations;
    CExoString* m_pDebugWatchViewVariableNames;
    CExoString* m_pDebugWatchViewTypeNames;
    CExoString* m_pDebugWatchViewLineNumbers;
    CExoString* m_pDebugWatchViewVariableValues;
    CVirtualMachineDebugLoader m_pDebugLoader;
    CExoString m_sCurrentSourceFileName;
    CScriptSourceFile m_pCurrentSourceScriptFile;
    int32_t m_nActiveCallStackEntry;

    // The below are auto generated stubs.
    CVirtualMachineDebuggerInstance(const CVirtualMachineDebuggerInstance&) = default;
    CVirtualMachineDebuggerInstance& operator=(const CVirtualMachineDebuggerInstance&) = default;

    CVirtualMachineDebuggerInstance();
    ~CVirtualMachineDebuggerInstance();
    int32_t DebuggerDisplayCurrentLocation(int32_t, int32_t);
    int32_t DebuggerMainLoop();
    int32_t DebuggerSingleStep(int32_t);
    int32_t FindEmptyWatchViewEntry();
    int32_t FindWatchViewEntry(CExoString*, CExoString*, int32_t);
    CExoString GenerateCallStackParameterView(int32_t, CExoString*, CExoString*);
    CExoString GenerateCallStackView(int32_t, int32_t, int32_t);
    int32_t GenerateDebugVariableLocationForParameter(int32_t, int32_t);
    int32_t GenerateFunctionIDFromInstructionPointer(int32_t);
    int32_t GenerateLineNumberFromInstructionPointer(int32_t, int32_t);
    int32_t GenerateStackSizeAtInstructionPointer(int32_t, int32_t);
    CExoString GenerateTypeName(CExoString*);
    int32_t GenerateTypeSize(CExoString*);
    CExoString GenerateTypeValueFromStackLocation(int32_t, CExoString*);
    int32_t GetNextDebugVariable(int32_t, int32_t, int32_t);
    int32_t LoadDebugInfo(CVirtualMachineDebugLoader*);
    char* LoadDebugInfoLine(unsigned char*, uint32_t, uint32_t, uint32_t*);
    char* LoadScriptLine(unsigned char*, uint32_t, uint32_t, uint32_t*, int32_t);
    int32_t ParseAndExecuteMessage(int32_t*);
    int32_t ReadIntegerFromInput(int32_t*, int32_t*);
    int32_t ReadStringFromInput(int32_t*, CExoString*);
    void SendCallStackWindowUpdateCommands();
    void SendCodeWindowUpdateCommands(CExoString, int32_t);
    void SendLabelsAndKeywords();
    void SendWatchWindowEntry(CExoString*, CExoString*, CExoString*, CExoString*, int32_t);
    void SendWatchWindowUpdateCommands(int32_t);
    void ShutDownDebugger();
    int32_t SpawnDebugger();
    void ToggleWatchWindowExpansion(CExoString);
};

void CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceCtor__0(CVirtualMachineDebuggerInstance* thisPtr);
void CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceDtor__0(CVirtualMachineDebuggerInstance* thisPtr);
int32_t CVirtualMachineDebuggerInstance__DebuggerDisplayCurrentLocation(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t);
int32_t CVirtualMachineDebuggerInstance__DebuggerMainLoop(CVirtualMachineDebuggerInstance* thisPtr);
int32_t CVirtualMachineDebuggerInstance__DebuggerSingleStep(CVirtualMachineDebuggerInstance* thisPtr, int32_t);
int32_t CVirtualMachineDebuggerInstance__FindEmptyWatchViewEntry(CVirtualMachineDebuggerInstance* thisPtr);
int32_t CVirtualMachineDebuggerInstance__FindWatchViewEntry(CVirtualMachineDebuggerInstance* thisPtr, CExoString*, CExoString*, int32_t);
CExoString CVirtualMachineDebuggerInstance__GenerateCallStackParameterView(CVirtualMachineDebuggerInstance* thisPtr, int32_t, CExoString*, CExoString*);
CExoString CVirtualMachineDebuggerInstance__GenerateCallStackView(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t, int32_t);
int32_t CVirtualMachineDebuggerInstance__GenerateDebugVariableLocationForParameter(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t);
int32_t CVirtualMachineDebuggerInstance__GenerateFunctionIDFromInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t);
int32_t CVirtualMachineDebuggerInstance__GenerateLineNumberFromInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t);
int32_t CVirtualMachineDebuggerInstance__GenerateStackSizeAtInstructionPointer(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t);
CExoString CVirtualMachineDebuggerInstance__GenerateTypeName(CVirtualMachineDebuggerInstance* thisPtr, CExoString*);
int32_t CVirtualMachineDebuggerInstance__GenerateTypeSize(CVirtualMachineDebuggerInstance* thisPtr, CExoString*);
CExoString CVirtualMachineDebuggerInstance__GenerateTypeValueFromStackLocation(CVirtualMachineDebuggerInstance* thisPtr, int32_t, CExoString*);
int32_t CVirtualMachineDebuggerInstance__GetNextDebugVariable(CVirtualMachineDebuggerInstance* thisPtr, int32_t, int32_t, int32_t);
int32_t CVirtualMachineDebuggerInstance__LoadDebugInfo(CVirtualMachineDebuggerInstance* thisPtr, CVirtualMachineDebugLoader*);
char* CVirtualMachineDebuggerInstance__LoadDebugInfoLine(CVirtualMachineDebuggerInstance* thisPtr, unsigned char*, uint32_t, uint32_t, uint32_t*);
char* CVirtualMachineDebuggerInstance__LoadScriptLine(CVirtualMachineDebuggerInstance* thisPtr, unsigned char*, uint32_t, uint32_t, uint32_t*, int32_t);
int32_t CVirtualMachineDebuggerInstance__ParseAndExecuteMessage(CVirtualMachineDebuggerInstance* thisPtr, int32_t*);
int32_t CVirtualMachineDebuggerInstance__ReadIntegerFromInput(CVirtualMachineDebuggerInstance* thisPtr, int32_t*, int32_t*);
int32_t CVirtualMachineDebuggerInstance__ReadStringFromInput(CVirtualMachineDebuggerInstance* thisPtr, int32_t*, CExoString*);
void CVirtualMachineDebuggerInstance__SendCallStackWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr);
void CVirtualMachineDebuggerInstance__SendCodeWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr, CExoString, int32_t);
void CVirtualMachineDebuggerInstance__SendLabelsAndKeywords(CVirtualMachineDebuggerInstance* thisPtr);
void CVirtualMachineDebuggerInstance__SendWatchWindowEntry(CVirtualMachineDebuggerInstance* thisPtr, CExoString*, CExoString*, CExoString*, CExoString*, int32_t);
void CVirtualMachineDebuggerInstance__SendWatchWindowUpdateCommands(CVirtualMachineDebuggerInstance* thisPtr, int32_t);
void CVirtualMachineDebuggerInstance__ShutDownDebugger(CVirtualMachineDebuggerInstance* thisPtr);
int32_t CVirtualMachineDebuggerInstance__SpawnDebugger(CVirtualMachineDebuggerInstance* thisPtr);
void CVirtualMachineDebuggerInstance__ToggleWatchWindowExpansion(CVirtualMachineDebuggerInstance* thisPtr, CExoString);

}

}
