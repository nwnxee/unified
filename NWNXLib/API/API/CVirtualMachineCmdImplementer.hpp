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


struct CVirtualMachineCmdImplementer
{
    BOOL m_bValidObjectRunScript;
    OBJECT_ID m_oidObjectRunScript;

    virtual ~CVirtualMachineCmdImplementer();
    virtual void InitializeCommands();
    virtual int32_t ExecuteCommand(int32_t nCommandId, int32_t nParameters);
    virtual void RunScriptCallback(CExoString * psFileName, int nRecursionLevel);
    virtual void RunScriptEndCallback(CExoString * psFileName, int nRecursionLevel);
    virtual void ReportError(const CExoString & sFileName, int32_t nError, const CExoString & customMsg = "");
    virtual void * CreateGameDefinedStructure(int32_t nUserDefinedType);
    virtual void DestroyGameDefinedStructure(int32_t nUserDefinedType, void * pStructureToDelete);
    virtual BOOL GetEqualGameDefinedStructure(int32_t nUserDefinedType, void * pStructure1, void * pStructure2);
    virtual void * CopyGameDefinedStructure(int32_t nUserDefinedType, void * pStructureSrc);
    virtual BOOL SaveGameDefinedStructure(int32_t nEngineStructure, void * pStructure, CResGFF * pRes, CResStruct * pStruct);
    virtual BOOL LoadGameDefinedStructure(int32_t nEngineStructure, void * * pStructure, CResGFF * pRes, CResStruct * pStruct);
    virtual CExoString GetGameDefinedStructureName(int32_t nEngineStructure);
    virtual CExoString GetDebuggerLabelName(int32_t nDebuggerLabel);
    virtual void GetEngineStructureWatchView(int32_t nEngineStructure, void * pEngineStructure, int32_t * nEntries, CExoString * * m_ppNames, CExoString * * m_ppValues);
    virtual void GetObjectWatchView(OBJECT_ID oidObject, int32_t * nEntries, CExoString * * m_ppNames, CExoString * * m_ppValues);
    virtual int32_t DebugGUIStart();
    virtual void DebugGUIStop();
    virtual void DebugGUISendMessageTo(char * pMsg, int32_t nSize);
    virtual int32_t DebugGUIGetMessageFrom(char * * pMsg, int32_t * nSize);
    virtual void DebugGUIUpdate();


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineCmdImplementer
    NWN_CLASS_EXTENSION_CVirtualMachineCmdImplementer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineCmdImplementer)
#endif

