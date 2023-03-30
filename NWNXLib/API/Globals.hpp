#pragma once

#include <cstdint>

extern CExoString                g_sBuildNumber;
extern CExoString                g_sBuildRevision;
extern CExoString                g_sBuildPostfix;
extern class CExoBase           *g_pExoBase;
extern class CExoResMan         *g_pExoResMan;
extern class CVirtualMachine    *g_pVirtualMachine;
extern class CScriptCompiler    *g_pScriptCompiler;
extern class CAppManager        *g_pAppManager;
extern class CTlkTable          *g_pTlkTable;
extern class CNWRules           *g_pRules;
namespace Task {
extern class CExoTaskManager    *g_pExoTaskManager;
}
extern int32_t                   g_bEnableCombatDebugging;
extern int32_t                   g_bEnableSavingThrowDebugging;
extern int32_t                   g_bEnableMovementSpeedDebugging;
extern int32_t                   g_bEnableHitDieDebugging;
extern int32_t                   g_bExitProgram;

namespace NWNXLib::API::Globals {

inline CExoString*            BuildNumber()     { return &g_sBuildNumber; }
inline CExoString*            BuildRevision()   { return &g_sBuildRevision; }
inline CExoString*            BuildPostfix()    { return &g_sBuildPostfix; }
inline CExoBase*              ExoBase()         { return g_pExoBase; }
inline CExoResMan*            ExoResMan()       { return g_pExoResMan; }
inline CVirtualMachine*       VirtualMachine()  { return g_pVirtualMachine; }
inline CScriptCompiler*       ScriptCompiler()  { return g_pScriptCompiler; }
inline CAppManager*           AppManager()      { return g_pAppManager; }
inline CTlkTable*             TlkTable()        { return g_pTlkTable; }
inline CNWRules*              Rules()           { return g_pRules; }
inline Task::CExoTaskManager* TaskManager()     { return Task::g_pExoTaskManager; }

inline int32_t* EnableCombatDebugging()         { return &g_bEnableCombatDebugging; }
inline int32_t* EnableSavingThrowDebugging()    { return &g_bEnableSavingThrowDebugging; }
inline int32_t* EnableMovementSpeedDebugging()  { return &g_bEnableMovementSpeedDebugging; }
inline int32_t* EnableHitDieDebugging()         { return &g_bEnableHitDieDebugging; }
#ifdef WIN32
inline int32_t* ExitProgram()                   { return NULL; }
#else
inline int32_t* ExitProgram()                   { return &g_bExitProgram; }
#endif

}
