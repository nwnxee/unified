#pragma once

#include <cstdint>


struct CExoBase;
struct CExoResMan;
struct CVirtualMachine;
struct CScriptCompiler;
struct CAppManager;
struct CTlkTable;
struct CNWRules;
struct CExoString;
namespace Task {
struct CExoTaskManager;
}

namespace NWNXLib::API::Globals {

struct NWNXExportedGlobals
{
    CExoString            *psBuildNumber;
    CExoString            *psBuildRevision;
    CExoBase              **ppExoBase;
    CExoResMan            **ppExoResMan;
    CVirtualMachine       **ppVirtualMachine;
    CScriptCompiler       **ppScriptCompiler;
    CAppManager           **ppAppManager;
    CTlkTable             **ppTlkTable;
    CNWRules              **ppRules;
    Task::CExoTaskManager **ppExoTaskManager;
    int32_t                *pbEnableCombatDebugging;
    int32_t                *pbEnableSavingThrowDebugging;
    int32_t                *pbEnableMovementSpeedDebugging;
    int32_t                *pbEnableHitDieDebugging;
    int32_t                *pbExitProgram;
};
extern NWNXExportedGlobals ExportedGlobals;

inline CExoString*            BuildNumber()     { return ExportedGlobals.psBuildNumber; }
inline CExoString*            BuildRevision()   { return ExportedGlobals.psBuildRevision; }
inline CExoBase*              ExoBase()         { return *ExportedGlobals.ppExoBase; }
inline CExoResMan*            ExoResMan()       { return *ExportedGlobals.ppExoResMan; }
inline CVirtualMachine*       VirtualMachine()  { return *ExportedGlobals.ppVirtualMachine; }
inline CScriptCompiler*       ScriptCompiler()  { return *ExportedGlobals.ppScriptCompiler; }
inline CAppManager*           AppManager()      { return *ExportedGlobals.ppAppManager; }
inline CTlkTable*             TlkTable()        { return *ExportedGlobals.ppTlkTable; }
inline CNWRules*              Rules()           { return *ExportedGlobals.ppRules; }
inline Task::CExoTaskManager* TaskManager()     { return *ExportedGlobals.ppExoTaskManager; }

inline int32_t* EnableCombatDebugging()         { return ExportedGlobals.pbEnableCombatDebugging; }
inline int32_t* EnableSavingThrowDebugging()    { return ExportedGlobals.pbEnableSavingThrowDebugging; }
inline int32_t* EnableMovementSpeedDebugging()  { return ExportedGlobals.pbEnableMovementSpeedDebugging; }
inline int32_t* EnableHitDieDebugging()         { return ExportedGlobals.pbEnableHitDieDebugging; }
inline int32_t* ExitProgram()                   { return ExportedGlobals.pbExitProgram; }

}
