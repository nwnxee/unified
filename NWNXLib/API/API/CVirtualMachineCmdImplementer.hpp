#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineCmdImplementer)
#endif

struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;

enum class VMContext
{
    SERVER = 1,
};

struct CVirtualMachineCmdImplementer
{
    BOOL m_bValidObjectRunScript;
    OBJECT_ID m_oidObjectRunScript;
    CVirtualMachine* m_pVM;
    const VMContext m_cCtx;

    CVirtualMachineCmdImplementer(CVirtualMachine* vm, VMContext ctx) : m_pVM(vm), m_cCtx(ctx) {};
    virtual ~CVirtualMachineCmdImplementer() {};
    virtual void InitializeCommands()  = 0;
    virtual int32_t ExecuteCommand(int32_t nCommandId, int32_t nParameters)  = 0;
    virtual void RunScriptCallback(CExoString * psFileName, int nRecursionLevel)  = 0;
    virtual void RunScriptEndCallback(CExoString * psFileName, int nRecursionLevel) = 0;
    virtual void ReportError(const CExoString & sFileName, int32_t nError, const CExoString & customMsg = "") = 0;
    virtual void * CreateGameDefinedStructure(int32_t nUserDefinedType) = 0;
    virtual void DestroyGameDefinedStructure(int32_t nUserDefinedType, void * pStructureToDelete) = 0;
    virtual BOOL GetEqualGameDefinedStructure(int32_t nUserDefinedType, void * pStructure1, void * pStructure2) = 0;
    virtual void * CopyGameDefinedStructure(int32_t nUserDefinedType, void * pStructureSrc) = 0;
    virtual BOOL SaveGameDefinedStructure(int32_t nEngineStructure, void * pStructure, CResGFF * pRes, CResStruct * pStruct) = 0;
    virtual BOOL LoadGameDefinedStructure(int32_t nEngineStructure, void * * pStructure, CResGFF * pRes, CResStruct * pStruct) = 0;
    virtual CExoString GetGameDefinedStructureName(int32_t nEngineStructure) = 0;
    virtual CExoString GetDebuggerLabelName(int32_t nDebuggerLabel) = 0;
    virtual void GetEngineStructureWatchView(int32_t nEngineStructure, void * pEngineStructure, int32_t * nEntries, CExoString * * m_ppNames, CExoString * * m_ppValues) = 0;
    virtual void GetObjectWatchView(OBJECT_ID oidObject, int32_t * nEntries, CExoString * * m_ppNames, CExoString * * m_ppValues) = 0;
    virtual int32_t DebugGUIStart() = 0;
    virtual void DebugGUIStop() = 0;
    virtual void DebugGUISendMessageTo(char * pMsg, int32_t nSize) = 0;
    virtual int32_t DebugGUIGetMessageFrom(char * * pMsg, int32_t * nSize) = 0;
    virtual void DebugGUIUpdate() = 0;

    int32_t ExecuteCommandRandom(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandPrintString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandPrintFloat(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandPrintInteger(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandPrintObject(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandFloatToString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandFloatToInt(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandIntToFloat(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandIntToHexString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandIntToString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetStringLength(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetStringUpperCase(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetStringLowerCase(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetStringRight(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetStringLeft(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandInsertString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandGetSubString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandFindSubString(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandMath(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandJsonShared(int32_t nCommandId, int32_t nParameters);
    int32_t ExecuteCommandCassowaryShared(int32_t nCommandId, int32_t nParameters);

#ifdef NWN_CLASS_EXTENSION_CVirtualMachineCmdImplementer
    NWN_CLASS_EXTENSION_CVirtualMachineCmdImplementer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineCmdImplementer)
#endif

