#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CVirtualMachineFile.hpp"
#include "CVirtualMachineScript.hpp"
#include "CVirtualMachineStack.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachine)
#endif

struct CExoString;
struct CResGFF;
struct CResStruct;
struct CScriptCompiler;
struct CScriptLog;
struct CScriptLog;
struct CVirtualMachineCache;
struct CVirtualMachineCmdImplementer;
struct CVirtualMachineDebuggingContext;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CVirtualMachine
{
    CScriptCompiler * m_pJitCompiler;
    int32_t m_nReturnValueParameterType;
    void * m_pReturnValue;
    uint32_t m_nInstructionsExecuted;
    int32_t m_nRecursionLevel;
    CVirtualMachineScript m_pVirtualMachineScript[8];
    BOOL m_bValidObjectRunScript[8];
    OBJECT_ID m_oidObjectRunScript[8];
    CVirtualMachineStack m_cRunTimeStack;
    int32_t m_nInstructPtrLevel;
    int32_t m_pnRunTimeInstructPtr[128];
    int32_t m_nSecondaryInstructionPointer;
    int32_t m_nStackSizeToSave;
    int32_t m_nBaseStackSizeToSave;
    CVirtualMachineCmdImplementer * m_pCmdImplementer;
    BOOL m_bDebugGUIRequired;
    BOOL m_bDebuggerSpawned;
    CVirtualMachineFile m_cVMFile;
    CVirtualMachineCache * m_pCache;
    CScriptLog * m_pLog;
    CExoArrayList<CScriptLog *> m_aScriptLog;
    BOOL m_bEnableScriptLogging;
    BOOL m_bEnableScriptProfiling;
    uint32_t m_nScriptStartTime;
    uint32_t m_nScriptEndTime;
    uint32_t m_nInstructionLimit;

    CVirtualMachine();
    ~CVirtualMachine();
    BOOL RunScript(CExoString * psFileName, OBJECT_ID oid, BOOL bOidValid = true);
    int32_t RunScriptChunk(const CExoString & sScriptChunk, OBJECT_ID oid, BOOL bOidValid = true, BOOL bWrapIntoMain = true);
    BOOL RunScriptSituation(void * pScriptSituation, OBJECT_ID oid, BOOL bOidValid = true);
    BOOL GetRunScriptReturnValue(int32_t * nParameterType, void * * pParameter);
    void SetDebugGUIFlag(BOOL bValue);
    void SetCommandImplementer(CVirtualMachineCmdImplementer * pImplementer);
    BOOL StackPopInteger(int32_t * nInteger);
    BOOL StackPushInteger(int32_t nInteger);
    BOOL StackPopFloat(float * fFloat);
    BOOL StackPushFloat(float fFloat);
    BOOL StackPopVector(Vector * vVector);
    BOOL StackPushVector(Vector vVector);
    BOOL StackPopString(CExoString * sString);
    BOOL StackPushString(const CExoString & sString);
    BOOL StackPopObject(OBJECT_ID * poidObjectId);
    BOOL StackPushObject(OBJECT_ID oidObjectId);
    BOOL StackPopEngineStructure(int32_t nEngineStructure, void * * ppEngineStructure);
    BOOL StackPushEngineStructure(int32_t nEngineStructure, void * pEngineStructure);
    void DeleteScriptSituation(void * pScript);
    int32_t ExecuteCode(int32_t * nInstructionPointer, char * pCode, int32_t nCodeLength, CVirtualMachineDebuggingContext * pDebugContext = nullptr);
    BOOL Test_RunAllScriptsInDirectory(CExoString & sRunDirectoryAlias);
    BOOL DeleteScript(CVirtualMachineScript * pScript);
    int32_t ExecuteInstructions(int32_t nRecursionLevel, int32_t nNodeLocation);
    void InitializeScript(CVirtualMachineScript * pScript, char * pData, int32_t nDataSize);
    BOOL PopInstructionPtr(int32_t * nInstructionPointer);
    BOOL PushInstructionPtr(int32_t nInstructionPointer);
    int32_t ReadScriptFile(CExoString * sFileName);
    int32_t RunScriptFile(int32_t nInstructionPointer);
    int32_t SetUpJITCompiledScript(const CExoString & sScriptChunk, BOOL bWrapIntoMain);
    int32_t SetUpScriptSituation(CVirtualMachineScript * pScript);
    void Debugger(int32_t * pnCurrentInstructionPointer);
    BOOL StackPopCommand_Internal(CVirtualMachineScript * * pScript);
    BOOL SaveScriptSituation_Internal(CVirtualMachineScript * pScript, CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadScriptSituation_Internal(CVirtualMachineScript * * pScript, CResGFF * pRes, CResStruct * pStruct);
    CScriptLog * GetScriptLog(const CExoString & sScript);


#ifdef NWN_CLASS_EXTENSION_CVirtualMachine
    NWN_CLASS_EXTENSION_CVirtualMachine
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachine)
#endif

