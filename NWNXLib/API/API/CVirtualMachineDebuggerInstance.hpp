#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineDebuggerInstance)
#endif

struct CVirtualMachine;


typedef int BOOL;


struct CVirtualMachineDebuggerInstance
{
    RESTYPE m_nResTypeSource;
    RESTYPE m_nResTypeDebug;
    CVirtualMachine * m_pVMachine;
    int32_t * m_pnInstructionPointer;
    char * m_pDebugInputMessageBuffer;
    int32_t m_nDebugInputMessageSize;
    char * m_pDebugOutputMessageBuffer;
    int32_t m_nDebugOutputMessageSize;
    int32_t m_nDebugSourceFileNames;
    CExoString * m_pDebugSourceFileNames;
    int32_t m_nDebugStructureDefines;
    CExoString * m_pDebugStructureNames;
    int32_t * m_pDebugStructureFields;
    CExoString * * m_ppDebugStructureFieldNames;
    CExoString * * m_ppDebugStructureTypeNames;
    int32_t m_nDebugFunctionNames;
    CExoString * m_pDebugFunctionNames;
    int32_t * m_pDebugFunctionBinaryStart;
    int32_t * m_pDebugFunctionBinaryEnd;
    int32_t * m_pDebugFunctionParameters;
    CExoString * m_pDebugFunctionReturnTypeNames;
    CExoString * * m_ppDebugFunctionParamTypeNames;
    int32_t m_nDebugVariables;
    int32_t * m_pDebugVariableBinaryStart;
    int32_t * m_pDebugVariableBinaryEnd;
    int32_t * m_pDebugVariableStackLocation;
    CExoString * m_pDebugVariableTypeNames;
    CExoString * m_pDebugVariableNames;
    int32_t m_nDebugLineNumbers;
    int32_t * m_pDebugLineNumberFileName;
    int32_t * m_pDebugLineNumberCodeLine;
    int32_t * m_pDebugLineNumberBinaryStart;
    int32_t * m_pDebugLineNumberBinaryEnd;
    int32_t m_nDebugWatchViewArraySize;
    BOOL * m_pDebugWatchViewEmpty;
    BOOL * m_pDebugWatchViewTouched;
    BOOL * m_pDebugWatchViewExpanded;
    int32_t * m_pDebugWatchViewStackLocations;
    CExoString * m_pDebugWatchViewVariableNames;
    CExoString * m_pDebugWatchViewTypeNames;
    CExoString * m_pDebugWatchViewLineNumbers;
    CExoString * m_pDebugWatchViewVariableValues;
    CExoString m_sCurrentSourceFileName;
    CExoString m_sCurrentSourceScriptSource;
    int32_t m_nActiveCallStackEntry;

    CVirtualMachineDebuggerInstance(RESTYPE nScriptResType, RESTYPE nDebugResType);
    ~CVirtualMachineDebuggerInstance();
    int32_t SpawnDebugger();
    int32_t DebuggerMainLoop();
    void ShutDownDebugger();
    int32_t GenerateLineNumberFromInstructionPointer(int32_t nIP, BOOL bExactCheck = false);
    static BOOL VerifyDebugInfo(DataViewRef pDebugInfo);
    BOOL ReadIntegerFromInput(int32_t * pnSize, int32_t * pnInteger);
    BOOL ReadStringFromInput(int32_t * pnSize, CExoString * psString);
    BOOL ParseAndExecuteMessage(int32_t * nSize);
    char * LoadDebugInfoLine(const uint8_t * pResourceData, uint32_t nResourceSize, uint32_t nOffsetStart, uint32_t * pnOffsetEnd);
    BOOL LoadDebugInfo(DataViewRef pDebugData);
    char * LoadScriptLine(const uint8_t * pResourceData, uint32_t nResourceSize, uint32_t nOffsetStart, uint32_t * pnOffsetEnd, BOOL bIncludeReturns);
    int32_t GenerateFunctionIDFromInstructionPointer(int32_t nIP);
    int32_t GenerateTypeSize(CExoString * pNDBString);
    int32_t GenerateStackSizeAtInstructionPointer(int32_t nFunctionID, int32_t nIP);
    int32_t GenerateDebugVariableLocationForParameter(int32_t nFunctionID, int32_t nParameter);
    int32_t GetNextDebugVariable(int32_t nFunctionID, int32_t nIP, int32_t nStackLocationToExceed);
    CExoString GenerateTypeName(CExoString * pNDBString);
    CExoString GenerateTypeValueFromStackLocation(int32_t nStackLocation, CExoString * pTypeString);
    CExoString GenerateCallStackParameterView(int32_t nStackLocation, CExoString * sVariableName, CExoString * sTypeName);
    CExoString GenerateCallStackView(int32_t nFunctionID, int32_t nInstructionPointer, int32_t nStackPointer);
    void ToggleWatchWindowExpansion(CExoString sLineNumber);
    BOOL DebuggerSingleStep(BOOL bStepOver = false);
    int32_t FindEmptyWatchViewEntry();
    int32_t FindWatchViewEntry(CExoString * psVariableName, CExoString * psTypeName, int32_t nStackLocation);
    void SendWatchWindowEntry(CExoString * psLineNumber, CExoString * psVariableName, CExoString * psVariableValue, CExoString * psTypeName, int32_t nStackLocation);
    void SendWatchWindowUpdateCommands(int32_t nActiveCallStackEntry);
    void SendCallStackWindowUpdateCommands();
    void SendCodeWindowUpdateCommands(CExoString sDebugFileName, int32_t nCodeLine);
    void SendLabelsAndKeywords();
    BOOL DebuggerDisplayCurrentLocation(int32_t nActiveCallStackEntry, BOOL bInternalDebug = false);


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineDebuggerInstance
    NWN_CLASS_EXTENSION_CVirtualMachineDebuggerInstance
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineDebuggerInstance)
#endif

